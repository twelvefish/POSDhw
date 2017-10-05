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
    return _value;
}
void Variable::setSymbol(string s){
    _symbol = s;
}
bool Variable::match(Number num)
{
    bool flag = tag;
    if (tag)
    {
        _value = num.value();
        tag = false;
        return true;
    }
    return flag;
}

bool Variable::match(Atom atom)
{
    if(_value == atom.symbol()) return true;
    if (tag || _symbol == atom.symbol())
    {
        _symbol = atom.symbol();
        tag = false;
        return true;
    }
    return false;
}
