#include "HexAIPlayerNorthSouth.h"
#include <algorithm>
#include <cmath>
#include <chrono>
#include <iostream>

typedef std::chrono::high_resolution_clock Clock;

const size_t NUM_VIRTUAL_TILES{ 4 };


using namespace std;


size_t HexAIPlayerNorthSouth::bestMoveTile(HexBoard& board)
{
	const auto& emptyTiles{ board.emptyTiles() };
	size_t bestTile{emptyTiles[0]};
	size_t bestNumWins{ 0 };

	for (const auto& tile : emptyTiles)
	{
		size_t mcWins{ runMCSim(board, tile) };
		cout << mcWins << " MC wins for tile " << tile << endl;
		if (mcWins > bestNumWins)
		{
			bestTile = tile;
			bestNumWins = mcWins;
		}
	}
	
	return bestTile;
}


void HexAIPlayerNorthSouth::drawMCBoard(HexBoard& board, std::vector<size_t>& emptyTiles, size_t nextMoveIdx)
{

	cout << "\n!!!Current Board of this MC simulation!!!" << endl;
	// connect actual board tiles
	size_t blankCount{ 1 };

	size_t _boardSize{ board.boardSize() };
	DenseUndirectedGraph<TileMarker, size_t> _board{ board._board };

	for (size_t i{ 0 }; i < _boardSize * _boardSize; i++)
	{
		auto ptr = std::find(emptyTiles.begin(), emptyTiles.end(), i);
		if (ptr != emptyTiles.end())
			cout << "o";

		if (i == nextMoveIdx)
			cout << "o";

		switch (_board.getVertexValue(i))
		{
		case TileMarker::EMPTY:
			// fill with little x, which is WE un-played fill for MC simulation
			cout << "x";
			break;
		case TileMarker::X:
			cout << "X";
			break;
		case TileMarker::O:
			cout << "O";
			break;
		}

		// Build the leading spaces & angled stick connections
		if (i % _boardSize == _boardSize - 1 && i != _boardSize * _boardSize - 1)
		{
			cout << endl;
			for (size_t j{ 0 }; j < blankCount; j++)
				cout << " ";
			for (size_t k{ 0 }; k < _boardSize - 1; k++)
				cout << "\\ / ";
			cout << "\\" << endl;
			for (size_t j{ 0 }; j < blankCount + 1; j++)
				cout << " ";

			blankCount += 2;
		}
		else
		{
			if (i != _boardSize * _boardSize - 1)
				cout << " - ";
		}
	}

	cout << "\n\n";
}


WeightedQuickUnionPathCompressionUF HexAIPlayerNorthSouth::buildMCIteration(HexBoard& board, size_t nextMoveIdx)
{
	std::vector<size_t> emptyTiles{ board.emptyTiles() };
	std::remove(emptyTiles.begin(), emptyTiles.end(), nextMoveIdx);
	emptyTiles.erase(emptyTiles.end() - 1, emptyTiles.end());
	std::random_shuffle(emptyTiles.begin(), emptyTiles.end());

	// Need to fill floor(n^2 - 2 * k) tiles with O, and connect them to the UF structure.
	// n = board side length, k = current move number
	size_t endOfHalf{ static_cast<size_t>(floor((emptyTiles.size() - 1) / 2.0)) };

	emptyTiles.erase(emptyTiles.begin() + endOfHalf, emptyTiles.end());

	// drawMCBoard(board, emptyTiles, nextMoveIdx);

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

size_t HexAIPlayerNorthSouth::runMCSim(HexBoard& board, size_t nextMoveIdx)
{
	auto t1 = Clock::now();

	size_t numWins{ 0 };

	size_t n{ board.boardSize() };
	for (size_t i{ 0 }; i < NUM_MC_ITERATIONS; i++)
	{
		WeightedQuickUnionPathCompressionUF mcUFIteration{ buildMCIteration(board, nextMoveIdx) };
		std::pair<size_t, size_t> winTiles = board.northSouthWinTiles();
		if (mcUFIteration.areConnected(winTiles.first, winTiles.second))
		{
			numWins++;
			// cout << "This is a winning MC sim, with " << numWins << " wins out of " << i + 1 << " sims run so far." << endl;
		}
	}
	
	auto t2 = Clock::now();
	//cout << "Time to run " << NUM_MC_ITERATIONS << " Monte Carlo Simulations is "
	//	<< std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << " ms." << endl;

	return numWins;
}

HexAIPlayerNorthSouth::HexAIPlayerNorthSouth()
	: HexAIPlayerNorthSouth{ HexBoard{} }
{
}

HexAIPlayerNorthSouth::HexAIPlayerNorthSouth(HexBoard& board)
	: HexPlayerNorthSouth{ board }
{
}



HexAIPlayerNorthSouth::~HexAIPlayerNorthSouth()
{
}




MoveResult HexAIPlayerNorthSouth::placeMarker(HexBoard& board, const size_t idx)
{
	size_t mcIdx = makeNextMove(board);

	switch (board.isValidIndex(mcIdx))
	{
	case MoveResult::LEGAL:
	{
		board.placeMarker(TileMarker::O, mcIdx);
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

size_t HexAIPlayerNorthSouth::makeNextMove(HexBoard& board)
{
	return bestMoveTile(board);
}


