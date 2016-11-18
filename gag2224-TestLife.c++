// --------------------------
// projects/life/TestLife.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include "Life.h"
#include "gtest/gtest.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string life_test1 = "4 4\n....\n....\n....\n....\n";
string life_test2 = "4 4\n----\n----\n----\n----\n";
string life_test3 = "4 4\n*.*.\n0-0-\n*.*.\n0-0-\n";

// ---------------
// LifeConstructor
// ---------------

TEST(LifeFixture, constructor1) {
  istringstream ss(life_test1);

  Life<ConwayCell> life(ss);

  ASSERT_EQ(life._x, 4);
  ASSERT_EQ(life._y, 4);
  ASSERT_EQ(life._gen, 0);
  ASSERT_EQ(life._pop, 0);
}

TEST(LifeFixture, constructor2) {
  istringstream ss(life_test2);

  Life<FredkinCell> life(ss);

  ASSERT_EQ(life._x, 4);
  ASSERT_EQ(life._y, 4);
  ASSERT_EQ(life._gen, 0);
  ASSERT_EQ(life._pop, 0);
}

TEST(LifeFixture, constructor3) {
  istringstream ss(life_test3);

  Life<Cell> life(ss);

  ASSERT_EQ(life._x, 4);
  ASSERT_EQ(life._y, 4);
  ASSERT_EQ(life._gen, 0);
  ASSERT_EQ(life._pop, 8);
}

// --------------------
// LifecomputeNeighbors
// --------------------

TEST(LifeFixture, computeNeighbors1) {
  vector<vector<int>> counts = {{0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0}};
  istringstream ss(life_test1);

  Life<ConwayCell> life(ss);
  life.computeNeighbors();

  ASSERT_EQ(life._counts, counts);
}

TEST(LifeFixture, computeNeighbors2) {
  vector<vector<int>> counts = {{0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0}};
  istringstream ss(life_test2);

  Life<FredkinCell> life(ss);
  life.computeNeighbors();

  ASSERT_EQ(life._counts, counts);
}

TEST(LifeFixture, computeNeighbors3) {
  vector<vector<int>> counts = {{1, 4, 1, 2},
                                {2, 2, 2, 1},
                                {2, 6, 2, 3},
                                {1, 2, 1, 1}};
  istringstream ss(life_test3);

  Life<Cell> life(ss);
  life.computeNeighbors();

  ASSERT_EQ(life._counts, counts);
}

// ---------------
// LifeexecuteTurn
// ---------------

TEST(LifeFixture, executeTurn1) {
  istringstream ss(life_test1);

  Life<ConwayCell> life(ss);
  life.executeTurn();

  ostringstream ss1;
  ss1 << life;

  ASSERT_EQ(ss1.str(), "\nGeneration = 1, Population = 0.\n....\n....\n....\n....\n");
}

TEST(LifeFixture, executeTurn2) {
  istringstream ss(life_test2);

  Life<FredkinCell> life(ss);
  life.executeTurn();

  ostringstream ss1;
  ss1 << life;

  ASSERT_EQ(ss1.str(), "\nGeneration = 1, Population = 0.\n----\n----\n----\n----\n");
}

TEST(LifeFixture, executeTurn3) {
  istringstream ss(life_test3);

  Life<Cell> life(ss);
  life.executeTurn();

  ostringstream ss1;
  ss1 << life;

  ASSERT_EQ(ss1.str(), "\nGeneration = 1, Population = 7.\n....\n---0\n*.**\n1-10\n");
}

// ---------
// Lifeprint
// ---------

TEST(LifeFixture, print1) {
  istringstream ss(life_test1);

  Life<ConwayCell> life(ss);

  ostringstream ss1;
  ss1 << life;

  ASSERT_EQ(ss1.str(), "\nGeneration = 0, Population = 0.\n....\n....\n....\n....\n");
}

TEST(LifeFixture, print2) {
  istringstream ss(life_test2);

  Life<FredkinCell> life(ss);

  ostringstream ss1;
  ss1 << life;

  ASSERT_EQ(ss1.str(), "\nGeneration = 0, Population = 0.\n----\n----\n----\n----\n");
}

TEST(LifeFixture, print3) {
  istringstream ss(life_test3);

  Life<Cell> life(ss);

  ostringstream ss1;
  ss1 << life;

  ASSERT_EQ(ss1.str(), "\nGeneration = 0, Population = 8.\n*.*.\n0-0-\n*.*.\n0-0-\n");
}

// ---------------
// Cellconstructor
// ---------------

TEST(CellFixture, constructor1) {
  Cell x;

  ASSERT_EQ(x._p, nullptr);
}

TEST(CellFixture, constructor2) {
  Cell x('.');

  ASSERT_TRUE(x._p != nullptr);
  ASSERT_FALSE(x.alive());
}

TEST(CellFixture, constructor3) {
  Cell x('-');

  ASSERT_TRUE(x._p != nullptr);
  ASSERT_FALSE(x.alive());
}

// -------------------
// Cellcopyconstructor
// -------------------

TEST(CellFixture, copyconstructor1) {
  Cell y;

  ASSERT_EQ(y._p, nullptr);

  Cell x(y);

  ASSERT_EQ(x._p, nullptr);
}

TEST(CellFixture, copyconstructor2) {
  Cell y('.');

  ASSERT_TRUE(y._p != nullptr);
  ASSERT_FALSE(y.alive());

  Cell x(y);

  ASSERT_TRUE(y._p != nullptr);
  ASSERT_FALSE(x.alive());
}

TEST(CellFixture, copyconstructor3) {
  Cell y('-');

  ASSERT_TRUE(y._p != nullptr);
  ASSERT_FALSE(y.alive());

  Cell x(y);

  ASSERT_TRUE(y._p != nullptr);
  ASSERT_FALSE(x.alive());
}

// ------------------
// Cellcopyassignment
// ------------------

TEST(CellFixture, copyassignment1) {
  Cell y;

  ASSERT_EQ(y._p, nullptr);

  Cell x = y;

  ASSERT_EQ(x._p, nullptr);
}

TEST(CellFixture, copyassignment2) {
  Cell y('.');

  ASSERT_TRUE(y._p != nullptr);
  ASSERT_FALSE(y.alive());

  Cell x = y;

  ASSERT_TRUE(y._p != nullptr);
  ASSERT_FALSE(x.alive());
}

TEST(CellFixture, copyassignment3) {
  Cell y('-');

  ASSERT_TRUE(y._p != nullptr);
  ASSERT_FALSE(y.alive());

  Cell x = y;

  ASSERT_TRUE(y._p != nullptr);
  ASSERT_FALSE(x.alive());
}

// --------------
// Celldestructor
// --------------

TEST(CellFixture, destructor1) {
  Cell x;

  ASSERT_EQ(x._p, nullptr);

  x.~Cell();

  ASSERT_EQ(x._p, nullptr);
}

TEST(CellFixture, destructor2) {
  Cell x('.');

  ASSERT_TRUE(x._p != nullptr);

  x.~Cell();

  ASSERT_EQ(x._p, nullptr);
}

TEST(CellFixture, destructor3) {
  Cell x('.');

  ASSERT_TRUE(x._p != nullptr);

  x.~Cell();

  ASSERT_EQ(x._p, nullptr);
}

// ---------
// Cellalive
// ---------

TEST(CellFixture, alive1) {
  Cell x('.');

  ASSERT_FALSE(x.alive());
}

TEST(CellFixture, alive2) {
  Cell x('-');

  ASSERT_FALSE(x.alive());
}

TEST(CellFixture, alive3) {
  Cell x('*');

  ASSERT_TRUE(x.alive());
}

// ----------
// Cellupdate
// ----------

TEST(CellFixture, update1) {
  Cell x('.');

  x.update(0);

  ASSERT_FALSE(x.alive());
}

TEST(CellFixture, update2) {
  Cell x('.');

  x.update(3);

  ASSERT_TRUE(x.alive());
}

TEST(CellFixture, update3) {
  Cell x('-');

  x.update(1);

  ASSERT_TRUE(x.alive());
}

// -----------------
// CellfindNeighbors
// -----------------

TEST(CellFixture, findNeighbors1) {
  bool neighbors[8] = {};
  Cell x('.');

  ASSERT_EQ(x.findNeighbors(neighbors), 0);
}

TEST(CellFixture, findNeighbors2) {
  bool neighbors[8] = {};
  Cell x('-');

  ASSERT_EQ(x.findNeighbors(neighbors), 0);
}

TEST(CellFixture, findNeighbors3) {
  bool neighbors[8] = {true, false, true, false, true, false, true, false};
  Cell x('-');

  ASSERT_EQ(x.findNeighbors(neighbors), 4);
}

// ---------
// Cellprint
// ---------

TEST(CellFixture, print1) {
  Cell x('.');

  ostringstream ss;

  ss << x;

  ASSERT_EQ(ss.str(), ".");
}

TEST(CellFixture, print2) {
  Cell x('-');

  ostringstream ss;

  ss << x;

  ASSERT_EQ(ss.str(), "-");
}

TEST(CellFixture, print3) {
  Cell x('*');

  ostringstream ss;

  ss << x;

  ASSERT_EQ(ss.str(), "*");
}

// --------
// Cellread
// --------

TEST(CellFixture, read1) {
  Cell x;

  istringstream ss(".");
  ostringstream ss1;

  ss >> x;
  ss1 << x;

  ASSERT_TRUE(x._p != nullptr);
  ASSERT_EQ(ss1.str(), ".");
  ASSERT_FALSE(x.alive());
}

TEST(CellFixture, read2) {
  Cell x;

  istringstream ss("-");
  ostringstream ss1;

  ss >> x;
  ss1 << x;

  ASSERT_TRUE(x._p != nullptr);
  ASSERT_EQ(ss1.str(), "-");
  ASSERT_FALSE(x.alive());
}

TEST(CellFixture, read3) {
  Cell x;

  istringstream ss("*");
  ostringstream ss1;

  ss >> x;
  ss1 << x;

  ASSERT_TRUE(x._p != nullptr);
  ASSERT_EQ(ss1.str(), "*");
  ASSERT_TRUE(x.alive());
}

// ---------------------
// ConwayCellconstructor
// ---------------------

TEST(ConwayCellFixture, constructor1) {
  ConwayCell x('.');

  ASSERT_FALSE(x.alive());
}

TEST(ConwayCellFixture, constructor2) {
  ConwayCell x('.');

  ASSERT_FALSE(x.alive());
}

TEST(ConwayCellFixture, constructor3) {
  ConwayCell x('*');

  ASSERT_TRUE(x.alive());
}

// ----------------
// ConwayCellmutate
// ----------------

TEST(ConwayCellFixture, mutate1) {
  ConwayCell x('.');

  ASSERT_FALSE(x.mutate(0));
}

TEST(ConwayCellFixture, mutate2) {
  ConwayCell x('.');

  ASSERT_FALSE(x.mutate(8));
}

TEST(ConwayCellFixture, mutate3) {
  ConwayCell x('*');

  ASSERT_FALSE(x.mutate(4));
}

// ---------------
// ConwayCellclone
// ---------------

TEST(ConwayCellFixture, clone1) {
  ConwayCell x('.');

  AbstractCell *y = x.clone();
  ASSERT_FALSE(y->alive());
  delete y;
  y = nullptr;
}

TEST(ConwayCellFixture, clone2) {
  ConwayCell x('.');

  AbstractCell *y = x.clone();
  ASSERT_FALSE(y->alive());
  delete y;
  y = nullptr;
}

TEST(ConwayCellFixture, clone3) {
  ConwayCell x('*');

  AbstractCell *y = x.clone();
  ASSERT_TRUE(y->alive());
  delete y;
  y = nullptr;
}

// ----------------
// ConwayCellupdate
// ----------------

TEST(ConwayCellFixture, update1) {
  ConwayCell x('.');

  ASSERT_FALSE(x.alive());
  x.update(1);

  ASSERT_FALSE(x.alive());
}

TEST(ConwayCellFixture, update2) {
  ConwayCell x('.');

  ASSERT_FALSE(x.alive());
  x.update(3);

  ASSERT_TRUE(x.alive());
}

TEST(ConwayCellFixture, update3) {
  ConwayCell x('*');

  ASSERT_TRUE(x.alive());
  x.update(8);

  ASSERT_FALSE(x.alive());
}

// -----------------------
// ConwayCellfindNeighbors
// -----------------------

TEST(ConwayCellFixture, findNeighbors1) {
  bool neighbors[8] = {};
  ConwayCell x('.');

  ASSERT_EQ(x.findNeighbors(neighbors), 0);
}

TEST(ConwayCellFixture, findNeighbors2) {
  bool neighbors[8] = {true, true, true, true, true, true, true, true};
  ConwayCell x('.');

  ASSERT_EQ(x.findNeighbors(neighbors), 8);
}

TEST(ConwayCellFixture, findNeighbors3) {
  bool neighbors[8] = {true, false, true, false, true, false, true, false};
  ConwayCell x('.');

  ASSERT_EQ(x.findNeighbors(neighbors), 4);
}

// --------------
// ConwayCellread
// --------------

TEST(ConwayCellFixture, read1) {
  ConwayCell x('.');

  ASSERT_FALSE(x.alive());

  istringstream ss(".");

  ss >> x;

  ASSERT_FALSE(x.alive());
}

TEST(ConwayCellFixture, read2) {
  ConwayCell x('.');

  ASSERT_FALSE(x.alive());

  istringstream ss(".");

  ss >> x;

  ASSERT_FALSE(x.alive());
}

TEST(ConwayCellFixture, read3) {
  ConwayCell x('.');

  ASSERT_FALSE(x.alive());

  istringstream ss("*");

  ss >> x;

  ASSERT_TRUE(x.alive());
}

// ---------------
// ConwayCellwrite
// ---------------

TEST(ConwayCellFixture, write1) {
  ConwayCell x('.');

  ostringstream ss;

  ss << x;

  ASSERT_EQ(ss.str(), ".");
}

TEST(ConwayCellFixture, write2) {
  ConwayCell x('.');

  ostringstream ss;

  ss << x;

  ASSERT_EQ(ss.str(), ".");
}

TEST(ConwayCellFixture, write3) {
  ConwayCell x('*');

  ostringstream ss;

  ss << x;

  ASSERT_EQ(ss.str(), "*");
}

// ----------------------
// FredkinCellconstructor
// ----------------------

TEST(FredkinCellFixture, constructor1) {
  FredkinCell x('-');

  ASSERT_FALSE(x.alive());
  ASSERT_EQ(x._age, 0);
}

TEST(FredkinCellFixture, constructor2) {
  FredkinCell x('-');

  ASSERT_FALSE(x.alive());
  ASSERT_EQ(x._age, 0);
}

TEST(FredkinCellFixture, constructor3) {
  FredkinCell x('0');

  ASSERT_TRUE(x.alive());
  ASSERT_EQ(x._age, 0);
}

// -----------------
// FredkinCellmutate
// -----------------

TEST(FredkinCellFixture, mutate1) {
  FredkinCell x('-');

  ASSERT_FALSE(x.mutate(4));
}

TEST(FredkinCellFixture, mutate2) {
  FredkinCell x('0');

  ASSERT_FALSE(x.mutate(4));
}

TEST(FredkinCellFixture, mutate3) {
  FredkinCell x('1');

  ASSERT_TRUE(x.mutate(3));
}

// ----------------
// FredkinCellclone
// ----------------

TEST(FredkinCellFixture, clone1) {
  FredkinCell x('-');

  AbstractCell *y = x.clone();
  ASSERT_FALSE(y->alive());
  delete y;
  y = nullptr;
}

TEST(FredkinCellFixture, clone2) {
  FredkinCell x('-');

  AbstractCell *y = x.clone();
  ASSERT_FALSE(y->alive());
  delete y;
  y = nullptr;
}

TEST(FredkinCellFixture, clone3) {
  FredkinCell x('0');

  AbstractCell *y = x.clone();
  ASSERT_TRUE(y->alive());
  delete y;
  y = nullptr;
}

// -----------------
// FredkinCellupdate
// -----------------

TEST(FredkinCellFixture, update1) {
  FredkinCell x('-');

  ASSERT_FALSE(x.alive());
  x.update(2);

  ASSERT_FALSE(x.alive());
}

TEST(FredkinCellFixture, update2) {
  FredkinCell x('-');

  ASSERT_FALSE(x.alive());
  x.update(1);

  ASSERT_TRUE(x.alive());
}

TEST(FredkinCellFixture, update3) {
  FredkinCell x('0');

  ASSERT_TRUE(x.alive());
  x.update(1);

  ASSERT_TRUE(x.alive());
}

// ------------------------
// FredkinCellfindNeighbors
// ------------------------

TEST(FredkinCellFixture, findNeighbors1) {
  bool neighbors[8] = {};
  FredkinCell x('-');

  ASSERT_EQ(x.findNeighbors(neighbors), 0);
}

TEST(FredkinCellFixture, findNeighbors2) {
  bool neighbors[8] = {true, true, true, true, true, true, true, true};
  FredkinCell x('-');

  ASSERT_EQ(x.findNeighbors(neighbors), 4);
}

TEST(FredkinCellFixture, findNeighbors3) {
  bool neighbors[8] = {false, true, false, true, false, true, false, true};
  FredkinCell x('-');

  ASSERT_EQ(x.findNeighbors(neighbors), 0);
}

// ---------------
// FredkinCellread
// ---------------

TEST(FredkinCellFixture, read1) {
  FredkinCell x('-');

  ASSERT_FALSE(x.alive());
  ASSERT_EQ(x._age, 0);

  istringstream ss("-");

  ss >> x;

  ASSERT_FALSE(x.alive());
  ASSERT_EQ(x._age, 0);
}

TEST(FredkinCellFixture, read2) {
  FredkinCell x('-');

  ASSERT_FALSE(x.alive());
  ASSERT_EQ(x._age, 0);

  istringstream ss("-");

  ss >> x;

  ASSERT_FALSE(x.alive());
  ASSERT_EQ(x._age, 0);
}

TEST(FredkinCellFixture, read3) {
  FredkinCell x('-');

  ASSERT_FALSE(x.alive());
  ASSERT_EQ(x._age, 0);

  istringstream ss("+");

  ss >> x;

  ASSERT_TRUE(x.alive());
  ASSERT_EQ(x._age, 10);
}

// ----------------
// FredkinCellwrite
// ----------------

TEST(FredkinCellFixture, write1) {
  FredkinCell x('-');

  ostringstream ss;

  ss << x;

  ASSERT_EQ(ss.str(), "-");
}

TEST(FredkinCellFixture, write2) {
  FredkinCell x('0');

  ostringstream ss;

  ss << x;

  ASSERT_EQ(ss.str(), "0");
}

TEST(FredkinCellFixture, write3) {
  FredkinCell x('+');

  ostringstream ss;

  ss << x;

  ASSERT_EQ(ss.str(), "+");
}
