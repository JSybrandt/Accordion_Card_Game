#include<windows.h>
#include"game.h"
#include <ctime>
#include <sstream>

using namespace std;
//Pre-condition:
//Postcondition:
Game::Game()
{
	keyPressed = false;
	deck.shuffle();
	board.spread(deck);
	turnCount = 0;
	seed = 0;
	availableUndos = 3;
	isPlaying = true;
}
//Pre-condition:
//Postcondition:
void Game::setSeed(int seed2)
{
	seed = seed2;
}

int Game::getSeed()
{
	return seed;
}

void Game::incrementTurnCount()
{
	turnCount++;
}
//Pre-condition:
//Postcondition:
void Game::resetTurnCount()
{
	turnCount = 0;
}
//Pre-condition:
//Postcondition:
void Game::revertDeck()
{
	deck.top = deck.cards.size()-1;
}
//Pre-condition:
//Postcondition:
void Game::spreadNewDeck()
{
	board.clear();
	revertDeck();
	deck.shuffle();
	board.spread(deck);
	turnCount = 0;
	availableUndos = 3;
	isPlaying = true;
}
//Pre-condition:
//Postcondition:
void Game::respreadDeck()
{
	board.clear();
	revertDeck();
	board.spread(deck);
	turnCount = 0;
	availableUndos = 3;
	isPlaying = true;
}
void Game::reseedDeck(int n)
{	
	srand(n);
	board.clear();
	revertDeck();
	board.spread(deck);
	turnCount = 0;
	availableUndos = 3;
	isPlaying = true;
}
//Pre-condition:
//Postcondition:
void Game::determineUserMove()
{
	if(isPlaying)
	{
		 if(GetAsyncKeyState(VK_LEFT))
			 pressLeft();
		 else if(GetAsyncKeyState(VK_RIGHT))
			 pressRight();
		 else if(GetAsyncKeyState('X'))
			pressX();
		 else if(GetAsyncKeyState('Z'))
			pressZ();
		 else if(GetAsyncKeyState('U'))
			pressU();
		 else keyPressed = false;
	}
}
//Pre-condition:
//Postcondition:
void Game::pressLeft()
{
	if(!keyPressed)
	{
		board.scrollLeft();
		printGame();
	}
	keyPressed = true;
}
//Pre-condition:
//Postcondition:
void Game::pressRight()
{
	if(!keyPressed)
	{
		 board.scrollRight();
		 printGame();
	}
	keyPressed = true;
}
//Pre-condition:
//Postcondition:
void Game::pressX()
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
	}
	keyPressed = true;
}
//Pre-condition:
//Postcondition:
void Game::pressZ()
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
	}
	keyPressed = true;
}
//Pre-condition:
//Postcondition:
void Game::pressU()
{
	if(!keyPressed)
	{
		if(board.canUndo() && availableUndos>0)
			{
				board.undo();
				availableUndos--;
				printGame();
			}
	}
	keyPressed = true;
}

void Game:: printUI()
{
	stringstream status;
	status<<"Cards Remaining: "<<	board.getCardsRemaining()<<"|";
	status<<"Turn Count: "<<turnCount<<"|";
	if(availableUndos>0)
		status<<"Press U to undo ("<<availableUndos<<" left)|";

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
//Pre-condition:
//Postcondition:
void Game::startScreen()
{
	srand(time(0));
	int data_key = 0;
	char answer;
	cout << "Would you like to select a specific seed (Y/N) :";
	cin >> answer;
	if(answer =='y')
	{
		cout << "ENTER SEED NUMBER: ";
		cin >> data_key;
	}
	else
	{
		data_key = rand() % 1000;
	}
	setSeed(data_key);
		
	cout << endl;
	
	srand(data_key);
	cout << "This Games data key is: "<<data_key<< endl;
	system("PAUSE");
	
}
//Pre-condition:
//Postcondition:
void Game::printGame()
{
	system("cls");
	board.sketch();
	printUI();
;
}
//Pre-condition:
//Postcondition:
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
//Pre-condition:
//Postcondition:
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
//Pre-condition:
//Postcondition:
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
//Pre-condition:
//Postcondition:
bool Game::askUserContinue()
{
	int data_key = 0;
	data_key = getSeed();
	system("CLS");
	cout<<endl<<endl<<"THE GAME KEY IS "<< data_key
		<<endl<<"PRESS R TO TRY AGAIN WITH THE SAME DECK"
		<<endl<<"PRESS S TO PLAY AGAIN WITH A SHUFFELED DECK"
		<<endl<<"PRESS A TO PLAY AGAIN WITH A NEW SEED"
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
		if(GetAsyncKeyState('A'))
		{
			system("CLS");
			int n=0;
			cout<<endl<<endl<<"THE GAME KEY IS "<< data_key
			<<endl<< "ENTER SEED NUMBER: ";
			cin >> n;
			reseedDeck(n);
			return true;
		}
		if(GetAsyncKeyState('Q'))
			return false;
	}
}
