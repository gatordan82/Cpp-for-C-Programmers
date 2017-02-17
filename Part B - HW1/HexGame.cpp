#include "HexGame.h"
#include <iostream>

using namespace std;

HexGame::HexGame(size_t size)
	: _board{ HexBoard{size} },
	_ns{ HexPlayerNorthSouth{_board} },
	_we{ HexPlayerWestEast{_board} },
	_blueTurn{ true }
{
}


HexGame::~HexGame()
{
}

void HexGame::startGame()
{
}
