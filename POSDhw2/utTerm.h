#ifndef UTTERM_H
#define UTTERM_H

#include "Number.h"
#include "atom.h"
#include "variable.h"

//test Number.value()
TEST(Number, ctor)
{
    Number num("Love", "1314");
    ASSERT_EQ("1314", num.value());
}

//test Number.symbol()
TEST(Number, symbol)
{
    Number num("apple", "10000");
    ASSERT_EQ("apple", num.symbol());
}

//?- 25=25.
//true.
TEST(Number, matchSuccess)
{
    Number num1("Dog", "25");
    Number num2("Cat", "25");
    ASSERT_TRUE(num1.match(num2));
}

//?- 25=0.
//false.
TEST(Number, matchFailureDiffValue)
{
    Number num1("Dog", "25");
    Number num2("Cat", "0");
    ASSERT_FALSE(num1.match(num2));
}
//?- 25=tom.
//false.
TEST(Number, matchFailureDiffConstant)
{
    Number num1("Dog", "25");
    Atom atom("tom");
    ASSERT_FALSE(num1.match(atom));
}
//?- 25=X.
//true.
TEST(Number, matchSuccessToVar)
{
    Number num1("Dog", "25");
    Variable var("X");
    ASSERT_TRUE(num1.match(var));
}

//?- tom=25.
//false.
TEST(Atom, matchFailureDiffConstant)
{
    Atom atom("tom");
    Number num1("Dog", "25");
    ASSERT_FALSE(atom.match(num1));
}

// ?- tom = X.
// X = tom.
TEST(Atom, matchSuccessToVar)
{
    Atom atom("tom");
    Variable var("X");
    ASSERT_TRUE(atom.match(var));
}

// ?- X=tom, tom=X.
// X = tom.
TEST(Atom, matchSuccessToVarInstantedToDiffConstant)
{
    Atom atom("tom");
    Variable var("X");
    ASSERT_TRUE(atom.match(var));
    ASSERT_TRUE(var.match(atom));
}

// ?- X=jerry, tom=X.
// false.
TEST(Atom, matchFailureToVarInstantedToDiffConstant)
{
    Variable var("X");
    Atom atom("jerry");
    Atom atom1("tom");
    ASSERT_TRUE(var.match(atom));
    ASSERT_FALSE(atom1.match(var));
}

// ?- X = 5.
// X = 5.
TEST(Var, matchSuccessToNumber)
{
    Variable var("X");
    Number num("Love", "5");
    ASSERT_TRUE(var.match(num.value()));
}

// ?- X=25, X= 100.
// false.
TEST(Var, matchFailureToTwoDiffNumbers)
{
    Variable var("X");
    Number num("Love", "5");
    Number num1("apple", "100");
    ASSERT_TRUE(var.match(num.value()));
    ASSERT_FALSE(var.match(num1.value()));
}

// ?- X=tom, X= 25.
// false.
TEST(Var, matchSuccessToAtomThenFailureToNumber)
{
    Variable var("X");
    Atom atom1("tom");
    Number num("Love", "25");
    ASSERT_TRUE(var.match(atom1));
    ASSERT_FALSE(var.match(num.value()));
}
//?- tom=X, 25=X.
//false.
TEST(Var, matchSuccessToAtomThenFailureToNumber2)
{
    Atom atom1("tom");
    Variable var("X");
    Number num("Love", "25");
    ASSERT_TRUE(atom1.match(var));
    ASSERT_FALSE(num.match(var));
}
//?- X=tom, X=tom.
//true.
TEST(Var, reAssignTheSameAtom)
{
    Variable var("X");
    Atom atom1("tom");
    ASSERT_TRUE(var.match(atom1));
    ASSERT_TRUE(var.match(atom1));
}
#endif
