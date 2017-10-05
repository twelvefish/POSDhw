#include "number.h"
#include "variable.h"
#include "atom.h"
#include <string>
#include <sstream>
using std::string;

bool _assignable = true;


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
    _value = std::to_string(_number);
    return _value;
}

string Number::symbol()
{
    _symbol = std::to_string(_number);
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
    if (_assignable || _symbol == variable.symbol())
    {
        _symbol = variable.symbol();
        _assignable = false;
        return true;
    }
    return ret;
}