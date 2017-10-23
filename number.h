#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include <sstream>
using std::string;
class Number : public Term
{
public:
  Number(double db) : Term(db) {}
  bool isNumber = true;
  bool match(Term &a)
  {
    if (a.isList)
    {
      return false;
    }
  }
};

#endif