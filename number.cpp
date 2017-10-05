#include "number.h"
#include "variable.h"
#include "atom.h"
#include <string>

using std::string;

bool _assignable = true;

Number::Number(string v)
{
    _value = v;
    _symbol = v;
}

Number::Number(int n)
{
    _number = n;
}

// Number::Number(string s)
// {
//     _symbol = s;
// }

string Number::value()
{
    return _value;
}

string Number::symbol()
{
    return _symbol;
}

int Number::num()
{
    return _number;
}


bool Number::match(Number number)
{
    return _number == number.num();
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