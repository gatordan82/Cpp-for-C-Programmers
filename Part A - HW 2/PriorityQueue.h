#ifndef _PRIORITYQUEUE_H
#define _PRIORITYQUEUE_H

#include <vector>
#include <algorithm>
#include <functional>

template <class Comparable>
class PriorityQueue
{
private:
	std::vector<Comparable> _heap;

public:
	PriorityQueue();
	PriorityQueue(const PriorityQueue<Comparable>& pq);

	~PriorityQueue();

	PriorityQueue& operator=(const PriorityQueue<Comparable>& pq);

	void chgPriority(Comparable& e, double priority);
	Comparable& minPriority(Comparable& e);
	bool contains(Comparable& e);
	void insert(Comparable& e);
	size_t size();
};



#endif

template<class Comparable>
inline PriorityQueue<Comparable>::PriorityQueue()
	: _heap(std::vector<Comparable>{})
{
}

template<class Comparable>
inline PriorityQueue<Comparable>::PriorityQueue(const PriorityQueue<Comparable>& pq)
	: _heap{ pq._heap }
{
}

template<class Comparable>
inline PriorityQueue<Comparable>::~PriorityQueue()
{
}

template<class Comparable>
inline PriorityQueue & PriorityQueue<Comparable>::operator=(const PriorityQueue<Comparable>& pq)
{
	if (this != &pq)
		_heap = pq._heap;

	return *this;
}

template<class Comparable>
inline bool PriorityQueue<Comparable>::contains(Comparable & e)
{
	auto ePtr = std::find(_heap.begin(), _heap.end(), e);
	return (ePtr != _heap.end());
}

template<class Comparable>
inline size_t PriorityQueue<Comparable>::size()
{
	return _heap.size();
}
