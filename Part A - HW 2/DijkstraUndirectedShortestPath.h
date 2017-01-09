#ifndef _DIJKSTRAUNDIRECTEDSHORTESTPATH_H
#define _DIJKSTRAUNDIRECTEDSHORTESTPATH_H

#include "Graph.h"
#include "IndexMinPriorityQueue.h"
#include <vector>

class DijkstraUndirectedShortestPath
{
	typedef size_t vertex;
	typedef double dist;

private:
	std::vector<dist> _distTo;
	typedef Edge<dist> edge;
	std::vector<edge> _edgeTo;
	IndexMinPriorityQueue<dist, vertex> _pq;

public:
	DijkstraUndirectedShortestPath() = delete;
	DijkstraUndirectedShortestPath(const Graph& g, vertex source);

	~DijkstraUndirectedShortestPath();

	const dist& distTo(const vertex& sink) const;
	bool hasPathTo(const vertex& sink) const;
	const std::vector<edge>& pathTo(const vertex& sink) const;

private:
	void relax(const edge& e, const vertex& v);

};

#endif

