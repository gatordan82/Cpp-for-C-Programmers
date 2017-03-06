// Main.cpp
//
// C++ for C Programmers, Part B
// Homework 1: Implement Hex Board
// 
// Entry point for starting a game of Hex.  Asks the user what size board
// you want to play on, and then starts the game.
//
// Daniel K. Benjamin
// 2/19/2017

#include <iostream>
#include "DenseUndirectedGraph.h"
#include "HexBoard.h"
#include "HexGame.h"
#include <ctime>

using namespace std;

HexGame startGamePrompt()
{
	size_t size{};
	cout << "What size board do you want to play on?" << endl;
	cin >> size;

	char useAIYesNo{};
	cout << "Do you want to play against the computer (Y/N)?" << endl;
	cin >> useAIYesNo;

	bool useAI{};
	switch (useAIYesNo)
	{
	case 'y': case 'Y':
		useAI = true;
		break;
	case 'n': case 'N':
		return HexGame{ size };
	default:
		cout << "Sorry, I didn't understand your input... use AI (Y/N)?" << endl;
		break;
	}

	size_t humanPlayerNumber{};
	cout << "Do you want to be Player 1 or 2?" << endl;
	cin >> humanPlayerNumber;
	switch (humanPlayerNumber)
	{
	case 1:
		HexGame{ size, useAI, humanPlayerNumber };
		break;
	case 'n': case 'N':
		return HexGame{ size };
	default:
		cout << "Sorry, I didn't understand your input... use AI (Y/N)?" << endl;
		break;
	}

}

int main()
{
	

	srand(time(0));

	size_t size{};

	cout << "What size board do you want to play on?" << endl;
	cin >> size;

	char useAI{};
	cout << "Do you want to play against the computer (Y/N)?" << endl;
	cin >> useAI;

	switch (useAI)
	{
	case 'y': case 'Y':
		
	}


	HexGame newGame{ size };
	newGame.startGame();

	cin.get();
	cin.get();
	return 0;
}