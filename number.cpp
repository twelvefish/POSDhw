#include "atom.h"
#include "number.h"
#include "variable.h"

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

Number::Number(double n)
{
    _number = n;
    text = to_string(_number);
    _symbol = to_string(_number).substr(0, text.find("0"));
}

// string Number::value() const
// {
//     return _value;
// }

string Number::symbol() const
{
    return _symbol;
}

double Number::num()
{
    return _number;
}

bool Number::match(Term &term)
{
    return symbol() == term.symbol();
}

// bool Number::match(Number number)
// {
//     return _number == number.num();
// }

// bool Number::match(Atom atom)
// {
//     return false;
// }

// bool Number::match(Variable &variable)
// {
//     if (variable.value() == std::to_string(_number))
//     {
//         variable.tag = false;
//         return true;
//     }

//     if (variable.tag)
//     {
//         variable.setValue(std::to_string(_number));
//         variable.tag = false;
//         return true;
//     }
//     return false;
// }