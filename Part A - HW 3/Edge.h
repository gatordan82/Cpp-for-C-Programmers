// Edge.h
//
// C++ for C Programmers, Part A
// Homework 2: Implement Dijkstra's Algorithm
// 
// Generic weighted, undirected, graph edge
//
// Daniel K. Benjamin
// 1/8/2017

#ifndef _EDGE_H
#define _EDGE_H

#include <string>
#include <iostream>

template <class Weight=double>
class Edge
{
private:
	size_t _first;      // first vertex
	size_t _second;		// second vertex
	Weight _weight;		// edge weight

public:
	// constructors
	Edge();
	explicit Edge(size_t v);
	Edge(size_t v, size_t w);
	Edge(size_t v, size_t w, Weight weight);
	Edge(const Edge<Weight>& e);

	// destructor
	virtual ~Edge();

	// copy assignment
	Edge<Weight>& operator=(const Edge<Weight>& e);

	// accessors & mutators
	Weight weight() const;
	void changeWeight(Weight w);
	size_t first() const;
	size_t second() const;
	
	// Comparators: < and > for algorithms, == checks object equality
	bool operator<(const Edge<Weight>& e) const;
	bool operator>(const Edge<Weight>& e) const;
	bool operator==(const Edge<Weight>& e) const; 
	bool operator!=(const Edge<Weight>& e) const;

	// string representation
	template <class Weight=double>
	friend std::ostream& operator<<(std::ostream& os, const Edge<Weight>& e);
	std::string toString() const;
};

// construct a 0 weight edge from vertex 0 to itself
template<class Weight>
inline Edge<Weight>::Edge()
	: Edge(0, 0, 0.0)
{
}

// construct a 0 weight edge from vertex v to vertex 0
template<class Weight>
inline Edge<Weight>::Edge(size_t v)
	: Edge(v, 0, 0.0)
{
}

// construct a 0 weight edge from vertex v to w
template<class Weight>
inline Edge<Weight>::Edge(size_t v, size_t w)
	: Edge(v, w, 0.0)
{
}

// construct an edge from vertex v to w, with weight
template<class Weight>
inline Edge<Weight>::Edge(size_t v, size_t w, Weight weight)
	: _first{ v },
	_second{ w },
	_weight{ weight }
{
}

// copy constructor
template<class Weight>
inline Edge<Weight>::Edge(const Edge<Weight>& e)
	: _first{ e._first },
	_second{ e._second },
	_weight{ e._weight }
{
}

// destructor
template<class Weight>
inline Edge<Weight>::~Edge()
{
}

// copy assignment operator
template<class Weight>
inline Edge<Weight>& Edge<Weight>::operator=(const Edge<Weight>& e)
{
	if (this != &e)
	{
		_first = e._first;
		_second = e._second;
		_weight = e._weight;
	}

	return *this;
}

// return the weight of this edge
template<class Weight>
inline Weight Edge<Weight>::weight() const
{
	return _weight;
}

// change the value of the edge weight
template<class Weight>
inline void Edge<Weight>::changeWeight(Weight w)
{
	_weight = w;
}

// returns the first vertex of the edge
template<class Weight>
inline size_t Edge<Weight>::first() const
{
	return _first;
}

// returns the second vertex of the edge
template<class Weight>
inline size_t Edge<Weight>::second() const
{
	return _second;
}

// returns if the edge weight is less than that of the argument
template<class Weight>
inline bool Edge<Weight>::operator<(const Edge<Weight>& e) const
{
	return (_weight < e._weight);
}

// returns if the edge weight is greater than that of the argument
template<class Weight>
inline bool Edge<Weight>::operator>(const Edge<Weight>& e) const
{
	return (_weight > e._weight);
}

// test for object equality (same vertices, and weight)
template<class Weight>
inline bool Edge<Weight>::operator==(const Edge<Weight>& e) const
{
	return (_first == e._first) 
		&& (_second == e._second) 
		&& (_weight == e._weight);
}

// test if the vertex is not the same, regardless of edge weight
template<class Weight>
inline bool Edge<Weight>::operator!=(const Edge<Weight>& e) const
{
	return (_first != e._first 
		|| _second != e._second);
}

// ostream overloading
template<class Weight>
inline std::ostream& operator<<(std::ostream& os, const Edge<Weight>& e)
{
	return os << e._first << "-" << e._second << ", " << e._weight;
}

// string representation of an edge
template<class Weight>
inline std::string Edge<Weight>::toString() const
{
	return std::to_string(_first)
		+ "-"
		+ std::to_string(_second)
		+ ", "
		+ std::to_string(_weight);
}


#endif // !_EDGE_H


