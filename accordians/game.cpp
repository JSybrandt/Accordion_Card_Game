#include<windows.h>
#include"game.h"
#include <sstream>

using namespace std;

Game::Game()
{
	keyPressed = false;
	Deck deck;
	deck.shuffle();
	board.spread(deck);
	turnCount = 0;
	isPlaying = true;
}
void Game::incrementTurnCount()
{
	turnCount++;
}
void Game::resetTurnCount()
{
	turnCount = 0;
}

void Game::determineUserMove()
{
	if(isPlaying)
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
		 else if(GetAsyncKeyState('X'))
		 {
			 if(!keyPressed)
			 {
				 if(board.checkOne() != NULL)
				 {
					board.moveOne();
					turnCount++;
					printGame();
					checkGameOver();
				 }
			 keyPressed = true;
			 }
		 }
		 else if(GetAsyncKeyState('Z'))
		 {
			 if(!keyPressed)
			 {
				if(board.checkThree() != NULL)
					 {
						board.moveThree();
						turnCount++;
						printGame();
						checkGameOver();
					 }
			 keyPressed = true;
			 }
		 }
		 else keyPressed = false;
	}
}
void Game:: printUI()
{
	stringstream status;
	status<<"Cards Remaining: "<<	board.getCardsRemaining()<<"|";
	if(board.checkOne() != NULL)
		status<<"X will merge to "<<*board.checkOne()<<"|";
	if(board.checkThree() != NULL)
		status<<"Z will merge to "<<*board.checkThree()<<"|";
	status<<"Turn Count: "<<turnCount<<"|";


	//printing
	cout<<endl<<"-";
	string toPrint = status.str();
	toPrint = toPrint.substr(0,toPrint.size()-1);
	for(int i = 0 ; i < toPrint.size();i++)
	{
		cout<<"-";
	}
	cout<<"-"<<endl;
	cout<<"|"<<toPrint<<"|"<<endl;
	for(int i = 0 ; i < toPrint.size();i++)
	{
		cout<<"-";
	}
	cout<<"--"<<endl;

}
void Game::printGame()
{
	system("cls");
	board.sketch();
	printUI();
;
}

void Game::checkGameOver()
{
	if(board.getCardsRemaining() == 1)
	{
		void printWinScreen();
		isPlaying = false;
	
	}
	else if(!board.validMovesLeft())
	{
		void printLoseScreen();
		isPlaying = false;
	}
}
void Game::printWinScreen()
{
	system("cls");
	gotoxy(0,0);
	cout<<"You Win"<<endl;
	system("pause");
}
void Game::printLoseScreen()
{
	system("cls");
	gotoxy(0,0);
	cout<<"YOU LOSE"<<endl;
	system("pause");
}