#ifndef _INDEXPRIORITYQUEUE_H
#define _INDEXPRIORITYQUEUE_H

#include <vector>
#include <algorithm>
#include <functional>
#include <utility>

template <class Key, class Index=size_t>
class IndexPriorityQueue
{
private:
	typedef std::vector<std::pair<Key, Index>> vector;
	vector _heap;

public:
	IndexPriorityQueue();
	IndexPriorityQueue(size_t size);
	IndexPriorityQueue(const IndexPriorityQueue<Key>& pq);

	~IndexPriorityQueue();

	IndexPriorityQueue& operator=(const IndexPriorityQueue<Key>& pq);

	void chgPriority(Index& e, Key priority);
	Key& minPriorityKey();
	Index& minPriorityIndex();
	bool contains(Key& e);
	void insert(Key& e);
	size_t size();
};



#endif

template<class Key, Index>
inline IndexPriorityQueue<Key, Index>::IndexPriorityQueue()
	: _heap(std::vector<std::pair<Key, Index>>{})
{
}

template<class Key>
inline IndexPriorityQueue<Key>::IndexPriorityQueue(const IndexPriorityQueue<Key>& pq)
	: _heap{ pq._heap }
{
}

template<class Key>
inline IndexPriorityQueue<Key>::~IndexPriorityQueue()
{
}

template<class Key>
inline IndexPriorityQueue& IndexPriorityQueue<Key>::operator=(const IndexPriorityQueue<Key>& pq)
{
	if (this != &pq)
		_heap = pq._heap;

	return *this;
}

template<class Key>
inline bool IndexPriorityQueue<Key>::contains(Key& e)
{
	auto ePtr = std::find(_heap.begin(), _heap.end(), e);
	return (ePtr != _heap.end());
}

template<class Key>
inline size_t IndexPriorityQueue<Key>::size()
{
	return _heap.size();
}
