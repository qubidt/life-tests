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
#include <iostream>
#include <utility>
#include <sstream>
#include <string>

using namespace std;

// ----
// test
// ----

// ----------
// ConwayCell
// ----------
// == default Constructor ==
TEST(ConwayCellFixture, defaultConstructor1) {
	try {
		ConwayCell c;
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(ConwayCellFixture, defaultConstructor2) {
	ConwayCell c;
	ASSERT_EQ(c.isAlive, false);
}

// == Object Constructor
TEST(ConwayCellFixture, objectConstructor1) {
	try {
		ConwayCell c('.', false);
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(ConwayCellFixture, objectConstructor2) {
	ConwayCell c('.', false);
	ASSERT_EQ(c.isAlive, false);
}
TEST(ConwayCellFixture, objectConstructor3) {
	ConwayCell c('*', true);
	ASSERT_EQ(c.isAlive, true);
}

// == clone ==
TEST(ConwayCellFixture, clone1) {
	ConwayCell c;
	AbstractCell* c2 = c.clone();

	bool isEqual = (&c == c2);
	delete c2;

	ASSERT_TRUE(!isEqual);
}
TEST(ConwayCellFixture, clone2) {
	ConwayCell c('.', false);
	AbstractCell* c2 = c.clone();

	bool isEqual = (&c == c2);
	delete c2;

	ASSERT_TRUE(!isEqual);
}
TEST(ConwayCellFixture, clone3) {
	ConwayCell c('*', true);
	AbstractCell* c2 = c.clone();

	bool isEqual = (&c == c2);
	delete c2;

	ASSERT_TRUE(!isEqual);
}

// == modifyCell(int, int) ==
TEST(ConwayCellFixture, modifyCell1) {
	try {
		ConwayCell c;
		int numAlive = 0;
		int population = 0;

		c.modifyCell(numAlive, population);
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(ConwayCellFixture, modifyCell2) {
	try {
		ConwayCell c('*', true);
		int numAlive = 0;
		int population = 0;

		c.modifyCell(numAlive, population, true);
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(ConwayCellFixture, modifyCell3) {
	ConwayCell c('.', false);
	int numAlive = 0;
	int population = 0;

	ASSERT_EQ(c.isAlive, false);

	ConwayCell* p = c.modifyCell(numAlive, population);

	ASSERT_EQ(p, nullptr);
	ASSERT_EQ(numAlive, 0);
	ASSERT_EQ(population, 0);
	ASSERT_EQ(c.isAlive, false);
}
TEST(ConwayCellFixture, modifyCell4) {
	ConwayCell c('.', false);
	int numAlive = 3;
	int population = 0;

	ASSERT_EQ(c.isAlive, false);

	ConwayCell* p = c.modifyCell(numAlive, population);

	ASSERT_EQ(p, nullptr);
	ASSERT_EQ(numAlive, 3);
	ASSERT_EQ(population, 1);
	ASSERT_EQ(c.isAlive, true);
}
TEST(ConwayCellFixture, modifyCell5) {
	ConwayCell c('*', true);
	int numAlive = 0;
	int population = 1;

	ASSERT_EQ(c.isAlive, true);

	ConwayCell* p = c.modifyCell(numAlive, population);

	ASSERT_EQ(p, nullptr);
	ASSERT_EQ(numAlive, 0);
	ASSERT_EQ(population, 0);
	ASSERT_EQ(c.isAlive, false);
}
TEST(ConwayCellFixture, modifyCell6) {
	ConwayCell c('*', true);
	int numAlive = 2;
	int population = 1;

	ASSERT_EQ(c.isAlive, true);

	ConwayCell* p = c.modifyCell(numAlive, population);

	ASSERT_EQ(p, nullptr);
	ASSERT_EQ(numAlive, 2);
	ASSERT_EQ(population, 1);
	ASSERT_EQ(c.isAlive, true);
}
TEST(ConwayCellFixture, modifyCell7) {
	ConwayCell c('*', true);
	int numAlive = 5;
	int population = 1;

	ASSERT_EQ(c.isAlive, true);

	ConwayCell* p = c.modifyCell(numAlive, population);

	ASSERT_EQ(p, nullptr);
	ASSERT_EQ(numAlive, 5);
	ASSERT_EQ(population, 0);
	ASSERT_EQ(c.isAlive, false);
}

// == isConway() ==
TEST(ConwayCellFixture, isConway1) {
	try {
		ConwayCell c;
		c.isConway();
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(ConwayCellFixture, isConway2) {
	ConwayCell c;

	ASSERT_EQ(c.isConway(), true);
}
TEST(ConwayCellFixture, isConway3) {
	ConwayCell c('*', true);

	ASSERT_EQ(c.isConway(), true);
}

// == operator<<() / write(os) ==
TEST(ConwayCellFixture, stream1) {
	try {
		ConwayCell c;
		ostringstream oss;

		oss << c;
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(ConwayCellFixture, stream2) {
	ConwayCell c;
	ostringstream oss;

	oss << c;
	string str;

  	str = oss.str();

  	ASSERT_EQ(str, ".");
}
TEST(ConwayCellFixture, stream3) {
	ConwayCell c('*', true);
	ostringstream oss;

	oss << c;
	string str;

  	str = oss.str();

  	ASSERT_EQ(str, "*");
}

// == operator==() / equals(rhs) ==
TEST(ConwayCellFixture, equals1) {
	try {
		ConwayCell c;
		ConwayCell c2;

		(c == c2);
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(ConwayCellFixture, equals2) {
	ConwayCell c;
	ConwayCell c2;
	
	bool isEqual = (c == c2);

	ASSERT_TRUE(isEqual);
}
TEST(ConwayCellFixture, equals3) {
	ConwayCell c;
	ConwayCell c2('.', false);
	
	bool isEqual = (c == c2);

	ASSERT_TRUE(isEqual);
}
TEST(ConwayCellFixture, equals4) {
	ConwayCell c('.', false);
	ConwayCell c2('.', false);
	
	bool isEqual = (c == c2);

	ASSERT_TRUE(isEqual);
}
TEST(ConwayCellFixture, equals5) {
	ConwayCell c('.', false);
	ConwayCell c2('*', true);
	
	bool isEqual = (c == c2);

	ASSERT_TRUE(!isEqual);
}


// -----------
// FredkinCell
// -----------
// == default Constructor ==
TEST(FredkinCellFixture, defaultConstructor1) {
	try {
		FredkinCell f;
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(FredkinCellFixture, defaultConstructor2) {
	FredkinCell f;
	ASSERT_EQ(f.isAlive, false);
	ASSERT_EQ(f.age, 0);
}

// == Object Constructor ==
TEST(FredkinCellFixture, objectConstructor1) {
	try {
		FredkinCell f('0', true);
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(FredkinCellFixture, objectConstructor2) {
	FredkinCell f('-', false);

	ASSERT_EQ(f.isAlive, false);
	ASSERT_EQ(f.age, 0);
}
TEST(FredkinCellFixture, objectConstructor3) {
	FredkinCell f('0', true);

	ASSERT_EQ(f.isAlive, true);
	ASSERT_EQ(f.age, 0);
}
TEST(FredkinCellFixture, objectConstructor4) {
	FredkinCell f('+', true);

	ASSERT_EQ(f.isAlive, true);
	ASSERT_EQ(f.age, 10);
}

// == clone ==
TEST(FredkinCellFixture, clone1) {
	FredkinCell f;
	AbstractCell* f2 = f.clone();

	bool isEqual = (&f == f2);
	delete f2;

	ASSERT_TRUE(!isEqual);
}
TEST(FredkinCellFixture, clone2) {
	FredkinCell f('-', false);
	AbstractCell* f2 = f.clone();

	bool isEqual = (&f == f2);
	delete f2;

	ASSERT_TRUE(!isEqual);
}
TEST(FredkinCellFixture, clone3) {
	FredkinCell f('2', true);
	AbstractCell* f2 = f.clone();

	bool isEqual = (&f == f2);
	delete f2;

	ASSERT_TRUE(!isEqual);
}
TEST(FredkinCellFixture, clone4) {
	FredkinCell f('+', true);
	AbstractCell* f2 = f.clone();

	bool isEqual = (&f == f2);
	delete f2;

	ASSERT_TRUE(!isEqual);
}

// == modifyCell(int, int) ==
TEST(FredkinCellFixture, modifyCell1) {
	try {
		FredkinCell f;
		int numAlive = 0;
		int population = 0;

		f.modifyCell(numAlive, population);
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(FredkinCellFixture, modifyCell2) {
	try {
		FredkinCell f('2', true);
		int numAlive = 0;
		int population = 0;

		f.modifyCell(numAlive, population);
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(FredkinCellFixture, modifyCell3) {
	FredkinCell f('-', false);
	int numAlive = 0;
	int population = 0;

	ASSERT_EQ(f.isAlive, false);
	ASSERT_EQ(f.age, 0);

	ConwayCell* p = f.modifyCell(numAlive, population);

	ASSERT_EQ(p, nullptr);
	ASSERT_EQ(numAlive, 0);
	ASSERT_EQ(population, 0);
	ASSERT_EQ(f.isAlive, false);
	ASSERT_EQ(f.age, 0);
}
TEST(FredkinCellFixture, modifyCell4) {
	FredkinCell f('-', false);
	int numAlive = 1;
	int population = 0;

	ASSERT_EQ(f.isAlive, false);
	ASSERT_EQ(f.age, 0);

	ConwayCell* p = f.modifyCell(numAlive, population);

	ASSERT_EQ(p, nullptr);
	ASSERT_EQ(numAlive, 1);
	ASSERT_EQ(population, 1);
	ASSERT_EQ(f.isAlive, true);
	ASSERT_EQ(f.age, 0);
}
TEST(FredkinCellFixture, modifyCell5) {
	FredkinCell f('0', true);
	int numAlive = 1;
	int population = 1;

	ASSERT_EQ(f.isAlive, true);
	ASSERT_EQ(f.age, 0);

	ConwayCell* p = f.modifyCell(numAlive, population);

	ASSERT_EQ(p, nullptr);
	ASSERT_EQ(numAlive, 1);
	ASSERT_EQ(population, 1);
	ASSERT_EQ(f.isAlive, true);
	ASSERT_EQ(f.age, 1);
}
TEST(FredkinCellFixture, modifyCell6) {
	FredkinCell f('0', true);
	int numAlive = 0;
	int population = 1;

	ASSERT_EQ(f.isAlive, true);
	ASSERT_EQ(f.age, 0);

	ConwayCell* p = f.modifyCell(numAlive, population);

	ASSERT_EQ(p, nullptr);
	ASSERT_EQ(numAlive, 0);
	ASSERT_EQ(population, 0);
	ASSERT_EQ(f.isAlive, false);
	ASSERT_EQ(f.age, 0);
}
TEST(FredkinCellFixture, modifyCell7) {
	FredkinCell f('2', true);
	int numAlive = 0;
	int population = 1;

	ASSERT_EQ(f.isAlive, true);
	ASSERT_EQ(f.age, 2);

	ConwayCell* p = f.modifyCell(numAlive, population);

	ASSERT_EQ(p, nullptr);
	ASSERT_EQ(numAlive, 0);
	ASSERT_EQ(population, 0);
	ASSERT_EQ(f.isAlive, false);
	ASSERT_EQ(f.age, 2);

	numAlive = 1;
	p = f.modifyCell(numAlive, population);

	ASSERT_EQ(p, nullptr);
	ASSERT_EQ(numAlive, 1);
	ASSERT_EQ(population, 1);
	ASSERT_EQ(f.isAlive, true);
	ASSERT_EQ(f.age, 2);
}

// == isConway() ==
TEST(FredkinCellFixture, isConway1) {
	try {
		FredkinCell f;
		f.isConway();
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(FredkinCellFixture, isConway2) {
	FredkinCell f('-', false);

	ASSERT_EQ(f.isConway(), false);
}
TEST(FredkinCellFixture, isConway3) {
	FredkinCell f('2', true);

	ASSERT_EQ(f.isConway(), false);
}

// == operator<<() / write(os) ==
TEST(FredkinCellFixture, stream1) {
	try {
		FredkinCell f;
		ostringstream oss;

		oss << f;
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(FredkinCellFixture, stream2) {
	FredkinCell f;
	ostringstream oss;

	oss << f;
	string str;

  	str = oss.str();

  	ASSERT_EQ(str, "-");
}
TEST(FredkinCellFixture, stream3) {
	FredkinCell f('2', true);
	ostringstream oss;

	oss << f;
	string str;

  	str = oss.str();

  	ASSERT_EQ(str, "2");
}
TEST(FredkinCellFixture, stream4) {
	FredkinCell f('+', true);
	ostringstream oss;

	oss << f;
	string str;

  	str = oss.str();

  	ASSERT_EQ(str, "+");
}

// == operator==() / equals(rhs) ==
TEST(FredkinCellFixture, equals1) {
	try {
		FredkinCell f;
		FredkinCell f2;

		(f == f2);
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(FredkinCellFixture, equals2) {
	ConwayCell f;
	ConwayCell f2;
	
	bool isEqual = (f == f2);

	ASSERT_TRUE(isEqual);
}
TEST(FredkinCellFixture, equals3) {
	FredkinCell f;
	FredkinCell f2('-', false);
	
	bool isEqual = (f == f2);

	ASSERT_TRUE(isEqual);
}
TEST(FredkinCellFixture, equals4) {
	FredkinCell f('-', false);
	FredkinCell f2('0', true);
	
	bool isEqual = (f == f2);

	ASSERT_TRUE(!isEqual);
}
TEST(FredkinCellFixture, equals5) {
	FredkinCell f('0', true);
	FredkinCell f2('2', true);
	
	bool isEqual = (f == f2);

	ASSERT_TRUE(!isEqual);
}
TEST(FredkinCellFixture, equals6) {
	FredkinCell f('+', true);
	FredkinCell f2('+', true);
	
	bool isEqual = (f == f2);

	ASSERT_TRUE(isEqual);
}

// ----
// Cell
// ----

// == Default Constructor ==
TEST(CellFixture, defaultConstructor1) {
	try {
		Cell c;
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(CellFixture, defaultConstructor2) {
	Cell c;

	ASSERT_EQ(c.AC, nullptr);
}

// == AbstractCell* Constructor ==
TEST(CellFixture, AbstractCellConstructor1) {
	ConwayCell cc;
	AbstractCell* p = nullptr;

	try {
		p = cc.clone();
		Cell c(p);
	}
	catch(exception& e) {
		if(p != nullptr)
			delete p;
		ASSERT_EQ(true, false);
	}
}
TEST(CellFixture, AbstractCellConstructor2) {
	ConwayCell cc;
	AbstractCell* p = cc.clone();
	Cell c(p);

	ASSERT_EQ(c.AC->isAlive, false);
	ASSERT_EQ(p->isAlive, false);
	ASSERT_EQ(c.AC, p);
}
TEST(CellFixture, AbstractCellConstructor3) {
	FredkinCell fc('0', true);
	AbstractCell* p = fc.clone();
	Cell c(p);

	ASSERT_EQ(c.AC->isAlive, true);
	ASSERT_EQ(p->isAlive, true);
	ASSERT_EQ(c.AC, p);
}

// == Object Constructor ==
TEST(CellFixture, objectConstructor1) {
	try {
		Cell c('.', false);
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(CellFixture, objectConstructor2) {
	Cell c('.', false);

	ASSERT_TRUE(c.AC != nullptr);
	ASSERT_EQ(c.AC->isAlive, false);
	ASSERT_EQ(c.AC->isConway(), true);
}
TEST(CellFixture, objectConstructor3) {
	Cell c('*', true);

	ASSERT_TRUE(c.AC != nullptr);
	ASSERT_EQ(c.AC->isAlive, true);
	ASSERT_EQ(c.AC->isConway(), true);
}
TEST(CellFixture, objectConstructor4) {
	Cell c('-', false);

	ASSERT_TRUE(c.AC != nullptr);
	ASSERT_EQ(c.AC->isAlive, false);
	ASSERT_EQ(c.AC->isConway(), false);
}
TEST(CellFixture, objectConstructor5) {
	Cell c('0', true);

	ASSERT_TRUE(c.AC != nullptr);
	ASSERT_EQ(c.AC->isAlive, true);
	ASSERT_EQ(c.AC->isConway(), false);
}

// == Copy Constructor ==
TEST(CellFixture, copyConstructor1) {
	try {
		Cell c('.', false);
		Cell c2(c);
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(CellFixture, copyConstructor2) {
	Cell c('.', false);

	ASSERT_TRUE(c.AC != nullptr);
	ASSERT_EQ(c.AC->isAlive, false);
	ASSERT_EQ(c.AC->isConway(), true);

	Cell c2(c);
	ASSERT_TRUE(c2.AC != nullptr);
	ASSERT_EQ(c2.AC->isAlive, false);
	ASSERT_EQ(c2.AC->isConway(), true);
	ASSERT_TRUE(c2.AC != c.AC);
}
TEST(CellFixture, copyConstructor3) {
	Cell c('0', true);

	ASSERT_TRUE(c.AC != nullptr);
	ASSERT_EQ(c.AC->isAlive, true);
	ASSERT_EQ(c.AC->isConway(), false);

	Cell c2(c);
	ASSERT_TRUE(c2.AC != nullptr);
	ASSERT_EQ(c2.AC->isAlive, true);
	ASSERT_EQ(c2.AC->isConway(), false);
	ASSERT_TRUE(c2.AC != c.AC);
}

// == Copy Assignment Operator ==
TEST(CellFixture, copyAssignmentConstructor1) {
	try {
		Cell c('.', false);
		Cell c2('-', false);

		c2 = c;
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(CellFixture, copyAssignmentConstructor2) {
	Cell c('.', false);
	Cell c2('-', false);

	ASSERT_TRUE(c.AC != nullptr);
	ASSERT_EQ(c.AC->isAlive, false);
	ASSERT_EQ(c.AC->isConway(), true);

	ASSERT_TRUE(c2.AC != nullptr);
	ASSERT_EQ(c2.AC->isAlive, false);
	ASSERT_EQ(c2.AC->isConway(), false);

	c2 = c;

	ASSERT_TRUE(c2.AC != nullptr);
	ASSERT_EQ(c2.AC->isAlive, false);
	ASSERT_EQ(c2.AC->isConway(), true);
	ASSERT_TRUE(c2.AC != c.AC);
}
TEST(CellFixture, copyAssignmentConstructor3) {
	Cell c('.', false);
	Cell c2('8', true);

	ASSERT_TRUE(c.AC != nullptr);
	ASSERT_EQ(c.AC->isAlive, false);
	ASSERT_EQ(c.AC->isConway(), true);

	ASSERT_TRUE(c2.AC != nullptr);
	ASSERT_EQ(c2.AC->isAlive, true);
	ASSERT_EQ(c2.AC->isConway(), false);

	c2 = c;

	ASSERT_TRUE(c2.AC != nullptr);
	ASSERT_EQ(c2.AC->isAlive, false);
	ASSERT_EQ(c2.AC->isConway(), true);
	ASSERT_TRUE(c2.AC != c.AC);
}

// == modifyCell(int, int) ==
TEST(CellFixture, modifyCell1) {
	try {
		Cell c('.', false);
		int numAlive = 0;
		int population = 0;

		c.modifyCell(numAlive, population);
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(CellFixture, modifyCell2) {
	Cell c('.', false);
	int numAlive = 0;
	int population = 0;

	ASSERT_EQ(c.AC->isAlive, false);

	c.modifyCell(numAlive, population);

	ASSERT_EQ(numAlive, 0);
	ASSERT_EQ(population, 0);
	ASSERT_EQ(c.AC->isAlive, false);
}
TEST(CellFixture, modifyCell3) {
	Cell c('.', false);
	int numAlive = 3;
	int population = 0;

	ASSERT_EQ(c.AC->isAlive, false);

	c.modifyCell(numAlive, population);

	ASSERT_EQ(numAlive, 3);
	ASSERT_EQ(population, 1);
	ASSERT_EQ(c.AC->isAlive, true);
}
TEST(CellFixture, modifyCell4) {
	Cell c('*', true);
	int numAlive = 0;
	int population = 1;

	ASSERT_EQ(c.AC->isAlive, true);

	c.modifyCell(numAlive, population);

	ASSERT_EQ(numAlive, 0);
	ASSERT_EQ(population, 0);
	ASSERT_EQ(c.AC->isAlive, false);
}
TEST(CellFixture, modifyCell5) {
	Cell c('-', false);
	int numAlive = 0;
	int population = 0;

	ASSERT_EQ(c.AC->isAlive, false);

	c.modifyCell(numAlive, population);

	ASSERT_EQ(numAlive, 0);
	ASSERT_EQ(population, 0);
	ASSERT_EQ(c.AC->isAlive, false);
}
TEST(CellFixture, modifyCell6) {
	Cell c('-', false);
	int numAlive = 1;
	int population = 0;

	ASSERT_EQ(c.AC->isAlive, false);

	c.modifyCell(numAlive, population);

	ASSERT_EQ(numAlive, 1);
	ASSERT_EQ(population, 1);
	ASSERT_EQ(c.AC->isAlive, true);
}
TEST(CellFixture, modifyCell7) {
	Cell c('0', true);
	int numAlive = 0;
	int population = 1;

	ASSERT_EQ(c.AC->isAlive, true);

	c.modifyCell(numAlive, population);

	ASSERT_EQ(numAlive, 0);
	ASSERT_EQ(population, 0);
	ASSERT_EQ(c.AC->isAlive, false);
}
TEST(CellFixture, modifyCell8) {
	Cell c('1', true);
	int numAlive = 1;
	int population = 1;

	ASSERT_EQ(c.AC->isAlive, true);
	ASSERT_EQ(c.AC->isConway(), false);

	c.modifyCell(numAlive, population);

	ASSERT_EQ(numAlive, 1);
	ASSERT_EQ(population, 1);
	ASSERT_EQ(c.AC->isAlive, true);
	ASSERT_EQ(c.AC->isConway(), true);
}

// == isConway() ==
TEST(CellFixture, isConway1) {
	try {
		Cell c;
		c.isConway();
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(CellFixture, isConway2) {
	try {
		Cell c('.', false);
		c.isConway();
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(CellFixture, isConway3) {
	Cell c('.', false);
	bool isEqual = c.isConway();

	ASSERT_EQ(isEqual, true);
}
TEST(CellFixture, isConway4) {
	Cell c('0', true);
	bool isEqual = c.isConway();
	
	ASSERT_EQ(isEqual, false);
}

// == countLiveCell ==
TEST(CellFixture, countLiveCell1) {
	try {
		Cell c;
		int count = 0;

		c.countLiveCell(count);

		ASSERT_EQ(true, false);
	}
	catch(exception& e) {
		ASSERT_EQ(true, true);
	}
}
TEST(CellFixture, countLiveCell2) {
	try {
		Cell c('.', false);
		int count = 0;

		c.countLiveCell(count);
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(CellFixture, countLiveCell3) {
	Cell c('*', true);
	int count = 0;

	c.countLiveCell(count);

	ASSERT_EQ(count, 1);
}
TEST(CellFixture, countLiveCell4) {
	Cell c('-', false);
	int count = 0;

	c.countLiveCell(count);

	ASSERT_EQ(count, 0);
}


// == operator<<() / write(os) ==
TEST(CellFixture, stream1) {
	try {
		Cell c;
		ostringstream oss;

		oss << c;

		ASSERT_EQ(true, false);
	}
	catch(exception& e) {
		ASSERT_EQ(true, true);
	}
}
TEST(CellFixture, stream2) {
	try {
		Cell c('.', false);
		ostringstream oss;

		oss << c;
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(CellFixture, stream3) {
	Cell c('.', false);
	ostringstream oss;

	oss << c;
	string str;

	str = oss.str();

	ASSERT_EQ(str, ".");
}
TEST(CellFixture, stream4) {
	Cell c('8', true);
	ostringstream oss;

	oss << c;
	string str;

	str = oss.str();

	ASSERT_EQ(str, "8");
}

// == operator==() / equals(rhs) ==
TEST(CellFixture, equals1) {
	try {
		Cell c;
		Cell c2;

		(c == c2);
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(CellFixture, equals2) {
	Cell c;
	Cell c2;
	
	bool isEqual = (c == c2);

	ASSERT_TRUE(!isEqual);
}
TEST(CellFixture, equals3) {
	Cell c;
	Cell c2('.', false);
	
	bool isEqual = (c == c2);

	ASSERT_TRUE(!isEqual);
}
TEST(CellFixture, equals4) {
	Cell c;
	Cell c2('0', true);
	
	bool isEqual = (c == c2);

	ASSERT_TRUE(!isEqual);
}
TEST(CellFixture, equals5) {
	Cell c('*', true);
	Cell c2('*', true);
	
	bool isEqual = (c == c2);

	ASSERT_TRUE(isEqual);
}
TEST(CellFixture, equals6) {
	Cell c('+', true);
	Cell c2('+', true);
	
	bool isEqual = (c == c2);

	ASSERT_TRUE(isEqual);
}

// -------
// Life<T>
// -------

// == defaultConstructor ==
TEST(LifeFixture, defaultConstructor1) {
	try {
		Life<ConwayCell> l;
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(LifeFixture, defaultConstructor2) {
	Life<ConwayCell> l;

	ASSERT_EQ(l.grid.size(), 0);
	ASSERT_EQ(l.neighborGrid.size(), 0);
	ASSERT_EQ(l._row, 0);
	ASSERT_EQ(l._col, 0);
	ASSERT_EQ(l._population, 0);
}

// == objectConstructor ==
TEST(LifeFixture, objectConstructor1) {
	try {
		// int rowNum = 2;
		// int colNum = 2;

		Life<ConwayCell> l(2,2);
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(LifeFixture, objectConstructor2) {
	// Life<Cell> c1(rowNum, colNum);
	Life<ConwayCell> l(2, 2);

	ASSERT_EQ(l.grid.size(), 4);
	ASSERT_EQ(l.neighborGrid.size(), 4);
	ASSERT_EQ(l._row, 2);
	ASSERT_EQ(l._col, 2);
	ASSERT_EQ(l._population, 0);
}
TEST(LifeFixture, objectConstructor3) {
	Life<ConwayCell> l(12, 25);

	ASSERT_EQ(l.grid.size(), 300);
	ASSERT_EQ(l.neighborGrid.size(), 300);
	ASSERT_EQ(l._row, 12);
	ASSERT_EQ(l._col, 25);
	ASSERT_EQ(l._population, 0);
}

// == addCell(char, int, int) ==
TEST(LifeFixture, addCell1) {
	try {
		Life<ConwayCell> l;
		l.addCell('.', 0, 0);

		ASSERT_EQ(true, false);
	}
	catch(exception& e) {
		ASSERT_EQ(true, true);
	}
}
TEST(LifeFixture, addCell2) {
	try {
		Life<ConwayCell> l(2,2);
		l.addCell('.', 3, 0);

		ASSERT_EQ(true, false);
	}
	catch(exception& e) {
		ASSERT_EQ(true, true);
	}
}
TEST(LifeFixture, addCell3) {
	try {
		Life<ConwayCell> l(2,2);
		l.addCell('#', 1, 1);

		ASSERT_EQ(true, false);
	}
	catch(exception& e) {
		ASSERT_EQ(true, true);
	}
}
TEST(LifeFixture, addCell4) {
	try {
		Life<ConwayCell> l(2,2);
		l.addCell('*', 1, 1);
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(LifeFixture, addCell5) {
	try {
		Life<Cell> l(2,2);
		l.addCell('8', 1, 1);
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(LifeFixture, addCell6) {
	Life<ConwayCell> l(2,2);

	ASSERT_EQ(l._population, 0);
	ASSERT_EQ(l.grid.size(), 4);
	ASSERT_EQ(l.grid.at(0), l.grid.at(3));

	l.addCell('*', 1, 1);

	ASSERT_EQ(l._population, 1);
	ASSERT_EQ(l.grid.size(), 4);
	ASSERT_TRUE(l.grid.at(0) != l.grid.at(3));
}

TEST(LifeFixture, addCell7) {
	Life<ConwayCell> l(2,2);

	ASSERT_EQ(l._population, 0);
	ASSERT_EQ(l.grid.size(), 4);
	ASSERT_EQ(l.grid.at(0), l.grid.at(3));

	l.addCell('.', 1, 1);

	ASSERT_EQ(l._population, 0);
	ASSERT_EQ(l.grid.size(), 4);
	ASSERT_EQ(l.grid.at(0), l.grid.at(3));
}
TEST(LifeFixture, addCell8) {
	Life<FredkinCell> l(2,2);

	ASSERT_EQ(l._population, 0);
	ASSERT_EQ(l.grid.size(), 4);
	ASSERT_EQ(l.grid.at(0), l.grid.at(3));

	l.addCell('-', 1, 1);

	ASSERT_EQ(l._population, 0);
	ASSERT_EQ(l.grid.size(), 4);
	ASSERT_EQ(l.grid.at(0), l.grid.at(3));
}
TEST(LifeFixture, addCell9) {
	Life<FredkinCell> l(2,2);

	ASSERT_EQ(l._population, 0);
	ASSERT_EQ(l.grid.size(), 4);
	ASSERT_EQ(l.grid.at(0), l.grid.at(3));

	l.addCell('0', 1, 1);

	ASSERT_EQ(l._population, 1);
	ASSERT_EQ(l.grid.size(), 4);
	ASSERT_TRUE(l.grid.at(0) != l.grid.at(3));
}
TEST(LifeFixture, addCell10) {
	Life<FredkinCell> l(2,2);

	ASSERT_EQ(l._population, 0);
	ASSERT_EQ(l.grid.size(), 4);
	ASSERT_EQ(l.grid.at(0), l.grid.at(3));

	l.addCell('+', 1, 1);

	ASSERT_EQ(l._population, 1);
	ASSERT_EQ(l.grid.size(), 4);
	ASSERT_TRUE(l.grid.at(0) != l.grid.at(3));
}
TEST(LifeFixture, addCell11) {
	Life<Cell> l(2,2);

	ASSERT_EQ(l._population, 0);
	ASSERT_EQ(l.grid.size(), 4);

	l.addCell('.', 1, 1);

	ASSERT_EQ(l._population, 0);
	ASSERT_EQ(l.grid.size(), 4);
}
TEST(LifeFixture, addCell12) {
	Life<Cell> l(2,2);

	ASSERT_EQ(l._population, 0);
	ASSERT_EQ(l.grid.size(), 4);

	l.addCell('-', 1, 1);

	ASSERT_EQ(l._population, 0);
	ASSERT_EQ(l.grid.size(), 4);
}
TEST(LifeFixture, addCell13) {
	Life<Cell> l(2,2);

	ASSERT_EQ(l._population, 0);
	ASSERT_EQ(l.grid.size(), 4);

	l.addCell('*', 0, 1);
	l.addCell('0', 1, 1);

	ASSERT_EQ(l._population, 2);
	ASSERT_EQ(l.grid.size(), 4);
	ASSERT_TRUE(l.grid.at(1) != l.grid.at(3));
}

// == countLivingNeighbors(int, int, bool) ==
TEST(LifeFixture, countLivingNeighbors1) {
	try {
		Life<ConwayCell> l(3,3);
		int rowPos = 1;
		int cellPos = 1;

		l.countLivingNeighbors(rowPos, cellPos, true);
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(LifeFixture, countLivingNeighbors2) {
	try {
		Life<FredkinCell> l(3,3);
		int rowPos = 1;
		int cellPos = 1;

		l.countLivingNeighbors(rowPos, cellPos, false);
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(LifeFixture, countLivingNeighbors3) {
	try {
		Life<Cell> l(3,3);
		int rowPos = 1;
		int cellPos = 1;

		l.countLivingNeighbors(rowPos, cellPos, false);

		ASSERT_EQ(true, false);
	}
	catch(exception& e) {
		ASSERT_EQ(true, true);
	}
}
TEST(LifeFixture, countLivingNeighbors4) {
	try {
		Life<Cell> l(3,3);
		int rowPos = 1;
		int cellPos = 1;

		for(int i = 0; i < 3; ++i){
			for(int j = 0; j < 3; ++j) {
				l.addCell('.', i, j);
			}
		}

		
		l.countLivingNeighbors(rowPos, cellPos, false);
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(LifeFixture, countLivingNeighbors5) {
	Life<ConwayCell> l(3,3);
	int rowPos = 1;
	int cellPos = 1;

	int count = l.countLivingNeighbors(rowPos, cellPos, true);

	ASSERT_EQ(count, 0);
}
TEST(LifeFixture, countLivingNeighbors6) {
	Life<ConwayCell> l(3,3);
	int rowPos = 1;
	int cellPos = 1;

	l.addCell('*', 0, 0);

	int count = l.countLivingNeighbors(rowPos, cellPos, true);

	ASSERT_EQ(count, 1);
}
TEST(LifeFixture, countLivingNeighbors7) {
	Life<ConwayCell> l(3,3);
	int rowPos = 1;
	int cellPos = 1;

	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			l.addCell('*', i, j);
		}
	}

	int count = l.countLivingNeighbors(rowPos, cellPos, true);

	ASSERT_EQ(count, 8);
}
TEST(LifeFixture, countLivingNeighbors8) {
	Life<ConwayCell> l(3,3);
	int rowPos = 0;
	int cellPos = 1;

	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			l.addCell('*', i, j);
		}
	}

	int count = l.countLivingNeighbors(rowPos, cellPos, true);

	ASSERT_EQ(count, 5);
}
TEST(LifeFixture, countLivingNeighbors9) {
	Life<ConwayCell> l(3,3);
	int rowPos = 0;
	int cellPos = 0;

	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			l.addCell('*', i, j);
		}
	}

	int count = l.countLivingNeighbors(rowPos, cellPos, true);

	ASSERT_EQ(count, 3);
}
TEST(LifeFixture, countLivingNeighbors10) {
	Life<FredkinCell> l(3,3);
	int rowPos = 1;
	int cellPos = 1;

	int count = l.countLivingNeighbors(rowPos, cellPos, false);

	ASSERT_EQ(count, 0);
}
TEST(LifeFixture, countLivingNeighbors11) {
	Life<FredkinCell> l(3,3);
	int rowPos = 1;
	int cellPos = 1;

	l.addCell('0', 0, 0);

	int count = l.countLivingNeighbors(rowPos, cellPos, false);

	ASSERT_EQ(count, 0);
}
TEST(LifeFixture, countLivingNeighbors12) {
	Life<FredkinCell> l(3,3);
	int rowPos = 1;
	int cellPos = 1;

	l.addCell('0', 0, 1);

	int count = l.countLivingNeighbors(rowPos, cellPos, false);

	ASSERT_EQ(count, 1);
}
TEST(LifeFixture, countLivingNeighbors13) {
	Life<FredkinCell> l(3,3);
	int rowPos = 1;
	int cellPos = 1;

	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			l.addCell('0', i, j);
		}
	}

	int count = l.countLivingNeighbors(rowPos, cellPos, false);

	ASSERT_EQ(count, 4);
}
TEST(LifeFixture, countLivingNeighbors14) {
	Life<FredkinCell> l(3,3);
	int rowPos = 2;
	int cellPos = 1;

	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			l.addCell('0', i, j);
		}
	}

	int count = l.countLivingNeighbors(rowPos, cellPos, false);

	ASSERT_EQ(count, 3);
}
TEST(LifeFixture, countLivingNeighbors15) {
	Life<FredkinCell> l(3,3);
	int rowPos = 2;
	int cellPos = 2;

	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			l.addCell('0', i, j);
		}
	}

	int count = l.countLivingNeighbors(rowPos, cellPos, false);

	ASSERT_EQ(count, 2);
}
TEST(LifeFixture, countLivingNeighbors16) {
	Life<Cell> l(3,3);
	int rowPos = 1;
	int cellPos = 1;

	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			if(j < 2)
				l.addCell('*', i, j);
			else
				l.addCell('0', i, j);
		}
	}

	int count = l.countLivingNeighbors(rowPos, cellPos, true);

	ASSERT_EQ(count, 8);
}
TEST(LifeFixture, countLivingNeighbors17) {
	Life<Cell> l(3,3);
	int rowPos = 2;
	int cellPos = 1;

	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			if(j < 2)
				l.addCell('*', i, j);
			else
				l.addCell('0', i, j);
		}
	}

	int count = l.countLivingNeighbors(rowPos, cellPos, false);

	ASSERT_EQ(count, 3);
}
TEST(LifeFixture, countLivingNeighbors18) {
	Life<Cell> l(3,3);
	int rowPos = 2;
	int cellPos = 2;

	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			if(j < 2)
				l.addCell('*', i, j);
			else
				l.addCell('0', i, j);
		}
	}

	int count = l.countLivingNeighbors(rowPos, cellPos, false);

	ASSERT_EQ(count, 2);
}
TEST(LifeFixture, countLivingNeighbors19) {
	Life<Cell> l(3,3);
	int rowPos = 1;
	int cellPos = 1;

	l.addCell('.', 0, 0);
	l.addCell('0', 0, 1);	// alive
	l.addCell('+', 0, 2);	// alive
	l.addCell('-', 1, 0);
	l.addCell('.', 1, 1);
	l.addCell('-', 1, 2);
	l.addCell('3', 2, 0);	// alive
	l.addCell('*', 2, 1);	// alive
	l.addCell('.', 2, 2);

	int count = l.countLivingNeighbors(rowPos, cellPos, true);

	ASSERT_EQ(count, 4);
}

// == simulate() ==
TEST(LifeFixture, simulate) {
	Life<Cell> l(3,3);
	ostringstream oss;
	string str;
	
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			if(j < 2)
				l.addCell('.', i, j);
			else
				l.addCell('0', i, j);
		}
	}

	l.simulate(2, 0, true, 1, oss);

	str = oss.str();

	ASSERT_EQ(str, "Generation = 0, Population = 3.\n..0\n..0\n..0\n\nGeneration = 1, Population = 3.\n..1\n.*-\n..1\n\nGeneration = 2, Population = 2.\n..-\n.*0\n..-\n\n");
}
// == operator <<()/ write() ==
TEST(LifeFixture, stream1) {
	try {
		Life<ConwayCell> l(2,2);
		ostringstream oss;

		oss << l;
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(LifeFixture, stream2) {
	try {
		Life<FredkinCell> l(2,2);
		ostringstream oss;

		oss << l;
	}
	catch(exception& e) {
		ASSERT_EQ(true, false);
	}
}
TEST(LifeFixture, stream3) {
	try {
		Life<Cell> l(2,2);
		ostringstream oss;

		oss << l;

		ASSERT_EQ(true, false);
	}
	catch(exception& e) {
		ASSERT_EQ(true, true);
	}
}
TEST(LifeFixture, stream4) {
	Life<ConwayCell> l(2,2);
	ostringstream oss;

	oss << l;
	string str;

	str = oss.str();

	ASSERT_EQ(str, "..\n..\n\n");
}
TEST(LifeFixture, stream5) {
	Life<ConwayCell> l(2,2);
	l.addCell('*', 0, 0);
	l.addCell('*', 1, 1);
	ostringstream oss;

	oss << l;
	string str;

	str = oss.str();

	ASSERT_EQ(str, "*.\n.*\n\n");
}
TEST(LifeFixture, stream6) {
	Life<FredkinCell> l(2,2);
	ostringstream oss;

	oss << l;
	string str;

	str = oss.str();

	ASSERT_EQ(str, "--\n--\n\n");
}
TEST(LifeFixture, stream7) {
	Life<FredkinCell> l(2,2);
	l.addCell('+', 0, 0);
	l.addCell('0', 1, 1);
	ostringstream oss;

	oss << l;
	string str;

	str = oss.str();

	ASSERT_EQ(str, "+-\n-0\n\n");
}