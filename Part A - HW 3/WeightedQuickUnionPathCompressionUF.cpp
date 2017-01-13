#include "WeightedQuickUnionPathCompressionUF.h"
#include <string>

using namespace std;

WeightedQuickUnionPathCompressionUF::WeightedQuickUnionPathCompressionUF(size_t n)
	: _parent{ std::vector<size_t>{n, 0} },
	_size{ std::vector<size_t>{n, 0} },
	_count{ n }
{
	for (size_t i{ 0 }; i < n; ++i)
	{
		_parent[i] = i;
		_size[i] = i;
	}
}


WeightedQuickUnionPathCompressionUF::~WeightedQuickUnionPathCompressionUF()
{
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
		size_t newp{ _parent[p] };
		_parent[p] = root;
		p = newp;
	}

	return root;
}

bool WeightedQuickUnionPathCompressionUF::connected(size_t p, size_t q)
{
	return (find(p) == find(q));
}

void WeightedQuickUnionPathCompressionUF::unionMerge(size_t p, size_t q)
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

void WeightedQuickUnionPathCompressionUF::validate(size_t p) const
{
	size_t n{ _parent.size() };
	if (p < 0 || p >= n)
		throw out_of_range{ "Index " 
							+ to_string(p) 
							+ " is not between 0 and " 
							+ to_string(n - 1)};

}
