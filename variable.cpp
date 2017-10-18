#include "atom.h"
#include "number.h"
#include "variable.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Variable::Variable(string s)
{
    _symbol = s;
}

string Variable::symbol() const
{
    return _symbol;
}

string Variable::value() const
{
    if (_value == "")
    {
        return _symbol;
    }
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

bool Variable::match(Term &term)
{
    if (_value != "" && _value != term.value())
        return false;

    bool flag = tag;
    // Variable *var = dynamic_cast<Variable *>(&term);

    if (tag)
    {
        _value = term.value();
        tag = false;

        // if (load.size() != 0)
        // {
        //     for (int i = 0; i < load.size(); i++)
        //     {
        //         load[i]->match(term);
        //     }
        // }
        if (arr[0] != NULL)
        {
            for (int i = 0; i < 5; i++)
            {
                if (arr[i] != NULL)
                {

                    // cout << this->symbol() << "&&&" << i << endl;
                    arr[i]->match(term);
                }
            }
        }
    }

    return flag;
}

// bool Variable::match(Number num)
// {

//     if (_value == num.value())
//     {
//         tag = false;
//         return true;
//     }
//     else if (tag)
//     {
//         _value = num.value();
//         tag = false;
//         return true;
//     }
//     return false;
// }

// bool Variable::match(Atom atom)
// {
//     if (_value == atom.symbol())
//     {
//         tag = false;
//         return true;
//     }

//     if (tag)
//     {
//         _value = atom.symbol();
//         tag = false;
//         return true;
//     }
//     return false;
// }

bool Variable::match(Variable &var)
{
    bool flag = tag;
    if (_value != "")
        return false;

    if (tag)
    {
        if (var.tag)
        {
            arr[index++] = &var;
            var.arr[var.index++] = this;
            // load.push_back(&var);
            // var.load.push_back(this);
        }
        else
        {
            _value = var.value();
            tag = false;
        }
    }

    return flag;
}
