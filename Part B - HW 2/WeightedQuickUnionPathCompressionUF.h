// WeightedQuickUnionPathCompressionUF.h
//
// C++ for C Programmers, Part B
// Homework 5: Implement Monte Carlo Hex move evaluation
// 
// Disjoint set data structure.  Uses weighting to determine
// which branch of two trees in the forest to merge to.  Uses
// path compression to keep each tree flat to within lg*N.
//
// Daniel K. Benjamin
// 4/30/2017

#ifndef _WEIGHTED_QUICK_UNION_PATH_COMPRESSION_UF_H
#define _WEIGHTED_QUICK_UNION_PATH_COMPRESSION_UF_H

#include <vector>

class WeightedQuickUnionPathCompressionUF
{
private:
	std::vector<size_t> _parent;	// parent node for connected components
	std::vector<size_t> _size;		// number of elements with a given parent node
	size_t _count;					// number of connected components

	// Check if an index is in the data structure
	void validate(size_t p) const;

public:
	// Constructors
	WeightedQuickUnionPathCompressionUF() = delete;
	WeightedQuickUnionPathCompressionUF(size_t n);
	WeightedQuickUnionPathCompressionUF(WeightedQuickUnionPathCompressionUF& uf);

	// Destructor
	~WeightedQuickUnionPathCompressionUF();

	WeightedQuickUnionPathCompressionUF& operator=(WeightedQuickUnionPathCompressionUF& uf);

	// Number of trees in the forest
	size_t count() const;
	// Return the tree identifier
	size_t find(size_t p);
	// Check if two indices are connected (in the same tree)
	bool areConnected(size_t p, size_t q);
	// Merges the trees containing the two indices
	void join(size_t p, size_t q);

};

#endif // !_WEIGHTED_QUICK_UNION_PATH_COMPRESSION_UF_H