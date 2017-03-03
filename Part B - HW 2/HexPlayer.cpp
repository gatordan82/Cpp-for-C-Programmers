// HexPlayer.cpp
//
// C++ for C Programmers, Part B
// Homework 1: Implement Hex Board
// 
// Base Hex player class.  Stores the marker type, and has
// pure virtual functions for identification, marker placement,
// and checking whether or not the player has won.
//
// Daniel K. Benjamin
// 2/19/2017

#include "HexPlayer.h"

HexPlayer::HexPlayer(const TileMarker mark)
	: _mark{ mark }
{
}


HexPlayer::~HexPlayer()
{
}

