#include "deck.h"
using namespace std;

Deck::Deck()
{
	for(Suit suit=HEARTS; suit!=END_OF_SUITS; suit = next_suit(suit))
	{
		for(Rank rank=ACE; rank!=END_OF_RANKS; rank = next_rank(rank))
		{
			cards.push_back(Card(rank, suit));
		}
	}
	top = cards.size()-1;
}

Card Deck::draw_card()
{
	if(top < 0)
	{
		cerr << "Tried to draw from an empty deck." << endl;
		exit(1);
	}
	return cards[top--];
}

void Deck::shuffle()
{
	int a, b;

	for(int i=0; i<10000; i++)
	{
		a = rand() % cards.size();
		b = rand() % cards.size();
		swap(cards[a], cards[b]);
	}

}

bool Deck::empty()
{
	return top < 0;
}