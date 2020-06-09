#pragma once
#include"Game.h"
#include<set>
class GameSolver
{
private :
	void static solver_helper(Game &g, std::vector<std::pair<int, int>> &moves, std::vector<std::vector<std::pair<int, int>>>& sols,std::vector<Game> &visited);
public:
	static std::vector<std::vector<std::pair<int, int>>>  Solve(Game g);
};

