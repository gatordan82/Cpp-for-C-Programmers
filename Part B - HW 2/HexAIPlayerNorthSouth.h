#ifndef _HEX_AI_PLAYER_NORTH_SOUTH_H
#define _HEX_AI_PLAYER_NORTH_SOUTH_H


#include "HexPlayer.h"



class HexAIPlayerNorthSouth :
	public HexPlayer
{
private:
	WeightedQuickUnionPathCompressionUF _uf;
	// Place a marker on the board, and make all adjacent marker connections
	MoveResult placeMarker(HexBoard& board, const size_t idx);

	size_t bestMoveTile(HexBoard& board);


public:
	// Constructors
	HexAIPlayerNorthSouth() = delete;
	HexAIPlayerNorthSouth(HexBoard& board);

	// Destructor
	~HexAIPlayerNorthSouth();

	MoveResult makeNextMove(HexBoard& board);
	// Check if the two appropriate edges are connected
	bool hasWon(HexBoard& board);
	// Output the player color to the console
	void color() const;
};

#endif // !_HEX_AI_PLAYER_NORTH_SOUTH_H