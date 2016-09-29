#ifndef _HW2_GRAPH_H
#define _HW2_GRAPH_H

#include <vector>


class Graph
{
private:
	int numVertices;
	int numEdges;
	std::vector<std::vector<double>> adjMatrix;

public:
	// Constructors
	Graph();
	explicit Graph(int _numVertices);
	explicit Graph(std::vector<std::vector<double>> _adjMatrix);
	explicit Graph(const Graph& g);
	
	// Destructor
	virtual ~Graph();

	// Copy assignment operator
	Graph& operator=(const Graph& g);

	// Graph API methods
	int V() const;
	int E() const;
	bool areAdjacent(int x, int y) const;
	std::vector<int> neighbors(int x) const;
	void addEdge(int x, int y, double edgeValue);
	void deleteEdge(int x, int y);
	double getEdgeValue(int x) const;
	void setEdgeValue(int x, int y, double edgeValue);


};

#endif

