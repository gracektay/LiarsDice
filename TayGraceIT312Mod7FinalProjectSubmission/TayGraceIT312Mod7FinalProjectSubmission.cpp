/*
Grace Tay
IT-312 Software Development with C++.Net
10/9/2016
7-1 Final Project Submission: Dice Game

Summary:
This game requires two or more players to run properly. This game will require a dice roll function, completed once at the beginning of play for every dice. 
Each player gets five six-sided dice. On each player’s turn, the player gets to view their own dice. They guess the rolled dice value (1-6) and how many of 
those dice are in the whole game. The game continues until someone inputs “Y” or "y" for "yes" when asked if they want to call liar. At this point, the game
checks to see if the guess is accurate. If the person guessed the right amount of dice and respective value, that guesser wins. If they did not get it right,
the accuser wins. After each turn, there must be an increase in how many dice are thought to be on the table.

Main file writes and reads file, seeds the number generator, and then calls the play function from game, which holds most of the game functionality.
*/
#include "stdafx.h"
#include "Game.h"
#include "FileHandler.h"

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, const char * argv[]) {
	FileHandler ruleOutput;
	ruleOutput.writingTheFile();
	ruleOutput.readingTheFile();
	
	srand(static_cast<unsigned int>(time(NULL)));

	Game game;
	game.play();


	cout << "test" << endl;

	return 0;
}