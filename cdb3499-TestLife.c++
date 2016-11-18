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

#include "Life.h"

using namespace std;

// ----
// test
// ----

template <typename A> struct TestLife : testing::Test { typedef A cell_type; };

typedef testing::Types<ConwayCell, FredkinCell> my_types;

TYPED_TEST_CASE(TestLife, my_types);

TYPED_TEST(TestLife, alive_1) {
  typedef typename TestFixture::cell_type cell_type;

  cell_type c;
  ASSERT_FALSE(c.isAlive());
}

TYPED_TEST(TestLife, evolve1) {
  typedef typename TestFixture::cell_type cell_type;

  vector<int> n = {0, 0, 0, 0, 1, 0, 0, 0, 0};
  cell_type c;
  int res = c.evolve(n, 1, 1, 3, 3);
  ASSERT_EQ(res, 0);
}

TYPED_TEST(TestLife, evolve2) {
  typedef typename TestFixture::cell_type cell_type;

  vector<int> n = {0, 1, 0, 1, 1, 1, 0, 1, 0};
  cell_type c;
  int res = c.evolve(n, 1, 1, 3, 3);
  ASSERT_EQ(res, 4);
}

TYPED_TEST(TestLife, evolve3) {
  typedef typename TestFixture::cell_type cell_type;

  vector<int> n = {0, 1, 0, 1, 0, 1, 0, 1, 0};
  cell_type c;
  int res = c.evolve(n, 0, 0, 3, 3);
  ASSERT_EQ(res, 2);
}

TYPED_TEST(TestLife, toString1) {
  typedef typename TestFixture::cell_type cell_type;

  cell_type c;
  ASSERT_TRUE(c.toString() == '.' || c.toString() == '-');
}

TYPED_TEST(TestLife, toString2) {
  typedef typename TestFixture::cell_type cell_type;

  cell_type c = cell_type('*');
  ASSERT_TRUE(c.toString() == '*' || c.toString() == '-');
}

TYPED_TEST(TestLife, toString3) {
  typedef typename TestFixture::cell_type cell_type;

  cell_type c = cell_type('9');
  ASSERT_TRUE(c.toString() == '.' || c.toString() == '9');
}

TEST(LifeFixture, construct1) {
  FredkinCell fc('9');
  ASSERT_EQ(fc.toString(), '9');
}

TEST(LifeFixture, construct2) {
  FredkinCell fc('+');
  ASSERT_EQ(fc.toString(), '+');
}

TEST(LifeFixture, string1) {
  ConwayCell c('*');
  ASSERT_EQ(c.toString(), '*');
}

TEST(LifeFixture, string2) {
  FredkinCell fc('0');
  ASSERT_EQ(fc.toString(), '0');
}

TEST(LifeFixture, string3) {
  ConwayCell *cc = new ConwayCell('*');
  Cell c = cc;
  ASSERT_EQ(c.toString(), '*');
  delete cc;
}

TEST(LifeFixture, string4) {
  FredkinCell *fc = new FredkinCell('0');
  Cell c = fc;
  ASSERT_EQ(c.toString(), '0');
  delete fc;
}

TEST(LifeFixture, equalop1) {
  ConwayCell a;
  ConwayCell b('*');
  a = b;
  ASSERT_EQ(a.toString(), '*');
}

TEST(LifeFixture, equalop2) {
  FredkinCell a;
  FredkinCell b('0');
  a = b;
  ASSERT_EQ(a.toString(), '0');
}

TEST(LifeFixture, equalop3) {
  ConwayCell *a = new ConwayCell();
  ConwayCell *b = new ConwayCell('*');
  Cell ca = a;
  Cell cb = b;
  ca = cb;
  ASSERT_EQ(ca.toString(), '*');
  delete a;
  delete b;
}

TEST(LifeFixture, equalop4) {
  FredkinCell *a = new FredkinCell();
  FredkinCell *b = new FredkinCell('0');
  Cell ca = a;
  Cell cb = b;
  ca = cb;
  ASSERT_EQ(ca.toString(), '0');
  delete a;
  delete b;
}

TEST(LifeFixture, cellevolve1) {

  vector<int> n = {0, 1, 0, 1, 0, 1, 0, 1, 0};
  ConwayCell *cc = new ConwayCell('*');
  Cell c = cc;
  int res = c.evolve(n, 0, 0, 3, 3);
  ASSERT_EQ(res, 2);
  delete cc;
}

TEST(LifeFixture, cellevolve2) {

  vector<int> n = {0, 1, 0, 1, 0, 1, 0, 1, 0};
  FredkinCell *fc = new FredkinCell('1');
  Cell c = fc;
  int res = c.evolve(n, 0, 0, 3, 3);
  ASSERT_EQ(res, 2);
  delete fc;
}

TEST(LifeFixture, cellevolve3) {

  vector<int> n = {0, 0, 0, 1, 0, 1, 0, 1, 0};
  FredkinCell *fc = new FredkinCell('1');
  Cell c = fc;
  int res = c.evolve(n, 0, 0, 3, 3);
  ASSERT_EQ(res, 1);
  ASSERT_EQ(c.toString(), '*');
  delete fc;
}

TEST(LifeFixture, life1) {
  string st = "000\
               111\
               000\
               ---";
  int x = 4;
  int y = 3;

  Life<FredkinCell> life(x, y);

  for (int i = 0; i < x * y; ++i) {
    FredkinCell c(st[i]);
    life.add(c);
  }
  ostringstream out;
  life.printGrid(out);
  ASSERT_EQ("Generation = 0, Population = 3.\n000\n---\n---\n---\n", out.str());
}

TEST(LifeFixture, life2) {
  string st = "00000000\
               11111111\
               00000000\
               11111111\
               00000000\
               11111111\
               00000000\
               11111111";
  int x = 8;
  int y = 8;

  Life<FredkinCell> life(x, y);

  for (int i = 0; i < x * y; ++i) {
    FredkinCell c(st[i]);
    life.add(c);
  }
  ostringstream out;
  life.printGrid(out);
  ASSERT_EQ("Generation = 0, Population = "
            "24.\n00000000\n--------\n-------1\n1111111-\n--------\n------"
            "00\n000000--\n--------\n",
            out.str());
}

TEST(LifeFixture, life3) {
  string st = "...\
               ***\
               ...\
               ***";
  int x = 4;
  int y = 3;

  Life<ConwayCell> life(x, y);

  for (int i = 0; i < x * y; ++i) {
    ConwayCell c(st[i]);
    life.add(c);
  }
  ostringstream out;
  life.printGrid(out);
  ASSERT_EQ("Generation = 0, Population = 0.\n...\n...\n...\n...\n", out.str());
}

TEST(LifeFixture, life4) {
  string st = "........\
               ********\
               ........\
               ********\
               ........\
               ********\
               ........\
               ********";
  int x = 8;
  int y = 8;

  Life<ConwayCell> life(x, y);

  for (int i = 0; i < x * y; ++i) {
    ConwayCell c(st[i]);
    life.add(c);
  }
  ostringstream out;
  life.printGrid(out);
  ASSERT_EQ("Generation = 0, Population = "
            "8.\n........\n........\n.......*\n*******.\n........\n........\n.."
            "......\n........\n",
            out.str());
}
