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
// AbstractCell
// ----

TEST(AbstractCell, is_alive_1) {
    ConwayCell c;
    ASSERT_EQ(false, c.isAlive());
}

TEST(AbstractCell, is_alive_2) {
    ConwayCell c;
    c._alive = true;
    ASSERT_EQ(true, c.isAlive());
}

TEST(AbstractCell, revive_1) {
    ConwayCell c;
    ASSERT_EQ(false, c._alive);
    c._alive = true;
    ASSERT_EQ(true, c._alive);
}

TEST(AbstractCell, revive_2) {
    ConwayCell c;
    c._alive = true;
    ASSERT_EQ(true, c._alive);
}

// ----
// ConwayCell
// ----

TEST(ConwayCell, simulate_1) {
    ConwayCell c;
    ASSERT_EQ(false, c._alive);
    c.simulate(3);
    ASSERT_EQ(true, c._alive);
}

TEST(ConwayCell, simulate_2) {
    ConwayCell c;
    c._alive = true;
    ASSERT_EQ(true, c._alive);

    c.simulate(0);
    ASSERT_EQ(false, c._alive);

    c._alive = true;
    c.simulate(1);
    ASSERT_EQ(false, c._alive);
}

TEST(ConwayCell, simulate_3) {
    ConwayCell c;
    c._alive = true;
    ASSERT_EQ(true, c._alive);

    c._alive = true;
    c.simulate(4);
    ASSERT_EQ(false, c._alive);

    c._alive = true;
    c.simulate(5);
    ASSERT_EQ(false, c._alive);
}

TEST(ConwayCell, print_1) {
    ConwayCell c;
    ASSERT_EQ(false, c._alive);
    ostringstream w;
    c.print(w);
    ASSERT_EQ(".", w.str());
}

TEST(ConwayCell, print_2) {
    ConwayCell c;
    c._alive = true;
    ASSERT_EQ(true, c._alive);
    ostringstream w;
    c.print(w);
    ASSERT_EQ("*", w.str());
}

TEST(ConwayCell, clone_1) {
    ConwayCell c;
    ConwayCell* c2 = c.clone();
    ASSERT_EQ(false, c._alive);
    ASSERT_EQ(false, c2->_alive);
}

TEST(ConwayCell, clone_2) {
    ConwayCell c;
    c._alive = true;
    ConwayCell* c2 = c.clone();
    ASSERT_EQ(true, c._alive);
    ASSERT_EQ(true, c2->_alive);
}

TEST(ConwayCell, clone_3) {
    ConwayCell c;
    ConwayCell* c2 = c.clone();
    ASSERT_NE(&c, c2);
}

TEST(ConwayCell, type_1) {
    ConwayCell c;
    ASSERT_EQ(CC, c.type());
}

TEST(ConwayCell, evolve_1) {
    ConwayCell c;
    ASSERT_EQ(nullptr, c.evolve());
}

// ----
// FredkinCell
// ----

TEST(FredkinCell, simulate_1) {
    FredkinCell c;
    ASSERT_EQ(false, c._alive);
    c.simulate(2);
    ASSERT_EQ(false, c._alive);
}

TEST(FredkinCell, simulate_2) {
    FredkinCell c;

    c._alive = true;
    c.simulate(0);
    ASSERT_EQ(false, c._alive);

    c._alive = true;
    c.simulate(2);
    ASSERT_EQ(false, c._alive);

    c._alive = true;
    c.simulate(4);
    ASSERT_EQ(false, c._alive);
}

TEST(FredkinCell, simulate_3) {
    FredkinCell c;

    c.simulate(1);
    ASSERT_EQ(true, c._alive);

    c._alive = false;
    c.simulate(3);
    ASSERT_EQ(true, c._alive);
}

TEST(FredkinCell, print_1) {
    FredkinCell c;
    ASSERT_EQ(false, c._alive);
    ostringstream w;
    c.print(w);
    ASSERT_EQ("-", w.str());
}

TEST(FredkinCell, print_2) {
    FredkinCell c;
    c._alive = true;
    ASSERT_EQ(true, c._alive);
    ostringstream w;
    c.print(w);
    ASSERT_EQ("0", w.str());
}

TEST(FredkinCell, print_3) {
    FredkinCell c;
    c._alive = true;
    ASSERT_EQ(true, c._alive);
    ostringstream w;
    c.simulate(1);
    c.simulate(1);
    c.simulate(1);
    c.simulate(1);
    c.simulate(1);
    c.simulate(1);
    c.simulate(1);
    c.simulate(1);
    c.simulate(1);
    c.simulate(1);
    c.print(w);
    ASSERT_EQ("+", w.str());
}

TEST(FredkinCell, clone_1) {
    FredkinCell c;
    FredkinCell* c2 = c.clone();
    ASSERT_EQ(false, c._alive);
    ASSERT_EQ(0, c._age);

    ASSERT_EQ(false, c2->_alive);
    ASSERT_EQ(0, c2->_age);
}

TEST(FredkinCell, clone_2) {
    FredkinCell c;
    c._alive = true;
    c.simulate(1);
    FredkinCell* c2 = c.clone();
    ASSERT_EQ(true, c._alive);
    ASSERT_EQ(1, c._age);
    ASSERT_EQ(true, c2->_alive);
    ASSERT_EQ(1, c2->_age);
}

TEST(FredkinCell, clone_3) {
    FredkinCell c;
    FredkinCell* c2 = c.clone();
    ASSERT_NE(&c, c2);

    ASSERT_EQ(c._age, c2->_age);
    c._age = 10;
    ASSERT_NE(c._age, c2->_age);
}

TEST(FredkinCell, type_1) {
    FredkinCell c;
    ASSERT_EQ(FC, c.type());
}

TEST(FredkinCell, evolve_1) {
    FredkinCell c;
    ASSERT_EQ(nullptr, c.evolve());
}

TEST(FredkinCell, evolve_2) {
    FredkinCell c;
    c._age = 2;
    ASSERT_NE(nullptr, c.evolve());
}

// ----
// FredkinCell
// ----

TEST(Life, build_1) {
    Life<ConwayCell> l(5,5);
    string board =  "....."
                    "....."
                    "....."
                    "....."
                    ".....";
    ostringstream w;
    l.print(false, w);
    ASSERT_EQ(board, w.str());
}

TEST(Life, build_2) {
    Life<FredkinCell> l(5,5);
    string board =  "-----"
                    "-----"
                    "-----"
                    "-----"
                    "-----";
    ostringstream w;
    l.print(false, w);
    ASSERT_EQ(board, w.str());
}

TEST(Life, build_3) {
    Life<Cell> l(5,5);
    l.initLife();
    string board =  "-----"
                    "-----"
                    "-----"
                    "-----"
                    "-----";
    ostringstream w;
    l.print(false, w);
    ASSERT_EQ(board, w.str());
}

TEST(Life, neighbor_count_1) {
    Life<ConwayCell> l(5,5);
    string board =  ".*..."
                    "**..."
                    "....."
                    "....."
                    "....*";
    l.revive(1,2);
    l.revive(2,1);
    l.revive(2,2);
    l.revive(5,5);
    ostringstream w;
    l.print(false, w);
    ASSERT_EQ(board, w.str());

    ASSERT_EQ(3 , l.neighborCount(1,1));
    ASSERT_EQ(2 , l.neighborCount(1,2));
    ASSERT_EQ(2 , l.neighborCount(2,1));
    ASSERT_EQ(2 , l.neighborCount(2,2));
    ASSERT_EQ(0 , l.neighborCount(5,5));
}

TEST(Life, neighbor_count_2) {
    Life<FredkinCell> l(5,5);
    string board =  "-0---"
                    "00---"
                    "-----"
                    "-----"
                    "----0";
    l.revive(1,2);
    l.revive(2,1);
    l.revive(2,2);
    l.revive(5,5);
    ostringstream w;
    l.print(false, w);
    ASSERT_EQ(board, w.str());

    ASSERT_EQ(2 , l.neighborCount(1,1));
    ASSERT_EQ(1 , l.neighborCount(1,2));
    ASSERT_EQ(1 , l.neighborCount(2,1));
    ASSERT_EQ(2 , l.neighborCount(2,2));
    ASSERT_EQ(0 , l.neighborCount(5,5));
}

TEST(Life, neighbor_count_3) {
    Life<Cell> l(5,5);
    l.initLife();
    string board =  "-0---"
                    "00---"
                    "-----"
                    "-----"
                    "----0";
    l.revive(1,2);
    l.revive(2,1);
    l.revive(2,2);
    l.revive(5,5);
    ostringstream w;
    l.print(false, w);
    ASSERT_EQ(board, w.str());

    ASSERT_EQ(2 , l.neighborCount(1,1));
    ASSERT_EQ(1 , l.neighborCount(1,2));
    ASSERT_EQ(1 , l.neighborCount(2,1));
    ASSERT_EQ(2 , l.neighborCount(2,2));
    ASSERT_EQ(0 , l.neighborCount(5,5));
}

TEST(Life, simulate_1) {
    Life<ConwayCell> b(20, 29);
    string board =  "............................."
                    "............................."
                    "............................."
                    "...**........................"
                    "...*.......***......****....."
                    "............................."
                    "............................."
                    "............................."
                    "............................."
                    "............................."
                    "............................."
                    "....*......*.........*......."
                    "....**.....***......***......"
                    ".....*......................."
                    "............................."
                    "............................."
                    "............................."
                    "............................."
                    "............................."
                    ".............................";

    int idx = 0;
    for (int r = 1; r <= 20; ++r) {
        for (int c = 1; c <= 29; ++c) {
            if (board[idx] == '*')
                b.revive(r, c);
            ++idx;
        }
    }

    board = "............................."
            "............................."
            "............................."
            "...**................**......"
            "...**......***......*..*....."
            ".....................**......"
            "............................."
            "............................."
            ".....................*......."
            ".....................*......."
            ".....................*......."
            "....**.....**................"
            "...*..*...*..*...***...***..."
            "....**.....**................"
            ".....................*......."
            ".....................*......."
            ".....................*......."
            "............................."
            "............................."
            ".............................";

    b.simulate(28);
    ostringstream w;
    b.print(false, w);
    ASSERT_EQ(board, w.str());
}

TEST(Life, simulate_2) {
    Life<FredkinCell> d(20, 20);
    string board =  "--------------------"
                    "--------------------"
                    "--------------------"
                    "--------------------"
                    "--------------------"
                    "--------------------"
                    "--------------------"
                    "--------------------"
                    "--------------------"
                    "---------00---------"
                    "---------00---------"
                    "--------------------"
                    "--------------------"
                    "--------------------"
                    "--------------------"
                    "--------------------"
                    "--------------------"
                    "--------------------"
                    "--------------------"
                    "--------------------";

    int idx = 0;
    for (int r = 1; r <= 20; ++r) {
        for (int c = 1; c <= 20; ++c) {
            if (board[idx] == '0')
                d.revive(r, c);
            ++idx;
        }
    }

    board = "--------------------"
            "--------------------"
            "--------------------"
            "--------------------"
            "---------00---------"
            "--------0--0--------"
            "--------0--0--------"
            "---------00---------"
            "-----00------00-----"
            "----0--0----0--0----"
            "----0--0----0--0----"
            "-----00------00-----"
            "---------00---------"
            "--------0--0--------"
            "--------0--0--------"
            "---------00---------"
            "--------------------"
            "--------------------"
            "--------------------"
            "--------------------";

    d.simulate(5);
    ostringstream w;
    d.print(false, w);
    ASSERT_EQ(board, w.str());
}

TEST(Life, simulate_3) {
    Life<Cell> e(20, 20);
        e.initLife();
        string board =  "--------------------"
                        "--------------------"
                        "--------------------"
                        "--------------------"
                        "--------------------"
                        "--------------------"
                        "--------------------"
                        "--------------------"
                        "--------------------"
                        "---------00---------"
                        "--------0000--------"
                        "--------------------"
                        "--------------------"
                        "--------------------"
                        "--------------------"
                        "--------------------"
                        "--------------------"
                        "--------------------"
                        "--------------------"
                        "--------------------";

    int idx = 0;
    for (int r = 1; r <= 20; ++r) {
        for (int c = 1; c <= 20; ++c) {
            if (board[idx] == '0')
                e.revive(r, c);
            ++idx;
        }
    }

    board = "--------------------"
            "--------------------"
            "--------------------"
            "--------------------"
            "---------00---------"
            "--------------------"
            "-------01**10-------"
            "--------0000--------"
            "-----00-0**0-00-----"
            "--------.--.--------"
            "---01**.*..*.**10---"
            "----0000-..-0000----"
            "--------1111--------"
            "--------------------"
            "-------011110-------"
            "--------0000--------"
            "--------------------"
            "--------------------"
            "--------------------"
            "--------------------";
        e.simulate(5);
        ostringstream w;
        e.print(false, w);
        ASSERT_EQ(board, w.str());
}
