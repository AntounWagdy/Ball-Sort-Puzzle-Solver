#include "GameSolver.h"

int min(int x, int y) {
	if (x < y) {
		return x;
	}
	return y;
}

// we may need to add dp 
int GameSolver::recursion_solver_helper(Game &g, std::vector<std::pair<int, int>>& moves, std::vector<std::pair<int, int>>& sol, std::set<Game> &visited, std::map<Game, int>& dp)
{
	if (moves.size() > sol.size() && !sol.empty()) {
		return 1e9;
	}

	if (g.isEnd()) {
		sol = moves;
		return dp[g] = 0;
	}
	int _min = 1e9;

	std::vector<std::pair<int, int>> vec = g.generateGoodValidMoves();
	Game temp;
	for (size_t i = 0; i < vec.size(); i++)
	{
		temp = g;
		temp.makeMove(vec[i].first, vec[i].second);
		if (visited.find(temp) == visited.end()) {
			if (dp.find(temp) == dp.end() || (dp.find(temp) != dp.end() && moves.size() + dp[temp] < sol.size()))
			{
				visited.insert(temp);
				moves.push_back(std::make_pair(vec[i].first, vec[i].second));
				_min = min(_min, recursion_solver_helper(temp, moves, sol, visited,dp));
				moves.pop_back();
				visited.erase(temp);
			}
		}
	}
	return dp[g] = 1 + _min;
}

std::vector<std::pair<int, int>> GameSolver::recursion_solve(Game g)
{
	std::vector<std::pair<int, int>> moves;
	std::vector<std::pair<int, int>> sol;
	std::set<Game> visited;
	std::map<Game, int> dp;
	recursion_solver_helper(g,moves,sol,visited,dp);
	return sol;
}
