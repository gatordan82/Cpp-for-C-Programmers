#ifndef _HW2_GRAPH_H
#define _HW2_GRAPH_H

#include "Edge.h"
#include "Bag.h"
#include <vector>
#include <array>

class Graph
{
private:
	size_t _vertices;
	size_t _edges;
	std::vector<Bag<Edge<double>>> _edgeList;

public:
	// Constructors
	Graph();
	explicit Graph(size_t vertices);
	Graph(std::vector<Bag<Edge<double>>> edgeList);
	Graph(size_t vertices, double density, std::array<double, 2> distanceRange);
	Graph(const Graph& g);
	
	// Destructor
	virtual ~Graph();

	// Copy assignment operator
	Graph& operator=(const Graph& g);

	// Graph API methods
	size_t V() const;
	size_t E() const;
	bool areAdjacent(int x, int y) const;
	std::vector<int> neighbors(int x) const;
	int degree(int x) const;
	void addEdge(int x, int y, double edgeValue);
	void deleteEdge(int x, int y);
	double getEdgeValue(int x, int y) const;
	void setEdgeValue(int x, int y, double edgeValue);

	std::string toString() const;

};

#endif

