// Bag.h
//
// C++ for C Programmers, Part A
// Homework 2: Implement Dijkstra's Algorithm
// 
// Abstract un-ordered container of like items
//
// Daniel K. Benjamin
// 1/8/2017

#ifndef _BAG_H
#define _BAG_H

#include <forward_list>
#include <initializer_list>

template <class Item>
class Bag
{
private:
	size_t _N;						// Number of elements in bag
	std::forward_list<Item> _list;  // STL singly-linked list

public:
	// constructors
	Bag();
	Bag(const Bag& b);

	virtual ~Bag();

	Bag& operator=(const Bag& b);

	// Bag API
	bool isEmpty() const;
	size_t size() const;
	void add(Item it);
	void remove(Item it);

	// iterators
	typename std::forward_list<Item>::const_iterator begin() const;
	typename std::forward_list<Item>::const_iterator end() const;
	typename std::forward_list<Item>::iterator begin();
	typename std::forward_list<Item>::iterator end();
};

// Constructor of an empty bag
template<class Item>
inline Bag<Item>::Bag()
	: _N{ 0 }, 
	_list{ std::forward_list<Item>{} }
{
}

// Copy constructor
template<class Item>
inline Bag<Item>::Bag(const Bag<Item>& b)
	: _N{ b._N },
	_list{ b._list }
{
}

// Destructor
template<class Item>
inline Bag<Item>::~Bag()
{
}

// Copy assignment
template<class Item>
inline Bag<Item>& Bag<Item>::operator=(const Bag<Item>& b)
{
	if (this != &b)
	{
		_N = b._N;
		_list = b._list;
	}

	return *this;
}

// Return if there no elements in the bag
template<class Item>
inline bool Bag<Item>::isEmpty() const
{
	return (_N == 0);
}

// Current number of elements stored in the bag
template<class Item>
inline size_t Bag<Item>::size() const
{
	return _N;
}

// Insert an element into the bag
template<class Item>
inline void Bag<Item>::add(Item it)
{
	_list.push_front(it);
	++_N;
}
// Remove an item from the bag
template<class Item>
inline void Bag<Item>::remove(Item it)
{
	_list.remove(it);
	--_N;
}

// Bag (const and non-const) iterators
template<class Item>
typename std::forward_list<Item>::const_iterator Bag<Item>::begin() const
{
	return _list.cbegin();
}

template<class Item>
typename std::forward_list<Item>::const_iterator Bag<Item>::end() const
{
	return _list.cend();
}

template<class Item>
inline typename std::forward_list<Item>::iterator Bag<Item>::begin()
{
	return _list.begin();
}

template<class Item>
inline typename std::forward_list<Item>::iterator Bag<Item>::end()
{
	return _list.end();
}

#endif // !_BAG_H