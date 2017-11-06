#ifndef PARSER_H
#define PARSER_H
#include <string>
using std::string;
using namespace std;
#include "atom.h"
#include "number.h"
#include "variable.h"
#include "global.h"
#include "scanner.h"
#include "struct.h"
#include "list.h"
#include <iostream>

class Parser
{
public:
  Parser(Scanner scanner) : _scanner(scanner) {}
  Term *createTerm()
  {
    token = _scanner.nextToken();
    _scanner.skipLeadingWhiteSpace();
    if (token == VAR)
    {
      return new Variable(symtable[_scanner.tokenValue()].first);
    }
    else if (token == NUMBER)
    {
      return new Number(_scanner.tokenValue());
    }
    else if (token == ATOM)
    {
      Atom *atom = new Atom(symtable[_scanner.tokenValue()].first);
      if (_scanner.currentChar() == '(')
      {

        _scanner.nextToken();
        if (_scanner.currentChar() == ')')
        {
          _scanner.nextToken();
          return new Struct(*atom);
        }
        vector<Term *> terms = getArgs();
        if (token == ')')
          return new Struct(*atom, terms);
      }
      else
        return atom;
    }
    else if (token == ATOMSC)
    {
      Atom *atom = new Atom(symtable[_scanner.tokenValue()].first);
      if (_scanner.currentChar() == '(')
      {
        _scanner.nextToken();
        if (_scanner.currentChar() == ')')
        {
          _scanner.nextToken();
          return new Struct(*atom);
        }
        vector<Term *> terms = getArgs();
        if (token == ')')
          return new Struct(*atom, terms);
      }
      else
        return atom;
    }
    else if (token == '[')
    {
      if (_scanner.currentChar() != ']')
      {
        vector<Term *> terms = getArgs();
        if (token == ']')
        {
          return new List(terms);
        }
      }
      else if (_scanner.currentChar() == ']')
      {
        _scanner.nextToken();
        vector<Term *> terms = {};
        return new List(terms);
      }
    }
    return nullptr;
  }

  vector<Term *> getArgs()
  {
    Term *term = createTerm();
    vector<Term *> args;
    if (term)
      args.push_back(term);
    while ((token = _scanner.nextToken()) == ',')
    {
      args.push_back(createTerm());
    }
    return args;
  }

private:
  Scanner _scanner;
  int token;
};
#endif