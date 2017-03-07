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

	HexAIPlayerWestEast& operator=(HexAIPlayerWestEast& player);

	// Place a marker on the board, and make all adjacent marker connections

	MoveResult placeMarker(HexBoard& board, const size_t idx);


};

#endif // !_HEX_AI_PLAYER_WEST_EAST_H