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
	const Index DNE{static_cast<Index>(-1)}; // index does not exist
	size_t _maxN;
	size_t _N;
	std::vector<Index> _pq;
	std::vector<Index> _qp;
	std::vector<Key> _keys;

public:
	IndexMinPriorityQueue() = delete;
	explicit IndexMinPriorityQueue(Index maxN);
	IndexMinPriorityQueue(const IndexMinPriorityQueue<Key, Index>& pq);

	~IndexMinPriorityQueue();

	IndexMinPriorityQueue<Key, Index>& operator=(const IndexMinPriorityQueue<Key, Index>& pq);

	bool isEmpty() const;
	bool containsIndex(Index& i) const;
	size_t size() const;
	void insert(Key& k, Index& i);
	const Key& minKey() const;
	const Index& minIndex() const;
	Index& removeMin();
	const Key& keyOf(Index& i) const;
	void changeKey(Key& newPriority, Index& i);
	void deleteIndex(Index& i);

private:
	bool greater(Index i, Index j) const;
	void exchange(Index i, Index j);
	void swim(Index i);
	void sink(Index i);
};




template<class Key, class Index>
inline IndexMinPriorityQueue<Key, Index>::IndexMinPriorityQueue(Index maxN)
	: _maxN{ static_cast<size_t>(maxN) }, _N{ 0 }, 
	_pq{ std::vector<Index>(maxN + 1, 0) },
	_qp{ std::vector<Index>(maxN + 1, DNE) },
	_keys{ std::vector<Key>(maxN + 1, Key{}) }
{
	
}

template<class Key, class Index>
inline IndexMinPriorityQueue<Key, Index>::IndexMinPriorityQueue(const IndexMinPriorityQueue<Key, Index>& impq)
	: _maxN{ pq._maxN }, _N{ pq._N },
	_pq{ impq._pq },
	_qp{ impq._qp },
	_keys{ impq._keys }
{
}

template<class Key, class Index>
inline IndexMinPriorityQueue<Key, Index>::~IndexMinPriorityQueue()
{
}

template<class Key, class Index>
inline IndexMinPriorityQueue<Key, Index>& IndexMinPriorityQueue<Key, Index>::operator=(const IndexMinPriorityQueue<Key, Index>& impq)
{
	if (&pq != this)
	{
		_maxN = impq._maxN;
		_N = impq._N;
		_pq = impq._pq;
		_qp = impq._qp;
		_keys = impq._keys;
	}

	return *this;
}

template<class Key, class Index>
inline bool IndexMinPriorityQueue<Key, Index>::isEmpty() const
{
	return (_N == 0);
}

template<class Key, class Index>
inline bool IndexMinPriorityQueue<Key, Index>::containsIndex(Index& i) const
{
	if (i < 0 || i >= _maxN) throw std::out_of_range{""};

	return (_qp[i] != DNE);
}

template<class Key, class Index>
inline size_t IndexMinPriorityQueue<Key, Index>::size() const
{
	return _N;
}

template<class Key, class Index>
inline void IndexMinPriorityQueue<Key, Index>::insert(Key& k, Index& i)
{
	if (i < 0 || i >= _maxN) throw std::out_of_range{""};
	if (containsIndex(i)) throw std::invalid_argument{ "Index is already in the priority queue." };

	++_N;
	_qp[i] = _N;
	_pq[_N] = i;
	_keys[i] = k;
	swim(_N);
}

template<class Key, class Index>
inline const Key& IndexMinPriorityQueue<Key, Index>::minKey() const
{
	if (_N == 0) throw std::out_of_range{ "No elements in priority queue." };

	return _keys[_pq[1]];
}

template<class Key, class Index>
inline const Index& IndexMinPriorityQueue<Key, Index>::minIndex() const
{
	if (_N == 0) throw std::out_of_range{ "No elements in priority queue." };

	return _pq[1];
}

template<class Key, class Index>
inline typename Index& IndexMinPriorityQueue<Key, Index>::removeMin()
{
	if (_N == 0) throw std::out_of_range{ "No elements in priority queue." };

	Index min = _pq[1];
	exchange(1, _N--);
	sink(1);
	_qp[min] = DNE;

	return min;
}

template<class Key, class Index>
inline const Key& IndexMinPriorityQueue<Key, Index>::keyOf(Index& i) const
{
	if (i < 0 || i >= _maxN) throw std::out_of_range{""};
	if (!containsIndex(i)) throw std::invalid_argument{ "Index is not in the priority queue." };

	return _keys[i];
}

template<class Key, class Index>
inline void IndexMinPriorityQueue<Key, Index>::changeKey(Key& newPriority, Index & i)
{
	if (i < 0 || i >= _maxN) throw std::out_of_range{""};
	if (!containsIndex(i)) throw std::invalid_argument{ "Index is not in the priority queue." };

	_keys[i] = newPriority;
	swim(_qp[i]);
	sink(_qp[i]);
}

template<class Key, class Index>
inline void IndexMinPriorityQueue<Key, Index>::deleteIndex(Index & i)
{
	if (i < 0 || i >= _maxN) throw std::out_of_range{""};
	if (!containsIndex(i)) throw std::invalid_argument{ "Index is not in the priority queue." };

	Index idx = _qp[i];
	exchange(idx, _N--);
	swim(idx);
	sink(idx);
	_qp[i] = DNE;
}

template<class Key, class Index>
inline bool IndexMinPriorityQueue<Key, Index>::greater(Index i, Index j) const
{
	return (_keys[_pq[i]] > _keys[_pq[j]]);
}

template<class Key, class Index>
inline void IndexMinPriorityQueue<Key, Index>::exchange(Index i, Index j)
{
	Index swap = _pq[i];
	_pq[i] = _pq[j];
	_pq[j] = swap;
	_qp[_pq[i]] = i;
	_qp[_pq[j]] = j;
}

template<class Key, class Index>
inline void IndexMinPriorityQueue<Key, Index>::swim(Index i)
{
	while (i > 1 && greater(i / 2, i))
	{
		exchange(i, i / 2);
		i = i / 2;
	}
}

template<class Key, class Index>
inline void IndexMinPriorityQueue<Key, Index>::sink(Index i)
{
	while (2 * i <= size())
	{
		Index j = 2 * i;
		if (j < size() && greater(j, j + 1)) j++;
		if (!greater(i, j)) break;
		exchange(i, j);
		i = j;
	}
}

#endif // !_INDEXMINPRIORITYQUEUE_H