#include "atom.h"
#include "number.h"
#include "variable.h"

#include <string>
using std::string;

Atom::Atom(string s)
{
    _symbol = s;
}

string Atom::symbol()
{
    return _symbol;
}

bool Atom::match(Number number)
{
    return false;
}

bool Atom::match(Variable &variable)
{
    bool ret = variable._assignable;
    if (variable._assignable || _symbol == variable.symbol())
    {
        _symbol = variable.symbol();
        variable._assignable = false;
        return true;
    }
    return ret;
}