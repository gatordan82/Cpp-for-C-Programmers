#ifndef _HEX_AI_PLAYER_NORTH_SOUTH_H
#define _HEX_AI_PLAYER_NORTH_SOUTH_H

#include "HexPlayerNorthSouth.h"

class HexAIPlayerNorthSouth :
	public HexPlayerNorthSouth
{
private:
	WeightedQuickUnionPathCompressionUF _uf;

	size_t bestMoveTile(HexBoard& board);
	WeightedQuickUnionPathCompressionUF buildMCIteration(HexBoard& board, size_t nextMoveIdx);
	size_t runMCSim(HexBoard& board, size_t nextMoveIdx);
	size_t makeNextMove(HexBoard& board);


public:
	// Constructors
	HexAIPlayerNorthSouth();
	HexAIPlayerNorthSouth(HexBoard& board);

	// Destructor
	~HexAIPlayerNorthSouth();

	MoveResult placeMarker(HexBoard& board, const size_t idx);

};

#endif // !_HEX_AI_PLAYER_NORTH_SOUTH_H