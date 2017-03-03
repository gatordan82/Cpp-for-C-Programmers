#include "HexAIPlayerWestEast.h"

using namespace std;

const size_t NUM_VIRTUAL_TILES{ 4 };

HexAIPlayerWestEast::HexAIPlayerWestEast(HexBoard& board)
	: HexPlayer{ TileMarker::X },
	_uf{ WeightedQuickUnionPathCompressionUF{ board.boardSize() * board.boardSize() + NUM_VIRTUAL_TILES } }
{
	size_t n{ board.boardSize() };
	// connect virtual tiles to board edge tiles
	for (size_t j{ 0 }; j < n; j++)
	{
		// connect left virtual tile
		_uf.join(n * n + 1, j * n);
		// connect right virtual tile
		_uf.join(n * n + 2, j * n + n - 1);
	}
}


HexAIPlayerWestEast::~HexAIPlayerWestEast()
{
}
