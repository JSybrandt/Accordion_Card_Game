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
	Accordion(Deck deck);
	void sketch();
	void spread(Deck deck);
	void scrollLeft();
	void scrollRight();
	bool cardCheck(int target);
	void moveOne();
	void moveThree();

private:
	int cursor;
	std::vector<Card> cards;

};

#endif