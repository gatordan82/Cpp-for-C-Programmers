// HexBoard.cpp
//
// C++ for C Programmers, Part B
// Homework 1: Implement Hex Board
// 
// Hex board representation.  Allows marker placement, and to draw
// an ASCII representation of the board to the console.  Tiles are 
// stored in a DenseUndirectedGraph.
//
// Daniel K. Benjamin
// 2/19/2017

#include "HexBoard.h"
#include <iostream>
#include <algorithm>

using namespace std;

const size_t NUM_VIRTUAL_TILES{ 4 };

HexBoard::HexBoard()
	: HexBoard{ 2 }
{
}

HexBoard::HexBoard(const size_t n)
	: _board{ DenseUndirectedGraph<TileMarker, size_t>{n * n + NUM_VIRTUAL_TILES, } },
	_boardSize{ n },
	_emptyTiles{ std::vector<size_t>(n * n, 0) }
{
	// connect actual board tiles
	for (size_t i{ 0 }; i < n * n - 1; i++)
	{
		// connect right neighbor
		if (i % n != n - 1)
			_board.addEdge(i, i + 1, 1);
		if (i < n * (n - 1))
		{
			// connect down-right neighbor
			_board.addEdge(i, i + n, 1);
			// connect down-left neighbor
			if (i && n != 0)
				_board.addEdge(i, i + n - 1, 1);
		}
	}

	for (size_t i{ 0 }; i < n * n; i++)
		_emptyTiles[i] = i;
}

HexBoard::~HexBoard()
{
}

size_t HexBoard::boardSize() const
{
	return _boardSize;
}

MoveResult HexBoard::isValidIndex(size_t idx) const
{
	if (idx >= 0 && idx < _boardSize * _boardSize)
	{
		if (_board.getVertexValue(idx) == TileMarker::EMPTY)
			return MoveResult::LEGAL;
		else
			return MoveResult::OCCUPIED;
	}
	else return MoveResult::OUT_OF_BOUNDS;
}

void HexBoard::placeMarker(const TileMarker mark, const size_t idx)
{
	_board.setVertexValue(idx, mark);
	remove(_emptyTiles.begin(), _emptyTiles.end(), idx);
}

TileMarker HexBoard::getMarker(const size_t idx) const
{
	return _board.getVertexValue(idx);
}

void HexBoard::drawBoard() const
{
	cout << "\nCurrent Board" << endl;
	// connect actual board tiles
	size_t blankCount{ 1 };

	for (size_t i{ 0 }; i < _boardSize * _boardSize; i++)
	{
		switch (_board.getVertexValue(i))
		{
		case TileMarker::EMPTY:
			cout << ".";
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

void HexBoard::resetBoard()
{
	for (size_t i{ 0 }; i < _board.V(); i++)
		_board.setVertexValue(i, TileMarker::EMPTY);
}

std::pair<size_t, size_t> HexBoard::northSouthWinTiles() const
{
	return std::pair<size_t, size_t>{_boardSize * _boardSize, _boardSize * _boardSize + 3};
}

std::pair<size_t, size_t> HexBoard::westEastWinTiles() const
{
	return std::pair<size_t, size_t>{_boardSize * _boardSize + 1, _boardSize * _boardSize + 2};
}

std::vector<size_t> HexBoard::neighbors(size_t idx) const
{
	return _board.neighbors(idx);
}

std::vector<size_t> HexBoard::emptyTiles() const
{
	return _emptyTiles;
}
