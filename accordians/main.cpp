#include <iostream>
#include <Windows.h>
#include <vector>
#include <ctime>
#include "card.h"
#include "deck.h"
using namespace std;


int main()
{
	Card c(ACE, HEARTS);
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
	return 0;
}


