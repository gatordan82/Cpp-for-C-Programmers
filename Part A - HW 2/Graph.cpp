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

Graph::Graph(const Graph& g)
	: _vertices{ g._vertices },
	_edges{ g._edges },
	_edgeList{g._edgeList}
{
}

Graph::~Graph()
{
}

Graph& Graph::operator=(const Graph& g)
{
	if (this != &g)
	{
		_vertices = g._vertices;
		_edges = g._edges;
		_edgeList = g._edgeList;
	}

	return *this;
}

size_t Graph::V() const
{
	return _vertices;
}

size_t Graph::E() const
{
	return _edges;
}

bool Graph::areAdjacent(int x, int y) const
{
	Bag<Edge<double>> vertexEdgeList = _edgeList[x];
	for (const auto& e : vertexEdgeList)
		if (e.second() == y)
			return true;

	return false;
}

std::vector<int> Graph::neighbors(int x) const
{
	return _edgeList[x];
}

int Graph::degree(int x) const
{
	return _edgeList[x].size();
}

void Graph::addEdge(int x, int y, double edgeValue)
{
	_edgeList[x].add(Edge<double>(x, y, edgeValue));
	_edgeList[y].add(Edge<double>(y, x, edgeValue));
}

void Graph::deleteEdge(int x, int y)
{
	Bag<Edge<double>> xList = _edgeList[x];
	Bag<Edge<double>> yList = _edgeList[y];

	for (const auto& e : xList)
	{
		if (e.second() == y)
			;
	}

	for (const auto& e : yList)
	{
		if (e.second() == x)
			;
	}
}

double Graph::getEdgeValue(int x, int y) const
{
	if (areAdjacent(x, y))
	{
		Bag<Edge<double>> vertexList = _edgeList[x];
		for (const auto& e : vertexList)
		{
			if (e.second() == y)
				return e.weight();
		}
	}
}
