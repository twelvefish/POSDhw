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
    if (variable.tags() || _symbol == variable.symbol())
    {
        variable.setSymbol(_symbol);
        variable.setTag(false);
        return true;
    }
    return false;
}