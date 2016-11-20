// --------------------------
// projects/life/TestLife.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------
#include <vector>

#include "gtest/gtest.h"

#include "Life.h"

using namespace std;

// --------------------------------------------------
// Testing for common/inherited methods between FC/CC
// --------------------------------------------------

// -------------------------
// AbstractCell_toggle tests
// -------------------------
TEST(AbstractCell_toggle, now_dead_1) {
    ConwayCell cc = ConwayCell('*');
    cc.toggle();
    ASSERT_FALSE(cc.is_alive());
}

TEST(AbstractCell_toggle, now_dead_2) {
    FredkinCell fc = FredkinCell('1');
    fc.toggle();
    ASSERT_FALSE(fc.is_alive());
}

TEST(AbstractCell_toggle, now_alive_1) {
    ConwayCell cc = ConwayCell('.');
    cc.toggle();
    ASSERT_TRUE(cc.is_alive());
}

TEST(AbstractCell_toggle, now_alive_2) {
    FredkinCell fc= FredkinCell('-');
    fc.toggle();
    ASSERT_TRUE(fc.is_alive());
}

// ---------------------------
// AbstractCell_is_alive tests
// ---------------------------

TEST(AbstractCell_is_alive, dead_1) {
    ConwayCell cc = ConwayCell('.');
    ASSERT_FALSE(cc.is_alive());
}

TEST(AbstractCell_is_alive, dead_2) {
    FredkinCell fc = FredkinCell('-');
    ASSERT_FALSE(fc.is_alive());
}

TEST(AbstractCell_is_alive, alive_1) {
    ConwayCell cc = ConwayCell('*');
    ASSERT_TRUE(cc.is_alive());
}

TEST(AbstractCell_is_alive, alive_2) {
    FredkinCell fc = FredkinCell('5');
    ASSERT_TRUE(fc.is_alive());
}

// ------------------------------------------------------
// Testing for ConwayCell implemented methods/constructor
// ------------------------------------------------------

// ----------------------------
// ConwayCell_constructor tests
// ----------------------------

TEST(ConwayCell_constructor, dot) {
    ConwayCell cc = ConwayCell('*');
    ASSERT_TRUE(cc.is_alive());
    ASSERT_EQ(cc.display(), '*');
}

TEST(ConwayCell_constructor, star) {
    ConwayCell cc = ConwayCell('.');
    ASSERT_FALSE(cc.is_alive());
    ASSERT_EQ(cc.display(), '.');
}

TEST(ConwayCell_constructor, other) {
    ConwayCell cc = ConwayCell('+'); //Will be alive CC
    ASSERT_TRUE(cc.is_alive());
    ASSERT_EQ(cc.display(), '*');
}

// ------------------------
// ConwayCell_display tests
// ------------------------

TEST(ConwayCell_display, is_alive) {
    ConwayCell cc = ConwayCell('*');
    ASSERT_EQ(cc.display(), '*');
}

TEST(ConwayCell_display, is_dead) {
    ConwayCell cc = ConwayCell('.');
    ASSERT_EQ(cc.display(), '.');
}

TEST(ConwayCell_display, toggled) {
    ConwayCell cc = ConwayCell('*');
    ASSERT_EQ(cc.display(), '*');
    cc.toggle();
    ASSERT_EQ(cc.display(), '.');
}

// -----------------------------
// ConwayCell_check_evolve tests
// -----------------------------

TEST(ConwayCell_check_evolve, become_alive) {
    ConwayCell cc_star = ConwayCell('*');
    vector <AbstractCell*> neighbors = {nullptr, nullptr, nullptr,
                                 nullptr, nullptr, &cc_star,
                                 nullptr, &cc_star, &cc_star};
    ConwayCell cc = ConwayCell('.');
    ASSERT_TRUE(cc.check_evolve(neighbors));
}

TEST(ConwayCell_check_evolve, become_dead) {
    ConwayCell cc_dot = ConwayCell('.');
    vector <AbstractCell*> neighbors = {nullptr, &cc_dot, nullptr,
                                 nullptr, nullptr, nullptr,
                                 nullptr, nullptr, nullptr};
    ConwayCell cc = ConwayCell('*');
    ASSERT_TRUE(cc.check_evolve(neighbors));
}

TEST(ConwayCell_check_evolve, both) {
    ConwayCell cc_dot = ConwayCell('.');
    ConwayCell cc_star = ConwayCell('*');
    vector <AbstractCell*> neighbors = {&cc_dot, &cc_dot, &cc_dot,
                                        &cc_dot, nullptr, &cc_star,
                                        &cc_dot, &cc_star, &cc_star};
    ConwayCell cc = ConwayCell('.');
    ASSERT_TRUE(cc.check_evolve(neighbors));
    cc.toggle();
    ASSERT_FALSE(cc.check_evolve(neighbors));
}

// ----------------
// ConwayCell_clone
// ----------------

TEST(ConwayCell_clone, test_alive) {
    ConwayCell cc = ConwayCell('*');
    AbstractCell* cc_clone = cc.clone();
    ASSERT_EQ(cc.display(), cc_clone->display());
    delete cc_clone;
}

TEST(ConwayCell_clone, test_dead) {
    ConwayCell cc = ConwayCell('.');
    AbstractCell* cc_clone = cc.clone();
    ASSERT_EQ(cc.display(), cc_clone->display());
    delete cc_clone;
}

// -------------------------------------------------------
// Testing for FredkinCell implemented methods/constructor
// -------------------------------------------------------

// -----------------------------
// FredkinCell_constructor tests
// -----------------------------

TEST(FredkinCell_constructor, number) {
    FredkinCell fc = FredkinCell('5');
    ASSERT_TRUE(fc.is_alive());
    ASSERT_EQ(fc.display(), '5');
}

TEST(FredkinCell_constructor, plus) {
    FredkinCell fc = FredkinCell('+');
    ASSERT_TRUE(fc.is_alive());
    ASSERT_EQ(fc.display(), '+');
}

TEST(FredkinCell_constructor, minus) {
    FredkinCell fc = FredkinCell('-');
    ASSERT_FALSE(fc.is_alive());
    ASSERT_EQ(fc.display(), '-');
}

TEST(FredkinCell_constructor, other) { //Will still be alive FC
    FredkinCell fc = FredkinCell('*');
    ASSERT_TRUE(fc.is_alive());
    ASSERT_EQ(fc.display(), '0');
}

// -------------------------
// FredkinCell_display tests
// -------------------------

TEST(FredkinCell_display, alive_number_0) {
    FredkinCell fc = FredkinCell('0');
    ASSERT_EQ(fc.display(), '0');
}

TEST(FredkinCell_display, alive_number_9) {
    FredkinCell fc = FredkinCell('9');
    ASSERT_EQ(fc.display(), '9');
}

TEST(FredkinCell_display, alive_plus) {
    FredkinCell fc = FredkinCell('+');
    ASSERT_EQ(fc.display(), '+');
}

TEST(FredkinCell_display, dead) {
    FredkinCell fc = FredkinCell('-');
    ASSERT_EQ(fc.display(), '-');
}

// ------------------------------
// FredkinCell_check_evolve tests
// ------------------------------

TEST(FredkinCell_check_evolve, dead_not_evolve) {
    FredkinCell fc_alive = FredkinCell('0');
    FredkinCell fc_dead = FredkinCell('-');
    vector<AbstractCell*> neighbors = {&fc_alive, &fc_dead, &fc_dead,
                                       &fc_alive, nullptr, &fc_alive,
                                        nullptr, nullptr, nullptr};
    FredkinCell fc = FredkinCell('-');
    ASSERT_FALSE(fc.check_evolve(neighbors));
}

TEST(FredkinCell_check_evolve, dead_evolve) {
    FredkinCell fc_alive = FredkinCell('+');
    FredkinCell fc_dead = FredkinCell('-');
    vector<AbstractCell*> neighbors = {&fc_dead, &fc_dead, &fc_dead,
                                       &fc_alive, nullptr, &fc_alive,
                                       &fc_alive, &fc_alive, &fc_dead};
    FredkinCell fc = FredkinCell('-');
    ASSERT_TRUE(fc.check_evolve(neighbors));
}

TEST(FredkinCell_check_evolve, alive_not_evolve) {
    FredkinCell fc_alive = FredkinCell('9');
    FredkinCell fc_dead = FredkinCell('-');
    vector<AbstractCell*> neighbors = {nullptr, nullptr, nullptr,
                                       &fc_alive, nullptr, &fc_alive,
                                       &fc_dead, &fc_alive, &fc_alive};
    FredkinCell fc = FredkinCell('+');
    ASSERT_FALSE(fc.check_evolve(neighbors));
}

TEST(FredkinCell_check_evolve, alive_evolve) {
    FredkinCell fc_alive = FredkinCell('0');
    FredkinCell fc_dead = FredkinCell('-');
    vector<AbstractCell*> neighbors = {nullptr, nullptr, nullptr,
                                       nullptr, nullptr, &fc_dead,
                                       &fc_alive, &fc_dead, &fc_alive};
    FredkinCell fc = FredkinCell ('0');
    ASSERT_TRUE(fc.check_evolve(neighbors));
}

// -----------------
// FredkinCell_clone
// -----------------

TEST(FredkinCell_clone, test_alive) {
    FredkinCell fc = FredkinCell('0');
    AbstractCell* fc_clone = fc.clone();
    ASSERT_EQ(fc.display(), fc_clone->display());
    delete fc_clone;
}

TEST(FredkinCell_clone, test_alive_plus) {
    FredkinCell fc = FredkinCell('+');
    AbstractCell* fc_clone = fc.clone();
    ASSERT_EQ(fc.display(), fc_clone->display());
    delete fc_clone;
}

TEST(FredkinCell_clone, test_dead) {
    FredkinCell fc = FredkinCell('-');
    AbstractCell* fc_clone = fc.clone();
    ASSERT_EQ(fc.display(), fc_clone->display());
    delete fc_clone;
}

// ----------------
// Testing for Cell
// ----------------

// ---------------------
// Cell copy constructor
// ---------------------

TEST(Cell_copy_constructor, copy_alive_cc) {
    Cell alive_cc = Cell('*');
    Cell ce = Cell (alive_cc);
    ASSERT_EQ(ce.display(), '*');
}

TEST(Cell_copy_constructor, copy_dead_cc) {
    Cell dead_cc = Cell('.');
    Cell ce = Cell(dead_cc);
    ASSERT_EQ(ce.display(), '.');
}

TEST(Cell_copy_constructor, copy_alive_fc) {
    Cell alive_fc = Cell('9');
    Cell ce = Cell(alive_fc);
    ASSERT_EQ(ce.display(), '9');
}

TEST(Cell_copy_constructor, copt_alive_fc_2) {
    Cell alive_fc = Cell('+');
    Cell ce = Cell(alive_fc);
    ASSERT_EQ(ce.display(), '+');
}

TEST(Cell_copy_constructor, copy_dead_fc) {
    Cell dead_fc = Cell('-');
    Cell ce = Cell(dead_fc);
    ASSERT_EQ(ce.display(), '-');
}

// --------------------
// Cell copy assignment
// --------------------

TEST(Cell_copy_assignment, copy_assignment_alive_cc) {
    Cell alive_cc = Cell('*');
    Cell cc = alive_cc;
    ASSERT_EQ(cc.display(), '*');
}

TEST(Cell_copy_assignment, copy_assignment_dead_cc) {
    Cell dead_cc = Cell('.');
    Cell cc = dead_cc;
    ASSERT_EQ(cc.display(), '.');
}

TEST(Cell_copy_assignment, copy_assignment_alive_fc) {
    Cell alive_fc = Cell ('0');
    Cell cc = alive_fc;
    ASSERT_EQ(cc.display(), '0');
}

TEST(Cell_copy_assignment, copy_assignment_alive_fc_2) {
    Cell alive_fc = Cell('+');
    Cell cc = alive_fc;
    ASSERT_EQ(cc.display(), '+');
}

TEST(Cell_copy_assignment, copy_assignment_dead_fc) {
    Cell dead_fc = Cell('-');
    Cell cc = dead_fc;
    ASSERT_EQ(cc.display(), '-');
}

// -----------
// Cell toggle
// -----------

TEST(Cell_toggle, CC_alive) {
    Cell cc = Cell('*');
    cc.toggle();
    ASSERT_FALSE(cc.is_alive());
}

TEST(Cell_toggle, CC_dead) {
    Cell cc = Cell('.');
    cc.toggle();
    ASSERT_TRUE(cc.is_alive());
}

TEST(Cell_toggle, FC_alive) {
    Cell fc = Cell('9');
    fc.toggle();
    ASSERT_FALSE(fc.is_alive());
}

TEST(Cell_toggle, FC_dead) {
    Cell fc = Cell('-');
    fc.toggle();
    ASSERT_TRUE(fc.is_alive());
}

// ------------
// Cell display
// ------------

TEST(Cell_display, CC_1) {
    Cell ce = Cell('*');
    ASSERT_EQ(ce.display(), '*');
}

TEST(Cell_display, CC_2) {
    Cell ce = Cell('.');
    ASSERT_EQ(ce.display(), '.');
}

TEST(Cell_display, FC_1) {
    Cell ce = Cell('+');
    ASSERT_EQ(ce.display(), '+');
}

TEST(Cell_display, FC_2) {
    Cell ce = Cell('0');
    ASSERT_EQ(ce.display(), '0');
}

TEST(Cell_display, FC_3) {
    Cell ce = Cell('-');
    ASSERT_EQ(ce.display(), '-');
}

// -----------------
// Cell check_evolve
// -----------------

TEST(Cell_check_evolve, FC_to_CC) {
    Cell ce = Cell('1');
    ConwayCell alive_ce = ConwayCell('*');
    vector<AbstractCell*> neighbors = {nullptr, &alive_ce, nullptr,
                                       nullptr, nullptr, nullptr,
                                       nullptr, nullptr, nullptr};
    bool result = ce.check_evolve(neighbors);
    ASSERT_FALSE(result);
    ASSERT_EQ(ce.display(), '*');
}

TEST(Cell_check_evolve, become_dead_CC) {
    Cell ce = Cell('*');
    FredkinCell alive_fc = FredkinCell('+');
    vector<AbstractCell*> neighbors = {&alive_fc, &alive_fc, &alive_fc,
                                       &alive_fc, nullptr, &alive_fc,
                                       &alive_fc, &alive_fc, &alive_fc};
    ASSERT_TRUE(ce.check_evolve(neighbors));
}

TEST(Cell_check_evolve, become_alive_FC) {
    Cell ce = Cell('-');
    ConwayCell alive_cc = ConwayCell('*');
    vector<AbstractCell*> neighbors = {nullptr, &alive_cc, &alive_cc,
                                       &alive_cc, nullptr, &alive_cc,
                                       nullptr, nullptr, nullptr};
    ASSERT_TRUE(ce.check_evolve(neighbors));
}

// -------------
// Cell is_alive
// -------------

TEST(Cell_is_alive, CC_alive) {
    Cell ce = Cell('*');
    ASSERT_TRUE(ce.is_alive());
}

TEST(Cell_is_alive, CC_dead) {
    Cell ce = Cell('.');
    ASSERT_FALSE(ce.is_alive());
}

TEST(Cell_is_alive, FC_alive) {
    Cell ce = Cell('9');
    ASSERT_TRUE(ce.is_alive());
}

TEST(Cell_is_alive, FC_dead) {
    Cell ce = Cell('-');
    ASSERT_FALSE(ce.is_alive());
}


// ----------
// Life tests
// ----------

// ------------------------
// Life istream constructor
// ------------------------

TEST(Life_constructor, cc_2) {
    stringstream input("3 4\n*...\n.*..\n....\n");
    Life<ConwayCell> test(input);
    ASSERT_EQ(test._row, 3);
    ASSERT_EQ(test._col, 4);
    ASSERT_EQ(test._population, 2);
    ASSERT_EQ(test._generation, 0);
}

TEST(Life_constructor, fc_1) {
    stringstream input("4 3\n---\n---\n--0\n---\n");
    Life<FredkinCell> test(input);
    ASSERT_EQ(test._row, 4);
    ASSERT_EQ(test._col, 3);
    ASSERT_EQ(test._population, 1);
    ASSERT_EQ(test._generation, 0);
}

TEST(Life_constructor, ce) {
    stringstream input("4 5\n.*.*.\n0-3-5\n.+++.\n--..-\n");
    Life<Cell> test(input);
    ASSERT_EQ(test._row, 4);
    ASSERT_EQ(test._col, 5);
    ASSERT_EQ(test._population, 8);
    ASSERT_EQ(test._generation, 0);
}

// ------------------
// Life display_world
// ------------------

TEST(Life_display_world, line) {
    stringstream input("14 1\n0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n+\n-\n*\n.\n");
    Life<Cell> test(input);
    stringstream output;
    test.display_world(0, output);
    ASSERT_EQ("Generation = 0, Population = 12.\n0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n+\n-\n*\n.\n\n", output.str());
}

TEST(Life_display_world, 2x2) {
    stringstream input("2 2\n.*\n*.\n");
    Life<Cell> test(input);
    stringstream output;
    test.display_world(1, output);
    ASSERT_EQ("Generation = 1, Population = 0.\n..\n..\n\n", output.str());
}

TEST(Life_display_world, 3x3) {
    stringstream input("3 3\n..*\n.+.\n*..\n");
    Life<Cell> test(input);
    stringstream output;
    test.display_world(1, output);
    ASSERT_EQ("Generation = 1, Population = 0.\n...\n.-.\n...\n\n", output.str());
}
