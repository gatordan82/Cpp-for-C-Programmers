// HexGame.h
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

#ifndef _HEX_GAME_H
#define _HEX_GAME_H

#include "HexBoard.h"
#include "HexAIPlayerNorthSouth.h"
#include "HexAIPlayerWestEast.h"
#include <memory>
#include <iostream>
#include <string>

enum class AIPlayerNumber : char { NONE, X, O };

class HexGame
{
private:
	HexBoard _board;
	std::unique_ptr<HexPlayer> _ns;
	std::unique_ptr<HexPlayer> _we;
	bool _blueTurn;
	AIPlayerNumber _aiPlayer;

	// Changes user input ordered pair to index
	size_t coordsToIndex(size_t i, size_t j);

	bool takeHumanTurn(std::unique_ptr<HexPlayer>& player);
	bool takeAITurn(std::unique_ptr<HexPlayer>& player);

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
	bool takeTurn(std::unique_ptr<HexPlayer>& player);
};




#endif
