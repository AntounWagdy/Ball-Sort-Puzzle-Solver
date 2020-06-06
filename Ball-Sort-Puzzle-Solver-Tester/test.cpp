#include "gtest/gtest.h"
#include"../Ball-Sort-Puzzle-Solver/Tube.h"

TEST(Testing_Tube, EmptyTube) {
	Tube t;
	Ball b;
	EXPECT_EQ(t.isEmpty(), true);
	EXPECT_EQ(t.isFull(), false);
	EXPECT_EQ(t.pop(b), false);
}

TEST(Testing_Tube, OneElementTube) {
	Tube t;
	Ball b = 'R';
	EXPECT_EQ(t.push(b), true);
	EXPECT_EQ(t.isEmpty(), false);
	EXPECT_EQ(t.isFull(), false);
	
	EXPECT_EQ(t.top(), b);
	EXPECT_EQ(t.pop(b), true);
	EXPECT_EQ(b, 'R');
}


TEST(Testing_Tube, FullTube) {
	Tube t;
	Ball b = 'R';
	EXPECT_EQ(t.push(b), true);
	EXPECT_EQ(t.push(b), true);
	EXPECT_EQ(t.push(b), true);
	EXPECT_EQ(t.push(b), true);

	EXPECT_EQ(t.isEmpty(), false);
	EXPECT_EQ(t.isFull(), true);
	EXPECT_EQ(t.pop(b), true);
}


TEST(Testing_Tube, TestingHomogenous) {
	Tube t;
	Ball b = 'R';
	EXPECT_EQ(t.push(b), true);
	EXPECT_EQ(t.push(b), true);
	EXPECT_EQ(t.push(b), true);
	EXPECT_EQ(t.push(b), true);

	EXPECT_EQ(t.isHomogenous(), true);
	EXPECT_EQ(t.pop(b), true);
	EXPECT_EQ(t.push('A'), true);
	EXPECT_EQ(t.isHomogenous(), false);
}
