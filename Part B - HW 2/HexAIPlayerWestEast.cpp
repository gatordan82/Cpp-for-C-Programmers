#include "HexAIPlayerWestEast.h"
#include <algorithm>
#include <cmath>
#include <chrono>
#include <iostream>

typedef std::chrono::high_resolution_clock Clock;

const size_t NUM_VIRTUAL_TILES{ 4 };


using namespace std;



size_t HexAIPlayerWestEast::makeNextMove(HexBoard& board)
{
	return bestMoveTile(board);
}


size_t HexAIPlayerWestEast::bestMoveTile(HexBoard& board)
{
	size_t bestTile{};
	size_t bestNumWins{ 0 };

	for (const auto& tile : board.emptyTiles())
	{
		size_t mcWins = runMCSim(board, tile);
		if (mcWins > bestNumWins)
		{
			bestTile = tile;
			bestNumWins = mcWins;
		}
	}

	return bestTile;
}

WeightedQuickUnionPathCompressionUF HexAIPlayerWestEast::buildMCIteration(HexBoard& board, size_t nextMoveIdx)
{
	std::vector<size_t> emptyTiles{ board.emptyTiles() };
	std::remove(emptyTiles.begin(), emptyTiles.end(), nextMoveIdx);
	emptyTiles.erase(emptyTiles.end() - 1, emptyTiles.end());
	std::random_shuffle(emptyTiles.begin(), emptyTiles.end());

	// Need to fill floor(n^2 - 2 * k) tiles with O, and connect them to the UF structure.
	// n = board side length, k = current move number
	size_t endOfHalf{ static_cast<size_t>(floor((emptyTiles.size() - 1) / 2.0)) };

	emptyTiles.erase(emptyTiles.begin() + endOfHalf, emptyTiles.end());

	WeightedQuickUnionPathCompressionUF sim{ _uf };
	joinNeighbors(sim, board, nextMoveIdx);
	for (const auto& tile : emptyTiles)
	{
		for (const auto& neighborTile : board.neighbors(tile))
		{
			if (neighborTile == nextMoveIdx
				|| board.getMarker(neighborTile) == _mark
				|| find(emptyTiles.begin(), emptyTiles.end(), neighborTile) != emptyTiles.end())
			{
				sim.join(neighborTile, tile);
			}
		}
	}

	return sim;
}

size_t HexAIPlayerWestEast::runMCSim(HexBoard& board, size_t nextMoveIdx)
{
	auto t1 = Clock::now();

	size_t numWins{ 0 };

	size_t n{ board.boardSize() };
	for (size_t i{ 0 }; i < NUM_MC_ITERATIONS; i++)
	{
		WeightedQuickUnionPathCompressionUF mcUFIteration{ buildMCIteration(board, nextMoveIdx) };
		std::pair<size_t, size_t> winTiles = board.westEastWinTiles();
		if (mcUFIteration.areConnected(winTiles.first, winTiles.second))
			numWins++;
	}

	auto t2 = Clock::now();
	cout << "Time to run " << NUM_MC_ITERATIONS << " Monte Carlo Simulations is "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << " ms." << endl;

	return numWins;
}

HexAIPlayerWestEast::HexAIPlayerWestEast()
	: HexAIPlayerWestEast{ HexBoard{} }
{
}

HexAIPlayerWestEast::HexAIPlayerWestEast(HexBoard& board)
	: HexPlayerWestEast{ board }
{
}


HexAIPlayerWestEast::~HexAIPlayerWestEast()
{
}

HexAIPlayerWestEast& HexAIPlayerWestEast::operator=(HexAIPlayerWestEast& player)
{
	if (this != &player)
	{
		_uf = player._uf;
	}

	return *this;
}


MoveResult HexAIPlayerWestEast::placeMarker(HexBoard& board, const size_t idx)
{
	size_t mcIdx = makeNextMove(board);

	switch (board.isValidIndex(mcIdx))
	{
	case MoveResult::LEGAL:
	{
		board.placeMarker(TileMarker::X, mcIdx);
		for (const auto& tile : board.neighbors(mcIdx))
		{
			if (board.getMarker(tile) == TileMarker::O)
				_uf.join(mcIdx, tile);
		}
		return MoveResult::LEGAL;
	}
	case MoveResult::OCCUPIED:
		return MoveResult::OCCUPIED;
	case MoveResult::OUT_OF_BOUNDS:
		return MoveResult::OUT_OF_BOUNDS;
	}
}
