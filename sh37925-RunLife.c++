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

#include "Life.h"

// ----
// main
// ----

int main() {
  using namespace std;

  // ----------------------
  // Life<ConwayCell> 21x13
  // ----------------------

  cout << "*** Life<ConwayCell> 21x13 ***\n" << endl;
  /*
  Simulate 12 evolutions.
  Print every grid (i.e. 0, 1, 2, 3, ... 12)
  */
  Life<ConwayCell> life(12);
  life.print_grid(0);
  for (int i = 1; i <= 12; ++i) {
    life.run_life();
    life.print_grid(i);
  }

  // ----------------------
  // Life<ConwayCell> 20x29
  // ----------------------

  cout << "*** Life<ConwayCell> 20x29 ***\n" << endl;
  /*
  Simulate 28 evolutions.
  Print every 4th grid (i.e. 0, 4, 8, ... 28)
  */

  Life<ConwayCell> life2(28);
  life2.print_grid(0);
  for (int i = 1; i <= 28; ++i) {
    life2.run_life();
    if (i % 4 == 0)
      life2.print_grid(i);
  }

  // -----------------------
  // Life<ConwayCell> 109x69
  // -----------------------

  cout << "*** Life<ConwayCell> 109x69 ***\n" << endl;
  /*
  Simulate 283 evolutions.
  Print the first 10 grids (i.e. 0, 1, 2, ... 9).
  Print the 283rd grid.
  Simulate 40 evolutions.
  Print the 323rd grid.
  Simulate 2177 evolutions.
  Print the 2500th grid.
  */

  Life<ConwayCell> life3(283);
  life3.print_grid(0);
  int i;
  for (i = 1; i <= 283; ++i) {
    life3.run_life();
    if (i < 10)
      life3.print_grid(i);
  }
  life3.print_grid(i - 1);
  for (; i <= 323; ++i) {
    life3.run_life();
  }
  life3.print_grid(i - 1);
  for (; i <= 2500; ++i) {
    life3.run_life();
  }
  life3.print_grid(i - 1);

  // -----------------------
  // Life<FredkinCell> 20x20
  // -----------------------

  cout << "*** Life<FredkinCell> 20x20 ***" << endl;
  /*
  Simulate 5 evolutions.
  Print every grid (i.e. 0, 1, 2, ... 5)
  */

  Life<FredkinCell> life4(5);
  life4.print_grid(0);
  for (int i = 1; i <= 5; ++i) {
    life4.run_life();
    life4.print_grid(i);
  }

  // ----------------
  // Life<Cell> 20x20
  // ----------------

  cout << "*** Life<Cell> 20x20 ***" << endl;
  /*
  Simulate 5 evolutions.
  Print every grid (i.e. 0, 1, 2, ... 5)
  */

  Life<Cell> life5(5);
  life5.print_grid(0);
  for (int i = 1; i <= 5; ++i) {
    life5.run_life();
    life5.print_grid(i);
  }

  return 0;
}
