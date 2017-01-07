#ifndef _INDEXMINPRIORITYQUEUE_H
#define _INDEXMINPRIOIRYTQUEUE_H

#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
#include <exception>

template <class Key, class Index=size_t>
class IndexMinPriorityQueue
{
private:
	typedef std::pair<Key, Index> pair;
	typedef std::vector<pair> vector;
	vector _heap;

public:
	IndexMinPriorityQueue();
	explicit IndexMinPriorityQueue(size_t size);
	IndexMinPriorityQueue(const IndexMinPriorityQueue<Key, Index>& pq);

	~IndexMinPriorityQueue();

	IndexMinPriorityQueue<Key, Index>& operator=(const IndexMinPriorityQueue<Key, Index>& pq);

	bool isEmpty() const;
	bool containsIndex(Index& i) const;
	size_t size() const;
	void insert(Key& k, Index& i);
	Key& minKey() const;
	Index& minIndex() const;
	Index& removeMin();
	Key& keyOf(Index& i) const;
	void changeKey(Key& newPriority, Index& i);
	void delete(Index& i);

};

#endif // !_INDEXMINPRIORITYQUEUE_H

template<class Key, class Index>
inline IndexMinPriorityQueue<Key, Index>::IndexMinPriorityQueue()
	: _heap(vector{})
{
}

template<class Key, class Index>
inline IndexMinPriorityQueue<Key, Index>::IndexMinPriorityQueue(size_t size)
	: _heap(vector{})
{
	_heap.resize(size);
}

template<class Key, class Index>
inline IndexMinPriorityQueue<Key, Index>::IndexMinPriorityQueue(const IndexMinPriorityQueue<Key, Index>& pq)
	: _heap{ pq._heap }
{
}

template<class Key, class Index>
inline IndexMinPriorityQueue<Key, Index>::~IndexMinPriorityQueue()
{
}

template<class Key, class Index>
inline IndexMinPriorityQueue<Key, Index>& IndexMinPriorityQueue<Key, Index>::operator=(const IndexMinPriorityQueue<Key, Index>& pq)
{
	if (&pq != this)
	{
		_heap = pq._heap;
	}

	return *this;
}

template<class Key, class Index>
inline bool IndexMinPriorityQueue<Key, Index>::isEmpty() const
{
	return (_heap.size == 0);
}

template<class Key, class Index>
inline bool IndexMinPriorityQueue<Key, Index>::containsIndex(Index& i) const
{
	const auto& it = std::find_if(_heap.begin(), _heap.end(), 
		[](const pair& p)
	{
		p.second == i;
	});

	return (it != _heap.end());
}

template<class Key, class Index>
inline size_t IndexMinPriorityQueue<Key, Index>::size() const
{
	return _heap.size();
}

template<class Key, class Index>
inline void IndexMinPriorityQueue<Key, Index>::insert(Key& k, Index& i)
{
	_heap.push_back(pair{ k, i });
	std::push_heap(_heap.begin(), _heap.end());
}

template<class Key, class Index>
inline Key& IndexMinPriorityQueue<Key, Index>::minKey() const
{
	if (size() == 0)
		throw std::length_error{ "Priority Queue is empty." };

	return _heap[0].first;
}

template<class Key, class Index>
inline Index& IndexMinPriorityQueue<Key, Index>::minIndex() const
{
	if (size() == 0)
		throw std::length_error{ "Priority Queue is empty." };

	return _heap[0].second;
}

template<class Key, class Index>
inline typename Index& IndexMinPriorityQueue<Key, Index>::removeMin()
{
	if (size() == 0)
		throw std::length_error{ "Priority Queue is empty." };

	std::pop_heap(_heap.begin(), _heap.end());
	
	return _heap.pop_back().second;
}

template<class Key, class Index>
inline Key& IndexMinPriorityQueue<Key, Index>::keyOf(Index& i) const
{
	const auto& it = std::find_if(_heap.begin(), _heap.end(),
		[](const pair& p)
	{
		p.second == i;
	});

	return it->first;
}

template<class Key, class Index>
inline void IndexMinPriorityQueue<Key, Index>::changeKey(Key& newPriority, Index & i)
{
}
