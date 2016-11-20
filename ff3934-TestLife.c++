// --------------------------
// projects/life/TestLife.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <sstream>
#include "gtest/gtest.h"

#include "Life.h"

using namespace std;

// ----------------------------
// testing AbstractCell methods
// ----------------------------

TEST(AbstractCellFixture, bear_test1) {
   ConwayCell ac (dead);
   ac.bear ();
   ASSERT_TRUE(ac.is_alive ());}

TEST(AbstractCellFixture, bear_test2) {
   ConwayCell ac (alive);
   ac.die ();
   ASSERT_FALSE(ac.is_alive ());
   ac.bear ();
   ASSERT_TRUE(ac.is_alive ());}

TEST(AbstractCellFixture, bear_test3) {
   ConwayCell ac (dead);
   ac.bear ();
   ac.die ();
   ASSERT_FALSE(ac.is_alive ());
   ac.bear ();
   ASSERT_TRUE(ac.is_alive ());}

TEST(AbstractCellFixture, die_test1) {
   ConwayCell ac (alive);
   ac.die ();
   ASSERT_FALSE(ac.is_alive ());}

TEST(AbstractCellFixture, die_test2) {
   ConwayCell ac (dead);
   ac.bear ();
   ASSERT_TRUE(ac.is_alive ());
   ac.die ();
   ASSERT_FALSE(ac.is_alive ());}

TEST(AbstractCellFixture, die_test3) {
   ConwayCell ac (alive);
   ac.die ();
   ac.bear ();
   ASSERT_TRUE(ac.is_alive ());
   ac.die ();
   ASSERT_FALSE(ac.is_alive ());}

TEST(AbstractCellFixture, is_alive_test1) {
   ConwayCell ac (alive);
   ASSERT_TRUE(ac.is_alive ());}

TEST(AbstractCellFixture, is_alive_test2) {
   ConwayCell ac (dead);
   ASSERT_FALSE(ac.is_alive ());}

TEST(AbstractCellFixture, is_alive_test3) {
   ConwayCell ac (dead);
   ASSERT_FALSE(ac.is_alive ());
   ac.bear ();
   ASSERT_TRUE(ac.is_alive ());
   ac.die ();
   ASSERT_FALSE(ac.is_alive ());}

// --------------------------
// testing ConwayCell methods
// --------------------------

TEST(ConwayCellFixture, destiny_test1) {
   ConwayCell cc (dead);
   cc.destiny (2, 2);
   ASSERT_FALSE(cc.is_alive ());}

TEST(ConwayCellFixture, destiny_test2) {
   ConwayCell cc (dead);
   cc.destiny (3, 2);
   ASSERT_TRUE(cc.is_alive ());}

TEST(ConwayCellFixture, destiny_test3) {
   ConwayCell cc (alive);
   cc.destiny (1, 1);
   ASSERT_FALSE(cc.is_alive ());
   cc.destiny (3, 1);
   cc.destiny (2, 1);
   ASSERT_TRUE(cc.is_alive ());}

TEST(ConwayCellFixture, clone_test1) {
   ConwayCell cc (alive);
   ConwayCell* cp;
   cp = cc.clone ();
   ASSERT_TRUE(cp->is_alive ());
   delete (cp);}

TEST(ConwayCellFixture, clone_test2) {
   ConwayCell cc (dead);
   ConwayCell* cp;
   cp = cc.clone ();
   ASSERT_FALSE(cp->is_alive ());
   delete (cp);}

TEST(ConwayCellFixture, clone_test3) {
   ConwayCell cc (dead);
   ConwayCell* cp;
   cp = cc.clone ();
   cp->destiny (3, 2);
   ASSERT_TRUE(cp->is_alive ());
   delete (cp);}

// ---------------------------
// testing FredkinCell methods
// ---------------------------

TEST(FredkinCellFixture, survived_test1) {
   FredkinCell fc (alive);
   fc.survived ();
   ASSERT_TRUE(fc.age == 1);}

TEST(FredkinCellFixture, survived_test2) {
   FredkinCell fc (alive);
   fc.survived ();
   fc.survived ();
   ASSERT_TRUE(fc.age == 2);}

TEST(FredkinCellFixture, survived_test3) {
   FredkinCell fc (alive);
   ASSERT_TRUE(fc.age == 0);
   fc.survived ();
   ASSERT_TRUE(fc.age == 1);
   fc.survived ();
   ASSERT_TRUE(fc.age == 2);
   fc.survived ();
   ASSERT_TRUE(fc.age == 3);}

TEST(FredkinCellFixture, evolve_test1) {
   FredkinCell fc (alive);
   ASSERT_FALSE(fc.evolve ());}

TEST(FredkinCellFixture, evolve_test2) {
   FredkinCell fc (alive);
   fc.survived ();
   ASSERT_FALSE(fc.evolve ());}

TEST(FredkinCellFixture, evolve_test3) {
   FredkinCell fc (alive);
   ASSERT_FALSE(fc.evolve ());
   fc.survived ();
   ASSERT_FALSE(fc.evolve ());
   fc.survived ();
   ASSERT_TRUE(fc.evolve ());}

TEST(FredkinCellFixture, destiny_test1) {
   FredkinCell fc (dead);
   fc.destiny (2, 2);
   ASSERT_FALSE(fc.is_alive ());}

TEST(FredkinCellFixture, destiny_test2) {
   FredkinCell fc (dead);
   fc.destiny (3, 1);
   ASSERT_TRUE(fc.is_alive ());}

TEST(FredkinCellFixture, destiny_test3) {
   FredkinCell fc (alive);
   fc.destiny (2, 2);
   ASSERT_FALSE(fc.is_alive ());
   fc.destiny (3, 2);
   fc.destiny (2, 1);
   ASSERT_TRUE(fc.is_alive ());}

TEST(FredkinCellFixture, clone_test1) {
   FredkinCell fc (alive);
   FredkinCell* fp;
   fp = fc.clone ();
   ASSERT_TRUE(fp->is_alive ());
   delete (fp);}

TEST(FredkinCellFixture, clone_test2) {
   FredkinCell fc (dead);
   FredkinCell* fp;
   fp = fc.clone ();
   ASSERT_FALSE(fp->is_alive ());
   delete (fp);}

TEST(FredkinCellFixture, clone_test3) {
   FredkinCell fc (dead);
   FredkinCell* fp;
   fp = fc.clone ();
   fp->destiny (3, 1);
   ASSERT_TRUE(fp->is_alive ());
   delete (fp);}

// --------------------
// testing Life methods
// --------------------

TEST(LifeFixture, is_index_valid_test1) {
   Life<ConwayCell> l (5, 5);
   ASSERT_FALSE(l.is_index_valid (-1));}

TEST(LifeFixture, is_index_valid_test2) {
   Life<ConwayCell> l (5, 5);
   ASSERT_TRUE(l.is_index_valid (1));}

TEST(LifeFixture, is_index_valid_test3) {
   Life<ConwayCell> l (5, 5);
   ASSERT_FALSE(l.is_index_valid (28));}

TEST(LifeFixture, add_cell_test1) {
   Life<ConwayCell> l (5, 5);
   ConwayCell dead_cc (dead);
   ConwayCell alive_cc (alive);
   l.add_cell (dead_cc, 1);
   l.add_cell (alive_cc, 5);
   ASSERT_TRUE(l.grid.at (5).is_alive ());
   ASSERT_FALSE(l.grid.at (1).is_alive ());}

TEST(LifeFixture, add_cell_test2) {
   Life<FredkinCell> l (5, 5);
   FredkinCell dead_cc (dead);
   FredkinCell alive_cc (alive);
   l.add_cell (dead_cc, 1);
   l.add_cell (alive_cc, 5);
   ASSERT_TRUE(l.grid.at (5).is_alive ());
   ASSERT_FALSE(l.grid.at (1).is_alive ());}

TEST(LifeFixture, add_cell_test3) {
   Life<Cell> l (5, 5);
   Cell deadFredkin_c (fredkin, dead);
   Cell aliveFredkin_c (fredkin, alive);
   Cell deadConway_c (conway, dead);
   Cell aliveConway_c (conway, alive);
   l.add_cell (deadFredkin_c, 1);
   l.add_cell (aliveFredkin_c, 5);
   l.add_cell (deadConway_c, 2);
   l.add_cell (aliveConway_c, 6);
   ASSERT_TRUE(l.grid.at (5).is_alive ());
   ASSERT_FALSE(l.grid.at (1).is_alive ());
   ASSERT_TRUE(l.grid.at (6).is_alive ());
   ASSERT_FALSE(l.grid.at (2).is_alive ());}

TEST(LifeFixture, count_neighbors_test1) {
   Life<ConwayCell> l (2, 2);
   ConwayCell dead_cc (dead);
   ConwayCell alive_cc (alive);
   l.add_cell (dead_cc, 0);
   l.add_cell (dead_cc, 1);
   l.add_cell (dead_cc, 2);
   l.add_cell (alive_cc, 3);
   ASSERT_TRUE(l.count_neighbors (3) == 0);
   ASSERT_TRUE(l.count_neighbors (2) == 1);}
