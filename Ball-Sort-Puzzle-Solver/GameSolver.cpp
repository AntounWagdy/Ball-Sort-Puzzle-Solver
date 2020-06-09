#include "GameSolver.h"

void GameSolver::solver_helper(Game &g, std::vector<std::pair<int, int>>& moves, std::vector<std::vector<std::pair<int, int>>>& sols, std::vector<Game> &visited)
{

	if (moves.size() > 20) {
		return;
	}
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
		if (find(visited.begin(),visited.end(),temp) == visited.end()) {
			visited.push_back(temp);
			moves.push_back(std::make_pair(vec[i].first, vec[i].second));
			solver_helper(temp, moves, sols,visited);
			moves.pop_back();
		}
	}
}

std::vector<std::vector<std::pair<int, int>>> GameSolver::Solve(Game g)
{
	std::vector<std::pair<int, int>> moves;
	std::vector<std::vector<std::pair<int, int>>> sols;
	std::vector<Game> visited;
	solver_helper(g,moves,sols,visited);
	return sols;
}
