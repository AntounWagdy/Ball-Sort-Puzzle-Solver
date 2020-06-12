#include "GameSolver.h"


std::set<Game> GameSolver::threaded_visited;
std::vector<std::pair<int, int>> GameSolver::threaded_soln;

int minfun(int x, int y) {
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
				_min = minfun(_min, recursion_solver_helper(temp, moves, sol, visited,dp));
				moves.pop_back();
				visited.erase(temp);
			}
		}
	}
	return dp[g] = 1 + _min;
}

void GameSolver::threaded_helper(void*d)
{
	threaded_struct* data = (threaded_struct*)d;
	//std::cout << "Createt thread with " << data->parent.getHash() << " " << data->current.getHash() << std::endl;
	std::queue<Game> gameQ;
	std::queue<std::vector<std::pair<int, int>>> pathQ;
	
	gameQ.push(data->current);
	pathQ.push(std::vector <std::pair<int, int>>());
	pathQ.front().push_back(data->first);
	

	Game currentG;
	std::vector<std::pair<int, int>> currentV;
	Game newG;
	std::vector<std::pair<int, int>> newV;
	std::vector<std::pair<int, int>> moves;
	bool found = false;
	while (!found && !gameQ.empty()) {
		currentG = gameQ.front();
		currentV = pathQ.front();
		gameQ.pop();
		pathQ.pop();
		moves = currentG.generateGoodValidMoves();
		for (size_t i = 0; i < moves.size(); i++)
		{
			newG = currentG;
			newV = currentV;
			newG.makeMove(moves[i].first, moves[i].second);
			newV.push_back(moves[i]);

			if (newG.isEnd() && (newV.size() < threaded_soln.size() || threaded_soln.empty())) {
				found = true;
				threaded_soln = newV;
				break;
			}

			if (!threaded_soln.empty()) {
				break;
			}
			if (threaded_visited.find(newG) == threaded_visited.end()) {
				threaded_visited.insert(newG);
				gameQ.push(newG);
				pathQ.push(newV);
			}
		}
	}
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

std::vector<std::pair<int, int>> GameSolver::iteration_solve(Game g)
{
	std::set<Game> visited;
	std::queue<Game> gameQ;
	std::queue<std::vector<std::pair<int,int>>> pathQ;
	gameQ.push(g);
	pathQ.push(std::vector < std::pair<int, int>>());
	
	Game currentG;
	std::vector<std::pair<int, int>> currentV;
	Game newG;
	std::vector<std::pair<int, int>> newV;
	std::vector<std::pair<int, int>> moves;
	bool found = false;
	while (!found) {
		currentG = gameQ.front();
		currentV = pathQ.front();
		gameQ.pop();
		pathQ.pop();
		moves = currentG.generateGoodValidMoves();
		for (size_t i = 0; i < moves.size(); i++)
		{
			newG = currentG;
			newV = currentV;
			newG.makeMove(moves[i].first, moves[i].second);
			newV.push_back(moves[i]);

			if (newG.isEnd()) {
				found = true;
				break;
			}

			if (visited.find(newG) == visited.end()) {
				visited.insert(newG);
				gameQ.push(newG);
				pathQ.push(newV);
			}
		}
	}
	return newV;
}

std::vector<std::pair<int, int>> GameSolver::threaded_iteration_solve(Game g)
{
	threaded_visited.clear();
	threaded_soln.clear();
	std::vector<std::pair<int,int>> moves = g.generateGoodValidMoves();
	HANDLE *handlers = new HANDLE[moves.size()];
	threaded_visited.insert(g);
	for (size_t i = 0; i < moves.size(); i++)
	{
		threaded_struct *data = new threaded_struct;
		data->current  = g;
		
		data->current.makeMove(moves[i].first, moves[i].second);
		data->first = moves[i];
		handlers[i] = (HANDLE)_beginthread(&threaded_helper, 0, data);
	}
	WaitForMultipleObjects(moves.size(), handlers, true, INFINITE);
	return threaded_soln;
}

std::vector<std::pair<int, int>> GameSolver::iteration_solve_with_heuristic(Game g)
{
	std::set<Game> visited;
	
	std::priority_queue<heuristic_struct> Qelements;
	Qelements.push({g,std::vector < std::pair<int, int>>() });

	heuristic_struct current;

	heuristic_struct newH;
	
	std::vector<std::pair<int, int>> moves;
	bool found = false;
	while (!found) {
		current = Qelements.top();
		Qelements.pop();
		moves = current.current.generateGoodValidMoves();
		for (size_t i = 0; i < moves.size(); i++)
		{
			newH = current;
			newH.current.makeMove(moves[i].first, moves[i].second);
			newH.path.push_back(moves[i]);

			if (newH.current.isEnd()) {
				found = true;
				break;
			}

			if (visited.find(newH.current) == visited.end()) {
				visited.insert(newH.current);
				Qelements.push(newH);
			}
		}
	}
	return newH.path;
}

bool operator<(const heuristic_struct& h1, const heuristic_struct& h2)
{
	return h1.current.getHeuristic() < h2.current.getHeuristic();
}
