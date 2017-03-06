// HexGame.cpp
//
// C++ for C Programmers, Part B
// Homework 1: Implement Hex Board
// 
// Sets up a game of hex, with a board of size to be input 
// as a constructor.  Defines the two players (N/S & W/E), and 
// toggles turns back and forth between the two players.
//
// Daniel K. Benjamin
// 2/19/2017

#include "HexGame.h"
#include <iostream>
#include <string>

using namespace std;

size_t HexGame::coordsToIndex(size_t i, size_t j)
{
	// Return a value off the board if either coordinate is invalid
	if (i < 0
		|| i >= _board.boardSize()
		|| j < 0
		|| j >= _board.boardSize())
		return (_board.boardSize() * _board.boardSize());

	return j * _board.boardSize() + i;
}

HexGame::HexGame(size_t size)
	: _board{ HexBoard{size} },
	_ns{ HexPlayerNorthSouth{_board} },
	_we{ HexPlayerWestEast{_board} },
	_blueTurn{ true }
{
	cout << "Starting new Hex game with board of size " << size << endl;

	cout << "\nPlayer 1 goes left to right, with marker X." << endl;
	cout << "Player 2 goes top to bottom, with marker O." << endl;
}

HexGame::HexGame(size_t size, bool useAI, size_t playerNumber)
	: _board{ HexBoard{ size } },
	_ns{},
	_we{},
	_blueTurn{ true }
{
	cout << "Starting new Hex game with board of size " << size << endl;

	cout << "\nPlayer 1 goes left to right, with marker X." << endl;
	cout << "Player 2 goes top to bottom, with marker O." << endl;
}


HexGame::~HexGame()
{
}

void HexGame::startGame()
{
	cout << "\nAre you ready to start (Y/N)?" << endl;
	string ready{};
	cin >> ready;

	if (ready == "Y" || ready == "y")
	{
		cout << "Let the game begin...\n" << endl;
		_board.drawBoard();
	}
	else if (ready == "N" || ready == "n")
	{
		cout << "Quitting game...\n" << endl;
		return;
	}		

	bool gameWon{ false };
	
	while (!gameWon)
	{
		gameWon = _blueTurn ? takeTurn(_we) : takeTurn(_ns);
		if (gameWon)
		{
			if (_blueTurn)
				cout << "Congratulations Player 1, you've won.\n" << endl;
			else
				cout << "Congratulations Player 2, you've won.\n" << endl;
		}
		_blueTurn = !_blueTurn;
	}
}

bool HexGame::takeTurn(HexPlayer& player)
{
	if (_blueTurn)
		cout << "Player 1's turn (X)." << endl;
	else
		cout << "Player 2's turn (O)." << endl;
	cout << "Please enter a tile location: ROW COLUMN." << endl;
	size_t j{0};
	size_t i{0};

	MoveResult isLegal{};
	size_t index{};

	while (isLegal != MoveResult::LEGAL)
	{
		cin >> j;
		cin >> i;

		index = coordsToIndex(i, j);

		isLegal =  _board.isValidIndex(index);
		switch (isLegal)
		{
		case MoveResult::OCCUPIED:
			cout << "Tile is already filled. Pick another tile location." << endl;
			break;
		case MoveResult::OUT_OF_BOUNDS:
			cout << "Tile is off the board. Pick another tile location." << endl;
			break;
		}
	}
	
	player.placeMarker(_board, index);
	_board.drawBoard();

	return player.hasWon(_board);
}
