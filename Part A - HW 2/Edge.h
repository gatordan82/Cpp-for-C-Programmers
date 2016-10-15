#ifndef _EDGE_H
#define _EDGE_H

#include <string>
#include <iostream>

template <class Weight>
class Edge
{
private:
	int _first;
	int _second;
	Weight _weight;

public:
	Edge();
	explicit Edge(int v);
	Edge(int v, int w);
	Edge(int v, int w, Weight weight);
	Edge(const Edge<Weight>& e);

	virtual ~Edge();

	Edge<Weight>& operator=(const Edge<Weight>& e);

	Weight weight();
	int either();
	int other();

	bool operator<(Edge e);
	std::string toString() const;
};


#endif // !_EDGE_H



template<class Weight>
inline Edge<Weight>::Edge()
	: _first{ 0 },
	_second{ 0 },
	_weight{ 0.0 }
{
}

template<class Weight>
inline Edge<Weight>::Edge(int v)
	: _first{ v },
	_second{ 0 },
	_weight{ 0.0 }
{
}

template<class Weight>
inline Edge<Weight>::Edge(int v, int w)
	: _first{ v },
	_second{ w },
	_weight{ 0.0 }
{
}

template<class Weight>
inline Edge<Weight>::Edge(int v, int w, Weight weight)
	: _first{ v },
	_second{ w },
	_weight{ weight }
{
}

template<class Weight>
inline Edge<Weight>::Edge(const Edge<Weight>& e)
	: _first{ e._first },
	_second{ e._second },
	_weight{ e._weight }
{
}

template<class Weight>
inline Edge<Weight>::~Edge()
{
}

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

template<class Weight>
inline Weight Edge<Weight>::weight()
{
	return _weight;
}

template<class Weight>
inline int Edge<Weight>::either()
{
	return _first;
}

template<class Weight>
inline int Edge<Weight>::other()
{
	return _second;
}

template<class Weight>
inline bool Edge<Weight>::operator<(Edge e)
{
	return (_weight < e._weight);
}


template<class Weight>
inline std::string Edge<Weight>::toString() const
{
	return std::to_string(_first)
		+ "-"
		+ std::to_string(_second)
		+ ", "
		+ std::to_string(_weight);
}


