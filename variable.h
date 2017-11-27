#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <iostream>
#include "atom.h"
#include "term.h"
using std::string;

class Variable : public Term
{
public:
  Variable(string s) : Term(s), _inst(0)
  {
    isVariable = true;
  }
  string value() const
  {
    if (_inst)
      return _inst->value();
    else
      return Term::value();
  }
  bool match(Term &term)
  {
    if (term.isList == true)
    {
      for (int i = 0; i < term.size(); i++)
      {
        if (term.count(i).symbol() == _symbol)
        {
          return false;
        }
      }
      if (!_inst)
      {
        _inst = &term;
        return true;
      }
      return _inst->match(term);
    }

    if (this == &term)
      return true;
    else if (_inst == NULL)
    {
      _inst = &term;
      return true;
    }
    else
    {
      Variable *var = dynamic_cast<Variable *>(&term);
      if (var != nullptr)
      {
        if (var->_inst == NULL)
        {
          var->_inst = _inst;
          return true;
        }
        else
          _inst->match(*var);
      }
      return _inst->match(term);
    }
  }

  Term *_inst;

private:
};

#endif
