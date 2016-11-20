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
#include <string>

#include "Life.h"

using namespace std;

// ------------------
// ConwayCell Fixture
// ------------------

TEST(CCFixture, cc_constructor_1) {
    ConwayCell cc('r');
    ASSERT_EQ(cc.state, 'r');
}

TEST(CCFixture, cc_constructor_2) {
    ConwayCell cc('d');
    ASSERT_EQ(cc.state, 'd');

}

TEST(CCFixture, cc_constructor_3) {
    ConwayCell cc('.');
    ASSERT_EQ(cc.state, '.');
}

TEST(CCFixture, cc_process_1) {
    ConwayCell cc('.');
    cc.process(1, true);
    ASSERT_EQ(cc.state, '.');
}

TEST(CCFixture, cc_process_2) {
    ConwayCell cc('*');
    cc.process(2, true);
    ASSERT_EQ(cc.state, '*');
}

TEST(CCFixture, cc_process_3) {
    ConwayCell cc('.');
    cc.process(8, false);
    ASSERT_EQ(cc.state, '.');
}

TEST(CCFixture, cc_is_alive_1) {
    ConwayCell cc('*');
    ASSERT_EQ(cc.is_alive(), true);
}

TEST(CCFixture, cc_is_alive_2) {
    ConwayCell cc('7');
    ASSERT_EQ(cc.is_alive(), false);
}

TEST(CCFixture, cc_mutate_1) {
    ConwayCell cc('0');
    ASSERT_EQ(cc.mutate(), nullptr);
}

TEST(CCFixture, cc_print_1) {
    ConwayCell cc('8');
    ostringstream os;
    cc.print(os);
    ASSERT_EQ("8", os.str());
}

TEST(CCFixture, cc_print_2) {
    ConwayCell cc1('8');
    ConwayCell cc2('3');
    ostringstream os;
    cc1.print(os);
    cc2.print(os);
    ASSERT_EQ("83", os.str());
}

// -------------------
// FredkinCell Fixture
// -------------------

TEST(FCFixture, fc_constructor_1) {
    FredkinCell fc('r');
    ASSERT_EQ(fc.state, 'r');
}

TEST(FCFixture, fc_constructor_2) {
    FredkinCell fc('3');
    ASSERT_EQ(fc.age, 3);
}

TEST(FCFixture, fc_constructor_3) {
    FredkinCell fc('+');
    ASSERT_EQ(fc.age, 10);
}

TEST(FCFixture, fc_constructor_4) {
    FredkinCell fc('-');
    ASSERT_EQ(fc.state, '-');
    ASSERT_EQ(fc.age, 0);
}

TEST(FCFixture, fc_process_1) {
    FredkinCell fc('3');
    fc.process(2, true);
    ASSERT_EQ(fc.state, '-');
}

TEST(FCFixture, fc_process_2) {
    FredkinCell fc('-');
    fc.process(2, false);
    ASSERT_EQ(fc.state, '-');
}

TEST(FCFixture, fc_process_3) {
    FredkinCell fc('+');
    fc.process(3, true);
    ASSERT_EQ(fc.age, 11);
}

TEST(FCFixture, fc_is_alive_1) {
    FredkinCell fc('+');
    ASSERT_EQ(fc.is_alive(), true);
}

TEST(FCFixture, fc_is_alive_2) {
    FredkinCell fc('-');
    ASSERT_EQ(fc.is_alive(), false);
}

TEST(FCFixture, fc_print_1) {
    FredkinCell fc('+');
    ostringstream os;
    fc.print(os);
    ASSERT_EQ("+", os.str());
}

TEST(FCFixture, fc_print_2) {
    FredkinCell fc1('8');
    FredkinCell fc2('3');
    ostringstream os;
    fc1.print(os);
    fc2.print(os);
    ASSERT_EQ("83", os.str());
}

// ------------
// Cell Fixture
// ------------

TEST(CFixture, c_constructor_1) {
    Cell c('-');
    FredkinCell* const cp = dynamic_cast<FredkinCell*>(c.ac);
    ASSERT_NE(cp, nullptr);
}

TEST(CFixture, c_constructor_2) {
    Cell c('*');
    ConwayCell * const cp = dynamic_cast<ConwayCell*>(c.ac);
    ASSERT_NE(cp, nullptr);
}

TEST(CFixture, c_constructor_3) {
    Cell c('a');
    FredkinCell* const cp = dynamic_cast<FredkinCell*>(c.ac);
    ASSERT_NE(cp, nullptr);
}

TEST(CFixture, c_copy_constructor_1) {
    Cell c1('-');
    Cell c2(c1);
    ASSERT_EQ(c1.ac->state, c2.ac->state);
}

TEST(CFixture, c_copy_constructor_2) {
    Cell c1('*');
    Cell c2(c1);
    ConwayCell * const cp1 = dynamic_cast<ConwayCell*>(c1.ac);
    ConwayCell * const cp2 = dynamic_cast<ConwayCell*>(c2.ac);
    ASSERT_NE(cp1, cp2);
}

TEST(CFixture, c_process_1) {
    Cell c('-');
    c.process(3, false);
    ASSERT_EQ(c.ac->state, '0');
}

TEST(CFixture, c_process_2) {
    Cell c('*');
    c.process(3, true);
    ASSERT_EQ(c.ac->state, '*');
}

TEST(CFixture, c_process_3) {
    Cell c('.');
    c.process(1, false);
    ASSERT_EQ(c.ac->state, '.');
}

TEST(CFixture, c_is_alive_1) {
    Cell c('-');
    ASSERT_EQ(c.is_alive(), false);
}

TEST(CFixture, c_is_alive_2) {
    Cell c('*');
    ASSERT_EQ(c.is_alive(), true);
}

TEST(CFixture, c_is_alive_3) {
    Cell c('.');
    ASSERT_EQ(c.is_alive(), false);
}

TEST(CFixture, c_is_alive_4) {
    Cell c('5');
    ASSERT_EQ(c.is_alive(), true);
}

TEST(CFixture, c_is_alive_5) {
    Cell c('+');
    ASSERT_EQ(c.is_alive(), true);
}

TEST(CFixture, c_print_1) {
    Cell c('+');
    ostringstream os;
    c.print(os);
    ASSERT_EQ("+", os.str());
}

TEST(CFixture, c_print_2) {
    Cell c('*');
    ostringstream os;
    c.print(os);
    ASSERT_EQ("*", os.str());
}

TEST(CFixture, c_print_3) {
    Cell c('3');
    Cell c2('.');
    ostringstream os;
    c.print(os);
    c2.print(os);
    ASSERT_EQ("3.", os.str());
}

TEST(CFixture, c_is_conway_1) {
    Cell c('-');
    ASSERT_EQ(c.is_conway(), false);
}

TEST(CFixture, c_is_conway_2) {
    Cell c('*');
    ASSERT_EQ(c.is_conway(), true);
}

TEST(CFixture, c_is_conway_3) {
    Cell c('.');
    ASSERT_EQ(c.is_conway(), true);
}

TEST(CFixture, c_is_conway_4) {
    Cell c('3');
    ASSERT_EQ(c.is_conway(), false);
}

TEST(CFixture, c_is_conway_5) {
    Cell c('+');
    ASSERT_EQ(c.is_conway(), false);
}

// -----------------------
// Life ConwayCell Fixture
// -----------------------

TEST(LifeFixture, life_constructor_1) {
    string input = "*";
    istringstream is (input);
    Life<ConwayCell> b1(1,1,is);
    ASSERT_EQ(b1.row, 1);
}

TEST(LifeFixture, life_constructor_2) {
    string input = "*";
    istringstream is (input);
    Life<ConwayCell> b1(1,1,is);
    ASSERT_EQ(b1.col, 1);
}

TEST(LifeFixture, life_constructor_3) {
    string input = "*";
    istringstream is (input);
    Life<ConwayCell> b1(1,1,is);
    ostringstream os;
    os << b1;
    ASSERT_EQ("Generation = 0, Population = 1.\n*\n\n", os.str());
}

TEST(LifeFixture, life_constructor_4) {
    string input = "*";
    istringstream is (input);
    Life<ConwayCell> b1(1,1,is);
    ASSERT_EQ(b1.population, 0);
}

TEST(LifeFixture, life_print_1) {
    string input = "*";
    istringstream is(input);
    Life<ConwayCell> b1(1,1,is);
    ostringstream os;
    os << b1;
    ASSERT_EQ("Generation = 0, Population = 1.\n*\n\n", os.str());
}

TEST(LifeFixture, life_print_2) {
    string input = ".";
    istringstream is(input);
    Life<ConwayCell> b1(1,1,is);
    ostringstream os;
    os << b1;
    ASSERT_EQ("Generation = 0, Population = 0.\n.\n\n", os.str());
}

TEST(LifeFixture, life_print_3) {
    string input = "*";
    istringstream is(input);
    Life<ConwayCell> b1(1,1,is);
    ostringstream os;
    os << b1;
    ASSERT_EQ("Generation = 0, Population = 1.\n*\n\n", os.str());
}

TEST(LifeFixture, life_run_1) {
    string input = "*";
    istringstream is(input);
    Life<ConwayCell> b1(1,1,is);
    b1.run();
    ostringstream os;
    os << b1;
    ASSERT_EQ("Generation = 1, Population = 0.\n.\n\n", os.str());
}


TEST(LifeFixture, life_run_2) {
    string input = "*.*.**";
    istringstream is(input);
    Life<ConwayCell> b1(2,3,is);
    b1.run();
    ostringstream os;
    os << b1;
    ASSERT_EQ("Generation = 1, Population = 3.\n..*\n.**\n\n", os.str());
}

TEST(LifeFixture, life_run_3) {
    string input = ".**.*.";
    istringstream is(input);
    Life<ConwayCell> b1(3,2,is);
    b1.run();
    ostringstream os;
    os << b1;
    ASSERT_EQ("Generation = 1, Population = 2.\n..\n**\n..\n\n", os.str());
}

TEST(LifeFixture, life_run_4) {
    string input = ".**.*.";
    istringstream is(input);
    Life<ConwayCell> b1(3,2,is);
    b1.run();
    b1.run();
    ostringstream os;
    os << b1;
    ASSERT_EQ("Generation = 2, Population = 0.\n..\n..\n..\n\n", os.str());
}

TEST(LifeFixture, life_run_5) {
    string input = "****";
    istringstream is(input);
    Life<ConwayCell> b1(2,2,is);
    for(int i = 0; i < 20; i++) {
        b1.run();
    }
    ostringstream os;
    os << b1;
    ASSERT_EQ("Generation = 20, Population = 4.\n**\n**\n\n", os.str());
}

TEST(LifeFixture, life_count_1) {
    string input = "****";
    istringstream is(input);
    Life<ConwayCell> b1(2,2,is);
    ASSERT_EQ(b1.count_population(), 4);
}

TEST(LifeFixture, life_count_2) {
    string input = "-0-0";
    istringstream is(input);
    Life<FredkinCell> b1(2,2,is);
    ASSERT_EQ(b1.count_population(), 2);
}

TEST(LifeFixture, life_count_3) {
    string input = "1010";
    istringstream is(input);
    Life<FredkinCell> b1(2,2,is);
    ASSERT_EQ(b1.count_population(), 4);
}

