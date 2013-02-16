#ifndef GAME_H
#define GAME_H
#include"accordion.h"

class Game
{
public:
	Game(){keyPressed = false; board.spread(deck);};
	 void determineUserMove();
	 void printGame();
private:
	bool keyPressed;
	Accordion board;
	Deck deck;
};
#endif