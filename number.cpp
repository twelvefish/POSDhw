#include "number.h"
#include "variable.h"
#include "atom.h"
#include <string>
using std::string;

bool tag = true;


Number::Number(int n)
{
    _number = n;
}

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
    bool flag = tag;
    if (tag)
    {
        variable.setSymbol(std::to_string(_number));
        tag = false;
        return true;
    }
    return flag;
}