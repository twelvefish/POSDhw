#include "Number.h"
#include "variable.h"
#include "atom.h"
bool _assignable = true;
Number::Number(string s, string v)
{
    _symbol = s;
    _value = v;
}

Number::Number(int num)
{
    _number = num;
}


string Number::symbol()
{
    return _symbol;
}

int Number::number()
{
    return _number;
}

string Number::value()
{
    return _value;
}

bool Number::match(Number number)
{
    return _number == number.number();
}

bool Number::match(Atom atom)
{
    return false;
}

bool Number::match(Variable variable)
{
    bool ret = _assignable;
    if (_assignable)
    {
        _symbol = variable._value;
        _assignable = false;
        return true;
    }
    return ret;
}