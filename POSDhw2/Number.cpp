#include "Number.h"
#include "variable.h"
#include "atom.h"
bool _assignable = true;
Number::Number(string s, string v)
{
    _symbol = s;
    _value = v;
}

string Number::symbol()
{
    return _symbol;
}

string Number::value()
{
    return _value;
}

bool Number::match(Number number)
{
    return _value == number.value();
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