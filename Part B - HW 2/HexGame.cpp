// HexGame.cpp
//
// C++ for C Programmers, Part B
// Homework 5: Implement Monte Carlo Hex move evaluation
// 
// Sets up a game of hex, with a board of size to be input 
// as a constructor.  Defines the two players (N/S & W/E), and 
// toggles turns back and forth between the two players.  Players
// are either human or AI players, using polymorphism.  The type
// of player is selected at run time, by using a smart pointer
// to the base class HexPlayer.
//
// Daniel K. Benjamin
// 4/30/2017

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
	: _board{ HexBoard{ size } },
	_ns{ std::make_unique<HexPlayerNorthSouth>(_board) },
	_we{ std::make_unique<HexPlayerWestEast>(_board) },
	_blueTurn{ true },
	_aiPlayer{ AIPlayerNumber::NONE }
{
	std::cout << "Starting new Hex game with board of size " << size << endl;

	std::cout << "\nPlayer 1 goes left to right, with marker X." << endl;
	std::cout << "Player 2 goes top to bottom, with marker O." << endl;
}


HexGame::HexGame(size_t size, size_t aiPlayerNumber)
	: _board{ HexBoard{ size } },
	_blueTurn{ true }
{
	if (aiPlayerNumber == 1)
	{
		_aiPlayer = AIPlayerNumber::X;
		_we = std::make_unique<HexAIPlayerWestEast>(_board);
		_ns = std::make_unique<HexPlayerNorthSouth>(_board);
	}
	else
	{
		_aiPlayer = AIPlayerNumber::O;
		_we = std::make_unique<HexPlayerWestEast>(_board);
		_ns = std::make_unique<HexAIPlayerNorthSouth>(_board);
	}

	std::cout << "Starting new Hex game with board of size " << size << endl;

	std::cout << "\nPlayer 1 goes left to right, with marker X." << endl;
	std::cout << "Player 2 goes top to bottom, with marker O." << endl;
}


HexGame::~HexGame()
{
}


void HexGame::startGame()
{
	std::cout << "\nAre you ready to start (Y/N)?" << endl;
	string ready{};
	cin >> ready;

	if (ready == "Y" || ready == "y")
	{
		std::cout << "Let the game begin...\n" << endl;
		_board.drawBoard();
	}
	else if (ready == "N" || ready == "n")
	{
		std::cout << "Quitting game...\n" << endl;
		return;
	}

	bool gameWon{ false };

	while (!gameWon)
	{
		gameWon = _blueTurn ? takeTurn(_we) : takeTurn(_ns);
		if (gameWon)
		{
			if (_blueTurn)
				std::cout << "Congratulations Player 1, you've won.\n" << endl;
			else
				std::cout << "Congratulations Player 2, you've won.\n" << endl;
		}
		_blueTurn = !_blueTurn;
	}
}


bool HexGame::takeTurn(std::unique_ptr<HexPlayer>& player)
{
	if (_aiPlayer == AIPlayerNumber::NONE 
		|| (_blueTurn && _aiPlayer == AIPlayerNumber::O)
		|| (!_blueTurn && _aiPlayer == AIPlayerNumber::X))
		return takeHumanTurn(player);
	else
		return takeAITurn(player);
}


bool HexGame::takeHumanTurn(std::unique_ptr<HexPlayer>& player)
{
	if (_blueTurn)
		std::cout << "Human Player 1's turn (X)." << endl;
	else
		std::cout << "Human Player 2's turn (O)." << endl;
	std::cout << "Please enter a tile location: ROW COLUMN." << endl;
	size_t j{ 0 };
	size_t i{ 0 };

	MoveResult isLegal{};
	size_t index{};

	while (isLegal != MoveResult::LEGAL)
	{
		cin >> j;
		cin >> i;

		index = coordsToIndex(i, j);

		isLegal = _board.isValidIndex(index);
		switch (isLegal)
		{
		case MoveResult::OCCUPIED:
			std::cout << "Tile is already filled. Pick another tile location." << endl;
			break;
		case MoveResult::OUT_OF_BOUNDS:
			std::cout << "Tile is off the board. Pick another tile location." << endl;
			break;
		}
	}

	player->placeMarker(_board, index);
	_board.drawBoard();

	return player->hasWon(_board);
}


bool HexGame::takeAITurn(std::unique_ptr<HexPlayer>& player)
{
	if (_aiPlayer == AIPlayerNumber::X)
	{
		std::cout << "AI Player 1's turn (X)." << endl;
		_we->placeMarker(_board, 0);
		_board.drawBoard();
		return _we->hasWon(_board);
	}
	else
	{
		std::cout << "AI Player 2's turn (O)." << endl;
		_ns->placeMarker(_board, 0);
		_board.drawBoard();
		return _ns->hasWon(_board);
	}
}










