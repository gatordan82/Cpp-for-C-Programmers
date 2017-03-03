// HexBoard.h
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

#ifndef _HEX_BOARD_H
#define _HEX_BOARD_H

#include "DenseUndirectedGraph.h"
#include <utility>
#include <vector>

enum class TileMarker : char { EMPTY, X, O };
enum class MoveResult : char { OCCUPIED, OUT_OF_BOUNDS, LEGAL };

class HexBoard
{
private:
	DenseUndirectedGraph<TileMarker, size_t> _board;
	size_t _boardSize;
	std::vector<size_t> _emptyTiles;

public:
	// Constructors
	HexBoard() = delete;
	HexBoard(const size_t n);

	// Destructor
	~HexBoard();

	// HexBoard API

	// The length of one side of the board
	size_t boardSize() const;
	// Return if an index is on the board
	MoveResult isValidIndex(size_t idx) const;
	// Put marker on the board at the given tile index
	void placeMarker(const TileMarker mark, const size_t idx);
	// Return the marker at a given tile index
	TileMarker getMarker(const size_t idx) const;
	// Draws ASCII representation of the board
	void drawBoard() const;
	// Clears the board of all markers
	void resetBoard();
	// Indices of virtual tiles for north and south edge connections
	std::pair<size_t, size_t> northSouthWinTiles() const;
	// Indices of virtual tiles for eash ant west edge connections
	std::pair<size_t, size_t> westEastWinTiles() const;
	// Returns the neighbor tiles for a given tile index
	std::vector<size_t> neighbors(size_t idx) const;
	// Returns the tiles with no markers yet
	std::vector<size_t> emptyTiles() const;
};

#endif // !_HEX_BOARD_H