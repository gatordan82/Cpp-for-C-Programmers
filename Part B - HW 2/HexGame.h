// HexGame.h
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

#ifndef _HEX_GAME_H
#define _HEX_GAME_H

#include "HexBoard.h"
#include "HexAIPlayerNorthSouth.h"
#include "HexAIPlayerWestEast.h"
#include <memory>
#include <iostream>
#include <string>

enum class AIPlayerNumber : char { NONE, X, O };

template <class PlayerNS, class PlayerWE>
class HexGame
{
private:
	HexBoard _board;
	PlayerNS _ns;
	PlayerWE _we;
	bool _blueTurn;
	AIPlayerNumber _aiPlayer;

	// Changes user input ordered pair to index
	size_t coordsToIndex(size_t i, size_t j);

	bool takeHumanTurn(HexPlayer& player);
	bool takeAITurn(HexPlayer& player);

public:
	// Constructors
	HexGame() = delete;
	HexGame(size_t size);
	HexGame(size_t size, size_t aiPlayerNumber);

	// Destructor
	~HexGame();

	// HexGame API

	// Starts a new game
	void startGame();
	// Initiates turn for a given player.  Player inputs move tile
	// and then returns whether or not that player has won.
	bool takeTurn(HexPlayer& player);
};

template <class PlayerNS, class PlayerWE>
size_t HexGame<PlayerNS, PlayerWE>::coordsToIndex(size_t i, size_t j)
{
	// Return a value off the board if either coordinate is invalid
	if (i < 0
		|| i >= _board.boardSize()
		|| j < 0
		|| j >= _board.boardSize())
		return (_board.boardSize() * _board.boardSize());

	return j * _board.boardSize() + i;
}


template <class PlayerNS, class PlayerWE>
HexGame<PlayerNS, PlayerWE>::HexGame(size_t size)
	: _board{ HexBoard{ size } },
	_ns{ HexPlayerNorthSouth{ _board } },
	_we{ HexPlayerWestEast{ _board } },
	_blueTurn{ true },
	_aiPlayer{ AIPlayerNumber::NONE }
{
	std::cout << "Starting new Hex game with board of size " << size << endl;

	std::cout << "\nPlayer 1 goes left to right, with marker X." << endl;
	std::cout << "Player 2 goes top to bottom, with marker O." << endl;
}

template <class PlayerNS, class PlayerWE>
HexGame<PlayerNS, PlayerWE>::HexGame(size_t size, size_t aiPlayerNumber)
	: _board{ HexBoard{ size } },
	_blueTurn{ true }
{
	if (aiPlayerNumber == 1)
	{
		_aiPlayer = AIPlayerNumber::X;
		HexAIPlayerWestEast _we{ _board };
		HexPlayerNorthSouth _ns{ _board };
	}
	else
	{
		_aiPlayer = AIPlayerNumber::O;
		HexPlayerWestEast _we{ _board };
		HexAIPlayerNorthSouth _ns{ _board };
	}
	
	std::cout << "Starting new Hex game with board of size " << size << endl;

	std::cout << "\nPlayer 1 goes left to right, with marker X." << endl;
	std::cout << "Player 2 goes top to bottom, with marker O." << endl;
}

template <class PlayerNS, class PlayerWE>
HexGame<PlayerNS, PlayerWE>::~HexGame()
{
}


template <class PlayerNS, class PlayerWE>
void HexGame<PlayerNS, PlayerWE>::startGame()
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


template <class PlayerNS, class PlayerWE>
bool HexGame<PlayerNS, PlayerWE>::takeTurn(HexPlayer& player)
{
	if (_aiPlayer == AIPlayerNumber::NONE || (_blueTurn && player.color() == TileMarker::X))
		return takeHumanTurn(player);
	else
		return takeAITurn(player);
}


template <class PlayerNS, class PlayerWE>
bool HexGame<PlayerNS, PlayerWE>::takeHumanTurn(HexPlayer& player)
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

	player.placeMarker(_board, index);
	_board.drawBoard();

	return player.hasWon(_board);
}


template <class PlayerNS, class PlayerWE>
bool HexGame<PlayerNS, PlayerWE>::takeAITurn(HexPlayer& player)
{
	if (_aiPlayer == AIPlayerNumber::X)
	{
		std::cout << "AI Player 1's turn (X)." << endl;
		_we.placeMarker(_board, 0);
		_board.drawBoard();
		return _we.hasWon(_board);
	}
	else
	{
		std::cout << "AI Player 2's turn (O)." << endl;
		_ns.placeMarker(_board, 0);
		_board.drawBoard();
		return _ns.hasWon(_board);
	}
}

#endif
