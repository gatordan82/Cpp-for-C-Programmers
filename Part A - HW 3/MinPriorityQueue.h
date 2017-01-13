#ifndef _MIN_PRIORITY_QUEUE_H
#define _MIN_PRIORITY_QUEUE_H

#include <vector>

template <class Key=double>
class MinPriorityQueue
{
private:
	std::vector<Key> _pq;
	size_t N;


public:
	MinPriorityQueue();
	MinPriorityQueue(size_t initialCapacity);


};

#endif // !_MIN_PRIORITY_QUEUE_H
