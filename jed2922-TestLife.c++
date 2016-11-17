/** @file TestLife.c++
 *  @brief Unit Test code for Life's World
 *
 *  @author Javier E. De la Garza Sanchez (jed2922)
 *  @author Jonathan Velasquez (jlv785)
 *  @bug 
 */

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

#include "Life.h"

using namespace std;

// --------
// TestLife
// --------

// -------------------
// Abstract Cell Tests
// -------------------

/**
 * isAlive() Tests
*/
TEST(AbstractCell_isAlive, isAlive_1) {
	Life<ConwayCell> game_board(1, 1);
	game_board.addCell(0, 0, false, -1);
	ASSERT_FALSE(game_board._board[0]->isAlive());
}

TEST(AbstractCell_isAlive, isAlive_2) {
    Life<FredkinCell> game_board(1, 1);
	game_board.addCell(0, 0, true, 1);
	ASSERT_TRUE(game_board._board[0]->isAlive());
}

TEST(AbstractCell_isAlive, isAlive_3) {
    Life<Cell> game_board(1, 1);
	game_board.addCell(0, 0, false, 1);
	ASSERT_FALSE(game_board._board[0]->isAlive());
}

/**
 * shouldSwitch() Tests
*/
TEST(AbstractCell_shouldSwitch, shouldSwitch_1) {
    Life<ConwayCell> game_board(1, 1);
	game_board.addCell(0, 0, false, -1);
	ASSERT_FALSE(game_board._board[0]->shouldSwitch());
}

TEST(AbstractCell_shouldSwitch, shouldSwitch_2) {
    Life<ConwayCell> game_board(1, 1);
	game_board.addCell(0, 0, true, -1);
	ASSERT_FALSE(game_board._board[0]->shouldSwitch());
}

// -----------------
// Conway Cell Tests
// -----------------

/**
 * clone() Tests
*/
TEST(ConwayCell_Clone, clone_1) {
	Life<ConwayCell> game_board(1, 1);
	game_board.addCell(0, 0, true, -1);
	ConwayCell* c = game_board._board[0]->clone();
	ASSERT_EQ(game_board._board[0]->isAlive(), c->isAlive());
}

TEST(ConwayCell_Clone, clone_2) {
    Life<ConwayCell> game_board(1, 1);
	game_board.addCell(0, 0, false, -1);
	ConwayCell* c = game_board._board[0]->clone();
	ASSERT_EQ(game_board._board[0]->isAlive(), c->isAlive());
}

TEST(ConwayCell_Clone, clone_3) {
    Life<ConwayCell> game_board(1, 1);
	game_board.addCell(0, 0, true, -1);
	ConwayCell* c = game_board._board[0]->clone();
	ASSERT_EQ(game_board._board[0]->shouldSwitch(), c->shouldSwitch());
}

/**
 * takeTurn() Tests
*/
TEST(ConwayCell_takeTurn, takeTurn_1) {
	Life<ConwayCell> game_board(1, 1);
	game_board.addCell(0, 0, false, -1);
	game_board._board[0]->takeTurn(3);
	ASSERT_TRUE(game_board._board[0]->isAlive());
}

TEST(ConwayCell_takeTurn, takeTurn_2) {
	Life<ConwayCell> game_board(1, 1);
	game_board.addCell(0, 0, false, -1);
	game_board._board[0]->takeTurn(4);
	ASSERT_FALSE(game_board._board[0]->isAlive());   
}

TEST(ConwayCell_takeTurn, takeTurn_3) {
	Life<ConwayCell> game_board(1, 1);
	game_board.addCell(0, 0, false, -1);
	game_board._board[0]->takeTurn(2);
	ASSERT_FALSE(game_board._board[0]->isAlive());
}

TEST(ConwayCell_takeTurn, takeTurn_4) {
	Life<ConwayCell> game_board(1, 1);
	game_board.addCell(0, 0, true, -1);
	game_board._board[0]->takeTurn(1);
	ASSERT_FALSE(game_board._board[0]->isAlive());
}

TEST(ConwayCell_takeTurn, takeTurn_5) {
	Life<ConwayCell> game_board(1, 1);
	game_board.addCell(0, 0, true, -1);
	game_board._board[0]->takeTurn(4);
	ASSERT_FALSE(game_board._board[0]->isAlive());   
}

TEST(ConwayCell_takeTurn, takeTurn_6) {
	Life<ConwayCell> game_board(1, 1);
	game_board.addCell(0, 0, true, -1);
	game_board._board[0]->takeTurn(2);
	ASSERT_TRUE(game_board._board[0]->isAlive());
}

TEST(ConwayCell_takeTurn, takeTurn_7) {
	Life<ConwayCell> game_board(1, 1);
	game_board.addCell(0, 0, true, -1);
	game_board._board[0]->takeTurn(3);
	ASSERT_TRUE(game_board._board[0]->isAlive());
}

/**
 * print() Tests
*/
TEST(ConwayCell_Print, print_1) {
	stringstream buffer;
	streambuf* cbuf = cout.rdbuf();
	cout.rdbuf(buffer.rdbuf());

	Life<ConwayCell> game_board(1, 1);
	game_board.addCell(0, 0, true, -1);
	game_board._board[0]->print();

	ASSERT_EQ('*', buffer.peek());

	cout.rdbuf(cbuf);
}

TEST(ConwayCell_Print, print_2) {
    stringstream buffer;
	streambuf* cbuf = cout.rdbuf();
	cout.rdbuf(buffer.rdbuf());

	Life<ConwayCell> game_board(1, 1);
	game_board.addCell(0, 0, false, -1);
	game_board._board[0]->print();

	ASSERT_EQ('.', buffer.peek());

	cout.rdbuf(cbuf);
}

// ------------------
// Fredkin Cell Tests
// ------------------

/**
 * clone() Tests
*/
TEST(FredkinCell_Clone, clone_1) {
	Life<FredkinCell> game_board(1, 1);
	game_board.addCell(0, 0, true, 0);
	FredkinCell* c = game_board._board[0]->clone();
	ASSERT_NE(game_board._board[0], c);
}

TEST(FredkinCell_Clone, clone_2) {
    Life<FredkinCell> game_board(1, 1);
	game_board.addCell(0, 0, false, 1);
	FredkinCell* c = game_board._board[0]->clone();
	ASSERT_EQ(game_board._board[0]->isAlive(), c->isAlive());
}

TEST(FredkinCell_Clone, clone_3) {
    Life<FredkinCell> game_board(1, 1);
	game_board.addCell(0, 0, true, 2);
	FredkinCell* c = game_board._board[0]->clone();
	ASSERT_EQ(game_board._board[0]->shouldSwitch(), c->shouldSwitch());
}

/**
 * shouldSwitch() Tests
*/
TEST(FredkinCell_shouldSwitch, shouldSwitch_1) {
    Life<FredkinCell> game_board(1, 1);
	game_board.addCell(0, 0, true, 0);
	ASSERT_FALSE(game_board._board[0]->shouldSwitch());
}

TEST(FredkinCell_shouldSwitch, shouldSwitch_2) {
    Life<FredkinCell> game_board(1, 1);
	game_board.addCell(0, 0, true, 1);
	ASSERT_FALSE(game_board._board[0]->shouldSwitch());
}

TEST(FredkinCell_shouldSwitch, shouldSwitch_3) {
    Life<FredkinCell> game_board(1, 1);
	game_board.addCell(0, 0, true, 2);
	ASSERT_TRUE(game_board._board[0]->shouldSwitch());
}

TEST(FredkinCell_shouldSwitch, shouldSwitch_4) {
    Life<FredkinCell> game_board(1, 1);
	game_board.addCell(0, 0, true, 10);
	ASSERT_TRUE(game_board._board[0]->shouldSwitch());
}

/**
 * takeTurn() Tests
*/
TEST(FredkinCell_takeTurn, takeTurn_1) {
	Life<FredkinCell> game_board(1, 1);
	game_board.addCell(0, 0, false, 0);
	game_board._board[0]->takeTurn(1);
	ASSERT_TRUE(game_board._board[0]->isAlive());
}

TEST(FredkinCell_takeTurn, takeTurn_2) {
    Life<FredkinCell> game_board(1, 1);
	game_board.addCell(0, 0, false, 0);
	game_board._board[0]->takeTurn(3);
	ASSERT_TRUE(game_board._board[0]->isAlive());
}

TEST(FredkinCell_takeTurn, takeTurn_3) {
    Life<FredkinCell> game_board(1, 1);
	game_board.addCell(0, 0, true, 0);
	game_board._board[0]->takeTurn(0);
	ASSERT_FALSE(game_board._board[0]->isAlive());
}

TEST(FredkinCell_takeTurn, takeTurn_4) {
    Life<FredkinCell> game_board(1, 1);
	game_board.addCell(0, 0, true, 0);
	game_board._board[0]->takeTurn(2);
	ASSERT_FALSE(game_board._board[0]->isAlive());
}

TEST(FredkinCell_takeTurn, takeTurn_5) {
    Life<FredkinCell> game_board(1, 1);
	game_board.addCell(0, 0, true, 0);
	game_board._board[0]->takeTurn(4);
	ASSERT_FALSE(game_board._board[0]->isAlive());
}

/**
 * print() Tests
*/
TEST(FredkinCell_Print, print_1) {
    stringstream buffer;
	streambuf* cbuf = cout.rdbuf();
	cout.rdbuf(buffer.rdbuf());

	Life<FredkinCell> game_board(1, 1);
	game_board.addCell(0, 0, true, 5);
	game_board._board[0]->print();

	ASSERT_EQ('5', buffer.peek());

	cout.rdbuf(cbuf);
}

TEST(FredkinCell_Print, print_2) {
    stringstream buffer;
	streambuf* cbuf = cout.rdbuf();
	cout.rdbuf(buffer.rdbuf());

	Life<FredkinCell> game_board(1, 1);
	game_board.addCell(0, 0, true, 10);
	game_board._board[0]->print();

	ASSERT_EQ('+', buffer.peek());

	cout.rdbuf(cbuf);
}

TEST(FredkinCell_Print, print_3) {
	stringstream buffer;
	streambuf* cbuf = cout.rdbuf();
	cout.rdbuf(buffer.rdbuf());

	Life<FredkinCell> game_board(1, 1);
	game_board.addCell(0, 0, false, 10);
	game_board._board[0]->print();

	ASSERT_EQ('-', buffer.peek());

	cout.rdbuf(cbuf);
    
}

// --------------
// CellCell Tests
// --------------

/**
 * Cell Constructor Tests
*/
TEST(Cell_Constructor, cell_constructor_1) {
    Life<Cell> game_board(1, 1);
	game_board.addCell(0, 0, true, 0);
	Cell* c = game_board._board[0]->clone();
	ASSERT_NE(game_board._board[0], c);
}

TEST(Cell_Constructor, cell_constructor_2) {
    Life<Cell> game_board(1, 1);
	game_board.addCell(0, 0, true, 2);
	Cell* c = game_board._board[0]->clone();
	ASSERT_NE(game_board._board[0], c);
}

TEST(Cell_Constructor, cell_constructor_3) {
	Life<Cell> game_board(1, 1);
	game_board.addCell(0, 0, false, 10);
	Cell* c = game_board._board[0]->clone();
	ASSERT_NE(game_board._board[0], c);
}

/**
 * clone() Tests
*/
TEST(Cell_Clone, clone_1) {
	Life<Cell> game_board(1, 1);
	game_board.addCell(0, 0, true, 0);
	Cell* c = game_board._board[0]->clone();
	ASSERT_NE(game_board._board[0], c);
}

TEST(Cell_Clone, clone_2) {
    Life<Cell> game_board(1, 1);
	game_board.addCell(0, 0, false, 1);
	Cell* c = game_board._board[0]->clone();
	ASSERT_EQ(game_board._board[0]->isAlive(), c->isAlive());
}

TEST(Cell_Clone, clone_3) {
    Life<Cell> game_board(1, 1);
	game_board.addCell(0, 0, true, 2);
	Cell* c = game_board._board[0]->clone();
	ASSERT_EQ(game_board._board[0]->isAlive(), c->isAlive());
}

/**
 * takeTurn() Tests
*/
TEST(CellCell_takeTurn, takeTurn_1) {
	Life<Cell> game_board(1, 1);
	game_board.addCell(0, 0, false, 0);
	game_board._board[0]->takeTurn(1);
	ASSERT_TRUE(game_board._board[0]->isAlive());
}

TEST(CellCell_takeTurn, takeTurn_2) {
    Life<Cell> game_board(1, 1);
	game_board.addCell(0, 0, true, 10);
	game_board._board[0]->takeTurn(2);
	ASSERT_TRUE(game_board._board[0]->isAlive());
}

TEST(CellCell_takeTurn, takeTurn_3) {
	Life<Cell> game_board(1, 1);
	game_board.addCell(0, 0, false, 10);
	game_board._board[0]->takeTurn(3);
	ASSERT_TRUE(game_board._board[0]->isAlive());
}

/**
 * isAlive() Tests
*/
TEST(Cell_isAlive, isAlive_1) {
	Life<Cell> game_board(1, 1);
	game_board.addCell(0, 0, false, 0);
	ASSERT_FALSE(game_board._board[0]->isAlive());
}

TEST(Cell_isAlive, isAlive_2) {
    Life<Cell> game_board(1, 1);
	game_board.addCell(0, 0, true, 1);
	ASSERT_TRUE(game_board._board[0]->isAlive());
}

TEST(Cell_isAlive, isAlive_3) {
    Life<Cell> game_board(1, 1);
	game_board.addCell(0, 0, false, 3);
	ASSERT_FALSE(game_board._board[0]->isAlive());
}

/**
 * print() Tests
*/
TEST(CellCell_Print, print_1) {
    stringstream buffer;
	streambuf* cbuf = cout.rdbuf();
	cout.rdbuf(buffer.rdbuf());

	Life<Cell> game_board(1, 1);
	game_board.addCell(0, 0, true, 5);
	game_board._board[0]->print();

	ASSERT_EQ('*', buffer.peek());

	cout.rdbuf(cbuf);
}

TEST(CellCell_Print, print_2) {
    stringstream buffer;
	streambuf* cbuf = cout.rdbuf();
	cout.rdbuf(buffer.rdbuf());

	Life<Cell> game_board(1, 1);
	game_board.addCell(0, 0, false, 0);
	game_board._board[0]->print();

	ASSERT_EQ('-', buffer.peek());

	cout.rdbuf(cbuf);
}

TEST(CellCell_Print, print_3) {
    stringstream buffer;
	streambuf* cbuf = cout.rdbuf();
	cout.rdbuf(buffer.rdbuf());

	Life<Cell> game_board(1, 1);
	game_board.addCell(0, 0, false, 5);
	game_board._board[0]->print();

	ASSERT_EQ('.', buffer.peek());

	cout.rdbuf(cbuf);
}

TEST(CellCell_Print, print_4) {
    stringstream buffer;
	streambuf* cbuf = cout.rdbuf();
	cout.rdbuf(buffer.rdbuf());

	Life<Cell> game_board(1, 1);
	game_board.addCell(0, 0, true, 1);
	game_board._board[0]->print();

	ASSERT_EQ('1', buffer.peek());

	cout.rdbuf(cbuf);
}
// ----------
// Life Tests
// ----------

/**
 * addcell() Tests
*/
TEST(Life_AddCell, addCell_1) {
	ConwayCell* c = 0;
	Life<ConwayCell> game_board(1, 1);
	game_board.addCell(0, 0, true, -1);
	ASSERT_NE(game_board._board[0], c);
}

TEST(Life_AddCell, addCell_2) {
	FredkinCell* c = 0;
	Life<FredkinCell> game_board(1, 1);
	game_board.addCell(0, 0, false, 0);
	ASSERT_NE(game_board._board[0], c);
}

TEST(Life_AddCell, addCell_3) {
	Cell* c = 0;
    Life<Cell> game_board(1, 1);
	game_board.addCell(0, 0, false, 0);
	ASSERT_NE(game_board._board[0], c);
}

/**
 * simulate() Tests
*/
TEST(Life_Simulate, simulate_1) {
    Life<ConwayCell> game_board(3, 3);
    game_board.addCell(0, 0, true, -1);
    game_board.addCell(0, 1, true, -1);
    game_board.addCell(0, 2, true, -1);
    game_board.addCell(1, 0, false, -1);
    game_board.addCell(1, 1, false, -1);
    game_board.addCell(1, 2, false, -1);
    game_board.addCell(2, 0, false, -1);
    game_board.addCell(2, 1, false, -1);
    game_board.addCell(2, 2, false, -1);
    game_board.simulate();
    ASSERT_FALSE(game_board._board[0]->isAlive());
    ASSERT_TRUE(game_board._board[1]->isAlive());
    ASSERT_FALSE(game_board._board[2]->isAlive());
    ASSERT_FALSE(game_board._board[3]->isAlive());
    ASSERT_TRUE(game_board._board[4]->isAlive());
    ASSERT_FALSE(game_board._board[5]->isAlive());
    ASSERT_FALSE(game_board._board[6]->isAlive());
    ASSERT_FALSE(game_board._board[7]->isAlive());
    ASSERT_FALSE(game_board._board[8]->isAlive());
}

TEST(Life_Simulate, simulate_2) {
	Life<FredkinCell> game_board(3, 3);
    game_board.addCell(0, 0, true, 0);
    game_board.addCell(0, 1, true, 0);
    game_board.addCell(0, 2, true, 0);
    game_board.addCell(1, 0, false, 0);
    game_board.addCell(1, 1, false, 0);
    game_board.addCell(1, 2, false, 0);
    game_board.addCell(2, 0, false, 0);
    game_board.addCell(2, 1, false, 0);
    game_board.addCell(2, 2, false, 0);
    game_board.simulate();
    ASSERT_TRUE(game_board._board[0]->isAlive());
    ASSERT_FALSE(game_board._board[1]->isAlive());
    ASSERT_TRUE(game_board._board[2]->isAlive());
    ASSERT_TRUE(game_board._board[3]->isAlive());
    ASSERT_TRUE(game_board._board[4]->isAlive());
    ASSERT_TRUE(game_board._board[5]->isAlive());
    ASSERT_FALSE(game_board._board[6]->isAlive());
    ASSERT_FALSE(game_board._board[7]->isAlive());
    ASSERT_FALSE(game_board._board[8]->isAlive());
}


// 0-.
// .*.
// ..*

//
//
//
TEST(Life_Simulate, simulate_3) {
	Life<Cell> game_board(3, 3);
    game_board.addCell(0, 0, true, 0);
    game_board.addCell(0, 1, false, 1);
    game_board.addCell(0, 2, false, 2);
    game_board.addCell(1, 0, false, 3);
    game_board.addCell(1, 1, true, 4);
    game_board.addCell(1, 2, false, 5);
    game_board.addCell(2, 0, false, 6);
    game_board.addCell(2, 1, false, 7);
    game_board.addCell(2, 2, true, 8);
    game_board.simulate();
    ASSERT_FALSE(game_board._board[0]->isAlive());
    ASSERT_FALSE(game_board._board[1]->isAlive());
    ASSERT_FALSE(game_board._board[2]->isAlive());
    ASSERT_FALSE(game_board._board[3]->isAlive());
    ASSERT_TRUE(game_board._board[4]->isAlive());
    ASSERT_FALSE(game_board._board[5]->isAlive());
    ASSERT_FALSE(game_board._board[6]->isAlive());
    ASSERT_FALSE(game_board._board[7]->isAlive());
    ASSERT_FALSE(game_board._board[8]->isAlive());
}

/**
 * populationCount() Tests
*/
TEST(Life_populationCount, populationCount_1) {
    Life<ConwayCell> game_board(3, 3);
    game_board.addCell(0, 0, true, -1);
    game_board.addCell(0, 1, true, -1);
    game_board.addCell(0, 2, true, -1);
    game_board.addCell(1, 0, false, -1);
    game_board.addCell(1, 1, false, -1);
    game_board.addCell(1, 2, false, -1);
    game_board.addCell(2, 0, false, -1);
    game_board.addCell(2, 1, false, -1);
    game_board.addCell(2, 2, false, -1);
    ASSERT_EQ(3, game_board._population);
}

TEST(Life_populationCount, populationCount_2) {
   	Life<FredkinCell> game_board(3, 3);
    game_board.addCell(0, 0, true, 0);
    game_board.addCell(0, 1, false, 0);
    game_board.addCell(0, 2, true, 0);
    game_board.addCell(1, 0, false, 0);
    game_board.addCell(1, 1, true, 0);
    game_board.addCell(1, 2, false, 0);
    game_board.addCell(2, 0, true, 0);
    game_board.addCell(2, 1, false, 0);
    game_board.addCell(2, 2, true, 0);
    ASSERT_EQ(5, game_board._population);
}

TEST(Life_populationCount, populationCount_3) {
    Life<Cell> game_board(3, 3);
    game_board.addCell(0, 0, true, 0);
    game_board.addCell(0, 1, false, 1);
    game_board.addCell(0, 2, false, 2);
    game_board.addCell(1, 0, false, 3);
    game_board.addCell(1, 1, true, 4);
    game_board.addCell(1, 2, false, 5);
    game_board.addCell(2, 0, true, 6);
    game_board.addCell(2, 1, false, 7);
    game_board.addCell(2, 2, true, 8);
    ASSERT_EQ(4, game_board._population);
}

/**
 * print() Tests
*/
TEST(Life_Print, print_1) {
    stringstream buffer;
	streambuf* cbuf = cout.rdbuf();
	cout.rdbuf(buffer.rdbuf());

	Life<ConwayCell> game_board(3, 3);
	game_board.addCell(0, 0, true, -1);
    game_board.addCell(0, 1, true, -1);
    game_board.addCell(0, 2, true, -1);
    game_board.addCell(1, 0, false, -1);
    game_board.addCell(1, 1, false, -1);
    game_board.addCell(1, 2, false, -1);
    game_board.addCell(2, 0, false, -1);
    game_board.addCell(2, 1, false, -1);
    game_board.addCell(2, 2, false, -1);
	game_board.print();
	ASSERT_EQ("Generation = 0, Population = 3.\n***\n...\n...\n\n", buffer.str());

	cout.rdbuf(cbuf);
}

TEST(Life_Print, print_2) {
    stringstream buffer;
	streambuf* cbuf = cout.rdbuf();
	cout.rdbuf(buffer.rdbuf());

	Life<FredkinCell> game_board(3, 3);
    game_board.addCell(0, 0, true, 0);
    game_board.addCell(0, 1, false, 0);
    game_board.addCell(0, 2, true, 0);
    game_board.addCell(1, 0, false, 0);
    game_board.addCell(1, 1, true, 0);
    game_board.addCell(1, 2, false, 0);
    game_board.addCell(2, 0, true, 0);
    game_board.addCell(2, 1, false, 0);
    game_board.addCell(2, 2, true, 0);
	game_board.print();

	ASSERT_EQ("Generation = 0, Population = 5.\n0-0\n-0-\n0-0\n\n", buffer.str());

	cout.rdbuf(cbuf);
}

TEST(Life_Print, print_3) {
    stringstream buffer;
	streambuf* cbuf = cout.rdbuf();
	cout.rdbuf(buffer.rdbuf());

	Life<Cell> game_board(3, 3);
    game_board.addCell(0, 0, true, 0);
    game_board.addCell(0, 1, false, 1);
    game_board.addCell(0, 2, false, 2);
    game_board.addCell(1, 0, false, 3);
    game_board.addCell(1, 1, true, 4);
    game_board.addCell(1, 2, false, 5);
    game_board.addCell(2, 0, true, 6);
    game_board.addCell(2, 1, false, 7);
    game_board.addCell(2, 2, true, 8);
	game_board.print();

	ASSERT_EQ("Generation = 0, Population = 4.\n0-.\n.*.\n*.*\n\n", buffer.str());

	cout.rdbuf(cbuf);
}

// /**
//  * begin() Tests
// */
// TEST(Life_Begin, begin_1) {
//     Life<ConwayCell> game_board(3, 3);
// 	game_board.addCell(0, 0, true, -1);
//     game_board.addCell(0, 1, true, -1);
//     game_board.addCell(0, 2, true, -1);
//     game_board.addCell(1, 0, false, -1);
//     game_board.addCell(1, 1, false, -1);
//     game_board.addCell(1, 2, false, -1);
//     game_board.addCell(2, 0, false, -1);
//     game_board.addCell(2, 1, false, -1);
//     game_board.addCell(2, 2, false, -1);
//     ConwayCell* c1 = game_board._board[0];
//     vector<ConwayCell*>::iterator c2 = game_board.begin();
//     ASSERT_EQ(c1->isAlive(), (*c2)->isAlive());
// }

// TEST(Life_Begin, begin_2) {
//     Life<FredkinCell> game_board(3, 3);
//     game_board.addCell(0, 0, true, 0);
//     game_board.addCell(0, 1, false, 0);
//     game_board.addCell(0, 2, true, 0);
//     game_board.addCell(1, 0, false, 0);
//     game_board.addCell(1, 1, true, 0);
//     game_board.addCell(1, 2, false, 0);
//     game_board.addCell(2, 0, true, 0);
//     game_board.addCell(2, 1, false, 0);
//     game_board.addCell(2, 2, true, 0);
//     FredkinCell* c1 = game_board._board[0];
//     vector<FredkinCell*>::iterator c2 = game_board.begin();
//     ASSERT_EQ(c1, c2);

// }

// TEST(Life_Begin, begin_3) {
//     Life<Cell> game_board(3, 3);
//     game_board.addCell(0, 0, true, 0);
//     game_board.addCell(0, 1, false, 1);
//     game_board.addCell(0, 2, false, 2);
//     game_board.addCell(1, 0, false, 3);
//     game_board.addCell(1, 1, true, 4);
//     game_board.addCell(1, 2, false, 5);
//     game_board.addCell(2, 0, true, 6);
//     game_board.addCell(2, 1, false, 7);
//     game_board.addCell(2, 2, true, 8);
//     Cell* c1 = game_board._board[0];
//     vector<Cell*>::iterator c2 = game_board.begin();
//     ASSERT_EQ(c1, c2);

// }

// /**
//  * end() Tests
// */
// TEST(Life_End, end_1) {
//     Life<ConwayCell> game_board(3, 3);
// 	game_board.addCell(0, 0, true, -1);
//     game_board.addCell(0, 1, true, -1);
//     game_board.addCell(0, 2, true, -1);
//     game_board.addCell(1, 0, false, -1);
//     game_board.addCell(1, 1, false, -1);
//     game_board.addCell(1, 2, false, -1);
//     game_board.addCell(2, 0, false, -1);
//     game_board.addCell(2, 1, false, -1);
//     game_board.addCell(2, 2, false, -1);
//     ConwayCell* c1 = game_board._board[0];
//     vector<ConwayCell*>::iterato* c2 = game_board.end();
//     ASSERT_EQ(c1, c2);
// }

// TEST(Life_End, end_2) {
//     Life<FredkinCell> game_board(3, 3);
//     game_board.addCell(0, 0, true, 0);
//     game_board.addCell(0, 1, false, 0);
//     game_board.addCell(0, 2, true, 0);
//     game_board.addCell(1, 0, false, 0);
//     game_board.addCell(1, 1, true, 0);
//     game_board.addCell(1, 2, false, 0);
//     game_board.addCell(2, 0, true, 0);
//     game_board.addCell(2, 1, false, 0);
//     game_board.addCell(2, 2, true, 0);
//     FredkinCell* c1 = game_board._board[0];
//     vector<FredkinCell*>::iterator c2 = game_board.end();
//     ASSERT_EQ(c1, c2);
// }

// TEST(Life_End, end_3) {
//     Life<Cell> game_board(3, 3);
//     game_board.addCell(0, 0, true, 0);
//     game_board.addCell(0, 1, false, 1);
//     game_board.addCell(0, 2, false, 2);
//     game_board.addCell(1, 0, false, 3);
//     game_board.addCell(1, 1, true, 4);
//     game_board.addCell(1, 2, false, 5);
//     game_board.addCell(2, 0, true, 6);
//     game_board.addCell(2, 1, false, 7);
//     game_board.addCell(2, 2, true, 8);
//     Cell* c1 = game_board._board[0];
//     vector<Cell*>::iterator c2 = game_board.end();
//     ASSERT_EQ(c1, c2);
// }

/**
 * at() Tests
*/
TEST(Life_At, at_1) {
    Life<ConwayCell> game_board(3, 3);
	game_board.addCell(0, 0, true, -1);
    game_board.addCell(0, 1, true, -1);
    game_board.addCell(0, 2, true, -1);
    game_board.addCell(1, 0, false, -1);
    game_board.addCell(1, 1, false, -1);
    game_board.addCell(1, 2, false, -1);
    game_board.addCell(2, 0, false, -1);
    game_board.addCell(2, 1, false, -1);
    game_board.addCell(2, 2, false, -1);
    ConwayCell* c1 = game_board._board[0];
    ConwayCell* c2 = game_board.at(0, 0);
    ASSERT_EQ(c1, c2);
}


TEST(Life_At, at_2) {
    Life<FredkinCell> game_board(3, 3);
    game_board.addCell(0, 0, true, 0);
    game_board.addCell(0, 1, false, 0);
    game_board.addCell(0, 2, true, 0);
    game_board.addCell(1, 0, false, 0);
    game_board.addCell(1, 1, true, 0);
    game_board.addCell(1, 2, false, 0);
    game_board.addCell(2, 0, true, 0);
    game_board.addCell(2, 1, false, 0);
    game_board.addCell(2, 2, true, 0);
    FredkinCell* c1 = game_board._board[4];
    FredkinCell* c2 = game_board.at(1, 1);
    ASSERT_EQ(c1, c2);
}

TEST(Life_At, at_3) {
    Life<Cell> game_board(3, 3);
    game_board.addCell(0, 0, true, 0);
    game_board.addCell(0, 1, false, 1);
    game_board.addCell(0, 2, false, 2);
    game_board.addCell(1, 0, false, 3);
    game_board.addCell(1, 1, true, 4);
    game_board.addCell(1, 2, false, 5);
    game_board.addCell(2, 0, true, 6);
    game_board.addCell(2, 1, false, 7);
    game_board.addCell(2, 2, true, 8);
    Cell* c1 = game_board._board[8];
    Cell* c2 = game_board.at(2, 2);
    ASSERT_EQ(c1, c2);
}
