// HexPlayer.cpp
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

#include "HexPlayer.h"

WeightedQuickUnionPathCompressionUF& HexPlayer::joinNeighbors(WeightedQuickUnionPathCompressionUF& uf, 
															  HexBoard& board, 
														      size_t tile)
{
	for (const auto& neighborTile : board.neighbors(tile))
	{
		if (board.getMarker(tile) == _mark)
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

