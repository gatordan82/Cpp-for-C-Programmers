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

public:
	HexGame();

	~HexGame();

	void startGame();
};

#endif
