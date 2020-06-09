#include "gtest/gtest.h"
#include"../Ball-Sort-Puzzle-Solver/GameSolver.h"

TEST(Testing_Game_sovler, Test1) {
	Game g("../tests/A4.txt");
	g.print();
	auto res = GameSolver::Solve(g);
	for (size_t i = 0; i < res.size(); i++)
	{
		Game temp("../tests/A4.txt");
		for (size_t j = 0; j < res[i].size(); j++)
		{
			//std::cout << res[i][j].first << " " << res[i][j].second << std::endl;
			temp.makeMove(res[i][j].first, res[i][j].second);
		}
		EXPECT_TRUE(temp.isEnd());
		//std::cout << std::endl;
	}
}


TEST(Testing_Game_sovler, Test2) {
	Game g("../tests/A11.txt");
	g.print();
	auto res = GameSolver::Solve(g);
	
	for (size_t i = 0; i < res.size(); i++)
	{
		Game temp("../tests/A11.txt");
		for (size_t j = 0; j < res[i].size(); j++)
		{
			std::cout << res[i][j].first << " " << res[i][j].second << std::endl;
			temp.makeMove(res[i][j].first, res[i][j].second);
		}
		EXPECT_TRUE(temp.isEnd());
		std::cout << std::endl;
	}
}
