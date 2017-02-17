#include "HexPlayerWestEast.h"
#include <iostream>

using namespace std;

const size_t NUM_VIRTUAL_TILES{ 4 };

HexPlayerWestEast::HexPlayerWestEast(HexBoard& board)
	: HexPlayer{TileMarker::X},
	_uf{WeightedQuickUnionPathCompressionUF{board.boardSize() * board.boardSize() + NUM_VIRTUAL_TILES}}
{
}

HexPlayerWestEast::~HexPlayerWestEast()
{
}

MoveResult HexPlayerWestEast::placeMarker(HexBoard& board, const size_t idx)
{
	switch (board.isValidIndex(idx))
	{
	case MoveResult::LEGAL:
	{
		board.placeMarker(TileMarker::X, idx);
		for (const auto& tile : board.neighbors(idx))
		{
			if (board.getMarker(tile) == TileMarker::X)
				_uf.join(idx, tile);
		}
		return MoveResult::LEGAL;
	}
	case MoveResult::OCCUPIED:
		return MoveResult::OCCUPIED;
	case MoveResult::OUT_OF_BOUNDS:
		return MoveResult::OUT_OF_BOUNDS;
	}
}

bool HexPlayerWestEast::hasWon(HexBoard& board)
{
	return _uf.areConnected(board.westEastWinTiles().first, board.westEastWinTiles().second);
}

void HexPlayerWestEast::color() const
{
	cout << "Blue Player (X)" << endl;
}
