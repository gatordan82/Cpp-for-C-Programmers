#include "Pips.h"
#include <assert.h>

Pips::Pips(int val) : v{ val }
{
	assert(v > 0 && v < 14);
}

Pips::~Pips()
{
}

std::ostream& operator<<(std::ostream& out, const Pips& p)
{
	out << p.v;

	return out;
}
