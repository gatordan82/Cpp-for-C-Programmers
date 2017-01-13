// DijkstraUndirectedShortestPath.h
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

#ifndef _DIJKSTRAUNDIRECTEDSHORTESTPATH_H
#define _DIJKSTRAUNDIRECTEDSHORTESTPATH_H

#include "Graph.h"
#include "IndexMinPriorityQueue.h"
#include <vector>
#include <stack>

class DijkstraUndirectedShortestPath
{
	typedef size_t vertex;
	typedef double dist;

private:
	std::vector<dist> _distTo;					// distance from source to a vertex
	typedef Edge<dist> edge;					
	std::vector<edge> _edgeTo;					// the last edge in the shortest path
	IndexMinPriorityQueue<dist, vertex> _pq;    // indexed priority queue

public:
	// constructors
	DijkstraUndirectedShortestPath() = delete;
	DijkstraUndirectedShortestPath(const Graph& g, vertex source);

	// desctructor
	~DijkstraUndirectedShortestPath();

	// Shortest path API
	const dist& distTo(const vertex& sink) const;
	bool hasPathTo(const vertex& sink) const;
	std::stack<edge> pathTo(const vertex& sink) const;

private:
	// relax an edge for performing Dijkstra's algorithm
	void relax(const edge& e, const vertex& v);
};

#endif

