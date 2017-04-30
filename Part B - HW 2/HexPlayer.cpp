// HexPlayer.cpp
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

#include "HexPlayer.h"

WeightedQuickUnionPathCompressionUF& HexPlayer::joinNeighbors(WeightedQuickUnionPathCompressionUF& uf, 
															  HexBoard& board, 
														      size_t tile)
{
	for (const auto& neighborTile : board.neighbors(tile))
	{
		if (board.getMarker(neighborTile) == _mark)
			uf.join(neighborTile, tile);
	}

	return uf;
}

HexPlayer::HexPlayer(const TileMarker mark)
	: _mark{ mark }
{
}


HexPlayer::~HexPlayer()
{
}

