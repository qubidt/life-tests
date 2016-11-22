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
#include <fstream>

using namespace std;

// ----
// test
// ----

TEST(ConwayCell, Test_Default_Constructor) {
  ConwayCell temp = ConwayCell();
  assert(temp.symbol == '.');
}

TEST(ConwayCell, Test_Default_Constructor2) {
  ConwayCell temp = ConwayCell();
  assert(temp.alive == false);
}

TEST(ConwayCell, Test_Copy_Constructor) {
  ConwayCell temp = ConwayCell();
  temp.symbol = '*';
  ConwayCell second = ConwayCell(temp);
  assert(second.symbol == '*');
}

TEST(ConwayCell, Test_Copy_Constructor2) {
  ConwayCell temp = ConwayCell();
  temp.alive = true;
  ConwayCell second = ConwayCell(temp);
  assert(second.alive == true);
}

TEST(ConwayCell, Test_Do_Turn) {
  ConwayCell temp = ConwayCell();
  temp.do_turn(3);
  assert(temp.symbol == '*');
}

TEST(ConwayCell, Test_Do_Turn2) {
  ConwayCell temp = ConwayCell();
  temp.do_turn(3);
  assert(temp.alive == true);
}

TEST(ConwayCell, Test_Do_Turn3) {
  ConwayCell temp = ConwayCell();
  temp.alive = true;
  temp.symbol = '*';
  temp.do_turn(0);
  assert(temp.symbol == '.');
}

TEST(ConwayCell, Test_Do_Turn4) {
  ConwayCell temp = ConwayCell();
  temp.alive = true;
  temp.symbol = '*';
  temp.do_turn(0);
  assert(temp.alive == false);
}

TEST(ConwayCell, Test_Assignment_Operator) {
  ConwayCell temp = ConwayCell('*');
  ConwayCell second = ConwayCell();
  second = temp;
  assert(second.alive == true);
}

TEST(ConwayCell, Test_Assignment_Operator2) {
  ConwayCell temp = ConwayCell('*');
  ConwayCell second = ConwayCell();
  second = temp;
  assert(second.symbol == '*');
}

TEST(ConwayCell, Test_Char_Constructor) {
  ConwayCell temp = ConwayCell('*');
  assert(temp.symbol == '*');
  assert(temp.alive == true);
}

TEST(ConwayCell, Test_Char_Constructor2) {
  ConwayCell temp = ConwayCell('.');
  assert(temp.symbol == '.');
  assert(temp.alive == false);
}

TEST(ConwayCell, Test_Clone) {
  ConwayCell temp = ConwayCell('.');
  AbstractCell *second = temp.clone();
  assert(second->symbol == '.');
  assert(second->alive == false);
  delete second;
}

TEST(ConwayCell, Test_Clone2) {
  ConwayCell temp = ConwayCell('*');
  AbstractCell *second = temp.clone();
  assert(second->symbol == '*');
  assert(second->alive == true);
  delete second;
}

TEST(FredkinCell, Test_Default_Constructor) {
  FredkinCell temp = FredkinCell();
  assert(temp.symbol == '-');
}

TEST(FredkinCell, Test_Default_Constructor2) {
  FredkinCell temp = FredkinCell();
  assert(temp.alive == false);
}

TEST(FredkinCell, Test_Default_Constructor3) {
  FredkinCell temp = FredkinCell();
  assert(temp.age == 0);
}

TEST(FredkinCell, Test_Copy_Constructor) {
  FredkinCell temp = FredkinCell();
  temp.symbol = '0';
  FredkinCell second = FredkinCell(temp);
  assert(second.symbol == '0');
}

TEST(FredkinCell, Test_Copy_Constructor2) {
  FredkinCell temp = FredkinCell();
  temp.alive = true;
  FredkinCell second = FredkinCell(temp);
  assert(second.alive == true);
}

TEST(FredkinCell, Test_Copy_Constructor3) {
  FredkinCell temp = FredkinCell();
  temp.age = 4;
  FredkinCell second = FredkinCell(temp);
  assert(second.age == 4);
}

TEST(FredkinCell, Test_Do_Turn) {
  FredkinCell temp = FredkinCell();
  temp.do_turn(3);
  assert(temp.symbol == '0');
}

TEST(FredkinCell, Test_Do_Turn2) {
  FredkinCell temp = FredkinCell();
  temp.do_turn(3);
  assert(temp.alive == true);
}

TEST(FredkinCell, Test_Do_Turn3) {
  FredkinCell temp = FredkinCell();
  temp.alive = true;
  temp.symbol = '0';
  temp.do_turn(0);
  assert(temp.symbol == '-');
}

TEST(FredkinCell, Test_Do_Turn4) {
  FredkinCell temp = FredkinCell();
  temp.alive = true;
  temp.symbol = '0';
  temp.do_turn(0);
  assert(temp.alive == false);
}

TEST(FredkinCell, Test_Do_Turn5) {
  FredkinCell temp = FredkinCell('0');
  temp.do_turn(3);
  assert(temp.age == 1);
  assert(temp.symbol = '1');
}

TEST(FredkinCell, Test_Assignment_Operator) {
  FredkinCell temp = FredkinCell('0');
  FredkinCell second = FredkinCell();
  second = temp;
  assert(second.alive == true);
}

TEST(FredkinCell, Test_Assignment_Operator2) {
  FredkinCell temp = FredkinCell('0');
  FredkinCell second = FredkinCell();
  second = temp;
  assert(second.symbol == '0');
  assert(second.age == 0);
}

TEST(FredkinCell, Test_Char_Constructor) {
  FredkinCell temp = FredkinCell('0');
  assert(temp.symbol == '0');
  assert(temp.alive == true);
}

TEST(FredkinCell, Test_Char_Constructor2) {
  FredkinCell temp = FredkinCell('-');
  assert(temp.symbol == '-');
  assert(temp.alive == false);
}

TEST(FredkinCell, Test_Clone) {
  FredkinCell temp = FredkinCell('-');
  AbstractCell *second = temp.clone();
  assert(second->symbol == '-');
  assert(second->alive == false);
  delete second;
}

TEST(FredkinCell, Test_Clone2) {
  FredkinCell temp = FredkinCell('0');
  AbstractCell *second = temp.clone();
  assert(second->symbol == '0');
  assert(second->alive == true);
  delete second;
}

TEST(Cell, Test_Copy_Constructor) {
  Cell temp = Cell('*');
  Cell second = Cell(temp);
  assert(second._p->symbol == '*');
}

TEST(Cell, Test_Copy_Constructor2) {
  Cell temp = Cell('*');
  Cell second = Cell(temp);
  assert(second._p->alive == true);
}

TEST(Cell, Test_Do_Turn) {
  Cell temp = Cell('.');
  temp.do_turn(3);
  assert(temp._p->symbol == '*');
}

TEST(Cell, Test_Do_Turn2) {
  Cell temp = Cell('.');
  temp.do_turn(3);
  assert(temp._p->alive == true);
}

TEST(Cell, Test_Do_Turn3) {
  Cell temp = Cell('*');
  temp.do_turn(0);
  assert(temp._p->symbol == '.');
}

TEST(Cell, Test_Do_Turn4) {
  Cell temp = Cell('*');
  temp.do_turn(0);
  assert(temp._p->alive == false);
}

TEST(Cell, Test_Assignment_Operator) {
  Cell temp = Cell('*');
  Cell second = Cell();
  second = temp;
  assert(second._p->alive == true);
}

TEST(Cell, Test_Assignment_Operator2) {
  Cell temp = Cell('*');
  Cell second = Cell();
  second = temp;
  assert(second._p->symbol == '*');
}

TEST(Cell, Test_Char_Constructor) {
  Cell temp = Cell('*');
  assert(temp._p->symbol == '*');
  assert(temp._p->alive == true);
}

TEST(Cell, Test_Char_Constructor2) {
  Cell temp = Cell('.');
  assert(temp._p->symbol == '.');
  assert(temp._p->alive == false);
}

int row = 0;
int col = 0;
ifstream myfile("RunLife.in");
int i = 0;
char symbol;
char board[109 * 69];

TEST(LIFE, Test_Constructor) {
  if (myfile.is_open()) {
    myfile >> row;
    myfile >> col;
    while (i < (row * col)) {
      myfile.get(symbol);
      if (symbol == '\n') {
      } else {
        board[i] = symbol;
        i++;
      }
    }
    Life<ConwayCell> first = Life<ConwayCell>(row, col, board);
    assert(first.board.size() == (row * col));
    assert(first.row == row);
    assert(first.col == col);
    assert(first.turn == 0);
    assert(first.population == 13);
    assert(first.copy_board.size() == (row * col));
  }
}

TEST(LIFE, Test_Running) {
  myfile >> row;
  myfile >> col;
  i = 0;
  while (i < (row * col)) {
    myfile.get(symbol);
    if (symbol == '\n') {
    } else {
      board[i] = symbol;
      i++;
    }
  }
  Life<ConwayCell> first = Life<ConwayCell>(row, col, board);
  first.run_simulation(4, -1, 0, false);
  assert(first.turn == 4);
  assert(first.population == 33);
}

TEST(LIFE, Test_Running2) {

  myfile >> row;
  myfile >> col;
  i = 0;
  while (i < (row * col)) {
    myfile.get(symbol);
    if (symbol == '\n') {
    } else {
      board[i] = symbol;
      i++;
    }
  }

  myfile >> row;
  myfile >> col;
  i = 0;
  while (i < (row * col)) {
    myfile.get(symbol);
    if (symbol == '\n') {
    } else {
      board[i] = symbol;
      i++;
    }
  }
  Life<FredkinCell> first = Life<FredkinCell>(row, col, board);
  first.run_simulation(3, -1, 0, false);
  assert(first.turn == 3);
  assert(first.population == 16);
}