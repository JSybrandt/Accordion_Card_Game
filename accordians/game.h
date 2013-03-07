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
	bool checkActiveGame() {return isPlaying;}
	bool askUserContinue();

private:
	void printWinScreen();
	void printLoseScreen();
	void printUI();
	
	
	int turnCount;
	bool isPlaying;
	bool keyPressed;
	Accordion board;
	Deck deck;
};
#endif