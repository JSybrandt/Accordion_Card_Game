#include "accordion.h"
using namespace std;

Accordion::Accordion()
{
	scroll = 0;
}

Accordion::Accordion(Deck deck)
{
	scroll = 0;
	spread(deck);
}

void Accordion::sketch()
{
	for(int i=0; i<cards.size(); i++)
	{
		if(i != scroll)
		{
			if((i-scroll)<=4 && (i-scroll)>=-4)
				cards[i].sketch(34+7*(i-scroll),6);
		}
		else
			cards[i].sketch(34, 3);
	}
}

void Accordion::spread(Deck deck)
{
	while(!deck.empty())
	{
		cards.push_back(deck.draw_card());
	}
}

void Accordion::scrollLeft()
{
	scroll--;
	if(scroll < 0)
		scroll = 0;
}

void Accordion::scrollRight()
{
	scroll++;
	if(scroll > cards.size()-1)
		scroll = cards.size()-1;
}





