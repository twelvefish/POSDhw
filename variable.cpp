#include "atom.h"
#include "number.h"
#include "variable.h"
using namespace std;
#include <string>

Variable::Variable(string s)
{
    _symbol = s;
}

string Variable::symbol()
{
    return _symbol;
}

int Variable::value()
{
    return _value;
}

bool Variable::match(Number num)
{
    bool ret = _assignable;
    if (_assignable)
    {
        _value = num.value();
        _assignable = false;
        return true;
    }
    return ret;
}

bool Variable::match(Atom atom)
{
    if (_assignable || _symbol == atom.symbol())
    {
        _symbol = atom.symbol();
        _assignable = false;
        return true;
    }
    return false;
}
