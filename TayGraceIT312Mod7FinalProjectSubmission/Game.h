/*
Grace Tay
IT-312 Software Development with C++.Net
10/9/2016
7-1 Final Project Submission: Dice Game

Summary:
Header for Game class
*/

#pragma once

#include <iostream>
#include <vector>
#include "Player.h"
#include "Dice.h"

using namespace std;

class Game {
private:
	vector<Player> vectorPlayers;
	vector<Player> createVectorOfPlayers();
	int howManyIn(vector<vector<int>> fullDice, int value);
	bool liar(vector<vector<int>> a, int b, int c);
	int guessedDiceSideValue;
	int guessedDiceOnTable;
	string name;
	bool finalOutputEndLoop(bool a, int b, vector<vector<int>> d);

public:
	void appendFile(Player player);
	int determinePlayers();
	int numOfPlayers;
	void play();
};