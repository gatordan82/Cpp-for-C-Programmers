// PrimMST.cpp
//
// C++ for C Programmers, Part A
// Homework 3: Compute the minimum spanning tree 
// for an inputted graph
// 
// Prim's algorithm for MST
//
// Daniel K. Benjamin
// 1/13/2017

#include "PrimMST.h"
#include <limits>

using namespace std;

const double infinity{ numeric_limits<double>::infinity() };

// Constructor that performs the algorithm
PrimMST::PrimMST(Graph& g)
	: _edgeTo{ vector<Edge<double>>(g.V(), Edge<double>{}) },
	_distTo{ vector<double>(g.V(), infinity) },
	_marked{ vector<bool>(g.V(), false) },
	_pq{ IndexMinPriorityQueue<double>{g.V()} }
{
	for (size_t v{ 0 }; v < g.V(); v++)
		if (!_marked[v]) 
			prim(g, v);
}

// Destructor
PrimMST::~PrimMST()
{
}

// Returns the list of edges in the MST as a vector
std::vector<Edge<double>> PrimMST::edges()
{
	vector<Edge<double>> mst{};

	Edge<double> e0{};

	for (size_t v{ 0 }; v < _edgeTo.size(); v++)
	{
		Edge<double> e = _edgeTo[v];
		if (e != e0)
			mst.push_back(e);
	}

	return mst;
}

// Returns the total weight of the MST
double PrimMST::weight()
{
	double weight{ 0.0 };

	for (const auto& e : edges())
		weight += e.weight();

	return weight;
}

// Run Prim's algorithm, starting from the source vertex
void PrimMST::prim(Graph& g, size_t source)
{
	_distTo[source] = 0.0;
	_pq.insert(_distTo[source], source);

	while (!_pq.isEmpty())
	{
		size_t v{ _pq.removeMin() };
		scan(g, v);
	}
}

// Scans the vertex v for the next shortest edge
void PrimMST::scan(Graph& g, size_t v)
{
	_marked[v] = true;

	for (const auto& e : g.neighbors(v))
	{
		size_t w{ e.other(v) };
		if (_marked[w]) continue;
		if (e.weight() < _distTo[w])
		{
			_distTo[w] = e.weight();
			_edgeTo[w] = e;

			if (_pq.containsIndex(w))
				_pq.changeKey(_distTo[w], w);
			else
				_pq.insert(_distTo[w], w);
		}
	}
}
