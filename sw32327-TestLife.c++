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

using namespace std;

// ----------
// Life::draw
// ----------

// Board lists generation and population
TEST(LifeFixture, life_draw_1) {
  Life<ConwayCell> x(1, 1, ConwayCell());
  ostringstream o;
  o << x;
  ASSERT_EQ(o.str(), "Generation = 0, Population = 0.\n.\n");
}

// can draw a Fredkin Cell's age
TEST(LifeFixture, life_draw_2) {
  Life<FredkinCell> x(1, 1, FredkinCell(true, 5));
  ostringstream o;
  o << x;
  ASSERT_EQ(o.str(), "Generation = 0, Population = 3.\n5\n");
}

// can draw both types of Cells simulatinously
TEST(LifeFixture, life_draw_3) {
  Life<Cell> x(1, 2, new FredkinCell());
  x.setCell(new ConwayCell(), 0, 1);
  ostringstream o;
  o << x;
  ASSERT_EQ(o.str(), "Generation = 0, Population = 0.\n-.\n");
}

//-------------
// Life::update
//-------------

// ConwayCell should be updated
TEST(LifeFixture, life_update_1) {
  Life<ConwayCell> x(1, 1, ConwayCell());
  ostringstream o;
  x.setCell(ConwayCell(true), 0, 0);
  x.update();
  // cell dies
  o << x;
  ASSERT_EQ(o.str(), "Generation = 1, Population = 0.\n.\n");
}

// updates happen simultaniously
TEST(LifeFixture, life_udpate_2) {
  Life<ConwayCell> x(3, 2, ConwayCell());
  ostringstream o;
  // set live cells
  x.setCell(ConwayCell(true), 0, 1);
  x.setCell(ConwayCell(true), 1, 0);
  x.setCell(ConwayCell(true), 2, 1);
  x.update();
  o << x;
  // only the ones with 2 neighbors in the middle should be alive
  ASSERT_EQ(o.str(), "Generation = 1, Population = 2.\n..\n**\n..\n");
}

// generation count increments each update
TEST(LifeFixture, life_update_3) {
  Life<ConwayCell> x(1, 1, ConwayCell());
  ostringstream o;
  for (int i = 0; i < 5; ++i)
    x.update();
  o << x;
  ASSERT_EQ(o.str(), "Generation = 5, Population = 0.\n.\n");
}

// updates both kinds of cells
TEST(LifeFixture, life_update_4) {
  Life<Cell> x(1, 2, new ConwayCell());
  ostringstream o;
  x.setCell(new FredkinCell(true, 0), 0, 0);
  x.setCell(new ConwayCell(true), 0, 1);
  x.update();
  o << x;
  // Fredkin ages, Conway dies
  ASSERT_EQ(o.str(), "Generation = 1, Population = 1.\n1.\n");
}

//--------------
// Life::setCell
//--------------

// set a cell to be alive
TEST(LifeFixture, life_set_cell_1) {
  Life<ConwayCell> x(1, 1, ConwayCell());
  ostringstream o;
  x.setCell(ConwayCell(true), 0, 0);
  o << x;
  ASSERT_EQ(o.str(), "Generation = 0, Population = 1.\n*\n");
}

// Insert a FredkinCell of a given age
TEST(LifeFixture, life_set_cell_2) {
  Life<FredkinCell> x(1, 1, FredkinCell());
  ostringstream o;
  x.setCell(FredkinCell(true, 3), 0, 0);
  o << x;
  ASSERT_EQ(o.str(), "Generation = 0, Population = 1.\n3\n");
}

// a Life<Cell> can have both kinds of cells
TEST(LifeFixture, life_set_cell_3) {
  Life<Cell> x(1, 2, new ConwayCell());
  ostringstream o;
  x.setCell(new ConwayCell(true), 0, 0);
  x.setCell(new FredkinCell(true, 0), 0, 1);
  o << x;
  ASSERT_EQ(o.str(), "Generation = 0, Population = 2.\n*0\n");
}

// ----------------------------
// AbstractCell::neighbor_count
// ----------------------------

// neighbor count returns the number of living cells
TEST(LifeFixture, abstractcell_neighbor_count_1) {
  ConwayCell dead(false);
  ConwayCell alive(true);
  AbstractCell *neighbors[8];
  for (int i = 0; i < 8; ++i) {
    if (i % 2)
      neighbors[i] = &dead;
    else
      neighbors[i] = &alive;
  }
  ConwayCell x;
  ASSERT_EQ(x.neighbor_count(neighbors), 4);
}

// neighbor count can interate over pointers to children of AbstractCell
TEST(LifeFixture, abstractcell_neighbor_count_2) {
  ConwayCell dead(false);
  ConwayCell alive(true);
  ConwayCell *neighbors[8];
  for (int i = 0; i < 8; ++i) {
    neighbors[i] = &alive;
  }
  ConwayCell x;
  ASSERT_EQ(x.neighbor_count(neighbors), 8);
}

//------------------
// ConwayCell::clone
//------------------

// clone produces an identical copy
TEST(LifeFixture, conwaycell_clone_1) {
  ConwayCell alive(true);
  ConwayCell *other = reinterpret_cast<ConwayCell *>(alive.clone());
  ostringstream o1;
  o1 << alive;
  ostringstream o2;
  o2 << *other;
  delete other;
  ASSERT_EQ(o1.str(), o2.str());
}

// clone is at a new address
TEST(LifeFixture, conwaycell_clone_2) {
  ConwayCell alive(true);
  ConwayCell *other = reinterpret_cast<ConwayCell *>(alive.clone());
  ASSERT_NE(&alive, other);
  delete other;
}

//------------------
// ConwayCell::count
//------------------

// returns a count of live neighbors
TEST(LifeFixture, conwaycell_count_1) {
  ConwayCell alive(true);
  bool vals[8];
  for (int i = 0; i < 8; ++i)
    vals[i] = true;
  ASSERT_EQ(alive.count(vals), 8);
}

// does not count neighbors who are dead
TEST(LifeFixture, conwaycell_count_2) {
  ConwayCell alive(true);
  bool vals[8];
  for (int i = 0; i < 8; ++i)
    vals[i] = true;
  vals[2] = false;
  ASSERT_EQ(alive.count(vals), 7);
}

//-----------------
// ConwayCell::draw
//-----------------

// live ConwayCells are stars
TEST(LifeFixture, conwaycell_draw_1) {
  ConwayCell alive(true);
  ostringstream o;
  o << alive;
  ASSERT_EQ(o.str(), "*");
}

// dead ConwayCells are dots
TEST(LifeFixture, conwaycell_draw_2) {
  ConwayCell dead(false);
  ostringstream o;
  o << dead;
  ASSERT_EQ(o.str(), ".");
}

//-------------------
// ConwayCell::update
//-------------------

// a dead cell becomes alive if it has 3 neighbors
TEST(LifeFixture, conwaycell_update_1) {
  ConwayCell dead(false);
  dead.update(3);
  ostringstream o;
  o << dead;
  ASSERT_EQ(o.str(), "*");
}

// a living cell becomes dead if it has more than 3 neighbors
TEST(LifeFixture, conwaycell_update_2) {
  ConwayCell alive(true);
  alive.update(5);
  ostringstream o;
  o << alive;
  ASSERT_EQ(o.str(), ".");
}

// a living cell becomes dead if it has 1 or less neighbors
TEST(LifeFixture, conwaycell_update_3) {
  ConwayCell alive(true);
  alive.update(1);
  ostringstream o;
  o << alive;
  ASSERT_EQ(o.str(), ".");
}

// ConwayCell stays alive if it has 2 neighbors
TEST(LifeFixture, conwaycell_update_4) {
  ConwayCell alive(true);
  alive.update(2);
  ostringstream o;
  o << alive;
  ASSERT_EQ(o.str(), "*");
}

// ConwayCell stays dead if it has too many neighbors
TEST(LifeFixture, conwaycell_update_5) {
  ConwayCell dead(false);
  dead.update(5);
  ostringstream o;
  o << dead;
  ASSERT_EQ(o.str(), ".");
}

//-------------------
// FredkinCell::clone
//-------------------

// clone produces an identical copy
TEST(LifeFixture, fredkincell_clone_1) {
  FredkinCell alive(true);
  FredkinCell *other = reinterpret_cast<FredkinCell *>(alive.clone());
  ostringstream o1;
  o1 << alive;
  ostringstream o2;
  o2 << *other;
  delete other;
  ASSERT_EQ(o1.str(), o2.str());
}

// clone is at a new address
TEST(LifeFixture, fredkincell_clone_2) {
  FredkinCell alive(true);
  FredkinCell *other = reinterpret_cast<FredkinCell *>(alive.clone());
  ASSERT_NE(&alive, other);
  delete other;
}

//-------------------
// FredkinCell::count
//-------------------

// returns a count of live neighbors only in 4 cardinals
TEST(LifeFixture, fredkincell_count_1) {
  FredkinCell alive(true);
  bool vals[8];
  for (int i = 0; i < 8; ++i)
    vals[i] = true;
  ASSERT_EQ(alive.count(vals), 4);
}

// the values of the other neighbors do not effect the result
TEST(LifeFixture, fredkincell_count_2) {
  FredkinCell alive(true);
  bool vals[8];
  for (int i = 0; i < 8; ++i)
    vals[i] = true;
  vals[0] = false;
  vals[7] = false;
  ASSERT_EQ(alive.count(vals), 4);
}

// dead cells in the cardinal directions are not counted
TEST(LifeFixture, fredkincell_count_3) {
  FredkinCell alive(true);
  bool vals[8];
  for (int i = 0; i < 8; ++i)
    vals[i] = true;
  vals[1] = false;
  vals[3] = false;
  vals[4] = false;
  vals[6] = false;
  ASSERT_EQ(alive.count(vals), 0);
}

//------------------
// FredkinCell::draw
//------------------

// live FredkinCells print their age
TEST(LifeFixture, fredkincell_draw_1) {
  FredkinCell alive(true, 3);
  ostringstream o;
  o << alive;
  ASSERT_EQ(o.str(), "3");
}

// dead FredkinCells are dashes
TEST(LifeFixture, fredkincell_draw_2) {
  FredkinCell dead(false);
  ostringstream o;
  o << dead;
  ASSERT_EQ(o.str(), "-");
}

// a FredkinCell older than 9 is a plus
TEST(LifeFixture, fredkincell_draw_3) {
  FredkinCell alive(true, 10);
  ostringstream o;
  o << alive;
  ASSERT_EQ(o.str(), "+");
}

//--------------------
// FredkinCell::update
//--------------------

// a dead cell becomes alive if it has 3 neighbors
TEST(LifeFixture, fredkincell_update_1) {
  FredkinCell dead(false);
  dead.update(3);
  ostringstream o;
  o << dead;
  ASSERT_EQ(o.str(), "0");
}

// a dead cell becomes alive if it has only 1 neighbor
TEST(LifeFixture, fredkincell_update_2) {
  FredkinCell dead(false);
  dead.update(1);
  ostringstream o;
  o << dead;
  ASSERT_EQ(o.str(), "0");
}

// a living cell becomes dead if it has and even number of neighbors
TEST(LifeFixture, fredkincell_update_3) {
  FredkinCell alive(true);
  alive.update(0);
  ostringstream o;
  o << alive;
  ASSERT_EQ(o.str(), "-");
}

// a living FredkinCell that stays alive advances its age
TEST(LifeFixture, fredkincell_update_4) {
  FredkinCell alive(true, 3);
  alive.update(1);
  ostringstream o;
  o << alive;
  ASSERT_EQ(o.str(), "4");
}

// a living FredkinCell don't age while dead
TEST(LifeFixture, fredkincell_update_5) {
  FredkinCell alive(true, 3);
  alive.update(0);
  alive.update(0);
  alive.update(1);
  ostringstream o;
  o << alive;
  ASSERT_EQ(o.str(), "3");
}

// a FredkinCell requests to change to ConwayCell if it turns 2
TEST(LifeFixture, fredkincell_update_6) {
  FredkinCell alive(true, 1);
  ASSERT_TRUE(alive.update(1));
}

//----------------
// Cell::operator=
//----------------
// a copy of a nullptr cell is a nullptr cell
TEST(LifeFixture, cell_eq_1) {
  Cell our_cell;
  Cell null_cell;
  our_cell = null_cell;
  ASSERT_EQ(our_cell._cell, nullptr);
}

// a copy value is at a different address
TEST(LifeFixture, cell_eq_2) {
  Cell our_cell;
  Cell conway_cell(new ConwayCell());
  our_cell = conway_cell;
  ASSERT_NE(our_cell._cell, conway_cell._cell);
}

// ConwayCells are copied correctly
TEST(LifeFixture, cell_eq_3) {
  Cell our_cell;
  Cell conway_cell(new ConwayCell());
  our_cell = conway_cell;
  ostringstream o1;
  o1 << our_cell;
  ostringstream o2;
  o2 << conway_cell;
  ASSERT_EQ(o1.str(), o2.str());
}

// FredkinCells are copied correctly
TEST(LifeFixture, cell_eq_4) {
  Cell our_cell;
  Cell fredkin_cell(new FredkinCell(true, 1));
  our_cell = fredkin_cell;
  ostringstream o1;
  o1 << our_cell;
  ostringstream o2;
  o2 << fredkin_cell;
  ASSERT_EQ(o1.str(), o2.str());
}

//---------------------
// Cell::neighbor_count
//---------------------

// neighbor count returns the number of living cells
TEST(LifeFixture, cell_neighbor_count_1) {
  Cell dead(new ConwayCell(false));
  Cell alive(new ConwayCell(true));
  Cell *neighbors[8];
  for (int i = 0; i < 8; ++i) {
    if (i % 2)
      neighbors[i] = &dead;
    else
      neighbors[i] = &alive;
  }
  Cell x(new ConwayCell());
  ASSERT_EQ(x.neighbor_count(neighbors), 4);
}

// neighbor count can interate over a mix of FredkinCelss and ConwayCells
TEST(LifeFixture, cell_neighbor_count_2) {
  Cell con(new ConwayCell(true));
  Cell fred(new FredkinCell(true));
  Cell *neighbors[8];
  for (int i = 0; i < 8; ++i) {
    if (i % 2)
      neighbors[i] = &con;
    else
      neighbors[i] = &fred;
  }
  Cell x(new ConwayCell());
  ASSERT_EQ(x.neighbor_count(neighbors), 8);
}

// neighbor count perfoms a Fredkin neighbor check if it has a FredkinCell
TEST(LifeFixture, cell_neighbor_count_3) {
  Cell alive(new ConwayCell(true));
  Cell dead(new FredkinCell(false));
  Cell *neighbors[8];
  for (int i = 0; i < 8; ++i) {
    if (i % 2)
      neighbors[i] = &alive;
    else
      neighbors[i] = &dead;
  }
  Cell x(new FredkinCell());
  // bottom and right should be alive
  ASSERT_EQ(x.neighbor_count(neighbors), 2);
}

// neighbor count counts null Cells as dead
TEST(LifeFixture, cell_neighbor_count_4) {
  Cell dead;
  Cell *neighbors[8];
  for (int i = 0; i < 8; ++i) {
    neighbors[i] = &dead;
  }
  Cell x(new ConwayCell());
  ASSERT_EQ(x.neighbor_count(neighbors), 0);
}

//-------------
// Cell::update
//-------------

// if a FredkinCell grows to 2, it mutates
TEST(LifeFixture, cell_update_1) {
  Cell fcell(new FredkinCell(true, 1));
  fcell.update(1);
  ostringstream o;
  o << fcell;
  ASSERT_EQ(o.str(), "*");
}

// ConwayCells are updated
TEST(LifeFixture, cell_update_2) {
  Cell ccell(new ConwayCell(true));
  ccell.update(5);
  ostringstream o;
  o << ccell;
  // cell is now dead
  ASSERT_EQ(o.str(), ".");
}

// FredkinCells are updated
TEST(LifeFixture, cell_update_3) {
  Cell fcell(new FredkinCell(true, 1));
  fcell.update(0);
  ostringstream o;
  o << fcell;
  // cell is now dead
  ASSERT_EQ(o.str(), "-");
}

//-----------
// Cell::draw
//-----------

// ConwayCells are drawn
TEST(LifeFixture, cell_draw_1) {
  Cell ccell(new ConwayCell(true));
  ostringstream o;
  o << ccell;
  ASSERT_EQ(o.str(), "*");
}

// FredkinCells are drawn
TEST(LifeFixture, cell_draw_2) {
  Cell fcell(new FredkinCell(true, 2));
  ostringstream o;
  o << fcell;
  ASSERT_EQ(o.str(), "2");
}

//-----------
// population
//-----------

// The population count counts from the first cell to one before the last
TEST(LifeFixture, population_1) {
  vector<ConwayCell> cells(10, ConwayCell(true));
  ASSERT_EQ(8, population(&*(cells.begin()), &*(cells.end()) - 2));
}

// The population count does not include dead cells
TEST(LifeFixture, population_2) {
  vector<ConwayCell> cells(10, ConwayCell(true));
  cells[2] = ConwayCell(false);
  ASSERT_EQ(9, population(&*(cells.begin()), &*(cells.end())));
}

// The population works on FredkinCells aswell
TEST(LifeFixture, population_3) {
  vector<FredkinCell> cells(10, FredkinCell(true, 2));
  cells[2] = FredkinCell(false);
  ASSERT_EQ(9, population(&*(cells.begin()), &*(cells.end())));
}

//-------------------------
// population<const Cell *>
//-------------------------

// The population count counts from the first cell to one before the last
TEST(LifeFixture, cell_population_1) {
  const vector<Cell> cells(10, new ConwayCell(true));
  ASSERT_EQ(8, population(&*(cells.begin()), &*(cells.end()) - 2));
}

// The population count does not include dead cells
TEST(LifeFixture, cell_population_2) {
  vector<Cell> cells;
  for (int i = 0; i < 10; ++i) {
    if (i < 3)
      cells.push_back(new ConwayCell(true));
    else
      cells.push_back(new ConwayCell(false));
  }
  const vector<Cell> &cells_const = cells;
  ASSERT_EQ(3, population(&*(cells_const.begin()), &*(cells_const.end())));
}

// The population count works on Cells contianing FredkinCells aswell
TEST(LifeFixture, cell_population_3) {
  const vector<Cell> cells(10, new FredkinCell(true, 2));
  ASSERT_EQ(10, population(&*(cells.begin()), &*(cells.end())));
}

// The populatin count counts null Cells as dead
TEST(LifeFixture, cell_population_4) {
  const vector<Cell> cells(10);
  ASSERT_EQ(0, population(&*(cells.begin()), &*(cells.end())));
}
