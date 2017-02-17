#ifndef _HEX_BOARD_H
#define _HEX_BOARD_H

#include "DenseUndirectedGraph.h"

enum class TileMarker : char { EMPTY, X, O };

class HexBoard
{
private:
	DenseUndirectedGraph<TileMarker, size_t> _board;
	size_t _boardSize;

public:
	HexBoard() = delete;
	HexBoard(const size_t n);

	~HexBoard();

	size_t boardSize() const;
	bool isValidIndex(size_t idx) const;
	void placeMarker(const TileMarker mark, const size_t idx);
	TileMarker getMarker(const size_t idx) const;
	void drawBoard() const;
	void resetBoard();
};

#endif // !_HEX_BOARD_H