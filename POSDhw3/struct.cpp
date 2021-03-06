#include "number.h"
#include "variable.h"
#include "term.h"
#include "atom.h"
#include <string>
#include <vector>
using namespace std;

// Struct(Atom const &name, std::vector<Term *> args) : _name(name), _args(args)
// {
// }

// Term *args(int index)
// {
//     return _args[index];
// }

// Atom const & name()
// {
//     return _name;
// }

// string symbol() const
// {
//     string ret = _name.symbol() + "(";
//     for (int i = 0; i < _args.size() - 1; i++)
//     {
//         ret += _args[i]->symbol() + ", ";
//     }
//     ret += _args[_args.size() - 1]->symbol() + ")";
//     return ret;
// }

// bool match(Term &term)
// {
//     Struct *ps = dynamic_cast<Struct *>(&term);
//     if (ps)
//     {
//         if (!_name.match(ps->_name))
//             return false;
//         if (_args.size() != ps->_args.size())
//             return false;
//         for (int i = 0; i < _args.size(); i++)
//         {
//             if (_args[i]->symbol() != ps->_args[i]->symbol())
//                 return false;
//         }
//         return true;
//     }
//     return false;
// }