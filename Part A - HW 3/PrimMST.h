// PrimMST.h
//
// C++ for C Programmers, Part A
// Homework 3: Compute the minimum spanning tree 
// for an inputted graph
// 
// Prim's algorithm for MST
//
// Daniel K. Benjamin
// 1/13/2017

#ifndef _PRIM_MST_H
#define _PRIM_MST_H

#include "IndexMinPriorityQueue.h"
#include "Graph.h"
#include <vector>

class PrimMST
{
private:
	std::vector<Edge<double>> _edgeTo;  // Shortest edge from tree vertex to non-tree vertex
	std::vector<double> _distTo;        // weight of the shortest edge
	std::vector<bool> _marked;          // true if vertex is on the tree
	IndexMinPriorityQueue<double> _pq;  // priority queue of edges

public:
	// Constructors
	PrimMST() = delete;
	PrimMST(Graph& g);

	// Destructor
	~PrimMST();

	// MST API
	std::vector<Edge<double>> edges();
	double weight();

private:
	// Helper functions
	void prim(Graph& g, size_t source);
	void scan(Graph& g, size_t v);
};

#endif // !_PRIM_MST_H