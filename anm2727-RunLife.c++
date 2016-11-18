// -------------------------
// projects/life/RunLife.c++
// Copyright (C) 2016
// Glenn P. Downing
// -------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <stdlib.h>

#include "Life.h"

// ----
// life_solve
// ----

/**
 * Process the given input to an actual Life Object
 */
template <typename T>
void life_add(int rows, int cols, Life<T> &x, istream &r) {

  string str;

  for (int row = 0; row < rows; ++row) {
    str = "";
    r >> str;

    for (int col = 0; col < cols; ++col) {
      if (str[col] != '.' && str[col] != '-') {
        T cell(str[col]);
        x.addCell(col, row, cell);
      }
    }
  }
}

// ----
// main
// ----

int main() {
  using namespace std;

  istream &r = cin;
  string str = "";

  // ----------------------
  // Life<ConwayCell> 21x13
  // ----------------------
  cout << "*** Life<ConwayCell> 21x13 ***" << endl;

  // Grab the dimensions of the grid
  r >> str;
  int rows = atoi(str.c_str());

  assert(rows == 21);

  str = "";

  r >> str;
  int cols = atoi(str.c_str());

  assert(cols == 13);

  Life<ConwayCell> x(rows, cols);

  life_add(rows, cols, x, r);

  /*
  Simulate 12 evolutions.
  Print every grid (i.e. 0, 1, 2, 3, ... 12)
  */
  int evolutions = 12;
  x.simulate(evolutions, 1);

  // ----------------------
  // Life<ConwayCell> 20x29
  // ----------------------

  cout << "*** Life<ConwayCell> 20x29 ***" << endl;

  str = "";
  r >> str;
  rows = atoi(str.c_str());

  assert(rows == 20);

  str = "";

  r >> str;
  cols = atoi(str.c_str());

  assert(cols == 29);

  Life<ConwayCell> x2(rows, cols);

  life_add(rows, cols, x2, r);

  /*
  Simulate 28 evolutions.
  Print every 4th grid (i.e. 0, 4, 8, ... 28)
  */
  evolutions = 28;
  x2.simulate(evolutions, 4);

  // -----------------------
  // Life<ConwayCell> 109x69
  // -----------------------

  cout << "*** Life<ConwayCell> 109x69 ***" << endl;

  str = "";
  r >> str;
  rows = atoi(str.c_str());
  assert(rows == 109);

  str = "";
  r >> str;
  cols = atoi(str.c_str());
  assert(cols == 69);

  Life<ConwayCell> x3(rows, cols);
  life_add(rows, cols, x3, r);

  /*
  Simulate 283 evolutions.
  Print the first 10 grids (i.e. 0, 1, 2, ... 9).
  Print the 283rd grid.
  */
  evolutions = 9;
  x3.simulate(evolutions, 1);

  evolutions = 274;
  x3.simulate(evolutions, 283);

  /*
  Simulate 40 evolutions.
  Print the 323rd grid.
  */
  evolutions = 40;
  x3.simulate(evolutions, 323);

  // /*
  // Simulate 2177 evolutions.
  // Print the 2500th grid.
  // */
  evolutions = 2177;
  x3.simulate(evolutions, 2500);

  // -----------------------
  // Life<FredkinCell> 20x20
  // -----------------------

  cout << "*** Life<FredkinCell> 20x20 ***" << endl;

  str = "";
  r >> str;
  rows = atoi(str.c_str());
  assert(rows == 20);

  str = "";
  r >> str;
  cols = atoi(str.c_str());
  assert(cols == 20);

  Life<FredkinCell> x4(rows, cols);
  life_add(rows, cols, x4, r);

  /*
  Simulate 5 evolutions.
  Print every grid (i.e. 0, 1, 2, ... 5)
  */
  evolutions = 5;
  x4.simulate(evolutions, 1);

  // ----------------
  // Life<Cell> 20x20
  // ----------------

  cout << "*** Life<Cell> 20x20 ***" << endl;

  str = "";
  r >> str;
  rows = atoi(str.c_str());
  assert(rows == 20);

  str = "";
  r >> str;
  cols = atoi(str.c_str());
  assert(cols == 20);

  Life<Cell> x5(rows, cols);
  life_add(rows, cols, x5, r);

  // Simulate 5 evolutions.
  // Print every grid (i.e. 0, 1, 2, ... 5)

  evolutions = 5;
  x5.simulate(evolutions, 1);

  return 0;
}
