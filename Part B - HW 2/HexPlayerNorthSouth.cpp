// HexPlayerNorthSouth.cpp
//
// C++ for C Programmers, Part B
// Homework 1: Implement Hex Board
// 
// Hex player that wins by connecting the top and bottom edges.
// Connections are stored by an efficient disjoint-set structure.
//
// Daniel K. Benjamin
// 2/19/2017

#include "HexPlayerNorthSouth.h"
#include <iostream>

using namespace std;

const size_t NUM_VIRTUAL_TILES{ 4 };

HexPlayerNorthSouth::HexPlayerNorthSouth()
	: HexPlayerNorthSouth{ HexBoard{} }
{
}

HexPlayerNorthSouth::HexPlayerNorthSouth(HexBoard& board)
	: HexPlayer{ TileMarker::O },
	_uf{WeightedQuickUnionPathCompressionUF{ board.boardSize() * board.boardSize() + NUM_VIRTUAL_TILES } }
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
