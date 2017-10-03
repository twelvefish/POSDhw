#include "atom.h"
#include "Number.h"
#include "variable.h"
using namespace std;
#include <string>

bool Var::match(string s)
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
bool Var::match(Atom atom)
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
