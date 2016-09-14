#pragma once
#ifndef _ITERATORS_PIPS_H
#define _ITERATORS_PIPS_H

#include <ostream>

class Pips
{
private:
	int v;

public:
	Pips(int val);
	friend std::ostream& operator<<(std::ostream& out, const Pips& p);
	
	virtual ~Pips();

	inline int getPips() const
	{
		return v;
	}
};

#endif
