#include "HexAIPlayerNorthSouth.h"
#include <algorithm>
#include <cmath>
#include <chrono>
#include <iostream>

typedef std::chrono::high_resolution_clock Clock;

const size_t NUM_VIRTUAL_TILES{ 4 };
const size_t NUM_MC_ITERATIONS{ 100 };

using namespace std;


size_t HexAIPlayerNorthSouth::bestMoveTile(HexBoard& board)
{
	size_t bestTile{};
	size_t bestNumWins{ 0 };

	for (const auto& tile : board.emptyTiles())
	{
		if (size_t mcWins = runMCSim(board, tile) > bestNumWins)
		{
			bestTile = tile;
			bestNumWins = mcWins;
		}
	}
	
	return bestTile;
}

WeightedQuickUnionPathCompressionUF HexAIPlayerNorthSouth::buildMCIteration(HexBoard& board, size_t nextMoveIdx)
{
	std::vector<size_t> emptyTiles{ board.emptyTiles() };
	std::remove(emptyTiles.begin(), emptyTiles.end(), nextMoveIdx);
	std::random_shuffle(emptyTiles.begin(), emptyTiles.end());

	// Need to fill floor(n^2 - 2 * k) tiles with O, and connect them to the UF structure.
	// n = board side length, k = current move number
	size_t endOfHalf{ static_cast<size_t>(floor((emptyTiles.size() - 1) / 2.0)) };

	emptyTiles.erase(emptyTiles.begin() + endOfHalf - 1, emptyTiles.end());

	WeightedQuickUnionPathCompressionUF sim{ _uf };
	joinNeighbors(sim, board, nextMoveIdx);
	for (const auto& tile : emptyTiles)
	{
		for (const auto& neighborTile : board.neighbors(tile))
		{
			if (board.getMarker(tile) == _mark
				|| find(emptyTiles.begin(), emptyTiles.end(), neighborTile) != emptyTiles.end())
			{
				sim.join(neighborTile, tile);
			}
		}
	}
	
	return sim;
}

size_t HexAIPlayerNorthSouth::runMCSim(HexBoard& board, size_t nextMoveIdx)
{
	auto t1 = Clock::now();

	size_t numWins{ 0 };

	size_t n{ board.boardSize() };
	for (size_t i{ 0 }; i < NUM_MC_ITERATIONS; i++)
	{
		WeightedQuickUnionPathCompressionUF mcUFIteration{ buildMCIteration(board, nextMoveIdx) };
		if (mcUFIteration.areConnected(n * n, n * n + 3))
			numWins++;
	}
	
	auto t2 = Clock::now();
	cout << "Time to run " << NUM_MC_ITERATIONS << " Monte Carlo Simulations is "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << " ms." << endl;

	return numWins;
}

HexAIPlayerNorthSouth::HexAIPlayerNorthSouth()
	: HexAIPlayerNorthSouth{ HexBoard{} }
{
}

HexAIPlayerNorthSouth::HexAIPlayerNorthSouth(HexBoard& board)
	: HexPlayerNorthSouth{ board },
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

