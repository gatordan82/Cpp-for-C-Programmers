#include "Graph.h"
#include <ctime>
#include <random>


Graph::Graph()
	: _vertices{ 0 },
	_edges{ 0 }
{
	std::vector<Bag<Edge<double>>> _edgeLists{};
	std::vector<double> _vertexValues{};
}

Graph::Graph(size_t vertices)
	: _vertices{ vertices },
	_edges{ 0 }
{
	std::vector<Bag<Edge<double>>> _edgeLists(_vertices, Bag<Edge<double>>());
	std::vector<double> _vertexValues{};
}

Graph::Graph(std::vector<Bag<Edge<double>>> edgeLists)
	: _vertices{ edgeLists.size() },
	_edgeLists{ edgeLists }
{
	size_t _edges{ 0 };
	for (const auto& b : edgeLists)
		_edges += b.size();
	
	_edges /= 2;

	std::vector<double> _vertexValues{};
}

Graph::Graph(size_t vertices, double density, std::array<double, 2> distanceRange)
	: _vertices{ vertices }
{
	std::uniform_real_distribution<double> prob(0, 1);
	std::uniform_real_distribution<double> value(distanceRange[0], distanceRange[1]);
	std::default_random_engine e(time(0));

	for (int i = 0; i < _vertices; ++i)
		for (int j = 0; j <= i; ++j)
		{
			if (prob(e) < density)
				addEdge(i, j, value(e));
		}
}

Graph::Graph(const Graph& g)
	: _vertices{ g._vertices },
	_edges{ g._edges },
	_edgeLists{g._edgeLists},
	_vertexValues{ g._vertexValues }
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
		_edgeLists = g._edgeLists;
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
	Bag<Edge<double>> xList = _edgeLists[x];
	for (const auto& e : xList)
		if (e.second() == y)
			return true;

	return false;
}

Bag<Edge<double>> Graph::neighbors(int x) const
{
	return _edgeLists[x];
}

size_t Graph::degree(int x) const
{
	return _edgeLists[x].size();
}

void Graph::addEdge(int x, int y, double edgeValue)
{
	_edgeLists[x].add(Edge<double>(x, y, edgeValue));
	_edgeLists[y].add(Edge<double>(y, x, edgeValue));
}

void Graph::deleteEdge(int x, int y)
{
	Bag<Edge<double>> xList = _edgeLists[x];
	Bag<Edge<double>> yList = _edgeLists[y];

	for (auto& e : xList)
	{
		if (e.second() == y)
			xList.remove(e);
	}

	for (auto& e : yList)
	{
		if (e.second() == x)
			yList.remove(e);
	}
}

double Graph::getEdgeValue(int x, int y) const
{
	if (areAdjacent(x, y))
	{
		Bag<Edge<double>> vertexList = _edgeLists[x];
		for (const auto& e : vertexList)
		{
			if (e.second() == y)
				return e.weight();
		}
	}
}

void Graph::setEdgeValue(int x, int y, double edgeValue)
{
	Bag<Edge<double>> xList = _edgeLists[x];

}
