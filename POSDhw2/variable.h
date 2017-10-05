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
  
  string value();
  string symbol();
  void setSymbol(string);
  void setValue(string);

  bool match(Number num);
  bool match(Atom atom);
  bool tag = true;

private:
  string _symbol;
  string _value;
};

#endif
