#pragma once
#include"Game.h"
#include<set>
#include<map>
class GameSolver
{
private :
	/*This function is the actual recursioin to get the shortest solution to the problem*/
	int static recursion_solver_helper(Game &g, std::vector<std::pair<int, int>> &moves, std::vector<std::pair<int, int>>& sols,std::set<Game> &visited,std::map<Game,int>&dp);
public:
	/*This function is responsible for getting the shortest solution to the problem*/
	static std::vector<std::pair<int, int>>  recursion_solve(Game g);
};

