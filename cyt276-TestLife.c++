// --------------------------
// projects/life/TestLife.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <stdio.h>
#include <vector>

#include "gtest/gtest.h"

#include "Life.h"

using namespace std;

// ----
// is_alive
// ----

TEST(LifeFixture, is_alive_1) {
  ConwayCell cell(true);
  ASSERT_EQ(cell.is_alive(), true);
}

TEST(LifeFixture, is_alive_2) {
  ConwayCell cell(false);
  ASSERT_EQ(cell.is_alive(), false);
}

TEST(LifeFixture, is_alive_3) {
  FredkinCell cell(true);
  ASSERT_EQ(cell.is_alive(), true);
}

TEST(LifeFixture, is_alive_4) {
  FredkinCell cell(false);
  ASSERT_EQ(cell.is_alive(), false);
}

TEST(LifeFixture, is_alive_5) {
  Cell cell(new ConwayCell(true));
  ASSERT_EQ(cell.is_alive(), true);
}

TEST(LifeFixture, is_alive_6) {
  Cell cell(new ConwayCell(false));
  ASSERT_EQ(cell.is_alive(), false);
}

TEST(LifeFixture, is_alive_7) {
  Cell cell(new ConwayCell());
  ASSERT_EQ(cell.is_alive(), false);
}

TEST(LifeFixture, is_alive_8) {
  Cell cell(new FredkinCell(true));
  ASSERT_EQ(cell.is_alive(), true);
}

TEST(LifeFixture, is_alive_9) {
  Cell cell(new FredkinCell(false));
  ASSERT_EQ(cell.is_alive(), false);
}

TEST(LifeFixture, is_alive_10) {
  Cell cell(new FredkinCell());
  ASSERT_EQ(cell.is_alive(), false);
}

// ----
// count_alive_neighbors
// ----

TEST(LifeFixture, count_alive_neighbors_1) {
  vector<ConwayCell *> v;
  ConwayCell cell(false);

  ConwayCell n1(true);
  v.push_back(&n1);

  vector<void *> neighbors(v.begin(), v.end());
  ASSERT_EQ(cell.count_alive_neighbors(neighbors), 1);
}

TEST(LifeFixture, count_alive_neighbors_2) {
  vector<ConwayCell *> v;
  ConwayCell cell(false);

  ConwayCell n1(false);
  v.push_back(&n1);

  vector<void *> neighbors(v.begin(), v.end());
  ASSERT_EQ(cell.count_alive_neighbors(neighbors), 0);
}

TEST(LifeFixture, count_alive_neighbors_3) {
  vector<ConwayCell *> v;
  ConwayCell cell(false);

  ConwayCell n1(false);
  ConwayCell n2(true);
  ConwayCell n3(false);
  ConwayCell n4(true);
  ConwayCell n5(true);
  ConwayCell n6(false);
  ConwayCell n7(false);
  ConwayCell n8(true);

  v.push_back(&n1);
  v.push_back(&n2);
  v.push_back(&n3);
  v.push_back(&n4);
  v.push_back(&n5);
  v.push_back(&n6);
  v.push_back(&n7);
  v.push_back(&n8);

  vector<void *> neighbors(v.begin(), v.end());
  ASSERT_EQ(cell.count_alive_neighbors(neighbors), 4);
}

TEST(LifeFixture, count_alive_neighbors_4) {
  vector<FredkinCell *> v;
  FredkinCell cell(false);

  FredkinCell n1(true);
  v.push_back(&n1);

  vector<void *> neighbors(v.begin(), v.end());
  ASSERT_EQ(cell.count_alive_neighbors(neighbors), 1);
}

TEST(LifeFixture, count_alive_neighbors_5) {
  vector<FredkinCell *> v;
  FredkinCell cell(false);

  FredkinCell n1(false);
  v.push_back(&n1);

  vector<void *> neighbors(v.begin(), v.end());
  ASSERT_EQ(cell.count_alive_neighbors(neighbors), 0);
}

TEST(LifeFixture, count_alive_neighbors_6) {
  vector<FredkinCell *> v;
  FredkinCell cell(false);

  FredkinCell n1(false);
  FredkinCell n2(true);
  FredkinCell n3(false);
  FredkinCell n4(true);
  FredkinCell n5(true);
  FredkinCell n6(false);
  FredkinCell n7(false);
  FredkinCell n8(true);

  v.push_back(&n1);
  v.push_back(&n2);
  v.push_back(&n3);
  v.push_back(&n4);
  v.push_back(&n5);
  v.push_back(&n6);
  v.push_back(&n7);
  v.push_back(&n8);

  vector<void *> neighbors(v.begin(), v.end());
  ASSERT_EQ(cell.count_alive_neighbors(neighbors), 4);
}

// ----
// conway evolve
// ----

TEST(LifeFixture, conway_evolve_1) {
  vector<ConwayCell *> v;
  ConwayCell cell(true);

  ConwayCell n1(true);
  v.push_back(&n1);

  vector<void *> neighbors(v.begin(), v.end());
  cell.evolve(neighbors);
  ASSERT_EQ(cell._alive, false);
}

TEST(LifeFixture, conway_evolve_2) {
  vector<ConwayCell *> v;
  ConwayCell cell(true);

  ConwayCell n1(true);
  v.push_back(&n1);
  ConwayCell n2(true);
  v.push_back(&n2);
  ConwayCell n3(true);
  v.push_back(&n3);
  ConwayCell n4(true);
  v.push_back(&n4);

  vector<void *> neighbors(v.begin(), v.end());
  cell.evolve(neighbors);
  ASSERT_EQ(cell._alive, false);
}

TEST(LifeFixture, conway_evolve_3) {
  vector<ConwayCell *> v;
  ConwayCell cell(false);

  ConwayCell n1(true);
  v.push_back(&n1);
  ConwayCell n2(true);
  v.push_back(&n2);
  ConwayCell n3(true);
  v.push_back(&n3);

  vector<void *> neighbors(v.begin(), v.end());
  cell.evolve(neighbors);
  ASSERT_EQ(cell._alive, true);
}

// ----
// fredkin evolve
// ----

TEST(LifeFixture, fredkin_evolve_1) {
  vector<FredkinCell *> v;
  FredkinCell cell(false);

  FredkinCell n1(true);
  v.push_back(&n1);

  vector<void *> neighbors(v.begin(), v.end());
  cell.evolve(neighbors);
  ASSERT_EQ(cell._alive, true);
}

TEST(LifeFixture, fredkin_evolve_2) {
  vector<FredkinCell *> v;
  FredkinCell cell(false);

  FredkinCell n1(true);
  v.push_back(&n1);
  FredkinCell n2(true);
  v.push_back(&n2);
  FredkinCell n3(true);
  v.push_back(&n3);

  vector<void *> neighbors(v.begin(), v.end());
  cell.evolve(neighbors);
  ASSERT_EQ(cell._alive, true);
}

TEST(LifeFixture, fredkin_evolve_3) {
  FredkinCell cell(true);

  vector<void *> neighbors;
  cell.evolve(neighbors);
  ASSERT_EQ(cell._alive, false);
}

TEST(LifeFixture, fredkin_evolve_4) {
  vector<FredkinCell *> v;
  FredkinCell cell(true);

  FredkinCell n1(true);
  v.push_back(&n1);
  FredkinCell n2(true);
  v.push_back(&n2);

  vector<void *> neighbors(v.begin(), v.end());
  cell.evolve(neighbors);
  ASSERT_EQ(cell._alive, false);
}

TEST(LifeFixture, fredkin_evolve_5) {
  vector<FredkinCell *> v;
  FredkinCell cell(true);

  FredkinCell n1(true);
  v.push_back(&n1);
  FredkinCell n2(true);
  v.push_back(&n2);
  FredkinCell n3(true);
  v.push_back(&n3);
  FredkinCell n4(true);
  v.push_back(&n4);

  vector<void *> neighbors(v.begin(), v.end());
  cell.evolve(neighbors);
  ASSERT_EQ(cell._alive, false);
}

// ----
// cell evolve
// ----

TEST(LifeFixture, cell_evolve_1) {
  vector<Cell *> v;
  Cell cell(new ConwayCell(true));

  Cell n1(new ConwayCell(true));
  v.push_back(&n1);

  vector<void *> neighbors(v.begin(), v.end());
  cell.evolve(neighbors);
  ASSERT_EQ(cell.is_alive(), false);
}

TEST(LifeFixture, cell_evolve_2) {
  vector<Cell *> v;
  Cell cell(new ConwayCell(true));

  Cell n1(new ConwayCell(true));
  v.push_back(&n1);
  Cell n2(new ConwayCell(true));
  v.push_back(&n2);
  Cell n3(new ConwayCell(true));
  v.push_back(&n3);
  Cell n4(new ConwayCell(true));
  v.push_back(&n4);

  vector<void *> neighbors(v.begin(), v.end());
  cell.evolve(neighbors);
  ASSERT_EQ(cell.is_alive(), false);
}

TEST(LifeFixture, cell_evolve_3) {
  vector<Cell *> v;
  Cell cell(new ConwayCell(false));

  Cell n1(new ConwayCell(true));
  v.push_back(&n1);
  Cell n2(new ConwayCell(true));
  v.push_back(&n2);
  Cell n3(new ConwayCell(true));
  v.push_back(&n3);

  vector<void *> neighbors(v.begin(), v.end());
  cell.evolve(neighbors);
  ASSERT_EQ(cell.is_alive(), true);
}

TEST(LifeFixture, cell_evolve_4) {
  vector<Cell *> v;
  Cell cell(new FredkinCell(false));

  Cell n1(new FredkinCell(true));
  v.push_back(&n1);

  vector<void *> neighbors(v.begin(), v.end());
  cell.evolve(neighbors);
  ASSERT_EQ(cell.is_alive(), true);
}

TEST(LifeFixture, cell_evolve_5) {
  vector<Cell *> v;
  Cell cell(new FredkinCell(false));

  Cell n1(new FredkinCell(true));
  v.push_back(&n1);
  Cell n2(new FredkinCell(true));
  v.push_back(&n2);
  Cell n3(new FredkinCell(true));
  v.push_back(&n3);

  vector<void *> neighbors(v.begin(), v.end());
  cell.evolve(neighbors);
  ASSERT_EQ(cell.is_alive(), true);
}

TEST(LifeFixture, cell_evolve_6) {
  Cell cell(new FredkinCell(true));

  vector<void *> neighbors;
  cell.evolve(neighbors);
  ASSERT_EQ(cell.is_alive(), false);
}

TEST(LifeFixture, cell_evolve_7) {
  vector<Cell *> v;
  Cell cell(new FredkinCell(true));

  Cell n1(new FredkinCell(true));
  v.push_back(&n1);
  Cell n2(new FredkinCell(true));
  v.push_back(&n2);

  vector<void *> neighbors(v.begin(), v.end());
  cell.evolve(neighbors);
  ASSERT_EQ(cell.is_alive(), false);
}

TEST(LifeFixture, cell_evolve_8) {
  vector<Cell *> v;
  Cell cell(new FredkinCell(true));

  Cell n1(new FredkinCell(true));
  v.push_back(&n1);
  Cell n2(new FredkinCell(true));
  v.push_back(&n2);
  Cell n3(new FredkinCell(true));
  v.push_back(&n3);
  Cell n4(new FredkinCell(true));
  v.push_back(&n4);

  vector<void *> neighbors(v.begin(), v.end());
  cell.evolve(neighbors);
  ASSERT_EQ(cell.is_alive(), false);
}

// ----
// conway clone
// ----

TEST(LifeFixture, conway_clone_1) {
  ConwayCell cell1(true);
  ConwayCell *cell2 = reinterpret_cast<ConwayCell *>(cell1.clone());
  cell2->_alive = false;
  if (cell2->_alive)
    ASSERT_FALSE(true);
  if (!cell1._alive)
    ASSERT_FALSE(true);
  delete cell2;
}

TEST(LifeFixture, conway_clone_2) {
  ConwayCell cell1(false);
  ConwayCell *cell2 = reinterpret_cast<ConwayCell *>(cell1.clone());
  cell2->_alive = true;
  if (!cell2->_alive)
    ASSERT_FALSE(true);
  if (cell1._alive)
    ASSERT_FALSE(true);
  delete cell2;
}

TEST(LifeFixture, conway_clone_3) {
  ConwayCell cell1(true);
  ConwayCell *cell2 = reinterpret_cast<ConwayCell *>(cell1.clone());
  cell2->_alive = true;
  if (!cell2->_alive)
    ASSERT_FALSE(true);
  if (!cell1._alive)
    ASSERT_FALSE(true);
  delete cell2;
}

TEST(LifeFixture, conway_clone_4) {
  ConwayCell cell1(false);
  ConwayCell *cell2 = reinterpret_cast<ConwayCell *>(cell1.clone());
  cell2->_alive = false;
  if (cell2->_alive)
    ASSERT_FALSE(true);
  if (cell1._alive)
    ASSERT_FALSE(true);
  delete cell2;
}

// ----
// fredkin clone
// ----

TEST(LifeFixture, fredkin_clone_1) {
  FredkinCell cell1(true);
  FredkinCell *cell2 = reinterpret_cast<FredkinCell *>(cell1.clone());
  cell2->_alive = false;
  if (cell2->_alive)
    ASSERT_FALSE(true);
  if (!cell1._alive)
    ASSERT_FALSE(true);
  delete cell2;
}

TEST(LifeFixture, fredkin_clone_2) {
  FredkinCell cell1(false);
  FredkinCell *cell2 = reinterpret_cast<FredkinCell *>(cell1.clone());
  cell2->_alive = true;
  if (!cell2->_alive)
    ASSERT_FALSE(true);
  if (cell1._alive)
    ASSERT_FALSE(true);
  delete cell2;
}

TEST(LifeFixture, fredkin_clone_3) {
  FredkinCell cell1(true);
  FredkinCell *cell2 = reinterpret_cast<FredkinCell *>(cell1.clone());
  cell2->_alive = true;
  if (!cell2->_alive)
    ASSERT_FALSE(true);
  if (!cell1._alive)
    ASSERT_FALSE(true);
  delete cell2;
}

TEST(LifeFixture, fredkin_clone_4) {
  FredkinCell cell1(false);
  FredkinCell *cell2 = reinterpret_cast<FredkinCell *>(cell1.clone());
  cell2->_alive = false;
  if (cell2->_alive)
    ASSERT_FALSE(true);
  if (cell1._alive)
    ASSERT_FALSE(true);
  delete cell2;
}

TEST(LifeFixture, fredkin_clone_5) {
  FredkinCell cell1(false);
  FredkinCell *cell2 = reinterpret_cast<FredkinCell *>(cell1.clone());
  cell2->_age = 1;
  if (cell2->_age != 1)
    ASSERT_FALSE(true);
  if (cell1._age != 0)
    ASSERT_FALSE(true);
  delete cell2;
}

TEST(LifeFixture, fredkin_clone_6) {
  FredkinCell cell1(false);
  FredkinCell *cell2 = reinterpret_cast<FredkinCell *>(cell1.clone());
  cell2->_age = 3;
  cell1._age = 2;
  if (cell2->_age != 3)
    ASSERT_FALSE(true);
  if (cell1._age != 2)
    ASSERT_FALSE(true);
  delete cell2;
}

TEST(LifeFixture, fredkin_clone_7) {
  FredkinCell cell1(false);
  FredkinCell *cell2 = reinterpret_cast<FredkinCell *>(cell1.clone());
  cell2->_age = 1;
  cell1._age = 2;
  if (cell2->_age != 1)
    ASSERT_FALSE(true);
  if (cell1._age != 2)
    ASSERT_FALSE(true);
  delete cell2;
}

TEST(LifeFixture, fredkin_clone_8) {
  FredkinCell cell1(false);
  FredkinCell *cell2 = reinterpret_cast<FredkinCell *>(cell1.clone());
  cell2->_age = 2;
  cell1._age = 1;
  if (cell2->_age != 2)
    ASSERT_FALSE(true);
  if (cell1._age != 1)
    ASSERT_FALSE(true);
  delete cell2;
}

// ----
// should_become_conway
// ----

TEST(LifeFixture, should_become_conway_1) {
  FredkinCell cell(false);
  ASSERT_EQ(cell.should_become_conway(), false);
}

TEST(LifeFixture, should_become_conway_2) {
  FredkinCell cell(false);
  cell._age = 0;
  ASSERT_EQ(cell.should_become_conway(), false);
}

TEST(LifeFixture, should_become_conway_3) {
  FredkinCell cell(false);
  cell._age = 2;
  ASSERT_EQ(cell.should_become_conway(), true);
}

TEST(LifeFixture, should_become_conway_4) {
  FredkinCell cell(false);
  cell._age = 3;
  ASSERT_EQ(cell.should_become_conway(), true);
}

// ----
// alive_count
// ----

TEST(LifeFixture, alive_count_1) {
  Life<ConwayCell, 5, 5> life;
  life.add_cell(new ConwayCell(true), 0, 0);
  ASSERT_EQ(life.alive_count(), 1);
}

TEST(LifeFixture, alive_count_2) {
  Life<ConwayCell, 5, 5> life;
  life.add_cell(new ConwayCell(false), 0, 0);
  ASSERT_EQ(life.alive_count(), 0);
}

TEST(LifeFixture, alive_count_3) {
  Life<ConwayCell, 5, 5> life;
  life.add_cell(new ConwayCell(true), 0, 0);
  life.add_cell(new ConwayCell(false), 1, 0);
  ASSERT_EQ(life.alive_count(), 1);
}

TEST(LifeFixture, alive_count_4) {
  Life<ConwayCell, 5, 5> life;
  life.add_cell(new ConwayCell(true), 0, 0);
  life.add_cell(new ConwayCell(true), 1, 0);
  ASSERT_EQ(life.alive_count(), 2);
}

TEST(LifeFixture, alive_count_5) {
  Life<FredkinCell, 5, 5> life;
  life.add_cell(new FredkinCell(true), 0, 0);
  ASSERT_EQ(life.alive_count(), 1);
}

TEST(LifeFixture, alive_count_6) {
  Life<FredkinCell, 5, 5> life;
  life.add_cell(new FredkinCell(false), 0, 0);
  ASSERT_EQ(life.alive_count(), 0);
}

TEST(LifeFixture, alive_count_7) {
  Life<FredkinCell, 5, 5> life;
  life.add_cell(new FredkinCell(true), 0, 0);
  life.add_cell(new FredkinCell(false), 1, 0);
  ASSERT_EQ(life.alive_count(), 1);
}

TEST(LifeFixture, alive_count_8) {
  Life<FredkinCell, 5, 5> life;
  life.add_cell(new FredkinCell(true), 0, 0);
  life.add_cell(new FredkinCell(true), 1, 0);
  ASSERT_EQ(life.alive_count(), 2);
}

TEST(LifeFixture, alive_count_9) {
  Life<Cell, 5, 5> life;
  life.add_cell(Cell(new FredkinCell(true)), 0, 0);
  ASSERT_EQ(life.alive_count(), 1);
}

TEST(LifeFixture, alive_count_10) {
  Life<Cell, 5, 5> life;
  life.add_cell(Cell(new FredkinCell(false)), 0, 0);
  ASSERT_EQ(life.alive_count(), 0);
}

TEST(LifeFixture, alive_count_11) {
  Life<Cell, 5, 5> life;
  life.add_cell(Cell(new FredkinCell(true)), 0, 0);
  life.add_cell(Cell(new ConwayCell(false)), 1, 0);
  ASSERT_EQ(life.alive_count(), 1);
}

TEST(LifeFixture, alive_count_12) {
  Life<Cell, 5, 5> life;
  life.add_cell(Cell(new FredkinCell(true)), 0, 0);
  life.add_cell(Cell(new ConwayCell(true)), 1, 0);
  ASSERT_EQ(life.alive_count(), 2);
}
