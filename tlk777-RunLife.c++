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

// ----
// main
// ----

int main () {
    using namespace std;

    // ----------------------
    // Life<ConwayCell> 21x13
    // ----------------------

    cout << "*** Life<ConwayCell> 21x13 ***" << endl;
    Life<ConwayCell> twentyOne;

   
    /*
    Simulate 12 evolutions.
    Print every grid (i.e. 0, 1, 2, 3, ... 12)
    */

    twentyOne.print();
    for(int i = 0; i < 12; ++i){
        twentyOne.takeTurn();
        twentyOne.print();
    }

    // ----------------------
    // Life<ConwayCell> 20x29
    // ----------------------

    cout << "*** Life<ConwayCell> 20x29 ***" << endl;

    Life<ConwayCell> twenty;

    /*
    Simulate 28 evolutions.
    Print every 4th grid (i.e. 0, 4, 8, ... 28)
    */

    twenty.print();
    for(int i = 0; i < 28; ++i){
        twenty.takeTurn();
        twenty.print();
    }

    // -----------------------
    // Life<ConwayCell> 109x69
    // -----------------------

    cout << "*** Life<ConwayCell> 109x69 ***" << endl;

    Life<ConwayCell> OneOhNine;

    /*
    Simulate 283 evolutions.
    Print the first 10 grids (i.e. 0, 1, 2, ... 9).
    Print the 283rd grid.
    Simulate 40 evolutions.
    Print the 323rd grid.
    Simulate 2177 evolutions.
    Print the 2500th grid.
    */

    OneOhNine.print();
    for(int i = 1; i <= 2500; ++i){
        OneOhNine.takeTurn();
        if(i < 10 || i == 283 || i == 323 || i == 2500)
            OneOhNine.print();
    }


    // -----------------------
    // Life<FredkinCell> 20x20
    // -----------------------

    cout << "*** Life<FredkinCell> 20x20 ***" << endl;

    Life<FredkinCell> twentyTwenty;

    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */

    twentyTwenty.print();
    for(int i = 0; i < 5; ++i){
        twentyTwenty.takeTurn();
        twentyTwenty.print();
    }

    // ----------------
    // Life<Cell> 20x20
    // ----------------

    cout << "*** Life<Cell> 20x20 ***" << endl;
    Life<Cell> twentyTwentyTwo;

    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */


    twentyTwentyTwo.print();
    for(int i = 0; i < 5; ++i){
        twentyTwentyTwo.takeTurn(); 
        twentyTwentyTwo.print();
    }

    return 0;}
