#include <iostream>
#include "Card.h"
#include <vector>

const int MAX_PIP = 14;

void initDeck(std::vector<Card>& d)
{
	for (int i = 1; i < MAX_PIP; ++i)
	{
		Card c(Suit::SPADE, Pips(i));
		d.push_back(c);
	}
	for (int i = 1; i < MAX_PIP; ++i)
	{
		Card c(Suit::HEART, Pips(i));
		d.push_back(c);
	}
	for (int i = 1; i < MAX_PIP; ++i)
	{
		Card c(Suit::DIAMOND, Pips(i));
		d.push_back(c);
	}
	for (int i = 1; i < MAX_PIP; ++i)
	{
		Card c(Suit::CLUB, Pips(i));
		d.push_back(c);
	}
}

bool isFlush(std::vector<Card>& hand)
{
	Suit s = hand[0].getSuit();
	for (const auto& card : hand)
	{
		if (card.getSuit() != s)
			return false;
	}

	return true;
}

int main()
{
	using namespace std;

	//Pips pip(13);

	//cout << "Pip has value: " << pip.getPips() << endl;

	//cout << pip << endl;

	std::vector<Card> deck;

	initDeck(deck);

	for (const auto& card : deck)
		cout << card << endl;

	std::vector<Card> hand;

	for (int i = 1; i < 6; ++i)
		hand.push_back(Card(Suit::CLUB, Pips(i)));

	//hand.push_back(Card(Suit::DIAMOND, Pips(1)));

	cout << "Is this hand a flush? " << isFlush(hand) << endl;


	cin.get();
	return 0;

}