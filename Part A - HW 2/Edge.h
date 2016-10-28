#ifndef _EDGE_H
#define _EDGE_H

#include <string>
#include <iostream>

template <class Weight>
class Edge
{
private:
	size_t _first;
	size_t _second;
	Weight _weight;

public:
	Edge();
	explicit Edge(size_t v);
	Edge(size_t v, size_t w);
	Edge(size_t v, size_t w, Weight weight);
	Edge(const Edge<Weight>& e);

	virtual ~Edge();

	Edge<Weight>& operator=(const Edge<Weight>& e);

	Weight weight() const;
	void changeWeight(Weight w);

	size_t first() const;
	size_t second() const;

	bool operator<(const Edge<Weight>& e) const;
	bool operator>(const Edge<Weight>& e) const;
	bool operator==(const Edge<Weight>& e) const;
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
inline Edge<Weight>::Edge(size_t v)
	: _first{ v },
	_second{ 0 },
	_weight{ 0.0 }
{
}

template<class Weight>
inline Edge<Weight>::Edge(size_t v, size_t w)
	: _first{ v },
	_second{ w },
	_weight{ 0.0 }
{
}

template<class Weight>
inline Edge<Weight>::Edge(size_t v, size_t w, Weight weight)
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
inline Weight Edge<Weight>::weight() const
{
	return _weight;
}

template<class Weight>
inline void Edge<Weight>::changeWeight(Weight w)
{
	_weight = w;
}

template<class Weight>
inline size_t Edge<Weight>::first() const
{
	return _first;
}

template<class Weight>
inline size_t Edge<Weight>::second() const
{
	return _second;
}

template<class Weight>
inline bool Edge<Weight>::operator<(const Edge<Weight>& e) const
{
	return (_weight < e._weight);
}

template<class Weight>
inline bool Edge<Weight>::operator>(const Edge<Weight>& e) const
{
	return (_weight > e._weight);
}

template<class Weight>
inline bool Edge<Weight>::operator==(const Edge<Weight>& e) const
{
	return (_first == e._first) 
		&& (_second == e._second) 
		&& (_weight == e._weight);
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


