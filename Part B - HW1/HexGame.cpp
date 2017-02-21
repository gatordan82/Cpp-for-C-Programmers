#include "HexGame.h"
#include <iostream>
#include <string>

using namespace std;

size_t HexGame::coordsToIndex(size_t i, size_t j)
{
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
			switch (_blueTurn)
			{
			case true:
				cout << "Congratulations Player 1, you've won." << endl;
			case false:
				cout << "Congratulations Player 2, you've won." << endl;
			}
		}
		_blueTurn = !_blueTurn;
	}

	cout << "Would you like to play again (Y/N)?" << endl;
	string readyAgain{};
	cin >> readyAgain;
	if (readyAgain == "Y" || readyAgain == "y")
	{
		_board.resetBoard();
		startGame();
	}
}

bool HexGame::takeTurn(HexPlayer& player)
{
	cout << "Please enter a tile location: row column." << endl;
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
	
	if (_blueTurn) _board.placeMarker(TileMarker::X, index);
	else           _board.placeMarker(TileMarker::O, index);

	_board.drawBoard();

	return player.hasWon(_board);
}
