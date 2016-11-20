// --------------------------
// projects/life/TestLife.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

/***********/
/* DEFINES */
/***********/

// Define used to trigger friend declarations
#define IS_TESTING

/************/
/* INCLUDES */
/************/

#include "gtest/gtest.h"

#include <algorithm>
#include <sstream>

#include "Life.h"

using namespace std;

/******************/
/* TestConwayCell */
/******************/

TEST(TestConwayCell, test_constructor) {
  ConwayCell cc(false);
  ASSERT_FALSE(cc.is_alive);
}

TEST(TestConwayCell, test_constructor_default_parameter) {
  ConwayCell cc;
  ASSERT_TRUE(cc.is_alive);
}

TEST(TestConwayCell, test_character_representation_alive) {
  // The cell starts alive
  ConwayCell cc;

  ostringstream oss;
  oss << cc;

  ASSERT_EQ("*", oss.str());
}

TEST(TestConwayCell, test_character_representation_dead) {
  // The cell starts alive
  ConwayCell cc;
  cc.is_alive = false;

  ostringstream oss;
  oss << cc;

  ASSERT_EQ(".", oss.str());
}

TEST(TestConwayCell, test_count_neighbors_full) {
  std::vector<std::vector<AbstractCell *>> neighbors(
      3, std::vector<AbstractCell *>(3, nullptr));

  ConwayCell cell;
  for (size_t row_idx = 0; row_idx < 3; ++row_idx) {
    for (size_t col_idx = 0; col_idx < 3; ++col_idx) {
      neighbors[row_idx][col_idx] = &cell;
    }
  }

  ASSERT_EQ(8, cell.count_live_neighbors(neighbors));
}

TEST(TestConwayCell, test_count_neighbors_empty) {
  std::vector<std::vector<AbstractCell *>> neighbors(
      3, std::vector<AbstractCell *>(3, nullptr));

  ConwayCell cell;
  ASSERT_EQ(0, cell.count_live_neighbors(neighbors));
}

TEST(TestConwayCell, test_count_neighbors_middle_ignored) {
  std::vector<std::vector<AbstractCell *>> neighbors(
      3, std::vector<AbstractCell *>(3, nullptr));

  ConwayCell cell;
  for (size_t row_idx = 0; row_idx < 3; ++row_idx) {
    for (size_t col_idx = 0; col_idx < 3; ++col_idx) {
      neighbors[row_idx][col_idx] = &cell;
    }
  }

  // Count with the middle cell equal to a cell
  ASSERT_EQ(8, cell.count_live_neighbors(neighbors));

  neighbors[1][1] = nullptr;
  // Count with the middle cell equal to `nullptr`
  ASSERT_EQ(8, cell.count_live_neighbors(neighbors));
}

TEST(TestConwayCell, test_count_neighbors_sparse) {
  std::vector<std::vector<AbstractCell *>> neighbors(
      3, std::vector<AbstractCell *>(3, nullptr));

  ConwayCell cell;
  neighbors[0][1] = &cell;
  neighbors[1][2] = &cell;
  neighbors[2][1] = &cell;

  ASSERT_EQ(3, cell.count_live_neighbors(neighbors));
}

TEST(TestConwayCell, test_count_neighbors_corners) {
  std::vector<std::vector<AbstractCell *>> neighbors(
      3, std::vector<AbstractCell *>(3, nullptr));

  ConwayCell cell;
  neighbors[0][0] = &cell;
  neighbors[0][2] = &cell;
  neighbors[1][0] = &cell;
  neighbors[1][2] = &cell;
  neighbors[2][0] = &cell;
  neighbors[2][2] = &cell;

  ASSERT_EQ(6, cell.count_live_neighbors(neighbors));
}

TEST(TestConwayCell, test_execute_turn_general) {
  std::vector<std::vector<AbstractCell *>> neighbors(
      3, std::vector<AbstractCell *>(3, nullptr));

  ConwayCell cell;
  ConwayCell cell_store[3] = {};
  neighbors[0][1] = &cell_store[0];

  ASSERT_TRUE(cell.is_alive);

  cell.execute_turn(neighbors);
  ASSERT_FALSE(cell.is_alive);

  // With 3 neighbors the cell should become alive
  neighbors[0][0] = &cell_store[2];
  neighbors[1][0] = &cell_store[2];
  cell.execute_turn(neighbors);

  ASSERT_TRUE(cell.is_alive);
}

TEST(TestConwayCell, test_execute_turn_dead_to_live) {
  std::vector<std::vector<AbstractCell *>> neighbors(
      3, std::vector<AbstractCell *>(3, nullptr));

  ConwayCell cell;
  ConwayCell cell_store[3] = {};
  neighbors[0][1] = &cell_store[0];

  ASSERT_TRUE(cell.is_alive);

  cell.execute_turn(neighbors);
  ASSERT_FALSE(cell.is_alive);

  // With 2 neighbors the cell should not become alive
  neighbors[1][0] = &cell_store[2];
  cell.execute_turn(neighbors);
  ASSERT_FALSE(cell.is_alive);

  // With 3 neighbors the cell should become alive
  neighbors[0][0] = &cell_store[2];

  cell.execute_turn(neighbors);
  ASSERT_TRUE(cell.is_alive);

  cell.execute_turn(neighbors);
  ASSERT_TRUE(cell.is_alive);
}

TEST(TestConwayCell, test_clone_basic) {
  ConwayCell cell;
  cell.is_alive = false;

  const AbstractCell *clone_base_ptr = cell.clone();
  const ConwayCell *clone_conway_ptr =
      dynamic_cast<const ConwayCell *>(clone_base_ptr);

  ASSERT_TRUE(clone_conway_ptr != NULL);
  ASSERT_FALSE(clone_conway_ptr->is_alive);

  delete clone_base_ptr;
}

TEST(TestConwayCell, test_clone_not_same_address) {
  ConwayCell cell;
  cell.is_alive = false;

  const AbstractCell *clone_base_ptr = cell.clone();
  const ConwayCell *clone_conway_ptr =
      dynamic_cast<const ConwayCell *>(clone_base_ptr);

  ASSERT_TRUE(clone_conway_ptr != &cell);

  delete clone_base_ptr;
}

/*******************/
/* TestFredkinCell */
/*******************/

TEST(TestFredkinCell, test_constructor) {
  FredkinCell fc(false);
  ASSERT_FALSE(fc.is_alive);
  ASSERT_EQ(0, fc.age);
}

TEST(TestFredkinCell, test_constructor_default_parameter) {
  FredkinCell fc;
  ASSERT_TRUE(fc.is_alive);
  ASSERT_EQ(0, fc.age);
}

TEST(TestFredkinCell, test_character_representation_alive) {
  // The cell starts alive
  FredkinCell fc;

  ostringstream oss;
  oss << fc;

  ASSERT_EQ("0", oss.str());
}

TEST(TestFredkinCell, test_character_representation_five) {
  // The cell starts alive
  FredkinCell fc;
  fc.age = 5;

  ostringstream oss;
  oss << fc;

  ASSERT_EQ("5", oss.str());
}

TEST(TestFredkinCell, test_character_representation_dead) {
  // The cell starts alive
  FredkinCell fc;
  fc.is_alive = false;

  ostringstream oss;
  oss << fc;

  ASSERT_EQ("-", oss.str());
}

TEST(TestFredkinCell, test_character_representation_older_than_ten) {
  // The cell starts alive
  FredkinCell fc;
  fc.age = 11;

  ostringstream oss;
  oss << fc;

  ASSERT_EQ("+", oss.str());
}

TEST(TestFredkinCell, test_count_neighbors_full) {
  std::vector<std::vector<AbstractCell *>> neighbors(
      3, std::vector<AbstractCell *>(3, nullptr));

  FredkinCell cell;
  for (size_t row_idx = 0; row_idx < 3; ++row_idx) {
    for (size_t col_idx = 0; col_idx < 3; ++col_idx) {
      neighbors[row_idx][col_idx] = &cell;
    }
  }

  ASSERT_EQ(4, cell.count_live_neighbors(neighbors));
}

TEST(TestFredkinCell, test_count_neighbors_empty) {
  std::vector<std::vector<AbstractCell *>> neighbors(
      3, std::vector<AbstractCell *>(3, nullptr));

  FredkinCell cell;
  ASSERT_EQ(0, cell.count_live_neighbors(neighbors));
}

TEST(TestFredkinCell, test_count_neighbors_middle_ignored) {
  std::vector<std::vector<AbstractCell *>> neighbors(
      3, std::vector<AbstractCell *>(3, nullptr));

  FredkinCell cell;
  for (size_t row_idx = 0; row_idx < 3; ++row_idx) {
    for (size_t col_idx = 0; col_idx < 3; ++col_idx) {
      neighbors[row_idx][col_idx] = &cell;
    }
  }

  // Count with the middle cell equal to a cell
  ASSERT_EQ(4, cell.count_live_neighbors(neighbors));

  neighbors[1][1] = nullptr;
  // Count with the middle cell equal to `nullptr`
  ASSERT_EQ(4, cell.count_live_neighbors(neighbors));
}

TEST(TestFredkinCell, test_count_neighbors_sparse) {
  std::vector<std::vector<AbstractCell *>> neighbors(
      3, std::vector<AbstractCell *>(3, nullptr));

  FredkinCell cell;
  neighbors[0][1] = &cell;
  neighbors[1][2] = &cell;
  neighbors[2][0] = &cell;

  ASSERT_EQ(2, cell.count_live_neighbors(neighbors));
}

TEST(TestFredkinCell, test_count_neighbors_corners) {
  std::vector<std::vector<AbstractCell *>> neighbors(
      3, std::vector<AbstractCell *>(3, nullptr));

  FredkinCell cell;
  neighbors[0][0] = &cell;
  neighbors[0][2] = &cell;
  neighbors[2][0] = &cell;
  neighbors[2][2] = &cell;

  ASSERT_EQ(0, cell.count_live_neighbors(neighbors));
}

TEST(TestFredkinCell, test_count_neighbors_edges) {
  std::vector<std::vector<AbstractCell *>> neighbors(
      3, std::vector<AbstractCell *>(3, nullptr));

  FredkinCell cell;
  neighbors[0][1] = &cell;
  neighbors[1][0] = &cell;
  neighbors[1][2] = &cell;
  neighbors[2][1] = &cell;

  ASSERT_EQ(4, cell.count_live_neighbors(neighbors));
}

TEST(TestFredkinCell, test_count_neighbors_corners_and_edges) {
  std::vector<std::vector<AbstractCell *>> neighbors(
      3, std::vector<AbstractCell *>(3, nullptr));

  FredkinCell cell;
  neighbors[0][0] = &cell;
  neighbors[0][1] = &cell;
  neighbors[1][2] = &cell;
  neighbors[2][1] = &cell;
  neighbors[2][0] = &cell;

  ASSERT_EQ(3, cell.count_live_neighbors(neighbors));
}

TEST(TestFredkinCell, test_execute_turn_general) {
  std::vector<std::vector<AbstractCell *>> neighbors(
      3, std::vector<AbstractCell *>(3, nullptr));

  FredkinCell cell;
  FredkinCell cell_store[3] = {};
  neighbors[0][1] = &cell_store[0];
  neighbors[1][2] = &cell_store[1];
  neighbors[2][2] = &cell_store[1];

  ASSERT_TRUE(cell.is_alive);
  ASSERT_EQ(0, cell.age);

  cell.execute_turn(neighbors);
  ASSERT_FALSE(cell.is_alive);
  ASSERT_EQ(0, cell.age);

  // With 3 neighbors the cell should become alive
  neighbors[1][0] = &cell_store[2];
  cell.execute_turn(neighbors);

  ASSERT_TRUE(cell.is_alive);
  ASSERT_EQ(0, cell.age);
}

TEST(TestFredkinCell, test_aging_basic) {
  std::vector<std::vector<AbstractCell *>> neighbors(
      3, std::vector<AbstractCell *>(3, nullptr));

  FredkinCell cell;
  FredkinCell cell_store[3] = {};
  neighbors[0][1] = &cell_store[0];

  ASSERT_TRUE(cell.is_alive);
  ASSERT_EQ(0, cell.age);

  cell.execute_turn(neighbors);
  ASSERT_TRUE(cell.is_alive);
  ASSERT_EQ(1, cell.age);

  cell.execute_turn(neighbors);
  ASSERT_TRUE(cell.is_alive);
  ASSERT_EQ(2, cell.age);
}

TEST(TestFredkinCell, test_aging_and_dying) {
  std::vector<std::vector<AbstractCell *>> neighbors(
      3, std::vector<AbstractCell *>(3, nullptr));

  FredkinCell cell(true);
  FredkinCell cell_store[3] = {};
  neighbors[0][1] = &cell_store[0];
  neighbors[2][1] = &cell_store[0];

  cell.execute_turn(neighbors);
  ASSERT_FALSE(cell.is_alive);
  ASSERT_EQ(0, cell.age);

  cell.execute_turn(neighbors);
  ASSERT_FALSE(cell.is_alive);
  ASSERT_EQ(0, cell.age);

  neighbors[2][1] = nullptr;

  cell.execute_turn(neighbors);
  ASSERT_TRUE(cell.is_alive);
  ASSERT_EQ(0, cell.age);

  cell.execute_turn(neighbors);
  ASSERT_TRUE(cell.is_alive);
  ASSERT_EQ(1, cell.age);
}

TEST(TestFredkinCell, test_can_evlolve_basic) {
  FredkinCell cell(true);
  cell.age = 2;

  ASSERT_TRUE(cell.can_evolve());
}

TEST(TestFredkinCell, test_can_evlolve_too_young) {
  FredkinCell cell(true);
  cell.age = 1;

  ASSERT_FALSE(cell.can_evolve());
}

TEST(TestFredkinCell, test_can_evlolve_too_old) {
  FredkinCell cell(true);
  cell.age = 3;

  ASSERT_FALSE(cell.can_evolve());
}

TEST(TestFredkinCell, test_can_evlolve_dead) {
  FredkinCell cell(false);
  cell.age = 2;

  ASSERT_FALSE(cell.can_evolve());
}

TEST(TestFredkinCell, test_clone_basic) {
  FredkinCell cell;
  cell.is_alive = false;
  cell.age = 4;

  const AbstractCell *clone_base_ptr = cell.clone();
  const FredkinCell *clone_fredkin_ptr =
      dynamic_cast<const FredkinCell *>(clone_base_ptr);

  ASSERT_TRUE(clone_fredkin_ptr != NULL);
  ASSERT_FALSE(clone_fredkin_ptr->is_alive);
  ASSERT_EQ(4, clone_fredkin_ptr->age);

  delete clone_base_ptr;
}

/************/
/* TestCell */
/************/

TEST(TestCell, test_constructor) {
  Cell cell = new FredkinCell(false);

  // Check that the cell is pointing to a FredkinCell
  ASSERT_TRUE(dynamic_cast<FredkinCell *>(cell.cell) != NULL);
}

TEST(TestCell, test_copy_constructor) {
  Cell cell = new FredkinCell(false);
  Cell cell_copy = cell;

  // Check to see that indeed both are fredkin cells
  ASSERT_TRUE(dynamic_cast<FredkinCell *>(cell.cell) != NULL);
  ASSERT_TRUE(dynamic_cast<FredkinCell *>(cell_copy.cell) != NULL);

  // Check that the data was copied correctly
  ASSERT_TRUE(cell.cell != cell_copy.cell);
  ASSERT_EQ(0, dynamic_cast<FredkinCell *>(cell_copy.cell)->age);
}

TEST(TestCell, test_copy_assignment) {
  Cell cell = new FredkinCell(false);
  dynamic_cast<FredkinCell *>(cell.cell)->age = 3;

  Cell cell_copy = new ConwayCell(false);
  cell_copy = cell;

  // Check to see that indeed both are fredkin cells
  ASSERT_TRUE(dynamic_cast<FredkinCell *>(cell.cell) != NULL);
  ASSERT_TRUE(dynamic_cast<FredkinCell *>(cell_copy.cell) != NULL);

  // Check that the data was copied correctly
  ASSERT_TRUE(cell.cell != cell_copy.cell);
  ASSERT_EQ(3, dynamic_cast<FredkinCell *>(cell_copy.cell)->age);
}

TEST(TestCell, test_clone_basic) {
  Cell cell = new ConwayCell(true);
  AbstractCell *cell_clone = cell.clone();

  ASSERT_TRUE(cell_clone->cell_is_alive());
}

TEST(TestCell, test_clone_fredkin) {
  Cell cell = new FredkinCell(false);
  Cell *cell_clone = dynamic_cast<Cell *>(cell.clone());

  ASSERT_FALSE(cell_clone->cell->is_alive);
  ASSERT_EQ(0, dynamic_cast<FredkinCell *>(cell_clone->cell)->age);
}

TEST(TestCell, test_character_representation_basic) {
  Cell cell = new FredkinCell(true);

  ostringstream oss;
  oss << cell;

  ASSERT_EQ("0", oss.str());
}

TEST(TestCell, test_character_representation_conway_alive) {
  Cell cell = new ConwayCell(true);

  ostringstream oss;
  oss << cell;

  ASSERT_EQ("*", oss.str());
}

TEST(TestCell, test_character_representation_conway_dead) {
  Cell cell = new ConwayCell(false);

  ostringstream oss;
  oss << cell;

  ASSERT_EQ(".", oss.str());
}

TEST(TestCell, test_character_representation_fredkin_five) {
  Cell cell = new FredkinCell(true);
  dynamic_cast<FredkinCell *>(cell.cell)->age = 5;

  ostringstream oss;
  oss << cell;

  ASSERT_EQ("5", oss.str());
}

TEST(TestCell, test_character_representation_fredkin_old) {
  Cell cell = new FredkinCell(true);
  dynamic_cast<FredkinCell *>(cell.cell)->age = 100;

  ostringstream oss;
  oss << cell;

  ASSERT_EQ("+", oss.str());
}

TEST(TestCell, test_character_representation_fredkin_dead) {
  Cell cell = new FredkinCell(false);

  ostringstream oss;
  oss << cell;

  ASSERT_EQ("-", oss.str());
}

TEST(TestCell, test_execute_turn_general) {
  std::vector<std::vector<AbstractCell *>> neighbors(
      3, std::vector<AbstractCell *>(3, nullptr));

  Cell cell = new ConwayCell(true);
  ConwayCell cell_store[3] = {};
  neighbors[0][1] = &cell_store[0];

  ASSERT_TRUE(cell.cell->is_alive);

  cell.execute_turn(neighbors);
  ASSERT_FALSE(cell.cell->is_alive);

  // With 3 neighbors the cell should become alive
  neighbors[0][0] = &cell_store[2];
  neighbors[1][0] = &cell_store[2];
  cell.execute_turn(neighbors);

  ASSERT_TRUE(cell.cell->is_alive);
}

TEST(TestCell, test_execute_turn_mutate) {
  std::vector<std::vector<AbstractCell *>> neighbors(
      3, std::vector<AbstractCell *>(3, nullptr));

  Cell cell = new FredkinCell(true);
  const FredkinCell *const fredkin_cell_ptr =
      dynamic_cast<FredkinCell *>(cell.cell);
  FredkinCell cell_store[3] = {};
  neighbors[0][1] = &cell_store[0];

  ASSERT_TRUE(fredkin_cell_ptr->is_alive);
  ASSERT_EQ(0, fredkin_cell_ptr->age);

  cell.execute_turn(neighbors);
  ASSERT_TRUE(fredkin_cell_ptr->is_alive);
  ASSERT_EQ(1, fredkin_cell_ptr->age);

  // After this the cell should have mutated into a ConwayCell
  cell.execute_turn(neighbors);
  ASSERT_TRUE(dynamic_cast<ConwayCell *>(cell.cell) != NULL);
  ASSERT_TRUE(cell.cell->is_alive);
}

TEST(TestCell, test_count_neighbors_empty_conway) {
  std::vector<std::vector<AbstractCell *>> neighbors(
      3, std::vector<AbstractCell *>(3, nullptr));

  Cell cell = new ConwayCell(true);
  ASSERT_EQ(0, cell.count_live_neighbors(neighbors));
}

TEST(TestCell, test_count_neighbors_empty_fredkin) {
  std::vector<std::vector<AbstractCell *>> neighbors(
      3, std::vector<AbstractCell *>(3, nullptr));

  Cell cell = new FredkinCell(true);
  ASSERT_EQ(0, cell.count_live_neighbors(neighbors));
}

TEST(TestCell, test_count_neighbors_full_conway) {
  std::vector<std::vector<AbstractCell *>> neighbors(
      3, std::vector<AbstractCell *>(3, nullptr));

  Cell cell = new ConwayCell(true);
  for (size_t row_idx = 0; row_idx < 3; ++row_idx) {
    for (size_t col_idx = 0; col_idx < 3; ++col_idx) {
      neighbors[row_idx][col_idx] = cell.cell;
    }
  }

  ASSERT_EQ(8, cell.count_live_neighbors(neighbors));
}

TEST(TestCell, test_count_neighbors_full_fredkin) {
  std::vector<std::vector<AbstractCell *>> neighbors(
      3, std::vector<AbstractCell *>(3, nullptr));

  Cell cell = new FredkinCell(true);
  for (size_t row_idx = 0; row_idx < 3; ++row_idx) {
    for (size_t col_idx = 0; col_idx < 3; ++col_idx) {
      neighbors[row_idx][col_idx] = cell.cell;
    }
  }

  ASSERT_EQ(4, cell.count_live_neighbors(neighbors));
}

TEST(TestCell, test_count_neighbors_corners_conway) {
  std::vector<std::vector<AbstractCell *>> neighbors(
      3, std::vector<AbstractCell *>(3, nullptr));

  Cell cell = new ConwayCell(true);
  neighbors[0][0] = &cell;
  neighbors[0][2] = &cell;
  neighbors[2][0] = &cell;
  neighbors[2][2] = &cell;

  ASSERT_EQ(4, cell.count_live_neighbors(neighbors));
}

TEST(TestCell, test_count_neighbors_corners_fredkin) {
  std::vector<std::vector<AbstractCell *>> neighbors(
      3, std::vector<AbstractCell *>(3, nullptr));

  Cell cell = new FredkinCell(true);
  neighbors[0][0] = &cell;
  neighbors[0][2] = &cell;
  neighbors[2][0] = &cell;
  neighbors[2][2] = &cell;

  ASSERT_EQ(0, cell.count_live_neighbors(neighbors));
}

TEST(TestCell, test_cell_is_alive_fredkin) {
  Cell cell = new FredkinCell(false);
  ASSERT_FALSE(cell.cell_is_alive());
}

TEST(TestCell, test_cell_is_alive_conway) {
  Cell cell = new ConwayCell(true);
  ASSERT_TRUE(cell.cell_is_alive());
}

TEST(TestCell, test_cell_is_alive_conway_dead) {
  Cell cell = new ConwayCell(false);
  ASSERT_FALSE(cell.cell_is_alive());
}

/************/
/* TestLife */
/************/

TEST(TestLife, test_constructor) {
  Life<ConwayCell> life(4, 5);

  ASSERT_EQ(4, life.board.size());
  // Checks that all of the rows are of length 5
  ASSERT_TRUE(all_of(begin(life.board), end(life.board),
                     [](vector<ConwayCell *> row) { return 5 == row.size(); }));
  ASSERT_EQ(0, life.generation);
  ASSERT_EQ(4, life.num_rows);
  ASSERT_EQ(5, life.num_cols);
}

TEST(TestLife, test_copy_constructor) {
  Life<ConwayCell> life_old(4, 5);
  Life<ConwayCell> life_new = life_old;

  ASSERT_EQ(4, life_new.board.size());
  // Checks that all of the rows are of length 5
  ASSERT_TRUE(all_of(begin(life_new.board), end(life_new.board),
                     [](vector<ConwayCell *> row) { return 5 == row.size(); }));
  ASSERT_EQ(0, life_new.generation);
  ASSERT_EQ(4, life_new.num_rows);
  ASSERT_EQ(5, life_new.num_cols);
}

TEST(TestLife, test_copy_assignment) {
  Life<ConwayCell> life_old(4, 5);
  Life<ConwayCell> life_new(3, 2);
  life_new = life_old;

  ASSERT_EQ(4, life_new.board.size());
  // Checks that all of the rows are of length 5
  ASSERT_TRUE(all_of(begin(life_new.board), end(life_new.board),
                     [](vector<ConwayCell *> row) { return 5 == row.size(); }));
  ASSERT_EQ(0, life_new.generation);
  ASSERT_EQ(4, life_new.num_rows);
  ASSERT_EQ(5, life_new.num_cols);
}

TEST(TestLife, test_populate_cell_basic) {
  Life<ConwayCell> life(4, 5);
  life.populate_cell(2, 1, new ConwayCell(true));

  ASSERT_TRUE(life.board[2][1]->is_alive);
  ASSERT_EQ(2, life.cell_to_pos[life.board[2][1]].first);
  ASSERT_EQ(1, life.cell_to_pos[life.board[2][1]].second);
}

TEST(TestLife, test_populate_cell_cell) {
  Life<Cell> life(2, 2);
  life.populate_cell(1, 1, new Cell(new ConwayCell()));

  ASSERT_TRUE(life.board[1][1]->cell->is_alive);
}

TEST(TestLife, test_simulate_basic) {
  Life<ConwayCell> life(2, 2);
  life.populate_cell(0, 0, new ConwayCell(false));
  life.populate_cell(0, 1, new ConwayCell(false));
  life.populate_cell(1, 0, new ConwayCell(false));
  life.populate_cell(1, 1, new ConwayCell(true));

  life.simulate();

  ASSERT_FALSE(life.board[0][0]->is_alive);
  ASSERT_FALSE(life.board[0][1]->is_alive);
  ASSERT_FALSE(life.board[1][0]->is_alive);
  ASSERT_FALSE(life.board[1][1]->is_alive);
}

TEST(TestLife, test_simulate_one_by_one) {
  Life<ConwayCell> life(1, 1);
  life.populate_cell(0, 0, new ConwayCell(false));

  life.simulate();

  ASSERT_FALSE(life.board[0][0]->is_alive);
}

TEST(TestLife, test_simulate_generation) {
  Life<ConwayCell> life(1, 1);
  life.populate_cell(0, 0, new ConwayCell(false));

  life.simulate();

  ASSERT_EQ(1, life.generation);
}

TEST(TestLife, test_simulate_partial_death) {
  Life<ConwayCell> life(1, 3);
  life.populate_cell(0, 0, new ConwayCell(true));
  life.populate_cell(0, 1, new ConwayCell(true));
  life.populate_cell(0, 2, new ConwayCell(true));

  life.simulate();

  EXPECT_FALSE(life.board[0][0]->is_alive);
  EXPECT_TRUE(life.board[0][1]->is_alive);
  EXPECT_FALSE(life.board[0][2]->is_alive);

  life.simulate();

  EXPECT_FALSE(life.board[0][0]->is_alive);
  EXPECT_FALSE(life.board[0][1]->is_alive);
  EXPECT_FALSE(life.board[0][2]->is_alive);
}

TEST(TestLife, test_simulate_conversion) {
  Life<ConwayCell> life(2, 2);
  life.populate_cell(0, 0, new ConwayCell(true));
  life.populate_cell(0, 1, new ConwayCell(true));
  life.populate_cell(1, 0, new ConwayCell(true));
  life.populate_cell(1, 1, new ConwayCell(false));

  life.simulate();

  EXPECT_TRUE(life.board[0][0]->is_alive);
  EXPECT_TRUE(life.board[0][1]->is_alive);
  EXPECT_TRUE(life.board[1][0]->is_alive);
  EXPECT_TRUE(life.board[1][1]->is_alive);

  life.simulate();

  EXPECT_TRUE(life.board[0][0]->is_alive);
  EXPECT_TRUE(life.board[0][1]->is_alive);
  EXPECT_TRUE(life.board[1][0]->is_alive);
  EXPECT_TRUE(life.board[1][1]->is_alive);
}

TEST(TestLife, test_output_operator) {
  Life<ConwayCell> life(2, 2);
  life.populate_cell(0, 0, new ConwayCell(true));
  life.populate_cell(0, 1, new ConwayCell(false));
  life.populate_cell(1, 0, new ConwayCell(true));
  life.populate_cell(1, 1, new ConwayCell(false));

  ostringstream expected_oss;
  expected_oss << endl << "Generation = 0, Population = 2." << endl;
  expected_oss << "*." << endl << "*." << endl << endl;

  ostringstream actual_oss;
  actual_oss << life;

  ASSERT_EQ(expected_oss.str(), actual_oss.str());
}

TEST(TestLife, test_output_operator_one_by_one) {
  Life<FredkinCell> life(1, 1);
  life.populate_cell(0, 0, new FredkinCell(true));

  ostringstream expected_oss;
  expected_oss << endl << "Generation = 0, Population = 1." << endl;
  expected_oss << "0" << endl << endl;

  ostringstream actual_oss;
  actual_oss << life;

  ASSERT_EQ(expected_oss.str(), actual_oss.str());
}

TEST(TestLife, test_output_operator_dead_and_alive) {
  Life<FredkinCell> life(1, 2);
  life.populate_cell(0, 0, new FredkinCell(true));
  life.populate_cell(0, 1, new FredkinCell(false));

  ostringstream expected_oss;
  expected_oss << endl << "Generation = 0, Population = 1." << endl;
  expected_oss << "0-" << endl << endl;

  ostringstream actual_oss;
  actual_oss << life;

  ASSERT_EQ(expected_oss.str(), actual_oss.str());
}

TEST(TestLife, test_output_operator_cell) {
  Life<Cell> life(1, 2);
  life.populate_cell(0, 0, new Cell(new FredkinCell(true)));
  life.populate_cell(0, 1, new Cell(new ConwayCell(false)));

  ostringstream expected_oss;
  expected_oss << endl << "Generation = 0, Population = 1." << endl;
  expected_oss << "0." << endl << endl;

  ostringstream actual_oss;
  actual_oss << life;

  ASSERT_EQ(expected_oss.str(), actual_oss.str());
}
