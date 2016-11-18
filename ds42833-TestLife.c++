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

//---------------
// CC Constructor
//---------------

TEST(LifeFixture, cc_construct1) {
	CC cc_cell('*');
	ASSERT_EQ('*', cc_cell.display);
	ASSERT_EQ(true, cc_cell.living());
}

TEST(LifeFixture, cc_construct2) {
	CC cc_cell('.');
	ASSERT_EQ('.', cc_cell.display);
	ASSERT_EQ(false, cc_cell.living());
}

//---------------
// FC Constructor
//---------------

TEST(LifeFixture, fc_construct1) {
	FC fc_cell('-');
	ASSERT_EQ('-', fc_cell.display);
	ASSERT_EQ(false, fc_cell.living());
}

TEST(LifeFixture, fc_construct2) {
	FC fc_cell('0');
	ASSERT_EQ('0', fc_cell.display);
	ASSERT_EQ(true, fc_cell.living());
}

//----------
// CC Evolve
//----------

TEST(LifeFixture, evolve_CC1) {
	CC cc_cell('.');
	cc_cell.evolve();
	ASSERT_EQ(false, cc_cell.living());
}

TEST(LifeFixture, evolve_CC2) {
	CC cc_cell('*');
	cc_cell.evolve();
	ASSERT_EQ(false, cc_cell.living());
}

TEST(LifeFixture, evolve_CC3) {
	CC cc_cell('*');
	cc_cell.numNeighbors = 1;
	cc_cell.evolve();
	ASSERT_EQ('.', cc_cell.display);
}

TEST(LifeFixture, evolve_CC4) {
	CC cc_cell('*');
	cc_cell.numNeighbors = 2;
	cc_cell.evolve();
	ASSERT_EQ('*', cc_cell.display);
}

//----------
// FC Evolve
//----------

TEST(LifeFixture, evolve_FC1) {
	FC fc_cell('-');
	fc_cell.numNeighbors = 1;
	fc_cell.evolve();
	ASSERT_EQ('0', fc_cell.display);
}

TEST(LifeFixture, evolve_FC2) {
	FC fc_cell('-');
	fc_cell.numNeighbors = 3;
	fc_cell.evolve();
	ASSERT_EQ('0', fc_cell.display);
}

TEST(LifeFixture, evolve_FC3) {
	FC fc_cell('0');
	fc_cell.age = 5;
	fc_cell.evolve();
	ASSERT_EQ('-', fc_cell.display);
}

TEST(LifeFixture, evolve_FC4) {
	FC fc_cell('0');
	fc_cell.age = 9;
	fc_cell.numNeighbors = 3;
	fc_cell.evolve();
	ASSERT_EQ('+', fc_cell.display);
}

TEST(LifeFixture, evolve_FC5) {
	FC fc_cell('0');
	fc_cell.age = 1;
	fc_cell.numNeighbors = 4;
	fc_cell.evolve();
	ASSERT_EQ('-', fc_cell.display);
}

TEST(LifeFixture, evolve_FC6) {
	FC fc_cell('0');
	fc_cell.numNeighbors = 3;
	fc_cell.evolve();
	ASSERT_EQ('1', fc_cell.display);
	ASSERT_EQ(true, fc_cell.living());
}

//----------
// CC Neighbor
//----------

TEST(LifeFixture, neighbor_CC1) {
	CC cc_cell('*');
	cc_cell.numNeighbors = 0;
	cc_cell.corner_neighbor();
	ASSERT_EQ(1, cc_cell.numNeighbors);
}

TEST(LifeFixture, neighbor_CC2) {
	CC cc_cell('*');
	cc_cell.numNeighbors = 0;
	cc_cell.corner_neighbor();
	cc_cell.corner_neighbor();
	cc_cell.corner_neighbor();
	ASSERT_EQ(3, cc_cell.numNeighbors);
}

TEST(LifeFixture, neighbor_CC3) {
	CC cc_cell('*');
	cc_cell.numNeighbors = 0;
	cc_cell.corner_neighbor();
	cc_cell.numNeighbors = 3;
	cc_cell.corner_neighbor();
	ASSERT_EQ(4, cc_cell.numNeighbors);
}

TEST(LifeFixture, neighbor_CC4) {
	CC cc_cell('*');
	cc_cell.numNeighbors = 0;
	cc_cell.side_neighbor();
	ASSERT_EQ(1, cc_cell.numNeighbors);
}

TEST(LifeFixture, neighbor_CC5) {
	CC cc_cell('*');
	cc_cell.numNeighbors = 0;
	cc_cell.side_neighbor();
	cc_cell.side_neighbor();
	cc_cell.side_neighbor();
	ASSERT_EQ(3, cc_cell.numNeighbors);
}

TEST(LifeFixture, neighbor_CC6) {
	CC cc_cell('*');
	cc_cell.numNeighbors = 0;
	cc_cell.side_neighbor();
	cc_cell.numNeighbors = 3;
	cc_cell.corner_neighbor();
	cc_cell.side_neighbor();
	ASSERT_EQ(5, cc_cell.numNeighbors);
}

//----------
// FC Neighbor
//----------

TEST(LifeFixture, neighbor_FC1) {
	FC fc_cell('*');
	fc_cell.numNeighbors = 0;
	fc_cell.corner_neighbor();
	ASSERT_EQ(0, fc_cell.numNeighbors);
}

TEST(LifeFixture, neighbor_FC2) {
	FC fc_cell('*');
	fc_cell.numNeighbors = 0;
	fc_cell.corner_neighbor();
	fc_cell.numNeighbors = 0;
	fc_cell.corner_neighbor();
	ASSERT_EQ(0, fc_cell.numNeighbors);
}

TEST(LifeFixture, neighbor_FC3) {
	FC fc_cell('*');
	fc_cell.numNeighbors = 0;
	fc_cell.side_neighbor();
	ASSERT_EQ(1, fc_cell.numNeighbors);
}

TEST(LifeFixture, neighbor_FC4) {
	FC fc_cell('*');
	fc_cell.numNeighbors = 0;
	fc_cell.side_neighbor();
	fc_cell.side_neighbor();
	fc_cell.side_neighbor();
	ASSERT_EQ(3, fc_cell.numNeighbors);
}

TEST(LifeFixture, neighbor_FC5) {
	FC fc_cell('*');
	fc_cell.numNeighbors = 0;
	fc_cell.corner_neighbor();
	fc_cell.side_neighbor();
	fc_cell.newTurn();
	ASSERT_EQ(0, fc_cell.numNeighbors);
}

TEST(LifeFixture, neighbor_FC6) {
	FC fc_cell('*');
	fc_cell.numNeighbors = 0;
	fc_cell.corner_neighbor();
	fc_cell.side_neighbor();
	ASSERT_EQ(1, fc_cell.numNeighbors);
}

//----------
// New Turn
//----------

TEST(LifeFixture, new_turnCC) {
	CC cc_cell('*');
	cc_cell.numNeighbors = 0;
	cc_cell.newTurn();
	ASSERT_EQ(0, cc_cell.numNeighbors);
	cc_cell.numNeighbors = 3;
	cc_cell.newTurn();
	ASSERT_EQ(0, cc_cell.numNeighbors);
}

TEST(LifeFixture, new_turnFC) {
	FC fc_cell('0');
	fc_cell.numNeighbors = 0;
	fc_cell.newTurn();
	ASSERT_EQ(0, fc_cell.numNeighbors);
	fc_cell.numNeighbors = 3;
	fc_cell.newTurn();
	ASSERT_EQ(0, fc_cell.numNeighbors);
}

//----------
// CC Clone
//----------

TEST(LifeFixture, clone_CC1) {
	CC cc_cell('*');
	AC* new_cell = cc_cell.clone();
	ASSERT_EQ(cc_cell.display, new_cell->display);
	delete new_cell;
}

TEST(LifeFixture, clone_CC2) {
	CC cc_cell('*');
	AC* new_cell = cc_cell.clone();
	ASSERT_EQ(cc_cell.numNeighbors, new_cell->numNeighbors);
	ASSERT_NE(&cc_cell, new_cell);
	delete new_cell;
}

TEST(LifeFixture, clone_CC3) {
	CC cc_cell('*');
	AC* new_cell = cc_cell.clone();
	ASSERT_NE(&cc_cell, new_cell);
	delete new_cell;
}

//----------
// FC Clone
//----------

TEST(LifeFixture, clone_FC1) {
	FC fc_cell('-');
	AC* new_fc = fc_cell.clone();
	ASSERT_EQ(fc_cell.display, new_fc->display);
	delete new_fc;
}

TEST(LifeFixture, clone_FC2) {
	FC fc_cell('-');
	AC* new_fc = fc_cell.clone();
	ASSERT_EQ(fc_cell.numNeighbors, new_fc->numNeighbors);
	delete new_fc;
}

TEST(LifeFixture, clone_FC3) {
	FC fc_cell('-');
	AC* new_fc = fc_cell.clone();
	ASSERT_NE(&fc_cell, new_fc);
	delete new_fc;
}

//----------
// Cell Clone
//----------

TEST(LifeFixture, clone_Cell1) {
	Cell c_cell('*');
	Cell* new_cell = c_cell.clone();
	ASSERT_NE(&c_cell, new_cell);
	delete new_cell;
}

TEST(LifeFixture, clone_Cell2) {
	Cell c_cell('*');
	Cell* new_cell = c_cell.clone();
	ASSERT_NE(c_cell._p, new_cell->_p);
	delete new_cell;
}

TEST(LifeFixture, clone_Cell3) {
	Cell c_cell('0');
	Cell* new_cell = c_cell.clone();
	ASSERT_NE(c_cell._p, new_cell->_p);
	ASSERT_NE(&c_cell, new_cell);
	delete new_cell;
}

//----------
// Life InBounds
//----------

TEST(LifeFixture, inbounds1) {
	vector<vector<char> > temp(2, vector<char>(2, '*'));
	Life<CC> life (2, 2, temp);
    ASSERT_FALSE(life.inBounds(-1,-1));
}

TEST(LifeFixture, inbounds2) {
	vector<vector<char> > temp(2, vector<char>(2, '*'));
	Life<CC> life (2, 2, temp);
    ASSERT_TRUE(life.inBounds(0,0));
}

TEST(LifeFixture, inbounds3) {
	vector<vector<char> > temp(2, vector<char>(2, '*'));
	Life<CC> life (2, 2, temp);
    ASSERT_FALSE(life.inBounds(3,3));
}

TEST(LifeFixture, inbounds4) {
	vector<vector<char> > temp(3, vector<char>(3, '*'));
	Life<CC> life (3, 3, temp);
    ASSERT_FALSE(life.inBounds(3,3));
}

TEST(LifeFixture, inbounds5) {
	vector<vector<char> > temp(3, vector<char>(3, '*'));
	Life<CC> life (3, 3, temp);
    ASSERT_FALSE(life.inBounds(1,-1));
}

TEST(LifeFixture, inbounds6) {
	vector<vector<char> > temp(4, vector<char>(4, '*'));
	Life<CC> life (4, 4, temp);
    ASSERT_FALSE(life.inBounds(4,3));
}
TEST(LifeFixture, inbounds7) {
	vector<vector<char> > temp(2, vector<char>(2, '*'));
	Life<CC> life (2, 2, temp);
    ASSERT_FALSE(life.inBounds(654,3));
}

TEST(LifeFixture, inbounds8) {
	vector<vector<char> > temp(2, vector<char>(2, '*'));
	Life<CC> life (2, 2, temp);
    ASSERT_FALSE(life.inBounds(3,-88));
}
