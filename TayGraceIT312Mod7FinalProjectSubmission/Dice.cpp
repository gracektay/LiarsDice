/*
Grace Tay
IT-312 Software Development with C++.Net
10/9/2016
7-1 Final Project Submission: Dice Game

Summary: The Dice class handles the random number generator for each dice in the game.
*/

#include "stdafx.h"
#include "Dice.h"
#include "Game.h"
#include <iostream>

using namespace std;

//Rolls dice and uses random function to generate random number representing one of the dice sides
unsigned int Dice::randomlyRoll() {
	int random = rand() % 6 + 1;
	return random;
}