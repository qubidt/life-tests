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
#include <sstream>
#include <utility>
#include <cassert>   // assert
#include <fstream>

#include "Life.h"

using namespace std;

// ----
// test
// ----

TEST(LifeConstructor, test1) {
    istringstream ins (
        "21 13\n"
        ".............\n"
        ".............\n"
        ".............\n"
        ".............\n"
        ".............\n"
        ".............\n"
        ".............\n"
        ".............\n"
        "....*****....\n"
        ".......*.....\n"
        "......*......\n"
        ".....*.......\n"
        "....*****....\n"
        ".............\n"
        ".............\n"
        ".............\n"
        ".............\n"
        ".............\n"
        ".............\n"
        ".............\n"
        ".............\n"
    );

    Life<ConwayCell> lcc (ins);
    ASSERT_EQ(lcc.population, 13);
    ASSERT_EQ(lcc.generation, 0);
    ASSERT_EQ(lcc.alive[0][0], 0);
    ASSERT_EQ(lcc.alive[8][6], 1);

    lcc.run(1);
    ASSERT_EQ(lcc.neighbors[0][0], 0);
    ASSERT_EQ(lcc.neighbors[8][6], 3);
}

TEST(LifeConstructor, test2) {
    istringstream ins2 (
        "20 29\n"
        ".............................\n"
        ".............................\n"
        ".............................\n"
        "...**........................\n"
        "...*.......***......****.....\n"
        ".............................\n"
        ".............................\n"
        ".............................\n"
        ".............................\n"
        ".............................\n"
        ".............................\n"
        "....*......*.........*.......\n"
        "....**.....***......***......\n"
        ".....*.......................\n"
        ".............................\n"
        ".............................\n"
        ".............................\n"
        ".............................\n"
        ".............................\n"
        ".............................\n"
    );

    Life<ConwayCell> lcc2 (ins2);
    ASSERT_EQ(lcc2.population, 22);
    ASSERT_EQ(lcc2.generation, 0);
    ASSERT_EQ(lcc2.alive[0][0], 0);
    ASSERT_EQ(lcc2.alive[3][3], 1);

    lcc2.run(1);
    ASSERT_EQ(lcc2.neighbors[0][0], 0);
    ASSERT_EQ(lcc2.neighbors[3][3], 2);
}

TEST(LifeConstructor, test3) {
    istringstream ins3 (
        "20 20\n"
        "--------------------\n"
        "--------------------\n"
        "--------------------\n"
        "--------------------\n"
        "--------------------\n"
        "--------------------\n"
        "--------------------\n"
        "--------------------\n"
        "--------------------\n"
        "---------00---------\n"
        "---------00---------\n"
        "--------------------\n"
        "--------------------\n"
        "--------------------\n"
        "--------------------\n"
        "--------------------\n"
        "--------------------\n"
        "--------------------\n"
        "--------------------\n"
        "--------------------\n"
    );

    Life<FredkinCell> lcc3 (ins3);
    ASSERT_EQ(lcc3.population, 4);
    ASSERT_EQ(lcc3.generation, 0);
    ASSERT_EQ(lcc3.alive[0][0], 0);
    ASSERT_EQ(lcc3.alive[9][9], 1);

    lcc3.run(1);
    ASSERT_EQ(lcc3.neighbors[0][0], 0);
    ASSERT_EQ(lcc3.neighbors[9][9], 2);
}
