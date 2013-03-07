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
	game.printGame();
	while(true)
	{
		game.determineUserMove();
	}

	return 0;
}

