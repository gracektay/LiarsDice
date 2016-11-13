/*
Grace Tay
IT-312 Software Development with C++.Net
10/9/2016
7-1 Final Project Submission: Dice Game

Summary:
Here, the game determines how many players there are and uses that information to ask each player their name. This is then used to output the player’s name 
and their respective dice. At the beginning, all of these dice are read out to the player. Then, the first player is asked for a guess as to how many dice 
are on the table, and of what value. People can then call liar, which then prompts the game to determine and print a winner, print out all the dice, and ends 
the game. After this is asked once, each time from then on is an increased guess of the number of dice on the table and a request for the side value roll, also 
reminding each player what the last player guessed.  Again, liar can be called at anytime which ends the game, determining a winner and printing out final values.
*/

#include "stdafx.h"
#include "Game.h"
#include "Dice.h"
#include "FileHandler.h"
#include <vector>
#include <string>
#include <iostream>

//Sets up a minimum number of 2 players and returns how many are playing.
int Game::determinePlayers() {
	cout << "____________________________________________________________________" << endl;
	cout << "Welcome to Liar's Dice!" << endl;
	cout << "____________________________________________________________________" << endl;
	cout << "How many players are playing today?" << endl;
	cin >> numOfPlayers;

	while (numOfPlayers < 2) {
		cout << "There must be two to play!" << endl;
		cin >> numOfPlayers;
	};

	cout << "There are " << numOfPlayers << " players." << endl;

	return numOfPlayers;
}

//Vector is used because there is no hardcoded number of players
vector<Player> Game::createVectorOfPlayers() {
	size_t size = determinePlayers();
	vector <Player> playerVector(size);

	for (unsigned int i = 0; i < size; ++i) {
		string playerName;
		cout << "Welcome Player " << i + 1 << ", what is your name?" << endl;
		cin >> playerName;
		Player p = Player(playerName);
		playerVector[i] = p;
	}

	return playerVector;
}

//Where everything comes together, this is the function that is called by main and allows for all functionality
void Game::play() {
	vector<Player> players;
	players = createVectorOfPlayers();
	bool checkLiar = false;

	size_t totalDiceonTable = (players.size() * 5);
	vector<vector<int>> fullDiceVector(totalDiceonTable);
	int a = players.size();
	int b = totalDiceonTable;

	//For each player, prints out the player's name and their five sets of dice
	for (unsigned int i = 0; i < players.size(); ++i) {
		Player player = players[i];
		cout << "Player " << player.identifyPlayer() << ". Here's your dice: " << endl;

		vector<int> playerRoll = player.roll();
		for (unsigned int j = 0; j < playerRoll.size(); ++j) {
			cout << "Dice result " << j + 1 << ": " << playerRoll[j] << endl;
		}
		fullDiceVector[i] = playerRoll;
	}

	cout << "____________________________________________________________________________" << endl;
	cout << "Now that everyone has seen their dice, let's play!" << endl;
	cout << "____________________________________________________________________________" << endl;

	guessedDiceOnTable = 0;
	bool endingLoop = false;
	while (endingLoop != true) { //Continues to loop until someone calls liar
		for (unsigned int i = 0; i < players.size(); ++i) { //For each player, state the round and ask for the respective score.
			Player player = players[i];
			cout << player.identifyPlayer() << ". Here's your dice: " << endl;
			vector<int> playerRoll = fullDiceVector[i];

			for (unsigned int j = 0; j < playerRoll.size(); ++j) {
				cout << "Disce result " << j + 1 << ": " << playerRoll[j] << endl;
			}

			if (guessedDiceOnTable == 0) { //Called once to get the initial guess of dice on table, and the side value, asks if you want to call liar and ends game with full Dice output
				guessedDiceOnTable = player.guessNumberDiceTable(a, b);
				guessedDiceSideValue = player.guessDiceSideValue(guessedDiceOnTable);
				checkLiar = liar(fullDiceVector, guessedDiceSideValue, guessedDiceOnTable);
				if (checkLiar == true) {
					endingLoop = finalOutputEndLoop(endingLoop, a, fullDiceVector);
					break;
				}
			}
			else { //called rest of time, gets the increased guess of dice on table, side value, asks if you want to call liar and ends game with full dice output
				guessedDiceOnTable = player.increaseTableQuantityGuess(guessedDiceOnTable, b, guessedDiceSideValue);
				guessedDiceSideValue = player.guessDiceSideValue(guessedDiceOnTable);
				checkLiar = liar(fullDiceVector, guessedDiceSideValue, guessedDiceOnTable);
				if (checkLiar == true) {
					endingLoop = finalOutputEndLoop(endingLoop, a, fullDiceVector);	
					break;
				}
			}
		}
	}
}

//Function asks if anyone calls Liar. If someone does call Liar, checks to see who won and allows the game to conclue
bool Game::liar(vector<vector<int>> a, int b, int c) { //a == numberOfDiceOnTable b == guessDiceSideValue
	bool liarIsTrue = false;
	string calledLiar;

	cout << "Does anyone want to call liar? Type Y for yes or N for no" << endl;
	cin >> calledLiar;

	if (calledLiar == "Y" || calledLiar == "y") {
		int occurences = howManyIn(a, b);

		if (occurences != c) {
			cout << "You (the guesser) are wrong, you liar! Accuser, you win!" << endl;
		}
		else {
			cout << "The player did not lie in their guess and wins, you (the accuser) are wrong and lose." << endl;
		}
		liarIsTrue = true;
	}

	return liarIsTrue;
}

//This function checks how many dice are of a certain value
int Game::howManyIn(vector<vector<int>> fullDice, int value) {
	int count = 0;
	for (unsigned int i = 0; i < fullDice.size(); ++i) {
		vector<int> innerRoll = fullDice[i];
		for (unsigned int j = 0; j < innerRoll.size(); ++j) {
			if (innerRoll[j] == value) {
				++count;
			}
		}
	}
	return count;
}

//This function allows the dice to be printed at the end of the game
bool Game::finalOutputEndLoop(bool a, int b, vector<vector<int>> c) {
	//a -> endingLoop, b -> number of players, c ->fullDiceVector

	cout << "Let's see all the dice:" << endl;
	for (int i = 0; i < b; ++i) {
		vector<int> rolls = c[i];
		for (unsigned int j = 0; j < (rolls.size() - 1); ++j) {
			cout << c[i][j] << ", ";
		}
		cout << rolls.back() << endl;
	}
	a = true;

	return a;
}