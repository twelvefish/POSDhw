#include "atom.h"
#include "number.h"
#include "variable.h"

#include <iostream>
#include <string>
using namespace std;

Variable::Variable(string s)
{
    _symbol = s;
}

string Variable::symbol() const
{
    return _symbol;
}

string Variable::value() const
{
    return _value;
}
void Variable::setSymbol(string s)
{
    _symbol = s;
}

void Variable::setValue(string v)
{
    _value = v;
}

bool Variable::match(Term &term)
{
    if (_value != "" && _value != term.value())
        return false;

    Variable *var = dynamic_cast<Variable *>(&term);

    if (var)
    {
         _value = var->_value;
        return true;
    }
    else
    {
        if (_value == term.value())
        {
            tag = false;
            return true;
        }
        else if (tag)
        {
            _value = term.value();
            tag = false;
            return true;
        }
    }

    return false;
}

// bool Variable::match(Number num)
// {

//     if (_value == num.value())
//     {
//         tag = false;
//         return true;
//     }
//     else if (tag)
//     {
//         _value = num.value();
//         tag = false;
//         return true;
//     }
//     return false;
// }

// bool Variable::match(Atom atom)
// {
//     if (_value == atom.symbol())
//     {
//         tag = false;
//         return true;
//     }

//     if (tag)
//     {
//         _value = atom.symbol();
//         tag = false;
//         return true;
//     }
//     return false;
// }

// bool Variable::match(Variable &var)
// {
//     if( _value != "") return false;

//     test = &var;
//     return true;
// }
