#ifndef _PRIORITYQUEUE_H
#define _PRIORITYQUEUE_H

#include <vector>
#include <queue>
#include <functional>
#include "Graph.h"

template <class Comparable>
class PriorityQueue
{
private:
	std::priority_queue<Comparable, std::vector<Comparable>, std::greater<Comparable>> _pq;
	size_t _size;

public:
	PriorityQueue();
	PriorityQueue(const PriorityQueue<Comprable>& pq);

	~PriorityQueue();

	PriorityQueue& operator=(const PriorityQueue<Comparable>& pq);

	void chgPriority(Comparable& e, double priority);
	Comparable& minPriority(Comparable& e);
	bool contains(Comparable& e);
	void insert(Comparable& e);
	Comparable& top();
	size_t size();
};



#endif