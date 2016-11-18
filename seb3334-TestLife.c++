// --------------------------
// projects/life/TestLife.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#define TEST_FRIENDS                                                           \
  FRIEND_TEST(LifeFixture, Life_Test_1);                                       \
  FRIEND_TEST(LifeFixture, Life_Test_2);                                       \
  FRIEND_TEST(LifeFixture, Life_Test_3);                                       \
  FRIEND_TEST(LifeFixture, Life_Test_4);                                       \
  FRIEND_TEST(LifeFixture, Life_Test_5);                                       \
  FRIEND_TEST(LifeFixture, Life_Test_6);                                       \
  FRIEND_TEST(LifeFixture, Life_Test_7);                                       \
  FRIEND_TEST(LifeFixture, Life_Test_8);                                       \
  FRIEND_TEST(LifeFixture, Life_Test_9);

#include <iostream>
#include <sstream>

#include "gtest/gtest.h"

#include "Life.h"

using namespace std;

// ----
// test
// ----

// -----------
// Conway Cell
// -----------

TEST(ConwayFixture, tInit1) {
  ConwayCell c('.');
  ASSERT_TRUE(!c.living());
}

TEST(ConwayFixture, tInit2) {
  ConwayCell c('*');
  ASSERT_TRUE(c.living());
}

TEST(ConwayFixture, tInit3) {
  ConwayCell c('.');
  ConwayCell *cc(dynamic_cast<ConwayCell *>(c.clone()));
  delete cc;
  ASSERT_TRUE(!cc->living());
}

TEST(ConwayFixture, tInit4) {
  ConwayCell c('*');
  ConwayCell *cc(dynamic_cast<ConwayCell *>(c.clone()));
  delete cc;
  ASSERT_TRUE(cc->living());
}

TEST(ConwayFixture, tInit5) {
  ConwayCell c('*');
  ConwayCell *cc(dynamic_cast<ConwayCell *>(c.clone()));
  delete cc;
  ASSERT_TRUE(cc->living());
}

TEST(ConwayFixture, tUpdates1) {
  ConwayCell c('*');
  c.update_neighbors(3, 3);
  c.update_liveness();
  ASSERT_TRUE(!c.living());
}

TEST(ConwayFixture, tUpdates2) {
  ConwayCell c('.');
  c.update_neighbors(3, 0);
  c.update_liveness();
  ASSERT_TRUE(c.living());
}

TEST(ConwayFixture, tUpdates3) {
  ConwayCell c('.');
  c.update_neighbors(3, 3);
  c.update_liveness();
  ASSERT_TRUE(!c.living());
}

TEST(ConwayFixture, tUpdates4) {
  ConwayCell c('*');
  c.update_neighbors(3, 0);
  c.update_liveness();
  ASSERT_TRUE(c.living());
}

TEST(ConwayFixture, tUpdates5) {
  ConwayCell c('*');
  c.update_neighbors(4, 3);
  c.update_liveness();
  ASSERT_TRUE(!c.living());
}

TEST(ConwayFixture, tUpdates6) {
  ConwayCell c('.');
  c.update_neighbors(2, 1);
  c.update_liveness();
  ASSERT_TRUE(c.living());
}

// -----------
// Fredkin Cell
// -----------

TEST(FredkinFixture, tInit1) {
  FredkinCell c('-');
  ASSERT_TRUE(!c.living());
}

TEST(FredkinFixture, tInit2) {
  FredkinCell c('0');
  ASSERT_TRUE(c.living());
}

TEST(FredkinFixture, tInit3) {
  FredkinCell c('-');
  FredkinCell *cc(dynamic_cast<FredkinCell *>(c.clone()));
  delete cc;
  ASSERT_TRUE(!cc->living());
}

TEST(FredkinFixture, tInit4) {
  FredkinCell c('0');
  FredkinCell *cc(dynamic_cast<FredkinCell *>(c.clone()));
  delete cc;
  ASSERT_TRUE(cc->living());
}

TEST(FredkinFixture, tInit5) {
  FredkinCell c('0');
  FredkinCell *cc(dynamic_cast<FredkinCell *>(c.clone()));
  delete cc;
  ASSERT_TRUE(cc->living());
}

TEST(FredkinFixture, tUpdates1) {
  FredkinCell c('0');
  c.update_neighbors(3, 3);
  c.update_liveness();
  ASSERT_TRUE(c.living());
}

TEST(FredkinFixture, tUpdates2) {
  FredkinCell c('-');
  c.update_neighbors(3, 0);
  c.update_liveness();
  ASSERT_TRUE(c.living());
}

TEST(FredkinFixture, tUpdates3) {
  FredkinCell c('-');
  c.update_neighbors(3, 3);
  c.update_liveness();
  ASSERT_TRUE(c.living());
}

TEST(FredkinFixture, tUpdates4) {
  FredkinCell c('0');
  c.update_neighbors(3, 0);
  c.update_liveness();
  ASSERT_TRUE(c.living());
}

TEST(FredkinFixture, tUpdates5) {
  FredkinCell c('0');
  c.update_neighbors(4, 3);
  c.update_liveness();
  ASSERT_TRUE(!c.living());
}

TEST(FredkinFixture, tUpdates6) {
  FredkinCell c('-');
  c.update_neighbors(2, 1);
  c.update_liveness();
  ASSERT_TRUE(!c.living());
}

TEST(FredkinFixture, tUpdates7) {
  ostringstream out;
  std::streambuf *coutbuf = std::cout.rdbuf(); // save old buf
  std::cout.rdbuf(out.rdbuf()); // redirect std::cout to the stringstream
  FredkinCell c('-');
  c.update_neighbors(3, 1);
  c.update_liveness();
  c.print();
  std::cout.rdbuf(coutbuf); // reset to standard output again
  ASSERT_EQ("0", out.str());
}

TEST(FredkinFixture, tUpdates8) {
  ostringstream out;
  std::streambuf *coutbuf = std::cout.rdbuf(); // save old buf
  std::cout.rdbuf(out.rdbuf()); // redirect std::cout to the stringstream
  FredkinCell c('0');
  c.update_neighbors(3, 1);
  c.update_liveness();
  c.print();
  std::cout.rdbuf(coutbuf); // reset to standard output again
  ASSERT_EQ("1", out.str());
}

TEST(FredkinFixture, tUpdates9) {
  ostringstream out;
  std::streambuf *coutbuf = std::cout.rdbuf(); // save old buf
  std::cout.rdbuf(out.rdbuf()); // redirect std::cout to the stringstream
  FredkinCell c('0');
  c.update_neighbors(3, 0);
  c.update_liveness();
  c.print();
  std::cout.rdbuf(coutbuf); // reset to standard output again
  ASSERT_EQ("1", out.str());
}

TEST(FredkinFixture, tUpdates10) {
  ostringstream out;
  std::streambuf *coutbuf = std::cout.rdbuf(); // save old buf
  std::cout.rdbuf(out.rdbuf()); // redirect std::cout to the stringstream
  FredkinCell c('0');

  c.update_neighbors(3, 0);
  c.update_liveness();
  c.update_neighbors(2, 0);
  c.update_liveness();
  c.update_neighbors(3, 0);
  c.update_liveness();
  c.update_liveness();

  c.print();
  std::cout.rdbuf(coutbuf); // reset to standard output again
  ASSERT_EQ("2", out.str());
}

TEST(FredkinFixture, tUpdates11) {
  ostringstream out;
  std::streambuf *coutbuf = std::cout.rdbuf(); // save old buf
  std::cout.rdbuf(out.rdbuf()); // redirect std::cout to the stringstream
  FredkinCell c('9');

  c.update_neighbors(3, 0);
  c.update_liveness();
  c.update_neighbors(2, 0);
  c.update_liveness();
  c.update_neighbors(3, 0);
  c.update_liveness();
  c.update_liveness();

  c.print();
  std::cout.rdbuf(coutbuf); // reset to standard output again
  ASSERT_EQ("+", out.str());
}

// ----------
// Cell Tests
// ----------

TEST(CellFixture, tInit1) {
  Cell c('.');
  ASSERT_TRUE(!c.living());
}

TEST(CellFixture, tInit2) {
  Cell c('-');
  ASSERT_TRUE(!c.living());
}

TEST(CellFixture, tInit3) {
  Cell c('*');
  ASSERT_TRUE(c.living());
}

TEST(CellFixture, tInit4) {
  Cell c('0');
  ASSERT_TRUE(c.living());
}

TEST(CellFixture, tInit5) {
  Cell c('+');
  ASSERT_TRUE(c.living());
}

TEST(CellFixture, tUpdates1) {
  ostringstream out;
  std::streambuf *coutbuf = std::cout.rdbuf(); // save old buf
  std::cout.rdbuf(out.rdbuf()); // redirect std::cout to the stringstream

  Cell c('0');
  c.update_neighbors(3, 0);
  c.update_liveness();

  c.print();
  std::cout.rdbuf(coutbuf); // reset to standard output again

  ASSERT_EQ("1", out.str());
}

TEST(CellFixture, tMutate1) {
  ostringstream out;
  std::streambuf *coutbuf = std::cout.rdbuf(); // save old buf
  std::cout.rdbuf(out.rdbuf()); // redirect std::cout to the stringstream

  Cell c('1');
  c.update_neighbors(3, 0);
  c.update_liveness();

  c.print();
  std::cout.rdbuf(coutbuf); // reset to standard output again

  ASSERT_EQ("*", out.str());
}

TEST(CellFixture, tMutate2) {
  ostringstream out;
  std::streambuf *coutbuf = std::cout.rdbuf(); // save old buf
  std::cout.rdbuf(out.rdbuf()); // redirect std::cout to the stringstream

  Cell c('3');
  c.update_neighbors(3, 0);
  c.update_liveness();

  c.print();
  std::cout.rdbuf(coutbuf); // reset to standard output again

  ASSERT_EQ("4", out.str());
}

TEST(CellFixture, tMutate3) {
  ostringstream out;
  std::streambuf *coutbuf = std::cout.rdbuf(); // save old buf
  std::cout.rdbuf(out.rdbuf()); // redirect std::cout to the stringstream

  Cell c('0');
  c.update_neighbors(3, 1);
  c.update_liveness();
  c.update_liveness();
  c.print();
  std::cout.rdbuf(coutbuf); // reset to standard output again

  ASSERT_EQ("*", out.str());
}

TEST(CellFixture, tMutate4) {
  ostringstream out;
  std::streambuf *coutbuf = std::cout.rdbuf(); // save old buf
  std::cout.rdbuf(out.rdbuf()); // redirect std::cout to the stringstream

  Cell c('0');
  c.update_neighbors(3, 0);
  c.update_liveness();
  c.update_neighbors(2, 0);
  c.update_liveness();
  c.update_neighbors(3, 0);
  c.update_liveness();
  c.update_liveness();

  c.print();
  std::cout.rdbuf(coutbuf); // reset to standard output again

  ASSERT_EQ("*", out.str());
}

// ----------
// Life Tests
// ----------

TEST(LifeFixture, Life_Test_1) {
  stringstream s("3 3 ...\n...\n...\n");

  Life<ConwayCell> life(s);

  ASSERT_EQ(life.population, 0);
  ASSERT_EQ(life.row, 3);
  ASSERT_EQ(life.col, 3);
}

TEST(LifeFixture, Life_Test_2) {
  stringstream s("5 5 .....\n.***.\n.*.*.\n.***.\n.....\n\n");

  Life<ConwayCell> life(s);

  ASSERT_EQ(life.population, 8);
  life.run_simulation(4, 0);
  ASSERT_EQ(life.population, 16);
  ASSERT_EQ(life.row, 5);
  ASSERT_EQ(life.col, 5);
}

TEST(LifeFixture, Life_Test_3) {
  stringstream s("3 3 ---\n-0-\n---\n\n");

  Life<FredkinCell> life(s);

  ASSERT_EQ(life.population, 1);
  ASSERT_EQ(life.row, 3);
  ASSERT_EQ(life.col, 3);
  ASSERT_EQ(life.board[0].living(), false);
  ASSERT_EQ(life.board[4].living(), true);
}

TEST(LifeFixture, Life_Test_4) {
  stringstream s("3 3 ---\n-1-\n---\n\n");

  Life<FredkinCell> life(s);

  ASSERT_EQ(life.board[4].living(), true);
  ASSERT_EQ(life.board[4].age, 1);
  life.run_simulation(1, 0);
  ASSERT_EQ(life.board[4].living(), false);
  ASSERT_EQ(life.board[4].age, 1);
  ASSERT_EQ(life.population, 4);
}

TEST(LifeFixture, Life_Test_5) {
  stringstream s("3 3 ...\n.1.\n...\n\n");
  try {
    Life<ConwayCell> life(s);
    ASSERT_EQ(true, false);
  } catch (std::invalid_argument &e) {
    ASSERT_EQ(true, true);
  }
}

TEST(LifeFixture, Life_Test_6) {
  stringstream s("3 3 ...\n.1.\n...\n\n");
  try {
    Life<FredkinCell> life(s);
    ASSERT_EQ(true, false);
  } catch (std::invalid_argument &e) {
    ASSERT_EQ(true, true);
  }
}

TEST(LifeFixture, Life_Test_7) {
  stringstream s("3 3 ...\n.1.\n...\n\n");
  try {
    Life<Cell> life(s);
    ASSERT_EQ(true, true);
  } catch (std::invalid_argument &e) {
    ASSERT_EQ(true, false);
  }
}

TEST(LifeFixture, Life_Test_8) {
  stringstream s("3 3 ...\n*1.\n...\n\n");
  Life<Cell> life(s);
  ASSERT_EQ(life.population, 2);
  life.run_simulation(1, 0);
  ASSERT_EQ(life.board[4].living(), true);
  ASSERT_EQ(life.population, 1);
}

TEST(LifeFixture, Life_Test_9) {
  ostringstream out;
  std::streambuf *coutbuf = std::cout.rdbuf(); // save old buf
  std::cout.rdbuf(out.rdbuf()); // redirect std::cout to the stringstream
  stringstream s("3 3 ---\n-1-\n---\n\n");
  Life<FredkinCell> life(s);
  life.print_board();
  ASSERT_EQ(out.str(), "Generation = 0, Population = 1.\n---\n-1-\n---\n\n");
  std::cout.rdbuf(coutbuf); // reset to standard output again
}

TEST(LifeFixture, Life_Test_10) {
  stringstream s("3 3 ...\n.1.\n...\n\n");
  Life<Cell> life(s);
  life.run_simulation(1, 0);
  ostringstream out;
  std::streambuf *coutbuf = std::cout.rdbuf(); // save old buf
  std::cout.rdbuf(out.rdbuf()); // redirect std::cout to the stringstream
  life.run_simulation(2, 1);
  ASSERT_EQ(out.str(), "Generation = 2, Population = 0.\n...\n.-.\n...\n\n");
  std::cout.rdbuf(coutbuf); // reset to standard output again
}

TEST(LifeFixture, Life_Test_11) {
  stringstream s("5 5 ***..\n*...*\n.***.\n..***\n.*.*.\n\n");
  Life<ConwayCell> life(s);
  life.run_simulation(10, 0);
  ostringstream out;
  std::streambuf *coutbuf = std::cout.rdbuf(); // save old buf
  std::cout.rdbuf(out.rdbuf()); // redirect std::cout to the stringstream
  life.run_simulation(11, 1);
  ASSERT_EQ(out.str(), "Generation = 11, Population = "
                       "8.\n**...\n**...\n.....\n...**\n...**\n\n");
  std::cout.rdbuf(coutbuf); // reset to standard output again
}
