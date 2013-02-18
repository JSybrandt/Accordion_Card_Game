#include <iostream>
#include <Windows.h>
#include <vector>
#include <ctime>
#include "card.h"
#include "deck.h"
#include "accordion.h"
#include "game.h"
using namespace std;

bool card_check(Card selected, Card one_over, Card three_over);

int main()
{
/*	Card c(ACE, HEARTS);
	while(next_suit(c.get_suit()) != END_OF_SUITS)
	{
		c.set_rank(ACE);
		while(next_rank(c.get_rank()) != END_OF_RANKS)
		{
			int x = rand()%80;
			int y = rand()%5;	
			while(x<80&&y<14)
			{
				c.sketch(x,y,true,false);
				x++;
				y++;
				Sleep(7);
			}
			c.set_rank(next_rank(c.get_rank()));
		}
		c.set_suit(next_suit(c.get_suit()));
	}
*/	
	
	Accordion acc;
	Deck deck;
	Game game;
	acc.spread(deck);
	acc.sketch();

	while(true)
	{
		game.determineUserMove();

	}

	return 0;
}



