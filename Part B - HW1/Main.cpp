#include <iostream>
#include "DenseUndirectedGraph.h"


enum class TileMarker : char { NULL_TILE, DOT, X, O };


inline std::ostream& operator<<(std::ostream& os, const TileMarker& mark)
{
	switch (mark)
	{
	case TileMarker::DOT:
		os << ".";
		break;
	case TileMarker::X:
		os << "X";
		break;
	case TileMarker::O:
		os << "O";
		break;
	default:
		break;
	}

	return os;
}


int main()
{
	using namespace std;


	

	DenseUndirectedGraph<int, TileMarker> test{ 5 };

	test.addEdge(1, 2, TileMarker::DOT);

	cout << "Are nodes 1 & 2 connected? " << boolalpha << test.areAdjacent(1, 2) << endl;
	cout << test << endl;

	cin.get();
	cin.get();
	return 0;
}