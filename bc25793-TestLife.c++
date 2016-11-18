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
#include <ostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// ----
// Cell Tests
// ----

TEST(LifeFixture, Cell_Default_Constructor1) {
  Cell a;
  ASSERT_EQ(a._p, nullptr);
}

TEST(LifeFixture, Cell_Default_Constructor2) {
  Cell a;
  Cell b;
  ASSERT_EQ(a._p, nullptr);
}

TEST(LifeFixture, Cell_Default_Constructor3) {
  Cell a;
  Cell b;
  ASSERT_EQ(b._p, nullptr);
}

TEST(LifeFixture, Cell_Constructor1) {
  Cell a = new ConwayCell(false);
  ASSERT_NE(a._p, nullptr);
}

TEST(LifeFixture, Cell_Constructor2) {
  Cell a = new ConwayCell(false);
  Cell b = new ConwayCell(true);
  ASSERT_NE(a._p, nullptr);

  if (a._p != nullptr) {
    ASSERT_EQ((a._p)->_alive, false);
  } else {
    ASSERT_FALSE(true);
  }
}

TEST(LifeFixture, Cell_Constructor3) {
  Cell a = new ConwayCell(false);
  Cell b = new ConwayCell(true);
  if (b._p != nullptr) {
    ASSERT_NE((b._p)->_alive, false);
  } else {
    ASSERT_FALSE(true);
  }
}

TEST(LifeFixture, Cell_Copy_Constructor1) {
  Cell a = new ConwayCell(false);
  Cell b = a;

  if (a._p != nullptr && b._p != nullptr) {
    ASSERT_FALSE(a._p->_alive);
    ASSERT_FALSE(b._p->_alive);
  } else {
    ASSERT_FALSE(true);
  }
}

TEST(LifeFixture, Cell_Copy_Constructor2) {
  Cell a = new ConwayCell(false);
  Cell b = new ConwayCell(true);
  b = a;

  if (a._p != nullptr && b._p != nullptr) {
    ASSERT_FALSE(a._p->_alive);
    ASSERT_FALSE(b._p->_alive);
  } else {
    ASSERT_FALSE(true);
  }
}

TEST(LifeFixture, Cell_Copy_Constructor3) {
  Cell a = new ConwayCell(false);
  Cell b = a;
  a = b;

  ConwayCell *c = dynamic_cast<ConwayCell *>(a._p);
  ConwayCell *d = dynamic_cast<ConwayCell *>(b._p);

  if (c != nullptr && d != nullptr) {
    bool cb = c->_alive;
    ASSERT_FALSE(cb);
    bool db = d->_alive;
    ASSERT_FALSE(db);
  } else {
    ASSERT_FALSE(true);
  }
}

TEST(LifeFixture, Cell_Copy_Assignment_Constructor1) {
  Cell a = new ConwayCell(false);
  Cell b = new ConwayCell(true);

  if (a._p != nullptr && b._p != nullptr) {
    ASSERT_TRUE(b._p->_alive);
    b = a;
    ASSERT_NE(b._p, nullptr);
  } else {
    ASSERT_FALSE(true);
  }
}

TEST(LifeFixture, Cell_Copy_Assignment_Constructor2) {
  Cell a = new ConwayCell(false);
  Cell b = new ConwayCell(true);

  if (a._p != nullptr && b._p != nullptr) {

    ASSERT_TRUE(b._p->_alive);
    b = a;
    a = b;
    Cell c = a;

    if (c._p != nullptr) {
      ASSERT_NE(b._p, nullptr);
      ASSERT_NE(c._p, nullptr);
      ASSERT_FALSE(b._p->_alive);
    }

  } else {
    ASSERT_FALSE(true);
  }
}

TEST(LifeFixture, Cell_Copy_Assignment_Constructor3) {
  Cell a = new ConwayCell(false);
  Cell b = new ConwayCell(true);

  if (b._p != nullptr)
    ASSERT_TRUE(b._p->_alive);

  b = a;
  Cell c = new ConwayCell(true);
  c = b;
  ASSERT_NE(b._p, nullptr);
  if (c._p != nullptr) {
    ASSERT_FALSE(c._p->_alive);
  } else {
    ASSERT_FALSE(true);
  }
}

TEST(LifeFixture, Cell_evolve1) {
  Cell a = new ConwayCell(true);
  vector<Cell *> neighbors(8);
  Cell b = (new ConwayCell(true));
  neighbors[0] = &b;
  Cell c = (new ConwayCell(false));
  neighbors[1] = &c;
  Cell d = (new ConwayCell(true));
  neighbors[2] = &d;
  a.evolve(neighbors, false);
  ASSERT_EQ(a._p->_alive, true);
}

TEST(LifeFixture, Cell_evolve2) {
  Cell a = new ConwayCell(false);
  vector<Cell *> neighbors(8);
  Cell b = (new ConwayCell(true));
  neighbors[0] = &b;
  Cell c = (new ConwayCell(false));
  neighbors[3] = &c;
  Cell d = (new ConwayCell(true));
  neighbors[4] = &d;
  Cell e = (new ConwayCell(true));
  neighbors[6] = &e;
  a.evolve(neighbors, false);
  ASSERT_EQ(a._p->_alive, true);
}

TEST(LifeFixture, Cell_evolve3) {
  Cell a = new FredkinCell(true);
  vector<Cell *> neighbors(8);
  Cell b = (new FredkinCell(true));
  neighbors[0] = &b;
  a.evolve(neighbors, false);
  ASSERT_EQ(a._p->_alive, false);
  ASSERT_EQ((dynamic_cast<FredkinCell *>(a._p))->_age, 0);
}

TEST(LifeFixture, Cell_numAlive1) {
  vector<Cell *> neighbors(8);
  Cell a = new FredkinCell(true);
  neighbors[0] = &a;
  Cell b = (new FredkinCell(true));
  neighbors[1] = &b;
  Cell c = (new FredkinCell(false));
  neighbors[2] = &c;
  Cell d = (new FredkinCell(true));
  neighbors[3] = &d;
  Cell e = (new FredkinCell(true));
  neighbors[4] = &e;
  ASSERT_EQ(Cell::numAlive(neighbors), 4);
}

TEST(LifeFixture, Cell_numAlive2) {
  vector<Cell *> neighbors(8);
  Cell a = new ConwayCell(true);
  neighbors[0] = &a;
  Cell b = (new ConwayCell(true));
  neighbors[1] = &b;
  ASSERT_EQ(Cell::numAlive(neighbors), 2);
}

TEST(LifeFixture, Cell_numAlive3) {
  vector<Cell *> neighbors(8);
  ASSERT_EQ(Cell::numAlive(neighbors), 0);
}

TEST(LifeFixture, Cell_print1) {
  Cell a = new ConwayCell(false);
  ostringstream str;
  str << a;
  ASSERT_EQ(str.str(), ".");
}

TEST(LifeFixture, Cell_print2) {
  Cell a = new FredkinCell(true);
  ostringstream str;
  str << a;
  ASSERT_EQ(str.str(), "0");
}

TEST(LifeFixture, Cell_print3) {
  Cell a = new ConwayCell(true);
  ostringstream str;
  str << a;
  ASSERT_EQ(str.str(), "*");
}

// ----
//  ConwayCell Tests
// ----

TEST(LifeFixture, ConwayCell_Default_Constructor1) {
  ConwayCell a;
  ASSERT_EQ(a._alive, false);
}

TEST(LifeFixture, ConwayCell_Default_Constructor2) {
  ConwayCell a(true);
  ConwayCell b;
  ASSERT_EQ(a._alive, true);
  ASSERT_EQ(b._alive, false);
}

TEST(LifeFixture, ConwayCell_Default_Constructor3) {
  ConwayCell *b = new ConwayCell();
  Cell a(b);
  ASSERT_EQ(b->_alive, false);
  ASSERT_EQ(a._p, b);
}

TEST(LifeFixture, ConwayCell_Constructor1) {
  Cell b = new ConwayCell(true);
  if (b._p != nullptr) {
    ASSERT_EQ(b._p->_alive, true);
  } else {
    ASSERT_FALSE(true);
  }
}

TEST(LifeFixture, ConwayCell_Constructor2) {
  Cell a = new ConwayCell(false);
  Cell b = new ConwayCell(true);
  if (a._p != nullptr && b._p != nullptr) {
    ASSERT_EQ(a._p->_alive, false);
    ASSERT_EQ(b._p->_alive, true);
  }
}

TEST(LifeFixture, ConwayCell_Constructor3) {
  Cell b = new ConwayCell(true);
  Cell a(b);
  ASSERT_NE(a._p, b._p);
}

TEST(LifeFixture, ConwayCell_Copy_Constructor1) {
  ConwayCell a(false);
  ConwayCell b(a);
  ASSERT_FALSE(a._alive);
  ASSERT_FALSE(b._alive);
}

TEST(LifeFixture, ConwayCell_Copy_Constructor2) {
  ConwayCell a(false);
  ConwayCell b(true);
  b = a;
  ASSERT_FALSE(a._alive);
  ASSERT_FALSE(b._alive);
}

TEST(LifeFixture, ConwayCell_Copy_Constructor3) {
  ConwayCell a(false);
  ConwayCell b = a;
  a = b;
  ASSERT_FALSE(a._alive);
  ASSERT_FALSE(b._alive);
}

TEST(LifeFixture, ConwayCell_evolve1) {
  Cell a = new ConwayCell(true);
  vector<Cell *> neighbors(8);
  Cell b = (new ConwayCell(true));
  neighbors[0] = &b;
  Cell c = (new ConwayCell(false));
  neighbors[1] = &c;
  Cell d = (new ConwayCell(true));
  neighbors[2] = &d;
  a.evolve(neighbors, false);
  ASSERT_EQ(a._p->_alive, true);
}

TEST(LifeFixture, ConwayCell_evolve2) {
  Cell a = new ConwayCell(false);
  vector<Cell *> neighbors(8);
  Cell b = (new ConwayCell(true));
  neighbors[0] = &b;
  Cell c = (new ConwayCell(false));
  neighbors[3] = &c;
  Cell d = (new ConwayCell(true));
  neighbors[4] = &d;
  Cell e = (new ConwayCell(true));
  neighbors[6] = &e;
  a.evolve(neighbors, false);
  ASSERT_EQ(a._p->_alive, true);
}

TEST(LifeFixture, ConwayCell_evolve3) {
  Cell a = new ConwayCell(false);
  vector<Cell *> neighbors(8);
  a.evolve(neighbors, false);
  ASSERT_EQ(a._p->_alive, false);
}

TEST(LifeFixture, ConwayCell_clone1) {
  ConwayCell a(false);
  ConwayCell b(a);
  ASSERT_EQ(a._alive, false);
  ASSERT_EQ(b._alive, false);
}

TEST(LifeFixture, ConwayCell_clone2) {
  ConwayCell a(true);
  ConwayCell b(a);
  ASSERT_EQ(a._alive, true);
  ASSERT_EQ(b._alive, true);
}

TEST(LifeFixture, ConwayCell_clone3) {
  Cell a = new ConwayCell(false);

  if (a._p != nullptr) {
    Cell b = a._p->clone();

    if (b._p != nullptr)
      ASSERT_EQ(b._p->_alive, false);

  } else {
    ASSERT_FALSE(true);
  }
}

TEST(LifeFixture, ConwayCell_print1) {
  ConwayCell a(true);
  ASSERT_EQ(a.print(), '*');
}

TEST(LifeFixture, ConwayCell_print2) {
  ConwayCell a(false);
  ASSERT_EQ(a.print(), '.');
}

TEST(LifeFixture, ConwayCell_print3) {
  Cell a = new ConwayCell(true);
  ostringstream o;
  o << a;
  ASSERT_EQ(o.str(), "*");
}

// ----
//  FriedKinCell Tests
// ----

TEST(LifeFixture, FredkinCell_Default_Constructor1) {
  FredkinCell a;
  ASSERT_EQ(a._alive, false);
  ASSERT_EQ(a._age, 0);
}

TEST(LifeFixture, FredkinCell_Default_Constructor2) {
  FredkinCell a;
  FredkinCell b(true);
  ASSERT_EQ(a._alive, false);
  ASSERT_EQ(b._alive, true);
}

TEST(LifeFixture, FredkinCell_Default_Constructor3) {
  FredkinCell *b = new FredkinCell();
  Cell a(b);
  ASSERT_EQ(a._p, b);
}

TEST(LifeFixture, FredkinCell_Constructor1) {
  Cell a = new FredkinCell(false);
  Cell b = new FredkinCell(true);

  if (a._p != nullptr && b._p != nullptr) {
    ASSERT_NE((b._p)->_alive, false);
    ASSERT_EQ(dynamic_cast<FredkinCell *>(b._p)->_age, 0);
    ASSERT_EQ((b._p)->_alive, true);
    ASSERT_EQ(dynamic_cast<FredkinCell *>(b._p)->_age, 0);
  } else {
    ASSERT_FALSE(true);
  }
}

TEST(LifeFixture, FredkinCell_Constructor2) {
  Cell a = new FredkinCell(false);
  ASSERT_NE(a._p, nullptr);

  if (a._p != nullptr) {
    ASSERT_EQ((a._p)->_alive, false);
  } else {
    ASSERT_FALSE(true);
  }
}

TEST(LifeFixture, FredkinCell_Copy_Constructor1) {
  Cell a = new FredkinCell(true);
  Cell b = a;

  if (a._p != nullptr && b._p != nullptr) {
    ASSERT_TRUE(a._p->_alive);
    ASSERT_TRUE(b._p->_alive);
    ASSERT_EQ(dynamic_cast<FredkinCell *>(b._p)->_age, 0);
  } else {
    ASSERT_FALSE(true);
  }
}

TEST(LifeFixture, FredkinCell_Copy_Constructor2) {
  Cell a = new FredkinCell(false);
  Cell b = new FredkinCell(true);
  b = a;

  if (a._p != nullptr && b._p != nullptr) {
    ASSERT_FALSE(a._p->_alive);
    ASSERT_FALSE(b._p->_alive);
  } else {
    ASSERT_FALSE(true);
  }
}

TEST(LifeFixture, FredkinCell_Copy_Constructor3) {
  Cell a = new FredkinCell(false);
  Cell b = a;
  a = b;

  if (a._p != nullptr && b._p != nullptr) {
    ASSERT_FALSE(a._p->_alive);
    ASSERT_FALSE(b._p->_alive);
    ASSERT_EQ(dynamic_cast<FredkinCell *>(b._p)->_age, 0);
  } else {
    ASSERT_FALSE(true);
  }
}

TEST(LifeFixture, FredkinCell_evolve1) {
  Cell a = new FredkinCell(false);
  vector<Cell *> neighbors(8);
  Cell b = (new FredkinCell(true));
  neighbors[0] = &b;
  Cell c = (new FredkinCell(true));
  neighbors[1] = &c;
  Cell d = (new FredkinCell(true));
  neighbors[2] = &d;
  a.evolve(neighbors, false);
  ASSERT_EQ(a._p->_alive, true);
}

TEST(LifeFixture, FredkinCell_evolve2) {
  Cell a = new FredkinCell(true);
  vector<Cell *> neighbors(8);
  Cell b = (new FredkinCell(true));
  neighbors[0] = &b;
  Cell c = (new FredkinCell(false));
  neighbors[1] = &c;
  Cell d = (new FredkinCell(true));
  neighbors[2] = &d;
  Cell e = (new FredkinCell(true));
  neighbors[3] = &e;
  a.evolve(neighbors, false);
  ASSERT_EQ(a._p->_alive, true);
  ASSERT_EQ(dynamic_cast<FredkinCell *>(a._p)->_age, 1);
}

TEST(LifeFixture, FredkinCell_evolve3) {
  Cell a = new FredkinCell(true);
  vector<Cell *> neighbors(8);
  a.evolve(neighbors, false);
  ASSERT_EQ(a._p->_alive, false);
}

TEST(LifeFixture, FredkinCell_clone1) {
  Cell a = new FredkinCell(false);

  if (a._p != nullptr) {
    Cell b = a._p->clone();
    ASSERT_EQ(a._p->_alive, false);
    ASSERT_EQ(dynamic_cast<FredkinCell *>(a._p)->_age, 0);

    if (b._p != nullptr) {
      ASSERT_EQ(b._p->_alive, false);
      ASSERT_EQ(dynamic_cast<FredkinCell *>(b._p)->_age, 0);
    }

  } else {
    ASSERT_FALSE(true);
  }
}

TEST(LifeFixture, FredkinCell_clone2) {
  Cell a = new FredkinCell(false);

  if (a._p != nullptr) {
    Cell b = a._p->clone();

    if (b._p != nullptr)
      ASSERT_EQ(b._p->_alive, false);

  } else {
    ASSERT_FALSE(true);
  }
}

TEST(LifeFixture, FredkinCell_clone3) {
  Cell a = new FredkinCell(false);

  if (a._p != nullptr) {
    Cell b = a._p->clone();

    if (b._p != nullptr)
      ASSERT_EQ(b._p->_alive, false);

  } else {
    ASSERT_FALSE(true);
  }
}

TEST(LifeFixture, FredkinCell_print1) {
  FredkinCell a(true);
  ASSERT_EQ(a.print(), '0');
}

TEST(LifeFixture, FredkinCell_print2) {
  FredkinCell a(false);
  ASSERT_EQ(a.print(), '-');
}

TEST(LifeFixture, FredkinCell_print3) {
  Cell a = new FredkinCell(true);
  ostringstream o;
  o << a;
  ASSERT_EQ(o.str(), "0");
}

// ----
//  AbstractCell Tests
// ----

TEST(LifeFixture, AbstractCell_numAlive1) {
  vector<Cell *> neighbors(8);
  Cell a = new FredkinCell(true);
  neighbors[0] = &a;
  Cell b = (new FredkinCell(true));
  neighbors[1] = &b;
  Cell c = (new FredkinCell(false));
  neighbors[2] = &c;
  Cell d = (new FredkinCell(true));
  neighbors[3] = &d;
  Cell e = (new FredkinCell(true));
  neighbors[4] = &e;
  Cell f = (new FredkinCell(true));
  neighbors[5] = &f;
  ASSERT_EQ(Cell::numAlive(neighbors), 5);
}

TEST(LifeFixture, AbstractCell_numAlive2) {
  vector<Cell *> neighbors(8);
  Cell a = new ConwayCell(true);
  neighbors[0] = &a;
  Cell b = (new ConwayCell(true));
  neighbors[1] = &b;
  ASSERT_EQ(Cell::numAlive(neighbors), 2);
}

TEST(LifeFixture, AbstractCell_numAlive3) {
  vector<Cell *> neighbors(8);
  Cell a = new FredkinCell(false);
  neighbors[0] = &a;
  ASSERT_EQ(Cell::numAlive(neighbors), 0);
}

// ----
//  Life Tests
// ----

TEST(LifeFixture, Life_at_small) {
  istringstream i("0 0");
  Life<ConwayCell> x(i);
  ASSERT_EQ(x._at(0, 0), 0);

  istringstream j("1 1\n.");
  Life<ConwayCell> y(j);
  ASSERT_EQ(y._at(0, 0), 0);
  ASSERT_EQ(y._at(1, 0), 1);

  istringstream k("2 2\n..\n..");
  Life<ConwayCell> z(k);
  ASSERT_EQ(z._at(0, 0), 0);
  ASSERT_EQ(z._at(1, 1), 3);
}

TEST(LifeFixture, Life_at_large) {
  istringstream i("10 2\n..\n..\n..\n..\n..\n..\n..\n..\n..\n..");
  Life<ConwayCell> x(i);
  ASSERT_EQ(x._at(4, 0), 8);

  istringstream j("2 10\n..........\n..........");
  Life<ConwayCell> y(j);
  ASSERT_EQ(y._at(1, 8), 18);
}

TEST(LifeFixture, Life_at_mixed) {
  istringstream i("3 3\n.*.\n-0-\n*0.");
  Life<Cell> x(i);
  ASSERT_EQ(x._at(0, 0), 0);
  ASSERT_EQ(x._at(1, 1), 4);
  ASSERT_EQ(x._at(2, 2), 8);
}

// should many tests on this
TEST(LifeFixture, Life_Constructor_blank) {
  istringstream i("0 0");
  Life<ConwayCell> x(i);
  ASSERT_EQ(x._turn, 0);
  ASSERT_EQ(x._rows, 0);
  ASSERT_EQ(x._cols, 0);
  ASSERT_EQ(x._population, 0);
  ASSERT_EQ(x._board.size(), 0);
}

/** Test Life Constructor with ConwayCell template */
TEST(LifeFixture, Life_Constructor_conway) {
  istringstream i("2 2\n.*\n*.");
  Life<ConwayCell> x(i);
  ASSERT_EQ(x._rows, 2);
  ASSERT_EQ(x._cols, 2);
  ASSERT_EQ(x._population, 2);
  ASSERT_EQ(x._board.size(), 4);

  Cell &c1 = x._board[x._at(0, 0)];
  bool c1a = c1._p->_alive;
  ASSERT_FALSE(c1a);

  Cell &c2 = x._board[x._at(0, 1)];
  bool c2a = c2._p->_alive;
  ASSERT_TRUE(c2a);

  Cell &c3 = x._board[x._at(1, 0)];
  bool c3a = c3._p->_alive;
  ASSERT_TRUE(c3a);

  Cell &c4 = x._board[x._at(1, 1)];
  bool c4a = c4._p->_alive;
  ASSERT_FALSE(c4a);
}

/** Test Life Constructor with FredkinCell template */
TEST(LifeFixture, Life_Constructor_fredkin) {
  istringstream i("2 2\n-0\n0-");
  Life<FredkinCell> x(i);
  ASSERT_EQ(x._rows, 2);
  ASSERT_EQ(x._cols, 2);
  ASSERT_EQ(x._population, 2);
  ASSERT_EQ(x._board.size(), 4);

  Cell &c1 = x._board[x._at(0, 0)];
  bool c1a = c1._p->_alive;
  ASSERT_FALSE(c1a);

  Cell &c2 = x._board[x._at(0, 1)];
  bool c2a = c2._p->_alive;
  ASSERT_TRUE(c2a);

  Cell &c3 = x._board[x._at(1, 0)];
  bool c3a = c3._p->_alive;
  ASSERT_TRUE(c3a);

  Cell &c4 = x._board[x._at(1, 1)];
  bool c4a = c4._p->_alive;
  ASSERT_FALSE(c4a);
}

/** Test Life Constructor with Cell template */
TEST(LifeFixture, Life_Constructor_cell) {
  istringstream i("2 2\n.*\n0-");
  Life<Cell> x(i);
  ASSERT_EQ(x._rows, 2);
  ASSERT_EQ(x._cols, 2);
  ASSERT_EQ(x._population, 2);
  ASSERT_EQ(x._board.size(), 4);

  Cell &c1 = x._board[x._at(0, 0)];
  bool c1a = c1._p->_alive;
  ASSERT_FALSE(c1a);

  Cell &c2 = x._board[x._at(0, 1)];
  bool c2a = c2._p->_alive;
  ASSERT_TRUE(c2a);

  Cell &c3 = x._board[x._at(1, 0)];
  bool c3a = c3._p->_alive;
  ASSERT_TRUE(c3a);

  Cell &c4 = x._board[x._at(1, 1)];
  bool c4a = c4._p->_alive;
  ASSERT_FALSE(c4a);
}

TEST(LifeFixture, Life_print_basic) {
  istringstream i("1 1\n.");
  Life<ConwayCell> x(i);
  ostringstream o;
  o << x;
  ASSERT_EQ(o.str(), "Generation = 0, Population = 0.\n.\n\n");

  x.simulate();
  ostringstream p;
  p << x;
  ASSERT_EQ(p.str(), "Generation = 1, Population = 0.\n.\n\n");
}

TEST(LifeFixture, Life_print_conway) {
  istringstream i("3 3\n.*.\n***\n.*.");
  Life<ConwayCell> x(i);
  ostringstream o;
  o << x;
  ASSERT_EQ(o.str(), "Generation = 0, Population = 5.\n.*.\n***\n.*.\n\n");

  x.simulate();
  ostringstream p;
  p << x;
  ASSERT_EQ(p.str(), "Generation = 1, Population = 8.\n***\n*.*\n***\n\n");

  x.simulate();
  ostringstream q;
  q << x;
  ASSERT_EQ(q.str(), "Generation = 2, Population = 4.\n*.*\n...\n*.*\n\n");
}

TEST(LifeFixture, Life_print_fredkin) {
  istringstream i("3 3\n-0-\n000\n-0-");
  Life<ConwayCell> x(i);
  ostringstream o;
  o << x;
  ASSERT_EQ(o.str(), "Generation = 0, Population = 5.\n-0-\n000\n-0-\n\n");

  x.simulate();
  ostringstream p;
  p << x;
  ASSERT_EQ(p.str(), "Generation = 1, Population = 4.\n-1-\n1-1\n-1-\n\n");

  x.simulate();
  ostringstream q;
  q << x;
  ASSERT_EQ(q.str(), "Generation = 2, Population = 0.\n---\n---\n---\n\n");
}

TEST(LifeFixture, Life_print_cell) {
  istringstream i("3 3\n-0-\n0-0\n-0-");
  Life<Cell> x(i);
  ostringstream o;
  o << x;
  ASSERT_EQ(o.str(), "Generation = 0, Population = 4.\n-0-\n0-0\n-0-\n\n");

  x.simulate();
  ostringstream p;
  p << x;
  ASSERT_EQ(p.str(), "Generation = 1, Population = 0.\n---\n---\n---\n\n");

  x.simulate();
  ostringstream q;
  q << x;
  ASSERT_EQ(q.str(), "Generation = 2, Population = 0.\n---\n---\n---\n\n");
}

TEST(LifeFixture, Life_print_cell_complex) {
  istringstream i("6 6\n------\n------\n--00--\n-0000-\n------\n------");
  Life<Cell> x(i);
  ostringstream o;

  x.simulate();
  x.simulate();
  x.simulate();
  x.simulate();

  o << x;
  ASSERT_EQ(o.str(), "Generation = 4, Population = "
                     "16.\n--00--\n--..--\n0*11*0\n1....1\n-1..1-\n-****-\n\n");
}

TEST(LifeFixture, Life_simulate_basic) {
  istringstream i("1 1\n.");
  Life<ConwayCell> x(i);

  ASSERT_EQ(x._turn, 0);
  x.simulate();
  ASSERT_EQ(x._turn, 1);
  ASSERT_EQ(x._population, 0);

  istringstream j("1 1\n-");
  Life<FredkinCell> y(j);

  ASSERT_EQ(y._turn, 0);
  y.simulate();
  ASSERT_EQ(y._turn, 1);
  ASSERT_EQ(y._population, 0);
}

TEST(LifeFixture, Life_simulate_conway) {
  istringstream i("3 3\n...\n***\n...");
  Life<ConwayCell> x(i);
  ASSERT_EQ(x._turn, 0);

  x.simulate();
  ASSERT_EQ(x._turn, 1);
  ASSERT_EQ(x._population, 3);

  x.simulate();
  ASSERT_EQ(x._turn, 2);
  ASSERT_EQ(x._population, 3);

  x.simulate();
  ASSERT_EQ(x._turn, 3);
  ASSERT_EQ(x._population, 3);

  x.simulate();
  ASSERT_EQ(x._turn, 4);
  ASSERT_EQ(x._population, 3);
}

TEST(LifeFixture, Life_simulate_fredkin) {
  istringstream i("3 3\n---\n000\n---");
  Life<FredkinCell> x(i);
  ASSERT_EQ(x._turn, 0);

  x.simulate();
  ASSERT_EQ(x._turn, 1);
  ASSERT_EQ(x._population, 8);

  x.simulate();
  ASSERT_EQ(x._turn, 2);
  ASSERT_EQ(x._population, 0);

  x.simulate();
  ASSERT_EQ(x._turn, 3);
  ASSERT_EQ(x._population, 0);
}

TEST(LifeFixture, Life_simulate_cell) {
  istringstream i("6 6\n------\n------\n--00--\n-0000-\n------\n------");
  Life<Cell> x(i);
  ASSERT_EQ(x._turn, 0);

  x.simulate();
  ASSERT_EQ(x._turn, 1);
  ASSERT_EQ(x._population, 12);

  x.simulate();
  ASSERT_EQ(x._turn, 2);
  ASSERT_EQ(x._population, 22);

  x.simulate();
  ASSERT_EQ(x._turn, 3);
  ASSERT_EQ(x._population, 18);

  x.simulate();
  ASSERT_EQ(x._turn, 4);
  ASSERT_EQ(x._population, 16);

  x.simulate();
  ASSERT_EQ(x._turn, 5);
  ASSERT_EQ(x._population, 20);
}
