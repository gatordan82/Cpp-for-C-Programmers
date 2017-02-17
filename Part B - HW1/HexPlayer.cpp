#include "HexPlayer.h"



HexPlayer::HexPlayer()
{
}

HexPlayer::HexPlayer(const TileMarker mark)
	: _mark{ mark }
{
}


HexPlayer::~HexPlayer()
{
}

MoveResult HexPlayer::placeMarker(HexBoard& board, const size_t idx)
{
	if (board.isValidIndex(idx))
	{
		board.placeMarker(_mark, idx);
		return MoveResult::LEGAL;
	}

}

