#ifndef GAME_H
#define GAME_H
#include"accordion.h"

class Game
{
public:
	Game();
	void determineUserMove();
	void printGame();
	void incrementTurnCount();
	void resetTurnCount();
	void checkGameOver();
private:
	int turnCount;
	bool isPlaying;
	void printUI();
	void printWinScreen();
	void printLoseScreen();

	bool keyPressed;
	Accordion board;
};
#endif