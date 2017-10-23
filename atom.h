#ifndef ATOM_H
#define ATOM_H

#include <string>
#include <sstream>
using std::string;

class Atom : public Term
{
public:
  Atom(string s) : Term(s) {}
  bool isAtom = true;
  bool match(Term &a)
  {
    if (a.isList)
    {
      return false;
    }
  }
};

#endif
