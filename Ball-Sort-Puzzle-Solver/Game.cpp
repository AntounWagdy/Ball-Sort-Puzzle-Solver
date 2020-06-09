#include "Game.h"

Game::Game(std::string filename) : p(31), m(1e9 + 9)
{
	std::ifstream f(filename);
	if (!f) {
		throw std::exception("Input file not found.");
	}
	// hashing variables
	long long p_pow = 1;
	hash = 0;


	int num;
	std::string line;
	int counters[255];
	memset(counters, 0, 255 * sizeof(int));
	int ind = 0;

	f >> num;
	this->tubes.resize(num);

	std::getline(f, line); // ignore this line
	
	while(std::getline(f, line))
	{
		for (size_t j = 0; j < line.size(); j++)
		{
			line[j] = std::toupper(line[j]);
			tubes[ind].push(line[j]);
			counters[line[j]]++;
			hash = (hash + (line[j] - 'A' - 1) * p_pow) % m;
			p_pow = (p_pow * p) % m;
		}
		ind++;
	}
	f.close();
	for (int i = 0; i < 255; i++)
	{
		if (counters[i] != 0 && counters[i] != 4) {
			throw std::exception("Invalid input file.");
		}
	}
}

bool Game::isValidMove(int s, int e)
{
	if (s < 0 || e < 0 || s >= tubes.size() || e >= tubes.size()) {
		return false;
	}
	if (!tubes[s].isEmpty()) {
		if (tubes[e].isEmpty()) {
			return true;
		}
		if (tubes[e].isFull()) {
			return false;
		}
		if (tubes[s].top() == tubes[e].top()) {
			return true;
		}
	}
	return false;
}

bool Game::makeMove(int s, int e)
{
	if (!isValidMove(s, e)) {
		return false;
	}

	// hashing variables
	long long p_pow = 1;

	// remove the moving charcter from the hash
	// p_pow ^ index of the charcter 
	for (int i = 0; i < s * 4 + tubes[s].size(); i++) {
		p_pow = (p_pow * p) % m;
	}
	hash = (hash - (tubes[s].top() - 'A' + 1) * p_pow) % m;
	hash = (hash + m) % m;

	p_pow = 1;
	// add the moving charcter to the hash with the new value
	// p_pow ^ index of the charcter 
	for (int i = 0; i < e * 4 + tubes[e].size() + 1; i++) {
		p_pow = (p_pow * p) % m;
	}
	hash = (hash + (tubes[s].top() - 'A' + 1) * p_pow) % m;


	Ball b;
	tubes[s].pop(b);
	tubes[e].push(b);
	return true;
}

bool Game::isEnd()
{
	for (size_t i = 0; i < tubes.size(); i++)
	{
		if ((!tubes[i].isFull() || !tubes[i].isHomogenous()) && !tubes[i].isEmpty()) {
			return false;
		}
	}
	return true;
}



void Game::print()
{
	Tube temp;
	Ball b;
	char current[TUBESIZE];
	int j;
	for (size_t i = 0; i < tubes.size(); i++)
	{
		std::cout << "# ";
		// copy into temp
		temp = tubes[i];
		j = 0;
		while (!temp.isEmpty()) {
			temp.pop(b);
			current[j++] = b;
		}
		for (int i = j-1; i >= 0; i--)
		{
			std::cout << current[i];
		}
		std::cout << std::endl;
	}
}

int Game::getNumTubes()
{
	return tubes.size();
}

std::vector<std::pair<int, int>> Game::generateValidMoves()
{
	std::vector<std::pair<int, int>> vec;
	for (size_t i = 0; i < tubes.size(); i++)
	{
		for (size_t j = 0; j < tubes.size(); j++)
		{
			// by adding the condition after the first condition, we generate only the good moves
			if (i != j && !(tubes[i].isFull() && tubes[i].isHomogenous())) {
				if (this->isValidMove(i, j) && !(tubes[i].isHomogenous() && tubes[j].isEmpty())) {
					vec.push_back(std::make_pair(i, j));
				}
			}
		}
	}
	return vec;
}

bool Game::operator==(const Game& g)
{
	for (size_t i = 0; i < tubes.size(); i++)
	{
		if (tubes[i] != g.tubes[i]) {
			return false;
		}
	}
	return true;
}

bool Game::operator<(const Game& g) const
{
	return this->hash < g.hash;
}


int Game::getHash() {
	return hash;
}
