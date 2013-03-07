#include <iostream>
#include <Windows.h>
#include <vector>
#include <ctime>
#include "card.h"
#include "deck.h"
#include "accordion.h"
#include "game.h"
using namespace std;

int main()
{

	
	srand(time(0));
	Game game;
	
	while(game.askUserContinue())
	{
		game.printGame();
		while(game.checkActiveGame())
		{
			game.determineUserMove();
		}
	}

	return 0;
}

