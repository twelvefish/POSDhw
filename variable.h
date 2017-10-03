#ifndef VAR_H
#define VAR_H

#include <string>
using std::string;
class Number;
class Atom;
class Var
{
public:
  Var(string s) : _symbol(s) {}
  string const _symbol;
  string _value;
  bool match(string s);
  bool match(Atom atom);
  bool _assignable = true;
};

#endif
