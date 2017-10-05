#ifndef NUMBER_H_INCLUDED
#define NUMBER_H_INCLUDED

#include <string>
using std::string;

class Atom;
class Variable;
class Number
{
public:
  Number(int n);

  string value();
  string symbol();
  int num();

  bool match(Number number);
  bool match(Atom atom);
  bool match(Variable variable);

private:
  string _value;
  string _symbol;
  int _number;
};

#endif