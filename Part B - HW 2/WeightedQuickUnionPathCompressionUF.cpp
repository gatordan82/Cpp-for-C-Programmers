// WeightedQuickUnionPathCompressionUF.cpp
//
// C++ for C Programmers, Part B
// Homework 1: Implement Hex Board
// 
// Disjoint set data structure.  Uses weighting to determine
// which branch of two trees in the forest to merge to.  Uses
// path compression to keep each tree flat to within lg*N.
//
// Daniel K. Benjamin
// 2/19/2017

#include "WeightedQuickUnionPathCompressionUF.h"
#include <stdexcept>

using namespace std;

void WeightedQuickUnionPathCompressionUF::validate(size_t p) const
{
	size_t n = _parent.size();
	if (n < 0 || p >= n)
		throw out_of_range("Index is not between 0 and n - 1");
}


WeightedQuickUnionPathCompressionUF::WeightedQuickUnionPathCompressionUF(size_t n)
	: _parent{ vector<size_t>(n, 0) },
	_size{ vector<size_t>(n, 0) },
	_count{ n }
{
	for (size_t i{ 0 }; i < n; i++)
		_parent[i] = _size[i] = i;
}

WeightedQuickUnionPathCompressionUF::WeightedQuickUnionPathCompressionUF(WeightedQuickUnionPathCompressionUF& uf)
	: _parent{ uf._parent },
	_size{ uf._size },
	_count{ uf._count }
{
}


WeightedQuickUnionPathCompressionUF::~WeightedQuickUnionPathCompressionUF()
{
}

WeightedQuickUnionPathCompressionUF& WeightedQuickUnionPathCompressionUF::operator=(WeightedQuickUnionPathCompressionUF& uf)
{
	if (this != &uf)
	{
		_parent = uf._parent;
		_size = uf._size;
		_count = uf._count;
	}

	return *this;
}

size_t WeightedQuickUnionPathCompressionUF::count() const
{
	return _count;
}

size_t WeightedQuickUnionPathCompressionUF::find(size_t p)
{
	validate(p);

	size_t root{ p };
	while (root != _parent[root])
		root = _parent[root];

	while (p != root)
	{
		size_t newp = _parent[p];
		_parent[p] = root;
		p = newp;
	}

	return root;
}

bool WeightedQuickUnionPathCompressionUF::areConnected(size_t p, size_t q)
{
	return (find(p) == find(q));
}

void WeightedQuickUnionPathCompressionUF::join(size_t p, size_t q)
{
	size_t rootP{ find(p) };
	size_t rootQ{ find(q) };

	if (rootP == rootQ) return;

	if (_size[rootP] < _size[rootQ])
	{
		_parent[rootP] = rootQ;
		_size[rootQ] += _size[rootP];
	}
	else
	{
		_parent[rootQ] = rootP;
		_size[rootP] += _size[rootQ];
	}

	_count--;
}
