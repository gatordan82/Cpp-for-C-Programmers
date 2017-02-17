#include "HexPlayerNorthSouth.h"
#include <iostream>

using namespace std;

const size_t NUM_VIRTUAL_TILES{ 4 };

HexPlayerNorthSouth::HexPlayerNorthSouth(HexBoard& board)
	: HexPlayer{ TileMarker::O },
	_uf{WeightedQuickUnionPathCompressionUF{ board.boardSize() * board.boardSize() + NUM_VIRTUAL_TILES } }
{
}


HexPlayerNorthSouth::~HexPlayerNorthSouth()
{
}

MoveResult HexPlayerNorthSouth::placeMarker(HexBoard& board, const size_t idx)
{
	switch (board.isValidIndex(idx))
	{
	case MoveResult::LEGAL:
	{
		board.placeMarker(TileMarker::O, idx);
		for (const auto& tile : board.neighbors(idx))
		{
			if (board.getMarker(tile) == TileMarker::O)
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

bool HexPlayerNorthSouth::hasWon(HexBoard& board)
{
	return _uf.areConnected(board.northSouthWinTiles().first, board.northSouthWinTiles().second);
}

void HexPlayerNorthSouth::color() const
{
	cout << "Red Player (O)" << endl;
}
