#ifndef _BAG_H
#define _BAG_H

#include <forward_list>
#include <initializer_list>

template <class Item>
class Bag
{
private:
	size_t _N;
	//using forward_list = std::forward_list<Item>;
	std::forward_list<Item> _list;

public:
	// constructors
	Bag();
	Bag(const Bag& b);

	// destructor
	virtual ~Bag();

	// assignment operators
	Bag& operator=(const Bag& b);

	// Bag API
	bool isEmpty() const;
	size_t size() const;
	void add(Item it);
	void remove(Item it);

	// iterators
	//using const_iter = forward_list::const_iterator;
	typename std::forward_list<Item>::const_iterator begin() const;
	typename std::forward_list<Item>::const_iterator end() const;

	//using iter = forward_list::iterator;
	typename std::forward_list<Item>::iterator begin();
	typename std::forward_list<Item>::iterator end();
};




template<class Item>
inline Bag<Item>::Bag()
	: _N{ 0 }, 
	_list{ std::forward_list<Item>{} }
{
}

template<class Item>
inline Bag<Item>::Bag(const Bag<Item>& b)
	: _N{ b._N },
	_list{ b._list }
{
}


template<class Item>
inline Bag<Item>::~Bag()
{
}

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

template<class Item>
inline bool Bag<Item>::isEmpty() const
{
	return (_N == 0);
}

template<class Item>
inline size_t Bag<Item>::size() const
{
	return _N;
}

template<class Item>
inline void Bag<Item>::add(Item it)
{
	_list.push_front(it);
	++_N;
}

template<class Item>
inline void Bag<Item>::remove(Item it)
{
	_list.remove(it);
	--_N;
}

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