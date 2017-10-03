#include "atom.h"
#include "number.h"
#include "variable.h"
using namespace std;
#include <string>

string Variable::value()
{
    return _value;
}

bool Variable::match(string s)
{
    bool ret = _assignable;
    if (_assignable)
    {
        _value = s;
        _assignable = false;
        return true;
    }
    return ret;
}
bool Variable::match(Atom atom)
{
    bool ret = _assignable;
    if (_assignable ||  _value == atom._symbol)
    {
        _value = atom._symbol;
        _assignable = false;
        return true;
    }
    return ret;
}
