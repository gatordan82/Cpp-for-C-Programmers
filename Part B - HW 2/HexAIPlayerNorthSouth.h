// HexAIPlayerNorthSouth.h
//
// C++ for C Programmers, Part B
// Homework 5: Implement Monte Carlo Hex move evaluation
// 
// An Artificial Intelligence computer player for North-to-South.  
// This implementation uses Monte Carlo simulations, which randomly
// populate the remaining empty tiles with the appropriate number of
// markers of each type.  The next move is selected by which of the 
// open tiles produces the most simulated wins out of the total number
// of MC simulations ran for that tile.
//
// Daniel K. Benjamin
// 4/30/2017


#ifndef _HEX_AI_PLAYER_NORTH_SOUTH_H
#define _HEX_AI_PLAYER_NORTH_SOUTH_H

#include "HexPlayerNorthSouth.h"

class HexAIPlayerNorthSouth :
	public HexPlayerNorthSouth
{
private:
	// Use MC simulation to determine the next best move
	size_t bestMoveTile(HexBoard& board);
	// Create one random simulation of board popoulation
	WeightedQuickUnionPathCompressionUF buildMCIteration(HexBoard& board, size_t nextMoveIdx);
	// Run MC simulation to determine the number of wins from selecting the nextMoveIdx tile
	size_t runMCSim(HexBoard& board, size_t nextMoveIdx);
	// Completes the action of placing the bestMoveTile
	size_t makeNextMove(HexBoard& board);

public:
	// Constructors
	HexAIPlayerNorthSouth();
	HexAIPlayerNorthSouth(HexBoard& board);

	// Destructor
	~HexAIPlayerNorthSouth();
	
	// Place a marker on the board, and make all adjacent marker connections
	MoveResult placeMarker(HexBoard& board, const size_t idx);
};

#endif // !_HEX_AI_PLAYER_NORTH_SOUTH_H