/*
Grace Tay
IT-312 Software Development with C++.Net
10/9/2016
7-1 Final Project Submission: Dice Game

Summary:
The Player class gets the player name, creates a vector of five dice for each player (getting the function from Dice class), and obtains a guess of
how many dice are on the table and guesses what side these dice were rolled.
*/

#include "stdafx.h"
#include "Player.h"
#include "Dice.h"
#include "Game.h"
#include <vector>
#include <iostream>

using namespace std;
Player::Player() {
	playerName = "";
}

Player::Player(string name) {
	playerName = name;
}

//Gets player name
string Player::identifyPlayer() {
	return playerName;
}

//Creates a vector of five dice for each player, getting the function from Dice
vector<int> Player::roll() {
	int one = dice1.randomlyRoll();
	int two = dice2.randomlyRoll();
	int three = dice3.randomlyRoll();
	int four = dice4.randomlyRoll();
	int five = dice5.randomlyRoll();

	return vector<int> { one, two, three, four, five };
}

//Called once to see what the first guess is to how many dice are on table
int Player::guessNumberDiceTable(int a, int b) {
	cout << "There are " << a << " players. This means there are " << b << " dice on the table." << endl;
	cout << "Remember, for this game you will need to input two values: (1) how many dice on the table are of a (2) certain value. " << endl;
	cout << "Input the first value, the number of dice on the table: " << endl;
	cin >> numOfDiceOnTable;

	while (numOfDiceOnTable < 1 || numOfDiceOnTable > b) {
		cout << "The only possible number of dice on the table is 1 to " << b << "." << endl;
		cin >> numOfDiceOnTable;
	}

	return numOfDiceOnTable;
}

//After an inital dice number guess is made, this increases the guess of dice on the table
int Player::increaseTableQuantityGuess(int a, int b, int c) {
	int increasedGuess;
	cout << "The last player guessed " << a << " dice on the table were rolled on the side value of " << c << endl;
	cout << "Your new guess must be at least one dice higher than " << a << endl;
	cin >> increasedGuess;

	while (increasedGuess <= a || increasedGuess > b) {
		cout << "Please input a number greater than " << a << ", but less than " <<
			b << endl;
		cin >> increasedGuess;
	}

	return increasedGuess;
}

//Determines the guess as to which side was rolled
int Player::guessDiceSideValue(int a) {
	int guessedDiceSide;

	cout << "You said there are " << a << " dice of a certain value." << endl;
	cout << "Which side of the six-sided dice was rolled?" << endl;
	cin >> guessedDiceSide;

	while (guessedDiceSide < 1 || guessedDiceSide > 6) {
		cout << "You must input a dice side value between 1 and 6. " << endl;
		cin >> guessedDiceSide;
	}

	return guessedDiceSide;
}