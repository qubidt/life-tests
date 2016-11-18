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
#include <string>

#include "Life.h"

using namespace std;

// ----
// Life Test
// constructor
// ----
TEST(LifeFixture, constructor2) {
  std::stringstream actual, expected, in;

  in << "1 5" << endl;
  in << "....*" << endl;
  in << endl;

  expected << "....*" << endl;
  expected << endl;

  istringstream oss(in.str());
  cin.rdbuf(oss.rdbuf());

  Life<ConwayCell> life(3);

  ASSERT_EQ(3, life._generation);
  ASSERT_EQ(1, life._row);
  ASSERT_EQ(5, life._col);
  ASSERT_EQ(1, life._population);

  for (int i = 0; i < life._row; ++i) {
    for (int j = 0; j < life._col; ++j) {
      actual << life._grid[i][j];
    }
    actual << endl;
  }
  actual << endl;

  ASSERT_EQ(expected.str(), actual.str());
}

TEST(LifeFixture, constructor3) {
  std::stringstream actual, expected, in;

  in << "10 10" << endl;
  in << ".........." << endl;
  in << "...*......" << endl;
  in << ".........." << endl;
  in << "...*...*.." << endl;
  in << ".........." << endl;
  in << ".........." << endl;
  in << "....*....." << endl;
  in << ".........." << endl;
  in << "...*......" << endl;
  in << ".........." << endl;
  in << endl;

  expected << ".........." << endl;
  expected << "...*......" << endl;
  expected << ".........." << endl;
  expected << "...*...*.." << endl;
  expected << ".........." << endl;
  expected << ".........." << endl;
  expected << "....*....." << endl;
  expected << ".........." << endl;
  expected << "...*......" << endl;
  expected << ".........." << endl;
  expected << endl;

  istringstream oss(in.str());
  cin.rdbuf(oss.rdbuf());

  Life<ConwayCell> life(10);

  ASSERT_EQ(10, life._generation);
  ASSERT_EQ(10, life._row);
  ASSERT_EQ(10, life._col);
  ASSERT_EQ(5, life._population);

  for (int i = 0; i < life._row; ++i) {
    for (int j = 0; j < life._col; ++j) {
      actual << life._grid[i][j];
    }
    actual << endl;
  }
  actual << endl;

  ASSERT_EQ(expected.str(), actual.str());
}

// ---
// run_life
// ---

TEST(LifeFixture, run_life1) {
  std::stringstream actual, expected, in;

  in << "1 10" << endl;
  in << "*........." << endl;
  in << endl;

  expected << ".........." << endl;
  expected << endl;

  istringstream oss(in.str());
  cin.rdbuf(oss.rdbuf());

  Life<ConwayCell> life(1);

  life.run_life();

  for (int i = 0; i < life._row; ++i) {
    for (int j = 0; j < life._col; ++j) {
      actual << life._grid[i][j];
    }
    actual << endl;
  }
  actual << endl;

  ASSERT_EQ(expected.str(), actual.str());
}

TEST(LifeFixture, run_life2) {
  std::stringstream actual, expected, in;

  in << "1 10" << endl;
  in << "**.***.***" << endl;
  in << endl;

  expected << "....*...*." << endl;
  expected << endl;

  istringstream oss(in.str());
  cin.rdbuf(oss.rdbuf());

  Life<ConwayCell> life(1);

  life.run_life();

  for (int i = 0; i < life._row; ++i) {
    for (int j = 0; j < life._col; ++j) {
      actual << life._grid[i][j];
    }
    actual << endl;
  }
  actual << endl;

  ASSERT_EQ(expected.str(), actual.str());
}

TEST(LifeFixture, run_life3) {
  std::stringstream actual, expected, in;

  in << "3 10" << endl;
  in << "*........." << endl;
  in << ".*........" << endl;
  in << "*........." << endl;
  in << endl;

  expected << ".........." << endl;
  expected << "**........" << endl;
  expected << ".........." << endl;
  expected << endl;

  istringstream oss(in.str());
  cin.rdbuf(oss.rdbuf());

  Life<ConwayCell> life(1);

  life.run_life();

  for (int i = 0; i < life._row; ++i) {
    for (int j = 0; j < life._col; ++j) {
      actual << life._grid[i][j];
    }
    actual << endl;
  }
  actual << endl;

  ASSERT_EQ(expected.str(), actual.str());
}

TEST(LifeFixture, run_life4) {
  std::stringstream actual, expected, in;

  in << "1 10" << endl;
  in << "-----+-+--" << endl;
  in << endl;

  expected << "----0---0-" << endl;
  expected << endl;

  istringstream oss(in.str());
  cin.rdbuf(oss.rdbuf());

  Life<FredkinCell> life(1);

  life.run_life();

  for (int i = 0; i < life._row; ++i) {
    for (int j = 0; j < life._col; ++j) {
      actual << life._grid[i][j];
    }
    actual << endl;
  }
  actual << endl;

  ASSERT_EQ(expected.str(), actual.str());
}

TEST(LifeFixture, run_life5) {
  std::stringstream actual, expected, in;

  in << "3 10" << endl;
  in << "---------+" << endl;
  in << "----------" << endl;
  in << "----------" << endl;
  in << endl;

  expected << "--------0-" << endl;
  expected << "---------0" << endl;
  expected << "----------" << endl;
  expected << endl;

  istringstream oss(in.str());
  cin.rdbuf(oss.rdbuf());

  Life<FredkinCell> life(1);

  life.run_life();

  for (int i = 0; i < life._row; ++i) {
    for (int j = 0; j < life._col; ++j) {
      actual << life._grid[i][j];
    }
    actual << endl;
  }
  actual << endl;

  ASSERT_EQ(expected.str(), actual.str());
}

TEST(LifeFixture, run_life6) {
  std::stringstream actual, expected, in;

  in << "3 10" << endl;
  in << "---------4" << endl;
  in << "--33------" << endl;
  in << "----------" << endl;
  in << endl;

  expected << "--00----0-" << endl;
  expected << "-0440----0" << endl;
  expected << "--00------" << endl;
  expected << endl;

  istringstream oss(in.str());
  cin.rdbuf(oss.rdbuf());

  Life<FredkinCell> life(1);

  life.run_life();

  for (int i = 0; i < life._row; ++i) {
    for (int j = 0; j < life._col; ++j) {
      actual << life._grid[i][j];
    }
    actual << endl;
  }
  actual << endl;

  ASSERT_EQ(expected.str(), actual.str());
}

// ---
// find_neighbors<ConwayCell>
// ---

TEST(LifeFixture, find_neighbors_ConwayCell1) {
  std::stringstream actual, expected, in;

  in << "1 10" << endl;
  in << ".........." << endl;
  in << endl;

  expected << ".........." << endl;
  expected << endl;

  istringstream oss(in.str());
  cin.rdbuf(oss.rdbuf());

  Life<ConwayCell> life(1);

  vector<ConwayCell> neighbors;

  neighbors = life.find_neighbors(neighbors, 0, 1, 1, 10);
  ASSERT_EQ(2, neighbors.size());

  actual << neighbors[0] << "." << neighbors[1] << "......." << endl << endl;
  ASSERT_EQ(expected.str(), actual.str());
}

TEST(LifeFixture, find_neighbors_ConwayCell2) {
  std::stringstream actual, expected, in;

  in << "1 10" << endl;
  in << "......***." << endl;
  in << endl;

  expected << "......***." << endl;
  expected << endl;

  istringstream oss(in.str());
  cin.rdbuf(oss.rdbuf());

  Life<ConwayCell> life(1);

  vector<ConwayCell> neighbors;

  neighbors = life.find_neighbors(neighbors, 0, 7, 1, 10);
  ASSERT_EQ(2, neighbors.size());

  actual << "......" << neighbors[0] << "*" << neighbors[1] << "." << endl
         << endl;
  ASSERT_EQ(expected.str(), actual.str());
}

TEST(LifeFixture, find_neighbors_ConwayCell3) {
  std::stringstream actual, expected, in;

  in << "10 10" << endl;
  in << ".........*" << endl;
  in << ".........." << endl;
  in << ".........." << endl;
  in << "...*...*.." << endl;
  in << ".........." << endl;
  in << ".........." << endl;
  in << "....*....." << endl;
  in << ".........." << endl;
  in << "...*......" << endl;
  in << ".........*" << endl;
  in << endl;

  expected << ".........*" << endl;
  expected << ".........." << endl;
  expected << ".........." << endl;
  expected << "...*...*.." << endl;
  expected << ".........." << endl;
  expected << ".........." << endl;
  expected << "....*....." << endl;
  expected << ".........." << endl;
  expected << "...*......" << endl;
  expected << ".........*" << endl;
  expected << endl;

  istringstream oss(in.str());
  cin.rdbuf(oss.rdbuf());

  Life<ConwayCell> life(10);

  vector<ConwayCell> neighbors;

  neighbors = life.find_neighbors(neighbors, 3, 7, 10, 10);
  ASSERT_EQ(8, neighbors.size());

  actual << ".........*" << endl;
  actual << ".........." << endl;
  actual << "......" << neighbors[0] << neighbors[1] << neighbors[2] << "."
         << endl;
  actual << "...*.." << neighbors[3] << "*" << neighbors[4] << "." << endl;
  actual << "......" << neighbors[5] << neighbors[6] << neighbors[7] << "."
         << endl;
  actual << ".........." << endl;
  actual << "....*....." << endl;
  actual << ".........." << endl;
  actual << "...*......" << endl;
  actual << ".........*" << endl;
  actual << endl;

  ASSERT_EQ(expected.str(), actual.str());
}

// ---
// find_neighbors<FredkinCell>
// ---

TEST(LifeFixture, find_neighbors_FredkinCell1) {
  std::stringstream actual, expected, in;

  in << "1 10" << endl;
  in << "----------" << endl;
  in << endl;

  expected << "----------" << endl;
  expected << endl;

  istringstream oss(in.str());
  cin.rdbuf(oss.rdbuf());

  Life<FredkinCell> life(1);

  vector<FredkinCell> neighbors;

  neighbors = life.find_neighbors(neighbors, 0, 5, 1, 10);
  ASSERT_EQ(2, neighbors.size());

  actual << "----" << neighbors[0] << "-" << neighbors[1] << "---" << endl
         << endl;
  ASSERT_EQ(expected.str(), actual.str());
}

TEST(LifeFixture, find_neighbors_FredkinCell2) {
  std::stringstream actual, expected, in;

  in << "1 10" << endl;
  in << "------+++-" << endl;
  in << endl;

  expected << "------+++-" << endl;
  expected << endl;

  istringstream oss(in.str());
  cin.rdbuf(oss.rdbuf());

  Life<FredkinCell> life(1);

  vector<FredkinCell> neighbors;

  neighbors = life.find_neighbors(neighbors, 0, 8, 1, 10);
  ASSERT_EQ(2, neighbors.size());

  actual << "------+" << neighbors[0] << "+" << neighbors[1] << endl << endl;
  ASSERT_EQ(expected.str(), actual.str());
}

TEST(LifeFixture, find_neighbors_FredkinCell3) {
  std::stringstream actual, expected, in;

  in << "10 10" << endl;
  in << "----------" << endl;
  in << "---------+" << endl;
  in << "+---------" << endl;
  in << "----------" << endl;
  in << "++++++++++" << endl;
  in << "----------" << endl;
  in << "+---------" << endl;
  in << "----------" << endl;
  in << "------+---" << endl;
  in << "----------" << endl;
  in << endl;

  expected << "----------" << endl;
  expected << "---------+" << endl;
  expected << "+---------" << endl;
  expected << "----------" << endl;
  expected << "++++++++++" << endl;
  expected << "----------" << endl;
  expected << "+---------" << endl;
  expected << "----------" << endl;
  expected << "------+---" << endl;
  expected << "----------" << endl;
  expected << endl;

  istringstream oss(in.str());
  cin.rdbuf(oss.rdbuf());

  Life<FredkinCell> life(10);

  vector<FredkinCell> neighbors;

  neighbors = life.find_neighbors(neighbors, 8, 6, 10, 10);
  ASSERT_EQ(4, neighbors.size());

  actual << "----------" << endl;
  actual << "---------+" << endl;
  actual << "+---------" << endl;
  actual << "----------" << endl;
  actual << "++++++++++" << endl;
  actual << "----------" << endl;
  actual << "+---------" << endl;
  actual << "------" << neighbors[0] << "---" << endl;
  actual << "-----" << neighbors[1] << "+" << neighbors[2] << "--" << endl;
  actual << "------" << neighbors[3] << "---" << endl;
  actual << endl;

  ASSERT_EQ(expected.str(), actual.str());
}

TEST(LifeFixture, find_neighbors_FredkinCell4) {
  std::stringstream actual, expected, in;

  in << "1 10" << endl;
  in << "---2-5----" << endl;
  in << endl;

  expected << "---2-5----" << endl;
  expected << endl;

  istringstream oss(in.str());
  cin.rdbuf(oss.rdbuf());

  Life<FredkinCell> life(1);

  vector<FredkinCell> neighbors;

  neighbors = life.find_neighbors(neighbors, 0, 4, 1, 10);
  ASSERT_EQ(2, neighbors.size());

  actual << "---" << neighbors[0] << "-" << neighbors[1] << "----" << endl
         << endl;
  ASSERT_EQ(expected.str(), actual.str());
}

// ---
// find_neighbors<Cell>
// ---

TEST(LifeFixture, find_neighbors_Cell1) {
  std::stringstream actual, expected, in;

  in << "1 10" << endl;
  in << ".........." << endl;
  in << endl;

  expected << ".........." << endl;
  expected << endl;

  istringstream oss(in.str());
  cin.rdbuf(oss.rdbuf());

  Life<Cell> life(1);

  vector<Cell> neighbors;

  neighbors = life.find_neighbors(neighbors, 0, 1, 1, 10);
  ASSERT_EQ(2, neighbors.size());

  actual << neighbors[0] << neighbors[1] << "........" << endl << endl;
  ASSERT_EQ(expected.str(), actual.str());
}

TEST(LifeFixture, find_neighbors_Cell2) {
  std::stringstream actual, expected, in;

  in << "3 10" << endl;
  in << "......***." << endl;
  in << "......***." << endl;
  in << "......***." << endl;
  in << endl;

  expected << "......***." << endl;
  expected << "......***." << endl;
  expected << "......***." << endl;
  expected << endl;

  istringstream oss(in.str());
  cin.rdbuf(oss.rdbuf());

  Life<Cell> life(1);

  vector<Cell> neighbors;

  neighbors = life.find_neighbors(neighbors, 1, 7, 3, 10);
  ASSERT_EQ(8, neighbors.size());

  actual << "......" << neighbors[0] << neighbors[1] << neighbors[2] << "."
         << endl;
  actual << "......" << neighbors[3] << "*" << neighbors[4] << "." << endl;
  actual << "......" << neighbors[5] << neighbors[6] << neighbors[7] << "."
         << endl
         << endl;
  ASSERT_EQ(expected.str(), actual.str());
}

TEST(LifeFixture, find_neighbors_Cell3) {
  std::stringstream actual, expected, in;

  in << "3 5" << endl;
  in << "+++--" << endl;
  in << "+++--" << endl;
  in << "+++--" << endl;
  in << endl;

  expected << "+++--" << endl;
  expected << "+++--" << endl;
  expected << "+++--" << endl;
  expected << endl;

  istringstream oss(in.str());
  cin.rdbuf(oss.rdbuf());

  Life<Cell> life(1);

  vector<Cell> neighbors;

  neighbors = life.find_neighbors(neighbors, 1, 1, 3, 5);
  ASSERT_EQ(4, neighbors.size());

  actual << "+" << neighbors[0] << "+--" << endl;
  actual << neighbors[1] << "+" << neighbors[2] << "--" << endl;
  actual << "+" << neighbors[3] << "+--" << endl << endl;
  ASSERT_EQ(expected.str(), actual.str());
}

// trivial test of calling pring_grid without an error
TEST(LifeFixture, print_grid) {
  std::stringstream actual, expected, in;

  in << "1 10" << endl;
  in << ".........." << endl;
  in << endl;

  expected << ".........." << endl;
  expected << endl;

  istringstream oss(in.str());
  cin.rdbuf(oss.rdbuf());

  Life<Cell> life(1);

  // ignores the cout output
  streambuf *old = cout.rdbuf(0);
  life.print_grid(1);
  cout.rdbuf(old);

  ASSERT_TRUE(1);
}

TEST(CellFixture, default_constructor) {
  try {
    Cell x;
    ASSERT_TRUE(1);
  } catch (...) {
    ASSERT_FALSE(1);
  }
}

TEST(CellFixture, constructor1) {
  Cell x;
  ASSERT_TRUE(x._p == nullptr);
}

TEST(CellFixture, constructor2) {
  Cell x('*');
  if (ConwayCell *const c = dynamic_cast<ConwayCell *>(x._p))
    ASSERT_TRUE(1);
  else
    ASSERT_FALSE(1);
}

TEST(CellFixture, constructor3) {
  Cell x('+');
  if (FredkinCell *const f = dynamic_cast<FredkinCell *>(x._p))
    ASSERT_TRUE(1);
  else
    ASSERT_FALSE(1);
}

TEST(CellFixture, constructor4) {
  Cell x('5');
  if (FredkinCell *const f = dynamic_cast<FredkinCell *>(x._p))
    ASSERT_TRUE(1);
  else
    ASSERT_FALSE(1);
}

// pass garbage char and test if nullptr print out properly
TEST(CellFixture, constructor5) {
  std::stringstream s;
  Cell c('a');
  s << c;
  ASSERT_EQ("0", s.str());
}

// ---
// is_fredkin
// ---

// test Cell with nullptr of AbstractCell
TEST(CellFixture, is_fredkin1) {
  Cell c;
  ASSERT_FALSE(c.is_fredkin());
}

// test Cell with conway
TEST(CellFixture, is_fredkin2) {
  Cell c('*');
  ASSERT_FALSE(c.is_fredkin());
}

// test Cell with fredkin
TEST(CellFixture, is_fredkin3) {
  Cell c('-');
  ASSERT_TRUE(c.is_fredkin());
}

TEST(CellFixture, is_fredkin4) {
  Cell c('5');
  ASSERT_TRUE(c.is_fredkin());
}

// ---
// check_neighbors
// ---
TEST(CellFixture, check_neighbors1) {
  vector<Cell> neighbors(0);
  Cell c('-');
  ASSERT_TRUE(c.check_neighbors(neighbors) == 0);
}

TEST(CellFixture, check_neighbors2) {
  vector<Cell> neighbors;
  Cell a('*');
  neighbors.push_back(a);
  Cell c('-');
  ASSERT_EQ(c.check_neighbors(neighbors), 1);
}

TEST(CellFixture, check_neighbors3) {
  vector<Cell> neighbors;
  Cell a('*');
  Cell b('*');
  Cell d('*');
  Cell e('.');
  neighbors.push_back(a);
  neighbors.push_back(b);
  neighbors.push_back(d);
  neighbors.push_back(e);
  Cell c('-');
  ASSERT_EQ(c.check_neighbors(neighbors), 3);
}

TEST(CellFixture, check_neighbors4) {
  vector<Cell> neighbors;
  Cell a('+');
  Cell b('-');
  Cell d('4');
  Cell e('.');
  neighbors.push_back(a);
  neighbors.push_back(b);
  neighbors.push_back(d);
  neighbors.push_back(e);
  Cell c('-');
  ASSERT_EQ(c.check_neighbors(neighbors), 2);
}

/// ---
// evolve
// ---
// ConwayCell
// live to dead with condition of less than 2 alive
TEST(CellFixture, evolve1) {
  vector<Cell> neighbors(0);
  Cell c('*');
  bool status = c.evolve(neighbors);
  ASSERT_FALSE(status);
}

// live to dead with condition of more than 3 alive
TEST(CellFixture, evolve2) {
  vector<Cell> neighbors(0);
  Cell a('*');
  Cell b('*');
  Cell d('*');
  Cell e('*');
  neighbors.push_back(a);
  neighbors.push_back(b);
  neighbors.push_back(d);
  neighbors.push_back(e);
  Cell c('*');
  bool status = c.evolve(neighbors);
  ASSERT_FALSE(status);
}

/// dead to live of conway cell with condition of 3 alive
TEST(CellFixture, evolve3) {
  vector<Cell> neighbors;
  Cell a('*');
  Cell b('*');
  Cell d('*');
  neighbors.push_back(a);
  neighbors.push_back(b);
  neighbors.push_back(d);
  Cell c('.');
  bool status = c.evolve(neighbors);
  ASSERT_TRUE(status);
}

// FredkinCell
// live to dead with condition of 0
TEST(CellFixture, evolve4) {
  vector<Cell> neighbors(0);
  Cell c('+');
  bool status = c.evolve(neighbors);
  ASSERT_FALSE(status);
}

/// live to dead with condition of 2
TEST(CellFixture, evolve5) {
  vector<Cell> neighbors;
  Cell a('+');
  Cell e('+');
  neighbors.push_back(a);
  neighbors.push_back(e);
  Cell c('+');
  bool status = c.evolve(neighbors);
  ASSERT_FALSE(status);
}

/// live to dead with condition of 4
TEST(CellFixture, evolve6) {
  vector<Cell> neighbors;
  Cell a('+');
  Cell b('+');
  Cell d('+');
  Cell e('+');
  neighbors.push_back(a);
  neighbors.push_back(b);
  neighbors.push_back(d);
  neighbors.push_back(e);
  Cell c('+');
  bool status = c.evolve(neighbors);
  ASSERT_FALSE(status);
}

// dead to live with condition of 1 alive
TEST(CellFixture, evolve7) {
  vector<Cell> neighbors;
  Cell a('+');
  neighbors.push_back(a);
  Cell c('-');
  bool status = c.evolve(neighbors);
  ASSERT_TRUE(status);
}

// dead to live with condition of 3 alive
TEST(CellFixture, evolve8) {
  vector<Cell> neighbors;
  Cell a('+');
  Cell b('+');
  Cell d('+');
  neighbors.push_back(a);
  neighbors.push_back(b);
  neighbors.push_back(d);
  Cell c('.');
  bool status = c.evolve(neighbors);
  ASSERT_TRUE(status);
}

// live to live with condition of 3 alive
TEST(CellFixture, evolve9) {
  vector<Cell> neighbors;
  Cell a('+');
  Cell b('+');
  Cell d('+');
  neighbors.push_back(a);
  neighbors.push_back(b);
  neighbors.push_back(d);
  Cell c('3');
  bool status = c.evolve(neighbors);
  ASSERT_TRUE(status);
}

// Special case of FredkinCell
TEST(CellFixture, evolve10) {
  vector<Cell> neighbors;
  Cell a('+');
  Cell b('+');
  Cell d('+');
  neighbors.push_back(a);
  neighbors.push_back(b);
  neighbors.push_back(d);
  Cell c('1');
  bool status = c.evolve(neighbors);
  ASSERT_TRUE(status);

  std::stringstream s;
  s << c;
  ASSERT_EQ("*", s.str());
}

// ---
// operator <<
//
TEST(CellFixture, left_shift_1) {
  Cell c('.');
  std::stringstream s;
  s << c;
  ASSERT_EQ(".", s.str());
}

TEST(CellFixture, left_shift_2) {
  Cell c('*');
  std::stringstream s;
  s << c;
  ASSERT_EQ("*", s.str());
}

TEST(CellFixture, left_shift_3) {
  Cell c('+');
  std::stringstream s;
  s << c;
  ASSERT_EQ("+", s.str());
}

TEST(CellFixture, left_shift_4) {
  Cell c('-');
  std::stringstream s;
  s << c;
  ASSERT_EQ("-", s.str());
}

TEST(CellFixture, left_shift_5) {
  Cell c('0');
  std::stringstream s;
  s << c;
  ASSERT_EQ("0", s.str());
}

// ---
// update_symbol
// ---
// Just call update_symbol with _p = nullptr and check no error occurs
TEST(CellFixture, update_symbol1) {
  try {
    Cell c;
    c.update_symbol();
    ASSERT_FALSE(1);
  } catch (std::nullptr_t) {
    ASSERT_TRUE(1);
  }
}

TEST(CellFixture, update_symbol2) {
  Cell c('*');
  c.update_symbol();

  std::stringstream actual;
  actual << c;
  ASSERT_EQ("*", actual.str());
}

TEST(CellFixture, update_symbol3) {
  Cell c('+');
  c.update_symbol();

  std::stringstream actual;
  actual << c;
  ASSERT_EQ("+", actual.str());
}

TEST(CellFixture, update_symbol4) {
  Cell c('-');
  c.update_symbol();

  std::stringstream actual;
  actual << c;
  ASSERT_EQ("-", actual.str());
}

// ----
// Cell Test
// evolve
// ----

// ----
// Cell Test
// check_neighbors
// ----

// ----
// FredkinCell Test
// constructors
// ----

// default constructor
TEST(FredkinFixture, default_constructor) {
  FredkinCell x;
  ASSERT_EQ(false, x.was_alive());
  ASSERT_EQ(false, x.is_alive());
}

// symbol constructor

TEST(FredkinFixture, constructor_1) {
  FredkinCell x('+');
  ASSERT_EQ(true, x.was_alive());
  ASSERT_EQ(true, x.is_alive());
}

TEST(FredkinFixture, constructor_2) {
  FredkinCell x('-');
  ASSERT_EQ(false, x.was_alive());
  ASSERT_EQ(false, x.is_alive());
}

// ----
// FredkinCell Test
// is_alive
// ----

TEST(FredkinFixture, is_alive_1) {
  FredkinCell x;
  ASSERT_EQ(false, x.is_alive());
}

TEST(FredkinFixture, is_alive_2) {
  FredkinCell x('+');
  ASSERT_EQ(true, x.is_alive());
}

TEST(FredkinFixture, is_alive_3) {
  FredkinCell x('2');
  ASSERT_EQ(true, x.is_alive());
}

TEST(FredkinFixture, is_alive_4) {
  FredkinCell x('2');
  x.evolve(0);
  ASSERT_EQ(false, x.is_alive());
}

TEST(FredkinFixture, is_alive_5) {
  FredkinCell x('-');
  x.evolve(1);
  ASSERT_EQ(true, x.is_alive());
}

// ----
// FredkinCell Test
// was_alive
// ----

TEST(FredkinFixture, was_alive_1) {
  FredkinCell x;
  ASSERT_EQ(false, x.was_alive());
}

TEST(FredkinFixture, was_alive_2) {
  FredkinCell x('+');
  ASSERT_EQ(true, x.was_alive());
}

TEST(FredkinFixture, was_alive_3) {
  FredkinCell x('2');
  ASSERT_EQ(true, x.was_alive());
}

TEST(FredkinFixture, was_alive_4) {
  FredkinCell x('2');
  x.evolve(0);
  ASSERT_EQ(true, x.was_alive());
}

// ----
// FredkinCell Test
// update_symbol
// ----

TEST(FredkinFixture, update_symbol_1) {
  FredkinCell x;
  ASSERT_EQ(false, x.is_alive());
  ASSERT_EQ(false, x.was_alive());
  x.evolve(1);
  ASSERT_EQ(true, x.is_alive());
  ASSERT_EQ(false, x.was_alive());
  x.update_symbol();
  ASSERT_EQ(true, x.is_alive());
  ASSERT_EQ(true, x.was_alive());
}

// test that when you call update without having made any changes, nothing
// changes
TEST(FredkinFixture, update_symbol_2) {
  FredkinCell x('+');
  ASSERT_EQ(x.was_alive(), true);
  ASSERT_EQ(x.is_alive(), true);
  x.update_symbol();
  ASSERT_EQ(x.was_alive(), true);
  ASSERT_EQ(x.is_alive(), true);
}

TEST(FredkinFixture, update_symbol_3) {
  FredkinCell x('9');
  x.evolve(1);
  ASSERT_EQ('+', x._new_symbol);
  ASSERT_EQ('9', x._old_symbol);
  x.update_symbol();
  ASSERT_EQ('+', x._new_symbol);
  ASSERT_EQ('+', x._old_symbol);
}

// ----
// FredkinCell Test
// evolve(int alive_neighbors)
// ----

TEST(FredkinFixture, evolve_1) {
  FredkinCell x('-');
  x.evolve(1);
  ASSERT_EQ('\0', x._new_symbol);
}

TEST(FredkinFixture, evolve_2) {
  FredkinCell x('+');
  x.evolve(0);
  x.update_symbol();
  ASSERT_EQ('-', x._new_symbol);
  x.evolve(1);
  x.update_symbol();
  ASSERT_EQ(10, x._age);
  ASSERT_EQ('+', x._new_symbol);
}

TEST(FredkinFixture, evolve_3) {
  FredkinCell x('+');
  x.evolve(0);
  ASSERT_EQ('-', x._new_symbol);
}

TEST(FredkinFixture, evolve_4) {
  FredkinCell x('2');
  ASSERT_EQ(2, x._age);
  x.evolve(1);
  ASSERT_EQ(3, x._age);
  ASSERT_EQ('\x3', x._new_symbol);
}

TEST(FredkinFixture, evolve_5) {
  FredkinCell x('+');
  ASSERT_EQ('+', x._new_symbol);
  x.evolve(1);
  ASSERT_EQ(11, x._age);
}

TEST(FredkinFixture, evolve_6) {
  FredkinCell x('+');
  ASSERT_EQ('+', x._new_symbol);
  x.evolve(4);
  ASSERT_EQ(10, x._age);
  ASSERT_EQ('-', x._new_symbol);
}

// ----
// FredkinCell Test
// evolve(vector<FredkinCell> neighbors)
// ----

TEST(FredkinFixture, evolve_7) {
  FredkinCell x('-');

  // create 3 live neighbors
  vector<FredkinCell> neighbors;
  neighbors.push_back(FredkinCell('+'));
  neighbors.push_back(FredkinCell('+'));
  neighbors.push_back(FredkinCell('+'));
  x.evolve(neighbors);
  ASSERT_EQ('\0', x._new_symbol);
}

TEST(FredkinFixture, evolve_8) {
  FredkinCell x('*');
  vector<FredkinCell> neighbors;
  neighbors.push_back(FredkinCell('*'));
  neighbors.push_back(FredkinCell('*'));

  x.evolve(neighbors);
  x.update_symbol();
  ASSERT_EQ('-', x._new_symbol);

  neighbors.push_back(FredkinCell('*'));

  x.evolve(neighbors);
  ASSERT_EQ('\0', x._new_symbol);
}

TEST(FredkinFixture, evolve_9) {
  FredkinCell x('2');
  vector<FredkinCell> neighbors;
  neighbors.push_back(FredkinCell('*'));
  x.evolve(neighbors);
  ASSERT_EQ('\x3', x._new_symbol);
}

// ----
// FredkinCell Test
// check_neighbors(vector<FredkinCell> neighbors)
// ----

TEST(FredkinFixture, check_neighbors_1) {
  FredkinCell x('+');
  vector<FredkinCell> neighbors;
  neighbors.push_back(FredkinCell('+'));
  neighbors.push_back(FredkinCell('+'));
  neighbors.push_back(FredkinCell('+'));
  ASSERT_EQ(3, x.check_neighbors(neighbors));
}

TEST(FredkinFixture, check_neighbors_2) {
  FredkinCell x;
  vector<FredkinCell> neighbors;
  neighbors.push_back(FredkinCell('*'));
  neighbors.push_back(FredkinCell('2'));
  neighbors.push_back(FredkinCell('*'));
  ASSERT_EQ(3, x.check_neighbors(neighbors));
}

TEST(FredkinFixture, check_neighbors_3) {
  FredkinCell x;
  vector<FredkinCell> neighbors;
  neighbors.push_back(FredkinCell('-'));
  neighbors.push_back(FredkinCell('-'));
  neighbors.push_back(FredkinCell('-'));
  ASSERT_EQ(0, x.check_neighbors(neighbors));
}

TEST(FredkinFixture, check_neighbors_4) {
  FredkinCell x;
  vector<FredkinCell> neighbors;
  ASSERT_EQ(0, x.check_neighbors(neighbors));
}

TEST(FredkinFixture, check_neighbors_5) {
  FredkinCell x;
  vector<FredkinCell> neighbors;
  neighbors.push_back(FredkinCell('3'));
  neighbors.push_back(FredkinCell('2'));
  neighbors.push_back(FredkinCell('5'));
  ASSERT_EQ(3, x.check_neighbors(neighbors));
}
// ----
// FredkinCell Test
// print_N(vector<FredkinCell> n)
// ----

// ----
// FredkinCell Test
// is_age_two()
// ----

TEST(FredkinFixture, is_age_two_1) {
  FredkinCell x;
  ASSERT_EQ(false, x.is_age_two());
}

TEST(FredkinFixture, is_age_two_2) {
  FredkinCell x('+');
  ASSERT_EQ(false, x.is_age_two());
}

TEST(FredkinFixture, is_age_two_3) {
  FredkinCell x('2');
  ASSERT_EQ(true, x.is_age_two());
}

// ----
// ConwayCell Test
// constructors
// ----

// default constructor
TEST(ConwayFixture, default_constructor) {
  ConwayCell x;
  ASSERT_EQ(false, x.was_alive());
  ASSERT_EQ(false, x.is_alive());
}

// symbol constructor

TEST(ConwayFixture, constructor_1) {
  ConwayCell x('*');
  ASSERT_EQ(true, x.was_alive());
  ASSERT_EQ(true, x.is_alive());
}

TEST(ConwayFixture, constructor_2) {
  ConwayCell x('.');
  ASSERT_EQ(false, x.was_alive());
  ASSERT_EQ(false, x.is_alive());
}
// ----
// ConwayCell Test
// evolve(int alive_neighbors)
// ----
TEST(ConwayFixture, evolve_1) {
  ConwayCell x('.');
  x.evolve(3);
  ASSERT_EQ('*', x._new_symbol);
}

TEST(ConwayFixture, evolve_2) {
  ConwayCell x('*');
  x.evolve(0);
  x.update_symbol();
  ASSERT_EQ('.', x._new_symbol);
  x.evolve(3);
  x.update_symbol();
  ASSERT_EQ('*', x._new_symbol);
}

TEST(ConwayFixture, evolve_3) {
  ConwayCell x('*');
  x.evolve(0);
  ASSERT_EQ('.', x._new_symbol);
}

// ----
// ConwayCell Test
// evolve(vector<ConwayCell> neighbors)
// ----
TEST(ConwayFixture, evolve_4) {
  ConwayCell x('.');

  // create 3 live neighbors
  vector<ConwayCell> neighbors;
  neighbors.push_back(ConwayCell('*'));
  neighbors.push_back(ConwayCell('*'));
  neighbors.push_back(ConwayCell('*'));
  x.evolve(neighbors);
  ASSERT_EQ('*', x._new_symbol);
}

TEST(ConwayFixture, evolve_5) {
  ConwayCell x('*');
  vector<ConwayCell> neighbors;
  neighbors.push_back(ConwayCell('*'));

  x.evolve(neighbors);
  x.update_symbol();
  ASSERT_EQ('.', x._new_symbol);

  neighbors.push_back(ConwayCell('*'));
  neighbors.push_back(ConwayCell('*'));

  x.evolve(neighbors);
  ASSERT_EQ('*', x._new_symbol);
}

TEST(ConwayFixture, evolve_6) {
  ConwayCell x('*');
  vector<ConwayCell> neighbors;
  neighbors.push_back(ConwayCell('*'));
  x.evolve(neighbors);
  ASSERT_EQ('.', x._new_symbol);
}
// ----
// ConwayCell Test
// check_neighbors
// ----

TEST(ConwayFixture, check_neighbors_1) {
  ConwayCell x('*');
  vector<ConwayCell> neighbors;
  neighbors.push_back(ConwayCell('*'));
  neighbors.push_back(ConwayCell('*'));
  neighbors.push_back(ConwayCell('*'));
  ASSERT_EQ(3, x.check_neighbors(neighbors));
}

TEST(ConwayFixture, check_neighbors_2) {
  ConwayCell x('*');
  vector<ConwayCell> neighbors;
  neighbors.push_back(ConwayCell('*'));
  neighbors.push_back(ConwayCell('.'));
  neighbors.push_back(ConwayCell('*'));
  ASSERT_EQ(2, x.check_neighbors(neighbors));
}

TEST(ConwayFixture, check_neighbors_3) {
  ConwayCell x('*');
  vector<ConwayCell> neighbors;
  neighbors.push_back(ConwayCell('.'));
  neighbors.push_back(ConwayCell('.'));
  neighbors.push_back(ConwayCell('.'));
  ASSERT_EQ(0, x.check_neighbors(neighbors));
}

TEST(ConwayFixture, check_neighbors_4) {
  ConwayCell x('*');
  vector<ConwayCell> neighbors;
  ASSERT_EQ(0, x.check_neighbors(neighbors));
}

// ----
// ConwayCell Test
// was_alive
// ----

TEST(ConwayFixture, was_alive_1) {
  ConwayCell x;
  ASSERT_EQ(false, x.was_alive());
}

TEST(ConwayFixture, was_alive_2) {
  ConwayCell x('*');
  ASSERT_EQ(true, x.was_alive());
}

TEST(ConwayFixture, was_alive_3) {
  ConwayCell x('.');
  ASSERT_EQ(false, x.was_alive());
}

TEST(ConwayFixture, was_alive_4) {
  ConwayCell x('.');
  x.evolve(3);
  ASSERT_EQ(false, x.was_alive());
}

// ----
// ConwayCell Test
// is_alive
// ----

TEST(ConwayFixture, is_alive_1) {
  ConwayCell x;
  ASSERT_EQ(false, x.is_alive());
}

TEST(ConwayFixture, is_alive_2) {
  ConwayCell x('*');
  ASSERT_EQ(true, x.is_alive());
}

TEST(ConwayFixture, is_alive_3) {
  ConwayCell x('.');
  ASSERT_EQ(false, x.is_alive());
}

TEST(ConwayFixture, is_alive_4) {
  ConwayCell x('.');
  x.evolve(3);
  ASSERT_EQ(true, x.is_alive());
}
// ----
// ConwayCell Test
// update_symbol
// ----

TEST(ConwayFixture, update_symbol_1) {
  ConwayCell x;
  ASSERT_EQ(false, x.is_alive());
  ASSERT_EQ(false, x.was_alive());
  x.evolve(3);
  ASSERT_EQ(true, x.is_alive());
  ASSERT_EQ(false, x.was_alive());
  x.update_symbol();
  ASSERT_EQ(true, x.is_alive());
  ASSERT_EQ(true, x.was_alive());
}

TEST(ConwayFixture, update_symbol_2) {
  ConwayCell x('*');
  ASSERT_EQ(x.was_alive(), true);
  ASSERT_EQ(x.is_alive(), true);
  x.update_symbol();
  ASSERT_EQ(x.was_alive(), true);
  ASSERT_EQ(x.is_alive(), true);
}

TEST(ConwayFixture, update_symbol_3) {
  ConwayCell x('.');
  x.evolve(3);
  ASSERT_EQ('*', x._new_symbol);
  ASSERT_EQ('.', x._old_symbol);
  x.update_symbol();
  ASSERT_EQ('*', x._new_symbol);
  ASSERT_EQ('*', x._old_symbol);
}
