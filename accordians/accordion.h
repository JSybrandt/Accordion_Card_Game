#ifndef ACCORD_H
#define ACCORD_H

#include <iostream>
#include <vector>
#include "card.h"
#include "deck.h"

class Accordion
{
public:
	Accordion();
	void sketch();
	void spread(Deck deck);

private:
	int scroll;
	std::vector<Card> cards;

};

#endif