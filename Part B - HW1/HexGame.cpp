#include "HexGame.h"
#include <iostream>

using namespace std;

HexGame::HexGame()
	: _board{ HexBoard{2} },
	_ns{ HexPlayerNorthSouth{_board} },
	_we{ HexPlayerWestEast{_board} }
{
	cout << "Pick a board size between 2 - 100: " << endl;
	size_t size{ 2 };
	cin >> size;
	
	HexBoard _board{ size };
}


HexGame::~HexGame()
{
}
