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
	bool cardCheck(int start, int target);
	void moveOne();
	void moveThree();
	int numCardsLeft();
	bool validMovesLeft();
	//Justin Sybrandt
	//Added to print on lower UI
	const Card* checkOne();
	const Card* checkThree();
	int getCardsRemaining();
	void clear() {cards.clear();}

private:
	int cursor;
	std::vector<Card> cards;

};

#endif