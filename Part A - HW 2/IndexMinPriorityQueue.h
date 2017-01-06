#ifndef _INDEXMINPRIORITYQUEUE_H
#define _INDEXMINPRIOIRYTQUEUE_H

#include <vector>
#include <algorithm>
#include <functional>
#include <utility>

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
	pair& removeMin();
	Key& keyOf(Index& i);
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
{
}
