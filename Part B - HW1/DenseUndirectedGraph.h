#ifndef _DENSE_UNDIRECTED_GRAPH_H
#define	_DENSE_UNDIRECTED_GRAPH_H

#include <iostream>
#include <vector>
#include <stdexcept>


template <class NodeValue, class EdgeValue>
class DenseUndirectedGraph {
private:
	size_t _vertices;							// current number of vertices
	size_t _edges;								// current number of edges
	std::vector<std::vector<EdgeValue>> _adjacencyMatrix;  // List of edges from each vertex
	std::vector<NodeValue> _vertexValues;			// current value of each vertex

	void validateVertex(size_t x) const;	        // check if vertex is in the graph
	void validateVertices(size_t x, size_t y) const;  // check if two vertices are both in the graph

public:
	// Constructors
	DenseUndirectedGraph() = delete;
	explicit DenseUndirectedGraph(size_t vertices);
	DenseUndirectedGraph(const DenseUndirectedGraph& g);

	// Destructor
	virtual ~DenseUndirectedGraph();

	// Copy assignment operator
	DenseUndirectedGraph& operator=(const DenseUndirectedGraph& g);

	// Graph API methods
	size_t V() const;
	size_t E() const;
	bool areAdjacent(size_t x, size_t y) const;
	std::vector<size_t> neighbors(size_t x) const;
	size_t degree(size_t x) const;
	void addEdge(size_t x, size_t y, EdgeValue edgeValue);
	void deleteEdge(size_t x, size_t y);
	EdgeValue getEdgeValue(size_t x, size_t y) const;
	void setEdgeValue(size_t x, size_t y, EdgeValue edgeValue);
	NodeValue getVertexValue(size_t x) const;
	void setVertexValue(size_t x, NodeValue vertexValue);

	template<class NodeValue, class EdgeValue>
	friend std::ostream& operator<<(std::ostream& os, const DenseUndirectedGraph<NodeValue, EdgeValue>& g);
};



template<class NodeValue, class EdgeValue>
inline void DenseUndirectedGraph<NodeValue, EdgeValue>::validateVertex(size_t x) const
{
	if (x < 0 || x >= _vertices)
		throw invalid_argument{ "Invalid vertex." };
}

template<class NodeValue, class EdgeValue>
inline void DenseUndirectedGraph<NodeValue, EdgeValue>::validateVertices(size_t x, size_t y) const
{
	if (x < 0 ||
		x >= _vertices ||
		y < 0 ||
		y >= _vertices)

		throw std::invalid_argument{ "Invalid vertex or vertices." };
}

template<class NodeValue, class EdgeValue>
inline DenseUndirectedGraph<NodeValue, EdgeValue>::DenseUndirectedGraph(size_t vertices)
	: _vertices{ vertices }, 
	_edges{ 0 },
	_adjacencyMatrix{ std::vector<std::vector<EdgeValue>>(vertices, std::vector<EdgeValue>(vertices, EdgeValue{})) },
	_vertexValues{ std::vector<NodeValue>(vertices, NodeValue{}) }
{
}

template<class NodeValue, class EdgeValue>
inline DenseUndirectedGraph<NodeValue, EdgeValue>::DenseUndirectedGraph(const DenseUndirectedGraph<NodeValue, EdgeValue>& g)
	: _vertices{ g._vertices },
	_edges{ g._edges },
	_adjacencyMatrix{ g._adjacencyMatrix },
	_vertexValues{ g._vertexValues }
{
}

template<class NodeValue, class EdgeValue>
inline DenseUndirectedGraph<NodeValue, EdgeValue>::~DenseUndirectedGraph()
{
}

template<class NodeValue, class EdgeValue>
inline DenseUndirectedGraph<NodeValue, EdgeValue>& DenseUndirectedGraph<NodeValue, EdgeValue>::operator=(const DenseUndirectedGraph<NodeValue, EdgeValue>& g)
{
	if (this != &g)
	{
		_vertices = g._vertices;
		_edges = g._edges;
		_adjacencyMatrix = g._adjacencyMatrix;
		_vertexValues = g._vertexValues;
	}

	return *this;
}

template<class NodeValue, class EdgeValue>
inline size_t DenseUndirectedGraph<NodeValue, EdgeValue>::V() const
{
	return _vertices;
}

template<class NodeValue, class EdgeValue>
inline size_t DenseUndirectedGraph<NodeValue, EdgeValue>::E() const
{
	return _edges;
}

template<class NodeValue, class EdgeValue>
inline bool DenseUndirectedGraph<NodeValue, EdgeValue>::areAdjacent(size_t x, size_t y) const
{
	validateVertices(x, y);

	if (_adjacencyMatrix[x][y] != EdgeValue{})
		return true;

	return false;
}

template<class NodeValue, class EdgeValue>
inline std::vector<size_t> DenseUndirectedGraph<NodeValue, EdgeValue>::neighbors(size_t x) const
{
	validateVertex(x);

	std::vector<size_t> neighborList{};

	for (size_t i{ 0 }; i < _vertices; ++i)
		if (_adjacencyMatrix[x][i] != EdgeValue{} && i != x)
			neighborList.push_back(i);

	return neighborList;
}

template<class NodeValue, class EdgeValue>
inline size_t DenseUndirectedGraph<NodeValue, EdgeValue>::degree(size_t x) const
{
	return neighbors(x).size();
}

template<class NodeValue, class EdgeValue>
inline void DenseUndirectedGraph<NodeValue, EdgeValue>::addEdge(size_t x, size_t y, EdgeValue edgeValue)
{
	validateVertices(x, y);
	if (_adjacencyMatrix[x][y] != EdgeValue{})
		throw std::invalid_argument{ "An Edge already exists between these two vertices." };

	++_edges;
	_adjacencyMatrix[x][y] = _adjacencyMatrix[y][x] = edgeValue;
}

template<class NodeValue, class EdgeValue>
inline void DenseUndirectedGraph<NodeValue, EdgeValue>::deleteEdge(size_t x, size_t y)
{
	validateVertices(x, y);
	if (_adjacencyMatrix[x][y] == EdgeValue{})
		throw std::invalid_argument{ "There is no edge between these vertices." };

	_adjacencyMatrix[x][y] = _adjacencyMatrix[y][x] = EdgeValue{};
}

template<class NodeValue, class EdgeValue>
inline EdgeValue DenseUndirectedGraph<NodeValue, EdgeValue>::getEdgeValue(size_t x, size_t y) const
{
	validateVertices(x, y);

	return _adjacencyMatrix[x][y];
}

template<class NodeValue, class EdgeValue>
inline void DenseUndirectedGraph<NodeValue, EdgeValue>::setEdgeValue(size_t x, size_t y, EdgeValue edgeValue)
{
	validateVertices(x, y);

	_adjacencyMatrix[x][y] = _adjacencyMatrix[y][x] = edgeValue;
}

template<class NodeValue, class EdgeValue>
inline NodeValue DenseUndirectedGraph<NodeValue, EdgeValue>::getVertexValue(size_t x) const
{
	validateVertex(x);

	return _vertexValues[x];
}

template<class NodeValue, class EdgeValue>
inline void DenseUndirectedGraph<NodeValue, EdgeValue>::setVertexValue(size_t x, NodeValue vertexValue)
{
	validateVertex(x);

	_vertexValues[x] = vertexValue;
}

template<class NodeValue, class EdgeValue>
std::ostream& operator<<(std::ostream& os, const DenseUndirectedGraph<NodeValue, EdgeValue>& g)
{
	for (size_t x{ 0 }; x < g._vertices; x++)
	{
		for (size_t y{ x }; y < g._vertices; y++)
		{
			if (g._adjacencyMatrix[x][y] != EdgeValue{})
				os << x << "-" << y << ", " << g._adjacencyMatrix[x][y] << std::endl;
		}
	}

	return os;
}

#endif // !_DENSE_UNDIRECTED_GRAPH_H