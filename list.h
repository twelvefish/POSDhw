#ifndef LIST_H
#define LIST_H

#include "term.h"
#include "variable.h"

#include <vector>
using namespace std;

class List : public Term
{
public:
  string symbol() const
  {
    string ret = +"[";
    if (!_elements.empty())
    {
      std::vector<Term *>::const_iterator it = _elements.begin();
      for (; it != _elements.end() - 1; ++it)
        ret += (*it)->symbol() + ", ";
      ret += (*it)->symbol();
    }
    ret += "]";
    return ret;
  }
  string value() const
  {
  }
  bool match(Term &term)
  {
    if (term.isList)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  bool match(Variable &var){
    if(!var._inst){
      var._inst = this ;
      return true;
    }
    return var._inst->match(*this);
  }

public:
  List() : _elements() {
    isList = true;
  }
  List(vector<Term *> const &elements) : _elements(elements) {
    isList = true;
  }
  Term *head() const;
  List *tail() const;

private:
  vector<Term *> _elements;
};
#endif
