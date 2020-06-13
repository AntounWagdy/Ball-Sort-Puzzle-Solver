#include "gtest/gtest.h"
#include"../Ball-Sort-Puzzle-Solver/GameSolver.h"
//
//// 99231 ms for this funciton to end => on average 9.9 seconds in this function to finish one easy level (Debug mode)
//// 4496 ms for this funciton to end => on average .4 seconds in this function to finish one easy level (Release mode)
//TEST(Testing_Game_sovler, Recursion_Simple) {
//	for (int k = 0; k < 10; k++)
//	{
//		Game g("../tests/L"+std::to_string(k+1)+".txt");
//		//g.print();
//		auto res = GameSolver::recursion_solve(g);
//		std::cout << res.size() << std::endl;
//
//		Game temp("../tests/L" + std::to_string(k + 1) + ".txt");
//		for (size_t j = 0; j < res.size(); j++)
//		{
//			//std::cout << res[i][j].first << " " << res[i][j].second << std::endl;
//			temp.makeMove(res[j].first, res[j].second);
//		}
//		EXPECT_TRUE(temp.isEnd());
//		//std::cout << std::endl;
//		std::cout << "Test L" << k + 1 << " is finished." << std::endl;
//
//	}
//}
//
//// 287033 ms for this funciton to end => on average 28.7 seconds in this function to finish one easy level (Release mode)
//TEST(Testing_Game_sovler, Recursion_advanced) {
//	for (int k = 0; k < 9; k++)
//	{
//		Game g("../tests/L5" + std::to_string(k + 1) + ".txt");
//		//g.print();
//		auto res = GameSolver::recursion_solve(g);
//		std::cout << res.size() << std::endl;
//
//		Game temp("../tests/L5" + std::to_string(k + 1) + ".txt");
//		for (size_t j = 0; j < res.size(); j++)
//		{
//			//std::cout << res[i][j].first << " " << res[i][j].second << std::endl;
//			temp.makeMove(res[j].first, res[j].second);
//		}
//		EXPECT_TRUE(temp.isEnd());
//			//std::cout << std::endl;
//		std::cout << "Test L5" << k + 1 << " is finished." << std::endl;
//
//	}
//}
//
///*
//10
//Test L1 is finished.
//11
//Test L2 is finished.
//11
//Test L3 is finished.
//18
//Test L4 is finished.
//15
//Test L5 is finished.
//15
//Test L6 is finished.
//19
//Test L7 is finished.
//20
//Test L8 is finished.
//25
//Test L9 is finished.
//26
//Test L10 is finished.
//
//[       OK ] Testing_Game_sovler.Recursion_Simple (7546 ms)
//[ RUN      ] Testing_Game_sovler.Recursion_advanced
//
//26
//Test L51 is finished.
//38
//Test L52 is finished.
//36
//Test L53 is finished.
//29
//Test L54 is finished.
//29
//Test L55 is finished.
//37
//Test L56 is finished.
//24
//Test L57 is finished.
//37
//Test L58 is finished.
//35
//Test L59 is finished.
//*/
//
//
//
//
//// 6132 ms for this funciton to end => on average 0.6 seconds in this function to finish one easy level 
//TEST(Testing_Game_sovler, iteration_Simple) {
//	for (int k = 0; k < 10; k++)
//	{
//		Game g("../tests/L" + std::to_string(k + 1) + ".txt");
//		//g.print();
//		auto res = GameSolver::iteration_solve(g);
//		std::cout << res.size() << std::endl;
//
//		Game temp("../tests/L" + std::to_string(k + 1) + ".txt");
//		for (size_t j = 0; j < res.size(); j++)
//		{
//			//std::cout << res[i][j].first << " " << res[i][j].second << std::endl;
//			temp.makeMove(res[j].first, res[j].second);
//		}
//		EXPECT_TRUE(temp.isEnd());
//		//std::cout << std::endl;
//		std::cout << "Test L" << k + 1 << " is finished." << std::endl;
//
//	}
//}

// 517209 ms for this funciton to end => on average 51.7 seconds in this function to finish one easy level (Release mode)
//TEST(Testing_Game_sovler, iteration_advanced) {
//	for (int k = 0; k < 9; k++)
//	{
//		Game g("../tests/L5" + std::to_string(k + 1) + ".txt");
//		//g.print();
//		auto res = GameSolver::iteration_solve(g);
//		std::cout << res.size() << std::endl;
//
//		Game temp("../tests/L5" + std::to_string(k + 1) + ".txt");
//		for (size_t j = 0; j < res.size(); j++)
//		{
//			//std::cout << res[i][j].first << " " << res[i][j].second << std::endl;
//			temp.makeMove(res[j].first, res[j].second);
//		}
//		EXPECT_TRUE(temp.isEnd());
//			//std::cout << std::endl;
//		std::cout << "Test L5" << k + 1 << " is finished." << std::endl;
//
//	}
//}

// 72050 ms for this funciton to end => on average 7.2 seconds in this function to finish one easy level (Debug mode)
// 1808 ms for this funciton to end => on average 0.1 seconds in this function to finish one easy level (Release mode)
//TEST(Testing_Game_sovler, threaded_simple) {
//	for (int k = 0; k < 10; k++)
//	{
//		Game g("../tests/L" + std::to_string(k + 1) + ".txt");
//		//g.print();
//		auto res = GameSolver::threaded_iteration_solve(g);
//		std::cout << res.size() << std::endl;
//
//		Game temp("../tests/L" + std::to_string(k + 1) + ".txt");
//		for (size_t j = 0; j < res.size(); j++)
//		{
//			//std::cout << res[i][j].first << " " << res[i][j].second << std::endl;
//			temp.makeMove(res[j].first, res[j].second);
//		}
//		EXPECT_TRUE(temp.isEnd());
//		//std::cout << std::endl;
//		std::cout << "Test L" << k + 1 << " is finished." << std::endl;
//
//
//	}
//}
//
//// 158442 ms for this funciton to end => on average 18 seconds in this function to finish one advanced level (Release mode)
//TEST(Testing_Game_sovler, threaded_advanced) {
//	for (int k = 0; k < 9; k++)
//	{
//		Game g("../tests/L5" + std::to_string(k + 1) + ".txt");
//		//g.print();
//		auto res = GameSolver::threaded_iteration_solve(g);
//		std::cout << res.size() << std::endl;
//
//		Game temp("../tests/L5" + std::to_string(k + 1) + ".txt");
//		for (size_t j = 0; j < res.size(); j++)
//		{
//			//std::cout << res[i][j].first << " " << res[i][j].second << std::endl;
//			temp.makeMove(res[j].first, res[j].second);
//		}
//		EXPECT_TRUE(temp.isEnd());
//		//std::cout << std::endl;
//		std::cout << "Test L5" << k + 1 << " is finished." << std::endl;
//
//
//	}
//}


 // 843 ms for this funciton to end => on average 0.08 seconds in this function to finish one easy level (Debug mode)
 // 34 ms for this funciton to end => on average 0.003 seconds in this function to finish one easy level (Release mode)
TEST(Testing_Game_sovler, heurstic_simple) {
	for (int k = 0; k < 10; k++)
	{
		Game g("../tests/L" + std::to_string(k + 1) + ".txt");
		//g.print();
		auto res = GameSolver::iteration_solve_with_heuristic(g);
		std::cout << res.size() << std::endl;

		Game temp("../tests/L" + std::to_string(k + 1) + ".txt");
		for (size_t j = 0; j < res.size(); j++)
		{
			//std::cout << res[i][j].first << " " << res[i][j].second << std::endl;
			temp.makeMove(res[j].first, res[j].second);
		}
		EXPECT_TRUE(temp.isEnd());
		//std::cout << std::endl;
		std::cout << "Test L" << k + 1 << " is finished." << std::endl;


	}
}


// 1136 ms for this funciton to end => on average 0.1 seconds in this function to finish one easy level (debug mode)
// 57 ms for this funciton to end => on average 0.005 seconds in this function to finish one easy level (Release mode)
TEST(Testing_Game_sovler, heurstic_advanced) {
	for (int k = 0; k < 9; k++)
	{
		Game g("../tests/L5" + std::to_string(k + 1) + ".txt");
		//g.print();
		auto res = GameSolver::iteration_solve_with_heuristic(g);
		std::cout << res.size() << std::endl;

		Game temp("../tests/L5" + std::to_string(k + 1) + ".txt");
		for (size_t j = 0; j < res.size(); j++)
		{
			//std::cout << res[i][j].first << " " << res[i][j].second << std::endl;
			temp.makeMove(res[j].first, res[j].second);
		}
		EXPECT_TRUE(temp.isEnd());
		//std::cout << std::endl;
		std::cout << "Test L5" << k + 1 << " is finished." << std::endl;
	}
}

// l second (WOW !)
TEST(Testing_Game_sovler, heurstic_advanced_level_275) {
	Game g("../tests/L275.txt");
	//g.print();
	auto res = GameSolver::iteration_solve_with_heuristic(g);
	std::cout << res.size() << std::endl;

	Game temp("../tests/L275.txt");
	for (size_t j = 0; j < res.size(); j++)
	{
		//std::cout << res[i][j].first << " " << res[i][j].second << std::endl;
		temp.makeMove(res[j].first, res[j].second);
	}
	EXPECT_TRUE(temp.isEnd());
	//std::cout << std::endl;
	std::cout << "Test L275 is finished." << std::endl;
}