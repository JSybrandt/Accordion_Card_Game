#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include "card.h"

class Deck
{
public:
	Deck();
	Card draw_card();
	void shuffle();
	bool empty();

private:
	std::vector<Card> cards;
	int top; //index of the top card

};

#endif