#ifndef _WEIGHTED_QUICK_UNION_PATH_COMPRESSION_H
#define _WEIGHTED_QUICK_UNION_PATH_COMPRESSION_H

#include <vector>
#include <exception>

class WeightedQuickUnionPathCompressionUF
{
private:
	std::vector<size_t> _parent;  // the parent of i
	std::vector<size_t> _size;    // number of sites in tree rooted at i
	size_t _count;                // number of components

public:
	// Constructors
	WeightedQuickUnionPathCompressionUF() = delete;
	WeightedQuickUnionPathCompressionUF(size_t n);

	~WeightedQuickUnionPathCompressionUF();

	// Union Find API
	size_t count() const;
	size_t find(size_t p);
	bool connected(size_t p, size_t q);
	void unionMerge(size_t p, size_t q);

private:
	// Helper functions
	void validate(size_t p) const;

};

#endif
