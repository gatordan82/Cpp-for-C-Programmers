// HexPlayerWestEast.h
//
// C++ for C Programmers, Part B
// Homework 1: Implement Hex Board
// 
// Hex player that wins by connecting the left and right edges.
// Connections are stored by an efficient disjoint-set structure.
//
// Daniel K. Benjamin
// 2/19/2017

#ifndef _HEX_PLAYER_WEST_EAST_H
#define _HEX_PLAYER_WEST_EAST_H

#include "HexPlayer.h"
#include "WeightedQuickUnionPathCompressionUF.h"

class HexPlayerWestEast :
	public HexPlayer
{
private:
	WeightedQuickUnionPathCompressionUF _uf;

public:
	// Constructors
	HexPlayerWestEast() = delete;
	HexPlayerWestEast(HexBoard& board);

	// Destructor
	~HexPlayerWestEast();

	// Place a marker on the board, and make all adjacent marker connections
	MoveResult placeMarker(HexBoard& board, const size_t idx);
	// Check if the two appropriate edges are connected
	bool hasWon(HexBoard& board);
	// Output the player color to the console
	void color() const;
};

#endif _HEX_PLAYER_WEST_EAST_H