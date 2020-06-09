#include "GameSolver.h"

// we may need to add dp 
void GameSolver::recursion_solver_helper(Game &g, std::vector<std::pair<int, int>>& moves, std::vector<std::pair<int, int>>& sol, std::set<Game> &visited)
{
	if (moves.size() > sol.size() && !sol.empty() ) {
		return;
	}

	if (g.isEnd()) {
		sol = moves;
		return;
	}
	std::vector<std::pair<int, int>> vec = g.generateValidMoves();
	Game temp;
	for (size_t i = 0; i < vec.size(); i++)
	{
		temp = g;
		temp.makeMove(vec[i].first, vec[i].second);
		if (visited.find(temp) == visited.end()) {
			visited.insert(temp);
			moves.push_back(std::make_pair(vec[i].first, vec[i].second));
			recursion_solver_helper(temp, moves, sol,visited);
			moves.pop_back();
			visited.erase(temp);
		}
	}
}

std::vector<std::pair<int, int>> GameSolver::recursion_solve(Game g)
{
	std::vector<std::pair<int, int>> moves;
	std::vector<std::pair<int, int>> sol;
	std::set<Game> visited;
	recursion_solver_helper(g,moves,sol,visited);
	return sol;
}
