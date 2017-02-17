#ifndef _HEX_PLAYER_NORTH_SOUTH_H
#define _HEX_PLAYER_NORTH_SOUTH_H

#include "HexPlayer.h"

class HexPlayerNorthSouth :
	public HexPlayer
{
private:
	WeightedQuickUnionPathCompressionUF _uf;

public:
	HexPlayerNorthSouth() = delete;
	HexPlayerNorthSouth(HexBoard& board);

	~HexPlayerNorthSouth();

	MoveResult placeMarker(HexBoard& board, const size_t idx);
	bool hasWon(HexBoard& board);
	void color() const;
};

#endif // !_HEX_PLAYER_NORTH_SOUTH_H
