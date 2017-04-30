// HexPlayer.h
//
// C++ for C Programmers, Part B
// Homework 5: Implement Monte Carlo Hex move evaluation
// 
// Base Hex player class.  Stores the marker type, and has
// pure virtual functions for identification, marker placement,
// and checking whether or not the player has won.  Adds an
// implementation specific joinNeighbors() method for making
// connections in a Union-Find data structure.
//
// Daniel K. Benjamin
// 4/30/2017

#ifndef _HEX_PLAYER_H
#define _HEX_PLAYER_H

#include "HexBoard.h"
#include "WeightedQuickUnionPathCompressionUF.h"

const size_t NUM_MC_ITERATIONS{ 1000 };

class HexPlayer
{
protected:
	TileMarker _mark;	// tile marker type
	
	// Joins all adjacent tiles of the same marker type in the UF structure
	WeightedQuickUnionPathCompressionUF& joinNeighbors(WeightedQuickUnionPathCompressionUF& uf, HexBoard& board, size_t tile);

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
	virtual TileMarker color() const = 0;
};


#endif // !_HEX_PLAYER_H