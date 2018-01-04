#ifndef PARSER_H
#define PARSER_H

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <stack>
#include "list.h"
#include "atom.h"
#include "variable.h"
#include "scanner.h"
#include "struct.h"
#include "number.h"
#include "exp.h"

using namespace std;

class Parser
{
public:
  Parser(Scanner scanner) : _scanner(scanner), _terms(){}

  Term* createTerm(){
    int token = _scanner.nextToken();
    _currentToken = token;
    if(token == VAR){
      for (int i = 0; i < table.size(); i++){
        if (symtable[_scanner.tokenValue()].first == table[i]->symbol()){
          return table[i];
        }
      }
      Variable *variable = new Variable(symtable[_scanner.tokenValue()].first);
      table.push_back(variable);
      return variable;
    }else if(token == NUMBER){
      return new Number(_scanner.tokenValue());
    }else if(token == ATOM || token == ATOMSC){
      Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
      if(_scanner.currentChar() == '(' ) {
        return structure();
      }
      else
        return atom;
    }
    else if(token == '['){
      return list();
    }

    return nullptr;
  }

  Term * structure() {
    Atom structName = Atom(symtable[_scanner.tokenValue()].first);
    int startIndexOfStructArgs = _terms.size();
    _scanner.nextToken();
    createTerms();
    if(_currentToken == ')')
    {
      vector<Term *> args(_terms.begin() + startIndexOfStructArgs, _terms.end());
      _terms.erase(_terms.begin() + startIndexOfStructArgs, _terms.end());
      return new Struct(structName, args);
    }else if (_currentToken == ';'){
      throw string("Unbalanced operator");
    }else{
      throw string("unexpected token");
    }
  }

  Term * list() {
    int startIndexOfListArgs = _terms.size();
    createTerms();
    if(_currentToken == ']')
    {
      vector<Term *> args(_terms.begin() + startIndexOfListArgs, _terms.end());
      _terms.erase(_terms.begin() + startIndexOfListArgs, _terms.end());
      if(args.size()==0){
        return new Atom("[]");
      }
      return new List(args);
    }else if (_currentToken == ';'){
      throw string("Unbalanced operator");
    }else{
      throw string("unexpected token");
    }
  }

  Exp *buildExpression()
  {
    if (!_scanner.getCase().find(";.")){
      throw string("Unexpected ';' before '.'");
    }
    if (!_scanner.getCase().find(",.")){
      throw string("Unexpected ',' before '.'");
    }
    disjunctionMatch();
    restDisjunctionMatch();
    if (createTerm() != nullptr || _currentToken != '.')
      throw string("Missing token '.'");
    return _expStack.top();
  }

  void restDisjunctionMatch() {
    if (_scanner.currentChar() == ';') {
      table.clear();
      createTerm();
      disjunctionMatch();
      Exp *right = _expStack.top();
      _expStack.pop();
      Exp *left = _expStack.top();
      _expStack.pop();
      _expStack.push(new DisjExp(left, right));
      restDisjunctionMatch();
    }
  }

  void disjunctionMatch() {
    conjunctionMatch();
    restConjunctionMatch();
  }

  void restConjunctionMatch() {
    if (_scanner.currentChar() == ',') {
      createTerm();
      conjunctionMatch();
      Exp *right = _expStack.top();
      _expStack.pop();
      Exp *left = _expStack.top();
      _expStack.pop();
      _expStack.push(new ConjExp(left, right));
      restConjunctionMatch();
    }
  }

  void conjunctionMatch() {
    Term * left = createTerm();
    if (createTerm() == nullptr && _currentToken == '=') {
      Term * right = createTerm();
      _expStack.push(new MatchExp(left, right));
    }
    else if(_currentToken=='.')
    {
      throw string(left->symbol()+" does never get assignment");
    }else if(_currentToken==',')
    {
      throw string("Unexpected ',' before '.'");
    }else if(_currentToken==';')
    {
      throw string("Unexpected ';' before '.'");
    }
    else if(_currentToken != '=')
    {
      throw string ("Unexpected ',' before '.'");
    }
  }

  Exp *getExpressionTree() {
     return _expStack.top();
  }

  // vector<Term *> &getTerms() { return _terms; }
private:

  FRIEND_TEST(ParserTest, createArgs);
  FRIEND_TEST(ParserTest,ListOfTermsEmpty);
  FRIEND_TEST(ParserTest,listofTermsTwoNumber);
  FRIEND_TEST(ParserTest, createTerm_nestedStruct3);
  FRIEND_TEST(ParserTest, createTerms);

  void createTerms() {
    Term* term = createTerm();
    if(term!=nullptr)
    {
      _terms.push_back(term);
      while((_currentToken = _scanner.nextToken()) == ',') {
        _terms.push_back(createTerm());
      }
    }
  }

  vector<Term *> _terms;
  Scanner _scanner;
  int _currentToken;
  stack<Exp *> _expStack;
  vector<Variable *> table;
  int index;
};
#endif