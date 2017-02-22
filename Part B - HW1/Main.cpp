// Main.cpp
//
// C++ for C Programmers, Part B
// Homework 1: Implement Hex Board
// 
// Entry point for starting a game of Hex.  Asks the user what size board
// you want to play on, and then starts the game.
//
// Daniel K. Benjamin
// 2/19/2017

#include <iostream>
#include "DenseUndirectedGraph.h"
#include "HexBoard.h"
#include "HexGame.h"

int main()
{
	using namespace std;

	size_t size{};

	cout << "What size board do you want to play on?" << endl;
	cin >> size;

	HexGame newGame{ size };
	newGame.startGame();

	cin.get();
	cin.get();
	return 0;
}