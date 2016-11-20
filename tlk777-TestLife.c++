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
    istringstream iss("1");
    kanje.input(iss);
    ASSERT_TRUE(kanje.life());}

TEST(Cell, input1) {
    Cell kanje;
    istringstream iss("0");
    kanje.input(iss);
    ASSERT_TRUE(kanje.life());}

TEST(Cell, input2) {
    ConwayCell* kim = new ConwayCell(true);
    Cell kanje(kim);
    istringstream iss("*");
    kanje.input(iss);
    ASSERT_TRUE(kanje.life());}

TEST(Cell, input3) {
    Cell kanje;
    istringstream iss("+");
    kanje.input(iss);
    ASSERT_TRUE(kanje.life());}


// output 

TEST(ConwayCell, output1) {
    ConwayCell kanje(true);
    ostringstream oss;
    kanje.output(oss);
    ASSERT_TRUE(oss.str() == "*");}

TEST(ConwayCell, output2) {
    ConwayCell kanje(false);
    ostringstream oss;
    kanje.output(oss);
    ASSERT_FALSE(oss.str() == "*");}

TEST(ConwayCell, output3) {
    ConwayCell kanje(false);
    ostringstream oss;
    kanje.output(oss);
    ASSERT_TRUE(oss.str() == ".");}

TEST(FredkinCell, output1) {
    FredkinCell kanje(false);
    ostringstream oss;
    kanje.output(oss);
    ASSERT_TRUE(oss.str() == "-");}

TEST(FredkinCell, output2) {
    FredkinCell kanje(true);
    ostringstream oss;
    kanje.output(oss);
    ASSERT_FALSE(oss.str() == "-");}

TEST(FredkinCell, output3) {
    FredkinCell kanje(true);
    ostringstream oss;
    kanje.output(oss);
    ASSERT_TRUE(oss.str() == "0");}

TEST(Cell, output1) {
    Cell kanje;
    ostringstream oss;
    kanje.output(oss);
    ASSERT_TRUE(oss.str() == "-");}

TEST(Cell, output2) {
    FredkinCell* kim = new FredkinCell(true);
    Cell kanje(kim);
    ostringstream oss;
    kanje.output(oss);
    ASSERT_TRUE(oss.str() == "0");}


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

TEST(Cell, evolve1) {
    Cell kanje;
    int count = 3;
    kanje.evolve(count); 
    ASSERT_TRUE(kanje.life());}

TEST(Cell, evolve2) {
    Cell kanje;
    int count = 1;
    kanje.evolve(count); 
    ASSERT_TRUE(kanje.life());}

TEST(Cell, evolve3) {
    Cell kanje;
    int count = 4;
    kanje.evolve(count); 
    ASSERT_FALSE(kanje.life());}

//life

TEST(ConwayCell, life1) {
    ConwayCell kanje(false);
    int count = 3;
    kanje.evolve(count); 
    ASSERT_TRUE(kanje.life());}

TEST(ConwayCell, life2) {
    ConwayCell kanje(false);
    int count = 1;
    kanje.evolve(count); 
    ASSERT_FALSE(kanje.life());}

TEST(ConwayCell, life3) {
    ConwayCell kanje(false);
    int count = 4;
    kanje.evolve(count); 
    ASSERT_FALSE(kanje.life());}

TEST(FredkinCell, life1) {
    FredkinCell kanje(false);
    int count = 3;
    kanje.evolve(count); 
    ASSERT_TRUE(kanje.life());}

TEST(FredkinCell, life2) {
    FredkinCell kanje(false);
    int count = 1;
    kanje.evolve(count); 
    ASSERT_TRUE(kanje.life());}

TEST(FredkinCell, life3) {
    FredkinCell kanje(false);
    int count = 4;
    kanje.evolve(count); 
    ASSERT_FALSE(kanje.life());}

TEST(Cell, life1) {
    Cell kanje;
    ASSERT_FALSE(kanje.life());}

TEST(Cell, life2) {
    FredkinCell* kim = new FredkinCell(true);
    Cell kanje(kim);
    ASSERT_TRUE(kanje.life());}

TEST(Cell, life3) {
    ConwayCell* kim = new ConwayCell(true);
    Cell kanje(kim);
    ASSERT_TRUE(kanje.life());}

// listNeighbors

TEST(ConwayCell, neighbors1) {
    ConwayCell kanje(false);
    vector<pair<int, int>> locations;
    kanje.listNeighbors(0, 0, TL, locations); 
    ASSERT_TRUE(locations[0].first == 1 && locations[0].second == 0);}

TEST(ConwayCell, neighbors2) {
    ConwayCell kanje(false);
    vector<pair<int, int>> locations;
    kanje.listNeighbors(10, 10, BR, locations); 
    ASSERT_TRUE(locations[0].first == 9 && locations[0].second == 10);}

TEST(ConwayCell, neighbors3) {
    ConwayCell kanje(false);
    vector<pair<int, int>> locations;
    kanje.listNeighbors(5, 5, L, locations); 
    ASSERT_TRUE(locations[0].first == 4 && locations[0].second == 5);}

TEST(FredkinCell, neighbors1) {
    FredkinCell kanje(false);
    vector<pair<int, int>> locations;
    kanje.listNeighbors(5, 5, L, locations); 
    ASSERT_TRUE(locations[0].first == 4 && locations[0].second == 5);}

TEST(FredkinCell, neighbors2) {
    FredkinCell kanje(false);
    vector<pair<int, int>> locations;
    kanje.listNeighbors(10, 5, DEF, locations); 
    ASSERT_TRUE(locations[0].first == 9 && locations[0].second == 5);}

TEST(FredkinCell, neighbors3) {
    FredkinCell kanje(false);
    vector<pair<int, int>> locations;
    kanje.listNeighbors(0, 10, TR, locations); 
    ASSERT_TRUE(locations[0].first == 1 && locations[0].second == 10);}

TEST(Cell, neighbors1) {
    Cell kanje;
    vector<pair<int, int>> locations;
    kanje.listNeighbors(0, 10, TOP, locations); 
    ASSERT_TRUE(locations[0].first == 1 && locations[0].second == 10);}

TEST(Cell, neighbors2) {
    ConwayCell* kim = new ConwayCell();
    Cell kanje(kim);
    vector<pair<int, int>> locations;
    kanje.listNeighbors(0, 10, TOP, locations); 
    ASSERT_TRUE(locations[0].first == 1 && locations[0].second == 10);}

TEST(Cell, neighbors3) {
    ConwayCell* kim = new ConwayCell(true);
    Cell kanje(kim);
    vector<pair<int, int>> locations;
    kanje.listNeighbors(5, 10, BOT, locations); 
    ASSERT_TRUE(locations[0].first == 4 && locations[0].second == 10);}

//change

TEST(Cell, change) {
    Cell kanje;
    ostringstream oss;
    kanje.change();
    kanje.output(oss);
    ASSERT_TRUE(oss.str() == "*");}

//print
// I couldn't figure out a way to do this. 

//count

TEST(Life, count1){
    int count = 0;
    istringstream iss("3 4\n....\n....\n....");
    Life<ConwayCell> countTest(iss);
    vector<ConwayCell> neighbors;
    ConwayCell kanje(true);
    ConwayCell kim(false);
    ConwayCell beyonce(true);
    neighbors.push_back(kanje);
    neighbors.push_back(kim);
    neighbors.push_back(beyonce);
    count = countTest.count(neighbors);
    ASSERT_TRUE(count == 2);}

TEST(Life, count2){
    int count;
    istringstream iss("3 4\n....\n....\n....");
    Life<FredkinCell> countTest(iss);
    vector<FredkinCell> neighbors;
    FredkinCell kanje(true);
    FredkinCell kim(false);
    FredkinCell beyonce(true);
    neighbors.push_back(kanje);
    neighbors.push_back(kim);
    neighbors.push_back(beyonce);
    count = countTest.count(neighbors);
    ASSERT_TRUE(count == 2);}

TEST(Life, count3){
    int count;
    istringstream iss("3 4\n....\n....\n....");
    Life<Cell> countTest(iss);
    vector<Cell> neighbors;
    Cell kanje;
    Cell kim;
    Cell beyonce;
    beyonce.change();
    neighbors.push_back(kanje);
    neighbors.push_back(kim);
    neighbors.push_back(beyonce);
    count = countTest.count(neighbors);
    ASSERT_TRUE(count == 1);}

//evolution Not necessary to check because all of the functions it uses were checked. 
//I'm not certain how to test taketurn either w/o getters and setters.

