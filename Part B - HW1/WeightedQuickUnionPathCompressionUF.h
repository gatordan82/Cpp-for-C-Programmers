#ifndef _WEIGHTED_QUICK_UNION_PATH_COMPRESSION_UF_H
#define _WEIGHTED_QUICK_UNION_PATH_COMPRESSION_UF_H

#include <vector>

class WeightedQuickUnionPathCompressionUF
{
private:
	std::vector<size_t> _parent;
	std::vector<size_t> _size;
	size_t _count;

	void validate(size_t p) const;

public:
	WeightedQuickUnionPathCompressionUF() = delete;
	WeightedQuickUnionPathCompressionUF(size_t n);

	~WeightedQuickUnionPathCompressionUF();

	size_t count() const;
	size_t find(size_t p);
	bool areConnected(size_t p, size_t q);
	void join(size_t p, size_t q);

};

#endif // !_WEIGHTED_QUICK_UNION_PATH_COMPRESSION_UF_H