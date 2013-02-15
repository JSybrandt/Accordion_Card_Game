#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <Windows.h>

enum Suit {HEARTS = 3, DIAMONDS, CLUBS, SPADES, END_OF_SUITS };
enum Rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, 
		   EIGHT, NINE, TEN, JACK, QUEEN, KING, END_OF_RANKS};

Suit next_suit(Suit s);
Rank next_rank(Rank r);

void gotoxy(int x, int y);
const int CARD_WIDTH = 10;
const int CARD_HEIGHT = 10;

class Card
{
public:
	Card():rank(ACE), suit(DIAMONDS){}
	Card(Rank r, Suit s);
	friend std::ostream& operator<<(std::ostream& out, Card x);
	//NEW
	void sketch(int x, int y, bool face_up = true, bool stack = false);
	Suit get_suit(){return suit;}
	Rank get_rank(){return rank;}
	void set_suit(Suit s);
	void set_rank(Rank r);
	void display_suit(std::ostream& out = std::cout);
	void display_rank(std::ostream& out = std::cout);

private:
	void stamp(int x, int y);
	void stamp_top_single(int x, int y);
	void stamp_mid_single(int x, int y);
	void stamp_bottom_single(int x, int y);
	void stamp_top_double(int x, int y);
	void stamp_bottom_double(int x, int y);
	void stamp_mid_double(int x, int y);
	void stamp_mid_top(int x, int y);
	void stamp_mid_bottom(int x, int y);
	Suit suit;
	Rank rank;
};

#endif