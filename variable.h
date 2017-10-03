#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
using std::string;
class Number;
class Atom;
class Variable
{
public:
  Variable(string s);
  
  int value();
  string symbol();

  bool match(Number num);
  bool match(Atom atom);
  bool _assignable = true;

private:
  string _symbol;
  int _value;
};

#endif
