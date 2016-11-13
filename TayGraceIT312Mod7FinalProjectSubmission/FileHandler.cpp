/*
Grace Tay
IT-312 Software Development with C++.Net
10/9/2016
7-1 Final Project Submission: Dice Game

Summary:
Allows program to write and read the file with the Liar's Dice Rules.
*/

#include "stdafx.h"
#include <string>
#include <iostream>
#include "FileHandler.h"
#using <system.dll>

using namespace System;
using namespace System::IO;
using namespace std;

//Writes the file with all the rules
void FileHandler::writingTheFile() {
	String^ fileName = "LiarsDiceRules.txt";

	StreamWriter^ sw = gcnew StreamWriter(fileName);
	sw->WriteLine("There must be at least two players to play Liar's Dice!");
	sw->WriteLine("Each player gets a set of five dice, which is rolled one time when we start the game.");
	sw->WriteLine("On your turn, you will be able to view only your set of dice.");
	sw->WriteLine("On each of your turns, you will be asked two values : a guess of how many dice of a certain value are on the table.");
	sw->WriteLine("The first guess you will be asked about is how many dice are on the table.After each turn, the value of this guess must increase by at least one dice.");
	sw->WriteLine("You have been provided a six sided dice, so you can only guess a dice side value between 1 and 6.");
	sw->WriteLine("You can call liar at any point if you think the last player’s guess is wrong.This will end the game.");
	sw->WriteLine("You, the accuser, will win if the last player’s guess is wrong.");
	sw->WriteLine("The last player will win if they guess the correct amount of dice and the right side that was rolled.");
	sw->WriteLine("You can view everyone’s dice at the end of the game.");
	sw->Close();

	Console::WriteLine("a new file ('{0}') has been written", fileName);
}

//This function reads the file
void FileHandler::readingTheFile() {
	String^ fileName = "LiarsDiceRules.txt";

	try {
		Console::WriteLine("trying to open file {0}...", fileName);
		StreamReader^ din = File::OpenText(fileName);

		String^ str;
		int count = 0;
		while ((str = din->ReadLine()) != nullptr) {
			count++;
			Console::WriteLine("Rule {0}: {1}", count, str);
		}
	}
	catch (Exception^ e) {
		if (dynamic_cast<FileNotFoundException^>(e))
			Console::WriteLine("file '{0}' not found", fileName);
		else
			Console::WriteLine("problem reading file '{0}'", fileName);
	}
}