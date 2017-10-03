#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
using std::string;
class Number;
class Atom;
class Variable
{
public:
  Variable(string s) : _symbol(s) {}
  string const _symbol;
  string value();
  string symbol();
  string _value;
  bool match(string s);
  bool match(Atom atom);
  bool _assignable = true;
};

#endif
