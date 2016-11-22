// --------------------------
// projects/life/TestLife.c++
// Copyright (C) 2016
// Brandon L. Jackson
// --------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include "Life.h"
#include "gtest/gtest.h"
#include <iostream>
#include <sstream>

using namespace std;

// ----
// Checking if construction works, as well as output
// ----

TEST(LifeFixture, toString1) {
  FredkinCell fc;
  ASSERT_EQ(fc.toString(), '-');
}

TEST(LifeFixture, toString2) {
  ConwayCell cc;
  ASSERT_EQ(cc.toString(), '.');
}

TEST(LifeFixture, toString3) {
  Cell c;
  ASSERT_EQ(c.toString(), '\0');
}

TEST(LifeFixture, toString4) {
  FredkinCell *fcc = new FredkinCell();
  Cell fc = fcc;
  ASSERT_EQ(fc.toString(), '-');
  delete fcc;
}

TEST(LifeFixture, toString5) {
  ConwayCell *ccc = new ConwayCell();
  Cell cc = ccc;
  ASSERT_EQ(cc.toString(), '.');
  delete ccc;
}

TEST(LifeFixture, toString6) {
  FredkinCell *fcc = new FredkinCell();
  ConwayCell *ccc = new ConwayCell();
  Cell fc = fcc;
  Cell cc = ccc;
  ASSERT_EQ(fc.toString(), '-');
  ASSERT_EQ(cc.toString(), '.');
  delete fcc;
  delete ccc;
}

TEST(LifeFixture, toString7) {
  FredkinCell *fcc = new FredkinCell();
  ConwayCell *ccc = new ConwayCell();
  Cell fc = fcc;
  Cell cc = ccc;
  Cell c = fc;
  ASSERT_EQ(c.toString(), '-');
  delete fcc;
  delete ccc;
}

TEST(LifeFixture, toString8) {
  FredkinCell *fcc = new FredkinCell();
  ConwayCell *ccc = new ConwayCell();
  Cell fc = fcc;
  Cell cc = ccc;
  cc = fc;
  ASSERT_EQ(cc.toString(), '-');
  delete fcc;
  delete ccc;
}

TEST(LifeFixture, toString9) {
  ConwayCell c('*');
  ASSERT_EQ(c.toString(), '*');
  Cell cc = c.clone();
  ASSERT_EQ(cc.toString(), '*');
}

TEST(LifeFixture, toString10) {
  FredkinCell c('4');
  ASSERT_EQ(c.toString(), '4');
}

TEST(LifeFixture, toString11) {
  FredkinCell *cc = new FredkinCell('4');
  Cell c = cc;
  ASSERT_EQ(c.toString(), '4');
  delete cc;
}

// ----
// Checking if properly alive or dead
// ----

TEST(LifeFixture, Alive1) {
  FredkinCell c('4');
  ASSERT_TRUE(c.isAlive());
}

TEST(LifeFixture, Alive2) {
  FredkinCell c('-');
  ASSERT_FALSE(c.isAlive());
}

TEST(LifeFixture, Alive3) {
  ConwayCell c('*');
  ASSERT_TRUE(c.isAlive());
}

TEST(LifeFixture, Alive4) {
  ConwayCell c('.');
  ASSERT_FALSE(c.isAlive());
}

TEST(LifeFixture, Alive5) {
  FredkinCell *cc = new FredkinCell('4');
  Cell c = cc;
  ASSERT_TRUE(c.isAlive());
  delete cc;
}

TEST(LifeFixture, Alive6) {
  ConwayCell *cc = new ConwayCell('*');
  Cell c = cc;
  ASSERT_TRUE(c.isAlive());
  delete cc;
}

TEST(LifeFixture, Alive7) {
  ConwayCell *cc = new ConwayCell('.');
  Cell c = cc;
  ASSERT_FALSE(c.isAlive());
  delete cc;
}

TEST(LifeFixture, Alive8) {
  FredkinCell *cc = new FredkinCell('-');
  Cell c = cc;
  ASSERT_FALSE(c.isAlive());
  delete cc;
}

// ----
// Construct Life
// ----

TEST(LifeFixture, Life0) {
  string st = "";
  int x = 0;
  int y = 0;
  Life<ConwayCell> game(x, y);
  for (int i = 0; i < x * y; i++) {
    ConwayCell c(st[i]);
    game.add(c);
  }
  ostringstream out;
  game.printAll(out);
  ASSERT_EQ("Generation = 0, Population = 0.\n", out.str());
}

TEST(LifeFixture, Life1) {
  string st = "...";
  int x = 1;
  int y = 3;
  Life<ConwayCell> game(x, y);
  for (int i = 0; i < x * y; i++) {
    ConwayCell c(st[i]);
    game.add(c);
  }
  ostringstream out;
  game.printAll(out);
  ASSERT_EQ("Generation = 0, Population = 0.\n...\n", out.str());
}

TEST(LifeFixture, Life2) {
  string st = "---";
  int x = 1;
  int y = 3;
  Life<FredkinCell> game(x, y);
  for (int i = 0; i < x * y; i++) {
    FredkinCell c(st[i]);
    game.add(c);
  }
  ostringstream out;
  game.printAll(out);
  ASSERT_EQ("Generation = 0, Population = 0.\n---\n", out.str());
}

TEST(LifeFixture, Life3) {
  string st = "---111---000";
  int x = 4;
  int y = 3;
  Life<FredkinCell> game(x, y);
  for (int i = 0; i < x * y; i++) {
    FredkinCell c(st[i]);
    game.add(c);
  }
  ostringstream out;
  game.printAll(out);
  ASSERT_EQ("Generation = 0, Population = 6.\n---\n111\n---\n000\n", out.str());
}

TEST(LifeFixture, Life4) {
  string st = "...***...***";
  int x = 4;
  int y = 3;
  Life<ConwayCell> game(x, y);
  for (int i = 0; i < x * y; i++) {
    ConwayCell c(st[i]);
    game.add(c);
  }
  ostringstream out;
  game.printAll(out);
  ASSERT_EQ("Generation = 0, Population = 6.\n...\n***\n...\n***\n", out.str());
}

TEST(LifeFixture, Life5) {
  string st = "---111---000";
  int x = 4;
  int y = 3;
  Life<Cell> game(x, y);
  for (int i = 0; i < x * y; i++) {
    FredkinCell *cc = new FredkinCell(st[i]);
    Cell c = cc;
    game.add(c);
    delete cc;
  }
  ostringstream out;
  game.printAll(out);
  ASSERT_EQ("Generation = 0, Population = 6.\n---\n111\n---\n000\n", out.str());
}

// ----
// Mutate
// ----

TEST(LifeFixture, Mutate1) {
  string st = "11-11";
  int x = 1;
  int y = 5;
  Life<Cell> game(x, y);
  for (int i = 0; i < x * y; i++) {
    FredkinCell *cc = new FredkinCell(st[i]);
    Cell c = cc;
    game.add(c);
    delete cc;
  }
  ostringstream out;
  game.generation();
  game.printAll(out);
  ASSERT_EQ("Generation = 1, Population = 4.\n**-**\n", out.str());
}

TEST(LifeFixture, Mutate2) {
  string st = "00-00";
  int x = 1;
  int y = 5;
  Life<Cell> game(x, y);
  for (int i = 0; i < x * y; i++) {
    FredkinCell *cc = new FredkinCell(st[i]);
    Cell c = cc;
    game.add(c);
    delete cc;
  }
  ostringstream out;
  game.generation();
  game.generation();
  game.printAll(out);
  ASSERT_EQ("Generation = 2, Population = 4.\n**-**\n", out.str());
}

TEST(LifeFixture, Mutate3) {
  string st = "11-11";
  int x = 1;
  int y = 5;
  Life<Cell> game(x, y);
  for (int i = 0; i < x * y; i++) {
    FredkinCell *cc = new FredkinCell(st[i]);
    Cell c = cc;
    game.add(c);
    delete cc;
  }
  ostringstream out;
  game.generation();
  game.generation();
  game.printAll(out);
  ASSERT_EQ("Generation = 2, Population = 0.\n..-..\n", out.str());
}

TEST(LifeFixture, Mutate4) {
  string st = "11-11";
  int x = 1;
  int y = 5;
  Life<Cell> game(x, y);
  for (int i = 0; i < x * y; i++) {
    FredkinCell *cc = new FredkinCell(st[i]);
    Cell c = cc;
    game.add(c);
    delete cc;
  }
  ostringstream out;
  game.generation();
  game.generation();
  game.generation();
  game.printAll(out);
  ASSERT_EQ("Generation = 3, Population = 0.\n..-..\n", out.str());
}

TEST(LifeFixture, Mutate5) {
  string st = "00";
  int x = 1;
  int y = 2;
  Life<Cell> game(x, y);
  for (int i = 0; i < x * y; i++) {
    FredkinCell *cc = new FredkinCell(st[i]);
    Cell c = cc;
    game.add(c);
    delete cc;
  }
  ostringstream out;
  game.generation();
  game.generation();
  game.printAll(out);
  ASSERT_EQ("Generation = 2, Population = 2.\n**\n", out.str());
}

TEST(LifeFixture, Mutate6) {
  string st = "00";
  int x = 1;
  int y = 2;
  Life<Cell> game(x, y);
  for (int i = 0; i < x * y; i++) {
    FredkinCell *cc = new FredkinCell(st[i]);
    Cell c = cc;
    game.add(c);
    delete cc;
  }
  ostringstream out;
  game.generation();
  game.generation();
  game.generation();
  game.printAll(out);
  ASSERT_EQ("Generation = 3, Population = 0.\n..\n", out.str());
}

TEST(LifeFixture, Mutate7) {
  string st = "00-33";
  int x = 1;
  int y = 5;
  Life<Cell> game(x, y);
  for (int i = 0; i < x * y; i++) {
    FredkinCell *cc = new FredkinCell(st[i]);
    Cell c = cc;
    game.add(c);
    delete cc;
  }
  ostringstream out;
  game.generation();
  game.generation();
  game.printAll(out);
  ASSERT_EQ("Generation = 2, Population = 4.\n**-55\n", out.str());
}

TEST(LifeFixture, Mutate8) {
  string st = "..";
  int x = 1;
  int y = 2;
  Life<Cell> game(x, y);
  for (int i = 0; i < x * y; i++) {
    ConwayCell *cc = new ConwayCell(st[i]);
    Cell c = cc;
    game.add(c);
    delete cc;
  }
  ostringstream out;
  game.generation();
  game.generation();
  game.printAll(out);
  ASSERT_EQ("Generation = 2, Population = 0.\n..\n", out.str());
}

TEST(LifeFixture, Mutate9) {
  string st = "00.--";
  int x = 1;
  int y = 5;
  Life<Cell> game(x, y);
  for (int i = 0; i < x * y; i++) {
    if (i == 2) {
      ConwayCell *cc = new ConwayCell(st[i]);
      Cell c = cc;
      game.add(c);
      delete cc;
    } else {
      FredkinCell *cc = new FredkinCell(st[i]);
      Cell c = cc;
      game.add(c);
      delete cc;
    }
  }
  ostringstream out;
  game.generation();
  game.generation();
  game.printAll(out);
  ASSERT_EQ("Generation = 2, Population = 2.\n**.--\n", out.str());
}

// ----
// Neighbors
// ----

TEST(LifeFixture, Neighbors1) {
  vector<int> n = {1, 1, 1, 0, 0, 0, 1, 0};

  int x = 1;
  int y = 2;
  FredkinCell c('1');
  vector<int> res = c.getBounds2(n, x, y, 2, 4);
  ostringstream out;
  out << "{ ";
  for (int i = 0; i < (int)res.size(); i++) {
    out << res[i] << " ";
  }
  out << "}";
  ASSERT_EQ("{ 0 0 1 }", out.str());
}

TEST(LifeFixture, Neighbors2) {
  vector<int> n = {1, 1, 1, 0, 0, 0, 1, 1};

  int x = 1;
  int y = 2;
  FredkinCell c('1');
  vector<int> res = c.getBounds2(n, x, y, 2, 4);
  ostringstream out;
  out << "{ ";
  for (int i = 0; i < (int)res.size(); i++) {
    out << res[i] << " ";
  }
  out << "}";
  ASSERT_EQ("{ 1 0 1 }", out.str());
}

TEST(LifeFixture, Neighbors3) {
  vector<int> n = {1, 1, 1, 0, 0, 1, 1, 0};

  int x = 1;
  int y = 2;
  FredkinCell c('1');
  vector<int> res = c.getBounds2(n, x, y, 2, 4);
  ostringstream out;
  out << "{ ";
  for (int i = 0; i < (int)res.size(); i++) {
    out << res[i] << " ";
  }
  out << "}";
  ASSERT_EQ("{ 0 1 1 }", out.str());
}

TEST(LifeFixture, Neighbors4) {
  vector<int> n = {1, 1, 1, 0, 0, 1, 1, 1};

  int x = 1;
  int y = 2;
  FredkinCell c('1');
  vector<int> res = c.getBounds2(n, x, y, 2, 4);
  ostringstream out;
  out << "{ ";
  for (int i = 0; i < (int)res.size(); i++) {
    out << res[i] << " ";
  }
  out << "}";
  ASSERT_EQ("{ 1 1 1 }", out.str());
}

TEST(LifeFixture, Neighbors5) {
  vector<int> n = {1, 1, 1, 0, 0, 0, 1, 0};

  int x = 1;
  int y = 2;
  ConwayCell c('*');
  vector<int> res = c.getBounds2(n, x, y, 2, 4);
  ostringstream out;
  out << "{ ";
  for (int i = 0; i < (int)res.size(); i++) {
    out << res[i] << " ";
  }
  out << "}";
  ASSERT_EQ("{ 0 0 1 1 0 }", out.str());
}

TEST(LifeFixture, Neighbors6) {
  vector<int> n = {1, 1, 1, 0, 0, 0, 1, 1};

  int x = 1;
  int y = 2;
  ConwayCell c('*');
  vector<int> res = c.getBounds2(n, x, y, 2, 4);
  ostringstream out;
  out << "{ ";
  for (int i = 0; i < (int)res.size(); i++) {
    out << res[i] << " ";
  }
  out << "}";
  ASSERT_EQ("{ 1 0 1 1 0 }", out.str());
}

TEST(LifeFixture, Neighbors7) {
  vector<int> n = {1, 1, 1, 0, 0, 1, 1, 0};

  int x = 1;
  int y = 2;
  ConwayCell c('*');
  vector<int> res = c.getBounds2(n, x, y, 2, 4);
  ostringstream out;
  out << "{ ";
  for (int i = 0; i < (int)res.size(); i++) {
    out << res[i] << " ";
  }
  out << "}";
  ASSERT_EQ("{ 0 1 1 1 0 }", out.str());
}

TEST(LifeFixture, Neighbors8) {
  vector<int> n = {1, 1, 1, 0, 0, 1, 1, 1};

  int x = 1;
  int y = 2;
  ConwayCell c('*');
  vector<int> res = c.getBounds2(n, x, y, 2, 4);
  ostringstream out;
  out << "{ ";
  for (int i = 0; i < (int)res.size(); i++) {
    out << res[i] << " ";
  }
  out << "}";
  ASSERT_EQ("{ 1 1 1 1 0 }", out.str());
}

TEST(LifeFixture, Neighbors9) {
  vector<int> n = {1, 1, 0, 0};

  int x = 1;
  int y = 1;
  ConwayCell *cc = new ConwayCell('*');
  Cell c = cc;
  vector<int> res = c.getBounds2(n, x, y, 2, 2);
  ostringstream out;
  out << "{ ";
  for (int i = 0; i < (int)res.size(); i++) {
    out << res[i] << " ";
  }
  out << "}";
  delete cc;
  ASSERT_EQ("{ 0 1 1 }", out.str());
}

TEST(LifeFixture, Neighbors10) {
  vector<int> n = {1, 1, 0, 0};

  int x = 1;
  int y = 1;
  FredkinCell *cc = new FredkinCell('0');
  Cell c = cc;
  vector<int> res = c.getBounds2(n, x, y, 2, 2);
  ostringstream out;
  out << "{ ";
  for (int i = 0; i < (int)res.size(); i++) {
    out << res[i] << " ";
  }
  out << "}";
  delete cc;
  ASSERT_EQ("{ 0 1 }", out.str());
}

// ----
// Evolution
// ----

TEST(LifeFixture, Evolve1) {
  int n = 3;
  ConwayCell c('.');
  c.evolve(n);
  ASSERT_TRUE(c.isAlive());
}

TEST(LifeFixture, Evolve2) {
  int n = 2;
  ConwayCell c('.');
  c.evolve(n);
  ASSERT_FALSE(c.isAlive());
}

TEST(LifeFixture, Evolve3) {
  int n = 3;
  FredkinCell c('-');
  c.evolve(n);
  ASSERT_TRUE(c.isAlive());
}

TEST(LifeFixture, Evolve4) {
  int n = 1;
  FredkinCell c('-');
  c.evolve(n);
  ASSERT_TRUE(c.isAlive());
}

TEST(LifeFixture, Evolve5) {
  int n = 2;
  FredkinCell c('-');
  c.evolve(n);
  ASSERT_FALSE(c.isAlive());
}

// ----
// clone
// ----

TEST(LifeFixture, clone1) {
  ConwayCell c('.');
  Cell cc = c.clone();
  ASSERT_EQ(c.isAlive(), cc.isAlive());
}

TEST(LifeFixture, clone2) {
  FredkinCell c('-');
  Cell cc = c.clone();
  ASSERT_EQ(c.isAlive(), cc.isAlive());
  ASSERT_EQ(c.toString(), cc.toString());
}

// ----
// Explicit bounds checking
// ----
template <typename A> struct MultiTest : testing::Test { typedef A cell; };

typedef testing::Types<ConwayCell, FredkinCell> my_types;

TYPED_TEST_CASE(MultiTest, my_types);

TYPED_TEST(MultiTest, getBoundsExplicit1) {
  typedef typename TestFixture::cell cell;

  vector<int> n = {1, 1, 1, 0, 0, 0, 1, 1};

  int x = 1;
  int y = 2;
  cell c;
  vector<int> res = c.getBounds2(n, x, y, 2, 4);
  ostringstream out;
  out << "{ ";
  for (int i = 0; i < (int)res.size(); i++) {
    out << res[i] << " ";
  }
  out << "}";
  if (c.toString() == '.')
    ASSERT_EQ("{ 1 0 1 1 0 }", out.str());
  else
    ASSERT_EQ("{ 1 0 1 }", out.str());
}

TYPED_TEST(MultiTest, getBoundsExplicit2) {
  typedef typename TestFixture::cell cell;

  vector<int> n = {1, 1, 1, 0, 0, 0, 1, 1};

  int x = 1;
  int y = 1;
  cell c;
  vector<int> res = c.getBounds2(n, x, y, 2, 4);
  ostringstream out;
  out << "{ ";
  for (int i = 0; i < (int)res.size(); i++) {
    out << res[i] << " ";
  }
  out << "}";
  if (c.toString() == '.')
    ASSERT_EQ("{ 1 0 1 1 1 }", out.str());
  else
    ASSERT_EQ("{ 1 0 1 }", out.str());
}

TYPED_TEST(MultiTest, getBoundsExplicit3) {
  typedef typename TestFixture::cell cell;

  vector<int> n = {1, 1, 1, 0, 0, 0, 1, 1};

  int x = 0;
  int y = 0;
  cell c;
  vector<int> res = c.getBounds2(n, x, y, 2, 4);
  ostringstream out;
  out << "{ ";
  for (int i = 0; i < (int)res.size(); i++) {
    out << res[i] << " ";
  }
  out << "}";
  if (c.toString() == '.')
    ASSERT_EQ("{ 1 0 0 }", out.str());
  else
    ASSERT_EQ("{ 1 0 }", out.str());
}

TYPED_TEST(MultiTest, getBoundsExplicit4) {
  typedef typename TestFixture::cell cell;

  vector<int> n = {1, 1, 1, 0, 0, 0, 1, 1};

  int x = 1;
  int y = 3;
  cell c;
  vector<int> res = c.getBounds2(n, x, y, 2, 4);
  ostringstream out;
  out << "{ ";
  for (int i = 0; i < (int)res.size(); i++) {
    out << res[i] << " ";
  }
  out << "}";
  if (c.toString() == '.')
    ASSERT_EQ("{ 1 0 1 }", out.str());
  else
    ASSERT_EQ("{ 1 0 }", out.str());
}

TYPED_TEST(MultiTest, getBoundsExplicit5) {
  typedef typename TestFixture::cell cell;

  vector<int> n = {1, 1, 1, 0, 0, 0, 1, 1};

  int x = 0;
  int y = 3;
  cell c;
  vector<int> res = c.getBounds2(n, x, y, 2, 4);
  ostringstream out;
  out << "{ ";
  for (int i = 0; i < (int)res.size(); i++) {
    out << res[i] << " ";
  }
  out << "}";
  if (c.toString() == '.')
    ASSERT_EQ("{ 1 1 1 }", out.str());
  else
    ASSERT_EQ("{ 1 1 }", out.str());
}

// ----
// Explicit Evolve
// ----

TYPED_TEST(MultiTest, EvolveExplicit1) {
  typedef typename TestFixture::cell cell;

  int n = 4;

  cell c('1');
  char ch = c.toString();
  c.evolve(n);
  ostringstream out;
  out << c.toString();
  if (ch == '*')
    ASSERT_EQ(".", out.str());
  else
    ASSERT_EQ("-", out.str());
}

TYPED_TEST(MultiTest, EvolveExplicit2) {
  typedef typename TestFixture::cell cell;

  int n = 3;

  cell c('1');
  char ch = c.toString();
  c.evolve(n);
  ostringstream out;
  out << c.toString();
  if (ch == '*')
    ASSERT_EQ("*", out.str());
  else
    ASSERT_EQ("2", out.str());
}

TYPED_TEST(MultiTest, EvolveExplicit3) {
  typedef typename TestFixture::cell cell;

  int n = 1;

  cell c('1');
  char ch = c.toString();
  c.evolve(n);
  ostringstream out;
  out << c.toString();
  if (ch == '*')
    ASSERT_EQ(".", out.str());
  else
    ASSERT_EQ("2", out.str());
}

TYPED_TEST(MultiTest, EvolveExplicit4) {
  typedef typename TestFixture::cell cell;

  int n = 2;

  cell c('1');
  char ch = c.toString();
  c.evolve(n);
  ostringstream out;
  out << c.toString();
  if (ch == '*')
    ASSERT_EQ("*", out.str());
  else
    ASSERT_EQ("-", out.str());
}

TYPED_TEST(MultiTest, EvolveExplicit5) {
  typedef typename TestFixture::cell cell;

  int n = 0;

  cell c('1');
  char ch = c.toString();
  c.evolve(n);
  ostringstream out;
  out << c.toString();
  if (ch == '*')
    ASSERT_EQ(".", out.str());
  else
    ASSERT_EQ("-", out.str());
}

// ----
// ExtraLife
// ----

TYPED_TEST(MultiTest, MoreLife1) {
  typedef typename TestFixture::cell cell;

  string st = "---";
  int x = 1;
  int y = 3;
  char ch = cell(st[0]).toString();
  Life<cell> game(x, y);
  for (int i = 0; i < x * y; i++) {
    cell c(st[i]);
    game.add(c);
  }
  ostringstream out;
  game.printAll(out);
  if (ch == '*')
    ASSERT_EQ("Generation = 0, Population = 3.\n***\n", out.str());
  else
    ASSERT_EQ("Generation = 0, Population = 0.\n---\n", out.str());
}

TYPED_TEST(MultiTest, MoreLife2) {
  typedef typename TestFixture::cell cell;

  string st = "-1-";
  int x = 1;
  int y = 3;
  char ch = cell(st[0]).toString();
  Life<cell> game(x, y);
  for (int i = 0; i < x * y; i++) {
    cell c(st[i]);
    game.add(c);
  }
  ostringstream out;
  game.printAll(out);
  if (ch == '*')
    ASSERT_EQ("Generation = 0, Population = 3.\n***\n", out.str());
  else
    ASSERT_EQ("Generation = 0, Population = 1.\n-1-\n", out.str());
}

TYPED_TEST(MultiTest, MoreLife3) {
  typedef typename TestFixture::cell cell;

  string st = "111";
  int x = 1;
  int y = 3;
  char ch = cell(st[0]).toString();
  Life<cell> game(x, y);
  for (int i = 0; i < x * y; i++) {
    cell c(st[i]);
    game.add(c);
  }
  ostringstream out;
  game.printAll(out);
  if (ch == '*')
    ASSERT_EQ("Generation = 0, Population = 3.\n***\n", out.str());
  else
    ASSERT_EQ("Generation = 0, Population = 3.\n111\n", out.str());
}

TYPED_TEST(MultiTest, MoreLife4) {
  typedef typename TestFixture::cell cell;

  string st = "-11";
  int x = 1;
  int y = 3;
  char ch = cell(st[0]).toString();
  Life<cell> game(x, y);
  for (int i = 0; i < x * y; i++) {
    cell c(st[i]);
    game.add(c);
  }
  game.generation();
  ostringstream out;
  game.printAll(out);
  if (ch == '*')
    ASSERT_EQ("Generation = 1, Population = 1.\n.*.\n", out.str());
  else
    ASSERT_EQ("Generation = 1, Population = 3.\n022\n", out.str());
}

TYPED_TEST(MultiTest, MoreLife5) {
  typedef typename TestFixture::cell cell;

  string st = "000";
  int x = 1;
  int y = 3;
  char ch = cell(st[0]).toString();
  Life<cell> game(x, y);
  for (int i = 0; i < x * y; i++) {
    cell c(st[i]);
    game.add(c);
  }
  game.generation();
  ostringstream out;
  game.printAll(out);
  if (ch == '*')
    ASSERT_EQ("Generation = 1, Population = 1.\n.*.\n", out.str());
  else
    ASSERT_EQ("Generation = 1, Population = 2.\n1-1\n", out.str());
}

TYPED_TEST(MultiTest, MoreLife6) {
  typedef typename TestFixture::cell cell;

  string st = "1";
  int x = 1;
  int y = 1;
  Life<cell> game(x, y);
  cell c(st[0]);
  game.add(c);
  ASSERT_TRUE(c.isAlive());
}

TYPED_TEST(MultiTest,
           MoreLife7) { // This test is to make sure we don't modify original c
  typedef typename TestFixture::cell cell;

  string st = "0";
  int x = 1;
  int y = 1;
  Life<cell> game(x, y);
  cell c(st[0]);
  game.add(c);
  game.generation();
  ASSERT_TRUE(c.isAlive());
}

TYPED_TEST(MultiTest,
           MoreLife8) { // This test is to make sure we don't modify original c
  typedef typename TestFixture::cell cell;

  string st = "2";
  int x = 1;
  int y = 1;
  Life<cell> game(x, y);
  cell c(st[0]);
  game.add(c);
  game.generation();
  ASSERT_TRUE(c.isAlive());
}