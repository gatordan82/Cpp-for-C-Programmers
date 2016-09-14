#ifndef _ITERATORS_SUIT_H
#define _ITERATORS_SUIT_H

#include <ostream>

enum class Suit : short {SPADE, HEART, DIAMOND, CLUB};

inline std::ostream& operator<<(std::ostream& out, Suit s)
{
	switch (s)
	{
	case Suit::SPADE:
		out << "S";
		break;
	case Suit::HEART:
		out << "H";
		break;
	case Suit::DIAMOND:
		out << "D";
		break;
	case Suit::CLUB:
		out << "C";
		break;
	}

	return out;
}

#endif // !_ITERATORS_SUIT_H