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

TEST(LifeFixture, testACAlive1) {
    ConwayCell cc(true);
    ASSERT_TRUE(cc._alive);
}

TEST(LifeFixture, testACAlive2) {
    ConwayCell cc(false);
    ASSERT_FALSE(cc._alive);
}

TEST(LifeFixture, testACAlive3) {
    FredkinCell fc(true);
    ASSERT_TRUE(fc._alive);
}

TEST(LifeFixture, testIsAlive1) {
    ConwayCell cc(true);
    ASSERT_TRUE(cc.isAlive());
}

TEST(LifeFixture, testIsAlive2) {
    ConwayCell cc(false);
    ASSERT_FALSE(cc.isAlive());
}

TEST(LifeFixture, testIsAlive3) {
    FredkinCell fc(true);
    ASSERT_TRUE(fc.isAlive());
}

TEST(LifeFixture, testResurrect1) {
    ConwayCell cc(true);
    cc.resurrect();
    ASSERT_TRUE(cc.isAlive());
}

TEST(LifeFixture, testResurrect2) {
    ConwayCell cc(false);
    cc.resurrect();
    ASSERT_TRUE(cc.isAlive());
}

TEST(LifeFixture, testResurrect3) {
    ConwayCell cc(true);
    cc.kill();
    cc.resurrect();
    ASSERT_TRUE(cc.isAlive());
}

TEST(LifeFixture, testKill1) {
    ConwayCell cc(true);
    cc.kill();
    ASSERT_FALSE(cc.isAlive());
}

TEST(LifeFixture, testKill2) {
    ConwayCell cc(false);
    cc.kill();
    ASSERT_FALSE(cc.isAlive());
}

TEST(LifeFixture, testKill3) {
    ConwayCell cc(false);
    cc.resurrect();
    cc.kill();
    ASSERT_FALSE(cc.isAlive());
}

TEST(LifeFixture, testConwayOpFredkin1) {
    ConwayCell cc(true);
    FredkinCell fc(false);
    cc = fc;
    ASSERT_TRUE(cc.isAlive());
}

TEST(LifeFixture, testConwayOpFredkin2) {
    ConwayCell cc(false);
    FredkinCell fc(true);
    cc = fc;
    ASSERT_FALSE(cc.isAlive());
}

TEST(LifeFixture, testConwayOpFredkin3) {
    ConwayCell cc(true);
    FredkinCell fc(true);
    cc = fc;
    ASSERT_TRUE(cc.isAlive());
}

TEST(LifeFixture, testConwayOpFredkin4) {
    ConwayCell cc(false);
    FredkinCell fc(false);
    cc = fc;
    ASSERT_FALSE(cc.isAlive());
}

TEST(LifeFixture, testConwayClone1) {
    ConwayCell cc(true);
    AbstractCell *cell = cc.clone();
    ASSERT_TRUE(cell != nullptr);
    delete cell;
}

TEST(LifeFixture, testConwayClone2) {
    ConwayCell cc(true);
    AbstractCell *cell = cc.clone();
    AbstractCell *cell2 = cc.clone();
    ASSERT_TRUE(cell != cell2);
    delete cell;
    delete cell2;
}

TEST(LifeFixture, testConwayClone3) {
    ConwayCell cc(true);
    AbstractCell *cell = cc.clone();
    ASSERT_TRUE(cell->_alive);
    delete cell;
}

TEST(LifeFixture, testConwayMutatable) {
    ConwayCell cc(true);
    ASSERT_EQ(CellType::CONWAY, cc.mutatable());
}

TEST(LifeFixture, testConwayDoAction0) {
    ConwayCell cc(true);
    tuple<ActionResult, CellType> result = cc.doAction(0, 0);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::DEAD, ar);
}

TEST(LifeFixture, testConwayDoAction1) {
    ConwayCell cc(true);
    tuple<ActionResult, CellType> result = cc.doAction(1, 0);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::DEAD, ar);
}

TEST(LifeFixture, testConwayDoAction2) {
    ConwayCell cc(true);
    tuple<ActionResult, CellType> result = cc.doAction(2, 0);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::NOP, ar);
}

TEST(LifeFixture, testConwayDoAction3) {
    ConwayCell cc(true);
    tuple<ActionResult, CellType> result = cc.doAction(3, 0);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::ALIVE, ar);
}

TEST(LifeFixture, testConwayDoAction4) {
    ConwayCell cc(true);
    tuple<ActionResult, CellType> result = cc.doAction(4, 0);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::DEAD, ar);
}

TEST(LifeFixture, testConwayDoAction5) {
    ConwayCell cc(true);
    tuple<ActionResult, CellType> result = cc.doAction(5, 0);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::DEAD, ar);
}

TEST(LifeFixture, testConwayDoAction6) {
    ConwayCell cc(true);
    tuple<ActionResult, CellType> result = cc.doAction(6, 0);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::DEAD, ar);
}

TEST(LifeFixture, testConwayDoAction7) {
    ConwayCell cc(true);
    tuple<ActionResult, CellType> result = cc.doAction(7, 0);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::DEAD, ar);
}

TEST(LifeFixture, testConwayDoAction8) {
    ConwayCell cc(true);
    tuple<ActionResult, CellType> result = cc.doAction(8, 0);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::DEAD, ar);
}

TEST(LifeFixture, testConwayDoAction9) {
    ConwayCell cc(false);
    tuple<ActionResult, CellType> result = cc.doAction(0, 0);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::DEAD, ar);
}

TEST(LifeFixture, testConwayDoAction10) {
    ConwayCell cc(false);
    tuple<ActionResult, CellType> result = cc.doAction(1, 0);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::DEAD, ar);
}

TEST(LifeFixture, testConwayDoAction11) {
    ConwayCell cc(false);
    tuple<ActionResult, CellType> result = cc.doAction(2, 0);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::NOP, ar);
}

TEST(LifeFixture, testConwayDoAction12) {
    ConwayCell cc(false);
    tuple<ActionResult, CellType> result = cc.doAction(3, 0);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::ALIVE, ar);
}

TEST(LifeFixture, testConwayDoAction13) {
    ConwayCell cc(false);
    tuple<ActionResult, CellType> result = cc.doAction(4, 0);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::DEAD, ar);
}

TEST(LifeFixture, testConwayDoAction14) {
    ConwayCell cc(false);
    tuple<ActionResult, CellType> result = cc.doAction(5, 0);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::DEAD, ar);
}

TEST(LifeFixture, testConwayDoAction15) {
    ConwayCell cc(false);
    tuple<ActionResult, CellType> result = cc.doAction(6, 0);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::DEAD, ar);
}

TEST(LifeFixture, testConwayDoAction16) {
    ConwayCell cc(false);
    tuple<ActionResult, CellType> result = cc.doAction(7, 0);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::DEAD, ar);
}

TEST(LifeFixture, testConwayDoAction17) {
    ConwayCell cc(false);
    tuple<ActionResult, CellType> result = cc.doAction(8, 0);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::DEAD, ar);
}

TEST(LifeFixture, testFredkinOpConway1) {
    FredkinCell fc(true);
    ConwayCell cc(false);
    fc = cc;
    ASSERT_TRUE(fc.isAlive());
}

TEST(LifeFixture, testFredkinOpConway2) {
    FredkinCell fc(false);
    ConwayCell cc(true);
    fc = cc;
    ASSERT_FALSE(fc.isAlive());
}

TEST(LifeFixture, testFredkinClone1) {
    FredkinCell fc(true);
    AbstractCell *cell = fc.clone();
    ASSERT_TRUE(cell != nullptr);
    delete cell;
}

TEST(LifeFixture, testFredkinClone2) {
    FredkinCell fc(true);
    AbstractCell *cell = fc.clone();
    AbstractCell *cell2 = fc.clone();
    ASSERT_TRUE(cell != cell2);
    delete cell;
    delete cell2;
}

TEST(LifeFixture, testFredkinClone3) {
    FredkinCell fc(true);
    AbstractCell *cell = fc.clone();
    ASSERT_TRUE(cell->_alive);
    delete cell;
}

TEST(LifeFixture, testFredkinMutatable) {
    FredkinCell fc(true);
    ASSERT_EQ(CellType::FREDKIN, fc.mutatable());
}

TEST(LifeFixture, testFredkinDoAction0) {
    FredkinCell fc(true);
    tuple<ActionResult, CellType> result = fc.doAction(0, 0);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::DEAD, ar);
}

TEST(LifeFixture, testFredkinDoAction1) {
    FredkinCell fc(true);
    tuple<ActionResult, CellType> result = fc.doAction(0, 1);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::NOP, ar);
}

TEST(LifeFixture, testFredkinDoAction2) {
    FredkinCell fc(true);
    tuple<ActionResult, CellType> result = fc.doAction(0, 2);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::DEAD, ar);
}

TEST(LifeFixture, testFredkinDoAction3) {
    FredkinCell fc(true);
    tuple<ActionResult, CellType> result = fc.doAction(0, 3);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::NOP, ar);
}

TEST(LifeFixture, testFredkinDoAction4) {
    FredkinCell fc(true);
    tuple<ActionResult, CellType> result = fc.doAction(0, 4);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::DEAD, ar);
}

TEST(LifeFixture, testFredkinDoAction5) {
    FredkinCell fc(false);
    tuple<ActionResult, CellType> result = fc.doAction(0, 0);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::NOP, ar);
}

TEST(LifeFixture, testFredkinDoAction6) {
    FredkinCell fc(false);
    tuple<ActionResult, CellType> result = fc.doAction(0, 1);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::ALIVE, ar);
}

TEST(LifeFixture, testFredkinDoAction7) {
    FredkinCell fc(false);
    tuple<ActionResult, CellType> result = fc.doAction(0, 2);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::NOP, ar);
}

TEST(LifeFixture, testFredkinDoAction8) {
    FredkinCell fc(false);
    tuple<ActionResult, CellType> result = fc.doAction(0, 3);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::ALIVE, ar);
}

TEST(LifeFixture, testFredkinDoAction9) {
    FredkinCell fc(false);
    tuple<ActionResult, CellType> result = fc.doAction(0, 4);
    ActionResult ar = get<0>(result);
    ASSERT_EQ(ActionResult::NOP, ar);
}

TEST(LifeFixture, testFredkinDoAction10) {
    FredkinCell fc(true);
    tuple<ActionResult, CellType> result = fc.doAction(0, 1);
    result = fc.doAction(0, 1);
    CellType ct = get<1>(result);
    ASSERT_EQ(CellType::MUTATE, ct);
}

TEST(LifeFixture, testFredkinDoAction11) {
    FredkinCell fc(false);
    tuple<ActionResult, CellType> result = fc.doAction(0, 0);
    result = fc.doAction(0, 0);
    CellType ct = get<1>(result);
    ASSERT_EQ(CellType::FREDKIN, ct);
}

TEST(LifeFixture, testCellOpConway1) {
    ConwayCell cc(true);
    ConwayCell cc2(false);
    Cell temp(cc);
    temp = cc2;
    ASSERT_FALSE(temp.isAlive());
    delete temp._cell;
}

TEST(LifeFixture, testCellOpConway2) {
    ConwayCell cc(false);
    ConwayCell cc2(true);
    Cell temp(cc);
    temp = cc2;
    ASSERT_TRUE(temp.isAlive());
    delete temp._cell;
}

TEST(LifeFixture, testCellOpConway3) {
    ConwayCell cc(true);
    ConwayCell cc2(true);
    Cell temp(cc);
    temp = cc2;
    ASSERT_TRUE(temp.isAlive());
    delete temp._cell;
}

TEST(LifeFixture, testCellOpConway4) {
    ConwayCell cc(false);
    ConwayCell cc2(false);
    Cell temp(cc);
    temp = cc2;
    ASSERT_FALSE(temp.isAlive());
    delete temp._cell;
}

TEST(LifeFixture, testCellOpFredkin1) {
    FredkinCell fc(true);
    FredkinCell fc2(false);
    Cell temp(fc);
    temp = fc2;
    ASSERT_FALSE(temp.isAlive());
    delete temp._cell;
}

TEST(LifeFixture, testCellOpFredkin2) {
    FredkinCell fc(false);
    FredkinCell fc2(true);
    Cell temp(fc);
    temp = fc2;
    ASSERT_TRUE(temp.isAlive());
    delete temp._cell;
}

TEST(LifeFixture, testCellOpFredkin3) {
    FredkinCell fc(true);
    FredkinCell fc2(true);
    Cell temp(fc);
    temp = fc2;
    ASSERT_TRUE(temp.isAlive());
    delete temp._cell;
}

TEST(LifeFixture, testCellOpFredkin4) {
    FredkinCell fc(false);
    FredkinCell fc2(false);
    Cell temp(fc);
    temp = fc2;
    ASSERT_FALSE(temp.isAlive());
    delete temp._cell;
}

TEST(LifeFixture, testCellisAlive1) {
    ConwayCell cc(true);
    Cell temp(cc);
    ASSERT_TRUE(temp.isAlive());
    delete temp._cell;
}

TEST(LifeFixture, testCellisAlive2) {
    ConwayCell cc(false);
    Cell temp(cc);
    ASSERT_FALSE(temp.isAlive());
    delete temp._cell;
}

TEST(LifeFixture, testCellResurrect1) {
    ConwayCell cc(true);
    Cell temp(cc);
    temp.resurrect();
    ASSERT_TRUE(temp.isAlive());
    delete temp._cell;
}

TEST(LifeFixture, testCellResurrect2) {
    ConwayCell cc(false);
    Cell temp(cc);
    temp.resurrect();
    ASSERT_TRUE(temp.isAlive());
    delete temp._cell;
}

TEST(LifeFixture, testCellResurrect3) {
    ConwayCell cc(false);
    Cell temp(cc);
    temp.kill();
    temp.resurrect();
    ASSERT_TRUE(temp.isAlive());
    delete temp._cell;
}

TEST(LifeFixture, testCellKill1) {
    ConwayCell cc(true);
    Cell temp(cc);
    temp.kill();
    ASSERT_FALSE(temp.isAlive());
    delete temp._cell;
}

TEST(LifeFixture, testCellKill2) {
    ConwayCell cc(false);
    Cell temp(cc);
    temp.kill();
    ASSERT_FALSE(temp.isAlive());
    delete temp._cell;
}

TEST(LifeFixture, testCellKill3) {
    ConwayCell cc(false);
    Cell temp(cc);
    temp.resurrect();
    temp.kill();
    ASSERT_FALSE(temp.isAlive());
    delete temp._cell;
}

TEST(LifeFixture, testCellMutatable) {
    ConwayCell cc(true);
    Cell temp(cc);
    ASSERT_EQ(CellType::MUTATE, temp.mutatable());
    delete temp._cell;
}
