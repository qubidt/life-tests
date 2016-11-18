// -------------------------
// projects/life/RunLife.c++
// Copyright (C) 2016
// Glenn P. Downing
// -------------------------

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // cout, endl

#include "Life.h"


// Functions to decide what turns to print grid
bool f1 (int turn) {
    return true;
}
bool f2 (int turn) {
    if (turn%4 == 0)
        return true;
    return false;
}
bool f3 (int turn) {
    if (turn <  10        ||
        turn == 283       ||
        turn == 323       ||
        turn == 2500)
        return true;
    return false;
}

// ----
// main
// ----

int main () {
    using namespace std;

    // ----------------------
    // Life<ConwayCell> 21x13
    // ----------------------

    cout << "*** Life<ConwayCell> 21x13 ***" << endl;
    /*
    Simulate 12 evolutions.
    Print every grid (i.e. 0, 1, 2, 3, ... 12)
    */
    int x0, y0;
    string s0;

    cin >> x0;
    cin >> y0;
    getline (cin, s0);
    Life<ConwayCell> L0(x0, y0);
    for (int row = 0; row < x0; ++row) {
        getline (cin, s0);
        L0.add_line (row, s0);
    }
    L0.play (12, cout, f1);


    // ----------------------
    // Life<ConwayCell> 20x29
    // ----------------------

    cout << "*** Life<ConwayCell> 20x29 ***" << endl;
    /*
    Simulate 28 evolutions.
    Print every 4th grid (i.e. 0, 4, 8, ... 28)
    */
    int x1, y1;
    string s1;

    cin >> x1;
    cin >> y1;
    getline (cin, s1);
    Life<ConwayCell> L1(x1, y1);
    for (int row = 0; row < x1; ++row) {
        getline (cin, s1);
        L1.add_line (row, s1);
    }
    L1.play (28, cout, f2);

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
    int x2, y2;
    string s2;

    cin >> x2;
    cin >> y2;
    getline (cin, s2);
    Life<ConwayCell> L2(x2, y2);
    for (int row = 0; row < x2; ++row) {
        getline (cin, s2);
        L2.add_line (row, s2);
    }
    L2.play (283 + 40 + 2177, cout, f3);

    // -----------------------
    // Life<FredkinCell> 20x20
    // -----------------------

    cout << "*** Life<FredkinCell> 20x20 ***" << endl;
    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */
    int x3, y3;
    string s3;

    cin >> x3;
    cin >> y3;
    getline (cin, s3);
    Life<FredkinCell> L3(x3, y3);
    for (int row = 0; row < x3; ++row) {
        getline (cin, s3);
        L3.add_line (row, s3);
    }
    L3.play (5, cout, f1);

    // ----------------
    // Life<Cell> 20x20
    // ----------------

    cout << "*** Life<Cell> 20x20 ***" << endl;
    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */
    int x4, y4;
    string s4;

    cin >> x4;
    cin >> y4;
    getline (cin, s4);
    Life<Cell> L4(x4, y4);
    for (int row = 0; row < x4; ++row) {
        getline (cin, s4);
        L4.add_line (row, s4);
    }
    L4.play (5, cout, f1);

    return 0;}
