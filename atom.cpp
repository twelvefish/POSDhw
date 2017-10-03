#include "atom.h"
#include "Number.h"
#include "variable.h"
using namespace std;
#include <string>
bool Atom::match(Number number)
{
    return false;
}

bool Atom::match(Var var)
{
    bool ret = var._assignable;
    if (var._assignable)
    {
        _symbol = var._value;
        var._assignable = false;
        return true;
    }
    return ret;
}