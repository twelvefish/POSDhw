#include "atom.h"
#include "number.h"
#include "variable.h"

#include <string>
#include <sstream>
using namespace std;

Number::Number(double n)
{
    _number = n;
}

string  Number::value()
{
    _value = std::to_string(_number);
    return _value;
}

string Number::symbol()
{
    _symbol = std::to_string(_number);
    return _symbol;
}

double Number::num()
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

bool Number::match(Variable &variable)
{
    if (variable.value() == std::to_string(_number))
    {
        variable.tag = false;
        return true;
    }

    if (variable.tag)
    {
        variable.setValue(std::to_string(_number));
        variable.tag = false;
        return true;
    }
    return false;
}