#ifndef NUMBER_H_INCLUDED
#define NUMBER_H_INCLUDED

#include <string>

using namespace std;
class Atom;
class Var;
class Number
{
  public:
    Number(string s, string v);
    Number(int num);
    string value();
    string symbol();
    int number();
    bool match(Number number);
    bool match(Atom atom);
    bool match(Var var);

  private:
    string _value;
    string _symbol;
    int _number;
};

#endif