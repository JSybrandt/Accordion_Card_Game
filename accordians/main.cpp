#include <ctime>
#include "game.h"
using namespace std;

int main()
{

	
	srand(time(0));
	Game game;
	do
	{
		game.printGame();
		while(game.checkActiveGame())
		{
			game.determineUserMove();
		}
	} while(game.askUserContinue());


	return 0;
}

