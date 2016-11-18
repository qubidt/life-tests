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
#include "sstream"

#include "Life.h"

using namespace std;

// ----
// test
// ----

TEST(LifeFixture, CCEqualTest1) {
  ConwayCell x('.');
  ConwayCell y('.');
  ASSERT_TRUE(x == y);
}

TEST(LifeFixture, CCEqualTest2) {
  ConwayCell x('.');
  ConwayCell y('*');
  ASSERT_EQ(x == y, 0);
}

TEST(LifeFixture, CCEqualTest3) {
  ConwayCell x('.');
  ConwayCell y('.');
  ASSERT_EQ(x == y, 1);
}

TEST(LifeFixture, CCEqualTest4) {
  ConwayCell x('w');
  ConwayCell y('w');
  ASSERT_TRUE(x == y);
}

TEST(LifeFixture, CCEqualTest5) {
  ConwayCell x('q');
  ConwayCell y('q');
  ASSERT_TRUE(x == y);
}

TEST(LifeFixture, CCEqualTest6) {
  ConwayCell x(',');
  ConwayCell y(',');
  ASSERT_TRUE(x == y);
}

TEST(LifeFixture, CCReadTest1) {
  ConwayCell x('x');
  istringstream stream;
  stream.str(".");
  stream >> x;
  ConwayCell y('.');
  ASSERT_EQ(x == y, 1);
}

TEST(LifeFixture, CCReadTest2) {
  ConwayCell x('.');
  istringstream stream;
  stream.str("*");
  stream >> x;
  ConwayCell y('*');
  ASSERT_EQ(x == y, 1);
}

TEST(LifeFixture, CCReadTest3) {
  ConwayCell x('.');
  istringstream stream;
  stream.str("Jo");
  stream >> x;
  ConwayCell y('J');
  ASSERT_EQ(x == y, 1);
}

TEST(LifeFixture, CCWriteTest1) {
  ConwayCell x('.');
  ostringstream stream;
  stream << x;
  ASSERT_EQ(stream.str(), ".");
}

TEST(LifeFixture, CCWriteTest2) {
  ConwayCell x('*');
  ostringstream stream;
  stream << x;
  ASSERT_EQ(stream.str(), "*");
}

TEST(LifeFixture, CCWriteTest3) {
  ConwayCell x('!');
  ostringstream stream;
  stream << x;
  ASSERT_EQ(stream.str(), "!");
}

TEST(LifeFixture, CCcountNeighborsTest1) {
  istringstream stream;
  stream.str(".........");
  ConwayCell x('!');
  vector<vector<ConwayCell>> arr(3, vector<ConwayCell>(3, ConwayCell()));
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      stream >> x;
      arr[i][j] = x;
    }
  }
  int count = x.countNeighbors(arr);
  ASSERT_EQ(count, 0);
}

TEST(LifeFixture, CCcountNeighborsTest2) {
  istringstream stream;
  stream.str(".*.*....*");
  ConwayCell x('*');
  vector<vector<ConwayCell>> arr(3, vector<ConwayCell>(3, ConwayCell()));
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      stream >> x;
      arr[i][j] = x;
    }
  }
  int count = x.countNeighbors(arr);
  ASSERT_EQ(count, 3);
}

TEST(LifeFixture, CCcountNeighborsTest3) {
  istringstream stream;
  stream.str("********-");
  ConwayCell x('.');
  vector<vector<ConwayCell>> arr(3, vector<ConwayCell>(3, ConwayCell()));
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      stream >> x;
      arr[i][j] = x;
    }
  }
  int count = x.countNeighbors(arr);
  ASSERT_EQ(count, 7);
}

TEST(LifeFixture, CCevolveTest1) {
  ConwayCell x('.');
  x.evolve(1);
  ostringstream stream;
  stream << x;
  ASSERT_EQ(stream.str(), ".");
}

TEST(LifeFixture, CCevolveTest2) {
  ConwayCell x('.');
  x.evolve(3);
  ostringstream stream;
  stream << x;
  ASSERT_EQ(stream.str(), "*");
}

TEST(LifeFixture, CCevolveTest3) {
  ConwayCell x('*');
  x.evolve(2);
  ostringstream stream;
  stream << x;
  ASSERT_EQ(stream.str(), "*");
  stream.str("");
  stream.clear();
  x.evolve(4);
  stream << x;
  ASSERT_EQ(stream.str(), ".");
}

TEST(LifeFixture, CCcloneTest1) {
  ConwayCell x('*');
  AbstractCell *temp = x.clone();
  ostringstream stream;
  stream << *temp;
  ASSERT_EQ(stream.str(), "*");
}

TEST(LifeFixture, CCcloneTest2) {
  ConwayCell x('.');
  AbstractCell *temp = x.clone();
  ostringstream stream;
  stream << *temp;
  ASSERT_EQ(stream.str(), ".");
}

TEST(LifeFixture, CCcloneTest3) {
  ConwayCell x('*');
  AbstractCell *temp = x.clone();
  ostringstream stream;
  stream << *temp;
  ASSERT_TRUE(*temp == x);
}

// Test for Fredkin

TEST(LifeFixture, FCEqualTest1) {
  FredkinCell x('-');
  FredkinCell y('-');
  ASSERT_TRUE(x == y);
}

TEST(LifeFixture, FCEqualTest2) {
  ConwayCell x('.');
  ConwayCell y('0');
  ASSERT_EQ(x == y, 0);
}

TEST(LifeFixture, FCEqualTest3) {
  FredkinCell x('.');
  FredkinCell y('.');
  ASSERT_EQ(x == y, 1);
}

TEST(LifeFixture, FCReadTest1) {
  FredkinCell x('x');
  istringstream stream;
  stream.str("-");
  stream >> x;
  FredkinCell y('-');
  ASSERT_EQ(x == y, 1);
}

TEST(LifeFixture, FCReadTest2) {
  FredkinCell x('.');
  istringstream stream;
  stream.str("0");
  stream >> x;
  FredkinCell y('0');
  ASSERT_EQ(x == y, 1);
}

TEST(LifeFixture, FCReadTest3) {
  FredkinCell x('-');
  istringstream stream;
  stream.str("1o");
  stream >> x;
  FredkinCell y('1');
  ASSERT_EQ(x == y, 1);
}

TEST(LifeFixture, FCWriteTest1) {
  FredkinCell x('-');
  ostringstream stream;
  stream << x;
  ASSERT_EQ(stream.str(), "-");
}

TEST(LifeFixture, FCWriteTest2) {
  FredkinCell x('0');
  ostringstream stream;
  stream << x;
  ASSERT_EQ(stream.str(), "0");
}

TEST(LifeFixture, FCWriteTest3) {
  FredkinCell x('9');
  ostringstream stream;
  stream << x;
  ASSERT_EQ(stream.str(), "9");
}

TEST(LifeFixture, FCcountNeighborsTest1) {
  istringstream stream;
  stream.str("---------");
  FredkinCell x('-');
  vector<vector<FredkinCell>> arr(3, vector<FredkinCell>(3, FredkinCell()));
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      stream >> x;
      arr[i][j] = x;
    }
  }
  int count = x.countNeighbors(arr);
  ASSERT_EQ(count, 0);
}

TEST(LifeFixture, FCcountNeighborsTest2) {
  istringstream stream;
  stream.str("-0-1-2---");
  FredkinCell x('*');
  vector<vector<FredkinCell>> arr(3, vector<FredkinCell>(3, FredkinCell()));
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      stream >> x;
      arr[i][j] = x;
    }
  }
  int count = x.countNeighbors(arr);
  cout << "count: " << count << endl;
  ASSERT_TRUE(count == 3);
}

TEST(LifeFixture, FCcountNeighborsTest3) {
  istringstream stream;
  stream.str("12345678-");
  FredkinCell x('.');
  vector<vector<FredkinCell>> arr(3, vector<FredkinCell>(3, FredkinCell()));
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      stream >> x;
      arr[i][j] = x;
    }
  }
  int count = x.countNeighbors(arr);
  ASSERT_EQ(count, 4);
}

TEST(LifeFixture, FCevolveTest1) {
  FredkinCell x('-');
  x.evolve(1);
  ostringstream stream;
  stream << x;
  ASSERT_EQ(stream.str(), "0");
}

TEST(LifeFixture, FCevolveTest2) {
  FredkinCell x('-');
  x.evolve(2);
  ostringstream stream;
  stream << x;
  ASSERT_EQ(stream.str(), "-");
}

TEST(LifeFixture, FCevolveTest3) {
  FredkinCell x('0');
  x.evolve(3);
  ostringstream stream;
  stream << x;
  ASSERT_EQ(stream.str(), "1");
  stream.str("");
  stream.clear();
  x.evolve(4);
  stream << x;
  ASSERT_EQ(stream.str(), "-");
}

TEST(LifeFixture, FCcloneTest1) {
  FredkinCell x('0');
  AbstractCell *temp = x.clone();
  ostringstream stream;
  stream << *temp;
  ASSERT_EQ(stream.str(), "0");
}

TEST(LifeFixture, FCcloneTest2) {
  FredkinCell x('-');
  AbstractCell *temp = x.clone();
  ostringstream stream;
  stream << *temp;
  ASSERT_EQ(stream.str(), "-");
}

TEST(LifeFixture, FCcloneTest3) {
  FredkinCell x('1');
  AbstractCell *temp = x.clone();
  ostringstream stream;
  stream << *temp;
  ASSERT_TRUE(*temp == x);
}

// Test for Life class
TEST(LifeFixture, LifepopulationTest1) {
  istringstream stream;
  stream.str("......***");
  Life<ConwayCell> x(3, 3, stream);
  ASSERT_EQ(x.population(), 3);
}

TEST(LifeFixture, LifepopulationTest2) {
  istringstream stream;
  stream.str("*********");
  Life<ConwayCell> x(3, 3, stream);
  ASSERT_EQ(x.population(), 9);
}

TEST(LifeFixture, LifepopulationTest3) {
  istringstream stream;
  stream.str("......123");
  Life<FredkinCell> x(3, 3, stream);
  ASSERT_EQ(x.population(), 3);
}

TEST(LifeFixture, LifeprintTest1) {
  istringstream stream;
  stream.str("....");
  Life<ConwayCell> x(2, 2, stream);

  ostringstream ss;
  // auto old_buf = cout.rdbuf(ss.rdbuf());

  x.print(ss);

  // cout.rdbuf(old_buf);

  string expected = "Generation = 0, Population = 0\n..\n..\n";
  ASSERT_EQ(expected, ss.str());
}

TEST(LifeFixture, LifeprintTest2) {
  istringstream stream;
  stream.str("****");
  Life<ConwayCell> x(2, 2, stream);

  ostringstream ss;
  // auto old_buf = cout.rdbuf(ss.rdbuf());

  x.print(ss);

  // cout.rdbuf(old_buf);

  string expected = "Generation = 0, Population = 4\n**\n**\n";
  ASSERT_EQ(expected, ss.str());
}

TEST(LifeFixture, LifeprintTest3) {
  istringstream stream;
  stream.str("0.1.");
  Life<FredkinCell> x(2, 2, stream);

  ostringstream ss;
  // auto old_buf = cout.rdbuf(ss.rdbuf());

  x.print(ss);

  // cout.rdbuf(old_buf);

  string expected = "Generation = 0, Population = 2\n0.\n1.\n";
  ASSERT_EQ(expected, ss.str());
}

TEST(LifeFixture, LifesimulateTest1) {
  istringstream stream;
  stream.str("****");
  Life<ConwayCell> x(2, 2, stream);

  ostringstream ss;
  x.simulate(ss);
  // auto old_buf = cout.rdbuf(ss.rdbuf());

  x.print(ss);

  // cout.rdbuf(old_buf);

  string expected = "\nGeneration = 1, Population = 4\n**\n**\n";
  ASSERT_EQ(expected, ss.str());
}

TEST(LifeFixture, LifesimulateTest2) {
  istringstream stream;
  stream.str("....");
  Life<ConwayCell> x(2, 2, stream);

  ostringstream ss;
  x.simulate(ss);
  // auto old_buf = cout.rdbuf(ss.rdbuf());

  x.print(ss);

  // cout.rdbuf(old_buf);

  string expected = "\nGeneration = 1, Population = 0\n..\n..\n";
  ASSERT_EQ(expected, ss.str());
}

TEST(LifeFixture, LifesimulateTest3) {
  istringstream stream;
  stream.str("----");
  Life<FredkinCell> x(2, 2, stream);

  ostringstream ss;
  x.simulate(ss);
  // auto old_buf = cout.rdbuf(ss.rdbuf());

  x.print(ss);

  // cout.rdbuf(old_buf);

  string expected = "\nGeneration = 1, Population = 0\n--\n--\n";
  ASSERT_EQ(expected, ss.str());
}
