// --------------------------
// projects/life/TestLife.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include "gtest/gtest.h"

#include <sstream> // ostringstream
#include <string>  // string
#include "Life.h"

using namespace std;

// ----
// test
// ----

TEST(ConwayFixture, test1) {
  ConwayCell c;
  ostringstream s;
  s << c;
  ASSERT_EQ('.', s.str()[0]);
}

TEST(ConwayFixture, test2) {
  ConwayCell c(true);
  ostringstream s;
  s << c;
  ASSERT_EQ('*', s.str()[0]);
}

TEST(ConwayFixture, test3) {
  ConwayCell c(true);
  ConwayCell* c2 = c.clone();
  ASSERT_NE(c2, &c);
  delete c2;
}

TEST(ConwayFixture, test4) {
  ConwayCell c;
  ConwayCell* c2 = c.clone();
  ostringstream s, s2;
  s << c;
  s2 << *c2;
  ASSERT_STREQ(s.str().c_str(), s2.str().c_str());
  delete c2;
}

TEST(ConwayFixture, test5) {
  ConwayCell c(true);
  ConwayCell* c2 = c.clone();
  ostringstream s, s2;
  s << c;
  s2 << *c2;
  ASSERT_STREQ(s.str().c_str(), s2.str().c_str());
  delete c2;
}

TEST(ConwayFixture, test6) {
  ConwayCell c;
  c.evolve(1, 2);
  ostringstream s;
  s << c;
  ASSERT_EQ('*', s.str()[0]);
}

TEST(ConwayFixture, test7) {
  ConwayCell c;
  c.evolve(0, 2);
  ostringstream s;
  s << c;
  ASSERT_EQ('.', s.str()[0]);
}

TEST(ConwayFixture, test8) {
  ConwayCell c(true);
  c.evolve(1, 2);
  ostringstream s;
  s << c;
  ASSERT_EQ('*', s.str()[0]);
}

TEST(ConwayFixture, test9) {
  ConwayCell c(true);
  c.evolve(1, 1);
  ostringstream s;
  s << c;
  ASSERT_EQ('*', s.str()[0]);
}

TEST(ConwayFixture, test10) {
  ConwayCell c(true);
  c.evolve(0, 0);
  ostringstream s;
  s << c;
  ASSERT_EQ('.', s.str()[0]);
}

TEST(ConwayFixture, test11) {
  ConwayCell c(true);
  c.evolve(4, 4);
  ostringstream s;
  s << c;
  ASSERT_EQ('.', s.str()[0]);
}

TEST(FredkinFixture, test1) {
  FredkinCell f;
  ostringstream s;
  s << f;
  ASSERT_EQ('-', s.str()[0]);
}

TEST(FredkinFixture, test2) {
  FredkinCell f(true);
  ostringstream s;
  s << f;
  ASSERT_EQ('0', s.str()[0]);
}

TEST(FredkinFixture, test3) {
  FredkinCell f(true, 4);
  ostringstream s;
  s << f;
  ASSERT_EQ('4', s.str()[0]);
}

TEST(FredkinFixture, test4) {
  FredkinCell f(true, 9);
  ostringstream s;
  s << f;
  ASSERT_EQ('9', s.str()[0]);
}

TEST(FredkinFixture, test5) {
  FredkinCell f(true, 10);
  ostringstream s;
  s << f;
  ASSERT_EQ('+', s.str()[0]);
}

TEST(FredkinFixture, test6) {
  FredkinCell f(true);
  FredkinCell* f2 = f.clone();
  ASSERT_NE(f2, &f);
  delete f2;
}

TEST(FredkinFixture, test7) {
  FredkinCell f;
  FredkinCell* f2 = f.clone();
  ostringstream s, s2;
  s << f;
  s2 << *f2;
  ASSERT_STREQ(s.str().c_str(), s2.str().c_str());
  delete f2;
}

TEST(FredkinFixture, test8) {
  FredkinCell f(true, 3);
  FredkinCell* f2 = f.clone();
  ostringstream s, s2;
  s << f;
  s2 << *f2;
  ASSERT_STREQ(s.str().c_str(), s2.str().c_str());
  delete f2;
}

TEST(FredkinFixture, test9) {
  FredkinCell f;
  f.evolve(1, 2);
  ostringstream s;
  s << f;
  ASSERT_EQ('0', s.str()[0]);
}

TEST(FredkinFixture, test10) {
  FredkinCell f;
  f.evolve(0, 0);
  ostringstream s;
  s << f;
  ASSERT_EQ('-', s.str()[0]);
}

TEST(FredkinFixture, test11) {
  FredkinCell f(true);
  f.evolve(1, 0);
  ostringstream s;
  s << f;
  ASSERT_EQ('1', s.str()[0]);
}

TEST(FredkinFixture, test12) {
  FredkinCell f(true, 2);
  f.evolve(3, 1);
  ostringstream s;
  s << f;
  ASSERT_EQ('3', s.str()[0]);
}

TEST(FredkinFixture, test13) {
  FredkinCell f(true, 1);
  f.evolve(0, 0);
  ostringstream s;
  s << f;
  ASSERT_EQ('-', s.str()[0]);
}

TEST(FredkinFixture, test14) {
  FredkinCell f(true, 1);
  f.evolve(4, 0);
  ostringstream s;
  s << f;
  ASSERT_EQ('-', s.str()[0]);
}

TEST(FredkinFixture, test15) {
  FredkinCell f(false, 1);
  f.evolve(1, 0);
  ostringstream s;
  s << f;
  ASSERT_EQ('1', s.str()[0]);
}

TEST(FredkinFixture, test16) {
  FredkinCell f(true, 1);
  f.evolve(4, 0);
  f.evolve(3, 0);
  f.evolve(1, 0);
  ostringstream s;
  s << f;
  ASSERT_EQ('2', s.str()[0]);
}

TEST(FredkinFixture, test17) {
  FredkinCell f(false, 2);
  f.evolve(4, 0);
  f.evolve(3, 0);
  f.evolve(1, 0);
  f.evolve(3, 0);
  ostringstream s;
  s << f;
  ASSERT_EQ('4', s.str()[0]);
}

TEST(FredkinFixture, test18) {
  FredkinCell f(true, 1);
  f.evolve(4, 0);
  f.evolve(3, 0);
  f.evolve(1, 0);
  f.evolve(2, 0);
  ostringstream s;
  s << f;
  ASSERT_EQ('-', s.str()[0]);
}

TEST(FredkinFixture, test19) {
  FredkinCell f(false, 1);
  f.evolve(4, 0);
  f.evolve(3, 0);
  f.evolve(0, 0);
  f.evolve(1, 0);
  ostringstream s;
  s << f;
  ASSERT_EQ('1', s.str()[0]);
}

TEST(CellFixture, test1) {
  Cell c(new ConwayCell);
  ostringstream s;
  s << c;
  ASSERT_EQ('.',s.str()[0]);
}

TEST(CellFixture, test2) {
  Cell c(new FredkinCell);
  ostringstream s;
  s << c;
  ASSERT_EQ('-',s.str()[0]);
}

TEST(CellFixture, test3) {
  Cell c(new ConwayCell(true));
  ostringstream s;
  s << c;
  ASSERT_EQ('*',s.str()[0]);
}

TEST(CellFixture, test4) {
  Cell c(new FredkinCell(true));
  ostringstream s;
  s << c;
  ASSERT_EQ('0',s.str()[0]);
}

TEST(CellFixture, test5) {
  Cell c(new ConwayCell(true));
  Cell c2(c);
  ostringstream s;
  s << c2;
  ASSERT_EQ('*',s.str()[0]);
}

TEST(CellFixture, test6) {
  Cell c(new ConwayCell);
  Cell c2(new FredkinCell(true, 3));
  c = c2;
  ostringstream s;
  s << c;
  ASSERT_EQ('3',s.str()[0]);
}

TEST(CellFixture, test7) {
  Cell c(new ConwayCell);
  Cell c2(new FredkinCell(true, 4));
  c = c2;
  c.evolve(1, 1);
  ostringstream s, s2;
  s << c;
  s2 << c2;
  ASSERT_NE(s.str()[0],s2.str()[0]);
}

TEST(CellFixture, test8) {
  Cell c(new ConwayCell);
  c.evolve(1, 2);
  ostringstream s;
  s << c;
  ASSERT_EQ('*',s.str()[0]);
}

TEST(CellFixture, test9) {
  Cell c(new FredkinCell);
  c.evolve(1, 4);
  ostringstream s;
  s << c;
  ASSERT_EQ('0',s.str()[0]);
}

TEST(CellFixture, test10) {
  Cell c(new FredkinCell(true));
  c.evolve(3, 1);
  ostringstream s;
  s << c;
  ASSERT_EQ('1',s.str()[0]);
}

TEST(CellFixture, test11) {
  Cell c(new FredkinCell(true), true);
  c.evolve(1, 0);
  c.evolve(1, 0);
  ostringstream s;
  s << c;
  ASSERT_EQ('*',s.str()[0]);
}

TEST(CellFixture, test12) {
  Cell c(new FredkinCell);
  c.evolve(1, 0);
  c.evolve(1, 0);
  c.evolve(3, 0);
  ostringstream s;
  s << c;
  ASSERT_EQ('*',s.str()[0]);
}

TEST(CellFixture, test13) {
  Cell c(new ConwayCell(true), true);
  c.evolve(3, 0);
  c.evolve(3, 0);
  ostringstream s;
  s << c;
  ASSERT_EQ('*',s.str()[0]);
}

TEST(CellFixture, test14) {
  Cell c(new ConwayCell);
  c.evolve(1, 0);
  c.evolve(1, 0);
  ostringstream s;
  s << c;
  ASSERT_EQ('.',s.str()[0]);
}

TEST(CellFixture, test15) {
  Cell c(new FredkinCell(true), true);
  c.evolve(1, 0);
  Cell c2 = c;
  c2.evolve(1, 0);
  ostringstream s;
  s << c2;
  ASSERT_EQ('*',s.str()[0]);
}

TEST(LifeFixture, test1) {
  Life<ConwayCell> L(1, 1);
  L.add_cell(ConwayCell(true), true, 0, 0);
  ostringstream s;
  s << L;
  string s2 = "Generation = 0, Population = 1.\n*\n";
  ASSERT_STREQ(s2.c_str(),s.str().c_str());
}

TEST(LifeFixture, test2) {
  Life<FredkinCell> L(1, 1);
  L.add_cell(FredkinCell(true), true, 0, 0);
  ostringstream s;
  s << L;
  string s2 = "Generation = 0, Population = 1.\n0\n";
  ASSERT_STREQ(s2.c_str(),s.str().c_str());
}

TEST(LifeFixture, test3) {
  Life<Cell> L(1, 1);
  L.add_cell(Cell(new FredkinCell(true),true), true, 0, 0);
  ostringstream s;
  s << L;
  string s2 = "Generation = 0, Population = 1.\n0\n";
  ASSERT_STREQ(s2.c_str(),s.str().c_str());
}

TEST(LifeFixture, test4) {
  Life<ConwayCell> L(1, 1);
  L.add_cell(ConwayCell(true), true, 0, 0);
  L.advance();
  ostringstream s;
  s << L;
  string s2 = "Generation = 1, Population = 0.\n.\n";
  ASSERT_STREQ(s2.c_str(),s.str().c_str());
}

TEST(LifeFixture, test5) {
  Life<FredkinCell> L(1, 1);
  L.add_cell(FredkinCell(true), true, 0, 0);
  L.advance();
  ostringstream s;
  s << L;
  string s2 = "Generation = 1, Population = 0.\n-\n";
  ASSERT_STREQ(s2.c_str(),s.str().c_str());
}

TEST(LifeFixture, test6) {
  Life<ConwayCell> L(2, 2);
  L.add_cell(ConwayCell(true), true, 0, 0);
  L.add_cell(ConwayCell(true), true, 0, 1);
  L.add_cell(ConwayCell(true), true, 1, 0);
  L.advance();
  ostringstream s;
  s << L;
  string s2 = "Generation = 1, Population = 4.\n**\n**\n";
  ASSERT_STREQ(s2.c_str(),s.str().c_str());
}

TEST(LifeFixture, test7) {
  Life<FredkinCell> L(2, 2);
  L.add_cell(FredkinCell(true), true, 0, 0);
  L.add_cell(FredkinCell(true), true, 0, 1);
  L.add_cell(FredkinCell(true), true, 1, 0);
  L.advance();
  ostringstream s;
  s << L;
  string s2 = "Generation = 1, Population = 2.\n-1\n1-\n";
  ASSERT_STREQ(s2.c_str(),s.str().c_str());
}

TEST(LifeFixture, test8) {
  Life<Cell> L(2, 2);
  L.add_cell(Cell(new ConwayCell(true), true), true, 0, 0);
  L.add_cell(Cell(new ConwayCell(true), true), true, 0, 1);
  L.add_cell(Cell(new ConwayCell(true), true), true, 1, 0);
  L.add_cell(Cell(new ConwayCell), false, 1, 1);
  L.advance(2);
  ostringstream s;
  s << L;
  string s2 = "Generation = 2, Population = 4.\n**\n**\n";
  ASSERT_STREQ(s2.c_str(),s.str().c_str());
}

TEST(LifeFixture, test9) {
  Life<FredkinCell> L(2, 2);
  L.add_cell(FredkinCell(true), true, 0, 0);
  L.add_cell(FredkinCell(true), true, 0, 1);
  L.add_cell(FredkinCell(true), true, 1, 0);
  L.advance(2);
  ostringstream s;
  s << L;
  string s2 = "Generation = 2, Population = 0.\n--\n--\n";
  ASSERT_STREQ(s2.c_str(),s.str().c_str());
}

TEST(LifeFixture, test10) {
  Life<FredkinCell> L(2, 2);
  L.add_cell(FredkinCell(true), true, 0, 0);
  L.add_cell(FredkinCell(true), true, 1, 0);
  L.advance();
  ostringstream s;
  s << L;
  string s2 = "Generation = 1, Population = 4.\n10\n10\n";
  ASSERT_STREQ(s2.c_str(),s.str().c_str());
}

TEST(LifeFixture, test11) {
  Life<FredkinCell> L(2, 2);
  L.add_cell(FredkinCell(true), true, 0, 0);
  L.add_cell(FredkinCell(true), true, 1, 0);
  L.advance(2);
  ostringstream s;
  s << L;
  string s2 = "Generation = 2, Population = 0.\n--\n--\n";
  ASSERT_STREQ(s2.c_str(),s.str().c_str());
}

TEST(LifeFixture, test12) {
  Life<Cell> L(2, 2);
  L.add_cell(Cell(new FredkinCell(true), true), true, 0, 0);
  L.add_cell(Cell(new FredkinCell(true), true), true, 1, 0);
  L.add_cell(Cell(new FredkinCell), false, 0, 1);
  L.add_cell(Cell(new FredkinCell), false, 1, 1);
  L.advance();
  ostringstream s;
  s << L;
  string s2 = "Generation = 1, Population = 4.\n10\n10\n";
  ASSERT_STREQ(s2.c_str(),s.str().c_str());
}

TEST(LifeFixture, test13) {
  Life<Cell> L(1, 2);
  L.add_cell(Cell(new ConwayCell(true), true), true, 0, 0);
  L.add_cell(Cell(new FredkinCell), false, 0, 1);
  L.advance();
  ostringstream s;
  s << L;
  string s2 = "Generation = 1, Population = 1.\n.0\n";
  ASSERT_STREQ(s2.c_str(),s.str().c_str());
}

TEST(LifeFixture, test14) {
  Life<Cell> L(1, 2);
  L.add_cell(Cell(new ConwayCell(true), true), true, 0, 0);
  L.add_cell(Cell(new FredkinCell), false, 0, 1);
  L.advance(2);
  ostringstream s;
  s << L;
  string s2 = "Generation = 2, Population = 0.\n.-\n";
  ASSERT_STREQ(s2.c_str(),s.str().c_str());
}

TEST(LifeFixture, test15) {
  Life<Cell> L(1, 2);
  L.add_cell(Cell(new FredkinCell(true), true), true, 0, 0);
  L.add_cell(Cell(new FredkinCell(true), true), true, 0, 1);
  L.advance(2);
  ostringstream s;
  s << L;
  string s2 = "Generation = 2, Population = 2.\n**\n";
  ASSERT_STREQ(s2.c_str(),s.str().c_str());
}
