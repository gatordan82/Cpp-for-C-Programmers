#include "Graph.h"
#include <ctime>
#include <random>
#include <algorithm>

using namespace std;


void Graph::validateVertex(int x) const
{
	if (x < 0 || x >= _vertices)
		throw invalid_argument{ "Invalid vertex." };
}

void Graph::validateVertices(int x, int y) const
{
	if (x < 0 ||
		x >= _vertices ||
		y < 0 ||
		y >= _vertices)

		throw invalid_argument{ "Invalid vertex or vertices." };
}

Graph::Graph()
	: _vertices{ 0 },
	_edges{ 0 }, 
	_edgeLists{ vector<Bag<Edge<double>>>{} },
	_vertexValues{ vector<double>{} }
{
}

Graph::Graph(size_t vertices)
	: _vertices{ vertices },
	_edges{ 0 },
	_edgeLists{ vector<Bag<Edge<double>>>(vertices, Bag<Edge<double>>{}) },
	_vertexValues{ vector<double>(vertices, 0.0) }
{
}

Graph::Graph(vector<Bag<Edge<double>>> edgeLists)
	: _vertices{ edgeLists.size() },
	_edges{ 0 },
	_edgeLists{ edgeLists },
	_vertexValues{ vector<double>(_vertices, 0.0) }
{
	for (const auto& b : edgeLists)
		_edges += b.size();
	
	_edges /= 2;
}

Graph::Graph(size_t vertices, double density, array<double, 2> distanceRange)
	: _vertices{ vertices },
	_edges{ 0 },
	_edgeLists{ vector<Bag<Edge<double>>>(vertices, Bag<Edge<double>>{}) },
	_vertexValues{ vector<double>(vertices, 0.0) }
{
	uniform_real_distribution<double> prob(0, 1);
	uniform_real_distribution<double> value(distanceRange[0], distanceRange[1]);
	default_random_engine e(time(0));

	for (int i = 0; i < _vertices; ++i)
		for (int j = 0; j <= i; ++j)
			if (prob(e) < density) addEdge(i, j, value(e));
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
		_vertexValues = g._vertexValues;
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
	validateVertices(x, y);

	for (const auto& e : _edgeLists[x])
		if (e.second() == y) return true;

	return false;
}

Bag<Edge<double>> Graph::neighbors(int x) const
{
	validateVertex(x);
	return _edgeLists[x];
}

size_t Graph::degree(int x) const
{
	validateVertex(x);
	return _edgeLists[x].size();
}

void Graph::addEdge(int x, int y, double edgeValue)
{
	validateVertices(x, y);
	++_edges;
	_edgeLists[x].add(Edge<double>(x, y, edgeValue));
	_edgeLists[y].add(Edge<double>(y, x, edgeValue));
}

void Graph::deleteEdge(int x, int y)
{
	validateVertices(x, y);
	if (areAdjacent(x, y))
	{
		--_edges;
		Bag<Edge<double>>& xList = _edgeLists[x];
		for (auto& e : _edgeLists[x])
			if (e.second() == y) xList.remove(e);

		Bag<Edge<double>>& yList = _edgeLists[y];
		for (auto& e : yList)
			if (e.second() == x) yList.remove(e);
	}
	else throw invalid_argument{ "Edge doesn't exist." };
}

double Graph::getEdgeValue(int x, int y) const
{
	validateVertices(x, y);
	if (areAdjacent(x, y))
	{
		auto& xList = _edgeLists[x];
		for (auto& e : xList)
			if (e.second() == y) return e.weight();
	}
	else throw invalid_argument{ "Vertices are not connected." };
}

void Graph::setEdgeValue(int x, int y, double edgeValue)
{
	validateVertices(x, y);
	if (areAdjacent(x, y))
	{
		auto& xList = _edgeLists[x];
		for (auto& e : xList)
			if (e.second() == y) e.changeWeight(edgeValue);

		auto& yList = _edgeLists[y];
		for (auto& e : yList)
			if (e.second() == x) e.changeWeight(edgeValue);
	}
}

double Graph::getVertexValue(int x) const
{
	validateVertex(x);
	return _vertexValues[x];
}

void Graph::setVertexValue(int x, double vertexValue)
{
	validateVertices(x, 0);
	_vertexValues[x] = vertexValue;
}

string Graph::toString() const
{
	string graphString{ "" };

	for (const auto& b : _edgeLists)
		for (const auto& e : b)
			graphString += (e.toString() + "\n");

	return graphString;
}
