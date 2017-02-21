#ifndef _HEX_GAME_H
#define _HEX_GAME_H

#include "HexBoard.h"
#include "HexPlayerNorthSouth.h"
#include "HexPlayerWestEast.h"

class HexGame
{
private:
	HexBoard _board;
	HexPlayerNorthSouth _ns;
	HexPlayerWestEast _we;
	bool _blueTurn;

	size_t coordsToIndex(size_t i, size_t j);

public:
	HexGame() = delete;
	HexGame(size_t size);

	~HexGame();

	void startGame();
	bool takeTurn(HexPlayer& player);
};

#endif
