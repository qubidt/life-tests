// --------------------------
// projects/life/TestLife.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#define DEAD 0
#define ALIVE 1

#include "gtest/gtest.h"

#include "Life.h"

#include <iostream>
#include <sstream>  
#include <string>  

using namespace std;

// ----
// test
// ----

TEST(LifeFixture, test_conway) {
    Life<ConwayCell> x(4,4);

    x.addCell(2,2, CONWAY, ALIVE);
    x.addCell(1,2, CONWAY, ALIVE);
    x.addCell(1,1, CONWAY, ALIVE);
    cout << x;
    x.tick();
    cout << x;
}

TEST(LifeFixture, test_fredkin) {
    Life<FredkinCell> x(4,4);

    x.addCell(2,2, FREDKIN, ALIVE);
    x.addCell(1,2, FREDKIN, ALIVE);
    x.addCell(1,1, FREDKIN, ALIVE);
    x.addCell(2,1, FREDKIN, ALIVE);
    cout << x;
    x.tick();
    cout << x;
}
TEST(LifeFixture, test_cell) {
    Life<Cell> x(4,4);

    x.addCell(0,1, FREDKIN, ALIVE);
    x.addCell(1,0, FREDKIN, ALIVE);
    x.addCell(1,1, FREDKIN, ALIVE);
    x.addCell(1,2, FREDKIN, ALIVE);
    cout << x;
    x.tick();
    cout << x;
    x.tick();
    cout << x;

}

TEST(LifeFixture, test_cc_tick_1) {
    ConwayCell b;
    ASSERT_EQ(b.alive, ALIVE);
    b.tick();
    ASSERT_EQ(b.alive, DEAD);
}

TEST(LifeFixture, test_cc_tick_2) {
    ConwayCell b;
    b.neigh = 3;
    ASSERT_EQ(b.alive, ALIVE);
    b.tick();
    ASSERT_EQ(b.alive, ALIVE);
}

TEST(LifeFixture, test_cc_tick_3) {
    ConwayCell b;
    b.neigh = 3;
    b.alive = DEAD;
    ASSERT_EQ(b.alive, DEAD);
    b.tick();
    ASSERT_EQ(b.alive, ALIVE);
}

TEST(LifeFixture, test_cc_write_1) {
   ConwayCell b;
   ASSERT_TRUE(!(b.write()).compare("*"));

}
TEST(LifeFixture, test_cc_write_2) {
   ConwayCell b;
   b.alive = ALIVE;
   ASSERT_TRUE(!(b.write()).compare("*"));

}
TEST(LifeFixture, test_cc_write_3) {
   ConwayCell b;
   b.alive = DEAD;
   ASSERT_TRUE(!(b.write()).compare("."));

}

TEST(LifeFixture, test_cc_count_1) {
   ConwayCell b;
   Cell z(CONWAY, ALIVE);
   int p = 0;
   b.count(p, z.c, z.c, z.c, z.c,
              z.c, z.c, z.c, z.c);

   ASSERT_EQ(p, 1);
   ASSERT_EQ(b.neigh, 8);
}
TEST(LifeFixture, test_cc_count_2) {
   ConwayCell b;
   b.alive = DEAD;
   Cell z(CONWAY, DEAD);
   int p = 0;
   b.count(p, z.c, z.c, z.c, z.c,
              z.c, z.c, z.c, z.c);

   ASSERT_EQ(p, 0);
   ASSERT_EQ(b.neigh, 0);
}
TEST(LifeFixture, test_cc_count_3) {
   ConwayCell b;
   Cell z(CONWAY, ALIVE);
   int p = 0;
   b.count(p, z.c, nullptr, z.c, nullptr,
              z.c, nullptr, z.c, nullptr);;

   ASSERT_EQ(p, 1);
   ASSERT_EQ(b.neigh, 4);
}


TEST(LifeFixture, test_fc_tick_1) {
    FredkinCell b;
    ASSERT_EQ(b.alive, ALIVE);
    b.tick();
    ASSERT_EQ(b.alive, DEAD);
}

TEST(LifeFixture, test_fc_tick_2) {
    FredkinCell b;
    b.neigh = 1;
    ASSERT_EQ(b.alive, ALIVE);
    b.tick();
    ASSERT_EQ(b.alive, ALIVE);
}

TEST(LifeFixture, test_fc_tick_3) {
    FredkinCell b;
    b.neigh = 3;
    b.alive = DEAD;
    ASSERT_EQ(b.alive, DEAD);
    b.tick();
    ASSERT_EQ(b.alive, ALIVE);
}

TEST(LifeFixture, test_fc_write_1) {
   FredkinCell b;
   ASSERT_TRUE(!(b.write()).compare("0"));

}
TEST(LifeFixture, test_fc_write_2) {
   FredkinCell b;
   b.age = 10;
   ASSERT_TRUE(!(b.write()).compare("+"));

}
TEST(LifeFixture, test_fc_write_3) {
   FredkinCell b;
   b.alive = DEAD;
   ASSERT_TRUE(!(b.write()).compare("-"));

}

TEST(LifeFixture, test_fc_count_1) {
   FredkinCell b;
   Cell z(FREDKIN, ALIVE);
   int p = 0;
   b.count(p, z.c, z.c, z.c, z.c,
              z.c, z.c, z.c, z.c);

   ASSERT_EQ(p, 1);
   ASSERT_EQ(b.neigh, 4);
}
TEST(LifeFixture, test_fc_count_2) {
   FredkinCell b;
   b.alive = DEAD;
   Cell z(FREDKIN, DEAD);
   int p = 0;
   b.count(p, z.c, z.c, z.c, z.c,
              z.c, z.c, z.c, z.c);

   ASSERT_EQ(p, 0);
   ASSERT_EQ(b.neigh, 0);
}
TEST(LifeFixture, test_fc_count_3) {
   FredkinCell b;
   Cell z(FREDKIN, ALIVE);
   int p = 0;
   b.count(p, z.c, nullptr, z.c, nullptr,
              z.c, nullptr, z.c, nullptr);;

   ASSERT_EQ(p, 1);
   ASSERT_EQ(b.neigh, 2);
}

TEST(LifeFixture, test_can_transform_1) {
    ConwayCell b;
    ASSERT_FALSE(b.can_transform());

}
TEST(LifeFixture, test_can_transform_2) {
    FredkinCell b;
    ASSERT_FALSE(b.can_transform());

}
TEST(LifeFixture, test_can_transform_3) {
    FredkinCell b;
    b.age = 2;
    ASSERT_TRUE(b.can_transform());

}
TEST(LifeFixture, test_addcell_1) {
  Life<ConwayCell> b(2,2);
  b.addCell(0,0, CONWAY, ALIVE);

}
TEST(LifeFixture, test_addcell_2) {
  Life<FredkinCell> b(2,2);
  b.addCell(0,0, FREDKIN, ALIVE);

}
TEST(LifeFixture, test_addcell_3) {
  Life<Cell> b(2,2);
  b.addCell(0,0, FREDKIN, ALIVE);

}

TEST(LifeFixture, test_output_op_1) {
   Life<ConwayCell> b(2,2);
   b.addCell(0,0, CONWAY, ALIVE);
   b.addCell(1,1, CONWAY, ALIVE);

   stringstream s;
   s << b;
   string output = s.str();
   string exp = "\nGeneration = 0, Population = 2.\n*.\n.*\n\n";
   ASSERT_TRUE(!output.compare(exp));

}
TEST(LifeFixture, test_output_op_2) {
   Life<FredkinCell> b(2,2);
   b.addCell(0,0, FREDKIN, ALIVE);
   b.addCell(1,1, FREDKIN, ALIVE);

   stringstream s;
   s << b;
   string output = s.str();
   string exp = "\nGeneration = 0, Population = 2.\n0-\n-0\n\n";
   ASSERT_TRUE(!output.compare(exp));

}
TEST(LifeFixture, test_output_op_3) {
   Life<Cell> b(2,2);
   b.addCell(0,0, FREDKIN, ALIVE);
   b.addCell(1,1, CONWAY, ALIVE);

   stringstream s;
   s << b;
   string output = s.str();
   string exp = "\nGeneration = 0, Population = 2.\n0-\n-*\n\n";
   ASSERT_TRUE(!output.compare(exp));

}

TEST(LifeFixture, test_life_tick_1) {
   Life<ConwayCell> b(2,2);
   b.addCell(0,0, CONWAY, ALIVE);
   b.addCell(1,1, CONWAY, ALIVE);

   b.tick();
   stringstream s;
   s << b;
   string output = s.str();
   string exp = "\nGeneration = 1, Population = 0.\n..\n..\n\n";
   ASSERT_TRUE(!output.compare(exp));
}

TEST(LifeFixture, test_life_tick_2) {
   Life<Cell> b(3,3);
   b.addCell(0,1, CONWAY, ALIVE);
   b.addCell(1,0, CONWAY, ALIVE);
   b.addCell(1,2, CONWAY, ALIVE);

   b.tick();
   stringstream s;
   s << b;
   string output = s.str();
   cout << output;
   string exp = "\nGeneration = 1, Population = 4.\n-*-\n.0.\n0-0\n\n";
   ASSERT_TRUE(!output.compare(exp));
}
TEST(LifeFixture, test_life_tick_3) {
   Life<FredkinCell> b(2,2);
   b.addCell(0,1, FREDKIN, ALIVE);
   b.addCell(1,0, FREDKIN, ALIVE);

   b.tick();
   stringstream s;
   s << b;
   string output = s.str();
   cout << output;
   string exp = "\nGeneration = 1, Population = 0.\n--\n--\n\n";
   ASSERT_TRUE(!output.compare(exp));
}





