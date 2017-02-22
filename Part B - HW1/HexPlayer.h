// HexPlayer.h
//
// C++ for C Programmers, Part B
// Homework 1: Implement Hex Board
// 
// Base Hex player class.  Stores the marker type, and has
// pure virtual functions for identification, marker placement,
// and checking whether or not the player has won.
//
// Daniel K. Benjamin
// 2/19/2017

#ifndef _HEX_PLAYER_H
#define _HEX_PLAYER_H

#include "HexBoard.h"
#include "WeightedQuickUnionPathCompressionUF.h"

class HexPlayer
{
private:
	TileMarker _mark;

public:
	// Constructors
	HexPlayer() = delete;
	HexPlayer(const TileMarker mark);

	// Destructor
	virtual ~HexPlayer();

	// HexPlayer API

	// Place a marker on the board, and make all adjacent marker connections
	virtual MoveResult placeMarker(HexBoard& board, const size_t idx) = 0;
	// Check if the two appropriate edges are connected
	virtual bool hasWon(HexBoard& board) = 0;
	// Output the player color to the console
	virtual void color() const = 0;
};


#endif // !_HEX_PLAYER_H