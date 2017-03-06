#ifndef _HEX_AI_PLAYER_WEST_EAST_H
#define _HEX_AI_PLAYER_WEST_EAST_H

#include "HexPlayer.h"

class HexAIPlayerWestEast :
	public HexPlayer
{
private:
	WeightedQuickUnionPathCompressionUF _uf;
	// Place a marker on the board, and make all adjacent marker connections
	MoveResult placeMarker(HexBoard& board, const size_t idx);

	size_t bestMoveTile(HexBoard& board);
	WeightedQuickUnionPathCompressionUF buildMCIteration(HexBoard& board, size_t nextMoveIdx);
	size_t runMCSim(HexBoard& board, size_t nextMoveIdx);

public:
	// Constructors
	HexAIPlayerWestEast();
	HexAIPlayerWestEast(HexBoard& board);

	// Destructor
	~HexAIPlayerWestEast();

	// Place a marker on the board, and make all adjacent marker connections
	MoveResult makeNextMove(HexBoard& board);
	// Check if the two appropriate edges are connected
	bool hasWon(HexBoard& board);
	// Output the player color to the console
	void color() const;
};

#endif // !_HEX_AI_PLAYER_WEST_EAST_H