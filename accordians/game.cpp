#include<windows.h>
#include"game.h"
#include <sstream>

using namespace std;

Game::Game()
{
	keyPressed = false;
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
void Game::revertDeck()
{
	deck.top = deck.cards.size()-1;
}
void Game::spreadNewDeck()
{
	board.clear();
	revertDeck();
	deck.shuffle();
	board.spread(deck);
	turnCount = 0;
	isPlaying = true;
}
void Game::respreadDeck()
{
	board.clear();
	revertDeck();
	board.spread(deck);
	turnCount = 0;
	isPlaying = true;
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
		printWinScreen();
		isPlaying = false;
	
	}
	else if(!board.validMovesLeft())
	{
		printLoseScreen();
		isPlaying = false;
	}
}
void Game::printWinScreen()
{
	system("cls");
	Card c(ACE, HEARTS);
	int delx = -3;
	int sign = 1;
	for(int i = 0 ; i < 8; i++)
	{
		c.set_rank(ACE);
		int x = 34;
		int y = 3;
		for (int j = 0 ; j < 13 ; j++)
		{
			c.sketch(x,y,true,false);

			x += delx*2;
			y+=2;

			if(y>13|| x>70 || x<0)
			{
				delx += sign;
				if(abs(delx) >= 3)
				(( sign==1)? sign = -1: sign = 1);

					y=3;
					x = 34;
			}
				Sleep(20);
			if(next_rank(c.get_rank()) == END_OF_RANKS) c.set_rank(ACE);
			else
			c.set_rank(next_rank(c.get_rank()));

			
		}
		if(next_suit(c.get_suit()) == END_OF_SUITS) c.set_suit(SPADES);
		else
		c.set_suit(next_suit(c.get_suit()));
	}
	c.set_suit(SPADES);
	c.set_rank(ACE);
	c.sketch(34,5,true,true);
	cout<<endl<<endl<<endl<<endl<<endl;
	cout<<endl<<endl<<endl<<endl<<"                    !!!YOU WIN!!!"<<endl;
	system("pause");
}
void Game::printLoseScreen()
{
	system("cls");
	gotoxy(0,0);
	cout<<"                                                                             "<<endl
		<<"              ===========       _-_     ==========        |                  "<<endl
		<<"              |                /   \\         |            |                  "<<endl
		<<"              |               |     |        |            |                  "<<endl
		<<"              |======         |=====|        |            |                  "<<endl
		<<"              |               |     |        |            |                  "<<endl
		<<"              |               |     |        |            |                  "<<endl
		<<"              |               |     |   ==========        =========          "<<endl
		<<"                                                                             "<<endl
		<<"                        GAME                     OVER                        "<<endl<<endl;
	system("pause");
}

bool Game::askUserContinue()
{
	system("CLS");
	cout<<endl<<endl<<"PRESS R TO TRY AGAIN WITH THE SAME DECK"
		<<endl<<"PRESS S TO PLAY AGAIN WITH A SHUFFELED DECK"
		<<endl<<"PRESS Q TO QUIT"<<endl;
	while(true)
	{
		if(GetAsyncKeyState('R'))
		{
			respreadDeck();
			return true;
		}
		if(GetAsyncKeyState('S'))
		{
			spreadNewDeck();
			return true;
		}
		if(GetAsyncKeyState('Q'))
			return false;
	}



}