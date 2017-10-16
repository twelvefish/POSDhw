#ifndef NUMBER_H_INCLUDED
#define NUMBER_H_INCLUDED

#include <string>
using std::string;

class Atom;
class Variable;
class Number
{
public:
  Number(double n);

  string value();
  string symbol();
  double num();

  bool match(Number number);
  bool match(Atom atom);
  bool match(Variable &variable);

private:
  string _value;
  string _symbol;
  double _number;
};

#endif