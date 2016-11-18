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


// ---------
// conway constructor
// ---------
TEST(LifeFixture, ConwayCell_constructor_1){
	ConwayCell cc;
	ASSERT_FALSE(cc._alive);
}

TEST(LifeFixture, ConwayCell_constructor_2){
	ConwayCell cc;
	ASSERT_EQ(cc._sym, '.');
}


TEST(LifeFixture, ConwayCell_constructor_3){
	ConwayCell cc(true, '*');
	ASSERT_TRUE(cc._alive);
}

TEST(LifeFixture, ConwayCell_constructor_4){
	ConwayCell cc(true, '*');
	ASSERT_EQ(cc._sym, '*');
}

TEST(LifeFixture, ConwayCell_constructor_5){
	ConwayCell cc(false, '.');
	ASSERT_FALSE(cc._alive);
}


TEST(LifeFixture, ConwayCell_constructor_6){
	ConwayCell cc(false, '.');
	ASSERT_EQ(cc._sym, '.');
}

// ---------
// evolve_CC
// ---------

TEST(LifeFixture, evolve_CC_1) {
    ConwayCell cc;
    cc.evolve(3, false, nullptr);
    ASSERT_TRUE(cc.check_alive());

}

TEST(LifeFixture, evolve_CC_2) {
    ConwayCell cc;
    cc.evolve(2, false, nullptr);
    ASSERT_FALSE(cc.check_alive());

}

TEST(LifeFixture, evolve_CC_3) {
    ConwayCell cc(true, '*');
    cc.evolve(4, false, nullptr);
    ASSERT_FALSE(cc.check_alive());

}

TEST(LifeFixture, evolve_CC_4) {
    ConwayCell cc(true, '*');
    cc.evolve(3, false, nullptr);
    ASSERT_TRUE(cc.check_alive());

}

TEST(LifeFixture, evolve_CC_5) {
    ConwayCell cc(true, '*');
    cc.evolve(2, false, nullptr);
    ASSERT_TRUE(cc.check_alive());
}

TEST(LifeFixture, evolve_CC_6) {
    ConwayCell cc(true, '*');
    cc.evolve(1, false, nullptr);
    ASSERT_FALSE(cc.check_alive());

}

// --------
// clone_CC
// --------
TEST(LifeFixture, clone_CC_1){
	ConwayCell cc(true, '*');
	Cell cp(cc.clone());
	ASSERT_TRUE(cp.check_alive());

}

TEST(LifeFixture, clone_CC_2){
	ConwayCell cc;
	Cell cp(cc.clone());
	ASSERT_FALSE(cp.check_alive());

}

TEST(LifeFixture, clone_CC_3){
	ConwayCell cc(false, '-');
	Cell cp(cc.clone());
	ASSERT_FALSE(cp.check_alive());

}

// --------------
// check_alive_CC
// --------------
TEST(LifeFixture, check_alive_1){
	ConwayCell cc;
	ASSERT_FALSE(cc.check_alive());
}

TEST(LifeFixture, check_alive_2){
	ConwayCell cc(true, '*');
	ASSERT_TRUE(cc.check_alive());
}

TEST(LifeFixture, check_alive_3){
	ConwayCell cc(false, '-');
	ASSERT_FALSE(cc.check_alive());
}




// ---------------
// include_diag_CC
// ---------------
TEST(LifeFixture, include_diag_CC_1)
{
	ConwayCell cc(true, '*');
	ASSERT_TRUE(cc.include_diag());
}

TEST(LifeFixture, include_diag_CC_2)
{
	ConwayCell cc;
	ASSERT_TRUE(cc.include_diag());
}


// ------------
// print_sym_CC
// ------------

// TEST(LifeFixture, print_sym_CC_1)
// {

// }

// ---------
// evolve_FC
// ---------
TEST(LifeFixture, FredkinCell_constructor_1){
	FredkinCell fc;
	ASSERT_FALSE(fc._alive);
}

TEST(LifeFixture, FredkinCell_constructor_2){
	FredkinCell fc;
	ASSERT_EQ(fc._sym, '-');
}


TEST(LifeFixture, FredkinCell_constructor_3){
FredkinCell fc(true, '+');
	ASSERT_TRUE(fc._alive);
}

TEST(LifeFixture, FredkinCell_constructor_4){
FredkinCell fc(true, '+');
	ASSERT_EQ(fc._sym, '+');
}

TEST(LifeFixture, FredkinCell_constructor_5){
FredkinCell fc(false, '-');
	ASSERT_FALSE(fc._alive);
}


TEST(LifeFixture, FredkinCell_constructor_6){
FredkinCell fc(false, '-');
	ASSERT_EQ(fc._sym, '-');
}

TEST(LifeFixture, FredkinCell_constructor_7){
FredkinCell fc(true, '0');
	ASSERT_EQ(fc._sym, '0');
}

TEST(LifeFixture, FredkinCell_constructor_8){
FredkinCell fc(true, '0');
	ASSERT_EQ(fc._age, 0);
}

TEST(LifeFixture, FredkinCell_constructor_9){
FredkinCell fc;
	ASSERT_EQ(fc._age, 0);
}


// ---------
// evolve_FC
// ---------

TEST(LifeFixture, evolve_FC_1){
	FredkinCell fc;
    fc.evolve(1, false, nullptr);
    ASSERT_TRUE(fc.check_alive());

}

TEST(LifeFixture, evolve_FC_2){
	FredkinCell fc;
    fc.evolve(3, false, nullptr);
    ASSERT_TRUE(fc.check_alive());

}


TEST(LifeFixture, evolve_FC_3){
	FredkinCell fc(true, '+');
    fc.evolve(0, false, nullptr);
    ASSERT_FALSE(fc.check_alive());

}

TEST(LifeFixture, evolve_FC_4){
	FredkinCell fc(true, '+');
    fc.evolve(2, false, nullptr);
    ASSERT_FALSE(fc.check_alive());

}

TEST(LifeFixture, evolve_FC_5){
	FredkinCell fc(true, '+');
    fc.evolve(4, false, nullptr);
    ASSERT_FALSE(fc.check_alive());

}

TEST(LifeFixture, evolve_FC_6){
	FredkinCell fc(true, '0');
    fc.evolve(3, false, nullptr);
    ASSERT_EQ(fc._age, 1);

}

TEST(LifeFixture, evolve_FC_7){
	FredkinCell fc;
    fc.evolve(3, false, nullptr);
    ASSERT_EQ(fc._age, 0);

}

TEST(LifeFixture, evolve_FC_8){
	FredkinCell fc(true, '0');
    fc.evolve(0, false, nullptr);
    ASSERT_EQ(fc._age, 0);

}
// --------
// clone_FC
// --------
TEST(LifeFixture, clone_FC_1){
	FredkinCell fc(true, '+');
	Cell cp(fc.clone());
	ASSERT_TRUE(cp.check_alive());

}

TEST(LifeFixture, clone_FC_2){
	FredkinCell fc;
	Cell cp(fc.clone());
	ASSERT_FALSE(cp.check_alive());

}

// --------------
// check_alive_FC
// --------------
TEST(LifeFixture, check_alive_FC_1){
	FredkinCell fc(true, '+');
	ASSERT_TRUE(fc.check_alive());

}

TEST(LifeFixture, check_alive_FC_2){
	FredkinCell fc(false, '-');
	ASSERT_FALSE(fc.check_alive());

}

TEST(LifeFixture, check_alive_FC_3){
	FredkinCell fc;
	ASSERT_FALSE(fc.check_alive());

}

// ---------------
// include_diag_FC
// ---------------

TEST(LifeFixture, include_diag_FC_1)
{
	FredkinCell fc(true, '+');
	ASSERT_FALSE(fc.include_diag());
}

TEST(LifeFixture, include_diag_FC_2)
{
	FredkinCell fc;
	ASSERT_FALSE(fc.include_diag());
}


// -------------
// print_sym_FC
// -------------

// --------
// evolve_C
// --------
TEST(LifeFixture, evovle_C_1) {
	ConwayCell cc(true, '*');
	Cell cp(cc.clone());
	cp.evolve(1, true, nullptr);
	ASSERT_FALSE(cp.check_alive());
}

TEST(LifeFixture, evovle_C_2) {
	ConwayCell cc(true, '*');
	Cell cp(cc.clone());
	cp.evolve(1, true, nullptr);
	ASSERT_FALSE(cp.check_alive());
}

TEST(LifeFixture, evovle_C_3) {
	FredkinCell cc(true, '1');
	Cell cp(cc.clone());
	cp.evolve(1, true, nullptr);
	ASSERT_TRUE(cp.check_alive());
}

TEST(LifeFixture, evovle_C_4) {
	FredkinCell cc(true, '-');
	Cell cp(cc.clone());
	cp.evolve(1, true, nullptr);
	ASSERT_TRUE(cp.check_alive());
}

// -------------
// check_alive_C
// -------------
TEST(LifeFixture, check_alive_C_1) {
	ConwayCell cc(true, '*');
	Cell cp(cc.clone());
	ASSERT_TRUE(cp.check_alive());
}

TEST(LifeFixture, check_alive_C_2) {
	ConwayCell cc(false, '.');
	Cell cp(cc.clone());
	ASSERT_FALSE(cp.check_alive());
}

TEST(LifeFixture, check_alive_C_3) {
	FredkinCell cc(true, '0');
	Cell cp(cc.clone());
	ASSERT_TRUE(cp.check_alive());
}

TEST(LifeFixture, check_alive_C_4) {
	FredkinCell cc(false, '-');
	Cell cp(cc.clone());
	ASSERT_FALSE(cp.check_alive());
}

// ---------------
// include_diag_C
// ---------------
TEST(LifeFixture, include_diag_C_1) {
	ConwayCell cc(true, '*');
	Cell cp(cc.clone());
	ASSERT_TRUE(cp.include_diag());
}

TEST(LifeFixture, include_diag_C_2) {
	ConwayCell cc(false, '.');
	Cell cp(cc.clone());
	ASSERT_TRUE(cp.include_diag());
}

TEST(LifeFixture, include_diag_C_3) {
	FredkinCell cc(true, '0');
	Cell cp(cc.clone());
	ASSERT_FALSE(cp.include_diag());
}

TEST(LifeFixture, include_diag_C_4) {
	FredkinCell cc(false, '-');
	Cell cp(cc.clone());
	ASSERT_FALSE(cp.include_diag());
}

// ---------
// character
// ---------

TEST(LifeFixture, character_1)
{
	FredkinCell fc(false, '+');
	fc.character();
	ASSERT_EQ(fc._sym, '-');
}

TEST(LifeFixture, character_2)
{
	FredkinCell fc(true, '9');
	fc._age = 10;
	fc.character();
	ASSERT_EQ(fc._sym, '+');
}

TEST(LifeFixture, character_3)
{
	FredkinCell fc(true, '4');
	fc._age = 5;
	fc.character();
	ASSERT_EQ(fc._sym, '5');
}

// -----------
// print_sym_C
// -----------

// -----
// add
// -----

TEST(LifeFixture, add_1) {
	Life<ConwayCell> l;
	vector<ConwayCell*> v;
	ConwayCell cc(false, '.');
	v.push_back(cc.clone());
	l.add(v);
	ASSERT_FALSE(l._board[0][0]->check_alive());	
}

TEST(LifeFixture, add_2) {
	Life<ConwayCell> l;
	vector<ConwayCell*> v;
	ConwayCell cc1(false, '.');
	ConwayCell cc2(true, '*');
	v.push_back(cc1.clone());
	v.push_back(cc2.clone());
	l.add(v);
	ASSERT_TRUE(l._board[0][1]->check_alive());	
}

TEST(LifeFixture, add_3) {
	Life<ConwayCell> l;
	vector<ConwayCell*> v;
	ConwayCell cc1(false, '.');
	ConwayCell cc2(true, '*');
	v.push_back(cc1.clone());
	v.push_back(cc2.clone());
	l.add(v);
	ASSERT_FALSE(l._board[0][0]->check_alive());	
}

// --------
// evolve_L
// --------
TEST(LifeFixture, evolve_L_1) {
	Life<ConwayCell> l;
	vector<ConwayCell*> v1;
	vector<ConwayCell*> v2;
	ConwayCell cc1(true, '*');
	ConwayCell cc2(false, '.');
	ConwayCell cc3(false, '.');
	ConwayCell cc4(false, '.');
	v1.push_back(cc1.clone());
	v1.push_back(cc2.clone());
	v2.push_back(cc3.clone());
	v2.push_back(cc4.clone());
	l.add(v1);
	l.add(v2);
	l.set_neighbors();
	l.evolve();
	ASSERT_FALSE(l._board[0][0]->check_alive());	
}

TEST(LifeFixture, evolve_L_2) {
	Life<ConwayCell> l;
	vector<ConwayCell*> v1;
	vector<ConwayCell*> v2;
	ConwayCell cc1(true, '*');
	ConwayCell cc2(true, '*');
	ConwayCell cc3(false, '.');
	ConwayCell cc4(false, '.');
	v1.push_back(cc1.clone());
	v1.push_back(cc2.clone());
	v2.push_back(cc3.clone());
	v2.push_back(cc4.clone());
	l.add(v1);
	l.add(v2);
	l.set_neighbors();
	l.evolve();
	ASSERT_FALSE(l._board[0][0]->check_alive());	
}

TEST(LifeFixture, evolve_L_3) {
	Life<ConwayCell> l;
	vector<ConwayCell*> v1;
	vector<ConwayCell*> v2;
	ConwayCell cc1(true, '*');
	ConwayCell cc2(false, '.');
	ConwayCell cc3(true, '*');
	ConwayCell cc4(true, '*');
	v1.push_back(cc1.clone());
	v1.push_back(cc2.clone());
	v2.push_back(cc3.clone());
	v2.push_back(cc4.clone());
	l.add(v1);
	l.add(v2);
	l.set_neighbors();
	l.evolve();
	ASSERT_TRUE(l._board[0][0]->check_alive());	
}
// -------------
// set_neighbors
// -------------

TEST(LifeFixture, set_neighbors_1) {
	Life<ConwayCell> l;
	vector<ConwayCell*> v1;
	vector<ConwayCell*> v2;
	ConwayCell cc1(true, '*');
	ConwayCell cc2(false, '.');
	ConwayCell cc3(true, '*');
	ConwayCell cc4(true, '*');
	v1.push_back(cc1.clone());
	v1.push_back(cc2.clone());
	v2.push_back(cc3.clone());
	v2.push_back(cc4.clone());
	l.add(v1);
	l.add(v2);
	l.set_neighbors();
	ASSERT_TRUE(l._n_Count[0][0] == 2);	
}

TEST(LifeFixture, set_neighbors_2) {
	Life<ConwayCell> l;
	vector<ConwayCell*> v1;
	vector<ConwayCell*> v2;
	ConwayCell cc1(true, '*');
	ConwayCell cc2(false, '.');
	ConwayCell cc3(false, '.');
	ConwayCell cc4(false, '.');
	v1.push_back(cc1.clone());
	v1.push_back(cc2.clone());
	v2.push_back(cc3.clone());
	v2.push_back(cc4.clone());
	l.add(v1);
	l.add(v2);
	l.set_neighbors();
	ASSERT_TRUE(l._n_Count[0][0] == 0);	
}

TEST(LifeFixture, set_neighbors_3) {
	Life<ConwayCell> l;
	vector<ConwayCell*> v1;
	vector<ConwayCell*> v2;
	ConwayCell cc1(true, '*');
	ConwayCell cc2(false, '.');
	ConwayCell cc3(true, '*');
	ConwayCell cc4(false, '.');
	v1.push_back(cc1.clone());
	v1.push_back(cc2.clone());
	v2.push_back(cc3.clone());
	v2.push_back(cc4.clone());
	l.add(v1);
	l.add(v2);
	l.set_neighbors();
	ASSERT_TRUE(l._n_Count[0][0] == 1);	
}

// ---------
// total_pop
// ---------

TEST(LifeFixture, total_pop_1) {
	Life<ConwayCell> l;
	vector<ConwayCell*> v1;
	vector<ConwayCell*> v2;
	ConwayCell cc1(true, '*');
	ConwayCell cc2(false, '.');
	ConwayCell cc3(true, '*');
	ConwayCell cc4(false, '.');
	v1.push_back(cc1.clone());
	v1.push_back(cc2.clone());
	v2.push_back(cc3.clone());
	v2.push_back(cc4.clone());
	l.add(v1);
	l.add(v2);
	ASSERT_TRUE(l.total_pop() == 2);
}

TEST(LifeFixture, total_pop_2) {
	Life<ConwayCell> l;
	vector<ConwayCell*> v1;
	vector<ConwayCell*> v2;
	ConwayCell cc1(true, '*');
	ConwayCell cc2(false, '.');
	ConwayCell cc3(true, '*');
	ConwayCell cc4(true, '*');
	v1.push_back(cc1.clone());
	v1.push_back(cc2.clone());
	v2.push_back(cc3.clone());
	v2.push_back(cc4.clone());
	l.add(v1);
	l.add(v2);
	ASSERT_TRUE(l.total_pop() == 3);
}

TEST(LifeFixture, total_pop_3) {
	Life<ConwayCell> l;
	vector<ConwayCell*> v1;
	vector<ConwayCell*> v2;
	ConwayCell cc1(false, '.');
	ConwayCell cc2(false, '.');
	ConwayCell cc3(false, '*');
	ConwayCell cc4(false, '.');
	v1.push_back(cc1.clone());
	v1.push_back(cc2.clone());
	v2.push_back(cc3.clone());
	v2.push_back(cc4.clone());
	l.add(v1);
	l.add(v2);
	ASSERT_TRUE(l.total_pop() == 0);
}