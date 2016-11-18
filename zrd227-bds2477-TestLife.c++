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
#include <cassert>
#include <iostream>

#include "Life.h"

using namespace std;

// ----
// test
// ----

TEST(LifeFixture, LifeConstructorTest1) {
    ostringstream output;
	istringstream input("...*.*...*\n...*.*...*\n...*.*...*\n");
    Life<ConwayCell> life(3, 10, input);
    output << life;
    ASSERT_EQ(input.str(), output.str());
}

TEST(LifeFixture, LifeConstructorTest2) {
    ostringstream output;
	istringstream input("---0-0----\n---0-0----\n---0-0----\n");
    Life<FredkinCell> life(3, 10, input);
    output << life;
    ASSERT_EQ(input.str(), output.str());
}

TEST(LifeFixture, LifeConstructorTest3) {
    ostringstream output;
	istringstream input("-\n");
    Life<FredkinCell> life(1, 1, input);
    output << life;
    ASSERT_EQ(input.str(), output.str());
}

TEST(LifeFixture, LifeConstructorTest4) {
    ostringstream output;
	istringstream input(".\n");
    Life<ConwayCell> life(1, 1, input);
    output << life;
    ASSERT_EQ(input.str(), output.str());
}

TEST(LifeFixture, LifeConstructorTest5) {
    ostringstream output;
	istringstream input("-\n");
    Life<Cell> life(1, 1, input);
    output << life;
    ASSERT_EQ(input.str(), output.str());
}

TEST(LifeFixture, LifeConstructorTest6) {
    ostringstream output;
	istringstream input("0\n");
    Life<Cell> life(1, 1, input);
    output << life;
    ASSERT_EQ(input.str(), output.str());
}

TEST(LifeFixture, LifeConstructorTest7) {
    ostringstream output;
	istringstream input("-0\n");
    Life<Cell> life(1, 2, input);
    output << life;
    ASSERT_EQ(input.str(), output.str());
}

TEST(LifeFixture, LifeConstructorTest8) {
    ostringstream output;
	istringstream input("0-\n");
    Life<Cell> life(1, 2, input);
    output << life;
    ASSERT_EQ(input.str(), output.str());
}

TEST(LifeFixture, LifeConstructorTest9) {
    ostringstream output;
	istringstream input("--\n");
    Life<Cell> life(1, 2, input);
    output << life;
    ASSERT_EQ(input.str(), output.str());
}

TEST(LifeFixture, LifeConstructorTest10) {
    ostringstream output;
	istringstream input("00\n");
    Life<Cell> life(1, 2, input);
    output << life;
    ASSERT_EQ(input.str(), output.str());
}

TEST(LifeFixture, LifeConstructorTest11) {
    ostringstream output;
	istringstream input("0-0\n");
    Life<Cell> life(1, 3, input);
    output << life;
    ASSERT_EQ(input.str(), output.str());
}

TEST(LifeFixture, LifeMakeMoveTest1) {
    ostringstream output;
	istringstream input(".....\n*....\n....*\n");
    Life<ConwayCell> life(3, 5, input);
    life.makeMove();
    output << life;
    string expected = ".....\n.....\n.....\n";
    ASSERT_EQ(expected, output.str());
}

TEST(LifeFixture, LifeMakeMoveTest2) {
    ostringstream output;
	istringstream input("0---0\n--0--\n0---0\n");
    Life<FredkinCell> life(3, 5, input);
    life.makeMove();
    output << life;
    string expected = "-000-\n-0-0-\n-000-\n";
    ASSERT_EQ(expected, output.str());
}

TEST(LifeFixture, LifeMakeMoveTest3) {
    ostringstream output;
	istringstream input("--0--\n--00-\n--0--\n");
    Life<FredkinCell> life(3, 5, input);
    for(int a = 0; a<5; ++a)
	    life.makeMove();
    output << life;
    string expected = "30--3\n-2132\n30--3\n";
    ASSERT_EQ(expected, output.str());
}

TEST(LifeFixture, LifeMakeMoveTest4) {
    ostringstream output;
	istringstream input(".....\n**.**\n...**\n");
    Life<ConwayCell> life(3, 5, input);
    life.makeMove();
    output << life;
    string expected = ".....\n..***\n..***\n";
    ASSERT_EQ(expected, output.str());
}

TEST(LifeFixture, LifeMakeMoveTest5) {
    ostringstream output;
	istringstream input("....*\n**.**\n.....\n");
    Life<ConwayCell> life(3, 5, input);
    life.makeMove();
    output << life;
    string expected = "...**\n...**\n.....\n";
    ASSERT_EQ(expected, output.str());
}

TEST(LifeFixture, LifeMakeMoveTest6) {
    ostringstream output;
	istringstream input(".....\n**.**\n...**\n");
    Life<ConwayCell> life(3, 5, input);
    for(int a = 0; a<5; ++a)
	    life.makeMove();
    output << life;
    string expected = ".....\n.....\n.....\n";
    ASSERT_EQ(expected, output.str());
}

TEST(LifeFixture, LifeMakeMoveTest7) {
    ostringstream output;
	istringstream input("....*\n**.**\n.....\n");
    Life<ConwayCell> life(3, 5, input);
    for(int a = 0; a<5; ++a)
	    life.makeMove();
    output << life;
    string expected = "...**\n...**\n.....\n";
    ASSERT_EQ(expected, output.str());
}

// TEST(LifeFixture, LifeMakeMoveTest8) {
//     ostringstream output;
// 	istringstream input("--------\n---00---\n--0000--\n--------\n--------\n--------\n");
//     Life<Cell> life(6, 8, input);
// 	life.makeMove();
//     output << life;
//     string expected = "--------\n---00---\n--------\n-011110-\n--0000--\n--------\n";
//     ASSERT_EQ(expected, output.str());
// }

TEST(ConwayCellFixture, ConwayCellConstructor1) {
	ConwayCell cell('.');
	ostringstream output;
	output << cell;
	ASSERT_EQ(".", output.str());
}

TEST(ConwayCellFixture, ConwayCellConstructor2) {
	ConwayCell cell('*');
	ostringstream output;
	output << cell;
	ASSERT_EQ("*", output.str());
}

TEST(ConwayCellFixture, ConwayCellMakeMove1) {
	ConwayCell cell('.');
	AbstractCell* neighbors[8] = {nullptr, new ConwayCell('*'), new ConwayCell('*'), 
		new ConwayCell('*'), nullptr, nullptr, new ConwayCell('.'), new ConwayCell('.')};
	cell.nextState(neighbors);
	ostringstream output;
	output << cell;
	ASSERT_EQ("*", output.str());
}

TEST(ConwayCellFixture, ConwayCellMakeMove2) {
	ConwayCell cell('.');
	AbstractCell* neighbors[8] = {new ConwayCell('*'), new ConwayCell('*'), new ConwayCell('*'), 
		new ConwayCell('*'), nullptr, nullptr, new ConwayCell('.'), new ConwayCell('.')};
	cell.nextState(neighbors);
	ostringstream output;
	output << cell;
	ASSERT_EQ(".", output.str());
}

TEST(ConwayCellFixture, ConwayCellMakeMove3) {
	ConwayCell cell('*');
	AbstractCell* neighbors[8] = {nullptr, new ConwayCell('.'), new ConwayCell('.'), 
		new ConwayCell('*'), nullptr, nullptr, new ConwayCell('.'), new ConwayCell('.')};
	cell.nextState(neighbors);
	ostringstream output;
	output << cell;
	ASSERT_EQ(".", output.str());
}

TEST(ConwayCellFixture, ConwayCellMakeMove4) {
	ConwayCell cell('*');
	AbstractCell* neighbors[8] = {nullptr, new ConwayCell('*'), new ConwayCell('.'), 
		new ConwayCell('*'), nullptr, nullptr, new ConwayCell('*'), new ConwayCell('*')};
	cell.nextState(neighbors);
	ostringstream output;
	output << cell;
	ASSERT_EQ(".", output.str());
}

TEST(ConwayCellFixture, ConwayCellMakeMove5) {
	ConwayCell cell('*');
	AbstractCell* neighbors[8] = {nullptr, new ConwayCell('*'), new ConwayCell('*'), 
		new ConwayCell('*'), nullptr, nullptr, new ConwayCell('.'), new ConwayCell('.')};
	cell.nextState(neighbors);
	ostringstream output;
	output << cell;
	ASSERT_EQ("*", output.str());
}

TEST(FredkinCellFixture, ConwayCellCopyAssignment1) {
	ConwayCell cell1('*');
	ConwayCell cell2('.');
	cell1 = cell2;
	ostringstream output;
	output << cell1;
	ASSERT_EQ(".", output.str());
}

TEST(FredkinCellFixture, FredkinCellConstructor1) {
	FredkinCell cell('0');
	ostringstream output;
	output << cell;
	ASSERT_EQ("0", output.str());
}

TEST(FredkinCellFixture, FredkinCellConstructor2) {
	FredkinCell cell('-');
	ostringstream output;
	output << cell;
	ASSERT_EQ("-", output.str());
}

TEST(FredkinCellFixture, FredkinCellMakeMove1) {
	FredkinCell cell('-');
	AbstractCell* neighbors[8] = {nullptr, new FredkinCell('0'), new FredkinCell('-'), 
		new FredkinCell('-'), nullptr, nullptr, new FredkinCell('-'), new FredkinCell('-')};
	cell.nextState(neighbors);
	ostringstream output;
	output << cell;
	ASSERT_EQ("0", output.str());
}

TEST(FredkinCellFixture, FredkinCellMakeMove2) {
	FredkinCell cell('-');
	AbstractCell* neighbors[8] = {nullptr, new FredkinCell('-'), new FredkinCell('0'), 
		new FredkinCell('0'), nullptr, nullptr, new FredkinCell('-'), new FredkinCell('0')};
	cell.nextState(neighbors);
	ostringstream output;
	output << cell;
	ASSERT_EQ("0", output.str());
}

TEST(FredkinCellFixture, FredkinCellMakeMove3) {
	FredkinCell cell('-');
	AbstractCell* neighbors[8] = {nullptr, new FredkinCell('-'), new FredkinCell('0'), 
		new FredkinCell('0'), nullptr, nullptr, new FredkinCell('-'), new FredkinCell('-')};
	cell.nextState(neighbors);
	ostringstream output;
	output << cell;
	ASSERT_EQ("0", output.str());
}

TEST(FredkinCellFixture, FredkinCellMakeMove4) {
	FredkinCell cell('0');
	AbstractCell* neighbors[8] = {nullptr, new FredkinCell('-'), new FredkinCell('-'), 
		new FredkinCell('-'), nullptr, nullptr, new FredkinCell('-'), new FredkinCell('-')};
	cell.nextState(neighbors);
	ostringstream output;
	output << cell;
	ASSERT_EQ("-", output.str());
}

TEST(FredkinCellFixture, FredkinCellMakeMove5) {
	FredkinCell cell('0');
	AbstractCell* neighbors[8] = {nullptr, new FredkinCell('0'), new FredkinCell('-'), 
		new FredkinCell('0'), nullptr, nullptr, new FredkinCell('0'), new FredkinCell('0')};
	cell.nextState(neighbors);
	ostringstream output;
	output << cell;
	ASSERT_EQ("1", output.str());
}

TEST(FredkinCellFixture, FredkinCellMakeMove6) {
	FredkinCell cell('0');
	AbstractCell* neighbors[8] = {nullptr, new FredkinCell('0'), new FredkinCell('-'), 
		new FredkinCell('0'), nullptr, nullptr, new FredkinCell('0'), new FredkinCell('0')};
	cell.nextState(neighbors);
	cell.nextState(neighbors);
	ostringstream output;
	output << cell;
	ASSERT_EQ("2", output.str());
}

TEST(FredkinCellFixture, FredkinCellMakeMove7) {
	FredkinCell cell('0');
	AbstractCell* neighbors[8] = {nullptr, new FredkinCell('0'), new FredkinCell('-'), 
		new FredkinCell('0'), nullptr, nullptr, new FredkinCell('0'), new FredkinCell('0')};
	for(int a = 0; a<15; ++a)	
		cell.nextState(neighbors);
	ostringstream output;
	output << cell;
	ASSERT_EQ("+", output.str());
}

TEST(FredkinCellFixture, FredkinCellMakeMove8) {
	Cell cell('0');
	AbstractCell* neighbors[8] = {nullptr, new FredkinCell('0'), new FredkinCell('-'), 
		new FredkinCell('0'), nullptr, nullptr, new FredkinCell('0'), new FredkinCell('0')};
	for(int a = 0; a<15; ++a)	
		cell.nextState(neighbors);
	ostringstream output;
	output << cell;
	ASSERT_EQ("+", output.str());
}

TEST(FredkinCellFixture, FredkinCellMakeMove9) {
	Cell cell('-');
	AbstractCell* neighbors[8] = {nullptr, nullptr, nullptr, 
		nullptr, nullptr, nullptr, nullptr, nullptr};
	for(int a = 0; a<15; ++a)	
		cell.nextState(neighbors);
	ostringstream output;
	output << cell;
	ASSERT_EQ("-", output.str());
}

TEST(FredkinCellFixture, FredkinCellCopyAssignment1) {
	FredkinCell cell1('0');
	FredkinCell cell2('-');
	AbstractCell* neighbors[8] = {nullptr, new FredkinCell('0'), new FredkinCell('-'), 
		new FredkinCell('0'), nullptr, nullptr, new FredkinCell('0'), new FredkinCell('0')};
	cell1.nextState(neighbors);
	cell1.nextState(neighbors);
	cell1 = cell2;
	ostringstream output;
	output << cell1;
	ASSERT_EQ("-", output.str());
}

TEST(FredkinCellFixture, FredkinCellCopyAssignment2) {
	FredkinCell cell1('0');
	FredkinCell cell2('-');
	cell1 = cell2;
	ostringstream output;
	output << cell1;
	ASSERT_EQ("-", output.str());
}

TEST(FredkinCellFixture, FredkinCellCopyAssignment3) {
	FredkinCell cell1('-');
	FredkinCell cell2('0');
	cell1 = cell2;
	ostringstream output;
	output << cell1;
	ASSERT_EQ("0", output.str());
}

TEST(AbstractCellFixture, AbstractCellCheckState1) {
	ConwayCell cell('*');
	ASSERT_TRUE(cell.checkState());
}

TEST(AbstractCellFixture, AbstractCellCheckState2) {
	ConwayCell cell('.');
	ASSERT_FALSE(cell.checkState());
}

TEST(AbstractCellFixture, AbstractCellCheckState3) {
	FredkinCell cell('0');
	ASSERT_TRUE(cell.checkState());
}

TEST(AbstractCellFixture, AbstractCellCheckState4) {
	FredkinCell cell('-');
	ASSERT_FALSE(cell.checkState());
}

TEST(AbstractCellFixture, AbstractCellCheckState5) {
	Cell cell('-');
	ASSERT_FALSE(cell.checkState());
}

TEST(AbstractCellFixture, AbstractCellCheckState6) {
	Cell cell('0');
	ASSERT_TRUE(cell.checkState());
}

TEST(AbstractCellFixture, AbstractCellCheckState7) {
	Cell cell('.');
	ASSERT_FALSE(cell.checkState());
}

TEST(AbstractCellFixture, AbstractCellCheckState8) {
	Cell cell('*');
	ASSERT_TRUE(cell.checkState());
}

TEST(AbstractCellFixture, AbstractCellCheckState9) {
	Cell cell('-');
	ASSERT_FALSE(cell.checkState());
}

TEST(AbstractCellFixture, AbstractCellCheckState10) {
	FredkinCell cell('0');
	AbstractCell* neighbors[8] = {nullptr, new FredkinCell('0'), new FredkinCell('-'), 
		new FredkinCell('0'), nullptr, nullptr, new FredkinCell('0'), new FredkinCell('0')};
	for(int a = 0; a<15; ++a)	
		cell.nextState(neighbors);
	ASSERT_TRUE(cell.checkState());
}

TEST(AbstractCellFixture, AbstractCellCopyAssignment1) {
	ConwayCell cell1('.');
	ConwayCell cell2('*');
	cell1 = cell2;
	ASSERT_TRUE(cell1.checkState());
}

TEST(AbstractCellFixture, AbstractCellCopyAssignment2) {
	ConwayCell cell1('*');
	ConwayCell cell2('.');
	cell1 = cell2;
	ASSERT_FALSE(cell1.checkState());
}

TEST(AbstractCellFixture, AbstractCellCopyAssignment3) {
	FredkinCell cell1('-');
	FredkinCell cell2('0');
	cell1 = cell2;
	ASSERT_TRUE(cell1.checkState());
}

TEST(AbstractCellFixture, AbstractCellCopyAssignment4) {
	FredkinCell cell1('0');
	FredkinCell cell2('-');
	cell1 = cell2;
	ASSERT_FALSE(cell1.checkState());
}


TEST(AbstractCellFixture, CellCopyAssignment1) {
	Cell cell1('0');
	Cell cell2('-');
	cell1 = cell2;
	ASSERT_FALSE(cell1.checkState());
}

TEST(AbstractCellFixture, CellCopyAssignment2) {
	Cell cell1('0');
	Cell cell2('-');
	cell2 = cell1;
	ASSERT_TRUE(cell2.checkState());
}

TEST(AbstractCellFixture, CellCopyAssignment3) {
	Cell cell1('.');
	Cell cell2('0');
	cell2 = cell1;
	ASSERT_FALSE(cell2.checkState());
}

TEST(AbstractCellFixture, CellCopyAssignment4) {
	Cell cell1('0');
	Cell cell2('.');
	cell1 = cell2;
	ASSERT_FALSE(cell1.checkState());
}

TEST(AbstractCellFixture, CellCopyAssignment5) {
	Cell cell1('-');
	Cell cell2('.');
	cell1 = cell2;
	ASSERT_FALSE(cell1.checkState());
}

TEST(AbstractCellFixture, CellCopyAssignment6) {
	Cell cell1('.');
	Cell cell2('-');
	cell1 = cell2;
	ASSERT_FALSE(cell1.checkState());
}
