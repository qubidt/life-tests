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
#include <sstream>  // istringstream
#include <string>   // getline

#include "Life.h"

template <typename T> Life<T> process(istream &i, ostream &o);

// ----
// main
// ----

int main() {
  using namespace std;
  Life<ConwayCell> cclife;
  Life<FredkinCell> fclife;
  Life<Cell> clife;

  // ----------------------
  // Life<ConwayCell> 21x13
  // ----------------------
  /*
  Simulate 12 evolutions.
  Print every grid (i.e. 0, 1, 2, 3, ... 12)
  */

  cout << "*** Life<ConwayCell> 21x13 ***" << endl;
  cclife = process<ConwayCell>(cin, cout);
  cout << cclife;
  for (int i = 0; i < 12; i++) {
    cclife.run();
    cout << cclife;
  }

  // ----------------------
  // Life<ConwayCell> 20x29
  // ----------------------

  cout << "*** Life<ConwayCell> 20x29 ***" << endl;
  /*
  Simulate 28 evolutions.
  Print every 4th grid (i.e. 0, 4, 8, ... 28)
  */
  cclife = process<ConwayCell>(cin, cout);
  for (int i = 0; i <= 28; i++) {
    if (i % 4 == 0)
      cout << cclife;
    cclife.run();
  }

  // -----------------------
  // Life<ConwayCell> 109x69
  // -----------------------

  cout << "*** Life<ConwayCell> 109x69 ***" << endl;
  /*
  Simulate 283 evolutions.
  Print the first 10 grids (i.e. 0, 1, 2, ... 9).
  Print the 283rd grid.
  Simulate 40 evolutions.
  Print the 323rd grid.
  Simulate 2177 evolutions.
  Print the 2500th grid.
  */
  cclife = process<ConwayCell>(cin, cout);
  for (int i = 0; i <= 2500; i++) {
    if (i < 10 || i == 283 || i == 323 || i == 2500)
      cout << cclife;
    cclife.run();
  }

  // -----------------------
  // Life<FredkinCell> 20x20
  // -----------------------

  cout << "*** Life<FredkinCell> 20x20 ***" << endl;
  /*
  Simulate 5 evolutions.
  Print every grid (i.e. 0, 1, 2, ... 5)
  */
  fclife = process<FredkinCell>(cin, cout);
  for (int i = 0; i <= 5; i++) {
    cout << fclife;
    fclife.run();
  }

  // ----------------
  // Life<Cell> 20x20
  // ----------------

  cout << "*** Life<Cell> 20x20 ***" << endl;
  /*
  Simulate 5 evolutions.
  Print every grid (i.e. 0, 1, 2, ... 5)
  */
  clife = process<Cell>(cin, cout);
  for (int i = 0; i <= 5; i++) {
    cout << clife;
    clife.run();
  }

  return 0;
}

template <typename T> Life<T> process(istream &in, ostream &out) {
  string line;
  istringstream ss;
  int width, height;

  getline(in, line);
  ss.str(line);
  ss >> height >> width;

  Life<T> life(height, width);

  for (int i = 0; i < height; i++) {
    getline(in, line);
    for (int j = 0; j < width; j++)
      life[i][j] = line[j];
  }

  getline(in, line);
  out << endl;

  return life;
}
