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
	void printWinScreen();
	void printLoseScreen();
	int turnCount;
	bool isPlaying;
	void printUI();
	void revertDeck();
	void spreadNewDeck();
	void respreadDeck();



	bool keyPressed;
	Accordion board;
	Deck deck;
};
#endif