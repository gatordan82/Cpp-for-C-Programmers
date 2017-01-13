#ifndef _MIN_PRIORITY_QUEUE_H
#define _MIN_PRIORITY_QUEUE_H

#include <vector>
#include <exception>

template <class Key=double>
class MinPriorityQueue
{
private:
	std::vector<Key> _pq;
	size_t _N;

public:
	// Constructors
	MinPriorityQueue();
	explicit MinPriorityQueue(size_t initialSize);
	explicit MinPriorityQueue(std::vector<Key> keys);
	MinPriorityQueue(MinPriorityQueue<Key>& minPQ);

	~MinPriorityQueue();

	MinPriorityQueue<Key>& operator=(MinPriorityQueue<Key>& minPQ);

	// Priority Queue API
	bool isEmpty() const;
	size_t size() const;
	const Key& min() const;
	void insert(Key& key);
	Key removeMin();


private:
	// Helper functions
	void sink(size_t k);
	void swim(size_t k);
	bool greater(size_t i, size_t j) const;
	void exchange(size_t i, size_t j);
};

#endif // !_MIN_PRIORITY_QUEUE_H

template<class Key>
inline MinPriorityQueue<Key>::MinPriorityQueue()
	: _pq{ std::vector<Key>{} },
	_N{ 0 }
{
}

template<class Key>
inline MinPriorityQueue<Key>::MinPriorityQueue(size_t initialSize)
	: _pq{ std::vector<Key>{initialSize + 1, Key{}} },
	_N{ 0 }
{
}

template<class Key>
inline MinPriorityQueue<Key>::MinPriorityQueue(std::vector<Key> keys)
	: _pq{ keys },
	_N{ keys.size()}
{
	for (size_t i{ 0 }; i < _N; ++i)
		_pq[i + 1] = keys[i];
	for (size_t k{ _N / 2 }; k >= 1; --k)
		sink(k);
}

template<class Key>
inline MinPriorityQueue<Key>::MinPriorityQueue(MinPriorityQueue<Key>& minPQ)
	: _pq{ minPQ._pq },
	_N{ minPQ._N }
{
}

template<class Key>
inline MinPriorityQueue<Key>::~MinPriorityQueue()
{
}

template<class Key>
inline MinPriorityQueue<Key>& MinPriorityQueue<Key>::operator=(MinPriorityQueue<Key>& minPQ)
{
	if (&minPQ != this)
	{
		_pq = minPQ._pq;
		_N = minPQ._N;
	}

	return *this;
}


template<class Key>
inline bool MinPriorityQueue<Key>::isEmpty() const
{
	return (_N == 0);
}

template<class Key>
inline size_t MinPriorityQueue<Key>::size() const
{
	return _N;
}

template<class Key>
inline const Key& MinPriorityQueue<Key>::min() const
{
	if (isEmpty()) throw std::underflow_error("Priority Queue is empty.");

	return _pq[1];
}

template<class Key>
inline void MinPriorityQueue<Key>::insert(Key& key)
{
	_pq[++_N] = key;
	swim(_N);
}

template<class Key>
inline Key MinPriorityQueue<Key>::removeMin()
{
	if (isEmpty()) throw std::underflow_error("Priority Queue is empty.");

	exchange(1, _N);
	Key min{ _pq[_N--] };
	sink(1);

	return min;
}

template<class Key>
inline void MinPriorityQueue<Key>::sink(size_t k)
{
	while (2 * k <= _N)
	{
		size_t j{ 2 * k };
		if (j < _N && greater(j, j + 1)) j++;
		if (!greater(k, j)) break;
		exchange(k, j);
		k = j;
	}
}

template<class Key>
inline void MinPriorityQueue<Key>::swim(size_t k)
{
	while (k > 1 && greater(k / 2, k))
	{
		exchange(k, k / 2);
		k = k / 2;
	}
}

template<class Key>
inline bool MinPriorityQueue<Key>::greater(size_t i, size_t j) const
{
	return (_pq[i] > _pq[j]);
}

template<class Key>
inline void MinPriorityQueue<Key>::exchange(size_t i, size_t j)
{
	Key swap{ _pq[i] };
	_pq[i] = _pq[j];
	_pq[j] = swap;
}




