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
	HexPlayerWestEast() = delete;
	HexPlayerWestEast(HexBoard& board);

	~HexPlayerWestEast();

	MoveResult placeMarker(HexBoard& board, const size_t idx);
	bool hasWon(HexBoard& board);
	void color() const;
};

#endif _HEX_PLAYER_WEST_EAST_H