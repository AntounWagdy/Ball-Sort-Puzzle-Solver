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
public:
	// initiate game from file and throw exception if the file is wrong formatted
	Game(std::string filename);
	// returns true if the move is a valid move
	bool isValidMove(int s, int e);
	// do the move and return false if not valid.
	bool move(int s, int e);
	// return true if the game has ended.
	bool isEnd();
	// print the current status of the game.
	void print();
	// return the number of the tubes
	int getNumTubes();
};

