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
#include <sstream>

using namespace std;


// -----------------------
// AbstractCell is_alive()
// -----------------------
// test AbstractCell via ConwayCell proxy, which only uses default

TEST(AbstractCellFixture, test_alive_1)
{
	ConwayCell ac(true);
    ASSERT_TRUE(ac.is_alive());
}

TEST(AbstractCellFixture, test_alive_2)
{
	ConwayCell ac(false);
    ASSERT_FALSE(ac.is_alive());
}

// test when _next does not match _alive
TEST(AbstractCellFixture, test_alive_3)
{
	ConwayCell ac(true);
    ac.next_state(false);
    ASSERT_TRUE(ac.is_alive());
}

// test when _next does not match _alive
TEST(AbstractCellFixture, test_alive_4)
{
	ConwayCell ac(false);
    ac.next_state(true);
    ASSERT_FALSE(ac.is_alive());
}

// -------------------------
// AbstractCell next_state()
// -------------------------
// test AbstractCell via ConwayCell proxy, which only uses default

TEST(AbstractCellFixture, test_next_1)
{
	ConwayCell ac(true);
	ac.next_state(true);
    ASSERT_TRUE(ac._next);
}

TEST(AbstractCellFixture, test_next_2)
{
	ConwayCell ac(false);
	ac.next_state(false);
    ASSERT_FALSE(ac._next);
}

TEST(AbstractCellFixture, test_next_3)
{
	ConwayCell ac(false);
	ac.next_state(true);
    ASSERT_TRUE(ac._next);
}

TEST(AbstractCellFixture, test_next_4)
{
	ConwayCell ac(true);
	ac.next_state(false);
    ASSERT_FALSE(ac._next);
}

// -------------------------
// AbstractCell evolve()
// -------------------------
// test AbstractCell via ConwayCell proxy, which only uses default

TEST(AbstractCellFixture, test_evolve_1)
{
	ConwayCell ac(true);
	ac.next_state(true);
	AbstractCell* ret = ac.evolve();
	ASSERT_EQ(ret, nullptr);
    ASSERT_TRUE(ac.is_alive());
}

TEST(AbstractCellFixture, test_evolve_2)
{
	ConwayCell ac(false);
	ac.next_state(false);
	AbstractCell* ret = ac.evolve();
	ASSERT_EQ(ret, nullptr);
    ASSERT_FALSE(ac.is_alive());
}

TEST(AbstractCellFixture, test_evolve_3)
{
	ConwayCell ac(false);
	ac.next_state(true);
	AbstractCell* ret = ac.evolve();
	ASSERT_EQ(ret, nullptr);
    ASSERT_TRUE(ac.is_alive());
}

TEST(AbstractCellFixture, test_evolve_4)
{
	ConwayCell ac(true);
	ac.next_state(false);
	AbstractCell* ret = ac.evolve();
	ASSERT_EQ(ret, nullptr);
    ASSERT_FALSE(ac.is_alive());
}

// ----------------------
// ConwayCell Constructor
// ----------------------

TEST(ConwayCellFixture, test_constructor_1) {
    ConwayCell ac(true);
    ASSERT_TRUE(ac._alive);
    ASSERT_TRUE(ac._next);
}

TEST(ConwayCellFixture, test_constructor_2) {
    ConwayCell ac(false);
    ASSERT_FALSE(ac._alive);
    ASSERT_FALSE(ac._next);
}

// --------------------------
// ConwayCell CopyConstructor
// --------------------------

TEST(ConwayCellFixture, test_copy_1) {
    ConwayCell ac(true);
    ConwayCell cp(ac);
    ASSERT_TRUE(cp._alive);
    ASSERT_TRUE(cp._next);
}

TEST(ConwayCellFixture, test_copy_2) {
    ConwayCell ac(false);
    ConwayCell cp(ac);
    ASSERT_FALSE(cp._alive);
    ASSERT_FALSE(cp._next);
}

TEST(ConwayCellFixture, test_copy_3) {
    ConwayCell ac(true);
    ac.next_state(false);
    ConwayCell cp(ac);
    ASSERT_TRUE(cp._alive);
    ASSERT_FALSE(cp._next);
}

TEST(ConwayCellFixture, test_copy_4) {
    ConwayCell ac(false);
    ac.next_state(true);
    ConwayCell cp(ac);
    ASSERT_FALSE(cp._alive);
    ASSERT_TRUE(cp._next);
}

// ---------------------------
// ConwayCell CalculateState()
// ---------------------------

TEST(ConwayCellFixture, test_calculate_alive_1)
{
	ConwayCell ac(true);
	//--
	ConwayCell live(true);
	ConwayCell dead(false);
	vector<GridCell> v;
	v.push_back(GridCell(Direction::North, live));
	v.push_back(GridCell(Direction::East, dead));
	v.push_back(GridCell(Direction::South, dead));
	v.push_back(GridCell(Direction::West, dead));
	v.push_back(GridCell(Direction::NorthEast, dead));
	v.push_back(GridCell(Direction::NorthWest, dead));
	v.push_back(GridCell(Direction::SouthEast, dead));
	v.push_back(GridCell(Direction::SouthWest, dead));
	//--
	ac.calculate_state(v);
	ASSERT_FALSE(ac._next);
}

TEST(ConwayCellFixture, test_calculate_alive_2)
{
	ConwayCell ac(true);
	//--
	ConwayCell live(true);
	ConwayCell dead(false);
	vector<GridCell> v;
	v.push_back(GridCell(Direction::North, live));
	v.push_back(GridCell(Direction::East, dead));
	v.push_back(GridCell(Direction::South, dead));
	v.push_back(GridCell(Direction::West, dead));
	v.push_back(GridCell(Direction::NorthEast, live));
	v.push_back(GridCell(Direction::NorthWest, dead));
	v.push_back(GridCell(Direction::SouthEast, dead));
	v.push_back(GridCell(Direction::SouthWest, dead));
	//--
	ac.calculate_state(v);
	ASSERT_TRUE(ac._next);
}

TEST(ConwayCellFixture, test_calculate_alive_4)
{
	ConwayCell ac(true);

	//--
	ConwayCell live(true);
	ConwayCell dead(false);
	vector<GridCell> v;
	v.push_back(GridCell(Direction::North, live));
	v.push_back(GridCell(Direction::East, live));
	v.push_back(GridCell(Direction::South, dead));
	v.push_back(GridCell(Direction::West, dead));
	v.push_back(GridCell(Direction::NorthEast, live));
	v.push_back(GridCell(Direction::NorthWest, live));
	v.push_back(GridCell(Direction::SouthEast, dead));
	v.push_back(GridCell(Direction::SouthWest, dead));
	//--
	ac.calculate_state(v);
	ASSERT_FALSE(ac._next);
}

TEST(ConwayCellFixture, test_calculate_dead_2)
{
	ConwayCell ac(false);

	//--
	ConwayCell live(true);
	ConwayCell dead(false);
	vector<GridCell> v;
	v.push_back(GridCell(Direction::North, live));
	v.push_back(GridCell(Direction::East, dead));
	v.push_back(GridCell(Direction::South, dead));
	v.push_back(GridCell(Direction::West, dead));
	v.push_back(GridCell(Direction::NorthEast, live));
	v.push_back(GridCell(Direction::NorthWest, dead));
	v.push_back(GridCell(Direction::SouthEast, dead));
	v.push_back(GridCell(Direction::SouthWest, dead));
	//--
	ac.calculate_state(v);
	ASSERT_FALSE(ac._next);
}

TEST(ConwayCellFixture, test_calculate_dead_3)
{
	ConwayCell ac(false);
	//--
	ConwayCell live(true);
	ConwayCell dead(false);
	vector<GridCell> v;
	v.push_back(GridCell(Direction::North, live));
	v.push_back(GridCell(Direction::East, live));
	v.push_back(GridCell(Direction::South, dead));
	v.push_back(GridCell(Direction::West, dead));
	v.push_back(GridCell(Direction::NorthEast, live));
	v.push_back(GridCell(Direction::NorthWest, dead));
	v.push_back(GridCell(Direction::SouthEast, dead));
	v.push_back(GridCell(Direction::SouthWest, dead));
	//--
	ac.calculate_state(v);
	ASSERT_TRUE(ac._next);
}

TEST(ConwayCellFixture, test_calculate_dead_4)
{
	ConwayCell ac(false);
	//--
	ConwayCell live(true);
	ConwayCell dead(false);
	vector<GridCell> v;
	v.push_back(GridCell(Direction::North, live));
	v.push_back(GridCell(Direction::East, live));
	v.push_back(GridCell(Direction::South, dead));
	v.push_back(GridCell(Direction::West, dead));
	v.push_back(GridCell(Direction::NorthEast, live));
	v.push_back(GridCell(Direction::NorthWest, live));
	v.push_back(GridCell(Direction::SouthEast, dead));
	v.push_back(GridCell(Direction::SouthWest, dead));
	//--
	ac.calculate_state(v);
	ASSERT_FALSE(ac._next);
}

// -----------------------
// ConwayCell print_cell()
// -----------------------

TEST(ConwayCellFixture, test_print_1)
{
	ConwayCell ac(false);
	ostringstream w;
	ac.print_cell(w);
	ASSERT_EQ(".", w.str());
}

TEST(ConwayCellFixture, test_print_2)
{
	ConwayCell ac(true);
	ostringstream w;
	ac.print_cell(w);
	ASSERT_EQ("*", w.str());
}

// ------------------
// ConwayCell clone()
// ------------------
// note: different style of asserting values is used
// when testing clone() to avoid potential memory leaks.

TEST(ConwayCellFixture, test_clone_1) {
    ConwayCell ac(true);
    AbstractCell* cp = ac.clone();
    if(cp != nullptr)
    {
	    bool result = cp->_alive && cp->_next;
	    ConwayCell* cc = dynamic_cast<ConwayCell*>(cp);
	    delete cp;
	    ASSERT_NE(cc, nullptr);
	    ASSERT_TRUE(result);
	}
	else
		ASSERT_TRUE(0);
}

TEST(ConwayCellFixture, test_clone_2) {
    ConwayCell ac(false);
    AbstractCell* cp = ac.clone();
    if(cp != nullptr)
    {
	    bool result = cp->_alive || cp->_next;
	    ConwayCell* cc = dynamic_cast<ConwayCell*>(cp);
	    delete cp;
	    ASSERT_NE(cc, nullptr);
	    ASSERT_FALSE(result);
	}
	else
		ASSERT_TRUE(0);
}

TEST(ConwayCellFixture, test_clone_3) {
    ConwayCell ac(true);
    ac.next_state(false);
    AbstractCell* cp = ac.clone();
    if(cp != nullptr)
    {
	    bool result = cp->_alive && !cp->_next;
	    ConwayCell* cc = dynamic_cast<ConwayCell*>(cp);
	    delete cp;
	    ASSERT_NE(cc, nullptr);
	    ASSERT_TRUE(result);
	}
	else
		ASSERT_TRUE(0);
}

TEST(ConwayCellFixture, test_clone_4) {
    ConwayCell ac(false);
    ac.next_state(true);
    AbstractCell* cp = ac.clone();
    if(cp != nullptr)
    {
	    bool result = !cp->_alive && cp->_next;
	    ConwayCell* cc = dynamic_cast<ConwayCell*>(cp);
	    delete cp;
	    ASSERT_NE(cc, nullptr);
	    ASSERT_TRUE(result);
	}
	else
		ASSERT_TRUE(0);
}

// -----------------------
// Fredkincell Constructor
// -----------------------

TEST(FredkinCellFixture, test_constructor_1) {
    FredkinCell fc(true);
    ASSERT_TRUE(fc._alive);
    ASSERT_TRUE(fc._next);
    ASSERT_EQ(fc._age, 0);
    ASSERT_EQ(fc._older, 0);
}

TEST(FredkinCellFixture, test_constructor_2) {
    FredkinCell fc(false);
    ASSERT_FALSE(fc._alive);
    ASSERT_FALSE(fc._next);
    ASSERT_EQ(fc._age, 0);
    ASSERT_EQ(fc._older, 0);
}

// ---------------------------
// FredkinCell CopyConstructor
// ---------------------------

TEST(FredkinCellFixture, test_copy_1) {
    FredkinCell fc(true);
    FredkinCell cp(fc);
    ASSERT_TRUE(cp._alive);
    ASSERT_TRUE(cp._next);
    ASSERT_EQ(cp._age, 0);
    ASSERT_EQ(cp._older, 0);
}

TEST(FredkinCellFixture, test_copy_2) {
    FredkinCell fc(false);
    FredkinCell cp(fc);
    ASSERT_FALSE(cp._alive);
    ASSERT_FALSE(cp._next);
    ASSERT_EQ(cp._age, 0);
    ASSERT_EQ(cp._older, 0);
}

TEST(FredkinCellFixture, test_copy_3) {
    FredkinCell fc(true);
    fc.next_state(false);
    fc._age = 1;
    fc._older = 2;
    FredkinCell cp(fc);
    ASSERT_TRUE(cp._alive);
    ASSERT_FALSE(cp._next);
    ASSERT_EQ(cp._age, 1);
    ASSERT_EQ(cp._older, 2);
}

TEST(FredkinCellFixture, test_copy_4) {
    FredkinCell fc(false);
    fc.next_state(true);
    fc._age = 1;
    fc._older = 2;
    FredkinCell cp(fc);
    ASSERT_FALSE(cp._alive);
    ASSERT_TRUE(cp._next);
    ASSERT_EQ(cp._age, 1);
    ASSERT_EQ(cp._older, 2);
}

// ---------------------------
// FredkinCell CalculateState()
// ---------------------------

TEST(FredkinCellFixture, test_calculate_alive_0)
{
	FredkinCell fc(true);
	//--
	ConwayCell live(true);
	ConwayCell dead(false);
	vector<GridCell> v;
	v.push_back(GridCell(Direction::North, dead));
	v.push_back(GridCell(Direction::East, dead));
	v.push_back(GridCell(Direction::South, dead));
	v.push_back(GridCell(Direction::West, dead));
	v.push_back(GridCell(Direction::NorthEast, dead));
	v.push_back(GridCell(Direction::NorthWest, dead));
	v.push_back(GridCell(Direction::SouthEast, dead));
	v.push_back(GridCell(Direction::SouthWest, dead));
	//--
	fc.calculate_state(v);
	ASSERT_FALSE(fc._next);
	ASSERT_EQ(fc._older, fc._age);	// older should not have incremented
}

TEST(FredkinCellFixture, test_calculate_alive_2)
{
	FredkinCell fc(true);
	//--
	ConwayCell live(true);
	ConwayCell dead(false);
	vector<GridCell> v;
	v.push_back(GridCell(Direction::North, live));
	v.push_back(GridCell(Direction::East, live));
	v.push_back(GridCell(Direction::South, dead));
	v.push_back(GridCell(Direction::West, dead));
	v.push_back(GridCell(Direction::NorthEast, dead));
	v.push_back(GridCell(Direction::NorthWest, dead));
	v.push_back(GridCell(Direction::SouthEast, dead));
	v.push_back(GridCell(Direction::SouthWest, dead));
	//--
	fc.calculate_state(v);
	ASSERT_FALSE(fc._next);
	ASSERT_EQ(fc._older, fc._age);	// older should not have incremented
}

TEST(FredkinCellFixture, test_calculate_alive_3)
{
	FredkinCell fc(true);

	//--
	ConwayCell live(true);
	ConwayCell dead(false);
	vector<GridCell> v;
	v.push_back(GridCell(Direction::North, live));
	v.push_back(GridCell(Direction::East, live));
	v.push_back(GridCell(Direction::South, live));
	v.push_back(GridCell(Direction::West, dead));
	v.push_back(GridCell(Direction::NorthEast, dead));
	v.push_back(GridCell(Direction::NorthWest, dead));
	v.push_back(GridCell(Direction::SouthEast, dead));
	v.push_back(GridCell(Direction::SouthWest, dead));
	//--
	fc.calculate_state(v);
	ASSERT_TRUE(fc._next);
	ASSERT_EQ(fc._older, fc._age+1);	// older should have incremented
}

TEST(FredkinCellFixture, test_calculate_dead_1)
{
	FredkinCell fc(false);

	//--
	ConwayCell live(true);
	ConwayCell dead(false);
	vector<GridCell> v;
	v.push_back(GridCell(Direction::North, live));
	v.push_back(GridCell(Direction::East, dead));
	v.push_back(GridCell(Direction::South, dead));
	v.push_back(GridCell(Direction::West, dead));
	v.push_back(GridCell(Direction::NorthEast, dead));
	v.push_back(GridCell(Direction::NorthWest, dead));
	v.push_back(GridCell(Direction::SouthEast, dead));
	v.push_back(GridCell(Direction::SouthWest, dead));
	//--
	fc.calculate_state(v);
	ASSERT_TRUE(fc._next);
	ASSERT_EQ(fc._older, fc._age);	// older should not have incremented
}

TEST(FredkinCellFixture, test_calculate_dead_2)
{
	FredkinCell fc(false);
	//--
	ConwayCell live(true);
	ConwayCell dead(false);
	vector<GridCell> v;
	v.push_back(GridCell(Direction::North, live));
	v.push_back(GridCell(Direction::East, live));
	v.push_back(GridCell(Direction::South, dead));
	v.push_back(GridCell(Direction::West, dead));
	v.push_back(GridCell(Direction::NorthEast, dead));
	v.push_back(GridCell(Direction::NorthWest, dead));
	v.push_back(GridCell(Direction::SouthEast, dead));
	v.push_back(GridCell(Direction::SouthWest, dead));
	//--
	fc.calculate_state(v);
	ASSERT_FALSE(fc._next);
	ASSERT_EQ(fc._older, fc._age);	// older should not have incremented
}

TEST(FredkinCellFixture, test_calculate_dead_3)
{
	FredkinCell fc(false);
	//--
	ConwayCell live(true);
	ConwayCell dead(false);
	vector<GridCell> v;
	v.push_back(GridCell(Direction::North, live));
	v.push_back(GridCell(Direction::East, live));
	v.push_back(GridCell(Direction::South, live));
	v.push_back(GridCell(Direction::West, dead));
	v.push_back(GridCell(Direction::NorthEast, dead));
	v.push_back(GridCell(Direction::NorthWest, dead));
	v.push_back(GridCell(Direction::SouthEast, dead));
	v.push_back(GridCell(Direction::SouthWest, dead));
	//--
	fc.calculate_state(v);
	ASSERT_TRUE(fc._next);
	ASSERT_EQ(fc._older, fc._age);	// older should not have incremented
}

// test that NE, NW, SE, SW do not affect FredkinCells
TEST(FredkinCellFixture, test_calculate_neighbors_1)
{
	FredkinCell fc(false);
	//--
	ConwayCell live(true);
	ConwayCell dead(false);
	vector<GridCell> v;
	v.push_back(GridCell(Direction::North, live));
	v.push_back(GridCell(Direction::East, dead));
	v.push_back(GridCell(Direction::South, dead));
	v.push_back(GridCell(Direction::West, dead));
	v.push_back(GridCell(Direction::NorthEast, live));	// should not affect outcome: cell is still live
	v.push_back(GridCell(Direction::NorthWest, dead));
	v.push_back(GridCell(Direction::SouthEast, dead));
	v.push_back(GridCell(Direction::SouthWest, dead));
	//--
	fc.calculate_state(v);
	ASSERT_TRUE(fc._next);
	ASSERT_EQ(fc._older, fc._age);	// older should not have incremented
}

TEST(FredkinCellFixture, test_calculate_neighbors_2)
{
	FredkinCell fc(false);
	//--
	ConwayCell live(true);
	ConwayCell dead(false);
	vector<GridCell> v;
	v.push_back(GridCell(Direction::North, live));
	v.push_back(GridCell(Direction::East, live));
	v.push_back(GridCell(Direction::South, dead));
	v.push_back(GridCell(Direction::West, dead));
	v.push_back(GridCell(Direction::NorthEast, live));	// should not affect outcome: cell is still dead
	v.push_back(GridCell(Direction::NorthWest, dead));
	v.push_back(GridCell(Direction::SouthEast, dead));
	v.push_back(GridCell(Direction::SouthWest, dead));
	//--
	fc.calculate_state(v);
	ASSERT_FALSE(fc._next);
	ASSERT_EQ(fc._older, fc._age);	// older should not have incremented
}

TEST(FredkinCellFixture, test_calculate_neighbors_3)
{
	FredkinCell fc(true);
	//--
	ConwayCell live(true);
	ConwayCell dead(false);
	vector<GridCell> v;
	v.push_back(GridCell(Direction::North, live));
	v.push_back(GridCell(Direction::East, dead));
	v.push_back(GridCell(Direction::South, dead));
	v.push_back(GridCell(Direction::West, dead));
	v.push_back(GridCell(Direction::NorthEast, live));	// should not affect outcome: cell is still live
	v.push_back(GridCell(Direction::NorthWest, dead));
	v.push_back(GridCell(Direction::SouthEast, dead));
	v.push_back(GridCell(Direction::SouthWest, dead));
	//--
	fc.calculate_state(v);
	ASSERT_TRUE(fc._next);
	ASSERT_EQ(fc._older, fc._age+1);	// older should have incremented
}

TEST(FredkinCellFixture, test_calculate_neighbors_4)
{
	FredkinCell fc(true);
	//--
	ConwayCell live(true);
	ConwayCell dead(false);
	vector<GridCell> v;
	v.push_back(GridCell(Direction::North, live));
	v.push_back(GridCell(Direction::East, live));
	v.push_back(GridCell(Direction::South, dead));
	v.push_back(GridCell(Direction::West, dead));
	v.push_back(GridCell(Direction::NorthEast, live));	// should not affect outcome: cell is still dead
	v.push_back(GridCell(Direction::NorthWest, dead));
	v.push_back(GridCell(Direction::SouthEast, dead));
	v.push_back(GridCell(Direction::SouthWest, dead));
	//--
	fc.calculate_state(v);
	ASSERT_FALSE(fc._next);
	ASSERT_EQ(fc._older, fc._age);	// older should not have incremented
}

// ------------------------
// FredkinCell print_cell()
// ------------------------

TEST(FredkinCellFixture, test_print_dead)
{
	FredkinCell fc(false);
	ostringstream w;
	fc.print_cell(w);
	ASSERT_EQ("-", w.str());
}

TEST(FredkinCellFixture, test_print_young)
{
	FredkinCell fc(true);
	ostringstream w;
	fc.print_cell(w);
	ASSERT_EQ("0", w.str());
}

TEST(FredkinCellFixture, test_print_old)
{
	FredkinCell fc(true);
	fc._age = 10;
	ostringstream w;
	fc.print_cell(w);
	ASSERT_EQ("+", w.str());
}

// -------------------
// FredkinCell clone()
// -------------------
// note: different style of asserting values is used
// when testing clone() to avoid potential memory leaks.

TEST(FredkinCellFixture, test_clone_1) {
    FredkinCell ac(true);
    AbstractCell* cp = ac.clone();
    if(cp != nullptr)
    {
	    bool result = cp->_alive && cp->_next;
	    FredkinCell* cc = dynamic_cast<FredkinCell*>(cp);
	    result = result && cc->_age == 0 && cc->_older == 0;
	    delete cp;
	    ASSERT_NE(cc, nullptr);
	    ASSERT_TRUE(result);
	}
	else
		ASSERT_TRUE(0);
}

TEST(FredkinCellFixture, test_clone_2) {
    FredkinCell ac(false);
    ac._age = 2;
    ac._older = 2;
    AbstractCell* cp = ac.clone();
    if(cp != nullptr)
    {
	    bool result = cp->_alive || cp->_next;
	    FredkinCell* cc = dynamic_cast<FredkinCell*>(cp);
	    result = result && cc->_age == 2 && cc->_older == 2;
	    delete cp;
	    ASSERT_NE(cc, nullptr);
	    ASSERT_FALSE(result);
	}
	else
		ASSERT_TRUE(0);
}

TEST(FredkinCellFixture, test_clone_3) {
    FredkinCell ac(true);
    ac.next_state(false);
    ac._age = 1;
    ac._older = 2;
    AbstractCell* cp = ac.clone();
    if(cp != nullptr)
    {
	    bool result = cp->_alive && !cp->_next;
	    FredkinCell* cc = dynamic_cast<FredkinCell*>(cp);
	    result = result && cc->_age == 1 && cc->_older == 2;
	    delete cp;
	    ASSERT_NE(cc, nullptr);
	    ASSERT_TRUE(result);
	}
	else
		ASSERT_TRUE(0);
}

TEST(FredkinCellFixture, test_clone_4) {
    FredkinCell ac(false);
    ac.next_state(true);
    AbstractCell* cp = ac.clone();
    if(cp != nullptr)
    {
	    bool result = !cp->_alive && cp->_next;
	    FredkinCell* cc = dynamic_cast<FredkinCell*>(cp);
	    result = result && cc->_age == 0 && cc->_older == 0;
	    delete cp;
	    ASSERT_NE(cc, nullptr);
	    ASSERT_TRUE(result);
	}
	else
		ASSERT_TRUE(0);
}

// --------------------
// FredkinCell evolve()
// --------------------

TEST(FredkinCellFixture, test_evolve_1)
{
	FredkinCell ac(true);
	ac.next_state(true);
	ac._older = 1;
	AbstractCell* ret = ac.evolve();
	ASSERT_EQ(ret, nullptr);
    ASSERT_TRUE(ac.is_alive());
    ASSERT_EQ(ac._age, 1);
}

TEST(FredkinCellFixture, test_evolve_2)
{
	FredkinCell ac(false);
	ac.next_state(false);
	AbstractCell* ret = ac.evolve();
	ASSERT_EQ(ret, nullptr);
    ASSERT_FALSE(ac.is_alive());
    ASSERT_EQ(ac._age, 0);
}

TEST(FredkinCellFixture, test_evolve_3)
{
	FredkinCell ac(false);
	ac.next_state(true);
	AbstractCell* ret = ac.evolve();
	ASSERT_EQ(ret, nullptr);
    ASSERT_TRUE(ac.is_alive());
    ASSERT_EQ(ac._age, 0);
}

TEST(FredkinCellFixture, test_evolve_4)
{
	FredkinCell ac(true);
	ac.next_state(false);
	AbstractCell* ret = ac.evolve();
	ASSERT_EQ(ret, nullptr);
    ASSERT_FALSE(ac.is_alive());
    ASSERT_EQ(ac._age, 0);
}

// test that new ConwayCell is returned when older = 2. Ignore it, though.
TEST(FredkinCellFixture, test_evolve_5)
{
	FredkinCell ac(true);
	ac.next_state(true);
	ac._older = 2;
	AbstractCell* ret = ac.evolve();
	bool result = ret != nullptr && dynamic_cast<ConwayCell*>(ret) != nullptr;
	if(ret != nullptr)
		delete ret;
	ASSERT_TRUE(result);
    ASSERT_TRUE(ac.is_alive());
    ASSERT_EQ(ac._age, 2);
}

// ----------------
// Cell Constructor
// ----------------

// Constructor uses clone(), which is tested elsewhere.
// Just ensure the correct type is preserved.
TEST(CellFixture, test_constructor_1)
{
	ConwayCell cc(true);
	Cell c(&cc);
	bool result = (dynamic_cast<ConwayCell*>(c._cell) != nullptr);
	ASSERT_TRUE(result);
}

TEST(CellFixture, test_constructor_2)
{
	FredkinCell fc(true);
	Cell c(&fc);
	bool result = (dynamic_cast<FredkinCell*>(c._cell) != nullptr);
	ASSERT_TRUE(result);
}

TEST(CellFixture, test_constructor_3)
{
	Cell c;
	bool result = (!c._cell->is_alive()) && (dynamic_cast<FredkinCell*>(c._cell) != nullptr);
	ASSERT_TRUE(result);
}

// ----------------------
// Cell calculate_state()
// ----------------------
// check that correct function is called

TEST(CellFixture, test_calculate_neighbors_Fredkin)
{
	FredkinCell fc(true);
	Cell c(&fc);
	//--
	ConwayCell live(true);
	ConwayCell dead(false);
	vector<GridCell> v;
	v.push_back(GridCell(Direction::North, live));
	v.push_back(GridCell(Direction::East, live));
	v.push_back(GridCell(Direction::South, dead));
	v.push_back(GridCell(Direction::West, dead));
	v.push_back(GridCell(Direction::NorthEast, live));	// should not affect outcome: cell is still dead
	v.push_back(GridCell(Direction::NorthWest, dead));
	v.push_back(GridCell(Direction::SouthEast, dead));
	v.push_back(GridCell(Direction::SouthWest, dead));
	//--
	c.calculate_state(v);
	ASSERT_FALSE(c._cell->_next);
	ASSERT_EQ(dynamic_cast<FredkinCell*>(c._cell)->_older,
	          dynamic_cast<FredkinCell*>(c._cell)->_age);	// older should not have incremented
}

TEST(CellFixture, test_calculate_neighbors_Conway)
{
	ConwayCell ac(true);
	Cell c(&ac);
	//--
	ConwayCell live(true);
	ConwayCell dead(false);
	vector<GridCell> v;
	v.push_back(GridCell(Direction::North, live));
	v.push_back(GridCell(Direction::East, dead));
	v.push_back(GridCell(Direction::South, dead));
	v.push_back(GridCell(Direction::West, dead));
	v.push_back(GridCell(Direction::NorthEast, live));	// should affect outcome: cell is live instead of dead
	v.push_back(GridCell(Direction::NorthWest, dead));
	v.push_back(GridCell(Direction::SouthEast, dead));
	v.push_back(GridCell(Direction::SouthWest, dead));
	//--
	c.calculate_state(v);
	ASSERT_TRUE(c._cell->_next);
}

// ---------------
// Cell is_alive()
// ---------------

TEST(CellFixture, test_is_alive_1)
{
	ConwayCell cc(true);
	Cell c(&cc);
	ASSERT_TRUE(c.is_alive());
}

TEST(CellFixture, test_is_alive_2)
{
	ConwayCell cc(false);
	cc.next_state(true);
	Cell c(&cc);
	ASSERT_FALSE(c.is_alive());
}

TEST(CellFixture, test_is_alive_3)
{
	FredkinCell fc(true);
	Cell c(&fc);
	ASSERT_TRUE(c.is_alive());
}

TEST(CellFixture, test_is_alive_4)
{
	FredkinCell fc(false);
	fc.next_state(true);
	Cell c(&fc);
	ASSERT_FALSE(c.is_alive());
}

// -------------
// Cell evolve()
// -------------

TEST(CellFixture, test_evolve_1)
{
	ConwayCell cc(true);
	cc.next_state(false);
	Cell c(&cc);
	c.evolve();
	ASSERT_FALSE(c._cell->is_alive());
}

TEST(CellFixture, test_evolve_2)
{
	FredkinCell fc(true);
	fc.next_state(false);
	Cell c(&fc);
	c.evolve();
	ASSERT_FALSE(c._cell->is_alive());
	ASSERT_EQ(dynamic_cast<FredkinCell*>(c._cell)->_age, 0);
}

TEST(CellFixture, test_evolve_3)
{
	FredkinCell fc(true);
	fc.next_state(true);
	fc._older = 2;
	Cell c(&fc);
	c.evolve();
	ASSERT_TRUE(c._cell->is_alive());
	ASSERT_NE(dynamic_cast<ConwayCell*>(c._cell), nullptr);
}

// -----------------
// Cell print_cell()
// -----------------

TEST(CellFixture, test_print_conway_live)
{
	ConwayCell cc(true);
	Cell c(&cc);
	ostringstream w;
	c.print_cell(w);
	ASSERT_EQ("*", w.str());
}

TEST(CellFixture, test_print_conway_dead)
{
	ConwayCell cc(false);
	Cell c(&cc);
	ostringstream w;
	c.print_cell(w);
	ASSERT_EQ(".", w.str());
}

TEST(CellFixture, test_print_fredkin_dead)
{
	FredkinCell fc(false);
	Cell c(&fc);
	ostringstream w;
	c.print_cell(w);
	ASSERT_EQ("-", w.str());
}

TEST(CellFixture, test_print_young)
{
	FredkinCell fc(true);
	Cell c(&fc);
	ostringstream w;
	c.print_cell(w);
	ASSERT_EQ("0", w.str());
}

TEST(CellFixture, test_print_old)
{
	FredkinCell fc(true);
	fc._age = 10;
	Cell c(&fc);
	ostringstream w;
	c.print_cell(w);
	ASSERT_EQ("+", w.str());
}

// ----------------
// Life Constructor
// ----------------

TEST(LifeFixture, test_constructor_1)
{
	Life<Cell> l(5, 10);
	ASSERT_EQ(l._grid.size(), 7);
	ASSERT_EQ(l._grid[0].size(), 12);
	ASSERT_EQ(l._gen, 0);
	ASSERT_EQ(l._pop, 0);
	ASSERT_EQ(l._i, 5);
	ASSERT_EQ(l._j, 10);
}

TEST(LifeFixture, test_constructor_2)
{
	Life<FredkinCell> l(5, 10);
	ASSERT_EQ(l._grid.size(), 7);
	ASSERT_EQ(l._grid[0].size(), 12);
	ASSERT_EQ(l._gen, 0);
	ASSERT_EQ(l._pop, 0);
	ASSERT_EQ(l._i, 5);
	ASSERT_EQ(l._j, 10);
}

TEST(LifeFixture, test_constructor_3)
{
	Life<ConwayCell> l(5, 10);
	ASSERT_EQ(l._grid.size(), 7);
	ASSERT_EQ(l._grid[0].size(), 12);
	ASSERT_EQ(l._gen, 0);
	ASSERT_EQ(l._pop, 0);
	ASSERT_EQ(l._i, 5);
	ASSERT_EQ(l._j, 10);
}

// -----------------
// Life add_cell()
// -----------------

TEST(LifeFixture, add_cell_1)
{
	Life<ConwayCell> l(2,2);
	ConwayCell clive(true);
	ConwayCell cdead(false);
	l.add_cell(clive, 0,0);
	l.add_cell(cdead, 0,1);
	ASSERT_TRUE(l._grid[1][1]->is_alive());
	ASSERT_FALSE(l._grid[1][2]->is_alive());
	ASSERT_EQ(l._pop, 1);
}
