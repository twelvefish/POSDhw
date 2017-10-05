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
  bool tags();
  void setSymbol(string);

  bool match(Number num);
  bool match(Atom atom);
  void setTag(bool t);

private:
  string _symbol;
  string _value;
  bool tag = true ;
};

#endif
