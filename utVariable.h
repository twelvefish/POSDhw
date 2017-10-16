#ifndef UTVARIABLE_H
#define UTVARIABLE_H
#include "variable.h"
#include "struct.h"
#include "atom.h"
#include "number.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

TEST(Variable, constructor)
{
  Variable X("X");
  ASSERT_EQ("X", X.symbol());
}

TEST(Variable, matching)
{
  Atom tom("tom");
  Variable X("X");
  X.match(tom);
  ASSERT_EQ("tom", X.value());
}

TEST(Variable, haveValue)
{
  Atom tom("tom");
  Atom jerry("jerry");
  Variable X("X");
  ASSERT_TRUE(X.match(tom));
  ASSERT_FALSE(X.match(jerry));
}

// ?- X=2.7182.
// X=2.7182
TEST(Variable, numE_to_varX)
{
  Variable X("X");
  Number num(2.7182);
  X.match(num);
  ASSERT_EQ( "2.7182", X.value());
}

// ?- X=Y, X=1.
// Y=1
TEST(Variable, varY_to_varX_and_num1_to_varX)
{
  // Variable X("X");
  // Variable Y("Y");
  // Number num(1);
  // X.match(Y);
  // X.match(num);
  // ASSERT_EQ( "1", Y.value());

}

// ?- X=Y, Y=1.
// X=1
TEST(Variable, varY_to_varX_and_num1_to_varY)
{
  // Variable X("X");
  // Variable Y("Y");
  // Number num(1);
  // X.match(Y);
  // Y.match(num);
  // ASSERT_EQ( "1", X.value());
}

// ?- X=X, X=1.
// X=1
TEST(Variable, varX_match_varX_and_num1_to_varX)
{
  // Variable X("X");
  // Number num(1);
  // X.match(X);
  // X.match(num);
  // ASSERT_EQ( "1", X.value());
}

// ?- Y=1, X=Y.
// X=1
TEST(Variable, num1_to_varY_and_varX_match_varY)
{
  // Variable Y("Y");
  // Number num(1);
  // Variable X("X");
  // Y.match(num);
  // X.match(num);
  // ASSERT_EQ( "1", X.value());
}

// ?- X=Y, Y=Z, Z=1
// X=1, Y=1, Z=1
TEST(Variable, num1_to_varZ_to_varY_to_varX)
{
}

// ?- X=Y, X=Z, Z=1
// X=1, Y=1, Z=1
TEST(Variable, num1_to_varZ_to_varX_and_varY_to_varX)
{
}

// Give there is a Struct s contains Variable X
// And another Variable Y
// When Y matches Struct s
// Then #symbol() of Y should return "Y"
// And #value() of Y should return "s(X)"
TEST(Variable, Struct1)
{
}

// Give there is a Struct s contains Variable X
// And another Variable Y
// When Y matches Struct s
// And X matches Atom "teddy"
// Then #symbol() of Y should return "Y"
// And #value() of Y should return "s(teddy)"
TEST(Variable, Struct2)
{
}

#endif
