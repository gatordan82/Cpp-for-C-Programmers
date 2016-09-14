#include "Card.h"


Card::Card() : suit{ Suit::SPADE }, pips{ Pips(1) }
{
}

Card::Card(Suit s, Pips v) : suit{ s }, pips{ v }
{
}


Card::~Card()
{
}

std::ostream& operator<<(std::ostream& out, const Card& c)
{
	out << c.pips << c.suit;
	return out;
}
