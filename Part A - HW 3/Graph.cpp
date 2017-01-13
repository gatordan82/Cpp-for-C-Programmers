// Graph.cpp
//
// C++ for C Programmers, Part A
// Homework 2: Implement Dijkstra's Algorithm
// 
// Graph of undirected edges, with double precision edge weight
// Implemented with the edge list representation
//
// Daniel K. Benjamin
// 1/8/2017

#include "Graph.h"
#include <ctime>
#include <random>
#include <algorithm>
#include <fstream>

using namespace std;

// check if vertex is in the graph
void Graph::validateVertex(int x) const
{
	if (x < 0 || x >= _vertices)
		throw invalid_argument{ "Invalid vertex." };
}

// check if both vertices are in the graph
void Graph::validateVertices(int x, int y) const
{
	if (x < 0 ||
		x >= _vertices ||
		y < 0 ||
		y >= _vertices)

		throw invalid_argument{ "Invalid vertex or vertices." };
}

// construct an empty graph
Graph::Graph()
	: _vertices{ 0 },
	_edges{ 0 }, 
	_edgeLists{ vector<Bag<Edge<double>>>{} },
	_vertexValues{ vector<double>{} }
{
}

// construct a graph of a number of vertices, but no edges
Graph::Graph(size_t vertices)
	: _vertices{ vertices },
	_edges{ 0 },
	_edgeLists{ vector<Bag<Edge<double>>>(vertices, Bag<Edge<double>>{}) },
	_vertexValues{ vector<double>(vertices, 0.0) }
{
}

// construct a graph from a list of edges
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

// construct a graph from a text file of edges
Graph::Graph(std::string inputFileName) : Graph::Graph()
{
	ifstream str{ inputFileName };
	str >> _vertices;

	_edges = 0;
	_edgeLists = vector<Bag<Edge<double>>>(_vertices, Bag<Edge<double>>{});
	_vertexValues = vector<double>(_vertices, 0.0);

	size_t first{ 0 };
	size_t second{ 0 };
	double weight{ 0.0 };

	while (!str.eof())
	{
		str >> first;
		str >> second;
		str >> weight;
		addEdge(first, second, weight);
	}
}

// construct a random graph with known number of vertices
// number of edges depends on the density
// each edge is randomly assigned a weight in the distance range
Graph::Graph(size_t vertices, double density, array<double, 2> distanceRange)
	: _vertices{ vertices },
	_edges{ 0 },
	_edgeLists{ vector<Bag<Edge<double>>>(vertices, Bag<Edge<double>>{}) },
	_vertexValues{ vector<double>(vertices, 0.0) }
{
	uniform_real_distribution<double> prob(0, 1);
	uniform_real_distribution<double> value(distanceRange[0], distanceRange[1]);
	default_random_engine e(time(0));

	for (int i = 0; i < vertices; ++i)
		for (int j = 0; j < i; ++j)
		{
			if (i != j && prob(e) < density)
				addEdge(i, j, value(e));
		}
}

// copy constructor
Graph::Graph(const Graph& g)
	: _vertices{ g._vertices },
	_edges{ g._edges },
	_edgeLists{g._edgeLists},
	_vertexValues{ g._vertexValues }
{
}

// destructor
Graph::~Graph()
{
}

// copy assignment operator
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

// return the number of vertices in the graph
size_t Graph::V() const
{
	return _vertices;
}

// return the number of edges in the graph
size_t Graph::E() const
{
	return _edges;
}

// return true if two vertices are connected with an edge
bool Graph::areAdjacent(int x, int y) const
{
	validateVertices(x, y);

	for (const auto& e : _edgeLists[x])
		if (e.second() == y) return true;

	return false;
}

// return a bag containing the edges to all neighboring (connected) vertices
Bag<Edge<double>> Graph::neighbors(int x) const
{
	validateVertex(x);
	return _edgeLists[x];
}

// return the degree of a given vertex (how many connected edges)
size_t Graph::degree(int x) const
{
	validateVertex(x);
	return _edgeLists[x].size();
}

// add an edge between two vertices, with a given edge weight
void Graph::addEdge(int x, int y, double edgeValue)
{
	validateVertices(x, y);
	++_edges;
	_edgeLists[x].add(Edge<double>(x, y, edgeValue));
	_edgeLists[y].add(Edge<double>(y, x, edgeValue));
}

// remove an edge from two vertices
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

// return the weight of an edge connecting two vertices
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

// change the value of an edge between two vertices
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

// return the value associated with a vertex
double Graph::getVertexValue(int x) const
{
	validateVertex(x);
	return _vertexValues[x];
}

// change the value associated with a vertex
void Graph::setVertexValue(int x, double vertexValue)
{
	validateVertices(x, 0);
	_vertexValues[x] = vertexValue;
}

// string representation of a graph
string Graph::toString() const
{
	string graphString{ "" };

	for (const auto& b : _edgeLists)
		for (const auto& e : b)
			graphString += (e.toString() + "\n");

	return graphString;
}


// overloaded ostream operator, to display all edges
ostream& operator<<(ostream& os, const Graph& g)
{
	for (const auto& bag : g._edgeLists)
		for (const auto& edge : bag)
			os << edge << endl;

	return os;
}
