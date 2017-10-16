#include "atom.h"
#include "number.h"
#include "variable.h"

#include <string>
using std::string;

Variable::Variable(string s)
{
    _symbol = s;
}

string Variable::symbol()
{
    return _symbol;
}

string Variable::value()
{
    _value = _value.substr(0,6);
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

bool Variable::match(Number num)
{

    if (_value == num.value())
    {
        tag = false;
        return true;
    }
    else if (tag)
    {
        _value = num.value();
        tag = false;
        return true;
    }
    return false;
}

bool Variable::match(Atom atom)
{
    if (_value == atom.symbol())
    {
        tag = false;
        return true;
    }
    
    if (tag)
    {
        _value = atom.symbol();
        tag = false;
        return true;
    }
    return false;
}

bool Variable::match(Variable &var)
{
    if( _value == "") return false;
    
    test = &var;
    return true;
}
