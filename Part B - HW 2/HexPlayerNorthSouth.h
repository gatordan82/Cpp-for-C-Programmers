// HexPlayerNorthSouth.h
//
// C++ for C Programmers, Part B
// Homework 5: Implement Monte Carlo Hex move evaluation
// 
// Hex player that wins by connecting the top and bottom edges.
// Connections are stored by an efficient disjoint-set structure.
//
// Daniel K. Benjamin
// 4/30/2017

#ifndef _HEX_PLAYER_NORTH_SOUTH_H
#define _HEX_PLAYER_NORTH_SOUTH_H

#include "HexPlayer.h"

class HexPlayerNorthSouth :
	public HexPlayer
{
protected:
	WeightedQuickUnionPathCompressionUF _uf;

public:
	// Constructors
	HexPlayerNorthSouth();
	HexPlayerNorthSouth(HexBoard& board);
	HexPlayerNorthSouth(HexPlayerNorthSouth& player);

	// Destructor
	virtual ~HexPlayerNorthSouth();

	// Place a marker on the board, and make all adjacent marker connections
	virtual MoveResult placeMarker(HexBoard& board, const size_t idx);
	// Check if the two appropriate edges are connected
	bool hasWon(HexBoard& board);
	// Output the player color to the console
	TileMarker color() const;
};

#endif // !_HEX_PLAYER_NORTH_SOUTH_H
