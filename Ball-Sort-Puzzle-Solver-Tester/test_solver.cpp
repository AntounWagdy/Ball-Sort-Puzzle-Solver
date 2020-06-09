#include "gtest/gtest.h"
#include"../Ball-Sort-Puzzle-Solver/GameSolver.h"

// 22,198 for this funciton to end => 2.2 seconds in this function to finish one easy level 
TEST(Testing_Game_sovler, Recursion_Simple) {
	for (int k = 0; k < 10; k++)
	{
		Game g("../tests/L"+std::to_string(k+1)+".txt");
		//g.print();
		auto res = GameSolver::recursion_solve(g);
		std::cout << res.size() << std::endl;
		for (size_t i = 0; i < res.size(); i++)
		{
			Game temp("../tests/L" + std::to_string(k + 1) + ".txt");
			for (size_t j = 0; j < res[i].size(); j++)
			{
				//std::cout << res[i][j].first << " " << res[i][j].second << std::endl;
				temp.makeMove(res[i][j].first, res[i][j].second);
			}
			EXPECT_TRUE(temp.isEnd());
			//std::cout << std::endl;
		}
			std::cout << "Test L" << k + 1 << " is finished." << std::endl;

	}
}


TEST(Testing_Game_sovler, Recursion_advanced) {
	for (int k = 0; k < 10; k++)
	{
		Game g("../tests/L5" + std::to_string(k + 1) + ".txt");
		//g.print();
		auto res = GameSolver::recursion_solve(g);

		for (size_t i = 0; i < res.size(); i++)
		{
			Game temp("../tests/L5" + std::to_string(k + 1) + ".txt");
			for (size_t j = 0; j < res[i].size(); j++)
			{
				//std::cout << res[i][j].first << " " << res[i][j].second << std::endl;
				temp.makeMove(res[i][j].first, res[i][j].second);
			}
			EXPECT_TRUE(temp.isEnd());
			//std::cout << std::endl;
		}
		std::cout << "Test L5" << k + 1 << " is finished." << std::endl;

	}
}
