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
#include <sstream> // istringtstream, ostringstream

#include "Life.h"

using namespace std;

//
// Life
//

TEST(Life, Life_constructor_1) {
  Life<int> l(5, 5);

  ASSERT_EQ(l.width, 7);
  ASSERT_EQ(l.height, 7);
}

TEST(Life, Life_constructor_2) {
  Life<int> l(5, 5);

  ASSERT_EQ(l.generation, 0);
}

TEST(Life, Life_constructor_3) {
  Life<int> l(5, 5);

  ASSERT_EQ(l.population, 0);
}

//
// getIndex
//

TEST(Life, getIndex1) {
  Life<int> l(5, 5);
  Coordinate co = Coordinate(3, 3);

  int index = l.getIndex(co);

  ASSERT_EQ(32, index);
}

TEST(Life, getIndex2) {
  Life<int> l(50, 10);
  Coordinate co = Coordinate(20, 2);

  int index = l.getIndex(co);

  ASSERT_EQ(255, index);
}

TEST(Life, getIndex3) {
  Life<int> l(20, 8);
  Coordinate co = Coordinate(3, 5);

  int index = l.getIndex(co);

  ASSERT_EQ(46, index);
}

//
// addCell
//

TEST(Life, addCell_CC_1) {
  Life<ConwayCell> l(5, 5);
  Coordinate co = Coordinate(3, 3);

  l.addCell(ConwayCell(true), co);

  ostringstream testOutput;
  l.grid[l.getIndex(co)].printOut(testOutput);

  ostringstream trueOutput;
  trueOutput << "*";

  ASSERT_EQ(testOutput.str(), trueOutput.str());
}

TEST(Life, addCell_CC_2) {
  Life<ConwayCell> l(5, 5);
  Coordinate co = Coordinate(3, 3);

  l.addCell(ConwayCell(false), co);

  ostringstream testOutput;
  l.grid[l.getIndex(co)].printOut(testOutput);

  ostringstream trueOutput;
  trueOutput << ".";

  ASSERT_EQ(testOutput.str(), trueOutput.str());
}

TEST(Life, addCell_CC_3) {
  Life<ConwayCell> l(5, 5);
  Coordinate co = Coordinate(1, 1);

  l.addCell(ConwayCell(true), co);

  ostringstream testOutput;
  l.grid[l.getIndex(co)].printOut(testOutput);

  ostringstream trueOutput;
  trueOutput << "*";

  ASSERT_EQ(testOutput.str(), trueOutput.str());
}

TEST(Life, addCell_CC_4) {
  Life<ConwayCell> l(5, 5);
  Coordinate co = Coordinate(3, 3);

  l.addCell(ConwayCell(true), co);

  ASSERT_EQ(l.population, 1);
}

TEST(Life, addCell_CC_5) {
  Life<ConwayCell> l(5, 5);
  Coordinate co = Coordinate(8, 8);

  l.addCell(ConwayCell(true), co);

  ASSERT_EQ(l.population, 0);
}

//
// simulate
//

TEST(Life, simulate_CC_1) {
  Life<ConwayCell> l(5, 5);
  Coordinate co = Coordinate(3, 3);

  l.addCell(ConwayCell(true), co);

  l.simulate(1);

  ostringstream testOutput;
  l.grid[l.getIndex(co)].printOut(testOutput);

  ostringstream trueOutput;
  trueOutput << ".";

  ASSERT_EQ(testOutput.str(), trueOutput.str());
}

TEST(Life, simulate_CC_2) {
  Life<ConwayCell> l(5, 5);
  Coordinate co = Coordinate(2, 3);

  l.addCell(ConwayCell(true), Coordinate(3, 3));
  l.addCell(ConwayCell(true), Coordinate(3, 4));
  l.addCell(ConwayCell(true), Coordinate(3, 2));

  l.simulate(1);

  ostringstream testOutput;
  l.grid[l.getIndex(co)].printOut(testOutput);

  ostringstream trueOutput;
  trueOutput << "*";

  ASSERT_EQ(testOutput.str(), trueOutput.str());
}

TEST(Life, simulate_FF_1) {
  Life<FredkinCell> l(5, 5);
  Coordinate co = Coordinate(3, 3);

  l.addCell(FredkinCell(true), co);

  l.simulate(1);

  ostringstream testOutput;
  l.grid[l.getIndex(co)].printOut(testOutput);

  ostringstream trueOutput;
  trueOutput << "-";

  ASSERT_EQ(testOutput.str(), trueOutput.str());
}

TEST(Life, simulate_FF_2) {
  Life<FredkinCell> l(5, 5);
  Coordinate co = Coordinate(3, 3);

  l.addCell(FredkinCell(true), co);

  l.simulate(2);

  ostringstream testOutput;
  l.grid[l.getIndex(co)].printOut(testOutput);

  ostringstream trueOutput;
  trueOutput << "-";

  ASSERT_EQ(testOutput.str(), trueOutput.str());
}

TEST(Life, simulate_FF_3) {
  Life<FredkinCell> l(5, 5);
  Coordinate co = Coordinate(3, 3);

  l.addCell(FredkinCell(true), co);

  l.simulate(3);

  ostringstream testOutput;
  l.grid[l.getIndex(co)].printOut(testOutput);

  ostringstream trueOutput;
  trueOutput << "-";

  ASSERT_EQ(testOutput.str(), trueOutput.str());
}

TEST(Life, simulate_FF_4) {
  Life<FredkinCell> l(5, 5);
  Coordinate co = Coordinate(2, 3);

  l.addCell(FredkinCell(true), Coordinate(3, 3));
  l.addCell(FredkinCell(true), Coordinate(3, 4));
  l.addCell(FredkinCell(true), Coordinate(3, 2));

  l.simulate(1);

  ostringstream testOutput;
  l.grid[l.getIndex(co)].printOut(testOutput);

  ostringstream trueOutput;
  trueOutput << "0";

  ASSERT_EQ(testOutput.str(), trueOutput.str());
}

TEST(Life, simulate_FF_5) {
  Life<FredkinCell> l(5, 5);
  Coordinate co = Coordinate(2, 3);

  l.addCell(FredkinCell(true), Coordinate(3, 3));
  l.addCell(FredkinCell(true), Coordinate(3, 4));
  l.addCell(FredkinCell(true), Coordinate(3, 2));

  l.simulate(2);

  ostringstream testOutput;
  l.grid[l.getIndex(co)].printOut(testOutput);

  ostringstream trueOutput;
  trueOutput << "-";

  ASSERT_EQ(testOutput.str(), trueOutput.str());
}

TEST(Life, simulate_FF_6) {
  Life<FredkinCell> l(5, 5);
  Coordinate co = Coordinate(2, 3);

  l.addCell(FredkinCell(true), Coordinate(3, 3));
  l.addCell(FredkinCell(true), Coordinate(3, 4));
  l.addCell(FredkinCell(true), Coordinate(3, 2));

  l.simulate(3);

  ostringstream testOutput;
  l.grid[l.getIndex(co)].printOut(testOutput);

  ostringstream trueOutput;
  trueOutput << "0";

  ASSERT_EQ(testOutput.str(), trueOutput.str());
}

//
// Life <<
//

TEST(Life, print_1) {
  Life<ConwayCell> l(5, 5);
  Coordinate co = Coordinate(3, 3);

  l.addCell(ConwayCell(true), co);

  ostringstream testOutput;
  l.grid[l.getIndex(co)].printOut(testOutput);

  ostringstream trueOutput;
  trueOutput << "*";

  ASSERT_EQ(testOutput.str(), trueOutput.str());
}

TEST(Life, print_2) {
  Life<ConwayCell> l(5, 5);
  Coordinate co = Coordinate(3, 3);

  l.addCell(ConwayCell(true), co);

  ostringstream testOutput;
  l.grid[l.getIndex(co)].printOut(testOutput);

  l.simulate(1);

  ostringstream trueOutput;
  trueOutput << "*";

  ASSERT_EQ(testOutput.str(), trueOutput.str());
}

TEST(Life, print_3) {
  Life<FredkinCell> l(5, 5);
  Coordinate co = Coordinate(2, 3);

  l.addCell(FredkinCell(true), Coordinate(3, 3));
  l.addCell(FredkinCell(true), Coordinate(3, 4));
  l.addCell(FredkinCell(true), Coordinate(3, 2));

  l.simulate(3);

  ostringstream testOutput;
  l.grid[l.getIndex(co)].printOut(testOutput);

  ostringstream trueOutput;
  trueOutput << "0";

  ASSERT_EQ(testOutput.str(), trueOutput.str());
}

//
// AbstractCell
//

TEST(AbstractCell, AbstractCell_1) {
  AbstractCell ac(true);

  ASSERT_EQ(ac.alive, true);
}

TEST(AbstractCell, AbstractCell_2) {
  AbstractCell ac(false);

  ASSERT_EQ(ac.alive, false);
}

TEST(AbstractCell, AbstractCell_3) {
  AbstractCell ac(true);

  ASSERT_EQ(ac.age, 0);
}

TEST(AbstractCell, AbstractCell_4) {
  AbstractCell ac(false);

  ASSERT_EQ(ac.age, 0);
}

TEST(AbstractCell, AbstractCell_5) {
  AbstractCell ac(true);

  ASSERT_EQ(ac.isAlive(), true);
}

TEST(AbstractCell, AbstractCell_6) {
  AbstractCell ac(false);

  ASSERT_EQ(ac.isAlive(), false);
}

TEST(AbstractCell, clone1) {
  AbstractCell ac(true);

  ASSERT_EQ(ac.clone(), nullptr);
}

TEST(AbstractCell, clone2) {
  AbstractCell ac(false);

  ASSERT_EQ(ac.clone(), nullptr);
}

TEST(AbstractCell, taketurn_1) {
  AbstractCell ac(true);

  NeighborCount n(0, 0);

  ASSERT_EQ(ac.takeTurn(n), 0);
}

TEST(AbstractCell, taketurn_2) {
  AbstractCell ac(false);

  NeighborCount n(0, 0);

  ASSERT_EQ(ac.takeTurn(n), 0);
}

TEST(AbstractCell, taketurn_3) {
  AbstractCell ac(true);

  ac.age++;

  NeighborCount n(5, 5);

  ASSERT_EQ(ac.takeTurn(n), 1);
}

TEST(AbstractCell, taketurn_4) {
  AbstractCell ac(false);

  ac.age++;
  NeighborCount n(4, 6);

  ASSERT_EQ(ac.takeTurn(n), 1);
}

TEST(AbstractCell, print_1) {
  AbstractCell ac(true);

  ostringstream testOutput;
  ac.printOut(testOutput);

  ostringstream trueOutput;
  trueOutput << "";

  ASSERT_EQ(testOutput.str(), trueOutput.str());
}

TEST(AbstractCell, print_2) {
  AbstractCell ac(false);

  ostringstream testOutput;
  ac.printOut(testOutput);

  ostringstream trueOutput;
  trueOutput << "";

  ASSERT_EQ(testOutput.str(), trueOutput.str());
}

//
// Cell
//

TEST(Cell, Cell_2) {
  FredkinCell *p = new FredkinCell(true);
  Cell c(p);

  ASSERT_NE(c.cell, nullptr);

  delete p;
}

TEST(Cell, Cell_8) {
  FredkinCell *p = new FredkinCell(false);
  Cell c(p);

  ASSERT_NE(c.cell, nullptr);
  delete p;
}

TEST(Cell, Cell_3) {
  ConwayCell *p = new ConwayCell(true);
  Cell c(p);

  ASSERT_NE(c.cell, nullptr);
  delete p;
}

TEST(Cell, Cell_4) {
  ConwayCell *p = new ConwayCell(false);
  Cell c(p);

  ASSERT_NE(c.cell, nullptr);
  delete p;
}

TEST(Cell, Cell_6) {
  FredkinCell *p = new FredkinCell(true);
  Cell c(p);

  ASSERT_EQ(c.isAlive(), true);
  delete p;
}

TEST(Cell, Cell_7) {
  FredkinCell *p = new FredkinCell(false);
  Cell c(p);

  ASSERT_EQ(c.isAlive(), false);
  delete p;
}

TEST(Cell, taketurn_1) {
  FredkinCell *p = new FredkinCell(false);
  Cell c(p);

  NeighborCount n(0, 0);

  ASSERT_EQ(c.takeTurn(n), -1);
  delete p;
}

TEST(Cell, taketurn_2) {
  FredkinCell *p = new FredkinCell(false);
  Cell c(p);

  NeighborCount n(0, 0);

  ASSERT_EQ(c.takeTurn(n), -1);
  delete p;
}

TEST(Cell, taketurn_3) {
  ConwayCell *p = new ConwayCell(true);
  Cell c(p);

  NeighborCount n(0, 0);

  ASSERT_EQ(c.takeTurn(n), -1);
  delete p;
}

TEST(Cell, taketurn_4) {
  ConwayCell *p = new ConwayCell(true);
  Cell c(p);

  NeighborCount n(0, 0);

  ASSERT_EQ(c.takeTurn(n), -1);
  delete p;
}

TEST(Cell, print_1) {
  FredkinCell *p = new FredkinCell(true);
  Cell c(p);

  ostringstream testOutput;
  testOutput << c;

  ostringstream trueOutput;
  trueOutput << "0";

  ASSERT_EQ(testOutput.str(), trueOutput.str());
  delete p;
}

TEST(Cell, print_2) {
  FredkinCell *p = new FredkinCell(false);
  Cell c(p);

  ostringstream testOutput;
  testOutput << c;

  ostringstream trueOutput;
  trueOutput << "-";

  ASSERT_EQ(testOutput.str(), trueOutput.str());
  delete p;
}

TEST(Cell, print_3) {
  ConwayCell *p = new ConwayCell(true);
  Cell c(p);

  ostringstream testOutput;
  testOutput << c;

  ostringstream trueOutput;
  trueOutput << "*";

  ASSERT_EQ(testOutput.str(), trueOutput.str());
  delete p;
}

TEST(Cell, print_4) {
  ConwayCell *p = new ConwayCell(false);
  Cell c(p);

  ostringstream testOutput;
  testOutput << c;

  ostringstream trueOutput;
  trueOutput << ".";

  ASSERT_EQ(testOutput.str(), trueOutput.str());
  delete p;
}

//
// ConwayCell
//

TEST(ConwayCell, ConwayCell_1) {
  ConwayCell cc(true);

  ASSERT_EQ(cc.isAlive(), true);
}

TEST(ConwayCell, ConwayCell_2) {
  ConwayCell cc(false);

  ASSERT_EQ(cc.isAlive(), false);
}

TEST(ConwayCell, ConwayCell_3) {
  ConwayCell cc(true);

  ASSERT_EQ(cc.age, 0);
}

// TEST(ConwayCell, ConwayCell_4) {
//   ConwayCell c(false);

//   ASSERT_EQ(cc.age, 0);
// }

TEST(ConwayCell, ConwayCell_5) {
  ConwayCell cc(true);

  ASSERT_EQ(cc.isAlive(), true);
}

TEST(ConwayCell, ConwayCell_6) {
  ConwayCell cc(false);

  ASSERT_EQ(cc.isAlive(), false);
}

// TEST(ConwayCell, clone1) {
//   ConwayCell ac(true);

//   ASSERT_EQ(cc.clone(), nullptr);
// }

TEST(ConwayCell, clone2) {
  ConwayCell cc(false);

  ASSERT_NE(cc.clone(), nullptr);
}

TEST(ConwayCell, taketurn_1) {
  ConwayCell cc(true);

  NeighborCount n(0, 0);

  ASSERT_EQ(cc.takeTurn(n), -1);
}

TEST(ConwayCell, taketurn_2) {
  ConwayCell cc(false);

  NeighborCount n(0, 0);

  ASSERT_EQ(cc.takeTurn(n), -1);
}

TEST(ConwayCell, taketurn_3) {
  ConwayCell cc(true);

  NeighborCount n(5, 5);

  ASSERT_EQ(cc.takeTurn(n), -1);
}

TEST(ConwayCell, taketurn_4) {
  ConwayCell cc(false);

  NeighborCount n(4, 6);

  ASSERT_EQ(cc.takeTurn(n), -1);
}

TEST(ConwayCell, print_1) {
  ConwayCell cc(true);

  ostringstream testOutput;
  cc.printOut(testOutput);

  ostringstream trueOutput;
  trueOutput << "*";

  ASSERT_EQ(testOutput.str(), trueOutput.str());
}

TEST(ConwayCell, print_2) {
  ConwayCell cc(false);

  ostringstream testOutput;
  cc.printOut(testOutput);

  ostringstream trueOutput;
  trueOutput << ".";

  ASSERT_EQ(testOutput.str(), trueOutput.str());
}

//
// FredkinCell
//

TEST(FredkinCell, FredkinCell_1) {
  FredkinCell fc(true);

  ASSERT_EQ(fc.isAlive(), true);
}

TEST(FredkinCell, FredkinCell_2) {
  FredkinCell fc(false);

  ASSERT_EQ(fc.isAlive(), false);
}

TEST(FredkinCell, FredkinCell_3) {
  FredkinCell fc(true);

  ASSERT_EQ(fc.age, 0);
}

TEST(FredkinCell, FredkinCell_5) {
  FredkinCell fc(true);

  ASSERT_EQ(fc.isAlive(), true);
}

TEST(FredkinCell, FredkinCell_6) {
  FredkinCell fc(false);

  ASSERT_EQ(fc.isAlive(), false);
}

TEST(FredkinCell, clone2) {
  FredkinCell fc(false);

  ASSERT_NE(fc.clone(), nullptr);
}

TEST(FredkinCell, taketurn_1) {
  FredkinCell fc(true);

  NeighborCount n(0, 0);

  ASSERT_EQ(fc.takeTurn(n), -1);
}

TEST(FredkinCell, taketurn_2) {
  FredkinCell fc(false);

  NeighborCount n(0, 0);

  ASSERT_EQ(fc.takeTurn(n), -1);
}

TEST(FredkinCell, taketurn_3) {
  FredkinCell fc(true);

  NeighborCount n(5, 5);

  ASSERT_EQ(fc.takeTurn(n), 1);
}

TEST(FredkinCell, taketurn_4) {
  FredkinCell fc(false);

  NeighborCount n(4, 6);

  ASSERT_EQ(fc.takeTurn(n), -1);
}

TEST(FredkinCell, print_1) {
  FredkinCell fc(true);

  ostringstream testOutput;
  fc.printOut(testOutput);

  ostringstream trueOutput;
  trueOutput << "0";

  ASSERT_EQ(testOutput.str(), trueOutput.str());
}

TEST(FredkinCell, print_2) {
  FredkinCell fc(false);

  ostringstream testOutput;
  fc.printOut(testOutput);

  ostringstream trueOutput;
  trueOutput << "-";

  ASSERT_EQ(testOutput.str(), trueOutput.str());
}

//
// Coordinate
//

TEST(Coordinate, Coordinate_1) {
  Coordinate co(0, 0);

  ASSERT_EQ(co.x, 0);
}

TEST(Coordinate, Coordinate_2) {
  Coordinate co(0, 0);

  ASSERT_EQ(co.y, 0);
}

TEST(Coordinate, Coordinate_3) {
  Coordinate co(0, 0);

  co.x = 6;
  co.y = 10;

  ASSERT_EQ(co.y, 10);
  ASSERT_EQ(co.x, 6);
}

TEST(Coordinate, Coordinate_4) {
  Coordinate co(5, 5);

  ASSERT_EQ(co.y, 5);
  ASSERT_EQ(co.x, 5);
}

TEST(Coordinate, Coordinate_5) {
  Coordinate co(5, 5);

  co.x = 6;
  co.y = 10;

  ASSERT_EQ(co.y, 10);
  ASSERT_EQ(co.x, 6);
}

TEST(Coordinate, Coordinate_6) {
  Coordinate co(5, 5);

  co.x++;
  co.y++;

  ASSERT_EQ(co.y, 6);
  ASSERT_EQ(co.x, 6);
}

TEST(Coordinate, Coordinate_7) {
  Coordinate co(0, 0);

  co.x = 6;
  co.y = 10;

  Coordinate c2(3, 3);

  co = c2;

  ASSERT_EQ(co.y, 3);
  ASSERT_EQ(co.x, 3);
}

TEST(Coordinate, Coordinate_8) {
  Coordinate co(5, 5);

  Coordinate c2(3, 3);

  co = c2;

  co.x++;
  co.y++;

  ASSERT_EQ(co.y, 4);
  ASSERT_EQ(co.x, 4);
}

TEST(Coordinate, Coordinate_9) {
  Coordinate co(5, 5);

  Coordinate c2(3, 3);

  co = c2;

  co = Coordinate(10, 6);

  co.x = 6;
  co.y = 10;

  ASSERT_EQ(co.y, 10);
  ASSERT_EQ(co.x, 6);
}

TEST(Coordinate, Coordinate_10) {
  Coordinate co(5, 5);

  Coordinate c2(3, 3);

  co.x++;
  co.y++;

  ASSERT_EQ(co.y, 6);
  ASSERT_EQ(co.x, 6);
}

//
// NeighborCount
//

TEST(NeighborCount, NeighborCount_1) {
  NeighborCount n(0, 0);

  ASSERT_EQ(n.diagonal, 0);
}

TEST(NeighborCount, NeighborCount_2) {
  NeighborCount n(0, 0);

  ASSERT_EQ(n.adjacent, 0);
}

TEST(NeighborCount, NeighborCount_3) {
  NeighborCount n(0, 0);

  n.diagonal = 6;
  n.adjacent = 10;

  ASSERT_EQ(n.adjacent, 10);
  ASSERT_EQ(n.diagonal, 6);
}

TEST(NeighborCount, NeighborCount_4) {
  NeighborCount n(5, 5);

  ASSERT_EQ(n.adjacent, 5);
  ASSERT_EQ(n.diagonal, 5);
}

TEST(NeighborCount, NeighborCount_5) {
  NeighborCount n(5, 5);

  n.diagonal = 6;
  n.adjacent = 10;

  ASSERT_EQ(n.adjacent, 10);
  ASSERT_EQ(n.diagonal, 6);
}

TEST(NeighborCount, NeighborCount_6) {
  NeighborCount n(5, 5);

  n.diagonal++;
  n.adjacent++;

  ASSERT_EQ(n.adjacent, 6);
  ASSERT_EQ(n.diagonal, 6);
}