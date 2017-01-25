#include <iostream>
#include "Card.h"
#include <vector>
#include <algorithm>
#include <ctime>

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
	Suit s{ hand[0].getSuit() };
	for (const auto& card : hand)
	{
		if (card.getSuit() != s)
			return false;
	}

	return true;
}

bool isStraight(std::vector<Card>& hand)
{
	int pips_v[5]{ 0, 0, 0, 0, 0 };
	int i{ 0 };

	for (const auto& card : hand)
		pips_v[i++] = card.getPips().getPips();

	std::sort(pips_v, pips_v + 5);

	if (pips_v[0] != 1)
		return (pips_v[0] == pips_v[1] - 1
			&& pips_v[1] == pips_v[2] - 1
			&& pips_v[2] == pips_v[3] - 1
			&& pips_v[3] == pips_v[4] - 1);
	else
		return (pips_v[0] == pips_v[1] - 1
			&& pips_v[1] == pips_v[2] - 1
			&& pips_v[2] == pips_v[3] - 1
			&& pips_v[3] == pips_v[4] - 1)
		|| (pips_v[1] == 10
			&& pips_v[2] == 11
			&& pips_v[3] == 12
			&& pips_v[4] == 13);
}

bool isStraightFlush(std::vector<Card>& hand)
{
	return isFlush(hand) && isStraight(hand);
}

//int main()
//{
//	using namespace std;
//
//	//Pips pip(13);
//
//	//cout << "Pip has value: " << pip.getPips() << endl;
//
//	//cout << pip << endl;
//
//	std::vector<Card> deck{};
//
//	initDeck(deck);
//
//	for (const auto& card : deck)
//		cout << card << endl;
//
//	std::vector<Card> hand;
//
//	for (int i = 1; i < 6; ++i)
//		hand.push_back(Card(Suit::CLUB, Pips(i)));
//
//	//hand.push_back(Card(Suit::DIAMOND, Pips(1)));
//
//	cout << "\n\n";
//	for (const auto& card : hand)
//	{
//		cout << card << endl;
//	}
//
//	cout << "Is this hand a flush? " 
//		 << boolalpha << isFlush(hand) << endl;
//	cout << "Is this hand a straight?"
//		<< boolalpha << isStraight(hand) << endl;
//
//	cout << "\n\n";
//
//	srand(time(0));
//
//	size_t flushCount{ 0 };
//	size_t straightCount{ 0 };
//	size_t straightFlushCount{ 0 };
//
//	size_t howMany{};
//	cout << "How many shuffles?";
//	cin >> howMany;
//
//	for (size_t loop{ 0 }; loop < howMany; ++loop)
//	{
//		std::random_shuffle(deck.begin(), deck.end());
//		vector<Card> hand(5, Card{});
//		size_t i{ 0 };
//		for (auto& p{ deck.begin() }; i < 5; ++p)
//			hand[i++] = *p;
//
//		if (isFlush(hand))
//			flushCount++;
//		if (isStraight(hand))
//			straightCount++;
//		if (isStraightFlush(hand))
//			straightFlushCount++;
//	}
//
//	cout << "Flushes: " << flushCount
//		<< " out of " << howMany 
//		<< " -> p = " 
//		<< static_cast<double>(flushCount) / howMany
//		<< endl;
//	cout << "Straights: " << straightCount
//		<< " out of " << howMany 
//		<< " -> p = "
//		<< static_cast<double>(straightCount) / howMany
//		<< endl;
//	cout << "Straight Flushes: " << straightFlushCount
//		<< " out of " << howMany
//		<< " -> p = "
//		<< static_cast<double>(straightFlushCount) / howMany
//		<< endl;
//
//	cin.get();
//	cin.get();
//	return 0;
//
//}