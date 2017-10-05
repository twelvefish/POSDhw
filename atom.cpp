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

string Atom::value()
{
    return _value;
}


bool Atom::match(Number number)
{
    return false;
}

bool Atom::match(Variable &variable)
{
    if (variable.tag || _symbol  == variable.value())
    {
        variable.setValue(_symbol );
        variable.tag = false;
        return true;
    }
    return false;
}