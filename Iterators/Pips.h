#ifndef _ITERATORS_PIPS_H
#define _ITERATORS_PIPS_H

#include <ostream>

class Pips
{
private:
	int v;

public:
	Pips(int val);
	
	virtual ~Pips();

	int getPips() const;
	friend std::ostream& operator<<(std::ostream& out, const Pips& p);
};

#endif
