#include "number.h"
#include "variable.h"
#include "atom.h"
#include <string>

using std::string;

bool _assignable = true;

Number::Number(int v)
{
    _value = v;
}

Number::Number(string s)
{
    _symbol = s;
}

int Number::value()
{
    return _value;
}

string Number::symbol()
{
    return _symbol;
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
        _symbol = variable.symbol();
        _assignable = false;
        return true;
    }
    return ret;
}