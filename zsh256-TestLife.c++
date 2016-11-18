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

TEST(LifeFixture, updateNeighbours0) {

    int r = 2;
    int c = 2;
    
    vector< vector<ConwayCell*> > _grid(r, vector<ConwayCell*>(c, new ConwayCell));

    _grid[0][0] = new ConwayCell;
    _grid[1][1] = new ConwayCell(false);
    _grid[0][1] = new ConwayCell(false);
    _grid[1][0] = new ConwayCell(false);

    Life<ConwayCell> x(r, c, _grid);

    x.updateNeighbours();

    ASSERT_EQ(x.neighbours_grid[0][0], 0);

    delete _grid[0][0];
    delete _grid[0][1];
    delete _grid[1][0];
    delete _grid[1][1];

}


TEST(LifeFixture, updateNeighbours1) {
    
    int r = 2;
    int c = 2;
    
    vector< vector<ConwayCell*> > _grid(r, vector<ConwayCell*>(c, new ConwayCell));

    _grid[0][0] = new ConwayCell;
    _grid[1][1] = new ConwayCell(true);
    _grid[0][1] = new ConwayCell(false);
    _grid[1][0] = new ConwayCell(false);

    Life<ConwayCell> x(r, c, _grid);

    x.updateNeighbours();

    ASSERT_EQ(x.neighbours_grid[0][0], 1);

    delete _grid[0][0];
    delete _grid[0][1];
    delete _grid[1][0];
    delete _grid[1][1];

}

TEST(LifeFixture, updateNeighbours2) {
    
    int r = 2;
    int c = 2;
    
    vector< vector<ConwayCell*> > _grid(r, vector<ConwayCell*>(c, new ConwayCell));

    _grid[0][0] = new ConwayCell;
    _grid[1][1] = new ConwayCell(true);
    _grid[0][1] = new ConwayCell(true);
    _grid[1][0] = new ConwayCell(true);

    Life<ConwayCell> x(r, c, _grid);

    x.updateNeighbours();

    ASSERT_EQ(x.neighbours_grid[0][0], 3);

    delete _grid[0][0];
    delete _grid[0][1];
    delete _grid[1][0];
    delete _grid[1][1];

}

TEST(LifeFixture, updateNeighbours3) {
    
    int r = 3;
    int c = 3;
    
    vector< vector<ConwayCell*> > _grid(r, vector<ConwayCell*>(c, new ConwayCell));

    _grid[0][0] = new ConwayCell(true);
    _grid[0][1] = new ConwayCell(true);
    _grid[0][2] = new ConwayCell(true);
    _grid[1][0] = new ConwayCell(true);
    _grid[1][1] = new ConwayCell(true);
    _grid[1][2] = new ConwayCell(true);
    _grid[2][0] = new ConwayCell(true);
    _grid[2][1] = new ConwayCell(true);
    _grid[2][2] = new ConwayCell(true);

    Life<ConwayCell> x(r, c, _grid);

    x.updateNeighbours();

    ASSERT_EQ(x.neighbours_grid[1][1], 8);

    delete _grid[0][0];
    delete _grid[0][1];
    delete _grid[1][0];
    delete _grid[1][1];

}


TEST(LifeFixture, population0) {
    
    int r = 2;
    int c = 2;
    
    vector< vector<ConwayCell*> > _grid(r, vector<ConwayCell*>(c, new ConwayCell));
    
    _grid[0][0] = new ConwayCell(false);
    _grid[1][1] = new ConwayCell(false);
    _grid[0][1] = new ConwayCell(false);
    _grid[1][0] = new ConwayCell(false);

    Life<ConwayCell> x(r, c, _grid);
    

    ASSERT_EQ(x.population(), 0);

    delete _grid[0][0];
    delete _grid[0][1];
    delete _grid[1][0];
    delete _grid[1][1];

}


TEST(LifeFixture, population1) {
    
    int r = 2;
    int c = 2;
    
    vector< vector<ConwayCell*> > _grid(r, vector<ConwayCell*>(c, new ConwayCell));
    
    _grid[0][0] = new ConwayCell(true);
    _grid[1][1] = new ConwayCell(false);
    _grid[0][1] = new ConwayCell(false);
    _grid[1][0] = new ConwayCell(false);


    Life<ConwayCell> x(r, c, _grid);
    
    ASSERT_EQ(x.population(), 1);

    delete _grid[0][0];
    delete _grid[0][1];
    delete _grid[1][0];
    delete _grid[1][1];

}


TEST(LifeFixture, population2) {
    
    int r = 2;
    int c = 2;
    
    vector< vector<ConwayCell*> > _grid(r, vector<ConwayCell*>(c, new ConwayCell));
    
    _grid[0][0] = new ConwayCell(true);
    _grid[1][1] = new ConwayCell(true);
    _grid[0][1] = new ConwayCell(true);
    _grid[1][0] = new ConwayCell(true);

    Life<ConwayCell> x(r, c, _grid);
    

    ASSERT_EQ(x.population(), 4);

    delete _grid[0][0];
    delete _grid[0][1];
    delete _grid[1][0];
    delete _grid[1][1];

}


TEST(LifeFixture, updateBoard0) {

    int r = 2;
    int c = 2;
    
    vector< vector<ConwayCell*> > _grid(r, vector<ConwayCell*>(c, new ConwayCell));
    
    _grid[0][0] = new ConwayCell(false);
    _grid[0][1] = new ConwayCell(false);
    _grid[1][0] = new ConwayCell(false);
    _grid[1][1] = new ConwayCell(true);

    Life<ConwayCell> x(r, c, _grid);

    x.updateNeighbours();
    x.updateBoard();

    ASSERT_EQ(_grid[0][0]->live(), false);

    delete _grid[0][0];
    delete _grid[0][1];
    delete _grid[1][0];
    delete _grid[1][1];
}


TEST(LifeFixture, FC_updateNeighbours0) {
    
    int r = 2;
    int c = 2;
    
    vector< vector<FredkinCell*> > _grid(r, vector<FredkinCell*>(c, new FredkinCell));

    _grid[0][0] = new FredkinCell;
    _grid[1][1] = new FredkinCell(false);
    _grid[0][1] = new FredkinCell(false);
    _grid[1][0] = new FredkinCell(false);


    Life<FredkinCell> x(r, c, _grid);
    x.updateNeighbours();

    ASSERT_EQ(x.neighbours_grid[0][0], 0);

    delete _grid[0][0];
    delete _grid[0][1];
    delete _grid[1][0];
    delete _grid[1][1];

}


TEST(LifeFixture, FC_updateNeighbours1) {
    
    int r = 2;
    int c = 2;
    
    vector< vector<FredkinCell*> > _grid(r, vector<FredkinCell*>(c, new FredkinCell));

    _grid[0][0] = new FredkinCell;
    _grid[1][1] = new FredkinCell(true);
    _grid[0][1] = new FredkinCell(false);
    _grid[1][0] = new FredkinCell(false);

    Life<FredkinCell> x(r, c, _grid);

    x.updateNeighbours();

    ASSERT_EQ(x.neighbours_grid[0][0], 0);

    delete _grid[0][0];
    delete _grid[0][1];
    delete _grid[1][0];
    delete _grid[1][1];

}

TEST(LifeFixture, FC_updateNeighbours2) {
    
    int r = 2;
    int c = 2;
    
    vector< vector<FredkinCell*> > _grid(r, vector<FredkinCell*>(c, new FredkinCell));

    _grid[0][0] = new FredkinCell;
    _grid[1][1] = new FredkinCell(true);
    _grid[0][1] = new FredkinCell(true);
    _grid[1][0] = new FredkinCell(true);

    Life<FredkinCell> x(r, c, _grid);

    x.updateNeighbours();

    ASSERT_EQ(x.neighbours_grid[0][0], 2);

    delete _grid[0][0];
    delete _grid[0][1];
    delete _grid[1][0];
    delete _grid[1][1];

}

TEST(LifeFixture, FC_updateNeighbours3) {
    
    int r = 3;
    int c = 3;
    
    vector< vector<FredkinCell*> > _grid(r, vector<FredkinCell*>(c, new FredkinCell));

    _grid[0][0] = new FredkinCell(true);
    _grid[0][1] = new FredkinCell(true);
    _grid[0][2] = new FredkinCell(true);
    _grid[1][0] = new FredkinCell(true);
    _grid[1][1] = new FredkinCell(true);
    _grid[1][2] = new FredkinCell(true);
    _grid[2][0] = new FredkinCell(true);
    _grid[2][1] = new FredkinCell(true);
    _grid[2][2] = new FredkinCell(true);

    Life<FredkinCell> x(r, c, _grid);

    x.updateNeighbours();

    ASSERT_EQ(x.neighbours_grid[1][1], 4);

    delete _grid[0][0];
    delete _grid[0][1];
    delete _grid[1][0];
    delete _grid[1][1];

}


TEST(LifeFixture, FC_population0) {
    
    int r = 2;
    int c = 2;
    
    vector< vector<FredkinCell*> > _grid(r, vector<FredkinCell*>(c, new FredkinCell));
    
    _grid[0][0] = new FredkinCell(false);
    _grid[1][1] = new FredkinCell(false);
    _grid[0][1] = new FredkinCell(false);
    _grid[1][0] = new FredkinCell(false);

    Life<FredkinCell> x(r, c, _grid);
    

    ASSERT_EQ(x.population(), 0);

    delete _grid[0][0];
    delete _grid[0][1];
    delete _grid[1][0];
    delete _grid[1][1];

}


TEST(LifeFixture, FC_population1) {
    
    int r = 2;
    int c = 2;
    
    vector< vector<FredkinCell*> > _grid(r, vector<FredkinCell*>(c, new FredkinCell));
    
    _grid[0][0] = new FredkinCell(true);
    _grid[1][1] = new FredkinCell(false);
    _grid[0][1] = new FredkinCell(false);
    _grid[1][0] = new FredkinCell(false);

    Life<FredkinCell> x(r, c, _grid);
    

    ASSERT_EQ(x.population(), 1);

    delete _grid[0][0];
    delete _grid[0][1];
    delete _grid[1][0];
    delete _grid[1][1];

}


TEST(LifeFixture, FC_population2) {
    
    int r = 2;
    int c = 2;
    
    vector< vector<FredkinCell*> > _grid(r, vector<FredkinCell*>(c, new FredkinCell));

    _grid[0][0] = new FredkinCell(true);
    _grid[1][1] = new FredkinCell(true);
    _grid[0][1] = new FredkinCell(true);
    _grid[1][0] = new FredkinCell(true);

    Life<FredkinCell> x(r, c, _grid);
    
    

    ASSERT_EQ(x.population(), 4);

    delete _grid[0][0];
    delete _grid[0][1];
    delete _grid[1][0];
    delete _grid[1][1];

}


TEST(LifeFixture, FC_updateBoard0) {
    
    int r = 2;
    int c = 2;
    
    vector< vector<FredkinCell*> > _grid(r, vector<FredkinCell*>(c, new FredkinCell));
    
    _grid[0][0] = new FredkinCell(false);
    _grid[0][1] = new FredkinCell(false);
    _grid[1][0] = new FredkinCell(false);
    _grid[1][1] = new FredkinCell(true);

    Life<FredkinCell> x(r, c, _grid);

    x.updateNeighbours();
    x.updateBoard();

    ASSERT_EQ(_grid[0][0]->live(), 0);

    delete _grid[0][0];
    delete _grid[0][1];
    delete _grid[1][0];
    delete _grid[1][1];
}

TEST(LifeFixture, FC_updateBoard1) {
    
    int r = 2;
    int c = 2;
    
    vector< vector<FredkinCell*> > _grid(r, vector<FredkinCell*>(c, new FredkinCell));

    _grid[0][0] = new FredkinCell(false);
    _grid[0][1] = new FredkinCell(false);
    _grid[1][0] = new FredkinCell(true);
    _grid[1][1] = new FredkinCell(true);

    Life<FredkinCell> x(r, c, _grid);
    
    

    x.updateNeighbours();
    x.updateBoard();

    ASSERT_EQ(_grid[0][0]->live(), 1);

    delete _grid[0][0];
    delete _grid[0][1];
    delete _grid[1][0];
    delete _grid[1][1];
}



TEST(LifeFixture, AC0) {

    AbstractCell x;

    ASSERT_FALSE(x.live());

    
}

TEST(LifeFixture, FC_updateAge0) {

    FredkinCell x;

    ASSERT_EQ(x.updateAge(), 0);

    
}

TEST(LifeFixture, FC_updateAge1) {

    FredkinCell x;
    x.updateState();
    ASSERT_EQ(x.updateAge(), 1);

    
}

TEST(LifeFixture, FC_updateAge2) {

    FredkinCell x;
    x.updateState();
    x.updateState();
    ASSERT_EQ(x.updateAge(), 0);

    
}

TEST(LifeFixture, FC_updateAge3) {

    FredkinCell x;
    x.updateState();
    for(int i=0;i<5;++i)
        x.updateAge();
    ASSERT_EQ(x.updateAge(), 6);

    
}

TEST(LifeFixture, FC_updateAge4) {

    FredkinCell x;
    for(int i=0;i<5;++i)
        x.updateAge();
    ASSERT_EQ(x.updateAge(), 0);

    
}

TEST(LifeFixture, FC_updateAge5) {

    FredkinCell x(true);
    x.updateState();
    for(int i=0;i<5;++i)
        x.updateAge();
    ASSERT_EQ(x.updateAge(), 0);

    
}

TEST(LifeFixture, FC_updateAge6) {

    FredkinCell x(true);
    for(int i=0;i<5;++i)
        x.updateAge();
    ASSERT_EQ(x.updateAge(), 6);

    
}

TEST(LifeFixture, FC_updateAge7) {

    FredkinCell x(true);
    ASSERT_EQ(x.updateAge(), 1);

    
}

TEST(LifeFixture, FC_updateAge8) {

    FredkinCell x(true);
    for(int i=0;i<9;++i)
        x.updateAge();
    ASSERT_EQ(x.updateAge(), 10);

    
}

TEST(LifeFixture, FC_print0) {

    FredkinCell x(true);
    ASSERT_EQ(x.print(), '0');

    
}

TEST(LifeFixture, FC_print1) {

    FredkinCell x(false);
    ASSERT_EQ(x.print(), '-');

    
}

TEST(LifeFixture, FC_print2) {

    FredkinCell x;
    ASSERT_EQ(x.print(), '-');

    
}

TEST(LifeFixture, FC_print3) {

    FredkinCell x;
    x.updateState();
    ASSERT_EQ(x.print(), '0');

    
}

TEST(LifeFixture, FC_print4) {

    FredkinCell x;
    x.updateState();
    x.updateAge();
    ASSERT_EQ(x.print(), '1');

    
}

TEST(LifeFixture, FC_print5) {

    FredkinCell x;
    x.updateState();
    x.updateAge();
    x.updateAge();
    ASSERT_EQ(x.print(), '2');

    
}

TEST(LifeFixture, FC_print6) {

    FredkinCell x;
    x.updateState();
    for(int i=0;i<9;++i)
    x.updateAge();
    ASSERT_EQ(x.print(), '9');

    
}

TEST(LifeFixture, FC_print7) {

    FredkinCell x(true);
    x.updateState();
    for(int i=0;i<9;++i)
    x.updateAge();
    ASSERT_EQ(x.print(), '-');

    
}

TEST(LifeFixture, FC_print8) {

    FredkinCell x(true);
    for(int i=0;i<10;++i)
    x.updateAge();
    ASSERT_EQ(x.print(), '+');

    
}

TEST(LifeFixture, FC_print9) {

    FredkinCell x(true);
    for(int i=0;i<12;++i)
    x.updateAge();
    ASSERT_EQ(x.print(), '+');

    
}

TEST(LifeFixture, FC_updateState0) {

    FredkinCell x;
    x.updateState();

    ASSERT_TRUE(x.live());

    
}

TEST(LifeFixture, FC_updateState1) {

    FredkinCell x(false);
    x.updateState();

    ASSERT_TRUE(x.live());

    
}

TEST(LifeFixture, FC_updateState2) {

    FredkinCell x(true);
    x.updateState();

    ASSERT_FALSE(x.live());

    
}

TEST(LifeFixture, FC_updateState3) {

    FredkinCell x(false);
    x.updateState();
    x.updateState();

    ASSERT_FALSE(x.live());

    
}

TEST(LifeFixture, FC_updateState4) {

    FredkinCell x(true);
    x.updateState();
    x.updateState();

    ASSERT_TRUE(x.live());

    
}

TEST(LifeFixture, FC_evolve0) {

    FredkinCell x(false);


    ASSERT_EQ(x.evolve()->print(), '-');

    
}

TEST(LifeFixture, FC_evolve1) {

    FredkinCell x(true);


    ASSERT_EQ(x.evolve()->print(), '0');

    
}

TEST(LifeFixture, FC_evolve2) {

    FredkinCell x(true);
    x.updateAge();



    ASSERT_EQ(x.evolve()->print(), '1');

    
}

TEST(LifeFixture, FC_evolve3) {

    FredkinCell x(true);
    x.updateAge();
    x.updateAge();

    ASSERT_EQ(x.evolve()->print(), '*');    
}

TEST(LifeFixture, FC_evolve4) {

    FredkinCell x(true);
    x.updateAge();
    x.updateState();

    ASSERT_EQ(x.evolve()->print(), '-');    
}

TEST(LifeFixture, FC_clone0) {

    FredkinCell x;

    ASSERT_EQ(x.clone(true)->print(), '0');    
}

TEST(LifeFixture, FC_clone1) {

    FredkinCell x(false);

    ASSERT_EQ(x.clone(false)->print(), '-');    
}

TEST(LifeFixture, FC_clone2) {

    FredkinCell x(true);
    x.updateAge();
    x.updateAge();

    ASSERT_EQ(x.clone(true)->print(), '*');    
}


TEST(LifeFixture, FC0) {

    FredkinCell x;

    ASSERT_FALSE(x.live());

    
}

TEST(LifeFixture, FC1) {

    FredkinCell x(true);

    ASSERT_TRUE(x.live());
    ASSERT_EQ(x.print(), '0');
    
}


TEST(LifeFixture, FC2) {
    FredkinCell a(true);
    FredkinCell x(a);

    ASSERT_TRUE(x.live());
    
}


TEST(LifeFixture, FC3) {
    FredkinCell x;

    ASSERT_EQ(x.print(), '-');
    
}

TEST(LifeFixture, FC4) {
    FredkinCell x(true);

    ASSERT_EQ(x.print(), '0');
    
}

TEST(LifeFixture, CC_updateAge0) {

    ConwayCell x;

    ASSERT_EQ(x.updateAge(), 0);

    
}

TEST(LifeFixture, CC_updateAge1) {

    ConwayCell x;
    x.updateState();
    ASSERT_EQ(x.updateAge(), 0);

    
}

TEST(LifeFixture, CC_updateAge2) {

    ConwayCell x;
    x.updateState();
    x.updateState();
    ASSERT_EQ(x.updateAge(), 0);

    
}

TEST(LifeFixture, CC_updateAge3) {

    ConwayCell x;
    x.updateState();
    for(int i=0;i<5;++i)
        x.updateAge();
    ASSERT_EQ(x.updateAge(), 0);

    
}

TEST(LifeFixture, CC_updateAge4) {

    ConwayCell x;
    for(int i=0;i<5;++i)
        x.updateAge();
    ASSERT_EQ(x.updateAge(), 0);

    
}

TEST(LifeFixture, CC_updateAge5) {

    ConwayCell x(true);
    x.updateState();
    for(int i=0;i<5;++i)
        x.updateAge();
    ASSERT_EQ(x.updateAge(), 0);

    
}


TEST(LifeFixture, CC_print0) {

    ConwayCell x(true);
    ASSERT_EQ(x.print(), '*');

    
}

TEST(LifeFixture, CC_print1) {

    ConwayCell x(false);
    ASSERT_EQ(x.print(), '.');

    
}

TEST(LifeFixture, CC_print2) {

    ConwayCell x;
    ASSERT_EQ(x.print(), '.');

    
}

TEST(LifeFixture, CC_print3) {

    ConwayCell x;
    x.updateState();
    ASSERT_EQ(x.print(), '*');

    
}

TEST(LifeFixture, CC_print4) {

    ConwayCell x;
    x.updateState();
    x.updateAge();
    ASSERT_EQ(x.print(), '*');

    
}


TEST(LifeFixture, CC_print5) {

    ConwayCell x(true);
    x.updateState();
    for(int i=0;i<9;++i)
    x.updateAge();
    ASSERT_EQ(x.print(), '.');

    
}


TEST(LifeFixture, CC_updateState0) {

    ConwayCell x;
    x.updateState();

    ASSERT_TRUE(x.live());

    
}

TEST(LifeFixture, CC_updateState1) {

    ConwayCell x(false);
    x.updateState();

    ASSERT_TRUE(x.live());

    
}

TEST(LifeFixture, CC_updateState2) {

    ConwayCell x(true);
    x.updateState();

    ASSERT_FALSE(x.live());

    
}

TEST(LifeFixture, CC_updateState3) {

    ConwayCell x(false);
    x.updateState();
    x.updateState();

    ASSERT_FALSE(x.live());

    
}

TEST(LifeFixture, CC_updateState4) {

    ConwayCell x(true);
    x.updateState();
    x.updateState();

    ASSERT_TRUE(x.live());

    
}

TEST(LifeFixture, CC_evolve0) {

    ConwayCell x(false);


    ASSERT_EQ(x.evolve()->print(), '.');

    
}

TEST(LifeFixture, CC_evolve1) {

    ConwayCell x(true);


    ASSERT_EQ(x.evolve()->print(), '*');

    
}

TEST(LifeFixture, CC_evolve2) {

    ConwayCell x;

    ASSERT_EQ(x.evolve()->print(), '.');

    
}

TEST(LifeFixture, CC_evolve3) {

    ConwayCell x(true);
    x.updateState();

    ASSERT_EQ(x.evolve()->print(), '.');    
}


TEST(LifeFixture, CC_clone0) {

    ConwayCell x;

    ASSERT_EQ(x.clone(false)->print(), '.');    
}

TEST(LifeFixture, CC_clone1) {

    ConwayCell x(false);

    ASSERT_EQ(x.clone(true)->print(), '*');    
}

TEST(LifeFixture, CC_clone2) {

    ConwayCell x;

    ASSERT_EQ(x.clone(false)->print(), '.');    
}


TEST(LifeFixture, CC0) {

    ConwayCell x;

    ASSERT_FALSE(x.live());
    
}

TEST(LifeFixture, CC1) {

    ConwayCell x(true);

    ASSERT_TRUE(x.live());
    ASSERT_EQ(x.alive, '*');
    ASSERT_EQ(x.dead, '.');
    
}


TEST(LifeFixture, CC2) {
    ConwayCell a(true);
    ConwayCell x(a);

    ASSERT_TRUE(x.live());
    
}


TEST(LifeFixture, CC3) {
    ConwayCell x;

    ASSERT_EQ(x.print(), '.');
    
}

TEST(LifeFixture, CC4) {
    ConwayCell x(true);

    ASSERT_EQ(x.print(), '*');
    
}



TEST(LifeFixture, printBoard0) {
    
    int r = 2;
    int c = 2;
    
    vector< vector<ConwayCell*> > _grid(r, vector<ConwayCell*>(c, new ConwayCell));
    
    _grid[0][0] = new ConwayCell(true);
    _grid[1][1] = new ConwayCell(true);
    _grid[0][1] = new ConwayCell(true);
    _grid[1][0] = new ConwayCell(true);

    Life<ConwayCell> x(r, c, _grid);

    ostringstream output;
    x.printBoard(output);

    ASSERT_EQ("\nGeneration = 0, Population = 4.\n**\n**\n\n", output.str());

    delete _grid[0][0];
    delete _grid[0][1];
    delete _grid[1][0];
    delete _grid[1][1];

}


TEST(LifeFixture, printBoard1) {
    
    int r = 2;
    int c = 2;
    
    vector< vector<ConwayCell*> > _grid(r, vector<ConwayCell*>(c, new ConwayCell));

    _grid[0][0] = new ConwayCell(false);
    _grid[1][1] = new ConwayCell(false);
    _grid[0][1] = new ConwayCell(false);
    _grid[1][0] = new ConwayCell(false);

    Life<ConwayCell> x(r, c, _grid);

    ostringstream output;
    x.printBoard(output);

    ASSERT_EQ("\nGeneration = 0, Population = 0.\n..\n..\n\n", output.str());

    delete _grid[0][0];
    delete _grid[0][1];
    delete _grid[1][0];
    delete _grid[1][1];

}


TEST(LifeFixture, printBoard2) {
    
    int r = 2;
    int c = 2;
    
    vector< vector<FredkinCell*> > _grid(r, vector<FredkinCell*>(c, new FredkinCell));

    _grid[0][0] = new FredkinCell(false);
    _grid[1][1] = new FredkinCell(false);
    _grid[0][1] = new FredkinCell(false);
    _grid[1][0] = new FredkinCell(false);

    Life<FredkinCell> x(r, c, _grid);

    ostringstream output;
    x.printBoard(output);

    ASSERT_EQ("\nGeneration = 0, Population = 0.\n--\n--\n\n", output.str());

    delete _grid[0][0];
    delete _grid[0][1];
    delete _grid[1][0];
    delete _grid[1][1];

}