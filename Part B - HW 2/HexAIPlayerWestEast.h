// HexAIPlayerNorthSouth.h
//
// C++ for C Programmers, Part B
// Homework 5: Implement Monte Carlo Hex move evaluation
// 
// An Artificial Intelligence computer player for West-to-East.  
// This implementation uses Monte Carlo simulations, which randomly
// populate the remaining empty tiles with the appropriate number of
// markers of each type.  The next move is selected by which of the 
// open tiles produces the most simulated wins out of the total number
// of MC simulations ran for that tile.
//
// Daniel K. Benjamin
// 4/30/2017

#ifndef _HEX_AI_PLAYER_WEST_EAST_H
#define _HEX_AI_PLAYER_WEST_EAST_H

#include "HexPlayerWestEast.h"

class HexAIPlayerWestEast :
	public HexPlayerWestEast
{
private:
	size_t bestMoveTile(HexBoard& board);
	WeightedQuickUnionPathCompressionUF buildMCIteration(HexBoard& board, size_t nextMoveIdx);
	size_t runMCSim(HexBoard& board, size_t nextMoveIdx);
	size_t makeNextMove(HexBoard& board);

public:
	// Constructors
	HexAIPlayerWestEast();
	HexAIPlayerWestEast(HexBoard& board);

	// Destructor
	~HexAIPlayerWestEast();

	// Place a marker on the board, and make all adjacent marker connections
	MoveResult placeMarker(HexBoard& board, const size_t idx);


};

#endif // !_HEX_AI_PLAYER_WEST_EAST_H