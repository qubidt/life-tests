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
TEST(LifeFixture, advance_test1) {

  string raw = "**--\n**--\n----\n----\n";
  istringstream in(raw);

  ASSERT_TRUE(true);
  int first = 4;
  int second = 4;
  Life<ConwayCell> x(first, second, in);

  // cout << x<< '\n';

  // cout << '\n';

  int i = 0;

  while (i < 5) {
    x.advance();
    i++;
  }

  int a;
  int population = 0;
  for (a = 0; a < 36; a++) {
    char current_state = x._grid[a].stateRepresentation();
    if (current_state == '*') {
      population++;
    }
  }

  ASSERT_EQ(population, 4);
}

TEST(LifeFixture, advance_test2) {

  string raw = "00--\n00--\n----\n----\n";
  istringstream in(raw);

  int first = 4;
  int second = 4;
  int i = 0;
  Life<FredkinCell> x(first, second, in);

  // while(i < 5) {
  // 	x.advance();
  // 	i++;
  // 	cout << x;
  // 	cout << '\n';
  while (i < 5) {
    x.advance();
    i++;
    // cout << x;
    // cout << '\n';
  }

  int a;
  int population = 0;
  for (a = 0; a < 36; a++) {
    char current_state = x._grid[a].stateRepresentation();
    if (current_state != '-' || current_state == '0') {
      population++;
    }
  }

  ASSERT_EQ(population, 6);
}

TEST(LifeFixture, advance_test3) {

  string raw = "0000\n00--\n----\n----\n";
  istringstream in(raw);

  int first = 4;
  int second = 4;
  Life<FredkinCell> x(first, second, in);

  int i = 0;

  while (i < 5) {
    x.advance();
    i++;
    // cout << x;
    // cout << '\n';
  }

  int a;
  int population = 0;
  for (a = 0; a < 36; a++) {
    char current_state = x._grid[a].stateRepresentation();
    if (current_state != '-' || current_state == '0') {
      population++;
    }
  }
  ASSERT_EQ(population, 9);
}

TEST(LifeFixture, advance_test4) {

  string raw = "**--\n**--\n----\n**--\n";
  istringstream in(raw);

  int first = 4;
  int second = 4;
  Life<ConwayCell> x(first, second, in);

  // cout << x<< '\n';

  // cout << '\n';

  int i = 0;

  while (i < 5) {
    x.advance();
    i++;
    // cout << x;
    // cout << '\n';
  }

  int a;
  int population = 0;
  for (a = 0; a < 36; a++) {
    char current_state = x._grid[a].stateRepresentation();
    if (current_state == '*') {
      population++;
    }
  }

  ASSERT_EQ(population, 4);
}

TEST(LifeFixture, advance_test5) {

  string raw = "0--0\n-00-\n-00-\n0--0\n";
  istringstream in(raw);

  int first = 4;
  int second = 4;
  Life<FredkinCell> x(first, second, in);

  // cout << x<< '\n';

  // cout << '\n';

  int i = 0;

  while (i < 5) {
    x.advance();
    i++;
    // cout << x;
    // cout << '\n';
  }

  int a;
  int population = 0;
  for (a = 0; a < 36; a++) {
    char current_state = x._grid[a].stateRepresentation();
    if (current_state != '-' || current_state == '0') {
      population++;
    }
  }

  ASSERT_EQ(population, 0);
}

/////////////////////////////////////////////////////////////////////

TEST(LifeFixture, life_print_test1) {

  string raw = "**--\n**--\n----\n----\n";
  istringstream in(raw);

  int first = 4;
  int second = 4;
  Life<ConwayCell> x(first, second, in);

  // cout << x<< '\n';

  // cout << '\n';

  int i = 0;

  while (i < 5) {
    x.advance();
    i++;
    // cout << x;
    // cout << '\n';
  }

  int a;
  int population = 0;
  for (a = 0; a < 36; a++) {
    char current_state = x._grid[a].stateRepresentation();
    if (current_state == '*') {
      population++;
    }
  }

  ASSERT_EQ(x._generation, 5);
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

TEST(LifeFixture, ab_print_test1) {

  string raw = "--00\n--00\n00--\n-00-\n";
  istringstream in(raw);

  int first = 4;
  int second = 4;
  Life<FredkinCell> x(first, second, in);

  // cout << x<< '\n';

  // cout << '\n';

  int i = 0;

  while (i < 5) {
    x.advance();
    i++;
    // cout << x;
    // cout << '\n';
  }

  int a;
  int population = 0;
  for (a = 0; a < 36; a++) {
    char current_state = x._grid[a].stateRepresentation();
    if (current_state != '-') {
      population++;
    }
  }

  ASSERT_EQ(x._generation, 5);
}

TEST(LifeFixture, ab_print_test2) {

  string raw = "--00\n--00\n00--\n-00-\n";
  istringstream in(raw);

  int first = 4;
  int second = 4;
  Life<FredkinCell> x(first, second, in);

  // cout << x<< '\n';

  // cout << '\n';

  int i = 0;

  while (i < 5) {
    x.advance();
    i++;
    // cout << x;
    // cout << '\n';
  }

  int a;
  int population = 0;
  for (a = 0; a < 36; a++) {
    char current_state = x._grid[a].stateRepresentation();
    if (current_state != '-') {
      population++;
    }
  }

  ASSERT_EQ(x._generation, 5);
}

TEST(LifeFixture, ab_print_test3) {

  string raw = "--00\n--00\n00--\n-00-\n";
  istringstream in(raw);

  int first = 4;
  int second = 4;
  Life<FredkinCell> x(first, second, in);

  // cout << x<< '\n';

  // cout << '\n';

  int i = 0;

  while (i < 5) {
    x.advance();
    i++;
    // cout << x;
    // cout << '\n';
  }

  int a;
  int population = 0;
  for (a = 0; a < 36; a++) {
    char current_state = x._grid[a].stateRepresentation();
    if (current_state != '-') {
      population++;
    }
  }

  ASSERT_EQ(x._generation, 5);
}

/////////////////////////////////////////////////////////////////////

TEST(LifeFixture, update_hood_test1) {

  string raw = "-----\n-***-\n-***-\n-***-\n-----\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<ConwayCell> x(first, second, in);

  // cout << x<< '\n';
  // cout << '\n';

  x._grid[cellSlotInVector - _trueWidth].updateNeighborhood(neighbors, NORTH);
  x._grid[cellSlotInVector - _trueWidth + 1].updateNeighborhood(neighbors,
                                                                NORTHEAST);
  x._grid[cellSlotInVector + 1].updateNeighborhood(neighbors, EAST);
  x._grid[cellSlotInVector + _trueWidth + 1].updateNeighborhood(neighbors,
                                                                SOUTHEAST);
  x._grid[cellSlotInVector + _trueWidth].updateNeighborhood(neighbors, SOUTH);
  x._grid[cellSlotInVector + _trueWidth - 1].updateNeighborhood(neighbors,
                                                                SOUTHWEST);
  x._grid[cellSlotInVector - 1].updateNeighborhood(neighbors, WEST);
  x._grid[cellSlotInVector - _trueWidth - 1].updateNeighborhood(neighbors,
                                                                NORTHWEST);

  int livingNeighbors = x._grid[cellSlotInVector].countNeighbors(neighbors);

  ASSERT_EQ(livingNeighbors, 8);
}

TEST(LifeFixture, update_hood_test2) {

  string raw = "-----\n-***-\n-***-\n-*---\n-----\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<ConwayCell> x(first, second, in);

  // cout << x<< '\n';
  // cout << '\n';

  x._grid[cellSlotInVector - _trueWidth].updateNeighborhood(neighbors, NORTH);
  x._grid[cellSlotInVector - _trueWidth + 1].updateNeighborhood(neighbors,
                                                                NORTHEAST);
  x._grid[cellSlotInVector + 1].updateNeighborhood(neighbors, EAST);
  x._grid[cellSlotInVector + _trueWidth + 1].updateNeighborhood(neighbors,
                                                                SOUTHEAST);
  x._grid[cellSlotInVector + _trueWidth].updateNeighborhood(neighbors, SOUTH);
  x._grid[cellSlotInVector + _trueWidth - 1].updateNeighborhood(neighbors,
                                                                SOUTHWEST);
  x._grid[cellSlotInVector - 1].updateNeighborhood(neighbors, WEST);
  x._grid[cellSlotInVector - _trueWidth - 1].updateNeighborhood(neighbors,
                                                                NORTHWEST);

  int livingNeighbors = x._grid[cellSlotInVector].countNeighbors(neighbors);

  ASSERT_EQ(livingNeighbors, 6);
}

TEST(LifeFixture, update_hood_test3) {

  string raw = "-----\n-----\n-----\n------\n-----\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<ConwayCell> x(first, second, in);

  // cout << x<< '\n';
  // cout << '\n';

  x._grid[cellSlotInVector - _trueWidth].updateNeighborhood(neighbors, NORTH);
  x._grid[cellSlotInVector - _trueWidth + 1].updateNeighborhood(neighbors,
                                                                NORTHEAST);
  x._grid[cellSlotInVector + 1].updateNeighborhood(neighbors, EAST);
  x._grid[cellSlotInVector + _trueWidth + 1].updateNeighborhood(neighbors,
                                                                SOUTHEAST);
  x._grid[cellSlotInVector + _trueWidth].updateNeighborhood(neighbors, SOUTH);
  x._grid[cellSlotInVector + _trueWidth - 1].updateNeighborhood(neighbors,
                                                                SOUTHWEST);
  x._grid[cellSlotInVector - 1].updateNeighborhood(neighbors, WEST);
  x._grid[cellSlotInVector - _trueWidth - 1].updateNeighborhood(neighbors,
                                                                NORTHWEST);

  int livingNeighbors = x._grid[cellSlotInVector].countNeighbors(neighbors);

  ASSERT_EQ(livingNeighbors, 0);
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

TEST(LifeFixture, conway_evolve_test1) {

  string raw = "-----\n-***-\n-***-\n-***-\n-----\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<ConwayCell> x(first, second, in);

  // cout << x<< '\n';
  // cout << '\n';

  x._grid[cellSlotInVector - _trueWidth].updateNeighborhood(neighbors, NORTH);
  x._grid[cellSlotInVector - _trueWidth + 1].updateNeighborhood(neighbors,
                                                                NORTHEAST);
  x._grid[cellSlotInVector + 1].updateNeighborhood(neighbors, EAST);
  x._grid[cellSlotInVector + _trueWidth + 1].updateNeighborhood(neighbors,
                                                                SOUTHEAST);
  x._grid[cellSlotInVector + _trueWidth].updateNeighborhood(neighbors, SOUTH);
  x._grid[cellSlotInVector + _trueWidth - 1].updateNeighborhood(neighbors,
                                                                SOUTHWEST);
  x._grid[cellSlotInVector - 1].updateNeighborhood(neighbors, WEST);
  x._grid[cellSlotInVector - _trueWidth - 1].updateNeighborhood(neighbors,
                                                                NORTHWEST);

  x._grid[cellSlotInVector].evolve(neighbors);

  //    cout << x<< '\n';
  // cout << '\n';

  ASSERT_EQ(x._grid[cellSlotInVector]._alive, ALIVE);
  ASSERT_EQ(x._grid[cellSlotInVector]._nextState, DEAD);
}

TEST(LifeFixture, conway_evolve_test2) {

  string raw = "-----\n-----\n-*-*-\n---*-\n-----\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<ConwayCell> x(first, second, in);

  // cout << x<< '\n';
  // cout << '\n';

  x._grid[cellSlotInVector - _trueWidth].updateNeighborhood(neighbors, NORTH);
  x._grid[cellSlotInVector - _trueWidth + 1].updateNeighborhood(neighbors,
                                                                NORTHEAST);
  x._grid[cellSlotInVector + 1].updateNeighborhood(neighbors, EAST);
  x._grid[cellSlotInVector + _trueWidth + 1].updateNeighborhood(neighbors,
                                                                SOUTHEAST);
  x._grid[cellSlotInVector + _trueWidth].updateNeighborhood(neighbors, SOUTH);
  x._grid[cellSlotInVector + _trueWidth - 1].updateNeighborhood(neighbors,
                                                                SOUTHWEST);
  x._grid[cellSlotInVector - 1].updateNeighborhood(neighbors, WEST);
  x._grid[cellSlotInVector - _trueWidth - 1].updateNeighborhood(neighbors,
                                                                NORTHWEST);

  x._grid[cellSlotInVector].evolve(neighbors);

  //    cout << x<< '\n';
  // cout << '\n';

  ASSERT_EQ(x._grid[cellSlotInVector]._alive, DEAD);
  ASSERT_EQ(x._grid[cellSlotInVector]._nextState, ALIVE);
}

TEST(LifeFixture, conway_evolve_test3) {

  string raw = "-----\n-----\n-**--\n-----\n-----\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<ConwayCell> x(first, second, in);

  // cout << x<< '\n';
  // cout << '\n';

  x._grid[cellSlotInVector - _trueWidth].updateNeighborhood(neighbors, NORTH);
  x._grid[cellSlotInVector - _trueWidth + 1].updateNeighborhood(neighbors,
                                                                NORTHEAST);
  x._grid[cellSlotInVector + 1].updateNeighborhood(neighbors, EAST);
  x._grid[cellSlotInVector + _trueWidth + 1].updateNeighborhood(neighbors,
                                                                SOUTHEAST);
  x._grid[cellSlotInVector + _trueWidth].updateNeighborhood(neighbors, SOUTH);
  x._grid[cellSlotInVector + _trueWidth - 1].updateNeighborhood(neighbors,
                                                                SOUTHWEST);
  x._grid[cellSlotInVector - 1].updateNeighborhood(neighbors, WEST);
  x._grid[cellSlotInVector - _trueWidth - 1].updateNeighborhood(neighbors,
                                                                NORTHWEST);

  x._grid[cellSlotInVector].evolve(neighbors);

  //    cout << x<< '\n';
  // cout << '\n';

  ASSERT_EQ(x._grid[cellSlotInVector]._alive, ALIVE);
  ASSERT_EQ(x._grid[cellSlotInVector]._nextState, DEAD);
}

/////////////////////////////////////////////////////////////////////

TEST(LifeFixture, conway_staterep_test1) {

  string raw = ".....\n.***.\n.***.\n.***.\n.....\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  struct neighborhood neighbors;
  Life<ConwayCell> x(first, second, in);

  ASSERT_EQ(x._grid[cellSlotInVector].stateRepresentation(), '*');
}

TEST(LifeFixture, conway_staterep_test2) {

  string raw = ".....\n.***.\n.*.*.\n.***.\n.....\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  struct neighborhood neighbors;
  Life<ConwayCell> x(first, second, in);

  ASSERT_EQ(x._grid[cellSlotInVector].stateRepresentation(), '.');
}

TEST(LifeFixture, conway_staterep_test3) {

  string raw = ".....\n.***.\n.***.\n.***.\n.....\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  struct neighborhood neighbors;
  Life<ConwayCell> x(first, second, in);

  ASSERT_EQ(x._grid[cellSlotInVector].stateRepresentation(), '*');
}

/////////////////////////////////////////////////////////////////////

TEST(LifeFixture, conway_count_hood_test1) {

  string raw = ".....\n.***.\n.***.\n.***.\n.....\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<ConwayCell> x(first, second, in);

  // cout << x<< '\n';
  // cout << '\n';

  x._grid[cellSlotInVector - _trueWidth].updateNeighborhood(neighbors, NORTH);
  x._grid[cellSlotInVector - _trueWidth + 1].updateNeighborhood(neighbors,
                                                                NORTHEAST);
  x._grid[cellSlotInVector + 1].updateNeighborhood(neighbors, EAST);
  x._grid[cellSlotInVector + _trueWidth + 1].updateNeighborhood(neighbors,
                                                                SOUTHEAST);
  x._grid[cellSlotInVector + _trueWidth].updateNeighborhood(neighbors, SOUTH);
  x._grid[cellSlotInVector + _trueWidth - 1].updateNeighborhood(neighbors,
                                                                SOUTHWEST);
  x._grid[cellSlotInVector - 1].updateNeighborhood(neighbors, WEST);
  x._grid[cellSlotInVector - _trueWidth - 1].updateNeighborhood(neighbors,
                                                                NORTHWEST);

  int livingNeighbors = x._grid[cellSlotInVector].countNeighbors(neighbors);

  ASSERT_EQ(livingNeighbors, 8);
}

TEST(LifeFixture, conway_count_hood_test2) {

  string raw = ".....\n.***.\n.***.\n.*...\n.....\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<ConwayCell> x(first, second, in);

  // cout << x<< '\n';
  // cout << '\n';

  x._grid[cellSlotInVector - _trueWidth].updateNeighborhood(neighbors, NORTH);
  x._grid[cellSlotInVector - _trueWidth + 1].updateNeighborhood(neighbors,
                                                                NORTHEAST);
  x._grid[cellSlotInVector + 1].updateNeighborhood(neighbors, EAST);
  x._grid[cellSlotInVector + _trueWidth + 1].updateNeighborhood(neighbors,
                                                                SOUTHEAST);
  x._grid[cellSlotInVector + _trueWidth].updateNeighborhood(neighbors, SOUTH);
  x._grid[cellSlotInVector + _trueWidth - 1].updateNeighborhood(neighbors,
                                                                SOUTHWEST);
  x._grid[cellSlotInVector - 1].updateNeighborhood(neighbors, WEST);
  x._grid[cellSlotInVector - _trueWidth - 1].updateNeighborhood(neighbors,
                                                                NORTHWEST);

  int livingNeighbors = x._grid[cellSlotInVector].countNeighbors(neighbors);

  ASSERT_EQ(livingNeighbors, 6);
}

TEST(LifeFixture, conway_count_hood_test3) {

  string raw = ".....\n.....\n.....\n.....\n.....\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<ConwayCell> x(first, second, in);

  // cout << x<< '\n';
  // cout << '\n';

  x._grid[cellSlotInVector - _trueWidth].updateNeighborhood(neighbors, NORTH);
  x._grid[cellSlotInVector - _trueWidth + 1].updateNeighborhood(neighbors,
                                                                NORTHEAST);
  x._grid[cellSlotInVector + 1].updateNeighborhood(neighbors, EAST);
  x._grid[cellSlotInVector + _trueWidth + 1].updateNeighborhood(neighbors,
                                                                SOUTHEAST);
  x._grid[cellSlotInVector + _trueWidth].updateNeighborhood(neighbors, SOUTH);
  x._grid[cellSlotInVector + _trueWidth - 1].updateNeighborhood(neighbors,
                                                                SOUTHWEST);
  x._grid[cellSlotInVector - 1].updateNeighborhood(neighbors, WEST);
  x._grid[cellSlotInVector - _trueWidth - 1].updateNeighborhood(neighbors,
                                                                NORTHWEST);

  int livingNeighbors = x._grid[cellSlotInVector].countNeighbors(neighbors);

  ASSERT_EQ(livingNeighbors, 0);
}

/////////////////////////////////////////////////////////////////////

TEST(LifeFixture, conway_update_status_test1) {

  string raw = "-----\n-***-\n-***-\n-***-\n-----\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<ConwayCell> x(first, second, in);

  // cout << x<< '\n';
  // cout << '\n';

  x._grid[cellSlotInVector - _trueWidth].updateNeighborhood(neighbors, NORTH);
  x._grid[cellSlotInVector - _trueWidth + 1].updateNeighborhood(neighbors,
                                                                NORTHEAST);
  x._grid[cellSlotInVector + 1].updateNeighborhood(neighbors, EAST);
  x._grid[cellSlotInVector + _trueWidth + 1].updateNeighborhood(neighbors,
                                                                SOUTHEAST);
  x._grid[cellSlotInVector + _trueWidth].updateNeighborhood(neighbors, SOUTH);
  x._grid[cellSlotInVector + _trueWidth - 1].updateNeighborhood(neighbors,
                                                                SOUTHWEST);
  x._grid[cellSlotInVector - 1].updateNeighborhood(neighbors, WEST);
  x._grid[cellSlotInVector - _trueWidth - 1].updateNeighborhood(neighbors,
                                                                NORTHWEST);

  x._grid[cellSlotInVector].evolve(neighbors);

  ASSERT_EQ(x._grid[cellSlotInVector]._alive, ALIVE);
  ASSERT_EQ(x._grid[cellSlotInVector]._nextState, DEAD);

  x._grid[cellSlotInVector].updateStatus();

  ASSERT_EQ(x._grid[cellSlotInVector]._alive, DEAD);
  ASSERT_EQ(x._grid[cellSlotInVector]._nextState, DEAD);
}

TEST(LifeFixture, conway_update_status_test2) {

  string raw = "-----\n-----\n-*-*-\n---*-\n-----\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<ConwayCell> x(first, second, in);

  // cout << x<< '\n';
  // cout << '\n';

  x._grid[cellSlotInVector - _trueWidth].updateNeighborhood(neighbors, NORTH);
  x._grid[cellSlotInVector - _trueWidth + 1].updateNeighborhood(neighbors,
                                                                NORTHEAST);
  x._grid[cellSlotInVector + 1].updateNeighborhood(neighbors, EAST);
  x._grid[cellSlotInVector + _trueWidth + 1].updateNeighborhood(neighbors,
                                                                SOUTHEAST);
  x._grid[cellSlotInVector + _trueWidth].updateNeighborhood(neighbors, SOUTH);
  x._grid[cellSlotInVector + _trueWidth - 1].updateNeighborhood(neighbors,
                                                                SOUTHWEST);
  x._grid[cellSlotInVector - 1].updateNeighborhood(neighbors, WEST);
  x._grid[cellSlotInVector - _trueWidth - 1].updateNeighborhood(neighbors,
                                                                NORTHWEST);

  x._grid[cellSlotInVector].evolve(neighbors);

  //    cout << x<< '\n';
  // cout << '\n';

  ASSERT_EQ(x._grid[cellSlotInVector]._alive, DEAD);
  ASSERT_EQ(x._grid[cellSlotInVector]._nextState, ALIVE);

  x._grid[cellSlotInVector].updateStatus();

  ASSERT_EQ(x._grid[cellSlotInVector]._alive, ALIVE);
  ASSERT_EQ(x._grid[cellSlotInVector]._nextState, DEAD);
}

TEST(LifeFixture, conway_update_status_test3) {

  string raw = "-----\n-----\n-**--\n-----\n-----\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<ConwayCell> x(first, second, in);

  // cout << x<< '\n';
  // cout << '\n';

  x._grid[cellSlotInVector - _trueWidth].updateNeighborhood(neighbors, NORTH);
  x._grid[cellSlotInVector - _trueWidth + 1].updateNeighborhood(neighbors,
                                                                NORTHEAST);
  x._grid[cellSlotInVector + 1].updateNeighborhood(neighbors, EAST);
  x._grid[cellSlotInVector + _trueWidth + 1].updateNeighborhood(neighbors,
                                                                SOUTHEAST);
  x._grid[cellSlotInVector + _trueWidth].updateNeighborhood(neighbors, SOUTH);
  x._grid[cellSlotInVector + _trueWidth - 1].updateNeighborhood(neighbors,
                                                                SOUTHWEST);
  x._grid[cellSlotInVector - 1].updateNeighborhood(neighbors, WEST);
  x._grid[cellSlotInVector - _trueWidth - 1].updateNeighborhood(neighbors,
                                                                NORTHWEST);

  x._grid[cellSlotInVector].evolve(neighbors);

  //    cout << x<< '\n';
  // cout << '\n';

  ASSERT_EQ(x._grid[cellSlotInVector]._alive, ALIVE);
  ASSERT_EQ(x._grid[cellSlotInVector]._nextState, DEAD);

  x._grid[cellSlotInVector].updateStatus();

  ASSERT_EQ(x._grid[cellSlotInVector]._alive, DEAD);
  ASSERT_EQ(x._grid[cellSlotInVector]._nextState, DEAD);
}

TEST(LifeFixture, conway_update_status_test4) {

  string raw = "-----\n-----\n-**--\n*****\n-----\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<ConwayCell> x(first, second, in);

  // cout << x<< '\n';
  // cout << '\n';

  x._grid[cellSlotInVector - _trueWidth].updateNeighborhood(neighbors, NORTH);
  x._grid[cellSlotInVector - _trueWidth + 1].updateNeighborhood(neighbors,
                                                                NORTHEAST);
  x._grid[cellSlotInVector + 1].updateNeighborhood(neighbors, EAST);
  x._grid[cellSlotInVector + _trueWidth + 1].updateNeighborhood(neighbors,
                                                                SOUTHEAST);
  x._grid[cellSlotInVector + _trueWidth].updateNeighborhood(neighbors, SOUTH);
  x._grid[cellSlotInVector + _trueWidth - 1].updateNeighborhood(neighbors,
                                                                SOUTHWEST);
  x._grid[cellSlotInVector - 1].updateNeighborhood(neighbors, WEST);
  x._grid[cellSlotInVector - _trueWidth - 1].updateNeighborhood(neighbors,
                                                                NORTHWEST);

  x._grid[cellSlotInVector].evolve(neighbors);

  //    cout << x<< '\n';
  // cout << '\n';

  ASSERT_EQ(x._grid[cellSlotInVector]._alive, ALIVE);
  ASSERT_EQ(x._grid[cellSlotInVector]._nextState, DEAD);

  x._grid[cellSlotInVector].updateStatus();

  ASSERT_EQ(x._grid[cellSlotInVector]._alive, DEAD);
  ASSERT_EQ(x._grid[cellSlotInVector]._nextState, DEAD);
}

TEST(LifeFixture, conway_update_status_test5) {

  string raw = "-----\n-----\n--*--\n-----\n-----\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<ConwayCell> x(first, second, in);

  // cout << x<< '\n';
  // cout << '\n';

  x._grid[cellSlotInVector - _trueWidth].updateNeighborhood(neighbors, NORTH);
  x._grid[cellSlotInVector - _trueWidth + 1].updateNeighborhood(neighbors,
                                                                NORTHEAST);
  x._grid[cellSlotInVector + 1].updateNeighborhood(neighbors, EAST);
  x._grid[cellSlotInVector + _trueWidth + 1].updateNeighborhood(neighbors,
                                                                SOUTHEAST);
  x._grid[cellSlotInVector + _trueWidth].updateNeighborhood(neighbors, SOUTH);
  x._grid[cellSlotInVector + _trueWidth - 1].updateNeighborhood(neighbors,
                                                                SOUTHWEST);
  x._grid[cellSlotInVector - 1].updateNeighborhood(neighbors, WEST);
  x._grid[cellSlotInVector - _trueWidth - 1].updateNeighborhood(neighbors,
                                                                NORTHWEST);

  x._grid[cellSlotInVector].evolve(neighbors);

  //    cout << x<< '\n';
  // cout << '\n';

  ASSERT_EQ(x._grid[cellSlotInVector]._alive, ALIVE);
  ASSERT_EQ(x._grid[cellSlotInVector]._nextState, DEAD);

  x._grid[cellSlotInVector].updateStatus();

  ASSERT_EQ(x._grid[cellSlotInVector]._alive, DEAD);
  ASSERT_EQ(x._grid[cellSlotInVector]._nextState, DEAD);
}

/////////////////////////////////////////////////////////////////////

TEST(LifeFixture, conway_clone_test1) {
  string raw = "-----\n-----\n--*--\n-----\n-----\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  // int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<ConwayCell> x(first, second, in);

  AbstractCell *k = x._grid[cellSlotInVector].clone();

  bool b;
  if (k == NULL) {
    b = false;
  } else {
    b = true;
  }

  ASSERT_TRUE(b);
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

TEST(LifeFixture, fredkin_evolve_test1) {

  string raw = "-----\n-000-\n-000-\n-000-\n-----\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<FredkinCell> x(first, second, in);

  // cout << x<< '\n';
  // cout << '\n';

  x._grid[cellSlotInVector - _trueWidth].updateNeighborhood(neighbors, NORTH);
  x._grid[cellSlotInVector - _trueWidth + 1].updateNeighborhood(neighbors,
                                                                NORTHEAST);
  x._grid[cellSlotInVector + 1].updateNeighborhood(neighbors, EAST);
  x._grid[cellSlotInVector + _trueWidth + 1].updateNeighborhood(neighbors,
                                                                SOUTHEAST);
  x._grid[cellSlotInVector + _trueWidth].updateNeighborhood(neighbors, SOUTH);
  x._grid[cellSlotInVector + _trueWidth - 1].updateNeighborhood(neighbors,
                                                                SOUTHWEST);
  x._grid[cellSlotInVector - 1].updateNeighborhood(neighbors, WEST);
  x._grid[cellSlotInVector - _trueWidth - 1].updateNeighborhood(neighbors,
                                                                NORTHWEST);

  x._grid[cellSlotInVector].evolve(neighbors);

  ASSERT_EQ(x._grid[cellSlotInVector]._alive, ALIVE);
  ASSERT_EQ(x._grid[cellSlotInVector]._nextState, DEAD);
}

TEST(LifeFixture, fredkin_evolve_test2) {

  string raw = "-----\n-----\n-0-0-\n---0-\n-----\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<FredkinCell> x(first, second, in);

  // cout << x<< '\n';
  // cout << '\n';

  x._grid[cellSlotInVector - _trueWidth].updateNeighborhood(neighbors, NORTH);
  x._grid[cellSlotInVector - _trueWidth + 1].updateNeighborhood(neighbors,
                                                                NORTHEAST);
  x._grid[cellSlotInVector + 1].updateNeighborhood(neighbors, EAST);
  x._grid[cellSlotInVector + _trueWidth + 1].updateNeighborhood(neighbors,
                                                                SOUTHEAST);
  x._grid[cellSlotInVector + _trueWidth].updateNeighborhood(neighbors, SOUTH);
  x._grid[cellSlotInVector + _trueWidth - 1].updateNeighborhood(neighbors,
                                                                SOUTHWEST);
  x._grid[cellSlotInVector - 1].updateNeighborhood(neighbors, WEST);
  x._grid[cellSlotInVector - _trueWidth - 1].updateNeighborhood(neighbors,
                                                                NORTHWEST);

  x._grid[cellSlotInVector].evolve(neighbors);

  //    cout << x<< '\n';
  // cout << '\n';

  ASSERT_EQ(x._grid[cellSlotInVector]._alive, DEAD);
  ASSERT_EQ(x._grid[cellSlotInVector]._nextState, DEAD);
}

TEST(LifeFixture, fredkin_evolve_test3) {

  string raw = "-----\n-----\n-00--\n-----\n-----\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<FredkinCell> x(first, second, in);

  // cout << x<< '\n';
  // cout << '\n';

  x._grid[cellSlotInVector - _trueWidth].updateNeighborhood(neighbors, NORTH);
  x._grid[cellSlotInVector - _trueWidth + 1].updateNeighborhood(neighbors,
                                                                NORTHEAST);
  x._grid[cellSlotInVector + 1].updateNeighborhood(neighbors, EAST);
  x._grid[cellSlotInVector + _trueWidth + 1].updateNeighborhood(neighbors,
                                                                SOUTHEAST);
  x._grid[cellSlotInVector + _trueWidth].updateNeighborhood(neighbors, SOUTH);
  x._grid[cellSlotInVector + _trueWidth - 1].updateNeighborhood(neighbors,
                                                                SOUTHWEST);
  x._grid[cellSlotInVector - 1].updateNeighborhood(neighbors, WEST);
  x._grid[cellSlotInVector - _trueWidth - 1].updateNeighborhood(neighbors,
                                                                NORTHWEST);

  x._grid[cellSlotInVector].evolve(neighbors);

  //    cout << x<< '\n';
  // cout << '\n';

  ASSERT_EQ(x._grid[cellSlotInVector]._alive, ALIVE);
  ASSERT_EQ(x._grid[cellSlotInVector]._nextState, ALIVE);
}

/////////////////////////////////////////////////////////////////////

TEST(LifeFixture, fredkin_staterep_test1) {

  string raw = "00000\n0---0\n0---0\n0---0\n00000\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  struct neighborhood neighbors;
  Life<FredkinCell> x(first, second, in);

  ASSERT_EQ(x._grid[cellSlotInVector].stateRepresentation(), '-');
}

TEST(LifeFixture, fredkin_staterep_test2) {

  string raw = "00000\n0---0\n0-0-0\n0---0\n00000\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  struct neighborhood neighbors;
  Life<FredkinCell> x(first, second, in);

  ASSERT_EQ(x._grid[cellSlotInVector].stateRepresentation(), '0');
}

TEST(LifeFixture, fredkin_staterep_test3) {

  string raw = "00000\n0---0\n0---0\n0---0\n00000\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  struct neighborhood neighbors;
  Life<FredkinCell> x(first, second, in);

  ASSERT_EQ(x._grid[cellSlotInVector].stateRepresentation(), '-');
}

/////////////////////////////////////////////////////////////////////

TEST(LifeFixture, fredkin_count_hood_test1) {

  string raw = "-----\n-000-\n-000-\n-000-\n-----\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<FredkinCell> x(first, second, in);

  // cout << x<< '\n';
  // cout << '\n';

  x._grid[cellSlotInVector - _trueWidth].updateNeighborhood(neighbors, NORTH);
  x._grid[cellSlotInVector - _trueWidth + 1].updateNeighborhood(neighbors,
                                                                NORTHEAST);
  x._grid[cellSlotInVector + 1].updateNeighborhood(neighbors, EAST);
  x._grid[cellSlotInVector + _trueWidth + 1].updateNeighborhood(neighbors,
                                                                SOUTHEAST);
  x._grid[cellSlotInVector + _trueWidth].updateNeighborhood(neighbors, SOUTH);
  x._grid[cellSlotInVector + _trueWidth - 1].updateNeighborhood(neighbors,
                                                                SOUTHWEST);
  x._grid[cellSlotInVector - 1].updateNeighborhood(neighbors, WEST);
  x._grid[cellSlotInVector - _trueWidth - 1].updateNeighborhood(neighbors,
                                                                NORTHWEST);

  int livingNeighbors = x._grid[cellSlotInVector].countNeighbors(neighbors);

  ASSERT_EQ(livingNeighbors, 4);
}

TEST(LifeFixture, fredkin_count_hood_test2) {

  string raw = "-----\n-000-\n-000-\n-0---\n-----\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<FredkinCell> x(first, second, in);

  // cout << x<< '\n';
  // cout << '\n';

  x._grid[cellSlotInVector - _trueWidth].updateNeighborhood(neighbors, NORTH);
  x._grid[cellSlotInVector - _trueWidth + 1].updateNeighborhood(neighbors,
                                                                NORTHEAST);
  x._grid[cellSlotInVector + 1].updateNeighborhood(neighbors, EAST);
  x._grid[cellSlotInVector + _trueWidth + 1].updateNeighborhood(neighbors,
                                                                SOUTHEAST);
  x._grid[cellSlotInVector + _trueWidth].updateNeighborhood(neighbors, SOUTH);
  x._grid[cellSlotInVector + _trueWidth - 1].updateNeighborhood(neighbors,
                                                                SOUTHWEST);
  x._grid[cellSlotInVector - 1].updateNeighborhood(neighbors, WEST);
  x._grid[cellSlotInVector - _trueWidth - 1].updateNeighborhood(neighbors,
                                                                NORTHWEST);

  int livingNeighbors = x._grid[cellSlotInVector].countNeighbors(neighbors);

  ASSERT_EQ(livingNeighbors, 3);
}

TEST(LifeFixture, fredkin_count_hood_test3) {

  string raw = "-----\n-----\n-----\n-----\n-----\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<FredkinCell> x(first, second, in);

  // cout << x<< '\n';
  // cout << '\n';

  x._grid[cellSlotInVector - _trueWidth].updateNeighborhood(neighbors, NORTH);
  x._grid[cellSlotInVector - _trueWidth + 1].updateNeighborhood(neighbors,
                                                                NORTHEAST);
  x._grid[cellSlotInVector + 1].updateNeighborhood(neighbors, EAST);
  x._grid[cellSlotInVector + _trueWidth + 1].updateNeighborhood(neighbors,
                                                                SOUTHEAST);
  x._grid[cellSlotInVector + _trueWidth].updateNeighborhood(neighbors, SOUTH);
  x._grid[cellSlotInVector + _trueWidth - 1].updateNeighborhood(neighbors,
                                                                SOUTHWEST);
  x._grid[cellSlotInVector - 1].updateNeighborhood(neighbors, WEST);
  x._grid[cellSlotInVector - _trueWidth - 1].updateNeighborhood(neighbors,
                                                                NORTHWEST);

  int livingNeighbors = x._grid[cellSlotInVector].countNeighbors(neighbors);

  ASSERT_EQ(livingNeighbors, 0);
}

/////////////////////////////////////////////////////////////////////

TEST(LifeFixture, fredkin_update_status_test1) {

  string raw = "-----\n-000-\n-000-\n-000-\n-----\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<FredkinCell> x(first, second, in);

  // cout << x<< '\n';
  // cout << '\n';

  x._grid[cellSlotInVector - _trueWidth].updateNeighborhood(neighbors, NORTH);
  x._grid[cellSlotInVector - _trueWidth + 1].updateNeighborhood(neighbors,
                                                                NORTHEAST);
  x._grid[cellSlotInVector + 1].updateNeighborhood(neighbors, EAST);
  x._grid[cellSlotInVector + _trueWidth + 1].updateNeighborhood(neighbors,
                                                                SOUTHEAST);
  x._grid[cellSlotInVector + _trueWidth].updateNeighborhood(neighbors, SOUTH);
  x._grid[cellSlotInVector + _trueWidth - 1].updateNeighborhood(neighbors,
                                                                SOUTHWEST);
  x._grid[cellSlotInVector - 1].updateNeighborhood(neighbors, WEST);
  x._grid[cellSlotInVector - _trueWidth - 1].updateNeighborhood(neighbors,
                                                                NORTHWEST);

  x._grid[cellSlotInVector].evolve(neighbors);

  ASSERT_EQ(x._grid[cellSlotInVector]._alive, ALIVE);
  ASSERT_EQ(x._grid[cellSlotInVector]._nextState, DEAD);

  x._grid[cellSlotInVector].updateStatus();

  ASSERT_EQ(x._grid[cellSlotInVector]._alive, DEAD);
  ASSERT_EQ(x._grid[cellSlotInVector]._nextState, DEAD);
}

TEST(LifeFixture, fredkin_update_status_test2) {

  string raw = "-----\n-----\n-0-0-\n---0-\n-----\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<FredkinCell> x(first, second, in);

  // cout << x<< '\n';
  // cout << '\n';

  x._grid[cellSlotInVector - _trueWidth].updateNeighborhood(neighbors, NORTH);
  x._grid[cellSlotInVector - _trueWidth + 1].updateNeighborhood(neighbors,
                                                                NORTHEAST);
  x._grid[cellSlotInVector + 1].updateNeighborhood(neighbors, EAST);
  x._grid[cellSlotInVector + _trueWidth + 1].updateNeighborhood(neighbors,
                                                                SOUTHEAST);
  x._grid[cellSlotInVector + _trueWidth].updateNeighborhood(neighbors, SOUTH);
  x._grid[cellSlotInVector + _trueWidth - 1].updateNeighborhood(neighbors,
                                                                SOUTHWEST);
  x._grid[cellSlotInVector - 1].updateNeighborhood(neighbors, WEST);
  x._grid[cellSlotInVector - _trueWidth - 1].updateNeighborhood(neighbors,
                                                                NORTHWEST);

  x._grid[cellSlotInVector].evolve(neighbors);

  //    cout << x<< '\n';
  // cout << '\n';

  ASSERT_EQ(x._grid[cellSlotInVector]._alive, DEAD);
  ASSERT_EQ(x._grid[cellSlotInVector]._nextState, DEAD);

  x._grid[cellSlotInVector].updateStatus();

  ASSERT_EQ(x._grid[cellSlotInVector]._alive, DEAD);
  ASSERT_EQ(x._grid[cellSlotInVector]._nextState, DEAD);
}

TEST(LifeFixture, fredkin_update_status_test3) {

  string raw = "-----\n-----\n-00--\n-----\n-----\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<FredkinCell> x(first, second, in);

  // cout << x<< '\n';
  // cout << '\n';

  x._grid[cellSlotInVector - _trueWidth].updateNeighborhood(neighbors, NORTH);
  x._grid[cellSlotInVector - _trueWidth + 1].updateNeighborhood(neighbors,
                                                                NORTHEAST);
  x._grid[cellSlotInVector + 1].updateNeighborhood(neighbors, EAST);
  x._grid[cellSlotInVector + _trueWidth + 1].updateNeighborhood(neighbors,
                                                                SOUTHEAST);
  x._grid[cellSlotInVector + _trueWidth].updateNeighborhood(neighbors, SOUTH);
  x._grid[cellSlotInVector + _trueWidth - 1].updateNeighborhood(neighbors,
                                                                SOUTHWEST);
  x._grid[cellSlotInVector - 1].updateNeighborhood(neighbors, WEST);
  x._grid[cellSlotInVector - _trueWidth - 1].updateNeighborhood(neighbors,
                                                                NORTHWEST);

  x._grid[cellSlotInVector].evolve(neighbors);

  //    cout << x<< '\n';
  // cout << '\n';

  ASSERT_EQ(x._grid[cellSlotInVector]._alive, ALIVE);
  ASSERT_EQ(x._grid[cellSlotInVector]._nextState, ALIVE);

  x._grid[cellSlotInVector].updateStatus();

  ASSERT_EQ(x._grid[cellSlotInVector]._alive, ALIVE);
  ASSERT_EQ(x._grid[cellSlotInVector]._nextState, DEAD);
}

TEST(LifeFixture, fredkin_update_status_test4) {

  string raw = "-----\n-----\n-00--\n00000\n-----\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<FredkinCell> x(first, second, in);

  // cout << x<< '\n';
  // cout << '\n';

  x._grid[cellSlotInVector - _trueWidth].updateNeighborhood(neighbors, NORTH);
  x._grid[cellSlotInVector - _trueWidth + 1].updateNeighborhood(neighbors,
                                                                NORTHEAST);
  x._grid[cellSlotInVector + 1].updateNeighborhood(neighbors, EAST);
  x._grid[cellSlotInVector + _trueWidth + 1].updateNeighborhood(neighbors,
                                                                SOUTHEAST);
  x._grid[cellSlotInVector + _trueWidth].updateNeighborhood(neighbors, SOUTH);
  x._grid[cellSlotInVector + _trueWidth - 1].updateNeighborhood(neighbors,
                                                                SOUTHWEST);
  x._grid[cellSlotInVector - 1].updateNeighborhood(neighbors, WEST);
  x._grid[cellSlotInVector - _trueWidth - 1].updateNeighborhood(neighbors,
                                                                NORTHWEST);

  x._grid[cellSlotInVector].evolve(neighbors);

  //    cout << x<< '\n';
  // cout << '\n';

  ASSERT_EQ(x._grid[cellSlotInVector]._alive, ALIVE);
  ASSERT_EQ(x._grid[cellSlotInVector]._nextState, DEAD);

  x._grid[cellSlotInVector].updateStatus();

  ASSERT_EQ(x._grid[cellSlotInVector]._alive, DEAD);
  ASSERT_EQ(x._grid[cellSlotInVector]._nextState, DEAD);
}

TEST(LifeFixture, fredkin_update_status_test5) {

  string raw = "-----\n-----\n--0--\n-----\n-----\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<FredkinCell> x(first, second, in);

  // cout << x<< '\n';
  // cout << '\n';

  x._grid[cellSlotInVector - _trueWidth].updateNeighborhood(neighbors, NORTH);
  x._grid[cellSlotInVector - _trueWidth + 1].updateNeighborhood(neighbors,
                                                                NORTHEAST);
  x._grid[cellSlotInVector + 1].updateNeighborhood(neighbors, EAST);
  x._grid[cellSlotInVector + _trueWidth + 1].updateNeighborhood(neighbors,
                                                                SOUTHEAST);
  x._grid[cellSlotInVector + _trueWidth].updateNeighborhood(neighbors, SOUTH);
  x._grid[cellSlotInVector + _trueWidth - 1].updateNeighborhood(neighbors,
                                                                SOUTHWEST);
  x._grid[cellSlotInVector - 1].updateNeighborhood(neighbors, WEST);
  x._grid[cellSlotInVector - _trueWidth - 1].updateNeighborhood(neighbors,
                                                                NORTHWEST);

  x._grid[cellSlotInVector].evolve(neighbors);

  //    cout << x<< '\n';
  // cout << '\n';

  ASSERT_EQ(x._grid[cellSlotInVector]._alive, ALIVE);
  ASSERT_EQ(x._grid[cellSlotInVector]._nextState, DEAD);

  x._grid[cellSlotInVector].updateStatus();

  ASSERT_EQ(x._grid[cellSlotInVector]._alive, DEAD);
  ASSERT_EQ(x._grid[cellSlotInVector]._nextState, DEAD);
}

/////////////////////////////////////////////////////////////////////

TEST(LifeFixture, fredkin_clone_test1) {
  string raw = "-----\n-----\n--0--\n-----\n-----\n";
  istringstream in(raw);

  int first = 5;
  int second = 5;
  int cellSlotInVector = 24;
  // int _trueWidth = 7;
  struct neighborhood neighbors;
  Life<FredkinCell> x(first, second, in);

  ConwayCell *k = x._grid[cellSlotInVector].clone();

  bool b;
  if (k == NULL) {
    b = false;
  } else {
    b = true;
  }

  ASSERT_TRUE(b);
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

TEST(CellFixture, specialDestructor) {
  char c = '.';
  Cell cell = Cell(c);

  ASSERT_TRUE(cell._cellHolding != NULL);
  cell.specialDestructor();
}

TEST(CellFixture, specialDestructor2) {
  char c = '*';
  Cell cell = Cell(c);

  ASSERT_TRUE(cell._cellHolding != NULL);
  cell.specialDestructor();
  ASSERT_TRUE(cell._cellHolding == NULL);
}

TEST(CellFixture, specialDestructor3) {
  char c = '0';
  Cell cell = Cell(c);

  ASSERT_TRUE(cell._cellHolding != NULL);
  cell.specialDestructor();
  ASSERT_TRUE(cell._cellHolding == NULL);
}

TEST(CellFixture, specialDestructor4) {
  char c = '-';
  Cell cell = Cell(c);

  ASSERT_TRUE(cell._cellHolding != NULL);
  cell.specialDestructor();
  ASSERT_TRUE(cell._cellHolding == NULL);
}

TEST(CellFixture, evolve) {
  char c = '0';
  Cell cell = Cell(c);

  neighborhood n;

  cell.evolve(n);

  ASSERT_TRUE(cell._cellHolding->_nextState == state::DEAD);

  cell.specialDestructor();
  ASSERT_TRUE(cell._cellHolding == NULL);
}

TEST(CellFixture, evolve2) {
  char c = '0';
  Cell cell = Cell(c);

  neighborhood n;
  n._north = state::ALIVE;

  cell.evolve(n);

  ASSERT_TRUE(cell._cellHolding->_nextState == state::ALIVE);

  cell.specialDestructor();
  ASSERT_TRUE(cell._cellHolding == NULL);
}

TEST(CellFixture, evolve3) {
  char c = '*';
  Cell cell = Cell(c);

  neighborhood n;
  n._north = state::ALIVE;
  n._south = state::ALIVE;

  cell.evolve(n);

  ASSERT_TRUE(cell._cellHolding->_nextState == state::ALIVE);

  cell.specialDestructor();
  ASSERT_TRUE(cell._cellHolding == NULL);
}

TEST(CellFixture, updateStatus) {
  char c = '0';
  Cell cell = Cell(c);

  neighborhood n;

  cell.evolve(n);
  cell.updateStatus();

  ASSERT_TRUE(cell._cellHolding->_alive == state::DEAD);

  cell.specialDestructor();
  ASSERT_TRUE(cell._cellHolding == NULL);
}

TEST(CellFixture, updateStatus2) {
  char c = '0';
  Cell cell = Cell(c);

  neighborhood n;

  n._north = state::ALIVE;

  cell.evolve(n);
  cell.updateStatus();

  ASSERT_TRUE(cell._cellHolding->_alive == state::ALIVE);

  cell.specialDestructor();
  ASSERT_TRUE(cell._cellHolding == NULL);
}

TEST(CellFixture, updateStatus3) {
  char c = '-';
  Cell cell = Cell(c);

  neighborhood n;
  n._north = state::ALIVE;

  cell.evolve(n);
  cell.updateStatus();

  ASSERT_TRUE(cell._cellHolding->_alive == state::ALIVE);

  cell.specialDestructor();
  ASSERT_TRUE(cell._cellHolding == NULL);
}

TEST(CellFixture, updateNeighborhoodCell) {
  char c = '*';
  Cell cell = Cell(c);

  neighborhood n;
  cell.updateNeighborhood(n, Direction::NORTH);

  ASSERT_TRUE(n._north == state::ALIVE);

  cell.specialDestructor();
  ASSERT_TRUE(cell._cellHolding == NULL);
}

TEST(CellFixture, updateNeighborhoodCell2) {
  char c = '0';
  Cell cell = Cell(c);

  neighborhood n;
  cell.updateNeighborhood(n, Direction::NORTH);

  ASSERT_TRUE(n._north == state::ALIVE);

  cell.specialDestructor();
  ASSERT_TRUE(cell._cellHolding == NULL);
}

TEST(CellFixture, updateNeighborhoodCell3) {
  char c = '.';
  Cell cell = Cell(c);

  neighborhood n;
  cell.updateNeighborhood(n, Direction::NORTH);

  ASSERT_TRUE(n._north == state::DEAD);

  cell.specialDestructor();
  ASSERT_TRUE(cell._cellHolding == NULL);
}

TEST(CellFixture, updateNeighborhoodCell4) {
  char c = '-';
  Cell cell = Cell(c);

  neighborhood n;
  cell.updateNeighborhood(n, Direction::NORTH);

  ASSERT_TRUE(n._north == state::DEAD);

  cell.specialDestructor();
  ASSERT_TRUE(cell._cellHolding == NULL);
}

TEST(CellFixture, aliveCell) {
  Cell cell = Cell(state::ALIVE);

  ASSERT_TRUE(cell.alive() == state::DEAD);

  cell.specialDestructor();
  ASSERT_TRUE(cell._cellHolding == NULL);
}

TEST(CellFixture, aliveCell2) {
  Cell cell = Cell('0');

  ASSERT_TRUE(cell.alive() == state::ALIVE);

  cell.specialDestructor();
  ASSERT_TRUE(cell._cellHolding == NULL);
}

TEST(CellFixture, aliveCell3) {
  Cell cell = Cell('*');

  ASSERT_TRUE(cell.alive() == state::ALIVE);

  cell.specialDestructor();
  ASSERT_TRUE(cell._cellHolding == NULL);
}
