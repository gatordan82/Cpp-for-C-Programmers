#include <iostream>
#include "DenseUndirectedGraph.h"
#include "HexBoard.h"
#include "HexGame.h"


int main()
{
	using namespace std;

	HexBoard test{ 7 };

	////test.placeMarker(TileMarker::X, 13);
	////test.placeMarker(TileMarker::O, 25);
	//test.placeMarker(TileMarker::X, 0);

	//test.drawBoard();

	//test.placeMarker(TileMarker::O, 1);
	//test.drawBoard();

	//test.placeMarker(TileMarker::X, 4);
	//test.drawBoard();
	size_t size{};

	cout << "What size board do you want to play on?" << endl;
	cin >> size;

	HexGame newGame{ size };

	newGame.startGame();

	cin.get();
	cin.get();
	return 0;
}