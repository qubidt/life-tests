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

// ----
// test
// ----
Life<ConwayCell> prepareLifeConway(){
    Life<ConwayCell> life(21, 13);
    int i;
    string row = ".............";
    life.addRow(row, 1);
    row = ".............";
    life.addRow(row, 2);
    row = ".............";
    life.addRow(row, 3);
    row = ".............";
    life.addRow(row, 4);
    row = ".............";
    life.addRow(row, 5);
    row = ".............";
    life.addRow(row, 6);
    row = ".............";
    life.addRow(row, 7);
    row = ".............";
    life.addRow(row, 8);
    row = "....*****....";
    life.addRow(row, 9);
    row = ".......*.....";
    life.addRow(row, 10);
    row = "......*......";
    life.addRow(row, 11);
    row = ".....*.......";
    life.addRow(row, 12);
    row = "....*****....";
    life.addRow(row, 13);
    row = ".............";
    life.addRow(row, 14);
    row = ".............";
    life.addRow(row, 15);
    row = ".............";
    life.addRow(row, 16);
    row = ".............";
    life.addRow(row, 17);
    row = ".............";
    life.addRow(row, 18);
    row = ".............";
    life.addRow(row, 19);
    row = ".............";
    life.addRow(row, 20);
    row = ".............";
    life.addRow(row, 21);
    return life;
}


TEST(LifeFixture, testLifeConstructor1) {
    int height = 10;
    int width = 10;
    Life<ConwayCell> x(height, width);
    ASSERT_TRUE(1);
}

TEST(LifeFixture, testLifeConstructor2) {
    int height = 100; 
    int width = 1;
    Life<FredkinCell> x(height, width);
    ASSERT_TRUE(1);
}

TEST(LifeFixture, testLifeConstructor3) {
    int height = 100;
    int width = 100;
    Life<Cell> x(height, width);
    ASSERT_TRUE(1);
}

TEST(LifeFixture, testPopNum1){
    Life<ConwayCell> life = prepareLifeConway();
    int popNum = life.popNum();
    ASSERT_EQ(popNum, 13);
}

TEST(LifeFixture, testPopNum2){
    Life<ConwayCell> life = prepareLifeConway();
    life.nextGen();
    int popNum = life.popNum();
    ASSERT_EQ(popNum, 17);
   
}

TEST(LifeFixture, testPopNum3){
    Life<ConwayCell> life = prepareLifeConway();
    life.nextGen();
    life.nextGen();
    int popNum = life.popNum();
    ASSERT_EQ(popNum, 14);
}

TEST(LifeFixture, testNeighborAlive){
    Life<ConwayCell> life = prepareLifeConway();
    bool alive;
    alive = life.isNeighborAlive(8, 5);
    ASSERT_EQ(alive, true);
}

TEST(LifeFixture, testNeighborAlive2){
    Life<ConwayCell> life = prepareLifeConway();
    bool alive;
    alive = life.isNeighborAlive(8, 3);
    ASSERT_EQ(alive, false);
}

TEST(LifeFixture, testNeighborAlive3){
    Life<ConwayCell> life = prepareLifeConway();
    bool alive;
    alive = life.isNeighborAlive(20, 10);
    ASSERT_EQ(alive, false);
}

TEST(LifeFixture, testnumberNeighbors1){
    Life<ConwayCell> life = prepareLifeConway();
    ConwayCell x(10, 10, true);
    int numAlive = life.numNeighborsAlive(&x, 8, 5);
    ASSERT_EQ(numAlive, 2);
}

TEST(LifeFixture, testnumberNeighbors2){
    Life<ConwayCell> life = prepareLifeConway();
    ConwayCell x(10, 10, true);
    int numAlive = life.numNeighborsAlive(&x, 8, 6);
    ASSERT_EQ(numAlive, 3);
}

TEST(LifeFixture, testnumberNeighbors3){
    Life<ConwayCell> life = prepareLifeConway();
    ConwayCell x(10, 10, true);
    int numAlive = life.numNeighborsAlive(&x, 9, 7);
    ASSERT_EQ(numAlive, 4);
}

TEST(LifeFixture, testnextGen1){
   Life<ConwayCell> life = prepareLifeConway();
   life.nextGen();
   ASSERT_TRUE(1);
}

TEST(LifeFixture, testnextGen2){
   Life<ConwayCell> life = prepareLifeConway();
   life.nextGen();
   life.nextGen();
   life.nextGen();
   ASSERT_TRUE(1);
}

TEST(LifeFixture, testnextGen3){
   Life<ConwayCell> life = prepareLifeConway();
   for(int i = 0; i < 25; i++){
       life.nextGen();
   }
   ASSERT_TRUE(1);
}

TEST(LifeFixture, testConwayConstructor){
   ConwayCell x(10, 10, true);
   ASSERT_TRUE(1);
}

TEST(LifeFixture, testFredkinConstructor){
   FredkinCell x(10, 10, true);
   ASSERT_TRUE(1);
}

TEST(LifeFixture, testCellConstructor){
   Cell x(10, 10, true);
   ASSERT_TRUE(1);
}

TEST(LifeFixture, testConwayisAlive){
   ConwayCell x(10, 10, true);
   bool alive = x.isAlive();
   ASSERT_EQ(alive, true);
}

TEST(LifeFixture, testConwayAlive2){
   ConwayCell x(10, 10, false);
   bool alive = x.isAlive();
   ASSERT_EQ(alive, false);
}

TEST(LifeFixture, testFredkinAlive){
   FredkinCell x(10, 10, true);
   bool alive = x.isAlive();
   ASSERT_EQ(alive, true);
}

TEST(LifeFixture, testFredkinAlive2){
   FredkinCell x(10, 10, false);
   bool alive = x.isAlive();
   ASSERT_EQ(alive, false);
}

TEST(LifeFixture, testConwayCondition){
   ConwayCell x(10, 10, true);
   bool alive = x.condition(3);
   ASSERT_EQ(alive, true);
}

TEST(LifeFixture, testConwayCondition2){
   ConwayCell x(10, 10, false);
   bool alive = x.condition(3);
   ASSERT_EQ(alive, true);
}

TEST(LifeFixture, testConwayCondition3){
   ConwayCell x(10, 10, true);
   bool alive = x.condition(4);
   ASSERT_EQ(alive, false);
}

TEST(LifeFixture, testFredkinCondition1){
   FredkinCell x(10, 10, true);
   bool alive = x.condition(2);
   ASSERT_EQ(alive, false);
}

TEST(LifeFixture, testFredkinCondition2){
   FredkinCell x(10, 10, false);
   bool alive = x.condition(3);
   ASSERT_EQ(alive, true);
}
TEST(LifeFixture, testFredkinCondition3){
   FredkinCell x(10, 10, false);
   bool alive = x.condition(5);
   ASSERT_EQ(alive, false);
}

TEST(LifeFixture, testMutate1){
   Cell x(10, 10, true);
   x.evolve(3, true);
   bool alive = x.isFredkin();
   ASSERT_EQ(alive, false);
}

TEST(LifeFixture, testMutate2){
   Cell x(10, 10, true);
   bool alive = x.isFredkin();
   ASSERT_EQ(alive, true);
}
