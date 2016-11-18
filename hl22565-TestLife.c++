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
ConwayCell c = ConwayCell(0);

TEST(LifeFixture, test) { ASSERT_TRUE(c.getType() == 'c'); }

TEST(LifeFixture, test2) { ASSERT_TRUE(c.getType() != 'f'); }

TEST(LifeFixture, test3) { ASSERT_TRUE(c.getType() != 'a'); }

TEST(LifeFixture, test4) { ASSERT_TRUE(c.getState() == '*'); }

TEST(LifeFixture, test5) { ASSERT_TRUE(c.getState() != '.'); }

ConwayCell c2 = ConwayCell(-1);

TEST(LifeFixture, test6) { ASSERT_TRUE(c2.getState() == '.'); }

ConwayCell c3 = ConwayCell(0);

TEST(LifeFixture, test7) {
  c3.ageCell(3);
  ASSERT_TRUE(c3.getState() == '*');
}

ConwayCell c4 = ConwayCell(0);

TEST(LifeFixture, test8) {
  c4.ageCell(1);
  ASSERT_TRUE(c4.getState() == '.');
}

TEST(LifeFixture, test9) { ASSERT_TRUE(c4.getState() != '*'); }

TEST(LifeFixture, test10) { ASSERT_TRUE(c4.getState() != '0'); }

FredkinsCell f = FredkinsCell(0);

TEST(LifeFixture, test11) { ASSERT_TRUE(f.getType() == 'f'); }

TEST(LifeFixture, test12) { ASSERT_TRUE(f.getType() != 'c'); }

TEST(LifeFixture, test13) { ASSERT_TRUE(f.getType() != 'a'); }

TEST(LifeFixture, test14) { ASSERT_TRUE(f.getState() == '0'); }

TEST(LifeFixture, test15) { ASSERT_TRUE(f.getState() != '-'); }

FredkinsCell f2 = FredkinsCell(-1);

TEST(LifeFixture, test16) { ASSERT_TRUE(f2.getState() == '-'); }

FredkinsCell f3 = FredkinsCell(0);

TEST(LifeFixture, test17) {
  f3.ageCell(3);
  ASSERT_TRUE(f3.getState() == '1');
}

FredkinsCell f4 = FredkinsCell(0);

TEST(LifeFixture, test18) {
  f4.ageCell(0);
  ASSERT_TRUE(f4.getState() == '-');
}

TEST(LifeFixture, test19) { ASSERT_TRUE(f4.getState() != '*'); }

TEST(LifeFixture, test20) {
  f4.ageCell(1);
  ASSERT_TRUE(f4.getState() == '0');
}

TEST(LifeFixture, test21) {
  f4.ageCell(3);
  f4.ageCell(5);
  ASSERT_TRUE(f4.isAge2());
}

TEST(LifeFixture, test22) {
  f4.ageCell(3);
  ASSERT_TRUE(!f4.isAge2());
}

TEST(LifeFixture, test23) {
  f4.ageCell(0);
  ASSERT_TRUE(!f4.isAge2());
}

Cell C1 = Cell('f', 0);
TEST(LifeFixture, test24) { ASSERT_TRUE(C1.getState() == '0'); }

TEST(LifeFixture, test25) { ASSERT_TRUE(C1.getState() != '-'); }

TEST(LifeFixture, test26) { ASSERT_TRUE(C1.getState() != '1'); }

TEST(LifeFixture, test27) { ASSERT_TRUE(C1.getType() == 'f'); }

TEST(LifeFixture, test28) { ASSERT_TRUE(C1.getType() != 'c'); }

Cell C2 = Cell('c', -1);

TEST(LifeFixture, test29) { ASSERT_TRUE(C2.getState() == '.'); }

TEST(LifeFixture, test30) { ASSERT_TRUE(C2.getType() == 'c'); }
