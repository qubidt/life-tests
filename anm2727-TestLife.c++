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
#include <sstream>
#include <vector>

using namespace std;

class LifeFixture : public ::testing::Test {
protected:
  /* Abstract Cell */
  char getChar(AbstractCell &c) { return c._c; }
  char getChar(Cell &c) { return c._cell->_c; }

  /* Life */
  vector<vector<ConwayCell>> getConwayGrid(Life<ConwayCell> &l) {
    return l._grid;
  }
  vector<vector<FredkinCell>> getFredkinGrid(Life<FredkinCell> &l) {
    return l._grid;
  }
  vector<vector<Cell>> getCellGrid(Life<Cell> &l) { return l._grid; }
  vector<vector<int>> getConwayNeighborGrid(Life<ConwayCell> &l) {
    return l._neighborGrid;
  }
  vector<vector<int>> getFredkinNeighborGrid(Life<FredkinCell> &l) {
    return l._neighborGrid;
  }
  vector<vector<int>> getCellNeighborGrid(Life<Cell> &l) {
    return l._neighborGrid;
  }
};

// ----
// tests
// ----

/* Abstract Tests */
TEST_F(LifeFixture, abstract_test1) {
  ConwayCell x;
  ASSERT_TRUE(getChar(x) == '.');
}

TEST_F(LifeFixture, abstract_test2) {
  FredkinCell x;
  ASSERT_TRUE(getChar(x) == '-');
}

TEST_F(LifeFixture, abstract_test3) {
  Cell x('.');
  ASSERT_TRUE(getChar(x) == '.');
}

TEST_F(LifeFixture, abstract_alive_test1) {
  ConwayCell x;
  ASSERT_TRUE(!x.is_Alive());
}

TEST_F(LifeFixture, abstract_alive_test2) {
  FredkinCell x;
  ASSERT_TRUE(!x.is_Alive());
}

TEST_F(LifeFixture, abstract_alive_test3) {
  Cell x('*');
  ASSERT_TRUE(x.is_Alive());
}

TEST_F(LifeFixture, abstract_print_test1) {
  ConwayCell x;
  ostringstream o;
  o << x;
  ASSERT_TRUE(o.str()[0] == '.');
}

TEST_F(LifeFixture, abstract_print_test2) {
  ConwayCell x('*');
  ostringstream o;
  o << x;
  ASSERT_TRUE(o.str()[0] == '*');
}

TEST_F(LifeFixture, abstract_print_test3) {
  FredkinCell x;
  ostringstream o;
  o << x;
  ASSERT_TRUE(o.str()[0] == '-');
}

TEST_F(LifeFixture, abstract_print_test4) {
  FredkinCell x('*');
  ostringstream o;
  o << x;
  ASSERT_TRUE(o.str()[0] == '*');
}

/* Conway Tests */
TEST_F(LifeFixture, conway_test1) {
  ConwayCell x;
  ASSERT_TRUE(getChar(x) == '.');
}

TEST_F(LifeFixture, conway_test2) {
  ConwayCell x('*');
  ASSERT_TRUE(getChar(x) == '*');
}

TEST_F(LifeFixture, conway_test3) {
  ConwayCell x('.');
  ASSERT_TRUE(getChar(x) == '.');
}

TEST_F(LifeFixture, conway_alive_test1) {
  ConwayCell x;
  ASSERT_TRUE(!x.is_Alive());
}

TEST_F(LifeFixture, conway_alive_test2) {
  ConwayCell x('.');
  ASSERT_TRUE(!x.is_Alive());
}

TEST_F(LifeFixture, conway_alive_test3) {
  ConwayCell x('*');
  ASSERT_TRUE(x.is_Alive());
}

TEST_F(LifeFixture, conway_evolve_test1) {
  int count = 3;
  ConwayCell x('.');
  x.evolve(count);
  ASSERT_TRUE(getChar(x) == '*');
}

TEST_F(LifeFixture, conway_evolve_test2) {
  int count = 3;
  ConwayCell x('*');
  x.evolve(count);
  ASSERT_TRUE(getChar(x) == '*');
}

TEST_F(LifeFixture, conway_evolve_test3) {
  int count = 2;
  ConwayCell x('.');
  x.evolve(count);
  ASSERT_TRUE(getChar(x) == '.');
}

TEST_F(LifeFixture, conway_evolve_test4) {
  int count = 1;
  ConwayCell x('*');
  x.evolve(count);
  ASSERT_TRUE(getChar(x) == '.');
}

TEST_F(LifeFixture, conway_evolve_test5) {
  int count = 4;
  ConwayCell x('.');
  x.evolve(count);
  ASSERT_TRUE(getChar(x) == '.');
}

TEST_F(LifeFixture, conway_evolve_test6) {
  int count = 4;
  ConwayCell x('*');
  x.evolve(count);
  ASSERT_TRUE(getChar(x) == '.');
}

TEST_F(LifeFixture, conway_getType_test1) {
  ConwayCell x('*');
  ASSERT_TRUE(x.getType() == 'Y');
}

TEST_F(LifeFixture, conway_getType_test2) {
  ConwayCell x('*');
  ASSERT_TRUE(x.getType() != 'C');
}

TEST_F(LifeFixture, conway_getType_test3) {
  ConwayCell x('.');
  ASSERT_TRUE(x.getType() == 'Y');
}

/* FredkinCell Tests */
TEST_F(LifeFixture, fredkin_test1) {
  FredkinCell x;
  ASSERT_TRUE(getChar(x) == '-');
}

TEST_F(LifeFixture, fredkin_test2) {
  FredkinCell x('0');
  ASSERT_TRUE(getChar(x) == '0');
}

TEST_F(LifeFixture, fredkin_test3) {
  FredkinCell x('+');
  ASSERT_TRUE(getChar(x) == '+');
}

TEST_F(LifeFixture, fredkin_alive_test1) {
  FredkinCell x;
  ASSERT_TRUE(!x.is_Alive());
}

TEST_F(LifeFixture, fredkin_alive_test2) {
  FredkinCell x('-');
  ASSERT_TRUE(!x.is_Alive());
}

TEST_F(LifeFixture, fredkin_alive_test3) {
  FredkinCell x('0');
  ASSERT_TRUE(x.is_Alive());
}

TEST_F(LifeFixture, fredkin_alive_test4) {
  FredkinCell x('+');
  ASSERT_TRUE(x.is_Alive());
}

TEST_F(LifeFixture, fredkin_evolve_test1) {
  int numNeighbors = 3;
  FredkinCell x('-');
  x.evolve(numNeighbors);
  ASSERT_TRUE(getChar(x) == '0');
}

TEST_F(LifeFixture, fredkin_evolve_test2) {
  int numNeighbors = 3;
  FredkinCell x('0');
  x.evolve(numNeighbors);
  ASSERT_TRUE(getChar(x) == '1');
}

TEST_F(LifeFixture, fredkin_evolve_test3) {
  int numNeighbors = 2;
  FredkinCell x('+');
  x.evolve(numNeighbors);
  ASSERT_TRUE(getChar(x) == '-');
}

TEST_F(LifeFixture, fredkin_evolve_test4) {
  int numNeighbors = 2;
  FredkinCell x('4');
  x.evolve(numNeighbors);
  ASSERT_TRUE(getChar(x) == '-');
}

TEST_F(LifeFixture, fredkin_evolve_test5) {
  int numNeighbors = 2;
  FredkinCell x('-');
  x.evolve(numNeighbors);
  ASSERT_TRUE(getChar(x) == '-');
}

TEST_F(LifeFixture, fredkin_evolve_test6) {
  int numNeighbors = 0;
  FredkinCell x('+');
  x.evolve(numNeighbors);
  ASSERT_TRUE(getChar(x) == '-');
}

TEST_F(LifeFixture, fredkin_getType_test1) {
  FredkinCell x('0');
  ASSERT_TRUE(x.getType() == 'F');
}

TEST_F(LifeFixture, fredkin_getType_test2) {
  FredkinCell x('.');
  ASSERT_TRUE(x.getType() != 'Y');
}

TEST_F(LifeFixture, fredkin_getType_test3) {
  FredkinCell x('-');
  ASSERT_TRUE(x.getType() == 'F');
}

/* Cell Tests */
TEST_F(LifeFixture, cell_test2) {
  Cell x('.');
  ASSERT_TRUE(getChar(x) == '.');
}

TEST_F(LifeFixture, cell_test3) {
  Cell x('-');
  ASSERT_TRUE(getChar(x) == '-');
}

TEST_F(LifeFixture, cell_test4) {
  Cell x('*');
  ASSERT_TRUE(getChar(x) == '*');
}

TEST_F(LifeFixture, cell_test5) {
  Cell x('0');
  ASSERT_TRUE(getChar(x) == '0');
}

TEST_F(LifeFixture, cell_test6) {
  Cell x('0');
  Cell x2(x);
  ASSERT_TRUE(getChar(x2) == '0');
}

TEST_F(LifeFixture, cell_test7) {
  Cell x('-');
  Cell x2(x);
  ASSERT_TRUE(getChar(x2) == '-');
}

TEST_F(LifeFixture, cell_test8) {
  ConwayCell x('.');
  Cell x2(&x);
  ASSERT_TRUE(getChar(x2) == '.');
}

TEST_F(LifeFixture, cell_test9) {
  FredkinCell x('-');
  Cell x2(&x);
  ASSERT_TRUE(getChar(x2) == '-');
}

TEST_F(LifeFixture, cell_assignment_test1) {
  Cell x('-');
  Cell x2 = x;
  ASSERT_TRUE(getChar(x2) == '-');
}

TEST_F(LifeFixture, cell_assignment_test2) {
  Cell x('.');
  Cell x2 = x;
  ASSERT_TRUE(getChar(x2) == '.');
}

TEST_F(LifeFixture, cell_assignment_test3) {
  Cell x('0');
  Cell x2 = x;
  ASSERT_TRUE(getChar(x2) == '0');
}

TEST_F(LifeFixture, cell_assignment_test4) {
  Cell x('*');
  Cell x2 = x;
  ASSERT_TRUE(getChar(x2) == '*');
}

TEST_F(LifeFixture, cell_evolve_test1) {
  int numNeighbors = 3;
  Cell x('-');
  x.evolve(numNeighbors);
  ASSERT_TRUE(getChar(x) == '0');
}

TEST_F(LifeFixture, cell_evolve_test2) {
  int numNeighbors = 2;
  Cell x('-');
  x.evolve(numNeighbors);
  ASSERT_TRUE(getChar(x) == '-');
}

TEST_F(LifeFixture, cell_evolve_test3) {
  int numNeighbors = 2;
  Cell x('+');
  x.evolve(numNeighbors);
  ASSERT_TRUE(getChar(x) == '-');
}

TEST_F(LifeFixture, cell_evolve_test4) {
  int numNeighbors = 3;
  Cell x('0');
  x.evolve(numNeighbors);
  ASSERT_TRUE(getChar(x) == '1');
}

TEST_F(LifeFixture, cell_evolve_test5) {
  int numNeighbors = 3;
  Cell x('.');
  x.evolve(numNeighbors);
  ASSERT_TRUE(getChar(x) == '*');
}

TEST_F(LifeFixture, cell_evolve_test6) {
  int numNeighbors = 1;
  Cell x('*');
  x.evolve(numNeighbors);
  ASSERT_TRUE(getChar(x) == '.');
}

TEST_F(LifeFixture, cell_alive_test1) {
  Cell x('-');
  ASSERT_TRUE(!x.is_Alive());
}

TEST_F(LifeFixture, cell_alive_test2) {
  Cell x('*');
  ASSERT_TRUE(x.is_Alive());
}

TEST_F(LifeFixture, cell_alive_test3) {
  Cell x('0');
  ASSERT_TRUE(x.is_Alive());
}

TEST_F(LifeFixture, cell_alive_test4) {
  Cell x('-');
  ASSERT_TRUE(!x.is_Alive());
}

TEST_F(LifeFixture, cell_getType_test1) {
  Cell x('0');
  ASSERT_TRUE(x.getType() == 'F');
}

TEST_F(LifeFixture, cell_getType_test2) {
  Cell x('.');
  ASSERT_TRUE(x.getType() == 'Y');
}

TEST_F(LifeFixture, cell_getType_test3) {
  Cell x('-');
  ASSERT_TRUE(x.getType() == 'F');
}

/* Life Tests */
TEST_F(LifeFixture, life_addCell_test1) {
  Life<ConwayCell> l(2, 3);
  ConwayCell x('*');
  l.addCell(0, 0, x);
  char result = getChar(getConwayGrid(l)[0][0]);
  ASSERT_TRUE(getChar(x) == result);
}

TEST_F(LifeFixture, life_addCell_test2) {
  Life<FredkinCell> l(2, 3);
  FredkinCell x('+');
  l.addCell(0, 0, x);
  char result = getChar(getFredkinGrid(l)[0][0]);
  ASSERT_TRUE(getChar(x) == result);
}

TEST_F(LifeFixture, life_addCell_test3) {
  Life<ConwayCell> l(2, 3);
  ConwayCell x('*');
  l.addCell(0, 0, x);
  char result = getChar(getConwayGrid(l)[0][0]);
  ASSERT_TRUE(getChar(x) == result);
}

// checkNeighbors
TEST_F(LifeFixture, life_checkNeighbors_test1) {
  Life<ConwayCell> l(2, 3);
  ConwayCell x('*');
  l.addCell(0, 0, x);
  l.checkNeighbors(getConwayGrid(l), 0, 0);
  vector<vector<int>> neighbors = getConwayNeighborGrid(l);

  ASSERT_TRUE(neighbors[0][0] == 0);
}

// checkNeighbors
TEST_F(LifeFixture, life_checkNeighbors_test2) {
  Life<ConwayCell> l(2, 3);
  ConwayCell x('*');
  l.addCell(0, 0, x);
  l.addCell(0, 1, x);
  l.checkNeighbors(getConwayGrid(l), 0, 0);
  l.checkNeighbors(getConwayGrid(l), 0, 1);
  vector<vector<int>> neighbors = getConwayNeighborGrid(l);
  ASSERT_TRUE(neighbors[0][0] == 1 && neighbors[0][1] == 1);
}

// checkNeighbors
TEST_F(LifeFixture, life_checkNeighbors_test3) {
  Life<ConwayCell> l(2, 3);
  ConwayCell x('*');
  l.addCell(0, 0, x);
  l.addCell(0, 1, x);
  l.addCell(1, 0, x);
  l.checkNeighbors(getConwayGrid(l), 0, 0);
  l.checkNeighbors(getConwayGrid(l), 0, 1);
  l.checkNeighbors(getConwayGrid(l), 1, 0);
  vector<vector<int>> neighbors = getConwayNeighborGrid(l);
  ASSERT_TRUE(neighbors[0][0] == 2 && neighbors[1][0] == 2);
}

TEST_F(LifeFixture, life_nextGen_test1) {
  Life<FredkinCell> l(2, 3);
  FredkinCell x('-');
  FredkinCell y('0');
  l.addCell(0, 0, x);
  l.addCell(0, 1, y);
  l.nextGen();

  ASSERT_TRUE(getChar(getFredkinGrid(l)[0][0]) == '0');
}

TEST_F(LifeFixture, life_nextGen_test2) {
  Life<FredkinCell> l(2, 3);
  FredkinCell x('-');
  FredkinCell y('0');
  l.addCell(0, 0, x);
  l.addCell(0, 1, y);
  l.addCell(1, 0, y);
  l.nextGen();

  ASSERT_TRUE(getChar(getFredkinGrid(l)[0][0]) == '-');
}

TEST_F(LifeFixture, life_nextGen_test3) {
  Life<ConwayCell> l(2, 3);
  ConwayCell x('*');
  ConwayCell y('.');
  l.addCell(0, 0, x);
  l.addCell(0, 1, y);
  l.addCell(1, 0, y);
  l.nextGen();

  ASSERT_TRUE(getChar(getConwayGrid(l)[0][0]) == '.');
}

TEST_F(LifeFixture, life_nextGen_test4) {
  Life<Cell> l(2, 3);
  Cell x('*');
  Cell y('.');
  l.addCell(0, 0, x);
  l.addCell(0, 1, y);
  l.addCell(1, 0, y);
  l.nextGen();

  ASSERT_TRUE(getChar(getCellGrid(l)[0][0]) == '.');
}

TEST_F(LifeFixture, life_evolve_test1) {
  Life<ConwayCell> l(2, 3);
  ConwayCell x('*');
  ConwayCell y('.');
  l.addCell(0, 0, x);
  l.addCell(0, 1, y);
  l.addCell(1, 0, y);
  l.evolveGrid();

  ASSERT_TRUE(getChar(getConwayGrid(l)[0][0]) == '.');
}

TEST_F(LifeFixture, life_countPop_test1) {
  Life<FredkinCell> l(2, 3);
  FredkinCell x('-');
  FredkinCell y('0');
  l.addCell(0, 0, x);
  l.addCell(0, 1, y);
  int pop = l.countPopulation();
  ASSERT_TRUE(pop == 1);
}

TEST_F(LifeFixture, life_countPop_test2) {
  Life<FredkinCell> l(2, 3);
  FredkinCell x('-');
  FredkinCell y('0');
  l.addCell(0, 0, x);
  l.addCell(0, 1, y);
  l.addCell(1, 0, y);
  l.addCell(1, 1, y);
  int pop = l.countPopulation();
  ASSERT_TRUE(pop == 3);
}

TEST_F(LifeFixture, life_countPop_test3) {
  Life<ConwayCell> l(2, 3);
  ConwayCell x('*');
  ConwayCell y('.');
  l.addCell(0, 0, x);
  l.addCell(0, 1, y);
  l.addCell(1, 0, y);
  l.addCell(1, 1, y);
  int pop = l.countPopulation();
  ASSERT_TRUE(pop == 1);
}

TEST_F(LifeFixture, life_countPop_test4) {
  Life<Cell> l(2, 3);
  Cell x('*');
  Cell y('.');
  l.addCell(0, 0, x);
  l.addCell(0, 1, y);
  l.addCell(1, 0, y);
  l.addCell(1, 1, y);
  int pop = l.countPopulation();
  ASSERT_TRUE(pop == 1);
}

TEST_F(LifeFixture, life_sim_test1) {
  Life<ConwayCell> l(2, 2);
  ConwayCell x('.');
  ConwayCell y('.');
  l.addCell(0, 0, x);
  l.addCell(0, 1, y);
  l.addCell(1, 0, y);
  l.addCell(1, 1, y);
  l.simulate(1, 1);
  ASSERT_TRUE(getChar(getConwayGrid(l)[0][0]) == '.');
}

TEST_F(LifeFixture, life_sim_test2) {
  Life<ConwayCell> l(2, 2);
  ConwayCell x('*');
  ConwayCell y('.');
  l.addCell(0, 0, x);
  l.addCell(0, 1, y);
  l.addCell(1, 1, y);
  l.simulate(1, 1);
  ASSERT_TRUE(getChar(getConwayGrid(l)[0][0]) == '.');
}

TEST_F(LifeFixture, life_sim_test3) {
  Life<Cell> l(2, 2);
  Cell x('*');
  Cell y('.');
  l.addCell(0, 0, x);
  l.addCell(0, 1, y);
  l.addCell(1, 1, y);
  l.simulate(1, 1);
  ASSERT_TRUE(getChar(getCellGrid(l)[0][0]) == '.');
}

TEST_F(LifeFixture, life_sim_test4) {
  Life<FredkinCell> l(2, 2);
  FredkinCell x('-');
  FredkinCell y('0');
  l.addCell(0, 0, x);
  l.addCell(0, 1, y);
  l.addCell(1, 1, y);
  l.simulate(1, 1);
  ASSERT_TRUE(getChar(getFredkinGrid(l)[0][0]) == '0');
}