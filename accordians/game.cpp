#include<windows.h>
#include"game.h"

using namespace std;
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