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
#include <iostream>  // cout, endl
#include <sstream>
#include <cstring>
#include <string>
#include <utility>

#include "Life.h"

using namespace std;

// ----
// test
// ----

// ------------------------
// Life Default Constructor
// ------------------------
TEST (LifeFixture, LifeDefaultConstructor0) {
	Life<ConwayCell> temp;
	ASSERT_TRUE (temp._row == 0);
	ASSERT_TRUE (temp._col == 0);
}
TEST (LifeFixture, LifeDefaultConstructor1) {
	Life<ConwayCell> temp;
	ASSERT_TRUE (temp._turn == 0);
}
TEST (LifeFixture, LifeDefaultConstructor2) {
	Life<ConwayCell> temp;
	ASSERT_TRUE (temp._pop == 0);
}

// ----------------
// Life Constructor
// ----------------
TEST (LifeFixture, LifeConstructor0) {
	Life<ConwayCell> temp(5, 6);
	ASSERT_TRUE (temp._row == 5);
}
TEST (LifeFixture, LifeConstructor1) {
	Life<ConwayCell> temp(5, 6);
	ASSERT_TRUE (temp._col == 6);
}
TEST (LifeFixture, LifeConstructor2) {
	Life<ConwayCell> temp(5, 6);
	ASSERT_TRUE (temp._turn == 0);
	ASSERT_TRUE (temp._pop == 0);
}

// --------------
// Life::add_line
//---------------
TEST (LifeFixture, LifeAddLine0) {
	Life<ConwayCell> temp(3, 3);
	temp.add_line (0, "...");
	temp.add_line (1, "...");
	temp.add_line (2, "...");
	ASSERT_TRUE ((temp.grid).size () > 0);
}
TEST (LifeFixture, LifeAddLine1) {
	Life<ConwayCell> temp(3, 3);
	temp.add_line (0, "...");
	temp.add_line (1, "...");
	temp.add_line (2, "...");
	ASSERT_TRUE ((temp.grid[0]).size () > 0);
}
TEST (LifeFixture, LifeAddLine2) {
	Life<ConwayCell> temp(3, 3);
	temp.add_line (0, "...");
	temp.add_line (1, "...");
	temp.add_line (2, "...");
	ASSERT_TRUE ((temp.grid[0]).size () > 0);
	ASSERT_TRUE ((temp.grid[1]).size () > 0);
	ASSERT_TRUE ((temp.grid[2]).size () > 0);
}

// --------------
// Life::draw_map
// --------------
TEST (LifeFixture, LifeDrawMap0) {
	Life<ConwayCell> temp(3, 3);
	temp.add_line (0, "...");
	temp.add_line (1, "...");
	temp.add_line (2, "...");

	ostringstream w;
	temp.draw_map (w);
	ASSERT_EQ(w.str(), "\nGeneration = 0, Population = 0.\n...\n...\n...\n");
}
TEST (LifeFixture, LifeDrawMap1) {
	Life<ConwayCell> temp(3, 3);
	temp.add_line (0, "***");
	temp.add_line (1, "***");
	temp.add_line (2, "***");

	ostringstream w;
	temp.draw_map (w);
	ASSERT_EQ(w.str(), "\nGeneration = 0, Population = 9.\n***\n***\n***\n");
}
TEST (LifeFixture, LifeDrawMap2) {
	Life<ConwayCell> temp(3, 3);
	temp.add_line (0, "*..");
	temp.add_line (1, ".*.");
	temp.add_line (2, "..*");

	ostringstream w;
	temp.draw_map (w);
	ASSERT_EQ(w.str(), "\nGeneration = 0, Population = 3.\n*..\n.*.\n..*\n");
}

// ------------
// Life::update
// ------------
TEST (LifeFixture, LifeUpdate0) {
	Life<ConwayCell> temp(3, 3);
	temp.add_line (0, "*..");
	temp.add_line (1, ".*.");
	temp.add_line (2, "..*");

	int i;
	i = temp.update ();
	ASSERT_TRUE(i == 1);
}
TEST (LifeFixture, LifeUpdate1) {
	Life<ConwayCell> temp(3, 3);
	temp.add_line (0, "***");
	temp.add_line (1, "***");
	temp.add_line (2, "***");

	int i;
	i = temp.update ();
	ASSERT_TRUE(i == 4);
}
TEST (LifeFixture, LifeUpdate2) {
	Life<ConwayCell> temp(3, 3);
	temp.add_line (0, "**.");
	temp.add_line (1, "**.");
	temp.add_line (2, "...");

	int i;
	i = temp.update ();
	ASSERT_TRUE(i == 4);
}

// ----------
// Life::play
// ----------
bool f1 (int turn) {return true;}
bool f2 (int turn) {return false;}
TEST (LifeFixture, LifePlay0) {
	Life<ConwayCell> temp(3, 3);
	temp.add_line (0, "*..");
	temp.add_line (1, ".*.");
	temp.add_line (2, "..*");

	ostringstream w;
	temp.play (1, w, f1);
	ostringstream w2;
	w2 << "\nGeneration = 0, Population = 3.\n*..\n.*.\n..*\n";
	w2 << "\nGeneration = 1, Population = 1.\n...\n.*.\n...\n";
	ASSERT_EQ(w.str(), w2.str());
}
TEST (LifeFixture, LifePlay1) {
	Life<ConwayCell> temp(3, 3);
	temp.add_line (0, "*..");
	temp.add_line (1, ".*.");
	temp.add_line (2, "..*");

	ostringstream w;
	temp.play (1, w, f2);
	ostringstream w2;
	w2 << "\nGeneration = 0, Population = 3.\n*..\n.*.\n..*\n";
	ASSERT_EQ(w.str(), w2.str());
}
TEST (LifeFixture, LifePlay2) {
	Life<ConwayCell> temp(3, 3);
	temp.add_line (0, "...");
	temp.add_line (1, "***");
	temp.add_line (2, "...");

	ostringstream w;
	temp.play (2, w, f1);
	ostringstream w2;
	w2 << "\nGeneration = 0, Population = 3.\n...\n***\n...\n";
	w2 << "\nGeneration = 1, Population = 3.\n.*.\n.*.\n.*.\n";
	w2 << "\nGeneration = 2, Population = 3.\n...\n***\n...\n";
	ASSERT_EQ(w.str(), w2.str());
}



// ------------------------
// Cell default constructor
// ------------------------
TEST (LifeFixture, CellDefaultConstructor0) {
	Cell temp;
	ASSERT_TRUE(temp._AC == nullptr);
}
TEST (LifeFixture, CellDefaultConstructor1) {
	Cell temp;
	ASSERT_TRUE(temp.startCell);
}
TEST (LifeFixture, CellDefaultConstructor2) {
	Cell temp;
	ASSERT_FALSE(temp._alive);
	ASSERT_FALSE(temp.next_state);
}

// -----------------------------------
// Cell (AbstractCell* AC, bool alive)
// -----------------------------------
TEST (LifeFixture, CellConstructor0_AC_alive) {
	ConwayCell cc;
	Cell temp (&cc, true);
	ASSERT_TRUE(temp._AC == &cc);
	ASSERT_FALSE(temp.startCell);
	ASSERT_TRUE(temp._alive);
	ASSERT_TRUE(temp.next_state);
}
TEST (LifeFixture, CellConstructor1_AC_alive) {
	ConwayCell cc;
	Cell temp (&cc, false);
	ASSERT_TRUE(temp._AC == &cc);
	ASSERT_FALSE(temp.startCell);
	ASSERT_FALSE(temp._alive);
	ASSERT_FALSE(temp.next_state);
}
TEST (LifeFixture, CellConstructor2_AC_alive) {
	FredkinCell fc;
	Cell temp (&fc, true);
	ASSERT_TRUE(temp._AC == &fc);
	ASSERT_FALSE(temp.startCell);
	ASSERT_TRUE(temp._alive);
	ASSERT_TRUE(temp.next_state);
}
TEST (LifeFixture, CellConstructor3_AC_alive) {
	FredkinCell fc;
	Cell temp (&fc, false);
	ASSERT_TRUE(temp._AC == &fc);
	ASSERT_FALSE(temp.startCell);
	ASSERT_FALSE(temp._alive);
	ASSERT_FALSE(temp.next_state);
}

// ----------------------------------
// Cell (const Cell& rhs, bool alive)
// ----------------------------------
TEST (LifeFixture, CellConstructor0_Cell_alive) {
	Cell c;
	Cell temp (c, true);
	ASSERT_TRUE(temp._AC == c._AC);
	ASSERT_TRUE(temp.startCell);
}
TEST (LifeFixture, CellConstructor1_Cell_alive) {
	Cell c;
	Cell temp (c, true);
	ASSERT_TRUE(temp._alive);
	ASSERT_TRUE(temp.next_state);
}
TEST (LifeFixture, CellConstructor2_Cell_alive) {
	Cell c;
	Cell temp (c, false);
	ASSERT_TRUE(temp._AC == c._AC);
	ASSERT_TRUE(temp.startCell);
}
TEST (LifeFixture, CellConstructor3_Cell_alive) {
	Cell c;
	Cell temp (c, false);
	ASSERT_FALSE(temp._alive);
	ASSERT_FALSE(temp.next_state);
}

// ---------------------
// Cell copy constructor
// ---------------------
TEST (LifeFixture, CellCopyConstructor0) {
	Cell c;
	Cell temp (c);
	ASSERT_TRUE(temp._AC == c._AC);
	ASSERT_TRUE(temp.startCell);
	ASSERT_FALSE(temp._alive);
	ASSERT_FALSE(temp.next_state);
}
TEST (LifeFixture, CellCopyConstructor1) {
	ConwayCell cc;
	Cell c (&cc, true);
	Cell temp (c);
	ASSERT_TRUE(temp._AC == c._AC);
	ASSERT_FALSE(temp.startCell);
	ASSERT_TRUE(temp._alive);
	ASSERT_TRUE(temp.next_state);
}
TEST (LifeFixture, CellCopyConstructor2) {
	FredkinCell fc;
	Cell c (&fc, false);
	Cell temp (c);
	ASSERT_TRUE(temp._AC == c._AC);
	ASSERT_FALSE(temp.startCell);
	ASSERT_FALSE(temp._alive);
	ASSERT_FALSE(temp.next_state);
}

// --------------------
// Cell equals operator
// --------------------
TEST (LifeFixture, CellCopyAssignment0) {
	Cell c;
	Cell temp;
	temp = c;
	ASSERT_TRUE(temp._AC == c._AC);
	ASSERT_TRUE(temp.startCell);
	ASSERT_FALSE(temp._alive);
	ASSERT_FALSE(temp.next_state);
}
TEST (LifeFixture, CellCopyAssignment1) {
	ConwayCell cc;
	Cell c (&cc, true);
	Cell temp;
	temp = c;
	ASSERT_TRUE(temp._AC == c._AC);
	ASSERT_FALSE(temp.startCell);
	ASSERT_TRUE(temp._alive);
	ASSERT_TRUE(temp.next_state);
}
TEST (LifeFixture, CellCopyAssignment2) {
	FredkinCell fc;
	Cell c (&fc, false);
	Cell temp;
	temp = c;
	ASSERT_TRUE(temp._AC == c._AC);
	ASSERT_FALSE(temp.startCell);
	ASSERT_FALSE(temp._alive);
	ASSERT_FALSE(temp.next_state);
}

// ----------
// Cell:clone
// ----------
TEST (LifeFixture, CellClone0) {
	Cell c;
	Cell temp = c.clone ();
	ASSERT_TRUE(temp._AC != nullptr);
	ASSERT_TRUE(temp.startCell);
}
TEST (LifeFixture, CellClone1) {
	Cell c;
	Cell temp = c.clone ();
	ASSERT_FALSE(temp._alive);
	ASSERT_FALSE(temp.next_state);
}
TEST (LifeFixture, CellClone2) {
	Cell temp;
	temp = temp.clone ();
	ASSERT_TRUE(temp._AC != nullptr);
	ASSERT_TRUE(temp.startCell);
	ASSERT_FALSE(temp._alive);
	ASSERT_FALSE(temp.next_state);
}

// ---------
// Cell::act
// ---------
TEST (LifeFixture, CellAct0) {
	vector< vector<Cell> > g(3, vector<Cell>(3));
	FredkinCell fc;
	Cell c;

	Cell c0 (fc.clone (), false);
	g[0][0] = c0;
	Cell c1 (fc.clone (), true);
	g[0][1] = c1;
	Cell c2 (fc.clone (), false);
	g[0][2] = c2;
	Cell c3 (fc.clone (), true);
	g[1][0] = c3;
	Cell c4 (fc.clone (), true);
	g[1][1] = c4;
	Cell c5 (fc.clone (), true);
	g[1][2] = c5;
	Cell c6 (fc.clone (), true);
	g[2][0] = c6;
	Cell c7 (fc.clone (), true);
	g[2][1] = c7;
	Cell c8 (fc.clone (), true);
	g[2][2] = c8;

	Cell temp = g[0][0];
	ASSERT_TRUE(temp.act (0, 0, 3, 3, &g) == 0);
}
TEST (LifeFixture, CellAct1) {
	vector< vector<Cell> > g(3, vector<Cell>(3));
	FredkinCell fc;
	Cell c;

	Cell c0 (fc.clone (), false);
	g[0][0] = c0;
	Cell c1 (fc.clone (), true);
	g[0][1] = c1;
	Cell c2 (fc.clone (), false);
	g[0][2] = c2;
	Cell c3 (fc.clone (), true);
	g[1][0] = c3;
	Cell c4 (fc.clone (), true);
	g[1][1] = c4;
	Cell c5 (fc.clone (), true);
	g[1][2] = c5;
	Cell c6 (fc.clone (), true);
	g[2][0] = c6;
	Cell c7 (fc.clone (), true);
	g[2][1] = c7;
	Cell c8 (fc.clone (), true);
	g[2][2] = c8;

	Cell temp = g[0][1];
	ASSERT_TRUE(temp.act (0, 1, 3, 3, &g) == 1);
}
TEST (LifeFixture, CellAct2) {
	vector< vector<Cell> > g(3, vector<Cell>(3));
	FredkinCell fc;
	Cell c;

	Cell c0 (fc.clone (), false);
	g[0][0] = c0;
	Cell c1 (fc.clone (), true);
	g[0][1] = c1;
	Cell c2 (fc.clone (), false);
	g[0][2] = c2;
	Cell c3 (fc.clone (), true);
	g[1][0] = c3;
	Cell c4 (fc.clone (), true);
	g[1][1] = c4;
	Cell c5 (fc.clone (), true);
	g[1][2] = c5;
	Cell c6 (fc.clone (), true);
	g[2][0] = c6;
	Cell c7 (fc.clone (), true);
	g[2][1] = c7;
	Cell c8 (fc.clone (), true);
	g[2][2] = c8;

	Cell temp = g[0][2];
	ASSERT_TRUE(temp.act (0, 2, 3, 3, &g) == 0);
}
TEST (LifeFixture, CellAct3) {
	vector< vector<Cell> > g(3, vector<Cell>(3));
	FredkinCell fc;
	Cell c;

	Cell c0 (fc.clone (), false);
	g[0][0] = c0;
	Cell c1 (fc.clone (), true);
	g[0][1] = c1;
	Cell c2 (fc.clone (), false);
	g[0][2] = c2;
	Cell c3 (fc.clone (), true);
	g[1][0] = c3;
	Cell c4 (fc.clone (), true);
	g[1][1] = c4;
	Cell c5 (fc.clone (), true);
	g[1][2] = c5;
	Cell c6 (fc.clone (), true);
	g[2][0] = c6;
	Cell c7 (fc.clone (), true);
	g[2][1] = c7;
	Cell c8 (fc.clone (), true);
	g[2][2] = c8;

	Cell temp = g[1][0];
	ASSERT_TRUE(temp.act (1, 0, 3, 3, &g) == 0);
}
TEST (LifeFixture, CellAct4) {
	vector< vector<Cell> > g(3, vector<Cell>(3));
	FredkinCell fc;
	Cell c;

	Cell c0 (fc.clone (), false);
	g[0][0] = c0;
	Cell c1 (fc.clone (), true);
	g[0][1] = c1;
	Cell c2 (fc.clone (), false);
	g[0][2] = c2;
	Cell c3 (fc.clone (), true);
	g[1][0] = c3;
	Cell c4 (fc.clone (), true);
	g[1][1] = c4;
	Cell c5 (fc.clone (), true);
	g[1][2] = c5;
	Cell c6 (fc.clone (), true);
	g[2][0] = c6;
	Cell c7 (fc.clone (), true);
	g[2][1] = c7;
	Cell c8 (fc.clone (), true);
	g[2][2] = c8;

	Cell temp = g[1][1];
	ASSERT_TRUE(temp.act (1, 1, 3, 3, &g) == 0);
}
TEST (LifeFixture, CellAct5) {
	vector< vector<Cell> > g(3, vector<Cell>(3));
	FredkinCell fc;
	Cell c;

	Cell c0 (fc.clone (), false);
	g[0][0] = c0;
	Cell c1 (fc.clone (), true);
	g[0][1] = c1;
	Cell c2 (fc.clone (), false);
	g[0][2] = c2;
	Cell c3 (fc.clone (), true);
	g[1][0] = c3;
	Cell c4 (fc.clone (), true);
	g[1][1] = c4;
	Cell c5 (fc.clone (), true);
	g[1][2] = c5;
	Cell c6 (fc.clone (), true);
	g[2][0] = c6;
	Cell c7 (fc.clone (), true);
	g[2][1] = c7;
	Cell c8 (fc.clone (), true);
	g[2][2] = c8;

	Cell temp = g[1][2];
	ASSERT_TRUE(temp.act (1, 2, 3, 3, &g) == 0);
}
TEST (LifeFixture, CellAct6) {
	vector< vector<Cell> > g(3, vector<Cell>(3));
	FredkinCell fc;
	Cell c;

	Cell c0 (fc.clone (), false);
	g[0][0] = c0;
	Cell c1 (fc.clone (), true);
	g[0][1] = c1;
	Cell c2 (fc.clone (), false);
	g[0][2] = c2;
	Cell c3 (fc.clone (), true);
	g[1][0] = c3;
	Cell c4 (fc.clone (), true);
	g[1][1] = c4;
	Cell c5 (fc.clone (), true);
	g[1][2] = c5;
	Cell c6 (fc.clone (), true);
	g[2][0] = c6;
	Cell c7 (fc.clone (), true);
	g[2][1] = c7;
	Cell c8 (fc.clone (), true);
	g[2][2] = c8;

	Cell temp = g[2][0];
	ASSERT_TRUE(temp.act (2, 0, 3, 3, &g) == 0);
}
TEST (LifeFixture, CellAct7) {
	vector< vector<Cell> > g(3, vector<Cell>(3));
	FredkinCell fc;
	Cell c;

	Cell c0 (fc.clone (), false);
	g[0][0] = c0;
	Cell c1 (fc.clone (), true);
	g[0][1] = c1;
	Cell c2 (fc.clone (), false);
	g[0][2] = c2;
	Cell c3 (fc.clone (), true);
	g[1][0] = c3;
	Cell c4 (fc.clone (), true);
	g[1][1] = c4;
	Cell c5 (fc.clone (), true);
	g[1][2] = c5;
	Cell c6 (fc.clone (), true);
	g[2][0] = c6;
	Cell c7 (fc.clone (), true);
	g[2][1] = c7;
	Cell c8 (fc.clone (), true);
	g[2][2] = c8;

	Cell temp = g[2][1];
	ASSERT_TRUE(temp.act (2, 1, 3, 3, &g) == 1);
}
TEST (LifeFixture, CellAct8) {
	vector< vector<Cell> > g(3, vector<Cell>(3));
	FredkinCell fc;
	Cell c;

	Cell c0 (fc.clone (), false);
	g[0][0] = c0;
	Cell c1 (fc.clone (), true);
	g[0][1] = c1;
	Cell c2 (fc.clone (), false);
	g[0][2] = c2;
	Cell c3 (fc.clone (), true);
	g[1][0] = c3;
	Cell c4 (fc.clone (), true);
	g[1][1] = c4;
	Cell c5 (fc.clone (), true);
	g[1][2] = c5;
	Cell c6 (fc.clone (), true);
	g[2][0] = c6;
	Cell c7 (fc.clone (), true);
	g[2][1] = c7;
	Cell c8 (fc.clone (), true);
	g[2][2] = c8;

	Cell temp = g[2][2];
	ASSERT_TRUE(temp.act (2, 2, 3, 3, &g) == 0);
}

// ----------------
// Cell::print_self
// ----------------
TEST (LifeFixture, CellPrintSelf0) {
	ConwayCell cc;
	Cell c (&cc, true);
	ostringstream w;
	c.print_self (w);
	ASSERT_EQ(w.str (), "*");
}
TEST (LifeFixture, CellPrintSelf1) {
	ConwayCell cc;
	Cell c (&cc, false);
	ostringstream w;
	c.print_self (w);
	ASSERT_EQ(w.str (), ".");
}
TEST (LifeFixture, CellPrintSelf2) {
	FredkinCell fc;
	Cell c (&fc, true);
	ostringstream w;
	c.print_self (w);
	ASSERT_EQ(w.str (), "0");
}
TEST (LifeFixture, CellPrintSelf3) {
	FredkinCell fc;
	Cell c (&fc, false);
	ostringstream w;
	c.print_self (w);
	ASSERT_EQ(w.str (), "-");
}



// ----------------------
// ConwayCell::print_self
// ----------------------
TEST (LifeFixture, ConwayCellPrintSelf0) {
	ConwayCell cc;
	ostringstream w;
	cc.print_self (w, true);
	ASSERT_EQ(w.str (), "*");
}
TEST (LifeFixture, ConwayCellPrintSelf1) {
	ConwayCell cc;
	ostringstream w;
	cc.print_self (w, false);
	ASSERT_EQ(w.str (), ".");
}

// ---------------
// ConwayCell::act
// ---------------
TEST (LifeFixture, ConwayCellAct0) {
	ConwayCell cc;
	ASSERT_TRUE(cc.act (true, 0, 0, false) == 0);
}
TEST (LifeFixture, ConwayCellAct1) {
	ConwayCell cc;
	ASSERT_TRUE(cc.act (true, 1, 0, false) == 0);
}
TEST (LifeFixture, ConwayCellAct2) {
	ConwayCell cc;
	ASSERT_TRUE(cc.act (true, 1, 1, false) == 1);
}
TEST (LifeFixture, ConwayCellAct3) {
	ConwayCell cc;
	ASSERT_TRUE(cc.act (true, 2, 1, false) == 1);
}
TEST (LifeFixture, ConwayCellAct4) {
	ConwayCell cc;
	ASSERT_TRUE(cc.act (true, 2, 2, false) == 0);
}
TEST (LifeFixture, ConwayCellAct5) {
	ConwayCell cc;
	ASSERT_TRUE(cc.act (false, 2, 1, false) == 1);
}
TEST (LifeFixture, ConwayCellAct6) {
	ConwayCell cc;
	ASSERT_TRUE(cc.act (false, 2, 2, false) == 0);
}
TEST (LifeFixture, ConwayCellAct7) {
	ConwayCell cc;
	ASSERT_TRUE(cc.act (false, 0, 0, false) == 0);
}

// -----------------
// ConwayCell::clone
// -----------------
TEST (LifeFixture, ConwayCellClone0) {
	ConwayCell cc;
	AbstractCell* temp = cc.clone ();
	bool tmp = (temp != nullptr);
	delete temp;
	ASSERT_TRUE(tmp);
}
TEST (LifeFixture, ConwayCellClone1) {
	ConwayCell cc;
	AbstractCell* temp = cc.clone ();
	bool tmp = (temp != &cc);
	delete temp;
	ASSERT_TRUE(tmp);
}




// -------------------------------
// FredkinCell Default Constructor
// -------------------------------
TEST (LifeFixture, FredkinCellDefaultConstructor0) {
	FredkinCell fc;
	ASSERT_TRUE(fc._age == 0);
}

// -----------------------
// FredkinCell Constructor
// -----------------------
TEST (LifeFixture, FredkinCellConstructor0) {
	FredkinCell fc (0);
	ASSERT_TRUE(fc._age == 0);
}
TEST (LifeFixture, FredkinCellConstructor1) {
	FredkinCell fc (2);
	ASSERT_TRUE(fc._age == 2);
}
TEST (LifeFixture, FredkinCellConstructor2) {
	FredkinCell fc (-1);
	ASSERT_TRUE(fc._age == 0);
}

// ----------------------------
// FredkinCell Copy Constructor
// ----------------------------
TEST (LifeFixture, FredkinCellCopyConstructor0) {
	FredkinCell temp (5);
	FredkinCell fc (temp);
	ASSERT_TRUE(fc._age == 5);
}
TEST (LifeFixture, FredkinCellCopyConstructor1) {
	FredkinCell temp;
	FredkinCell fc (temp);
	ASSERT_TRUE(fc._age == 0);
}
TEST (LifeFixture, FredkinCellCopyConstructor2) {
	FredkinCell temp (-1);
	FredkinCell fc (temp);
	ASSERT_TRUE(fc._age == 0);
}

// ---------------------------
// FredkinCell equals operator
// ---------------------------
TEST (LifeFixture, FredkinCellEqualsOperator0) {
	FredkinCell temp (1);
	FredkinCell fc;
	fc = temp;
	ASSERT_TRUE(fc._age == 1);
}
TEST (LifeFixture, FredkinCellEqualsOperator1) {
	FredkinCell temp (1);
	FredkinCell fc;
	fc = temp;
	ASSERT_FALSE(&fc == &temp);
}
TEST (LifeFixture, FredkinCellEqualsOperator2) {
	FredkinCell temp (-1);
	FredkinCell fc;
	fc = temp;
	ASSERT_TRUE(fc._age == 0);
}

// -----------------------
// FredkinCell::print_self
// -----------------------
TEST (LifeFixture, FredkinCellPrintSelf0) {
	FredkinCell fc;
	ostringstream w;
	fc.print_self (w, false);
	ASSERT_EQ(w.str (), "-");
}
TEST (LifeFixture, FredkinCellPrintSelf1) {
	FredkinCell fc (4);
	ostringstream w;
	fc.print_self (w, true);
	ASSERT_EQ(w.str (), "4");
}
TEST (LifeFixture, FredkinCellPrintSelf2) {
	FredkinCell fc (11);
	ostringstream w;
	fc.print_self (w, true);
	ASSERT_EQ(w.str (), "+");
}

// ----------------
// FredkinCell::act
// ----------------
TEST (LifeFixture, FredkinCellAct0) {
	FredkinCell fc;
	ASSERT_TRUE(fc.act (false, 1, 0, false) == 1);
}
TEST (LifeFixture, FredkinCellAct1) {
	FredkinCell fc;
	ASSERT_TRUE(fc.act (false, 3, 0, false) == 1);
}
TEST (LifeFixture, FredkinCellAct2) {
	FredkinCell fc;
	ASSERT_TRUE(fc.act (false, 0, 0, false) == 0);
}
TEST (LifeFixture, FredkinCellAct3) {
	FredkinCell fc;
	ASSERT_TRUE(fc.act (false, 2, 0, false) == 0);
}
TEST (LifeFixture, FredkinCellAct4) {
	FredkinCell fc;
	ASSERT_TRUE(fc.act (false, 4, 0, false) == 0);
}
TEST (LifeFixture, FredkinCellAct5) {
	FredkinCell fc;
	ASSERT_TRUE(fc.act (true, 0, 0, false) == 0);
}
TEST (LifeFixture, FredkinCellAct6) {
	FredkinCell fc;
	ASSERT_TRUE(fc.act (true, 2, 0, false) == 0);
}
TEST (LifeFixture, FredkinCellAct7) {
	FredkinCell fc;
	ASSERT_TRUE(fc.act (true, 4, 0, false) == 0);
}
TEST (LifeFixture, FredkinCellAct8) {
	FredkinCell fc;
	ASSERT_TRUE(fc.act (true, 1, 0, false) == 1);
}
TEST (LifeFixture, FredkinCellAct9) {
	FredkinCell fc;
	ASSERT_TRUE(fc.act (true, 1, 0, true) == 1);
}
TEST (LifeFixture, FredkinCellAct10) {
	FredkinCell fc (1);
	ASSERT_TRUE(fc.act (true, 3, 0, true) == 2);
}
TEST (LifeFixture, FredkinCellAct11) {
	FredkinCell fc;
	ASSERT_TRUE(fc.act (true, 3, 0, false) == 1);
}
TEST (LifeFixture, FredkinCellAct12) {
	FredkinCell fc;
	ASSERT_TRUE(fc.act (true, 3, 0, true) == 1);
}
TEST (LifeFixture, FredkinCellAct13) {
	FredkinCell fc (1);
	ASSERT_TRUE(fc.act (true, 3, 0, true) == 2);
}

// ------------------
// FredkinCell::clone
// ------------------
TEST (LifeFixture, FredkinCellClone0) {
	FredkinCell fc;
	AbstractCell* temp = fc.clone ();
	bool tmp = (temp != nullptr);
	delete temp;
	ASSERT_TRUE(tmp);
}
TEST (LifeFixture, FredkinCellClone1) {
	FredkinCell fc;
	AbstractCell* temp = fc.clone ();
	bool tmp = (temp != &fc);
	delete temp;
	ASSERT_TRUE(tmp);
}


