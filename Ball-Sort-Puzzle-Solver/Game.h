#pragma once
#include"Tube.h"
#include<vector>
#include<fstream>
#include<string>
#include<exception>
#include<iostream>

class Game
{
private:
	std::vector<Tube> tubes;
	long long int hash;
	// hashing constants
	int p;
	int m;

public:
	Game() : p(31),m(1e9+9) { hash = 0; }
	// initiate game from file and throw exception if the file is wrong formatted
	Game(std::string filename);
	// returns true if the move is a valid move
	bool isValidMove(int s, int e);
	// do the move and return false if not valid.
	bool makeMove(int s, int e);
	// return true if the game has ended.
	bool isEnd();
	// print the current status of the game.
	void print();
	// return the number of the tubes
	int getNumTubes();
	// generate all valid moves
	std::vector<std::pair<int, int>> generateGoodValidMoves();

	// operator ==
	bool operator==(const Game& g);

	// opertor <
	bool operator<(const Game& g) const;

	// get hash value
	long long getHash();
};

