#include "accordion.h"
using namespace std;
//Pre-condition: 
//Postcondition:
Accordion::Accordion()
{
	cursor = 0;
}
//Pre-condition: 
//Postcondition:
Accordion::Accordion(Deck deck)
{
	cursor = 0;
	spread(deck);
}
//Pre-condition: Game is sketching the accordian game into the screen
//Postcondition: First card is placed in the center and desk is spread out to the right.
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
//Pre-condition: Cards are contained in deck object
//Postcondition: Places the cards onto the spread object
void Accordion::spread(Deck deck)
{
	while(!deck.empty())
	{
		cards.push_back(deck.draw_card());
	}
}
//Pre-condition: Async Key State setup for left scroll
//Postcondition: Allows curser to scroll left for the number of remaining cards
void Accordion::scrollLeft()
{
	cursor--;
	if(cursor < 0)
		cursor = 0;
}
//Pre-condition: Async Key State setup for right scroll
//Postcondition: Allows curser to scroll right for the number of remaining cards
void Accordion::scrollRight()
{
	cursor++;
	if(cursor > cards.size()-1)
		cursor = cards.size()-1;
}
//Pre-condition: Player is checking if target card has same suit or number as cursor card (1 cards away)
//Postcondition: Returns true if same suit or rank, false otherwise
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
//Pre-condition: Player is checking if target card has same suit or number as start card (3 cards away)
//Postcondition: Returns true if same suit or rank, false otherwise
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
//Pre-condition: Player is moving the stack 1 cards to the left
//Postcondition: Inbetween cards are placed in the trashIndex, move is completed
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
//Pre-condition: Player is moving the stack 3 cards to the left
//Postcondition: Inbetween cards are placed in the trashIndex, move is completed
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
//Postcondition: returns the number of remaining cards
int Accordion::getCardsRemaining()
{
	return cards.size();
}
//Pre-condition: Player is check to see if the card 1 to the left is a valid move
//Postcondition: Returns card if valid, else null
const Card* Accordion:: checkOne()
{
   if(cursor >= 1 && cardCheck(cursor-1))
		return &(cards.at(cursor-1));
	else return NULL;
}
//Pre-condition: Player is check to see if the card 3 to the left is a valid move
//Postcondition: Returns card if valid, else null
const Card* Accordion::checkThree()
{
	if(cursor >= 3 && cardCheck(cursor-3))
		return &(cards.at(cursor-3));
	else return NULL;
} 
//Pre-condition: Checks through all the cards in play for valid moves
//Postcondition: Returns false if there are no playable moves, true if there are
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
//Pre-condition: The player has just made a move and a cards have been placed in trashIndex
//Postcondition: The players move has been undone
void Accordion::undo()
{
	vector<Card>::iterator iter = cards.begin() + trashIndex;
	for(int i=0; i<trash.size(); i++)
	{
		iter = cards.begin() + trashIndex; //keeps iterator valid
		cards.insert(iter, trash[i]);
		if(cursor >= trashIndex)
			cursor++;
	}
	trash.clear();
}

