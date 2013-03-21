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
	void setSeed(int);
	int getSeed();
	void startScreen();

private:
	void printWinScreen();
	void printLoseScreen();
	void printUI();
	void revertDeck();
	void spreadNewDeck();
	void respreadDeck();
	void pressLeft();
	void pressRight();
	void pressX();
	void pressZ();
	void pressU();
	void pressY();
	void pressN();
	int turnCount;
	bool isPlaying;
	bool keyPressed;
	Accordion board;
	Deck deck;
	int availableUndos;
	void Game::reseedDeck(int n);
	int seed;
};
#endif