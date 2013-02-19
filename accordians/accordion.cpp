#include "accordion.h"
using namespace std;

Accordion::Accordion()
{
	cursor = 0;
}

Accordion::Accordion(Deck deck)
{
	cursor = 0;
	spread(deck);
}

void Accordion::sketch()
{
	for(int i=0; i<cards.size(); i++)
	{
		if(i == cursor)
		{
			cards[i].sketch(34, 3);
		}
		else if((i-cursor)<=4 && (i-cursor)>=-4)
		{
			if(i == cursor-3 && cardCheck(cursor-3))
				cards[i].sketch(34+7*(i-cursor),4);
			else if(i == cursor-1 && cardCheck(cursor-1))
				cards[i].sketch(34+7*(i-cursor),4);
			else
				cards[i].sketch(34+7*(i-cursor),6);
		}
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
	cursor--;
	if(cursor < 0)
		cursor = 0;
}

void Accordion::scrollRight()
{
	cursor++;
	if(cursor > cards.size()-1)
		cursor = cards.size()-1;
}

bool Accordion::cardCheck(int target)
{
	if(cards[cursor].get_rank() == cards[target].get_rank())
	{
		return true;
	}
	else if(cards[cursor].get_suit() == cards[target].get_suit())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Accordion::moveOne()
{
	if(cursor == 0)
	{
		throw "Invalid move.";
	}
	else if(cardCheck(cursor-1))
	{
		cards.erase(cards.begin()+(cursor-1));
		cursor -= 1;
	}
	else
	{
		throw "Invalid move.";
	}
}

void Accordion::moveThree()
{
	if(cursor < 3)
	{
		throw "Invalid move.";
	}
	else if(cardCheck(cursor-3))
	{
		cards.erase(cards.begin()+(cursor-3), cards.begin()+cursor);
		cursor -= 3;
	}
	else
	{
		throw "Invalid move.";
	}
}

