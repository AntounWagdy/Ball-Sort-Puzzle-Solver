#include "GameSolver.h"

void GameSolver::recursion_solver_helper(Game &g, std::vector<std::pair<int, int>>& moves, std::vector<std::vector<std::pair<int, int>>>& sols, std::set<Game> &visited)
{
	if (g.isEnd()) {
		sols.push_back(moves);
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
			recursion_solver_helper(temp, moves, sols,visited);
			moves.pop_back();
		}
	}
}

std::vector<std::vector<std::pair<int, int>>> GameSolver::recursion_solve(Game g)
{
	std::vector<std::pair<int, int>> moves;
	std::vector<std::vector<std::pair<int, int>>> sols;
	std::set<Game> visited;
	recursion_solver_helper(g,moves,sols,visited);
	return sols;
}
