// DijkstraUndirectedShortestPath.cpp
//
// C++ for C Programmers, Part A
// Homework 2: Implement Dijkstra's Algorithm
// 
// Takes a graph of undirected edges
// Using Dijkstra's algorithm to compute the shortest path
// from a source vertex in that graph
//
// Daniel K. Benjamin
// 1/8/2017

#include "DijkstraUndirectedShortestPath.h"
#include <limits>

using namespace std;

const double infinity{ numeric_limits<double>::infinity() }; 

// construct the shortest path from source to every other vertex in the graph
DijkstraUndirectedShortestPath::DijkstraUndirectedShortestPath(const Graph& g, vertex source)
	: _distTo{ vector<dist>(g.V(), infinity) },
	_edgeTo{ vector<Edge<dist>>(g.V(), Edge<double>{}) },
	_pq{ IndexMinPriorityQueue<dist, vertex>{g.V()} }
{
	_distTo[source] = 0.0;

	_pq.insert(_distTo[source], source);

	// relax the vertices in order of distance from the source
	while (!_pq.isEmpty())
	{
		vertex v = _pq.removeMin();
		for (const edge& e : g.neighbors(v))
			relax(e, v);
	}
}

// destructor
DijkstraUndirectedShortestPath::~DijkstraUndirectedShortestPath()
{
}

// returns the distance of the shortest path from source to sink
const DijkstraUndirectedShortestPath::dist& DijkstraUndirectedShortestPath::distTo(const vertex& sink) const
{
	return _distTo[sink];
}

// return true if source and sink are connected
bool DijkstraUndirectedShortestPath::hasPathTo(const vertex& sink) const
{
	return (_distTo[sink] < infinity);
}

// return the path from source to sink in that order
stack<DijkstraUndirectedShortestPath::edge> DijkstraUndirectedShortestPath::pathTo(const vertex& sink) const
{
	stack<edge> path{};
	
	if (!hasPathTo(sink)) return path;

	vertex x{ sink };
	// last edge in path from source to sink
	edge e{ _edgeTo[sink] };
	// empty edge (
	edge e0{};

	// trace back path from sink to source, adding each to a stack
	// will return stack such that top of stack is first edge from source
	// in the shortest path to the sink
	while (e != e0)
	{
		path.push(e);
		x = e.first();
		e = _edgeTo[x];
	}

	return path;
}

// relax edge, and update priority queue if found a shorter distance edge
void DijkstraUndirectedShortestPath::relax(const edge& e, const vertex& v)
{
	vertex w{ e.second() };
	if (_distTo[w] > _distTo[v] + e.weight())
	{
		_distTo[w] = _distTo[v] + e.weight();
		_edgeTo[w] = e;

		if (_pq.containsIndex(w)) _pq.changeKey(_distTo[w], w);
		else                      _pq.insert(_distTo[w], w);
	}
}
