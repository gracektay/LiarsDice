/*
Grace Tay
IT-312 Software Development with C++.Net
10/9/2016
7-1 Final Project Submission: Dice Game

Summary:
Header for Player class.

*/

#pragma once
#include <string>
#include <iostream>
#include "Dice.h"
#include <vector>

using namespace std;

class Player {
private:
	string playerName;
	Dice dice1 = Dice();
	Dice dice2 = Dice();
	Dice dice3 = Dice();
	Dice dice4 = Dice();
	Dice dice5 = Dice();

public:
	int playerScore;
	int numOfDiceOnTable;
	int guessedNumberDiceTable;
	int guessNumberDiceTable(int a, int b);
	int guessDiceSideValue(int a);
	int increaseTableQuantityGuess(int a, int b, int c);
	Player();
	Player(string name);
	string identifyPlayer();
	vector<int> roll();
};