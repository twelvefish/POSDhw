#include "number.h"
#include "variable.h"
#include "atom.h"
#include <string>
#include <iostream>
using std::string;
using namespace std;


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

bool Number::match(Variable &variable)
{
    if (variable.tag || variable.symbol() == std::to_string(_number))
    {
        variable.setSymbol(std::to_string(_number));
        variable.tag = false;
        return true;
    }
    return false;
    
}