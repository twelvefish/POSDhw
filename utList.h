#ifndef UTLIST_H
#define UTLIST_H

#include <string>
using namespace std;

#include "list.h"
#include "struct.h"
#include "atom.h"
#include "number.h"
#include "variable.h"
#include <iostream>

// When create a new list without any item
// Then #symbol() of the list should return "[]"
TEST(List, constructor)
{
  List any;
  ASSERT_EQ("[]", any.symbol());
}

// Given there are two perfect Numbers: 8128, 496
// When create a new list with the perfect Number
// Then #symbol() of the list should return "[496, 8128]"
TEST(List, Numbers)
{
  Number num(496);
  Number num1(8128);
  vector<Term *> arr = {&num, &num1};
  List ls(arr);
  cout << ls.symbol() << endl;
  ASSERT_EQ("[496, 8128]", ls.symbol());
}

// Given there are two atoms: "terence_tao", "alan_mathison_turing"
// When create a new list with the Atoms
// Then #symbol() of the list should return "[terence_tao, alan_mathison_turing]"
TEST(List, Atoms)
{
  Atom terence_tao("terence_tao");
  Atom alan_mathison_turing("alan_mathison_turing");
  vector<Term *> arr = {&terence_tao, &alan_mathison_turing};
  List ls(arr);
  cout << ls.symbol() << endl;
  ASSERT_EQ("[terence_tao, alan_mathison_turing]", ls.symbol());
}

// Given there are two variables: X, Y
// When create a new list with the variables
// Then #symbol() of the list should return "[X, Y]"
TEST(List, Vars)
{
  Variable X("X");
  Variable Y("Y");
  vector<Term *> arr = {&X, &Y};
  List ls(arr);
  cout << ls.symbol() << endl;
  ASSERT_EQ("[X, Y]", ls.symbol());
}

// ?- tom = [496, X, terence_tao].
// false.
TEST(List, matchToAtomShouldFail)
{
  Number num(496);
  Variable X("X");
  Atom terence_tao("terence_tao");
  Atom tom("tom");
  vector<Term *> arr = {&num, &X, &terence_tao};
  List ls(arr);
  cout << tom.match(ls) << endl;
  cout << ls.match(tom) << endl;
  ASSERT_FALSE(tom.match(ls));
  ASSERT_FALSE(ls.match(tom));
}

// ?- 8128 = [496, X, terence_tao].
// false.
TEST(List, matchToNumberShouldFail)
{
  Number num(496);
  Variable X("X");
  Atom terence_tao("terence_tao");
  Number num1(8128);
  vector<Term *> arr = {&num, &X, &terence_tao};
  List ls(arr);
  cout << num1.match(ls) << endl;
  cout << ls.match(num1) << endl;
  ASSERT_FALSE(num1.match(ls));
  ASSERT_FALSE(ls.match(num1));
}

// ?- s(X) = [496, X, terence_tao].
// false.
TEST(List, matchToStructShouldFail)
{
  Number num(496);
  Variable X("X");
  Atom terence_tao("terence_tao");
  vector<Term *> arr = {&num, &X, &terence_tao};
  List ls(arr);
  vector<Term *> v = {&X};
  Struct s(Atom("s"), v);
  cout << "&& " << s.isList << endl;
  ASSERT_FALSE(s.match(ls));
  ASSERT_FALSE(ls.match(s));
}

// ?- Y = [496, X, terence_tao].
// Y = [496, X, terence_tao].
TEST(List, matchToVarShouldSucceed)
{
  Number num(496);
  Variable X("X");
  Atom terence_tao("terence_tao");
  vector<Term *> arr = {&num, &X, &terence_tao};
  List ls(arr);
  Variable Y("Y");
  ASSERT_TRUE(Y.match(ls));
  ASSERT_TRUE(ls.match(Y));
}

// ?- X = [496, X, terence_tao].
// false.
TEST(List, matchToVarOccuredInListShouldFail)
{
  Number num(496);
  Variable X("X");
  Atom terence_tao("terence_tao");
  vector<Term *> arr = {&num, &X, &terence_tao};
  List ls(arr);
  ASSERT_FALSE(X.match(ls));
  ASSERT_FALSE(ls.match(X));
}

// ?- [496, X, terence_tao] = [496, X, terence_tao].
// true.
TEST(List, matchToSameListShouldSucceed)
{
  Number num(496);
  Variable X("X");
  Atom terence_tao("terence_tao");
  vector<Term *> arr = {&num, &X, &terence_tao};
  List ls(arr);
  ASSERT_TRUE(ls.match(ls));
}
// ?- [496, X, terence_tao] = [496, Y, terence_tao].
// true.
TEST(List, matchToSameListWithDiffVarNameShouldSucceed)
{
  Number num(496);
  Variable X("X");
  Variable Y("Y");
  Atom terence_tao("terence_tao");
  vector<Term *> arr = {&num, &X, &terence_tao};
  vector<Term *> arr1 = {&num, &Y, &terence_tao};
  List ls(arr);
  List ls1(arr1);
  ASSERT_TRUE(ls.match(ls1));
}
// ?- [496, X, terence_tao] = [496, 8128, terence_tao].
// X = 8128.
TEST(List, matchToVarToAtominListShouldSucceed)
{
  Number num(496);
  Variable X("X");
  Number num1(8128);
  Atom terence_tao("terence_tao");
  vector<Term *> arr = {&num, &X, &terence_tao};
  vector<Term *> arr1 = {&num, &num1, &terence_tao};
  List ls(arr);
  List ls1(arr1);
  ASSERT_TRUE(ls.match(ls1));
  ASSERT_EQ("8128", X.value());
}

// ?- Y = [496, X, terence_tao], X = alan_mathison_turing.
// Y = [496, alan_mathison_turing, terence_tao],
// X = alan_mathison_turing.
TEST(List, matchVarinListToAtomShouldSucceed)
{
  // Number num(496);
  // Variable X("X");
  // Variable Y("Y");
  // Atom terence_tao("terence_tao");
  // Atom alan_mathison_turing("alan_mathison_turing");
  // vector<Term *> arr = {&num, &X, &terence_tao};
  // List ls(arr);
  // ASSERT_TRUE(X.match(alan_mathison_turing));
  // ASSERT_TRUE(Y.match(ls));
  // cout << Y.value() <<endl;
  // cout << ls.value() <<endl;
  // ASSERT_EQ("[496, alan_mathison_turing, terence_tao]", ls.value());
}

// Example:
// ?- [first, second, third] = [H|T].
// H = first, T = [second, third].
TEST(List, headAndTailMatching1)
{
  Atom f("first");
  Atom s("second");
  Atom t("third");
  vector<Term *> args = {&f, &s, &t};
  List l(args);
  EXPECT_EQ(string("first"), l.head()->symbol());
  EXPECT_EQ(string("[second, third]"), l.tail()->value());
}

// Example:
// ?- [first, second, third] = [first, H|T].
// H = second, T = [third].
TEST(List, headAndTailMatching2)
{
  Atom f("first"), s("second"), t("third");
  vector<Term *> args = {&f, &s, &t};
  List l(args);

  EXPECT_EQ(string("second"), l.tail()->head()->value());
  EXPECT_EQ(string("[third]"), l.tail()->tail()->value());
}

// ?- [[first], second, third] = [H|T].
// H = [first], T = [second, third].
TEST(List, headAndTailMatching3)
{
  Atom f("first"), s("second"), t("third");
  vector<Term *> arr = {&f};
  List ls(arr);
  vector<Term *> arr1 = {&ls, &s, &t};
  List ls1(arr1);

  EXPECT_EQ(string("[first]"), ls1.head()->value());
  EXPECT_EQ(string("[second, third]"), ls1.tail()->value());
}

// ?- [first, second, third] = [first, second, H|T].
// H = third, T = [].
TEST(List, headAndTailMatching4)
{
  Atom f("first"), s("second"), t("third");
  vector<Term *> arr = {&f, &s, &t};
  List l(arr);

  EXPECT_EQ(string("third"), l.tail()->tail()->head()->value());
  EXPECT_EQ(string("[]"), l.tail()->tail()->tail()->value());
}

// Given there is a empty list
// When client still want to get the head of list
// Then it should throw a string: "Accessing head in an empty list" as an exception.
TEST(List, emptyExecptionOfHead)
{
  List ls;
  try
  {
    ls.head();
  }
  catch (const string err)
  {
    EXPECT_EQ(string("Accessing head in an empty list"), err);
  }
}

// Given there is a empty list
// When client still want to get the tail of list
// Then it should throw a string: "Accessing tail in an empty list" as an exception.
TEST(List, emptyExecptionOfTail)
{
  List ls;
   try
  {
    ls.tail();
  }
  catch (const string err)
  {
    EXPECT_EQ(string("Accessing tail in an empty list"), err);
  }
}

#endif
