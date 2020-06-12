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

	while (std::getline(f, line))
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
		for (int i = j - 1; i >= 0; i--)
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

std::vector<std::pair<int, int>> Game::generateGoodValidMoves()
{
	std::vector<std::pair<int, int>> vec;
	bool isH1, isH2;

	for (size_t i = 0; i < tubes.size(); i++)
	{
		for (size_t j = 0; j < tubes.size(); j++)
		{
			isH1 = tubes[i].isHomogenous();
			isH2 = tubes[j].isHomogenous();

			// by adding the condition after the first condition, we generate only the good moves
			if (i != j &&
				isValidMove(i, j) && // check if valid move
				!(isH1 && tubes[j].isEmpty()) &&
				!(isH1 && isH2 && tubes[i].size() > tubes[j].size()) &&
				!(tubes[i].isFull() && isH1) // don't move from full and homogenous tube
				) {
				vec.push_back(std::make_pair(i, j));
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


long long Game::getHash() {
	return hash;
}

int Game::getHeuristic() const
{
	int score = 0;
	Tube temp;
	char c2,c1;
	int cnt = 1;
	for (size_t i = 0; i < tubes.size(); i++)
	{
		if (tubes[i].isEmpty()) {
			score += 10;
		}
		else {
			temp = tubes[i];
			temp.pop(c1);
			while (!temp.isEmpty()) {
				temp.pop(c2);
				if (c1 == c2) {
					cnt++;
				}
				else {
					c1 = c2;
					cnt = 1;
				}
			}
			score += (5 * cnt);
		}
	}
	return score;
}
