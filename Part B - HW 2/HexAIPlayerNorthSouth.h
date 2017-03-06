#ifndef _HEX_AI_PLAYER_NORTH_SOUTH_H
#define _HEX_AI_PLAYER_NORTH_SOUTH_H

#include "HexPlayerNorthSouth.h"

class HexAIPlayerNorthSouth :
	public HexPlayerNorthSouth
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
	HexAIPlayerNorthSouth();
	HexAIPlayerNorthSouth(HexBoard& board);

	// Destructor
	~HexAIPlayerNorthSouth();

	MoveResult makeNextMove(HexBoard& board);

};

#endif // !_HEX_AI_PLAYER_NORTH_SOUTH_H