#ifndef GAME_H
#define GAME_H
#include"accordion.h"

class Game
{
public:
	Game(){keyPressed = false;};
	 void determineUserMove();
	 void printGame();
private:
	bool keyPressed;
	Accordion board;
};
#endif