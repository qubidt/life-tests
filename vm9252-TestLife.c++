// --------------------------
// projects/life/TestLife.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

#include <sstream>
#include <algorithm>

#include "gtest/gtest.h"

#include "Life.h"

using namespace std;

class ConwayCellTest : public ::testing::Test {
public:
	const std::vector<int> neighborCount = {0, 1, 2, 3, 4, 5, 6, 7, 8};

	bool willRevive(int neighborCount) {
		return neighborCount == 3;
	}

	bool willKill(int neighborCount) {
		return neighborCount < 2 || neighborCount > 3;
	}
};

TEST_F(ConwayCellTest, deadCell) {
	ConwayCell x(false);
	EXPECT_FALSE(x);
}

TEST_F(ConwayCellTest, aliveCell) {
	ConwayCell x(true);
	EXPECT_TRUE(x);
}

TEST_F(ConwayCellTest, printDeadCell) {
	ConwayCell x(false);
	stringstream ss;
	ss << x;
	EXPECT_EQ(ss.str(), ".");
}

TEST_F(ConwayCellTest, printAliveCell) {
	ConwayCell x(true);
	stringstream ss;
	ss << x;
	EXPECT_EQ(ss.str(), "*");
}

TEST_F(ConwayCellTest, reviveCell) {
	for (int it : neighborCount) {
		if (willRevive(it)) {
			ConwayCell x(false);
			x.update(it);
			EXPECT_TRUE(x);
		}
	}
}

TEST_F(ConwayCellTest, killCell) {
	for (int it : neighborCount) {
		if (willKill(it)) {
			ConwayCell x(true);
			x.update(it);
			EXPECT_FALSE(x);
		}
	}
}

TEST_F(ConwayCellTest, keepCellDead) {
	for (int it : neighborCount) {
		if (!willRevive(it)) {
			ConwayCell x(false);
			x.update(it);
			EXPECT_FALSE(x);
		}
	}
}

TEST_F(ConwayCellTest, keepCellAlive) {
	for (int it : neighborCount) {
		if (!willKill(it)) {
			ConwayCell x(true);
			x.update(it);
			EXPECT_TRUE(x);
		}
	}
}

TEST_F(ConwayCellTest, neighborCount) {
	ConwayCell x;
	EXPECT_EQ(8, x.neighbors(5, 5).size());
}

TEST_F(ConwayCellTest, neighborList) {
	ConwayCell x;
	std::vector<vec2> expect = {
		{4, 4},
		{4, 5},
		{4, 6},
		{5, 4},
		{5, 6},
		{6, 4},
		{6, 5},
		{6, 6}
	};
	EXPECT_TRUE(is_permutation(begin(expect), end(expect), begin(x.neighbors(5, 5))));
}

TEST_F(ConwayCellTest, negativeNeighbor) {
	ConwayCell x;
	std::vector<vec2> expect = {
		{-1, -1},
		{-1, 0},
		{-1, 1},
		{0, -1},
		{0, 1},
		{1, -1},
		{1, 0},
		{1, 1}
	};
	EXPECT_TRUE(is_permutation(begin(expect), end(expect), begin(x.neighbors(0, 0))));
}

class FredkinCellTest : public ::testing::Test {
public:
	const std::vector<int> neighborCount = {0, 1, 2, 3, 4, 5, 6, 7, 8};

	bool willRevive(int neighborCount) {
		return neighborCount == 1 || neighborCount == 3;
	}

	bool willKill(int neighborCount) {
		return neighborCount == 0 || neighborCount == 2 || neighborCount == 4;
	}
};

TEST_F(FredkinCellTest, deadCell) {
	FredkinCell x(false);
	EXPECT_FALSE(x);
}

TEST_F(FredkinCellTest, aliveCell) {
	FredkinCell x(true);
	EXPECT_TRUE(x);
}

TEST_F(FredkinCellTest, printDeadCell) {
	FredkinCell x(false);
	stringstream ss;
	ss << x;
	EXPECT_EQ(ss.str(), "-");
}

TEST_F(FredkinCellTest, printNewCell) {
	FredkinCell x(true);
	stringstream ss;
	ss << x;
	EXPECT_EQ("0", ss.str());
}

TEST_F(FredkinCellTest, printAliveCell) {
	for (unsigned it = 0; it < 10; ++it) {
		FredkinCell x(true, it);
		stringstream ss;
		ss << x;
		EXPECT_EQ(to_string(it), ss.str());
	}
}

TEST_F(FredkinCellTest, printOldCell) {
	FredkinCell x(true, 40);
	stringstream ss;
	ss << x;
	EXPECT_EQ(ss.str(), "+");
}

TEST_F(FredkinCellTest, reviveCell) {
	for (int it : neighborCount) {
		if (willRevive(it)) {
			FredkinCell x(false);
			x.update(it);
			EXPECT_TRUE(x);
		}
	}
}

TEST_F(FredkinCellTest, killCell) {
	for (int it : neighborCount) {
		if (willKill(it)) {
			FredkinCell x(true);
			x.update(it);
			EXPECT_FALSE(x);
		}
	}
}

TEST_F(FredkinCellTest, keepCellDead) {
	for (int it : neighborCount) {
		if (!willRevive(it)) {
			FredkinCell x(false);
			x.update(it);
			EXPECT_FALSE(x);
		}
	}
}

TEST_F(FredkinCellTest, keepCellAlive) {
	for (int it : neighborCount) {
		if (!willKill(it)) {
			FredkinCell x(true);
			x.update(it);
			EXPECT_TRUE(x);
		}
	}
}

TEST_F(FredkinCellTest, ageCell) {
	stringstream ss;
	FredkinCell x(true, 0);
	for (int it = 0; it < 10; ++it) {
		ss << x;
		x.update(1);
	}
	ss << x;
	EXPECT_EQ("0123456789+", ss.str());
}

TEST_F(FredkinCellTest, preventAging) {
	stringstream ss;
	FredkinCell x(true, 0);
	for (int it = 0; it < 2; ++it) {
		ss << x;
		x.update(0);
		ss << x;
		x.update(1);
	}
	ss << x;
	EXPECT_EQ("0-0-0", ss.str());
}

TEST_F(FredkinCellTest, neighborCount) {
	FredkinCell x;
	EXPECT_EQ(4, x.neighbors(5, 5).size());
}

TEST_F(FredkinCellTest, neighborList) {
	FredkinCell x;
	std::vector<vec2> expect = {
		{4, 5},
		{5, 4},
		{5, 6},
		{6, 5},
	};
	EXPECT_TRUE(is_permutation(begin(expect), end(expect), begin(x.neighbors(5, 5))));
}

TEST_F(FredkinCellTest, negativeNeighbor) {
	FredkinCell x;
	std::vector<vec2> expect = {
		{-1, 0},
		{0, -1},
		{0, 1},
		{1, 0},
	};
	EXPECT_TRUE(is_permutation(begin(expect), end(expect), begin(x.neighbors(0, 0))));
}

TEST(HandleCellTest, CellLifeDelegation) {
	Cell x = ConwayCell(false);
	EXPECT_FALSE(x);
	x = ConwayCell(true);
	EXPECT_TRUE(x);

	x = FredkinCell(false);
	EXPECT_FALSE(x);
	x = FredkinCell(true);
	EXPECT_TRUE(x);
}

TEST(HandleCellTest, CellNeighborDelegation) {
	Cell x = ConwayCell(false);
	std::vector<vec2> expect = {
		{-1, -1},
		{-1, 0},
		{-1, 1},
		{0, -1},
		{0, 1},
		{1, -1},
		{1, 0},
		{1, 1}
	};
	EXPECT_TRUE(is_permutation(begin(expect), end(expect), begin(x.neighbors(0, 0))));

	x = FredkinCell(false);
	expect = {
		{-1, 0},
		{0, -1},
		{0, 1},
		{1, 0},
	};
	EXPECT_TRUE(is_permutation(begin(expect), end(expect), begin(x.neighbors(0, 0))));
}

TEST(HandleCellTest, CellPrintDelegation) {
	stringstream ss;
	ss
		<< "Conway: " << Cell(ConwayCell(false)) << Cell(ConwayCell(true)) << std::endl
		<< "Fredkin: " << Cell(FredkinCell(false)) << Cell(FredkinCell(true))
		<< Cell(FredkinCell(true, 1));
	EXPECT_EQ(ss.str(), "Conway: .*\nFredkin: -01");
}

TEST(HandleCellTest, updateConwayDelegation) {
	stringstream ss;
	Cell x = ConwayCell(false);
	for (const auto& it : {2, 3, 2, 1}) {
		ss << x;
		x.update(it);
	}
	ss << x;
	EXPECT_EQ("..**.", ss.str());
}

TEST(HandleCellTest, updateFredkinDelegation) {
	stringstream ss;
	Cell x = FredkinCell(false);
	for (const auto& it : {0, 1, 2, 3, 3}) {
		ss << x;
		x.update(it);
	}
	ss << x;
	EXPECT_EQ("--0-01", ss.str());
}

TEST(HandleCellTest, cellTransformation) {
	stringstream ss;
	Cell x = FredkinCell(false);
	for (const auto& it : {3, 3, 3, 3, 4}) {
		ss << x;
		x.update(it);
	}
	ss << x;
	EXPECT_EQ("-01**.", ss.str());
}

TEST(LifeBoard, printBoard) {
	stringstream ss;
	Life<int> x(2, 4);
	ss << x;
	EXPECT_EQ(
		"Generation = 0, Population = 0.\n"
		"0000\n"
		"0000\n",
		ss.str());
}

TEST(LifeBoard, placeCell) {
	stringstream ss;
	Life<int> x(2, 4);
	x.placeCell(1, 2, 4);
	ss << x;
	x.placeCell(0, 3, 5);
	ss << x;
	EXPECT_EQ(
		"Generation = 0, Population = 1.\n"
		"0000\n"
		"0040\n"
		"Generation = 0, Population = 2.\n"
		"0005\n"
		"0040\n",
		ss.str());
}

TEST(ConwayLife, emptyConwayBoard) {
	stringstream ss;
	Life<ConwayCell> x(3, 5);
	ss << x;
	EXPECT_EQ(
		"Generation = 0, Population = 0.\n"
		".....\n"
		".....\n"
		".....\n",
		ss.str());
}

TEST(ConwayLife, conwayInput) {
	stringstream ss;
	Life<ConwayCell> x(3, 5);
	string board =
			"*....\n"
			".*..*\n"
			"*.***\n";
	stringstream iss(board);
	iss >> x;
	ss << x;
	EXPECT_EQ(
		"Generation = 0, Population = 7.\n" + board,
		ss.str());
}

TEST(ConwayLife, conwayBoard) {
	stringstream ss;
	Life<ConwayCell> x(3, 5);
	x.placeCell(0, 0, true);
	x.placeCell(1, 1, true);
	x.placeCell(1, 1, false);
	x.placeCell(2, 4, true);
	ss << x;
	EXPECT_EQ(
		"Generation = 0, Population = 2.\n"
		"*....\n"
		".....\n"
		"....*\n",
		ss.str());
}

TEST(ConwayLife, emptyUpdate) {
	stringstream ss;
	Life<ConwayCell> x(3, 5);
	ss << x;
	x.update();
	ss << x;
	EXPECT_EQ(
		"Generation = 0, Population = 0.\n"
		".....\n"
		".....\n"
		".....\n"
		"Generation = 1, Population = 0.\n"
		".....\n"
		".....\n"
		".....\n",
		ss.str());
}

TEST(ConwayLife, underPopulation) {
	stringstream ss;
	Life<ConwayCell> x(3, 5);
	x.placeCell(0, 0, true);
	x.placeCell(0, 1, true);
	x.placeCell(0, 3, true);
	x.placeCell(0, 4, true);
	x.placeCell(2, 0, true);
	x.placeCell(2, 1, true);
	x.placeCell(2, 3, true);
	x.placeCell(2, 4, true);
	ss << x;
	x.update();
	ss << x;
	EXPECT_EQ(
		"Generation = 0, Population = 8.\n"
		"**.**\n"
		".....\n"
		"**.**\n"
		"Generation = 1, Population = 0.\n"
		".....\n"
		".....\n"
		".....\n",
		ss.str());
}

TEST(ConwayLife, overPopulation) {
	stringstream ss;
	Life<ConwayCell> x(3, 5);
	for (unsigned r = 0; r < 3; ++r)
		for (unsigned c = 0; c < 5; ++c)
			x.placeCell(r, c, true);
	ss << x;
	x.update();
	ss << x;
	EXPECT_EQ(
		"Generation = 0, Population = 15.\n"
		"*****\n"
		"*****\n"
		"*****\n"
		"Generation = 1, Population = 4.\n"
		"*...*\n"
		".....\n"
		"*...*\n",
		ss.str());
}

TEST(ConwayLife, reviveCell) {
	stringstream ss;
	Life<ConwayCell> x(3, 5);
	x.placeCell(0, 2, true);
	x.placeCell(2, 1, true);
	x.placeCell(2, 3, true);
	ss << x;
	x.update();
	ss << x;
	EXPECT_EQ(
		"Generation = 0, Population = 3.\n"
		"..*..\n"
		".....\n"
		".*.*.\n"
		"Generation = 1, Population = 1.\n"
		".....\n"
		"..*..\n"
		".....\n",
		ss.str());
}

TEST(ConwayLife, boardCorners) {
	stringstream ss;
	Life<ConwayCell> x(3, 5);
	x.placeCell(0, 0, true);
	x.placeCell(0, 4, true);
	x.placeCell(2, 0, true);
	x.placeCell(2, 4, true);
	ss << x;
	x.update();
	ss << x;
	EXPECT_EQ(
		"Generation = 0, Population = 4.\n"
		"*...*\n"
		".....\n"
		"*...*\n"
		"Generation = 1, Population = 0.\n"
		".....\n"
		".....\n"
		".....\n",
		ss.str());
}

TEST(ConwayLife, boardEdges) {
	stringstream ss;
	Life<ConwayCell> x(3, 5);
	x.placeCell(0, 1, true);
	x.placeCell(0, 3, true);
	x.placeCell(2, 1, true);
	x.placeCell(2, 3, true);
	x.placeCell(1, 0, true);
	x.placeCell(1, 4, true);
	ss << x;
	x.update();
	ss << x;
	EXPECT_EQ(
		"Generation = 0, Population = 6.\n"
		".*.*.\n"
		"*...*\n"
		".*.*.\n"
		"Generation = 1, Population = 4.\n"
		".....\n"
		"**.**\n"
		".....\n",
		ss.str());
}

TEST(ConwayLife, conwayGlider) {
	stringstream ss;
	Life<ConwayCell> x(6, 9);
	x.placeCell(1, 2, true);
	x.placeCell(2, 3, true);
	x.placeCell(3, 1, true);
	x.placeCell(3, 2, true);
	x.placeCell(3, 3, true);
	ss << x;
	x.update();
	ss << x;
	x.update();
	ss << x;
	x.update();
	ss << x;
	x.update();
	ss << x;
	EXPECT_EQ(
		"Generation = 0, Population = 5.\n"
		".........\n"
		"..*......\n"
		"...*.....\n"
		".***.....\n"
		".........\n"
		".........\n"
		"Generation = 1, Population = 5.\n"
		".........\n"
		".........\n"
		".*.*.....\n"
		"..**.....\n"
		"..*......\n"
		".........\n"
		"Generation = 2, Population = 5.\n"
		".........\n"
		".........\n"
		"...*.....\n"
		".*.*.....\n"
		"..**.....\n"
		".........\n"
		"Generation = 3, Population = 5.\n"
		".........\n"
		".........\n"
		"..*......\n"
		"...**....\n"
		"..**.....\n"
		".........\n"
		"Generation = 4, Population = 5.\n"
		".........\n"
		".........\n"
		"...*.....\n"
		"....*....\n"
		"..***....\n"
		".........\n",
		ss.str());
}

TEST(FredkinLife, emptyFredkinBoard) {
	stringstream ss;
	Life<FredkinCell> x(3, 5);
	ss << x;
	EXPECT_EQ(
		"Generation = 0, Population = 0.\n"
		"-----\n"
		"-----\n"
		"-----\n",
		ss.str());
}

TEST(FredkinLife, fredkinInput) {
	stringstream ss;
	Life<FredkinCell> x(3, 5);
	string board =
			"--+++\n"
			"01234\n"
			"56789\n";
	stringstream iss(board);
	iss >> x;
	ss << x;
	EXPECT_EQ(
		"Generation = 0, Population = 13.\n" + board,
		ss.str());
}

TEST(FredkinLife, fredkinBoard) {
	stringstream ss;
	Life<FredkinCell> x(3, 5);
	x.placeCell(0, 0, true);
	x.placeCell(1, 1, true);
	x.placeCell(1, 1, false);
	x.placeCell(2, 4, true);
	ss << x;
	EXPECT_EQ(
		"Generation = 0, Population = 2.\n"
		"0----\n"
		"-----\n"
		"----0\n",
		ss.str());
}

TEST(FredkinLife, emptyUpdate) {
	stringstream ss;
	Life<FredkinCell> x(3, 5);
	ss << x;
	x.update();
	ss << x;
	EXPECT_EQ(
		"Generation = 0, Population = 0.\n"
		"-----\n"
		"-----\n"
		"-----\n"
		"Generation = 1, Population = 0.\n"
		"-----\n"
		"-----\n"
		"-----\n",
		ss.str());
}

TEST(FredkinLife, aging) {
	stringstream ss;
	Life<FredkinCell> x(1, 2);
	x.placeCell(0, 0, true);
	x.placeCell(0, 1, true);
	ss << x;
	for (int it = 0; it < 10; ++it) {
		x.update();
		ss << x;
	}
	EXPECT_EQ(
		"Generation = 0, Population = 2.\n"
		"00\n"
		"Generation = 1, Population = 2.\n"
		"11\n"
		"Generation = 2, Population = 2.\n"
		"22\n"
		"Generation = 3, Population = 2.\n"
		"33\n"
		"Generation = 4, Population = 2.\n"
		"44\n"
		"Generation = 5, Population = 2.\n"
		"55\n"
		"Generation = 6, Population = 2.\n"
		"66\n"
		"Generation = 7, Population = 2.\n"
		"77\n"
		"Generation = 8, Population = 2.\n"
		"88\n"
		"Generation = 9, Population = 2.\n"
		"99\n"
		"Generation = 10, Population = 2.\n"
		"++\n",
		ss.str());
}

TEST(FredkinLife, reviveCell) {
	stringstream ss;
	Life<FredkinCell> x(3, 5);
	x.placeCell(1, 2, true);
	ss << x;
	x.update();
	ss << x;
	EXPECT_EQ(
		"Generation = 0, Population = 1.\n"
		"-----\n"
		"--0--\n"
		"-----\n"
		"Generation = 1, Population = 4.\n"
		"--0--\n"
		"-0-0-\n"
		"--0--\n",
		ss.str());
}

TEST(FredkinLife, reviveOldCell) {
	stringstream ss;
	Life<FredkinCell> x(3, 5);
	x.placeCell(0, 2, {false, 5});
	x.placeCell(2, 2, {false, 10});
	x.placeCell(1, 2, true);
	ss << x;
	x.update();
	ss << x;
	EXPECT_EQ(
		"Generation = 0, Population = 1.\n"
		"-----\n"
		"--0--\n"
		"-----\n"
		"Generation = 1, Population = 4.\n"
		"--5--\n"
		"-0-0-\n"
		"--+--\n",
		ss.str());
}

TEST(FredkinLife, boardCorners) {
	stringstream ss;
	Life<FredkinCell> x(3, 5);
	x.placeCell(0, 0, true);
	x.placeCell(0, 4, true);
	x.placeCell(2, 0, true);
	x.placeCell(2, 4, true);
	ss << x;
	x.update();
	ss << x;
	EXPECT_EQ(
		"Generation = 0, Population = 4.\n"
		"0---0\n"
		"-----\n"
		"0---0\n"
		"Generation = 1, Population = 4.\n"
		"-0-0-\n"
		"-----\n"
		"-0-0-\n",
		ss.str());
}

TEST(FredkinLife, boardEdges) {
	stringstream ss;
	Life<FredkinCell> x(3, 5);
	x.placeCell(0, 1, true);
	x.placeCell(0, 3, true);
	x.placeCell(2, 1, true);
	x.placeCell(2, 3, true);
	x.placeCell(1, 0, true);
	x.placeCell(1, 4, true);
	ss << x;
	x.update();
	ss << x;
	EXPECT_EQ(
		"Generation = 0, Population = 6.\n"
		"-0-0-\n"
		"0---0\n"
		"-0-0-\n"
		"Generation = 1, Population = 2.\n"
		"-----\n"
		"-0-0-\n"
		"-----\n",
		ss.str());
}
