#ifndef _ITERATORS_CARD_H
#define _ITERATORS_CARD_H

#include "Suit.h"
#include "Pips.h"


class Card
{
private:
	Suit suit;
	Pips pips;

public:
	Card();
	Card(Suit s, Pips v);

	virtual ~Card();

	friend std::ostream& operator<<(std::ostream& out, const Card& c);

	inline Suit getSuit() const { return suit; }
	inline Pips getPips() const { return pips; }
};

#endif