#pragma once
#include"Game.h"
#include<set>
class GameSolver
{
private :
	void static recursion_solver_helper(Game &g, std::vector<std::pair<int, int>> &moves, std::vector<std::vector<std::pair<int, int>>>& sols,std::set<Game> &visited);
public:
	static std::vector<std::vector<std::pair<int, int>>>  recursion_solve(Game g);
};

