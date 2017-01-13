// Graph.h
//
// C++ for C Programmers, Part A
// Homework 3: Compute the minimum spanning tree 
// for an inputted graph
// 
// Graph of undirected edges, with double precision edge weight
// Implemented with the edge list representation
//
// Daniel K. Benjamin
// 1/13/2017

#ifndef _HW2_GRAPH_H
#define _HW2_GRAPH_H

#include "Edge.h"
#include "Bag.h"
#include <vector>
#include <array>
#include <algorithm>
#include <iostream>
#include <string>

class Graph
{
private:
	size_t _vertices;							// current number of vertices
	size_t _edges;								// current number of edges
	std::vector<Bag<Edge<double>>> _edgeLists;  // List of edges from each vertex
	std::vector<double> _vertexValues;			// current value of each vertex

	void validateVertex(int x) const;	        // check if vertex is in the graph
	void validateVertices(int x, int y) const;  // check if two vertices are both in the graph

public:
	// Constructors
	Graph();
	explicit Graph(size_t vertices);
	explicit Graph(std::vector<Bag<Edge<double>>> edgeList);
	explicit Graph(std::string inputFileName);
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
	Bag<Edge<double>> neighbors(int x) const;
	size_t degree(int x) const;
	void addEdge(int x, int y, double edgeValue);
	void deleteEdge(int x, int y);
	double getEdgeValue(int x, int y) const;
	void setEdgeValue(int x, int y, double edgeValue);
	double getVertexValue(int x) const;
	void setVertexValue(int x, double vertexValue);

	friend std::ostream& operator<<(std::ostream& os, const Graph& g);
	std::string toString() const;


};

#endif

