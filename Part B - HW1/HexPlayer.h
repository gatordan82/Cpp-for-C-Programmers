#ifndef _HEX_PLAYER_H
#define _HEX_PLAYER_H

#include "HexBoard.h"


enum class MoveResult : char { LEGAL, OCCUPIED, OUT_OF_BOUNDS};

class HexPlayer
{
private:
	TileMarker _mark;

public:
	HexPlayer() = delete;
	HexPlayer(const TileMarker mark);
	virtual ~HexPlayer();

	MoveResult placeMarker(HexBoard& board, const size_t idx);
	virtual bool hasWon(HexBoard& board) const = 0;
	virtual void color() const = 0;
};


#endif // !_HEX_PLAYER_H