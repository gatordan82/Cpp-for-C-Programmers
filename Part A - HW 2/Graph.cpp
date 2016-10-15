#include "Graph.h"
#include <ctime>
#include <random>

Graph::Graph()
	: _vertices{ 0 },
	_edges{ 0 }
{
	std::vector<Bag<Edge<double>>> _edgeList;
}

Graph::Graph(size_t vertices)
	: _vertices{ vertices },
	_edges{ 0 }
{
	std::vector<Bag<Edge<double>>> _edgeList(_vertices, Bag<Edge<double>>());
}

Graph::Graph(std::vector<Bag<Edge<double>>> edgeList)
	: _vertices{ edgeList.size() },
	_edgeList{ edgeList }
{
	size_t _edges{ 0 };
	for (const auto& b : edgeList)
		_edges += b.size();
	
	_edges /= 2;
}

Graph::Graph(size_t vertices, double density, std::array<double, 2> distanceRange)
	: _vertices{ vertices }
{

}
