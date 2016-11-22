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

TEST(LifeFixture, parseBoardFred) {
	istringstream inp("3 3\n---\n-0-\n---");
	istringstream outp("\nGeneration = 0, Population = 1.\n---\n-0-\n---\n\n");
	ostringstream w;
	Life<FredkinCell>* x = new Life<FredkinCell>(3,3,2, inp);

	w << *x;
    ASSERT_EQ(outp.str(), w.str());

}

TEST(LifeFixture, parseBoardCon) {
	istringstream inp("3 3\n...\n.*.\n...");
	istringstream outp("\nGeneration = 0, Population = 1.\n...\n.*.\n...\n\n");
	ostringstream w;
	Life<ConwayCell>* x = new Life<ConwayCell>(3,3,2, inp);

	w << *x;
    ASSERT_EQ(outp.str(), w.str());

}

TEST(LifeFixture, parseBoardCell) {
	istringstream inp("3 3\n---\n-0-\n---");
	istringstream outp("\nGeneration = 0, Population = 1.\n---\n-0-\n---\n\n");
	ostringstream w;
	Life<Cell>* x = new Life<Cell>(3,3,2, inp);

	w << *x;
    ASSERT_EQ(outp.str(), w.str());

}

TEST(LifeFixture, printOutFred) {
	istringstream inp("3 3\n---\n-0-\n---");
	istringstream outp("\nGeneration = 0, Population = 1.\n---\n-0-\n---\n\n\n");
	ostringstream w;
	Life<FredkinCell>* x = new Life<FredkinCell>(3,3,0, inp);
	x->playGame(w);
    ASSERT_EQ(outp.str(), w.str());
}

TEST(LifeFixture, turnFred) {
	istringstream inp("3 3\n---\n-0-\n---");
	istringstream outp("\nGeneration = 0, Population = 1.\n---\n-0-\n---\n\n\n\nGeneration = 1, Population = 4.\n-0-\n0-0\n-0-\n\n\n");
	ostringstream w;
	Life<FredkinCell>* x = new Life<FredkinCell>(3,3,1, inp);
	x->playGame(w);
    ASSERT_EQ(outp.str(), w.str());
}

TEST(LifeFixture, turnFred2) {
	istringstream inp("3 3\n---\n-0-\n---");
	istringstream outp("\nGeneration = 0, Population = 1.\n---\n-0-\n---\n\n\n\nGeneration = 1, Population = 4.\n-0-\n0-0\n-0-\n\n\n\nGeneration = 2, Population = 0.\n---\n---\n---\n\n\n");
	ostringstream w;
	Life<FredkinCell>* x = new Life<FredkinCell>(3,3,2, inp);
	x->playGame(w);
    ASSERT_EQ(outp.str(), w.str());
}

TEST(LifeFixture, FredAge) {
	istringstream inp("3 3\n00-\n---\n---");
	istringstream outp("\nGeneration = 0, Population = 2.\n00-\n---\n---\n\n\n\nGeneration = 1, Population = 5.\n110\n00-\n---\n\n\n");
	ostringstream w;
	Life<FredkinCell>* x = new Life<FredkinCell>(3,3,1, inp);
	x->playGame(w);
    ASSERT_EQ(outp.str(), w.str());
}

TEST(LifeFixture, printOutCon) {
	istringstream inp("3 3\n...\n.*.\n...");
	istringstream outp("\nGeneration = 0, Population = 1.\n...\n.*.\n...\n\n\n");
	ostringstream w;
	Life<ConwayCell>* x = new Life<ConwayCell>(3,3,0, inp);
	x->playGame(w);
    ASSERT_EQ(outp.str(), w.str());
}

TEST(LifeFixture, turnCon) {
	istringstream inp("3 3\n...\n.*.\n...");
	istringstream outp("\nGeneration = 0, Population = 1.\n...\n.*.\n...\n\n\n\nGeneration = 1, Population = 0.\n...\n...\n...\n\n\n");
	ostringstream w;
	Life<ConwayCell>* x = new Life<ConwayCell>(3,3,1, inp);
	x->playGame(w);
    ASSERT_EQ(outp.str(), w.str());
}

TEST(LifeFixture, turnCon2) {
	istringstream inp("3 3\n.*.\n**.\n...");
	istringstream outp("\nGeneration = 0, Population = 3.\n.*.\n**.\n...\n\n\n\nGeneration = 1, Population = 4.\n**.\n**.\n...\n\n\n");
	ostringstream w;
	Life<ConwayCell>* x = new Life<ConwayCell>(3,3,1, inp);
	x->playGame(w);
    ASSERT_EQ(outp.str(), w.str());
}


TEST(LifeFixture, turnCon3) {
	istringstream inp("3 3\n.*.\n**.\n...");
	istringstream outp("\nGeneration = 0, Population = 3.\n.*.\n**.\n...\n\n\n\nGeneration = 1, Population = 4.\n**.\n**.\n...\n\n\n\nGeneration = 2, Population = 4.\n**.\n**.\n...\n\n\n");
	ostringstream w;
	Life<ConwayCell>* x = new Life<ConwayCell>(3,3,2, inp);
	x->playGame(w);
    ASSERT_EQ(outp.str(), w.str());
}

TEST(LifeFixture, turnCon4) {
	istringstream inp("3 3\n.*.\n**.\n.*.");
	istringstream outp("\nGeneration = 0, Population = 4.\n.*.\n**.\n.*.\n\n\n\nGeneration = 1, Population = 7.\n**.\n***\n**.\n\n\n\nGeneration = 2, Population = 5.\n*.*\n..*\n*.*\n\n\n");
	ostringstream w;
	Life<ConwayCell>* x = new Life<ConwayCell>(3,3,2, inp);
	x->playGame(w);
    ASSERT_EQ(outp.str(), w.str());
}

TEST(LifeFixture, lifeCopy) {
	istringstream inp("3 3\n.*.\n**.\n.*.");
	istringstream outp1("\nGeneration = 2, Population = 5.\n*.*\n..*\n*.*\n\n");
	istringstream outp2("\nGeneration = 1, Population = 7.\n**.\n***\n**.\n\n");
	ostringstream w;
	ostringstream v;
	ostringstream z;
	Life<ConwayCell>* x = new Life<ConwayCell>(3,3,2, inp);
	Life<ConwayCell>* y = new Life<ConwayCell>(*x);

	x->takeTurn(true,v);
	x->takeTurn(true,w);
	y->takeTurn(true,z);


    ASSERT_EQ(outp1.str(), w.str());
    ASSERT_EQ(outp2.str(), z.str());
}

TEST(LifeFixture, parseBoardFred2) {
	istringstream inp("3 3\n---\n-0-\n0--");
	istringstream outp("\nGeneration = 0, Population = 2.\n---\n-0-\n0--\n\n");
	ostringstream w;
	Life<FredkinCell>* x = new Life<FredkinCell>(3,3,2, inp);

	w << *x;
    ASSERT_EQ(outp.str(), w.str());

}


TEST(LifeFixture, parseBoardFred3) {
	istringstream inp("3 3\n---\n-0-\n00-");
	istringstream outp("\nGeneration = 0, Population = 3.\n---\n-0-\n00-\n\n");
	ostringstream w;
	Life<FredkinCell>* x = new Life<FredkinCell>(3,3,2, inp);

	w << *x;
    ASSERT_EQ(outp.str(), w.str());

}

TEST(LifeFixture, parseBoardFred4) {
	istringstream inp("3 3\n---\n-0-\n000");
	istringstream outp("\nGeneration = 0, Population = 4.\n---\n-0-\n000\n\n");
	ostringstream w;
	Life<FredkinCell>* x = new Life<FredkinCell>(3,3,2, inp);

	w << *x;
    ASSERT_EQ(outp.str(), w.str());
}

TEST(LifeFixture, parseBoardFred5) {
	istringstream inp("3 3\n---\n-00\n000");
	istringstream outp("\nGeneration = 0, Population = 5.\n---\n-00\n000\n\n");
	ostringstream w;
	Life<FredkinCell>* x = new Life<FredkinCell>(3,3,2, inp);

	w << *x;
    ASSERT_EQ(outp.str(), w.str());
}

TEST(LifeFixture, parseBoardFred6) {
	istringstream inp("3 3\n000\n-00\n000");
	istringstream outp("\nGeneration = 0, Population = 8.\n000\n-00\n000\n\n");
	ostringstream w;
	Life<FredkinCell>* x = new Life<FredkinCell>(3,3,2, inp);

	w << *x;
    ASSERT_EQ(outp.str(), w.str());
}

TEST(LifeFixture, parseBoardFred7) {
	istringstream inp("3 3\n00-\n-00\n000");
	istringstream outp("\nGeneration = 0, Population = 7.\n00-\n-00\n000\n\n");
	ostringstream w;
	Life<FredkinCell>* x = new Life<FredkinCell>(3,3,2, inp);

	w << *x;
    ASSERT_EQ(outp.str(), w.str());
}

TEST(LifeFixture, parseBoardFred8) {
	istringstream inp("3 3\n-00\n-00\n000");
	istringstream outp("\nGeneration = 0, Population = 7.\n-00\n-00\n000\n\n");
	ostringstream w;
	Life<FredkinCell>* x = new Life<FredkinCell>(3,3,2, inp);

	w << *x;
    ASSERT_EQ(outp.str(), w.str());
}

TEST(LifeFixture, parseBoardFred9) {
	istringstream inp("3 3\n000\n000\n000");
	istringstream outp("\nGeneration = 0, Population = 9.\n000\n000\n000\n\n");
	ostringstream w;
	Life<FredkinCell>* x = new Life<FredkinCell>(3,3,2, inp);

	w << *x;
    ASSERT_EQ(outp.str(), w.str());
}

TEST(LifeFixture, parseBoardFred10) {
	istringstream inp("3 3\n---\n---\n---");
	istringstream outp("\nGeneration = 0, Population = 0.\n---\n---\n---\n\n");
	ostringstream w;
	Life<FredkinCell>* x = new Life<FredkinCell>(3,3,2, inp);

	w << *x;
    ASSERT_EQ(outp.str(), w.str());
}

TEST(LifeFixture, parseBoardFred11) {
	istringstream inp("3 3\n---\n--0\n---");
	istringstream outp("\nGeneration = 0, Population = 1.\n---\n--0\n---\n\n");
	ostringstream w;
	Life<FredkinCell>* x = new Life<FredkinCell>(3,3,2, inp);

	w << *x;
    ASSERT_EQ(outp.str(), w.str());
}

TEST(LifeFixture, parseBoardFred12) {
	istringstream inp("3 3\n0--\n---\n---");
	istringstream outp("\nGeneration = 0, Population = 1.\n0--\n---\n---\n\n");
	ostringstream w;
	Life<FredkinCell>* x = new Life<FredkinCell>(3,3,2, inp);

	w << *x;
    ASSERT_EQ(outp.str(), w.str());
}

TEST(LifeFixture, parseBoardFred13) {
	istringstream inp("3 3\n---\n---\n-0-");
	istringstream outp("\nGeneration = 0, Population = 1.\n---\n---\n-0-\n\n");
	ostringstream w;
	Life<FredkinCell>* x = new Life<FredkinCell>(3,3,2, inp);

	w << *x;
    ASSERT_EQ(outp.str(), w.str());
}