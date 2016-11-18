// --------------------------
// projects/life/TestLife.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <vector>  //vector
#include <utility> //pair
#include "gtest/gtest.h"
#include "Life.h"

using namespace std;

// ----------------
// ConwayCell Tests
// ----------------

TEST(ConwayCellFixture, test_default1) {
  ConwayCell cc;
  ASSERT_EQ('.', cc._id);
}
TEST(ConwayCellFixture, test_default2) {
  ConwayCell cc;
  ASSERT_EQ('.', cc._id);
}
TEST(ConwayCellFixture, test_default3) {
  ConwayCell cc;
  ASSERT_EQ('.', cc._id);
}

TEST(ConwayCellFixture, test_revive1) {
  ConwayCell cc;
  cc.revive();
  ASSERT_EQ('*', cc._id);
}
TEST(ConwayCellFixture, test_revive2) {
  ConwayCell cc;
  cc.revive();
  cc.revive();
  ASSERT_EQ('*', cc._id);
}
TEST(ConwayCellFixture, test_revive3) {
  ConwayCell cc;
  ConwayCell cc1;
  cc.revive();
  cc1.revive();
  ASSERT_EQ(cc._id, cc1._id);
}

TEST(ConwayCellFixture, test_kill1) {
  ConwayCell cc;
  cc.kill();
  ASSERT_EQ('.', cc._id);
}
TEST(ConwayCellFixture, test_kill2) {
  ConwayCell cc;
  cc.revive();
  ASSERT_EQ('*', cc._id);
  cc.kill();
  ASSERT_EQ('.', cc._id);
}
TEST(ConwayCellFixture, test_kill3) {
  ConwayCell cc;
  cc.kill();
  cc.kill();
  ASSERT_EQ('.', cc._id);
}

TEST(ConwayCellFixture, test_printID1) {
  ConwayCell cc;
  ostringstream w;
  cc.printID(w);
  ASSERT_EQ(".", w.str());
}
TEST(ConwayCellFixture, test_printID2) {
  ConwayCell cc;
  cc.revive();
  ostringstream w;
  cc.printID(w);
  ASSERT_EQ("*", w.str());
}
TEST(ConwayCellFixture, test_printID3) {
  ConwayCell cc;
  cc.revive();
  ostringstream w;
  cc.printID(w);
  ASSERT_EQ("*", w.str());
  cc.kill();
  ostringstream w1;
  cc.printID(w1);
  ASSERT_EQ(".", w1.str());
}

TEST(ConwayCellFixture, test_clone1) {
  ConwayCell cc;
  AbstractCell *cc1 = cc.clone();
  ostringstream w;
  ostringstream w1;
  cc.printID(w);
  cc1->printID(w1);
  ASSERT_EQ(w.str(), w1.str());
  delete cc1;
}
TEST(ConwayCellFixture, test_clone2) {
  ConwayCell cc;
  AbstractCell *cc1 = cc.clone();
  cc.revive();
  cc1->revive();
  ostringstream w;
  ostringstream w1;
  cc.printID(w);
  cc1->printID(w1);
  ASSERT_EQ(w.str(), w1.str());
  delete cc1;
}
TEST(ConwayCellFixture, test_clone3) {
  ConwayCell cc;
  AbstractCell *cc1 = cc.clone();
  cc.revive();
  cc.kill();
  cc1->revive();
  cc1->kill();
  ostringstream w;
  ostringstream w1;
  cc.printID(w);
  cc1->printID(w1);
  ASSERT_EQ(w.str(), w1.str());
  delete cc1;
}

TEST(ConwayCellFixture, test_evolve1) {
  ConwayCell cc;
  AbstractCell *cc1 = cc.evolve(3);
  ostringstream w;
  cc.printID(w);
  ASSERT_EQ("*", w.str());
  ASSERT_EQ(nullptr, cc1);
  delete cc1;
}
TEST(ConwayCellFixture, test_evolve2) {
  ConwayCell cc;
  cc.revive();
  AbstractCell *cc1 = cc.evolve(1);
  ostringstream w;
  cc.printID(w);
  ASSERT_EQ(".", w.str());
  ASSERT_EQ(nullptr, cc1);
  delete cc1;
}
TEST(ConwayCellFixture, test_evolve3) {
  ConwayCell cc;
  cc.revive();
  AbstractCell *cc1 = cc.evolve(4);
  ostringstream w;
  cc.printID(w);
  ASSERT_EQ(".", w.str());
  ASSERT_EQ(nullptr, cc1);
  delete cc1;
}

TEST(ConwayCellFixture, test_isAlive1) {
  ConwayCell cc;
  cc.revive();
  ASSERT_TRUE(cc.isAlive());
}
TEST(ConwayCellFixture, test_isAlive2) {
  ConwayCell cc;
  ASSERT_FALSE(cc.isAlive());
}
TEST(ConwayCellFixture, test_isAlive3) {
  ConwayCell cc;
  cc.revive();
  ASSERT_TRUE(cc.isAlive());
  cc.kill();
  ASSERT_FALSE(cc.isAlive());
}

TEST(ConwayCellFixture, test_getNeighborCoordinates1) {
  ConwayCell cc;
  vector<pair<int, int>> neighborCoordinates;
  int cellType = 0; // interior cell
  cc.getNeighborCoordinates(1, 1, 3, 3, neighborCoordinates, cellType);
  ASSERT_EQ(make_pair(0, 0), neighborCoordinates[0]);
  ASSERT_EQ(make_pair(0, 1), neighborCoordinates[1]);
  ASSERT_EQ(make_pair(0, 2), neighborCoordinates[2]);
  ASSERT_EQ(make_pair(1, 0), neighborCoordinates[3]);
  ASSERT_EQ(make_pair(1, 2), neighborCoordinates[4]);
  ASSERT_EQ(make_pair(2, 0), neighborCoordinates[5]);
  ASSERT_EQ(make_pair(2, 1), neighborCoordinates[6]);
  ASSERT_EQ(make_pair(2, 2), neighborCoordinates[7]);
}
TEST(ConwayCellFixture, test_getNeighborCoordinates2) {
  ConwayCell cc;
  vector<pair<int, int>> neighborCoordinates1;
  vector<pair<int, int>> neighborCoordinates2;
  vector<pair<int, int>> neighborCoordinates3;
  vector<pair<int, int>> neighborCoordinates4;
  int cellType = 1; // edge cell
  // top edge cell
  cc.getNeighborCoordinates(0, 1, 3, 3, neighborCoordinates1, cellType);
  ASSERT_EQ(make_pair(0, 0), neighborCoordinates1[0]);
  ASSERT_EQ(make_pair(0, 2), neighborCoordinates1[1]);
  ASSERT_EQ(make_pair(1, 0), neighborCoordinates1[2]);
  ASSERT_EQ(make_pair(1, 1), neighborCoordinates1[3]);
  ASSERT_EQ(make_pair(1, 2), neighborCoordinates1[4]);

  // left edge cell
  cc.getNeighborCoordinates(1, 0, 3, 3, neighborCoordinates2, cellType);
  ASSERT_EQ(make_pair(0, 0), neighborCoordinates2[0]);
  ASSERT_EQ(make_pair(0, 1), neighborCoordinates2[1]);
  ASSERT_EQ(make_pair(1, 1), neighborCoordinates2[2]);
  ASSERT_EQ(make_pair(2, 0), neighborCoordinates2[3]);
  ASSERT_EQ(make_pair(2, 1), neighborCoordinates2[4]);
  // right edge cell
  cc.getNeighborCoordinates(1, 2, 3, 3, neighborCoordinates3, cellType);
  ASSERT_EQ(make_pair(0, 1), neighborCoordinates3[0]);
  ASSERT_EQ(make_pair(0, 2), neighborCoordinates3[1]);
  ASSERT_EQ(make_pair(1, 1), neighborCoordinates3[2]);
  ASSERT_EQ(make_pair(2, 1), neighborCoordinates3[3]);
  ASSERT_EQ(make_pair(2, 2), neighborCoordinates3[4]);
  // bottom edge cell
  cc.getNeighborCoordinates(2, 1, 3, 3, neighborCoordinates4, cellType);
  ASSERT_EQ(make_pair(1, 0), neighborCoordinates4[0]);
  ASSERT_EQ(make_pair(1, 1), neighborCoordinates4[1]);
  ASSERT_EQ(make_pair(1, 2), neighborCoordinates4[2]);
  ASSERT_EQ(make_pair(2, 0), neighborCoordinates4[3]);
  ASSERT_EQ(make_pair(2, 2), neighborCoordinates4[4]);
}
TEST(ConwayCellFixture, test_getNeighborCoordinates3) {
  ConwayCell cc;
  vector<pair<int, int>> neighborCoordinates1;
  vector<pair<int, int>> neighborCoordinates2;
  vector<pair<int, int>> neighborCoordinates3;
  vector<pair<int, int>> neighborCoordinates4;
  int cellType = 2; // corner cell
  // top left
  cc.getNeighborCoordinates(0, 0, 3, 3, neighborCoordinates1, cellType);
  ASSERT_EQ(make_pair(0, 1), neighborCoordinates1[0]);
  ASSERT_EQ(make_pair(1, 0), neighborCoordinates1[1]);
  ASSERT_EQ(make_pair(1, 1), neighborCoordinates1[2]);
  // top right
  cc.getNeighborCoordinates(0, 2, 3, 3, neighborCoordinates2, cellType);
  ASSERT_EQ(make_pair(0, 1), neighborCoordinates2[0]);
  ASSERT_EQ(make_pair(1, 1), neighborCoordinates2[1]);
  ASSERT_EQ(make_pair(1, 2), neighborCoordinates2[2]);
  // bottom left
  cc.getNeighborCoordinates(2, 0, 3, 3, neighborCoordinates3, cellType);
  ASSERT_EQ(make_pair(1, 0), neighborCoordinates3[0]);
  ASSERT_EQ(make_pair(1, 1), neighborCoordinates3[1]);
  ASSERT_EQ(make_pair(2, 1), neighborCoordinates3[2]);
  // bottom right
  cc.getNeighborCoordinates(2, 2, 3, 3, neighborCoordinates4, cellType);
  ASSERT_EQ(make_pair(1, 1), neighborCoordinates4[0]);
  ASSERT_EQ(make_pair(1, 2), neighborCoordinates4[1]);
  ASSERT_EQ(make_pair(2, 1), neighborCoordinates4[2]);
}

// ----------------
// FredkinCell Tests
// ----------------

TEST(FredkinCellFixture, test_default1) {
  FredkinCell fc;
  ASSERT_EQ('-', fc._id);
  ASSERT_EQ(0, fc._age);
}
TEST(FredkinCellFixture, test_default2) {
  FredkinCell fc;
  ASSERT_EQ('-', fc._id);
  ASSERT_EQ(0, fc._age);
}
TEST(FredkinCellFixture, test_default3) {
  FredkinCell fc;
  ASSERT_EQ('-', fc._id);
  ASSERT_EQ(0, fc._age);
}

TEST(FredkinCellFixture, test_revive1) {
  FredkinCell fc;
  fc.revive();
  ASSERT_EQ('0', fc._id);
}
TEST(FredkinCellFixture, test_revive2) {
  FredkinCell fc;
  fc.revive();
  fc.revive();
  ASSERT_EQ('0', fc._id);
}
TEST(FredkinCellFixture, test_revive3) {
  FredkinCell fc;
  FredkinCell fc1;
  fc.revive();
  fc1.revive();
  ASSERT_EQ(fc._id, fc1._id);
}

TEST(FredkinCellFixture, test_kill1) {
  FredkinCell fc;
  fc.kill();
  ASSERT_EQ('-', fc._id);
}
TEST(FredkinCellFixture, test_kill2) {
  FredkinCell fc;
  fc.revive();
  ASSERT_EQ('0', fc._id);
  fc.kill();
  ASSERT_EQ('-', fc._id);
}
TEST(FredkinCellFixture, test_kill3) {
  FredkinCell fc;
  fc.kill();
  fc.kill();
  ASSERT_EQ('-', fc._id);
}

TEST(FredkinCellFixture, test_printID1) {
  FredkinCell fc;
  ostringstream w;
  fc.printID(w);
  ASSERT_EQ("-", w.str());
}
TEST(FredkinCellFixture, test_printID2) {
  FredkinCell fc;
  fc.revive();
  ostringstream w;
  fc.printID(w);
  ASSERT_EQ("0", w.str());
}
TEST(FredkinCellFixture, test_printID3) {
  FredkinCell fc;
  fc.revive();
  ostringstream w;
  fc.printID(w);
  ASSERT_EQ("0", w.str());
  fc.kill();
  ostringstream w1;
  fc.printID(w1);
  ASSERT_EQ("-", w1.str());
}

TEST(FredkinCellFixture, test_clone1) {
  FredkinCell fc;
  AbstractCell *fc1 = fc.clone();
  ostringstream w;
  ostringstream w1;
  fc.printID(w);
  fc1->printID(w1);
  ASSERT_EQ(w.str(), w1.str());
  delete fc1;
}
TEST(FredkinCellFixture, test_clone2) {
  FredkinCell fc;
  AbstractCell *fc1 = fc.clone();
  fc.revive();
  fc1->revive();
  ostringstream w;
  ostringstream w1;
  fc.printID(w);
  fc1->printID(w1);
  ASSERT_EQ(w.str(), w1.str());
  delete fc1;
}
TEST(FredkinCellFixture, test_clone3) {
  FredkinCell fc;
  AbstractCell *fc1 = fc.clone();
  fc.revive();
  fc.kill();
  fc1->revive();
  fc1->kill();
  ostringstream w;
  ostringstream w1;
  fc.printID(w);
  fc1->printID(w1);
  ASSERT_EQ(w.str(), w1.str());
  delete fc1;
}

TEST(FredkinCellFixture, test_evolve1) {
  FredkinCell fc;
  AbstractCell *fc1 = fc.evolve(3);
  ostringstream w;
  fc.printID(w);
  ASSERT_EQ("0", w.str());
  ASSERT_EQ(nullptr, fc1);
  delete fc1;
}
TEST(FredkinCellFixture, test_evolve2) {
  FredkinCell fc;
  fc.revive();
  AbstractCell *fc1 = fc.evolve(0);
  ostringstream w;
  fc.printID(w);
  ASSERT_EQ("-", w.str());
  ASSERT_EQ(nullptr, fc1);
  delete fc1;
}
TEST(FredkinCellFixture, test_evolve3) {
  FredkinCell fc;
  fc.revive();
  AbstractCell *fc1 = fc.evolve(2);
  ostringstream w;
  fc.printID(w);
  ASSERT_EQ("-", w.str());
  ASSERT_EQ(nullptr, fc1);
  delete fc1;
}

TEST(FredkinCellFixture, test_isAlive1) {
  FredkinCell fc;
  fc.revive();
  ASSERT_TRUE(fc.isAlive());
}
TEST(FredkinCellFixture, test_isAlive2) {
  FredkinCell fc;
  ASSERT_FALSE(fc.isAlive());
}
TEST(FredkinCellFixture, test_isAlive3) {
  FredkinCell fc;
  fc.revive();
  ASSERT_TRUE(fc.isAlive());
  fc.kill();
  ASSERT_FALSE(fc.isAlive());
}

TEST(FredkinCellFixture, test_getNeighborCoordinates1) {
  FredkinCell fc;
  vector<pair<int, int>> neighborCoordinates;
  int cellType = 0; // interior cell
  fc.getNeighborCoordinates(1, 1, 3, 3, neighborCoordinates, cellType);
  ASSERT_EQ(make_pair(0, 1), neighborCoordinates[0]);
  ASSERT_EQ(make_pair(1, 0), neighborCoordinates[1]);
  ASSERT_EQ(make_pair(1, 2), neighborCoordinates[2]);
  ASSERT_EQ(make_pair(2, 1), neighborCoordinates[3]);
}
TEST(FredkinCellFixture, test_getNeighborCoordinates2) {
  FredkinCell fc;
  vector<pair<int, int>> neighborCoordinates1;
  vector<pair<int, int>> neighborCoordinates2;
  vector<pair<int, int>> neighborCoordinates3;
  vector<pair<int, int>> neighborCoordinates4;
  int cellType = 1; // edge cell
  // top edge cell
  fc.getNeighborCoordinates(0, 1, 3, 3, neighborCoordinates1, cellType);
  ASSERT_EQ(make_pair(0, 0), neighborCoordinates1[0]);
  ASSERT_EQ(make_pair(0, 2), neighborCoordinates1[1]);
  ASSERT_EQ(make_pair(1, 1), neighborCoordinates1[2]);
  // left edge cell
  fc.getNeighborCoordinates(1, 0, 3, 3, neighborCoordinates2, cellType);
  ASSERT_EQ(make_pair(0, 0), neighborCoordinates2[0]);
  ASSERT_EQ(make_pair(1, 1), neighborCoordinates2[1]);
  ASSERT_EQ(make_pair(2, 0), neighborCoordinates2[2]);
  // right edge cell
  fc.getNeighborCoordinates(1, 2, 3, 3, neighborCoordinates3, cellType);
  ASSERT_EQ(make_pair(0, 2), neighborCoordinates3[0]);
  ASSERT_EQ(make_pair(1, 1), neighborCoordinates3[1]);
  ASSERT_EQ(make_pair(2, 2), neighborCoordinates3[2]);
  // bottom edge cell
  fc.getNeighborCoordinates(2, 1, 3, 3, neighborCoordinates4, cellType);
  ASSERT_EQ(make_pair(1, 1), neighborCoordinates4[0]);
  ASSERT_EQ(make_pair(2, 0), neighborCoordinates4[1]);
  ASSERT_EQ(make_pair(2, 2), neighborCoordinates4[2]);
}
TEST(FredkinCellFixture, test_getNeighborCoordinates3) {
  FredkinCell fc;
  vector<pair<int, int>> neighborCoordinates1;
  vector<pair<int, int>> neighborCoordinates2;
  vector<pair<int, int>> neighborCoordinates3;
  vector<pair<int, int>> neighborCoordinates4;
  int cellType = 2; // corner cell
  // top left
  fc.getNeighborCoordinates(0, 0, 3, 3, neighborCoordinates1, cellType);
  ASSERT_EQ(make_pair(0, 1), neighborCoordinates1[0]);
  ASSERT_EQ(make_pair(1, 0), neighborCoordinates1[1]);
  // top right
  fc.getNeighborCoordinates(0, 2, 3, 3, neighborCoordinates2, cellType);
  ASSERT_EQ(make_pair(0, 1), neighborCoordinates2[0]);
  ASSERT_EQ(make_pair(1, 2), neighborCoordinates2[1]);
  // bottom left
  fc.getNeighborCoordinates(2, 0, 3, 3, neighborCoordinates3, cellType);
  ASSERT_EQ(make_pair(1, 0), neighborCoordinates3[0]);
  ASSERT_EQ(make_pair(2, 1), neighborCoordinates3[1]);
  // bottom right
  fc.getNeighborCoordinates(2, 2, 3, 3, neighborCoordinates4, cellType);
  ASSERT_EQ(make_pair(1, 2), neighborCoordinates4[0]);
  ASSERT_EQ(make_pair(2, 1), neighborCoordinates4[1]);
}

// ----------------
// Cell Tests
// ----------------

TEST(CellFixture, test_constructor1) {
  Cell c;
  ASSERT_EQ(nullptr, c._p);
}
TEST(CellFixture, test_constructor2) {
  Cell c;
  ASSERT_EQ(nullptr, c._p);
}
TEST(CellFixture, test_constructor3) {
  Cell c;
  ASSERT_EQ(nullptr, c._p);
}

TEST(CellFixture, test_copy_constructor1) {
  Cell c = new ConwayCell();
  ASSERT_NE(nullptr, c._p);
}
TEST(CellFixture, test_copy_constructor2) {
  Cell c = new FredkinCell();
  ASSERT_NE(nullptr, c._p);
}
TEST(CellFixture, test_copy_constructor3) {
  Cell c = new ConwayCell();
  Cell c1 = new FredkinCell();
  ASSERT_NE(c1._p, c._p);
}

TEST(CellFixture, test_copy_assignment1) {
  Cell c = new ConwayCell();
  Cell c1;
  c1 = c;
  ASSERT_NE(nullptr, c1._p);
}
TEST(CellFixture, test_copy_assignment2) {
  Cell c = new ConwayCell();
  Cell c1 = new FredkinCell();
  c1 = c;
  ASSERT_NE(nullptr, c1._p);
}
TEST(CellFixture, test_copy_assignment3) {
  Cell c = new ConwayCell();
  Cell c1 = new FredkinCell();
  ASSERT_NE(c._p, c1._p);
  c = c1;
}

TEST(CellFixture, test_revive1) {
  Cell c = new ConwayCell();
  ASSERT_EQ('.', c._p->_id);
  c.revive();
  ASSERT_EQ('*', c._p->_id);
}
TEST(CellFixture, test_revive2) {
  Cell c = new FredkinCell();
  ASSERT_EQ('-', c._p->_id);
  c.revive();
  ASSERT_EQ('0', c._p->_id);
}
TEST(CellFixture, test_revive3) {
  Cell c = new ConwayCell();
  ASSERT_EQ('.', c._p->_id);
  c.revive();
  ASSERT_EQ('*', c._p->_id);
  c.revive();
  ASSERT_EQ('*', c._p->_id);
}

TEST(CellFixture, test_printID1) {
  Cell c = new ConwayCell();
  ostringstream w;
  c.printID(w);
  ASSERT_EQ(".", w.str());
}
TEST(CellFixture, test_printID2) {
  Cell c = new FredkinCell();
  ostringstream w;
  c.printID(w);
  ASSERT_EQ("-", w.str());
}
TEST(CellFixture, test_printID3) {
  Cell c = new ConwayCell();
  c.revive();
  ostringstream w;
  c.printID(w);
  ASSERT_EQ("*", w.str());
}

TEST(CellFixture, test_evolve1) {
  Cell c = new ConwayCell();
  c.evolve(3);
  ostringstream w;
  c.printID(w);
  ASSERT_EQ("*", w.str());
}
TEST(CellFixture, test_evolve2) {
  Cell c = new FredkinCell();
  c.revive();
  c.evolve(0);
  ostringstream w;
  c.printID(w);
  ASSERT_EQ("-", w.str());
}
TEST(CellFixture, test_evolve3) {
  Cell c = new FredkinCell();
  ostringstream w;
  c.printID(w);
  ASSERT_EQ("-", w.str());
  c.revive();
  ostringstream w1;
  c.printID(w1);
  ASSERT_EQ("0", w1.str());
  c.evolve(1);
  c.evolve(1);
  ostringstream w2;
  c.printID(w2);
  ASSERT_EQ("*", w2.str());
}

TEST(CellFixture, test_isAlive1) {
  Cell c = new ConwayCell();
  ASSERT_FALSE(c.isAlive());
}
TEST(CellFixture, test_isAlive2) {
  Cell c = new FredkinCell();
  ASSERT_FALSE(c.isAlive());
}
TEST(CellFixture, test_isAlive3) {
  Cell c = new ConwayCell();
  c.revive();
  ASSERT_TRUE(c.isAlive());
}

TEST(CellFixture, test_getNeighborCoordinates1) {
  Cell c = new ConwayCell();
  vector<pair<int, int>> neighborCoordinates;
  int cellType = 0; // interior cell
  c.getNeighborCoordinates(1, 1, 3, 3, neighborCoordinates, cellType);
  ASSERT_EQ(make_pair(0, 0), neighborCoordinates[0]);
  ASSERT_EQ(make_pair(0, 1), neighborCoordinates[1]);
  ASSERT_EQ(make_pair(0, 2), neighborCoordinates[2]);
  ASSERT_EQ(make_pair(1, 0), neighborCoordinates[3]);
  ASSERT_EQ(make_pair(1, 2), neighborCoordinates[4]);
  ASSERT_EQ(make_pair(2, 0), neighborCoordinates[5]);
  ASSERT_EQ(make_pair(2, 1), neighborCoordinates[6]);
  ASSERT_EQ(make_pair(2, 2), neighborCoordinates[7]);
}
TEST(CellFixture, test_getNeighborCoordinates2) {
  Cell c = new ConwayCell();
  vector<pair<int, int>> neighborCoordinates1;
  vector<pair<int, int>> neighborCoordinates2;
  vector<pair<int, int>> neighborCoordinates3;
  vector<pair<int, int>> neighborCoordinates4;
  int cellType = 1; // edge cell
  // top edge cell
  c.getNeighborCoordinates(0, 1, 3, 3, neighborCoordinates1, cellType);
  ASSERT_EQ(make_pair(0, 0), neighborCoordinates1[0]);
  ASSERT_EQ(make_pair(0, 2), neighborCoordinates1[1]);
  ASSERT_EQ(make_pair(1, 0), neighborCoordinates1[2]);
  ASSERT_EQ(make_pair(1, 1), neighborCoordinates1[3]);
  ASSERT_EQ(make_pair(1, 2), neighborCoordinates1[4]);

  // left edge cell
  c.getNeighborCoordinates(1, 0, 3, 3, neighborCoordinates2, cellType);
  ASSERT_EQ(make_pair(0, 0), neighborCoordinates2[0]);
  ASSERT_EQ(make_pair(0, 1), neighborCoordinates2[1]);
  ASSERT_EQ(make_pair(1, 1), neighborCoordinates2[2]);
  ASSERT_EQ(make_pair(2, 0), neighborCoordinates2[3]);
  ASSERT_EQ(make_pair(2, 1), neighborCoordinates2[4]);
  // right edge cell
  c.getNeighborCoordinates(1, 2, 3, 3, neighborCoordinates3, cellType);
  ASSERT_EQ(make_pair(0, 1), neighborCoordinates3[0]);
  ASSERT_EQ(make_pair(0, 2), neighborCoordinates3[1]);
  ASSERT_EQ(make_pair(1, 1), neighborCoordinates3[2]);
  ASSERT_EQ(make_pair(2, 1), neighborCoordinates3[3]);
  ASSERT_EQ(make_pair(2, 2), neighborCoordinates3[4]);
  // bottom edge cell
  c.getNeighborCoordinates(2, 1, 3, 3, neighborCoordinates4, cellType);
  ASSERT_EQ(make_pair(1, 0), neighborCoordinates4[0]);
  ASSERT_EQ(make_pair(1, 1), neighborCoordinates4[1]);
  ASSERT_EQ(make_pair(1, 2), neighborCoordinates4[2]);
  ASSERT_EQ(make_pair(2, 0), neighborCoordinates4[3]);
  ASSERT_EQ(make_pair(2, 2), neighborCoordinates4[4]);
}
TEST(CellFixture, test_getNeighborCoordinates3) {
  Cell c = new ConwayCell();
  vector<pair<int, int>> neighborCoordinates1;
  vector<pair<int, int>> neighborCoordinates2;
  vector<pair<int, int>> neighborCoordinates3;
  vector<pair<int, int>> neighborCoordinates4;
  int cellType = 2; // corner cell
  // top left
  c.getNeighborCoordinates(0, 0, 3, 3, neighborCoordinates1, cellType);
  ASSERT_EQ(make_pair(0, 1), neighborCoordinates1[0]);
  ASSERT_EQ(make_pair(1, 0), neighborCoordinates1[1]);
  ASSERT_EQ(make_pair(1, 1), neighborCoordinates1[2]);
  // top right
  c.getNeighborCoordinates(0, 2, 3, 3, neighborCoordinates2, cellType);
  ASSERT_EQ(make_pair(0, 1), neighborCoordinates2[0]);
  ASSERT_EQ(make_pair(1, 1), neighborCoordinates2[1]);
  ASSERT_EQ(make_pair(1, 2), neighborCoordinates2[2]);
  // bottom left
  c.getNeighborCoordinates(2, 0, 3, 3, neighborCoordinates3, cellType);
  ASSERT_EQ(make_pair(1, 0), neighborCoordinates3[0]);
  ASSERT_EQ(make_pair(1, 1), neighborCoordinates3[1]);
  ASSERT_EQ(make_pair(2, 1), neighborCoordinates3[2]);
  // bottom right
  c.getNeighborCoordinates(2, 2, 3, 3, neighborCoordinates4, cellType);
  ASSERT_EQ(make_pair(1, 1), neighborCoordinates4[0]);
  ASSERT_EQ(make_pair(1, 2), neighborCoordinates4[1]);
  ASSERT_EQ(make_pair(2, 1), neighborCoordinates4[2]);
}
TEST(CellFixture, test_getNeighborCoordinates4) {
  Cell c = new FredkinCell();
  vector<pair<int, int>> neighborCoordinates;
  int cellType = 0; // interior cell
  c.getNeighborCoordinates(1, 1, 3, 3, neighborCoordinates, cellType);
  ASSERT_EQ(make_pair(0, 1), neighborCoordinates[0]);
  ASSERT_EQ(make_pair(1, 0), neighborCoordinates[1]);
  ASSERT_EQ(make_pair(1, 2), neighborCoordinates[2]);
  ASSERT_EQ(make_pair(2, 1), neighborCoordinates[3]);
}
TEST(CellFixture, test_getNeighborCoordinates5) {
  Cell c = new FredkinCell();
  vector<pair<int, int>> neighborCoordinates1;
  vector<pair<int, int>> neighborCoordinates2;
  vector<pair<int, int>> neighborCoordinates3;
  vector<pair<int, int>> neighborCoordinates4;
  int cellType = 1; // edge cell
  // top edge cell
  c.getNeighborCoordinates(0, 1, 3, 3, neighborCoordinates1, cellType);
  ASSERT_EQ(make_pair(0, 0), neighborCoordinates1[0]);
  ASSERT_EQ(make_pair(0, 2), neighborCoordinates1[1]);
  ASSERT_EQ(make_pair(1, 1), neighborCoordinates1[2]);
  // left edge cell
  c.getNeighborCoordinates(1, 0, 3, 3, neighborCoordinates2, cellType);
  ASSERT_EQ(make_pair(0, 0), neighborCoordinates2[0]);
  ASSERT_EQ(make_pair(1, 1), neighborCoordinates2[1]);
  ASSERT_EQ(make_pair(2, 0), neighborCoordinates2[2]);
  // right edge cell
  c.getNeighborCoordinates(1, 2, 3, 3, neighborCoordinates3, cellType);
  ASSERT_EQ(make_pair(0, 2), neighborCoordinates3[0]);
  ASSERT_EQ(make_pair(1, 1), neighborCoordinates3[1]);
  ASSERT_EQ(make_pair(2, 2), neighborCoordinates3[2]);
  // bottom edge cell
  c.getNeighborCoordinates(2, 1, 3, 3, neighborCoordinates4, cellType);
  ASSERT_EQ(make_pair(1, 1), neighborCoordinates4[0]);
  ASSERT_EQ(make_pair(2, 0), neighborCoordinates4[1]);
  ASSERT_EQ(make_pair(2, 2), neighborCoordinates4[2]);
}
TEST(CellFixture, test_getNeighborCoordinates6) {
  Cell c = new FredkinCell();
  vector<pair<int, int>> neighborCoordinates1;
  vector<pair<int, int>> neighborCoordinates2;
  vector<pair<int, int>> neighborCoordinates3;
  vector<pair<int, int>> neighborCoordinates4;
  int cellType = 2; // corner cell
  // top left
  c.getNeighborCoordinates(0, 0, 3, 3, neighborCoordinates1, cellType);
  ASSERT_EQ(make_pair(0, 1), neighborCoordinates1[0]);
  ASSERT_EQ(make_pair(1, 0), neighborCoordinates1[1]);
  // top right
  c.getNeighborCoordinates(0, 2, 3, 3, neighborCoordinates2, cellType);
  ASSERT_EQ(make_pair(0, 1), neighborCoordinates2[0]);
  ASSERT_EQ(make_pair(1, 2), neighborCoordinates2[1]);
  // bottom left
  c.getNeighborCoordinates(2, 0, 3, 3, neighborCoordinates3, cellType);
  ASSERT_EQ(make_pair(1, 0), neighborCoordinates3[0]);
  ASSERT_EQ(make_pair(2, 1), neighborCoordinates3[1]);
  // bottom right
  c.getNeighborCoordinates(2, 2, 3, 3, neighborCoordinates4, cellType);
  ASSERT_EQ(make_pair(1, 2), neighborCoordinates4[0]);
  ASSERT_EQ(make_pair(2, 1), neighborCoordinates4[1]);
}

// ----------------
// Life Tests
// ----------------

TEST(LifeFixture, test_constructor1) {
  Life<ConwayCell> l(3, 3);
  ASSERT_EQ(3, l._row);
  ASSERT_EQ(3, l._column);
  ASSERT_EQ(0, l._generation);
  ASSERT_EQ(0, l._population);
  ASSERT_EQ(9, l._board.size());
  ASSERT_EQ(9, l._neighborBoard.size());
}
TEST(LifeFixture, test_constructor2) {
  Life<FredkinCell> l(19, 7);
  ASSERT_EQ(19, l._row);
  ASSERT_EQ(7, l._column);
  ASSERT_EQ(0, l._generation);
  ASSERT_EQ(0, l._population);
  ASSERT_EQ(133, l._board.size());
  ASSERT_EQ(133, l._neighborBoard.size());
}
TEST(LifeFixture, test_constructor3) {
  Life<Cell> l(1, 80);
  ASSERT_EQ(1, l._row);
  ASSERT_EQ(80, l._column);
  ASSERT_EQ(0, l._generation);
  ASSERT_EQ(0, l._population);
  ASSERT_EQ(80, l._board.size());
  ASSERT_EQ(80, l._neighborBoard.size());
}

TEST(LifeFixture, test_addAliveCell1) {
  Life<ConwayCell> l(3, 3);
  l.addAliveCell(1, 1);
  ASSERT_EQ('*', l._board[1 * 3 + 1]._id);
}
TEST(LifeFixture, test_addAliveCell2) {
  Life<FredkinCell> l(3, 3);
  l.addAliveCell(1, 1);
  ASSERT_EQ('0', l._board[1 * 3 + 1]._id);
}
TEST(LifeFixture, test_addAliveCell3) {
  Life<ConwayCell> l(3, 3);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      l.addAliveCell(i, j);
    }
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      ASSERT_EQ('*', l._board[i * 3 + j]._id);
    }
  }
}

TEST(LifeFixture, test_Cell_addDeadCell1) {
  Life<Cell> l(3, 3);
  Cell c = new ConwayCell();
  l.addDeadCell(c, 1, 1);
  ASSERT_EQ('.', l._board[1 * 3 + 1]._p->_id);
}
TEST(LifeFixture, test_Cell_addDeadCell2) {
  Life<Cell> l(3, 3);
  Cell c = new FredkinCell();
  l.addDeadCell(c, 1, 1);
  ASSERT_EQ('-', l._board[1 * 3 + 1]._p->_id);
}
TEST(LifeFixture, test_Cell_addDeadCell3) {
  Life<Cell> l(3, 3);
  Cell c = new ConwayCell();
  Cell c1 = new FredkinCell();
  l.addDeadCell(c, 1, 1);
  l.addDeadCell(c1, 0, 0);
  ASSERT_EQ('.', l._board[1 * 3 + 1]._p->_id);
  ASSERT_EQ('-', l._board[0 * 3 + 0]._p->_id);
}

TEST(LifeFixture, test_Cell_addAliveCell1) {
  Life<Cell> l(3, 3);
  Cell c = new ConwayCell();
  l.addAliveCell(c, 1, 1);
  ASSERT_EQ('*', l._board[1 * 3 + 1]._p->_id);
}
TEST(LifeFixture, test_Cell_addAliveCell2) {
  Life<Cell> l(3, 3);
  Cell c = new FredkinCell();
  l.addAliveCell(c, 1, 1);
  ASSERT_EQ('0', l._board[1 * 3 + 1]._p->_id);
}
TEST(LifeFixture, test_Cell_addAliveCell3) {
  Life<Cell> l(3, 3);
  Cell c = new ConwayCell();
  Cell c1 = new FredkinCell();
  l.addAliveCell(c, 1, 1);
  l.addAliveCell(c1, 0, 0);
  ASSERT_EQ('*', l._board[1 * 3 + 1]._p->_id);
  ASSERT_EQ('0', l._board[0 * 3 + 0]._p->_id);
}

TEST(LifeFixture, test_printBoard1) {
  Life<ConwayCell> l(3, 3);
  ostringstream w;
  l.printBoard(w);
  ASSERT_EQ("\nGeneration = 0, Population = 0.\n...\n...\n...\n\n", w.str());
}
TEST(LifeFixture, test_printBoard2) {
  Life<FredkinCell> l(3, 3);
  ostringstream w;
  l.printBoard(w);
  ASSERT_EQ("\nGeneration = 0, Population = 0.\n---\n---\n---\n\n", w.str());
}
TEST(LifeFixture, test_printBoard3) {
  Life<ConwayCell> l(3, 3);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      l.addAliveCell(i, j);
    }
  }
  ostringstream w;
  l.printBoard(w);
  ASSERT_EQ("\nGeneration = 0, Population = 9.\n***\n***\n***\n\n", w.str());
}

TEST(LifeFixture, test_runTurn1) {
  Life<ConwayCell> l(3, 3);
  l.addAliveCell(1, 1);
  ostringstream w;
  l.printBoard(w);
  ASSERT_EQ("\nGeneration = 0, Population = 1.\n...\n.*.\n...\n\n", w.str());
  l.runTurn();
  ostringstream w1;
  l.printBoard(w1);
  ASSERT_EQ("\nGeneration = 1, Population = 0.\n...\n...\n...\n\n", w1.str());
}
TEST(LifeFixture, test_runTurn2) {
  Life<ConwayCell> l(3, 3);
  l.addAliveCell(0, 1);
  l.addAliveCell(1, 0);
  l.addAliveCell(1, 1);
  l.addAliveCell(1, 2);
  l.addAliveCell(2, 1);
  ostringstream w;
  l.printBoard(w);
  ASSERT_EQ("\nGeneration = 0, Population = 5.\n.*.\n***\n.*.\n\n", w.str());
  l.runTurn();
  ostringstream w1;
  l.printBoard(w1);
  ASSERT_EQ("\nGeneration = 1, Population = 8.\n***\n*.*\n***\n\n", w1.str());
}
TEST(LifeFixture, test_runTurn3) {
  Life<FredkinCell> l(3, 3);
  l.addAliveCell(0, 0);
  ostringstream w;
  l.printBoard(w);
  ASSERT_EQ("\nGeneration = 0, Population = 1.\n0--\n---\n---\n\n", w.str());
  l.runTurn();
  ostringstream w1;
  l.printBoard(w1);
  ASSERT_EQ("\nGeneration = 1, Population = 2.\n-0-\n0--\n---\n\n", w1.str());
}

TEST(LifeFixture, test_runGeneration1) {
  Life<ConwayCell> l(3, 3);
  l.addAliveCell(1, 1);
  ostringstream w;
  l.printBoard(w);
  ASSERT_EQ("\nGeneration = 0, Population = 1.\n...\n.*.\n...\n\n", w.str());
  l.runTurn();
  ostringstream w1;
  l.printBoard(w1);
  ASSERT_EQ("\nGeneration = 1, Population = 0.\n...\n...\n...\n\n", w1.str());
}
TEST(LifeFixture, test_runGeneration2) {
  Life<ConwayCell> l(3, 3);
  l.addAliveCell(0, 1);
  l.addAliveCell(1, 0);
  l.addAliveCell(1, 1);
  l.addAliveCell(1, 2);
  l.addAliveCell(2, 1);
  ostringstream w;
  l.printBoard(w);
  ASSERT_EQ("\nGeneration = 0, Population = 5.\n.*.\n***\n.*.\n\n", w.str());
  l.runTurn();
  ostringstream w1;
  l.printBoard(w1);
  ASSERT_EQ("\nGeneration = 1, Population = 8.\n***\n*.*\n***\n\n", w1.str());
}
TEST(LifeFixture, test_runGeneration3) {
  Life<FredkinCell> l(3, 3);
  l.addAliveCell(0, 0);
  ostringstream w;
  l.printBoard(w);
  ASSERT_EQ("\nGeneration = 0, Population = 1.\n0--\n---\n---\n\n", w.str());
  l.runTurn();
  ostringstream w1;
  l.printBoard(w1);
  ASSERT_EQ("\nGeneration = 1, Population = 2.\n-0-\n0--\n---\n\n", w1.str());
}

TEST(LifeFixture, test_getCellType1) {
  Life<ConwayCell> l(3, 3);
  int cellType = l.getCellType(0, 0);
  ASSERT_EQ(2, cellType); // corner cell
}
TEST(LifeFixture, test_getCellType2) {
  Life<FredkinCell> l(3, 3);
  int cellType = l.getCellType(0, 1);
  ASSERT_EQ(1, cellType); // edge cell
}
TEST(LifeFixture, test_getCellType3) {
  Life<ConwayCell> l(3, 3);
  int cellType = l.getCellType(1, 1);
  ASSERT_EQ(0, cellType); // interior cell
}

TEST(LifeFixture, test_getNeighborCount1) {
  Life<ConwayCell> l(3, 3);
  pair<int, int> p1 = make_pair(0, 1);
  pair<int, int> p2 = make_pair(1, 0);
  pair<int, int> p3 = make_pair(1, 1);
  vector<pair<int, int>> neighborCoordinates;
  neighborCoordinates.push_back(p1);
  neighborCoordinates.push_back(p2);
  neighborCoordinates.push_back(p3);
  l.addAliveCell(0, 0);
  l.addAliveCell(0, 1);
  l.addAliveCell(1, 0);
  l.addAliveCell(1, 1);
  int neighborCount = l.getNeighborCount(neighborCoordinates, 2);
  ASSERT_EQ(3, neighborCount);
}
TEST(LifeFixture, test_getNeighborCount2) {
  Life<FredkinCell> l(3, 3);
  pair<int, int> p1 = make_pair(0, 1);
  pair<int, int> p2 = make_pair(1, 0);
  vector<pair<int, int>> neighborCoordinates;
  neighborCoordinates.push_back(p1);
  neighborCoordinates.push_back(p2);
  l.addAliveCell(0, 0);
  l.addAliveCell(0, 1);
  l.addAliveCell(1, 0);
  int neighborCount = l.getNeighborCount(neighborCoordinates, 2);
  ASSERT_EQ(2, neighborCount);
}
TEST(LifeFixture, test_getNeighborCount3) {
  Life<Cell> l(3, 3);
  pair<int, int> p1 = make_pair(0, 1);
  pair<int, int> p2 = make_pair(1, 0);
  vector<pair<int, int>> neighborCoordinates;
  neighborCoordinates.push_back(p1);
  neighborCoordinates.push_back(p2);
  Cell c = new FredkinCell();
  Cell c1 = new ConwayCell();
  l.addAliveCell(c, 0, 0);
  l.addAliveCell(c1, 0, 1);
  int neighborCount = l.getNeighborCount(neighborCoordinates, 2);
  ASSERT_EQ(1, neighborCount);
}
