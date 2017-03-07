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

size_t queryBoardSize()
{
	size_t size{};
	cout << "What size board do you want to play on?" << endl;
	cin >> size;

	return size;
}


bool queryUseAI()
{
	char useAIYesNo{};
	cout << "Do you want to play against the computer (Y/N)?" << endl;
	cin >> useAIYesNo;

	switch (useAIYesNo)
	{
	case 'y': case 'Y':
		return true;
	case 'n': case 'N':
		return false;
	}
}

size_t getAIPlayerNumber()
{

	size_t humanPlayerNumber{};
	cout << "Do you want to be Player 1 or 2?" << endl;
	cin >> humanPlayerNumber;
	if (humanPlayerNumber == 1)
		return 2;
	else
		return 1;
}

int main()
{
	srand(time(0));

	size_t size{ queryBoardSize() };
	bool useAI{ queryUseAI() };

	if (useAI)
	{
		size_t aiPlayerNumber{ getAIPlayerNumber() };
		if (aiPlayerNumber == 1)
		{
			HexGame<HexPlayerNorthSouth, HexAIPlayerWestEast> newGame{ size, 1 };
			newGame.startGame();
		}
		else
		{
			HexGame<HexAIPlayerNorthSouth, HexPlayerWestEast> newGame{ size, 2 };
			newGame.startGame();
		}
	}
	else
	{
		HexGame<HexPlayerNorthSouth, HexPlayerWestEast> newGame{ size };
		newGame.startGame();
	}


	cin.get();
	cin.get();
	return 0;
}