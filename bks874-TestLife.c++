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

#define TEST_LIFE

#include "Life.h"

using namespace std;

// ----
// test
// ----

//75 tests

TEST(LifeFixture, LIFE_life_1) //TEST 1
{
    Life<ConwayCell> x(10, 20, ConwayCell(false));
    ASSERT_TRUE(x._width == 10);
}

TEST(LifeFixture, LIFE_life_2) //TEST 2
{
    Life<ConwayCell> x(10, 20, ConwayCell(false));
    ASSERT_TRUE(x._height == 20);
}

TEST(LifeFixture, LIFE_life_3) //TEST 3
{
    Life<ConwayCell> x(10, 20, ConwayCell(false));
    ASSERT_TRUE(x.board.size() == 10);
}

TEST(LifeFixture, LIFE_life_4) //TEST 4
{
    Life<ConwayCell> x(10, 20, ConwayCell(false));
    ASSERT_TRUE(x.board[3].size() == 20);
}

TEST(LifeFixture, LIFE_life_5) //TEST 5
{
    Life<ConwayCell> x(10, 20, ConwayCell(false));
    ASSERT_FALSE(x.board[5][5].alive());
}

TEST(LifeFixture, LIFE_population_1) //TEST 6
{
	Life<ConwayCell> x(10, 20, ConwayCell(false));
	ASSERT_EQ(x.population(), 0);
}

TEST(LifeFixture, LIFE_population_2) //TEST 7
{
	Life<ConwayCell> x(10, 20, ConwayCell());
	ASSERT_EQ(x.population(), 200);
}

TEST(LifeFixture, LIFE_put_1) //TEST 8
{
	Life<ConwayCell> x(10, 20, ConwayCell(false));
	x.put(ConwayCell(true), 5, 5);
	ASSERT_TRUE(x.board[5][5].alive());
}

TEST(LifeFixture, LIFE_put_2) //TEST 9
{
	Life<ConwayCell> x(10, 20, ConwayCell(true));
	x.put(ConwayCell(false), 5, 5);
	ASSERT_FALSE(x.board[5][5].alive());
}

TEST(LifeFixture, LIFE_put_3) //TEST 10
{
	Life<ConwayCell> x(10, 20, ConwayCell(false));
	x.put(ConwayCell(), 5, 5);
	x.put(ConwayCell(), 6, 6);
	x.put(ConwayCell(), 7, 7);
	x.put(ConwayCell(), 8, 8);
	x.put(ConwayCell(), 9, 9);
	ASSERT_EQ(x.population(), 5);
}

TEST(LifeFixture, LIFE_print_1) //TEST 11
{
	Life<ConwayCell> x(10, 20, ConwayCell(false));
	ostringstream s("");
	x.print(s);
	ASSERT_EQ(s.str(), "..........\n..........\n..........\n..........\n"
		"..........\n..........\n..........\n..........\n"
		"..........\n..........\n..........\n..........\n"
		"..........\n..........\n..........\n..........\n"
		"..........\n..........\n..........\n..........\n");
}

TEST(LifeFixture, LIFE_print_2) //TEST 12
{
	Life<ConwayCell> x(10, 20, ConwayCell(true));
	ostringstream s("");
	x.print(s);
	ASSERT_EQ(s.str(), "**********\n**********\n**********\n**********\n"
		"**********\n**********\n**********\n**********\n"
		"**********\n**********\n**********\n**********\n"
		"**********\n**********\n**********\n**********\n"
		"**********\n**********\n**********\n**********\n");
}

TEST(LifeFixture, LIFE_print_3) //TEST 13
{
	Life<ConwayCell> x(10, 20, ConwayCell(false));
	x.put(ConwayCell(true), 4, 0);
	x.put(ConwayCell(true), 4, 1);
	x.put(ConwayCell(true), 4, 2);
	x.put(ConwayCell(true), 4, 3);
	ostringstream s("");
	x.print(s);
	ASSERT_EQ(s.str(), "....*.....\n....*.....\n....*.....\n....*.....\n"
		"..........\n..........\n..........\n..........\n"
		"..........\n..........\n..........\n..........\n"
		"..........\n..........\n..........\n..........\n"
		"..........\n..........\n..........\n..........\n");
}

TEST(LifeFixture, LIFE_evolve_1) //TEST 14
{
	Life<ConwayCell> x(10, 20, ConwayCell(false));
	x.put(ConwayCell(true), 4, 0);
	x.put(ConwayCell(true), 4, 1);
	x.put(ConwayCell(true), 4, 2);
	x.put(ConwayCell(true), 4, 3);
	x.evolve();
	ostringstream s("");
	x.print(s);
	ASSERT_EQ(s.str(), "..........\n...***....\n...***....\n..........\n"
		"..........\n..........\n..........\n..........\n"
		"..........\n..........\n..........\n..........\n"
		"..........\n..........\n..........\n..........\n"
		"..........\n..........\n..........\n..........\n");
}

TEST(LifeFixture, LIFE_evolve_2) //TEST 15
{
	Life<FredkinCell> x(10, 20, FredkinCell(false));
	x.put(FredkinCell(true), 4, 0);
	x.put(FredkinCell(true), 4, 1);
	x.put(FredkinCell(true), 4, 2);
	x.put(FredkinCell(true), 4, 3);
	x.evolve();
	ostringstream s("");
	x.print(s);
	ASSERT_EQ(s.str(), "---010----\n---0-0----\n---0-0----\n---010----\n"
		"----0-----\n----------\n----------\n----------\n"
		"----------\n----------\n----------\n----------\n"
		"----------\n----------\n----------\n----------\n"
		"----------\n----------\n----------\n----------\n");
}

TEST(LifeFixture, LIFE_evolve_3) //TEST 16
{
	Life<Cell> x(10, 20, Cell(new FredkinCell(false)));
	for(int i = 10; i < 20; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			x.put(Cell(new ConwayCell(false)), j, i);
		}
	}
	x.put(Cell(new ConwayCell()), 5, 15);
	x.put(Cell(new FredkinCell()), 5, 5);
	x.evolve();
	ostringstream s("");
	x.print(s);
	ASSERT_EQ(s.str(), 
		"----------\n"
		"----------\n"
		"----------\n"
		"----------\n"
		"-----0----\n"
		"----0-0---\n"
		"-----0----\n"
		"----------\n"
		"----------\n"
		"----------\n"
		"..........\n"
		"..........\n"
		"..........\n"
		"..........\n"
		"..........\n"
		"..........\n"
		"..........\n"
		"..........\n"
		"..........\n"
		"..........\n"
	);
}

TEST(LifeFixture, CONWAYCELL_conwaycell_1) //TEST 17
{
	ConwayCell c(true);
	ASSERT_TRUE(c.alive());
}

TEST(LifeFixture, CONWAYCELL_conwaycell_2) //TEST 18
{
	ConwayCell c(false);
	ASSERT_FALSE(c.alive());
}

TEST(LifeFixture, CONWAYCELL_evolve_1) //TEST 19
{
	//	**.
	//	*c.
	//	...
	bool neighbors[] = {
		true, true, true, false, false, false, false, false
	};
	ConwayCell c(false);
	c.evolve(neighbors);
	ASSERT_TRUE(c.alive());
}

TEST(LifeFixture, CONWAYCELL_evolve_2) //TEST 20
{
	//	**.
	//	*c.
	//	...
	bool neighbors[] = {
		true, true, true, false, false, false, false, false
	};
	ConwayCell c(true);
	c.evolve(neighbors);
	ASSERT_TRUE(c.alive());
}

TEST(LifeFixture, CONWAYCELL_evolve_3) //TEST 21
{
	//	*..
	//	*c.
	//	...
	bool neighbors[] = {
		true, true, false, false, false, false, false, false
	};
	ConwayCell c(false);
	c.evolve(neighbors);
	ASSERT_FALSE(c.alive());
}

TEST(LifeFixture, CONWAYCELL_evolve_4) //TEST 22
{
	//	*..
	//	*c.
	//	...
	bool neighbors[] = {
		true, true, false, false, false, false, false, false
	};
	ConwayCell c(true);
	c.evolve(neighbors);
	ASSERT_TRUE(c.alive());
}

TEST(LifeFixture, CONWAYCELL_evolve_5) //TEST 23
{
	//	...
	//	*c.
	//	...
	bool neighbors[] = {
		true, false, false, false, false, false, false, false
	};
	ConwayCell c(false);
	c.evolve(neighbors);
	ASSERT_FALSE(c.alive());
}

TEST(LifeFixture, CONWAYCELL_evolve_6) //TEST 24
{
	//	...
	//	*c.
	//	...
	bool neighbors[] = {
		true, false, false, false, false, false, false, false
	};
	ConwayCell c(true);
	c.evolve(neighbors);
	ASSERT_FALSE(c.alive());
}

TEST(LifeFixture, CONWAYCELL_evolve_7) //TEST 25
{
	//	***
	//	*c.
	//	...
	bool neighbors[] = {
		true, true, true, true, false, false, false, false
	};
	ConwayCell c(false);
	c.evolve(neighbors);
	ASSERT_FALSE(c.alive());
}

TEST(LifeFixture, CONWAYCELL_evolve_8) //TEST 26
{
	//	***
	//	*c.
	//	...
	bool neighbors[] = {
		true, true, true, true, false, false, false, false
	};
	ConwayCell c(true);
	c.evolve(neighbors);
	ASSERT_FALSE(c.alive());
}

TEST(LifeFixture, CONWAYCELL_print_1) //TEST 27
{
	ConwayCell c(true);
	ostringstream s("");
	c.print(s);
	ASSERT_EQ(s.str(), "*");
}

TEST(LifeFixture, CONWAYCELL_print_2) //TEST 28
{
	ConwayCell c(false);
	ostringstream s("");
	c.print(s);
	ASSERT_EQ(s.str(), ".");
}

TEST(LifeFixture, CONWAYCELL_print_3) //TEST 29
{
	ConwayCell c(true);
	bool neighbors[] = {false, false, false, false, false, false, false, false};
	c.evolve(neighbors);
	ostringstream s("");
	c.print(s);
	ASSERT_EQ(s.str(), ".");
}

TEST(LifeFixture, CONWAYCELL_alive_1) //TEST 30
{
	ConwayCell c(true);
	ASSERT_TRUE(c.alive());
}

TEST(LifeFixture, CONWAYCELL_alive_2) //TEST 31
{
	ConwayCell c(false);
	ASSERT_FALSE(c.alive());
}

TEST(LifeFixture, CONWAYCELL_alive_3) //TEST 32
{
	ConwayCell c(false);
	bool neighbors[] = {true, true, true, false, false, false, false, false};
	c.evolve(neighbors);
	ASSERT_TRUE(c.alive());
}

TEST(LifeFixture, CONWAYCELL_clone_1) //TEST 33
{
	ConwayCell c(true);
	AbstractCell* ac = c.clone();
	ASSERT_TRUE(ac->alive());
}

TEST(LifeFixture, CONWAYCELL_clone_2) //TEST 34
{
	ConwayCell c(false);
	AbstractCell* ac = c.clone();
	ASSERT_FALSE(ac->alive());
}

TEST(LifeFixture, CONWAYCELL_clone_3) //TEST 35
{
	ConwayCell c(true);
	AbstractCell* ac = c.clone();
	bool neighbors[] = {false, false, false, false, false, false, false, false};
	c.evolve(neighbors);
	ASSERT_TRUE(ac->alive());
}

TEST(LifeFixture, CONWAYCELL_clone_4) //TEST 36
{
	ConwayCell c(true);
	AbstractCell* ac = c.clone();
	ASSERT_NE(dynamic_cast<ConwayCell*>(ac), nullptr);
}

TEST(LifeFixture, FREDKINCELL_fredkincell_1) //TEST 37
{
	FredkinCell c(true);
	ASSERT_TRUE(c.alive());
}

TEST(LifeFixture, FREDKINCELL_fredkincell_2) //TEST 38
{
	FredkinCell c(false);
	ASSERT_FALSE(c.alive());
}

TEST(LifeFixture, FREDKINCELL_evolve_1) //TEST 39
{
	//	-0-
	//	0f0
	//	---
	bool neighbors[] = {
		true, false, true, false, true, false, false, false
	};
	FredkinCell f(false);
	f.evolve(neighbors);
	ASSERT_TRUE(f.alive());
}

TEST(LifeFixture, FREDKINCELL_evolve_2) //TEST 40
{
	//	-0-
	//	0f0
	//	---
	bool neighbors[] = {
		true, false, true, false, true, false, false, false
	};
	FredkinCell f(true);
	f.evolve(neighbors);
	ASSERT_TRUE(f.isOlderThan(0));
}

TEST(LifeFixture, FREDKINCELL_evolve_3) //TEST 41
{
	//	-0-
	//	0f-
	//	---
	bool neighbors[] = {
		true, false, true, false, false, false, false, false
	};
	FredkinCell f(false);
	f.evolve(neighbors);
	ASSERT_FALSE(f.alive());
}

TEST(LifeFixture, FREDKINCELL_evolve_4) //TEST 42
{
	//	-0-
	//	0f-
	//	---
	bool neighbors[] = {
		true, false, true, false, false, false, false, false
	};
	FredkinCell f(true);
	f.evolve(neighbors);
	ASSERT_FALSE(f.alive());
}

TEST(LifeFixture, FREDKINCELL_evolve_5) //TEST 43
{
	//	---
	//	0f-
	//	---
	bool neighbors[] = {
		true, false, false, false, false, false, false, false
	};
	FredkinCell f(false);
	f.evolve(neighbors);
	ASSERT_TRUE(f.alive());
}

TEST(LifeFixture, FREDKINCELL_evolve_6) //TEST 44
{
	//	---
	//	0f-
	//	---
	bool neighbors[] = {
		true, false, false, false, false, false, false, false
	};
	FredkinCell f(true);
	f.evolve(neighbors);
	ASSERT_TRUE(f.isOlderThan(0));
}

TEST(LifeFixture, FREDKINCELL_evolve_7) //TEST 45
{
	//	-0-
	//	0f0
	//	-0-
	bool neighbors[] = {
		true, false, true, false, true, false, true, false
	};
	FredkinCell f(false);
	f.evolve(neighbors);
	ASSERT_FALSE(f.alive());
}

TEST(LifeFixture, FREDKINCELL_evolve_8) //TEST 46
{
	//	-0-
	//	0c0
	//	-0-
	bool neighbors[] = {
		true, false, true, false, true, false, true, false
	};
	FredkinCell f(true);
	f.evolve(neighbors);
	ASSERT_FALSE(f.alive());
}

TEST(LifeFixture, FREDKINCELL_print_1) //TEST 47
{
	FredkinCell f(true);
	ostringstream s("");
	f.print(s);
	ASSERT_EQ(s.str(), "0");
}

TEST(LifeFixture, FREDKINCELL_print_2) //TEST 48
{
	FredkinCell f(false);
	ostringstream s("");
	f.print(s);
	ASSERT_EQ(s.str(), "-");
}

TEST(LifeFixture, FREDKINCELL_print_3) //TEST 49
{
	FredkinCell f(true);
	bool neighbors[] = {false, false, false, false, false, false, false, false};
	f.evolve(neighbors);
	ostringstream s("");
	f.print(s);
	ASSERT_EQ(s.str(), "-");
}

TEST(LifeFixture, FREDKINCELL_alive_1) //TEST 50
{
	FredkinCell f(true);
	ASSERT_TRUE(f.alive());
}

TEST(LifeFixture, FREDKINCELL_alive_2) //TEST 51
{
	FredkinCell f(false);
	ASSERT_FALSE(f.alive());
}

TEST(LifeFixture, FREDKINCELL_alive_3) //TEST 52
{
	FredkinCell f(false);
	bool neighbors[] = {true, false, true, false, true, false, false, false};
	f.evolve(neighbors);
	ASSERT_TRUE(f.alive());
}

TEST(LifeFixture, FREDKINCELL_clone_1) //TEST 53
{
	FredkinCell f(true);
	AbstractCell* ac = f.clone();
	ASSERT_TRUE(ac->alive());
}

TEST(LifeFixture, FREDKINCELL_clone_2) //TEST 54
{
	FredkinCell f(false);
	AbstractCell* ac = f.clone();
	ASSERT_FALSE(ac->alive());
}

TEST(LifeFixture, FREDKINCELL_clone_3) //TEST 55
{
	FredkinCell f(true);
	AbstractCell* ac = f.clone();
	bool neighbors[] = {false, false, false, false, false, false, false, false};
	f.evolve(neighbors);
	ASSERT_TRUE(ac->alive());
}

TEST(LifeFixture, FREDKINCELL_clone_4) //TEST 56
{
	FredkinCell f(true);
	AbstractCell* ac = f.clone();
	ASSERT_NE(dynamic_cast<FredkinCell*>(ac), nullptr);
}

TEST(LifeFixture, FREDKINCELL_isOlderThan_1) //TEST 57
{
	FredkinCell f(true);
	ASSERT_FALSE(f.isOlderThan(0));
}

TEST(LifeFixture, FREDKINCELL_isOlderThan_2) //TEST 58
{
	FredkinCell f(false);
	ASSERT_FALSE(f.isOlderThan(0));
}

TEST(LifeFixture, FREDKINCELL_isOlderThan_3) //TEST 59
{
	FredkinCell f(true);
	bool neighbors[] = {true, false, false, false, false, false, false, false};
	f.evolve(neighbors);
	ASSERT_TRUE(f.isOlderThan(0));
}

TEST(LifeFixture, FREDKINCELL_isOlderThan_4) //TEST 60
{
	FredkinCell f(true);
	bool neighbors1[] = {true, false, false, false, false, false, false, false};
	bool neighbors2[] = {true, false, true, false, false, false, false, false};
	f.evolve(neighbors1);
	f.evolve(neighbors2);
	ASSERT_FALSE(f.isOlderThan(0));
}

TEST(LifeFixture, CELL_cell_abstractcell_1) //TEST 61
{
	Cell c(new ConwayCell(true));
	ASSERT_TRUE(c.alive());
}

TEST(LifeFixture, CELL_cell_abstractcell_2) //TEST 62
{
	Cell c(new ConwayCell(false));
	ASSERT_FALSE(c.alive());
}

TEST(LifeFixture, CELL_cell_cell_1) //TEST 63
{
	Cell c(new ConwayCell(true));
	Cell d = c;
	bool neighbors[] = {false, false, false, false, false, false, false, false};
	c.evolve(neighbors);
	ASSERT_TRUE(d.alive());
}

TEST(LifeFixture, CELL_cell_cell_2) //TEST 64
{
	Cell c(new ConwayCell(true));
	Cell d = c;
	ASSERT_TRUE(d.alive());
}

TEST(LifeFixture, CELL_cell_cell_3) //TEST 65
{
	Cell c(new ConwayCell(false));
	Cell d = c;
	ASSERT_FALSE(d.alive());
}

TEST(LifeFixture, CELL_assignment_abstractcellptr_1) //TEST 66
{
	Cell c(new ConwayCell(false));
	AbstractCell* a = new ConwayCell(true);
	c = a;
	ASSERT_TRUE(c.alive());
}

TEST(LifeFixture, CELL_assignment_abstractcellptr_2) //TEST 67
{
	Cell c(new ConwayCell(true));
	AbstractCell* a = new FredkinCell(false);
	c = a;
	ASSERT_FALSE(c.alive());
}

TEST(LifeFixture, CELL_assignment_abstractcellptr_3) //TEST 68
{
	Cell c(new ConwayCell(false));
	AbstractCell* a = new FredkinCell(false);
	c = a;
	bool neighbors[] = {true, false, false, false, false, false, false, false};
	c.evolve(neighbors);
	ASSERT_TRUE(c.alive());
}

TEST(LifeFixture, CELL_copy_assignment_1) //TEST 69
{
	Cell c(new ConwayCell(false));
	Cell a(new ConwayCell(true));
	c = a;
	ASSERT_TRUE(c.alive());
}

TEST(LifeFixture, CELL_copy_assignment_2) //TEST 70
{
	Cell c(new ConwayCell(true));
	Cell a(new FredkinCell(false));
	c = a;
	ASSERT_FALSE(c.alive());
}

TEST(LifeFixture, CELL_copy_assignment_3) //TEST 71
{
	Cell c(new ConwayCell(false));
	Cell a(new FredkinCell(false));
	c = a;
	bool neighbors[] = {true, false, false, false, false, false, false, false};
	c.evolve(neighbors);
	ASSERT_TRUE(c.alive());
}

TEST(LifeFixture, CELL_copy_assignment_4) //TEST 72
{
	Cell c(new ConwayCell(false));
	Cell a(new FredkinCell(false));
	c = a;
	bool neighbors[] = {true, false, true, false, false, false, false, false};
	c.evolve(neighbors);
	ASSERT_FALSE(a.alive());
}

TEST(LifeFixture, CELL_alive_1) //TEST 73
{
	Cell c(new ConwayCell(false));
	ASSERT_FALSE(c.alive());
}

TEST(LifeFixture, CELL_evolve_1) //TEST 74
{
	Cell c(new ConwayCell(false));
	bool neighbors[] = {true, true, true, false, false, false, false, false};
	c.evolve(neighbors);
	ASSERT_TRUE(c.alive());
}

TEST(LifeFixture, CELL_print_1) //TEST 75
{
	Cell c(new ConwayCell(false));
	ostringstream s("");
	c.print(s);
	ASSERT_EQ(s.str(), ".");
}

TEST(LifeFixture, CELL_clone_1) //TEST 76
{
	Cell f(new ConwayCell(true));
	AbstractCell* ac = f.clone();
	ASSERT_TRUE(ac->alive());
}

TEST(LifeFixture, CELL_clone_2) //TEST 77
{
	Cell f(new ConwayCell(false));
	AbstractCell* ac = f.clone();
	ASSERT_FALSE(ac->alive());
}

TEST(LifeFixture, CELL_clone_3) //TEST 78
{
	Cell f(new ConwayCell(true));
	AbstractCell* ac = f.clone();
	bool neighbors[] = {false, false, false, false, false, false, false, false};
	f.evolve(neighbors);
	ASSERT_TRUE(ac->alive());
}