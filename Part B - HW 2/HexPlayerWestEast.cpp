// HexPlayerWestEast.cpp
//
// C++ for C Programmers, Part B
// Homework 5: Implement Monte Carlo Hex move evaluation
// 
// Hex player that wins by connecting the left and right edges.
// Connections are stored by an efficient disjoint-set structure.
//
// Daniel K. Benjamin
// 4/30/2017

#include "HexPlayerWestEast.h"
#include <iostream>

using namespace std;

HexPlayerWestEast::HexPlayerWestEast()
	: HexPlayerWestEast{ HexBoard{} }
{
}

HexPlayerWestEast::HexPlayerWestEast(HexBoard& board)
	: HexPlayer{TileMarker::X},
	_uf{WeightedQuickUnionPathCompressionUF{board.boardSize() * board.boardSize() + NUM_VIRTUAL_TILES}}
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

TileMarker HexPlayerWestEast::color() const
{
	return TileMarker::X;
}
