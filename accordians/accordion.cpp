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
			{
				gotoxy(33+7*(i-cursor),3);
				cout<<"Press Z";
				cards[i].sketch(34+7*(i-cursor),4);
				
			}
			else if(i == cursor-1 && cardCheck(cursor-1))
			{
				gotoxy(33+7*(i-cursor),3);
				cout<<"Press X";
				cards[i].sketch(34+7*(i-cursor),4);
			}
			else
				cards[i].sketch(34+7*(i-cursor),6);
		}
	}
	if(cursor == cards.size()-1)
		cout<<endl<<endl<<endl;//the cursor is raised to high if we are at the end
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
	if(target < 0 || target >= cards.size())
	{
		return false;
	}
	else if(cards[cursor].get_rank() == cards[target].get_rank())
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
bool Accordion::cardCheck(int start, int target)
{
	if(target < 0 || target >= cards.size())
	{
		return false;
	}
	else if(cards[start].get_rank() == cards[target].get_rank())
	{
		return true;
	}
	else if(cards[start].get_suit() == cards[target].get_suit())
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
	if(cardCheck(cursor-1))
	{
		trashIndex = cursor-1;
		trash.clear();
		trash.push_back(cards[cursor-1]);
		cards.erase(cards.begin()+(cursor-1));
		cursor -= 1;
	}
}

void Accordion::moveThree()
{
	if(cardCheck(cursor-3))
	{
		trashIndex = cursor-3;
		trash.clear();
		for(int i=0;i<3;i++)
		{
			trash.push_back(cards[cursor-1]);
			cards.erase(cards.begin()+(cursor-1));
			cursor -= 1;
		}
		//cards.erase(cards.begin()+(cursor-3), cards.begin()+cursor);
		//cursor -= 3;
	}
}
int Accordion::getCardsRemaining()
{
	return cards.size();
}
const Card* Accordion:: checkOne()
{
   if(cursor >= 1 && cardCheck(cursor-1))
		return &(cards.at(cursor-1));
	else return NULL;
}
const Card* Accordion::checkThree()
{
	if(cursor >= 3 && cardCheck(cursor-3))
		return &(cards.at(cursor-3));
	else return NULL;
}

bool Accordion::validMovesLeft()
{
	for(int i = 1 ; i < cards.size();i++)
	{
		if(i>=3 && cardCheck(i,i-3))
			return true;
		if(cardCheck(i,i-1))
			return true;
	}
	return false;
}

void Accordion::undo()
{
	vector<Card>::iterator iter = cards.begin() + trashIndex;
	for(int i=0; canUndo(); i++)
	{
		cards.insert(iter, trash.at(i));
		trash.pop_back();
	}
}
