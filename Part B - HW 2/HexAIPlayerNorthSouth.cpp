#include "HexAIPlayerNorthSouth.h"

const size_t NUM_VIRTUAL_TILES{ 4 };

using namespace std;

MoveResult HexAIPlayerNorthSouth::placeMarker(HexBoard& board, const size_t idx)
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

size_t HexAIPlayerNorthSouth::bestMoveTile(HexBoard& board)
{
	size_t bestTile{};

}

HexAIPlayerNorthSouth::HexAIPlayerNorthSouth(HexBoard& board)
	: HexPlayer{ TileMarker::O },
	_uf{ WeightedQuickUnionPathCompressionUF{ board.boardSize() * board.boardSize() + NUM_VIRTUAL_TILES } }
{
	size_t n{ board.boardSize() };
	// connect virtual tiles to board edge tiles
	for (size_t j{ 0 }; j < n; j++)
	{
		// connect top virtual tile
		_uf.join(n * n, j);
		// connect bottom virtual tiles
		_uf.join(n * n + 3, n * (n - 1) + j);
	}
}


HexAIPlayerNorthSouth::~HexAIPlayerNorthSouth()
{
}

MoveResult HexAIPlayerNorthSouth::makeNextMove(HexBoard& board)
{
	size_t bestTile{ bestMoveTile(board) };
	return placeMarker(board, bestTile);
}

bool HexAIPlayerNorthSouth::hasWon(HexBoard & board)
{
	return _uf.areConnected(board.northSouthWinTiles().first, board.northSouthWinTiles().second);
}

void HexAIPlayerNorthSouth::color() const
{
	cout << "Red Player (O)" << endl;
}
