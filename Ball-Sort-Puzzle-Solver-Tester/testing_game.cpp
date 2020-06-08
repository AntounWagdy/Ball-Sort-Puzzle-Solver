#include "gtest/gtest.h"
#include"../Ball-Sort-Puzzle-Solver/Game.h"

TEST(Testing_Game, exceptions) {
	EXPECT_ANY_THROW(Game g("../tests/invalid.txt"));
	EXPECT_ANY_THROW(Game g("../tests/notExist.txt"));
}

TEST(Testing_Game, test_initiate) {
	Game g("../tests/A4.txt");
	EXPECT_EQ(g.getNumTubes(), 4);
	g.print();
}


TEST(Testing_Game, move_test) {
	Game g("../tests/A4.txt");
	// wrong indeces
	EXPECT_FALSE(g.makeMove(4, 1));
	// full destination 
	EXPECT_FALSE(g.makeMove(0, 1));
	// empty source
	EXPECT_FALSE(g.makeMove(3, 1));
	// Move to empty
	EXPECT_TRUE(g.makeMove(1, 3));
	// Wrong match top of tubes
	EXPECT_FALSE(g.makeMove(1, 3));
	// Move to a true match
	EXPECT_TRUE(g.makeMove(2, 3));
	g.print();
}


TEST(Testing_Game, end_test) {
	Game g("../tests/A4.txt");
	EXPECT_FALSE(g.isEnd());
	
	int arr[] = { 
		0,
		1,3,
		2,3,
		0,3,
		2,3,
		0,2,
		1,0,
		1,2,
		0,1,
		0,1,
		2,0,
		2,0,
		2,0,
		2,1
	};
	for (int i = 1; i <= 13; i++)
	{
		EXPECT_FALSE(g.isEnd());
		EXPECT_TRUE(g.makeMove(arr[2*i - 1], arr[i*2]));
	}
	EXPECT_TRUE(g.isEnd());
}

TEST(Testing_Game, generate_moves_test) {
	Game g("../tests/A4.txt");
	std::vector<std::pair<int,int>> v =  g.generateValidMoves();
	std::pair<int, int> p[3] = { std::make_pair(0,3),std::make_pair(1,3) ,std::make_pair(2,3) };

	for (int i = 0 ; i <v.size();i++)
	{
		EXPECT_EQ(v[i], p[i]);
	}
	g.makeMove(1, 3);

	v = g.generateValidMoves();
	
	EXPECT_EQ(v[0], p[0]);
	EXPECT_EQ(v[1], p[2]);

	g.makeMove(p[0].first, p[0].second);
	g.makeMove(2,3);
	g.makeMove(2,3);

	v = g.generateValidMoves();
	EXPECT_EQ(v[0], std::make_pair(0, 2));
	EXPECT_EQ(v[1], std::make_pair(2, 0));
}
