#include "game.h"
#include <ctime>
using namespace std;

int main()
{
	//Pre-condition: Setting up random seed for game for start of the game
	//Postcondition: Asks if seed is to be selected and allows player to enter one

	//Postcondition: Initalizes game 
	srand(time(0));
	int data_key = 0;
	char answer;
	cout << "Would you like to select a specific seed (Y/N) :";
	cin >> answer;
	if(answer =='y')
	{
		system("CLS");
		cout << "ENTER SEED NUMBER: ";
		cin >> data_key;
	}
	else
	{
		system("CLS");
		data_key = rand() % 1000;
	}
	//setSeed(data_key);
		
	cout << endl;
	
	
	cout << "This Games data key is: "<<data_key<< endl;
	system("PAUSE");
	srand(data_key);

	Game game;
	game.setSeed(data_key);
	//game.startScreen();
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

