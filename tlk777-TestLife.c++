#include "gtest/gtest.h"

#include "Life.h"

using namespace std;

// ----
// test
// ----

// Input

TEST(ConwayCell, input1) {
    ConwayCell kanje(true);
    istringstream iss("*");
    kanje.input(iss);
    ASSERT_TRUE(kanje.life());}

TEST(ConwayCell, input2) {
    ConwayCell kanje(true);
    istringstream iss(".");
    kanje.input(iss);
    ASSERT_FALSE(kanje.life());}

TEST(ConwayCell, input3) {
    ConwayCell kanje(false);
    istringstream iss("*");
    kanje.input(iss);
    ASSERT_TRUE(kanje.life());}

TEST(FredkinCell, input1) {
    FredkinCell kanje(false);
    istringstream iss("0");
    kanje.input(iss);
    ASSERT_TRUE(kanje.life());}

TEST(FredkinCell, input2) {
    FredkinCell kanje(false);
    istringstream iss("-");
    kanje.input(iss);
    ASSERT_FALSE(kanje.life());}

TEST(FredkinCell, input3) {
    FredkinCell kanje(false);
    istringstream iss("5");
    kanje.input(iss);
    ASSERT_TRUE(kanje.life());}

// evolve

TEST(ConwayCell, evolve1) {
    ConwayCell kanje(false);
    int count = 3;
    kanje.evolve(count); 
    ASSERT_TRUE(kanje.life());}

TEST(ConwayCell, evolve2) {
    ConwayCell kanje(false);
    int count = 1;
    kanje.evolve(count); 
    ASSERT_FALSE(kanje.life());}

TEST(ConwayCell, evolve3) {
    ConwayCell kanje(false);
    int count = 4;
    kanje.evolve(count); 
    ASSERT_FALSE(kanje.life());}

TEST(FredkinCell, evolve1) {
    FredkinCell kanje(false);
    int count = 3;
    kanje.evolve(count); 
    ASSERT_TRUE(kanje.life());}

TEST(FredkinCell, evolve2) {
    FredkinCell kanje(false);
    int count = 1;
    kanje.evolve(count); 
    ASSERT_TRUE(kanje.life());}

TEST(FredkinCell, evolve3) {
    FredkinCell kanje(false);
    int count = 4;
    kanje.evolve(count); 
    ASSERT_FALSE(kanje.life());}

