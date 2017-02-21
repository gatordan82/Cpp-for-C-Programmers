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

public:
	HexBoard() = delete;
	HexBoard(const size_t n);

	~HexBoard();

	size_t boardSize() const;
	MoveResult isValidIndex(size_t idx) const;
	void placeMarker(const TileMarker mark, const size_t idx);
	TileMarker getMarker(const size_t idx) const;
	void drawBoard() const;
	void resetBoard();
	std::pair<size_t, size_t> northSouthWinTiles() const;
	std::pair<size_t, size_t> westEastWinTiles() const;
	std::vector<size_t> neighbors(size_t idx) const;
};

#endif // !_HEX_BOARD_H