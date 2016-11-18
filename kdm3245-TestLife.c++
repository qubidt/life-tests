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

TEST(LifeFixture, test) {
    //Life<int> x;
    ASSERT_TRUE(true);}

// ----------
// ConwayCell
// ----------

TEST(ConwayFixture, alive1) {
    ConwayCell cc;
    ASSERT_TRUE(cc.is_alive() == false);
}

TEST(ConwayFixture, alive2) {
    ConwayCell cc;
    cc.alive = true;
    ASSERT_TRUE(cc.is_alive());
}

TEST(ConwayFixture, alive3) {
    ConwayCell cc;
    cc.state('*');
    ASSERT_TRUE(cc.is_alive());
}

TEST(ConwayFixture, clone1) {
    ConwayCell cc;
    AbstractCell *ac = cc.clone();
    ASSERT_TRUE(dynamic_cast<ConwayCell*>(ac) != &cc);
    delete ac;
}

TEST(ConwayFixture, print1) {
    ConwayCell cc;
    ASSERT_TRUE(cc.print() == '.');
}

TEST(ConwayFixture, print2) {
    ConwayCell cc;
    cc.alive = true;
    ASSERT_TRUE(cc.print() == '*');
}

TEST(ConwayFixture, print3) {
    ConwayCell cc;
    cc.alive = true;
    cc.state('.');
    ASSERT_TRUE(cc.print() == '.');
}

TEST(ConwayFixture, evolve1) {
    ConwayCell cc;
    cc.evolve(3);
    ASSERT_TRUE(cc.is_alive() == true);
}

TEST(ConwayFixture, evolve2) {
    ConwayCell cc;
    cc.evolve(0);
    ASSERT_TRUE(cc.is_alive() == false);
}

TEST(ConwayFixture, evolve3) {
    ConwayCell cc;
    cc.evolve(4);
    ASSERT_TRUE(cc.is_alive() == false);
}

TEST(ConwayFixture, state1) {
    ConwayCell cc;
    cc.state('*');
    ASSERT_TRUE(cc.is_alive() == true);
}

TEST(ConwayFixture, state2) {
    ConwayCell cc;
    cc.state('.');
    ASSERT_TRUE(cc.is_alive() == false);
}

TEST(ConwayFixture, state3) {
    ConwayCell cc;
    cc.state('*');
    cc.state('.');
    ASSERT_TRUE(cc.is_alive() == false);
}

TEST(ConwayFixture, neighbor1) {
    ConwayCell cc;
    ASSERT_TRUE(cc.has_neighbor(0, 0) == true);
}

TEST(ConwayFixture, neighbor2) {
    ConwayCell cc;
    ASSERT_TRUE(cc.has_neighbor(4, 2) == true);
}

TEST(ConwayFixture, neighbor3) {
    ConwayCell cc;
    ASSERT_TRUE(cc.has_neighbor(1, -1) == true);
}

// -----------
// FredkinCell
// -----------

TEST(FredkinFixture, alive4) {
    FredkinCell f;
    ASSERT_TRUE(f.is_alive() == false);
}

TEST(FredkinFixture, alive5) {
    FredkinCell f;
    f.state('1');
    ASSERT_TRUE(f.is_alive());
}

TEST(FredkinFixture, alive6) {
    FredkinCell f;
    f.alive = true;
    ASSERT_TRUE(f.is_alive());
}

TEST(FredkinFixture, clone4) {
    FredkinCell fc;
    AbstractCell *ac = fc.clone();
    ASSERT_TRUE(dynamic_cast<FredkinCell*>(ac) != &fc);
    delete ac;
}

TEST(FredkinFixture, print4) {
    FredkinCell f;
    ASSERT_TRUE(f.print() == '-');
}

TEST(FredkinFixture, print5) {
    FredkinCell f;
    f.alive = true;
    f.age = 0;
    ASSERT_TRUE(f.print() == '0');
}

TEST(FredkinFixture, print6) {
    FredkinCell f;
    f.alive = true;
    f.age = 11;
    ASSERT_TRUE(f.print() == '+');
}

TEST(FredkinFixture, evolve4) {
    FredkinCell f;
    f.evolve(1);
    ASSERT_TRUE(f.is_alive() == true);
}

TEST(FredkinFixture, evolve5) {
    FredkinCell f;
    f.evolve(2);
    ASSERT_TRUE(f.is_alive() == false);
}

TEST(FredkinFixture, evolve6) {
    FredkinCell f;
    f.evolve(3);
    ASSERT_TRUE(f.is_alive() == true);
}

TEST(FredkinFixture, state4) {
    FredkinCell f;
    f.state('1');
    ASSERT_TRUE(f.is_alive() == true);
}

TEST(FredkinFixture, state5) {
    FredkinCell f;
    f.state('0');
    ASSERT_TRUE(f.is_alive() == true);
}

TEST(FredkinFixture, state6) {
    FredkinCell f;
    f.state('4');
    ASSERT_TRUE(f.is_alive() == true);
}

TEST(FredkinFixture, neighbor4) {
    FredkinCell f;
    ASSERT_TRUE(f.has_neighbor(1, 0));
}

TEST(FredkinFixture, neighbor5) {
    FredkinCell f;
    ASSERT_TRUE(f.has_neighbor(0, 0));
}

TEST(FredkinFixture, neighbor6) {
    FredkinCell f;
    ASSERT_TRUE(f.has_neighbor(1, 1) == false);
}

// ----
// Cell
// ----

TEST(CellFixture, alive7) {
    Cell c;
    ASSERT_TRUE(c.is_alive() == false);
}

TEST(CellFixture, alive8) {
    Cell c;
    c.state('*');
    ASSERT_TRUE(c.is_alive());
}

TEST(CellFixture, alive9) {
    Cell c;
    c.state('5');
    ASSERT_TRUE(c.is_alive());
}

TEST(CellFixture, print7) {
    Cell c;
    ASSERT_TRUE(c.print() == '-');
}

TEST(CellFixture, print8) {
    Cell c;
    c.state('0');
    ASSERT_TRUE(c.print() == '0');
}

TEST(CellFixture, print9) {
    Cell c;
    c.state('*');
    ASSERT_TRUE(c.print() == '*');
}

TEST(CellFixture, evolve7) {
    Cell c;
    c.evolve(0);
    ASSERT_TRUE(c.is_alive() == false);
}

TEST(CellFixture, evolve8) {
    Cell c;
    c.evolve(3);
    ASSERT_TRUE(c.is_alive());
}

TEST(CellFixture, evolve9) {
    Cell c;
    c.evolve(4);
    ASSERT_TRUE(c.is_alive() == false);
}

TEST(CellFixture, state7) {
    Cell c;
    c.state('-');
    ASSERT_TRUE(c.is_alive() == false);
}

TEST(CellFixture, state8) {
    Cell c;
    c.state('6');
    ASSERT_TRUE(c.is_alive());
}

TEST(CellFixture, state9) {
    Cell c;
    c.state('9');
    ASSERT_TRUE(c.is_alive());
}

TEST(CellFixture, neighbor7) {
    Cell c;
    ASSERT_TRUE(c.has_neighbor(0, 0));
}

TEST(CellFixture, neighbor8) {
    Cell c;
    ASSERT_TRUE(c.has_neighbor(1, 0));
}

TEST(CellFixture, neighbor9) {
    Cell c;
    ASSERT_TRUE(c.has_neighbor(1, -1) == false);
}
