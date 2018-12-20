#ifndef CARD_H
#define CARD_H

class Card
{
public:
	//creates a card with x as data
	Card(int x);
	Card();
	//prints the data of the card
	void printCard();

private:
	friend class Deck;
	int data;
	Card* next;
	//Card* prev;
};

#endif