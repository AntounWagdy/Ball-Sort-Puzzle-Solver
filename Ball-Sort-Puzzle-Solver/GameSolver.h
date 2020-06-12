#pragma once
#include"Game.h"
#include<set>
#include<map>
#include<queue>
#include<Windows.h>
#include<process.h>
#include<stdio.h>
#include<stdlib.h>

struct threaded_struct {
	Game current;
	std::pair<int, int>first;

};
class GameSolver
{
private :
	static std::set<Game> threaded_visited;
	static std::vector<std::pair<int, int>> threaded_soln;

	/*This function is the actual recursioin to get the shortest solution to the problem*/
	int static recursion_solver_helper(Game &g, std::vector<std::pair<int, int>> &moves, std::vector<std::pair<int, int>>& sols,std::set<Game> &visited,std::map<Game,int>&dp);
	void static threaded_helper(void*data);
public:
	/*This function is responsible for getting the shortest solution to the problem using recursion*/
	static std::vector<std::pair<int, int>>  recursion_solve(Game g);
	static std::vector<std::pair<int, int>>  iteration_solve(Game g);
	static std::vector<std::pair<int, int>>  threaded_iteration_solve(Game g);



};

