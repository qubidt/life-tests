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
#include <limits>	//size_t max
#include <sstream>  //ostringstream

using namespace std;

// ------------
// Life
// ------------

TEST(Life, Constructor1){
	try{
		Life<ConwayCell> x(0,0);
	}
	catch(exception& e){
		ASSERT_TRUE(false);
	}
}

TEST(Life, Constructor2){
	bool errorOccured = false;
	try{
		Life<Cell> x(std::numeric_limits<std::size_t>::max(), std::numeric_limits<std::size_t>::max());
	}
	catch(exception& e){
		errorOccured = true;
	}
	ASSERT_TRUE(errorOccured);
}

TEST(Life, addCell1){
	Life<FredkinCell> x(5,5);
	x.addCell(ALIVE, 0, 0);
	x.addCell(ALIVE, 4, 4);
	stringstream output;
	output << x;
	stringstream expected("Population = 2.\n0----\n-----\n-----\n-----\n----0\n");
	ASSERT_EQ(expected.str(), output.str());
}


TEST(Life, addCell2){
	Life<ConwayCell> x(5,5);
	x.addCell(ALIVE, 0, 0);
	x.addCell(ALIVE, 4, 4);
	stringstream output;
	output << x;
	stringstream expected("Population = 2.\n*....\n.....\n.....\n.....\n....*\n");
	ASSERT_EQ(expected.str(), output.str());
}

TEST(Life, addCell3){
	Life<Cell> x(2,2);
	bool errorOccured = false;
	FredkinCell* f1 = new FredkinCell(DEAD);
	ConwayCell*  c2 = new ConwayCell(DEAD);
	ConwayCell*  c3 = new ConwayCell(DEAD);
	ConwayCell*  c4 = new ConwayCell(DEAD);
	try{
		x.addCell(Cell(f1), 0, 0);
		x.addCell(Cell(c2), 0, 1);
		x.addCell(Cell(c3), 1, 0);
		x.addCell(Cell(c4), 1, 1);
	}
	catch(invalid_argument& e){
		errorOccured = true;
	}
	ASSERT_FALSE(errorOccured);
	stringstream output;
	output << x;
	stringstream expected("Population = 0.\n-.\n..\n");
	ASSERT_EQ(expected.str(), output.str());
	delete f1;
	delete c2;
	delete c3;
	delete c4;
}


TEST(Life, iterate1){
	Life<ConwayCell> x(5,5);
	x.addCell(ALIVE, 0, 0);
	x.addCell(ALIVE, 4, 4);
	x.iterate();
	x.iterate();
	stringstream output;
	output << x;
	stringstream expected("Population = 0.\n.....\n.....\n.....\n.....\n.....\n");
	ASSERT_EQ(expected.str(), output.str());
}


TEST(Life, iterate2){
	Life<FredkinCell> x(5,5);
	x.addCell(ALIVE, 0, 0);
	x.addCell(ALIVE, 4, 4);
	x.iterate();
	x.iterate();
	stringstream output;
	output << x;
	stringstream expected("Population = 4.\n--0--\n-----\n0---0\n-----\n--0--\n");
	ASSERT_EQ(expected.str(), output.str());
}


TEST(Life, iterate3){
	Life<Cell> x(2,2);
	FredkinCell* f1 = new FredkinCell(ALIVE);
	ConwayCell*  c2 = new ConwayCell(ALIVE);
	FredkinCell* f3 = new FredkinCell(DEAD);
	FredkinCell* f4 = new FredkinCell(DEAD);
	x.addCell(Cell(f1), 0, 0);
	x.addCell(Cell(c2), 0, 1);
	x.addCell(Cell(f3), 1, 0);
	x.addCell(Cell(f4), 1, 1);
	for(int i=0; i<15; ++i){
		x.iterate();
	}
	stringstream output;
	output << x;
	stringstream expected("Population = 3.\n**\n-*\n");
	ASSERT_EQ(expected.str(), output.str());
	delete f1;
	delete c2;
	delete f3;
	delete f4;
}

TEST(Life, outOfBounds1){
	Life<Cell> x(5,5);
	ASSERT_TRUE(x.outOfBounds(-1,-1));
}

TEST(Life, outOfBounds2){
	Life<FredkinCell> x(5,5);
	ASSERT_TRUE(x.outOfBounds(10,10));
}

TEST(Life, outOfBounds3){
	Life<ConwayCell> x(5, 5);
	ASSERT_TRUE(x.outOfBounds(5, 5));
}






// ------------
// ConwayCell
// ------------







TEST(ConwayCell, ConstructDefault) {
	ConwayCell c;
	ASSERT_FALSE(c._isAlive);
	ASSERT_FALSE(c._nextIsAlive);
}

TEST(ConwayCell, ConstructLiveCell) {
	ConwayCell c(true);
	ASSERT_TRUE(c._isAlive);
	ASSERT_TRUE(c._nextIsAlive);
}

TEST(ConwayCell, ConstructDeadCell) {
	ConwayCell c(false);
	ASSERT_FALSE(c._isAlive);
	ASSERT_TRUE(c._nextIsAlive);
}

TEST(ConwayCell, PrintLive) {
	ConwayCell c(true);
	ostringstream out;
  	ASSERT_TRUE(c._isAlive);
  	ASSERT_TRUE(c._nextIsAlive);

  	out << c;
  	ASSERT_EQ("*", out.str());
}

TEST(ConwayCell, PrintDead) {
	ConwayCell c(false);
	ostringstream out;
  	ASSERT_FALSE(c._isAlive);
  	ASSERT_TRUE(c._nextIsAlive);
  	out << c;
  	ASSERT_EQ(".", out.str());
}

TEST(ConwayCell, Execute1) {
	ConwayCell NW(true);
	ConwayCell N(false);
	ConwayCell NE(false);
	ConwayCell E(false);
	ConwayCell SE(false);
	ConwayCell S(false);
	ConwayCell SW(false);
	ConwayCell W(false);
	AbstractCell* neighbors[8] = {&NW, &N, &NE, &E, &SE, &S, &SW, &W};

	ConwayCell c(true);
	c.execute(neighbors);
	ASSERT_FALSE(c._nextIsAlive);
}

TEST(ConwayCell, Execute2) {
	ConwayCell NW(true);
	ConwayCell N(true);
	ConwayCell NE(false);
	ConwayCell E(false);
	ConwayCell SE(false);
	ConwayCell S(false);
	ConwayCell SW(false);
	ConwayCell W(false);
	AbstractCell* neighbors[8] = {&NW, &N, &NE, &E, &SE, &S, &SW, &W};

	ConwayCell c(true);
	c.execute(neighbors);
	ASSERT_TRUE(c._nextIsAlive);
}

TEST(ConwayCell, Execute3) {
	ConwayCell NW(true);
	ConwayCell N(true);
	ConwayCell NE(true);
	ConwayCell E(false);
	ConwayCell SE(false);
	ConwayCell S(false);
	ConwayCell SW(false);
	ConwayCell W(false);
	AbstractCell* neighbors[8] = {&NW, &N, &NE, &E, &SE, &S, &SW, &W};

	ConwayCell c(true);
	c.execute(neighbors);
	ASSERT_TRUE(c._nextIsAlive);
}

TEST(ConwayCell, Execute4) {
	ConwayCell NW(true);
	ConwayCell N(true);
	ConwayCell NE(true);
	ConwayCell E(true);
	ConwayCell SE(false);
	ConwayCell S(false);
	ConwayCell SW(false);
	ConwayCell W(false);
	AbstractCell* neighbors[8] = {&NW, &N, &NE, &E, &SE, &S, &SW, &W};

	ConwayCell c(true);
	c.execute(neighbors);
	ASSERT_FALSE(c._nextIsAlive);
}

TEST(ConwayCell, Execute5) {
	ConwayCell NW(true);
	ConwayCell N(false);
	ConwayCell NE(false);
	ConwayCell E(false);
	ConwayCell SE(false);
	ConwayCell S(false);
	ConwayCell SW(false);
	ConwayCell W(false);
	AbstractCell* neighbors[8] = {&NW, &N, &NE, &E, &SE, &S, &SW, &W};

	ConwayCell c(false);
	c.execute(neighbors);
	ASSERT_FALSE(c._nextIsAlive);
}

TEST(ConwayCell, Execute6) {
	ConwayCell NW(true);
	ConwayCell N(true);
	ConwayCell NE(false);
	ConwayCell E(false);
	ConwayCell SE(false);
	ConwayCell S(false);
	ConwayCell SW(false);
	ConwayCell W(false);
	AbstractCell* neighbors[8] = {&NW, &N, &NE, &E, &SE, &S, &SW, &W};

	ConwayCell c(false);
	c.execute(neighbors);
	ASSERT_FALSE(c._nextIsAlive);
}

TEST(ConwayCell, Execute7) {
	ConwayCell NW(true);
	ConwayCell N(true);
	ConwayCell NE(true);
	ConwayCell E(false);
	ConwayCell SE(false);
	ConwayCell S(false);
	ConwayCell SW(false);
	ConwayCell W(false);
	AbstractCell* neighbors[8] = {&NW, &N, &NE, &E, &SE, &S, &SW, &W};

	ConwayCell c(false);
	c.execute(neighbors);
	ASSERT_TRUE(c._nextIsAlive);
}

TEST(ConwayCell, Execute8) {
	ConwayCell NW(true);
	ConwayCell N(true);
	ConwayCell NE(true);
	ConwayCell E(true);
	ConwayCell SE(false);
	ConwayCell S(false);
	ConwayCell SW(false);
	ConwayCell W(false);
	AbstractCell* neighbors[8] = {&NW, &N, &NE, &E, &SE, &S, &SW, &W};

	ConwayCell c(false);
	c.execute(neighbors);
	ASSERT_FALSE(c._nextIsAlive);
}

TEST(ConwayCell, Execute9) {
	AbstractCell* neighbors[8] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};

	ConwayCell c(true);
	c.execute(neighbors);
	ASSERT_FALSE(c._nextIsAlive);
}

TEST(ConwayCell, Update1) {
	ConwayCell c(false);
	ASSERT_FALSE(c._isAlive);

	c.update();
	ASSERT_TRUE(c._isAlive);
}

TEST(ConwayCell, Update2) {
	ConwayCell c(true);
	ASSERT_TRUE(c._isAlive);

	c.update();
	ASSERT_TRUE(c._isAlive);
}

TEST(ConwayCell, Clone1) {
	ConwayCell c(true);
	AbstractCell* clone = c.clone();
	ConwayCell c2 = clone;
	delete clone;
	ASSERT_TRUE(c._isAlive);
	ASSERT_TRUE(c2._isAlive);
	ASSERT_TRUE(c._nextIsAlive);
	ASSERT_TRUE(c2._nextIsAlive);
}

TEST(ConwayCell, Clone2) {
	ConwayCell c(true);
	AbstractCell* clone1 = c.clone();
	ConwayCell c2 = clone1;
	AbstractCell* clone2 = c2.clone();
	ConwayCell c3 = clone2;
	delete clone1;
	delete clone2;
	ASSERT_TRUE(c._isAlive);
	ASSERT_TRUE(c2._isAlive);
	ASSERT_TRUE(c3._isAlive);
	ASSERT_TRUE(c._nextIsAlive);
	ASSERT_TRUE(c2._nextIsAlive);
	ASSERT_TRUE(c3._nextIsAlive);
}

TEST(ConwayCell, Evolve) {
	ConwayCell c(false);
	ASSERT_EQ(nullptr, c.evolve());
}





// ------------
// FredkinCell
// ------------








TEST(FredkinCell, ConstructDefault) {
	FredkinCell c;
	ASSERT_EQ(0, c._age);
	ASSERT_EQ(0, c._nextAge);
}

TEST(FredkinCell, ConstructLiveCell) {
	FredkinCell c(true);
	ASSERT_EQ(0, c._age);
	ASSERT_EQ(0, c._nextAge);
	ASSERT_TRUE(c._isAlive);
}

TEST(FredkinCell, ConstructDeadCell) {
	FredkinCell c(false);
	ASSERT_EQ(0, c._age);
	ASSERT_EQ(0, c._nextAge);
	ASSERT_FALSE(c._isAlive);
}

TEST(FredkinCell, PrintLive) {
	FredkinCell c(true);
	ostringstream out;
	out << c;
  	ASSERT_EQ("0", out.str());
}

TEST(FredkinCell, PrintDead) {
	FredkinCell c(false);
	ostringstream out;
	out << c;
  	ASSERT_EQ("-", out.str());
}

TEST(FredkinCell, CopyConstruct1) {
	FredkinCell c(true);
	FredkinCell d(c);
	ASSERT_TRUE(d._isAlive);
	ASSERT_EQ(0, d._age);
	ASSERT_EQ(0, d._nextAge);
}

TEST(FredkinCell, CopyConstruct2) {
	FredkinCell c(false);
	FredkinCell d(c);
	ASSERT_FALSE(d._isAlive);
	ASSERT_EQ(0, d._age);
	ASSERT_EQ(0, d._nextAge);
}

TEST(FredkinCell, Execute1) {
	ConwayCell N(true);
	ConwayCell E(false);
	ConwayCell S(false);
	ConwayCell W(false);
	AbstractCell* neighbors[8] = {nullptr, &N, nullptr, &E, nullptr, &S, nullptr, &W};

	FredkinCell c(true);
	c.execute(neighbors);
	ASSERT_TRUE(c._nextIsAlive);
}

TEST(FredkinCell, Execute2) {
	ConwayCell N(true);
	ConwayCell E(true);
	ConwayCell S(false);
	ConwayCell W(false);
	AbstractCell* neighbors[8] = {nullptr, &N, nullptr, &E, nullptr, &S, nullptr, &W};

	FredkinCell c(true);
	c.execute(neighbors);
	ASSERT_FALSE(c._nextIsAlive);
}

TEST(FredkinCell, Execute3) {
	ConwayCell N(true);
	ConwayCell E(true);
	ConwayCell S(true);
	ConwayCell W(false);
	AbstractCell* neighbors[8] = {nullptr, &N, nullptr, &E, nullptr, &S, nullptr, &W};

	FredkinCell c(true);
	c.execute(neighbors);
	ASSERT_TRUE(c._nextIsAlive);
}

TEST(FredkinCell, Execute4) {
	ConwayCell N(true);
	ConwayCell E(true);
	ConwayCell S(true);
	ConwayCell W(true);
	AbstractCell* neighbors[8] = {nullptr, &N, nullptr, &E, nullptr, &S, nullptr, &W};

	FredkinCell c(true);
	c.execute(neighbors);
	ASSERT_FALSE(c._nextIsAlive);
}

TEST(FredkinCell, Execute5) {
	ConwayCell N(true);
	ConwayCell E(false);
	ConwayCell S(false);
	ConwayCell W(false);
	AbstractCell* neighbors[8] = {nullptr, &N, nullptr, &E, nullptr, &S, nullptr, &W};

	FredkinCell c(false);
	c.execute(neighbors);
	ASSERT_TRUE(c._nextIsAlive);
}

TEST(FredkinCell, Execute6) {
	ConwayCell N(true);
	ConwayCell E(true);
	ConwayCell S(false);
	ConwayCell W(false);
	AbstractCell* neighbors[8] = {nullptr, &N, nullptr, &E, nullptr, &S, nullptr, &W};

	FredkinCell c(false);
	c.execute(neighbors);
	ASSERT_FALSE(c._nextIsAlive);
}

TEST(FredkinCell, Execute7) {
	ConwayCell N(true);
	ConwayCell E(true);
	ConwayCell S(true);
	ConwayCell W(false);
	AbstractCell* neighbors[8] = {nullptr, &N, nullptr, &E, nullptr, &S, nullptr, &W};

	FredkinCell c(false);
	c.execute(neighbors);
	ASSERT_TRUE(c._nextIsAlive);
}

TEST(FredkinCell, Execute8) {
	ConwayCell N(true);
	ConwayCell E(true);
	ConwayCell S(true);
	ConwayCell W(true);
	AbstractCell* neighbors[8] = {nullptr, &N, nullptr, &E, nullptr, &S, nullptr, &W};

	FredkinCell c(false);
	c.execute(neighbors);
	ASSERT_FALSE(c._nextIsAlive);
}

TEST(FredkinCell, Execute9) {
	AbstractCell* neighbors[8] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};

	FredkinCell c(false);
	c.execute(neighbors);
	ASSERT_FALSE(c._nextIsAlive);
}

TEST(FredkinCell, Update1) {
	FredkinCell c(false);
	ASSERT_FALSE(c._isAlive);
	ASSERT_EQ(0, c._age);

	c.update();
	ASSERT_FALSE(c._isAlive);
	ASSERT_EQ(0, c._age);
}

TEST(FredkinCell, Update2) {
	FredkinCell c(true);
	ASSERT_TRUE(c._isAlive);
	ASSERT_EQ(0, c._age);

	c.update();
	ASSERT_FALSE(c._isAlive);
	ASSERT_EQ(0, c._age);
}

TEST(FredkinCell, Clone1) {
	FredkinCell c(true);
	AbstractCell* clone = c.clone();
	FredkinCell c2 = clone;
	delete clone;
	ASSERT_EQ(0, c._age);
	ASSERT_EQ(0, c._nextAge);
	ASSERT_EQ(0, c2._age);
	ASSERT_EQ(0, c2._nextAge);
}

TEST(FredkinCell, Clone2) {
	FredkinCell c(true);
	AbstractCell* clone1 = c.clone();
	FredkinCell c2 = clone1;
	AbstractCell* clone2 = c2.clone();
	FredkinCell c3 = clone2;
	delete clone1;
	delete clone2;
	ASSERT_EQ(0, c._age);
	ASSERT_EQ(0, c2._age);
	ASSERT_EQ(0, c3._age);
	ASSERT_EQ(0, c._nextAge);
	ASSERT_EQ(0, c2._nextAge);
	ASSERT_EQ(0, c3._nextAge);
}

TEST(FredkinCell, Evolve1) {
	FredkinCell c(false);
	ASSERT_EQ(nullptr, c.evolve());
}

TEST(FredkinCell, Evolve2) {
	FredkinCell c(false);
	c._age = 1;
	c._nextAge = 2;
	AbstractCell* evolved = c.evolve();
	ConwayCell e = evolved;
  	delete evolved;
	ostringstream out;
	out << e;
  	ASSERT_EQ("*", out.str());

}








// ------------
// Cell
// ------------











TEST(Cell, ConstructDefault){
	Cell c;
	ASSERT_EQ(nullptr, c._p);
}

TEST(Cell, ConstructLiveConwayCell){
	ConwayCell* cc = new ConwayCell(ALIVE);
	Cell c(cc);
	ASSERT_TRUE(c._p->_isAlive);
	delete cc;
}

TEST(Cell, ConstructLiveFredkinCell){
	FredkinCell* fc = new FredkinCell(ALIVE);
	Cell c(fc);
	ASSERT_TRUE(c._p->_isAlive);
	delete fc;
}

TEST(Cell, ConstructDeadConwayCell){
	ConwayCell* cc = new ConwayCell(DEAD);
	Cell c(cc);
	ASSERT_FALSE(c._p->_isAlive);
	delete cc;
}

TEST(Cell, ConstructDeadFredkinCell){
	FredkinCell* fc = new FredkinCell(DEAD);
	Cell c(fc);
	ASSERT_FALSE(c._p->_isAlive);
	delete fc;
}

TEST(Cell, PrintLiveConway){
	ConwayCell* cc = new ConwayCell(ALIVE);
	Cell c(cc);
	ostringstream out;
	out << c;
  	ASSERT_EQ("*", out.str());
	delete cc;
}

TEST(Cell, PrintLiveFredkin){
	FredkinCell* fc = new FredkinCell(ALIVE);
	Cell c(fc);
	ostringstream out;
	out << c;
  	ASSERT_EQ("0", out.str());
	delete fc;
}

TEST(Cell, PrintDeadConway){
	ConwayCell* cc = new ConwayCell(DEAD);
	Cell c(cc);
	ostringstream out;
	out << c;
  	ASSERT_EQ(".", out.str());
	delete cc;
}

TEST(Cell, PrintDeadFredkin){
	FredkinCell* fc = new FredkinCell(DEAD);
	Cell c(fc);
	ostringstream out;
	out << c;
  	ASSERT_EQ("-", out.str());
	delete fc;
}

TEST(Cell, Clone1) {
	Cell c;
	Cell c2 = c;
	ASSERT_EQ(nullptr, c2._p);
}

TEST(Cell, Clone2) {
	FredkinCell* fc = new FredkinCell(ALIVE);
	Cell c(fc);
	Cell c2 = c;
	Cell c3 = c2;
	ASSERT_NE(&c, &c2);
	ASSERT_NE(&c2, &c3);
	ASSERT_NE(&c, &c3);
	ASSERT_NE(c._p, c2._p);
	ASSERT_NE(c3._p, c2._p);
	ASSERT_NE(c._p, c3._p);
	delete fc;
}


TEST(Cell, Execute1) {
	ConwayCell* N = new ConwayCell(ALIVE);
	ConwayCell* E = new ConwayCell(DEAD);
	ConwayCell* S = new ConwayCell(DEAD);
	ConwayCell* W = new ConwayCell(DEAD);
	Cell Nc(N);
	Cell Ec(E);
	Cell Sc(S);
	Cell Wc(W);
	Cell* neighbors[8] = {nullptr, &Nc, nullptr, &Ec, nullptr, &Sc, nullptr, &Wc};

	FredkinCell* fc = new FredkinCell(ALIVE);
	Cell c(fc);
	c.execute(neighbors);
	ASSERT_TRUE(c._p->_nextIsAlive);
	delete N;
	delete E;
	delete S;
	delete W;
	delete fc;
}


TEST(Cell, Execute2) {
	ConwayCell* N = new ConwayCell(ALIVE);
	ConwayCell* E = new ConwayCell(ALIVE);
	ConwayCell* S = new ConwayCell(ALIVE);
	ConwayCell* W = new ConwayCell(ALIVE);
	Cell Nc(N);
	Cell Ec(E);
	Cell Sc(S);
	Cell Wc(W);
	Cell* neighbors[8] = {nullptr, &Nc, nullptr, &Ec, nullptr, &Sc, nullptr, &Wc};

	FredkinCell* fc = new FredkinCell(ALIVE);
	Cell c(fc);
	c.execute(neighbors);
	ASSERT_FALSE(c._p->_nextIsAlive);
	delete N;
	delete E;
	delete S;
	delete W;
	delete fc;
}

TEST(Cell, Execute3) {
	Cell* neighbors[8] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};

	FredkinCell* fc = new FredkinCell(DEAD);
	Cell c(fc);
	c.execute(neighbors);
	ASSERT_FALSE(c._p->_nextIsAlive);
	delete fc;
}

TEST(Cell, Evolve1) {
	FredkinCell* fc = new FredkinCell(ALIVE);
	fc->_age = 1;
	fc->_nextAge = 2;
	Cell c(fc);
	ostringstream output1;
	ostringstream output2;
	output1 << c;
	c.evolve();
	output2 << c;
	ASSERT_EQ("1", output1.str());
	ASSERT_EQ("*", output2.str());
	delete fc;
}

TEST(Cell, Evolve2){
	ConwayCell* cc = new ConwayCell(ALIVE);
	Cell c(cc);
	AbstractCell* resutl1 = c._p->evolve();
	AbstractCell* resutl2 = c.evolve();
	ostringstream output1;
	output1 << c;
	ASSERT_EQ("*", output1.str());
	ASSERT_EQ(nullptr, resutl1);
	ASSERT_EQ(nullptr, resutl2);
	delete cc;
}


TEST(Cell, Evolve3) {
	Cell c;
	AbstractCell* result = c.evolve();
	ASSERT_EQ(nullptr, result);
	ASSERT_EQ(nullptr, c._p);
}

