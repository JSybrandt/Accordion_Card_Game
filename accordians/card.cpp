#include "card.h"
using namespace std;

Suit next_suit(Suit s)
{
	switch(s)
	{
	case HEARTS:
		return DIAMONDS; break;
	case DIAMONDS:
		return CLUBS; break;
	case CLUBS:
		return SPADES; break;
	default:
		return END_OF_SUITS;
	}
}

Rank next_rank(Rank r)
{
	if(r!= END_OF_RANKS)
	{
		return static_cast<Rank>(static_cast<int>(r)+1);
	}
	return END_OF_RANKS;
}

void Card::set_rank(Rank r)
{
	if(r >= ACE && r <= KING)
	{
		rank = r;
	}
	else
	{
		cerr << "Called set_rank with invalid rank: " << r << endl;
		exit(1);
	}
}

void Card::set_suit(Suit s)
{
	if(s >= HEARTS && s <= SPADES)
	{
		suit = s;
	}
	else
	{
		cerr << "Called set_suit with invalid suit: " << s << endl;
		exit(1);
	}
}

Card::Card(Rank r, Suit s)
{
	set_rank(r);		
	set_suit(s);
}



void gotoxy(int x, int y) 
{ 
    COORD coord; 
    coord.X = x; coord.Y = y; 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); 
}

ostream& operator<<(ostream& out, Card x)
{
	x.display_rank(out);
	x.display_suit(out);
	return out;
}

void Card::sketch(int x, int y,  bool face_up, bool stack)
{
	int line = 0;
	
	const char TOP_LEFT = 218;
	const char STACK_TOP_LEFT = 195;
	const char BOTTOM_LEFT = 192;
	const char HORIZONTAL = 196;
	const char TOP_RIGHT = 191;
	const char STACK_TOP_RIGHT = 180;
	const char BOTTOM_RIGHT = 217;
	const char VERTICAL = 179;

	gotoxy(x, y);
	if(stack)
	{
		cout << STACK_TOP_LEFT;
	}
	else
	{
		cout << TOP_LEFT;
	}
	for(int i=0; i<CARD_WIDTH; i++)
	{
		cout << HORIZONTAL;
	}
	if(stack)
	{
		cout << STACK_TOP_RIGHT;
	}
	else
	{
		cout << TOP_RIGHT;
	}
	while(line < CARD_HEIGHT)
	{		
		line++;
		gotoxy(x, y+line);
		cout << VERTICAL;
		if(face_up)
		{
			if(suit == HEARTS || suit == DIAMONDS)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
					FOREGROUND_INTENSITY | FOREGROUND_RED |
					BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 
					BACKGROUND_INTENSITY);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
					BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 
					BACKGROUND_INTENSITY);
			}
			
			if(line == 1)
			{		
				cout << *this;
				for(int i=0; i<CARD_WIDTH-2; i++)
				{
					cout << " ";
				}
				
			}
			else if(line == CARD_HEIGHT )
			{						
				for(int i=0; i<CARD_WIDTH-2; i++)
				{
					cout << " ";
				}
				cout << *this;

			}
			else
			{
				for(int i=0; i<CARD_WIDTH; i++)
				{
					cout << " ";
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);			
		}
		else
		{
			for(int i=0; i<CARD_WIDTH; i++)
			{
				cout << "*";
			}

		}
		cout << VERTICAL;		
	}
	line++;
	gotoxy(x, y+line);
	cout << BOTTOM_LEFT;
	for(int i=0; i<CARD_WIDTH; i++)
	{
		cout << HORIZONTAL;
	}
	cout << BOTTOM_RIGHT;
	stamp(x,y);

}

void Card::display_suit(ostream& out)
{	
	out << static_cast<char>(suit);
}

void Card::display_rank(ostream& out)
{
	char displayed_rank = '*';
	switch(rank)
	{
	case ACE:
		displayed_rank = 'A';
		break;
	case KING:
		displayed_rank = 'K';
		break;
	case QUEEN:
		displayed_rank = 'Q';
		break;
	case JACK:
		displayed_rank = 'J';
		break;
	case TEN: 
		displayed_rank = 'T';
		break;
	default:
		displayed_rank = static_cast<int>('0') 
			+ static_cast<int>(rank);
	}
	
	out << displayed_rank;
}

void Card::stamp(int x, int y)
{
	if(suit == HEARTS || suit == DIAMONDS)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
			FOREGROUND_INTENSITY | FOREGROUND_RED |
			BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 
			BACKGROUND_INTENSITY);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
			BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 
			BACKGROUND_INTENSITY);
	}
	switch(rank)
	{
	case ACE:
		stamp_mid_single(x,y);
		break;
	case TWO:
		stamp_top_single(x,y);
		stamp_bottom_single(x,y);
		break;
	case THREE:
		stamp_top_single(x,y);
		stamp_mid_single(x,y);
		stamp_bottom_single(x,y);
		break;
	case FOUR:
		stamp_top_double(x,y);
		stamp_bottom_double(x,y);
		break;
	case FIVE:
		stamp_top_double(x,y);
		stamp_mid_single(x,y);
		stamp_bottom_double(x,y);
		break;
	case SIX:
		stamp_top_double(x,y);
		stamp_mid_double(x,y);
		stamp_bottom_double(x,y);
		break;
	case SEVEN:
		stamp_mid_top(x,y);
		stamp_top_double(x,y);
		stamp_mid_double(x,y);
		stamp_bottom_double(x,y);
		break;
	case EIGHT:
		stamp_mid_top(x,y);
		stamp_top_double(x,y);
		stamp_mid_double(x,y);
		stamp_bottom_double(x,y);
		stamp_mid_bottom(x,y);
		break;
	case NINE:
		stamp_top_double(x,y);
		gotoxy(x+CARD_WIDTH/2-2, y + CARD_HEIGHT/2-1);
		display_suit();
		gotoxy(x+CARD_WIDTH/2+2, y + CARD_HEIGHT/2-1);
		display_suit();
		stamp_mid_single(x,y);
		gotoxy(x+CARD_WIDTH/2-2, y + CARD_HEIGHT/2+1);
		display_suit();
		gotoxy(x+CARD_WIDTH/2+2, y + CARD_HEIGHT/2+1);
		display_suit();
		stamp_bottom_double(x,y);
		break;
	case TEN:
		stamp_mid_top(x,y);
		stamp_top_double(x,y);
		gotoxy(x+CARD_WIDTH/2-2, y + CARD_HEIGHT/2-1);
		display_suit();
		gotoxy(x+CARD_WIDTH/2+2, y + CARD_HEIGHT/2-1);
		display_suit();
		gotoxy(x+CARD_WIDTH/2-2, y + CARD_HEIGHT/2+1);
		display_suit();
		gotoxy(x+CARD_WIDTH/2+2, y + CARD_HEIGHT/2+1);
		display_suit();
		stamp_bottom_double(x,y);
		stamp_mid_bottom(x,y);		
		break;
	case JACK:
		break;
	case QUEEN:
		break;
	case KING:
		break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(x+CARD_WIDTH + 2, y + CARD_HEIGHT + 2);
}

void Card::stamp_top_single(int x, int y)
{
	gotoxy(x+CARD_WIDTH/2, y + 2);
	display_suit();
}

void Card::stamp_mid_single(int x, int y)
{
	gotoxy(x + CARD_WIDTH/2, y + CARD_HEIGHT/2);
	display_suit();
}

void Card::stamp_bottom_single(int x, int y)
{
	gotoxy(x+CARD_WIDTH/2, y+CARD_HEIGHT-2);
	display_suit();
}
void Card::stamp_top_double(int x, int y)
{
	gotoxy(x+CARD_WIDTH/2-2, y + 2);
	display_suit();
	gotoxy(x+CARD_WIDTH/2+2, y + 2);
	display_suit();
}
void Card::stamp_bottom_double(int x, int y)
{
	gotoxy(x+CARD_WIDTH/2-2, y+CARD_HEIGHT-2);
	display_suit();
	gotoxy(x+CARD_WIDTH/2+2, y+CARD_HEIGHT-2);
	display_suit();
}
void Card::stamp_mid_double(int x, int y)
{
	gotoxy(x+CARD_WIDTH/2-2, y + CARD_HEIGHT/2);
	display_suit();
	gotoxy(x+CARD_WIDTH/2+2, y + CARD_HEIGHT/2);
	display_suit();
}
void Card::stamp_mid_top(int x, int y)
{
	gotoxy(x+CARD_WIDTH/2, y + 3);
	display_suit();
}
void Card::stamp_mid_bottom(int x, int y)
{
	gotoxy(x+CARD_WIDTH/2, y+CARD_HEIGHT-3);
	display_suit();
}

