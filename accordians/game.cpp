#include<windows.h>
#include"game.h"

using namespace std;

Game::Game()
{
	keyPressed = false;
	Deck deck;
	deck.shuffle();
	accordion.spread(deck);
}

void Game::determineUserMove()
{
	 if(GetAsyncKeyState(VK_LEFT))
	 {
		 if(!keyPressed)
		 {
		 board.scrollLeft();
		 printGame();
		 keyPressed = true;
		 }
	 }
	 else if(GetAsyncKeyState(VK_RIGHT))
	 {
		 if(!keyPressed)
		 {
		 board.scrollRight();
		 printGame();
		 keyPressed = true;
		 }
	 }
	 else keyPressed = false;
}
void Game::printGame()
{
	system("cls");
	board.sketch();
}