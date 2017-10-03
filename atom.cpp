#include "atom.h"
#include "Number.h"
#include "variable.h"
using namespace std;
#include <string>
bool Atom::match(Number number)
{
    return false;
}

bool Atom::match(Variable variable)
{
    bool ret = variable._assignable;
    if (variable._assignable)
    {
        _symbol = variable._value;
        variable._assignable = false;
        return true;
    }
    return ret;
}