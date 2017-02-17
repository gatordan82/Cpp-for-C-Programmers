#ifndef _HEX_PLAYER_H
#define _HEX_PLAYER_H

#include "HexBoard.h"
#include "WeightedQuickUnionPathCompressionUF.h"



class HexPlayer
{
private:
	TileMarker _mark;

public:
	HexPlayer() = delete;
	HexPlayer(const TileMarker mark);
	virtual ~HexPlayer();

	virtual MoveResult placeMarker(HexBoard& board, const size_t idx) = 0;
	virtual bool hasWon(HexBoard& board) = 0;
	virtual void color() const = 0;
};


#endif // !_HEX_PLAYER_H