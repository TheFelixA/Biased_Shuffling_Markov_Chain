#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck
{
public:
	Deck();
	//keeps pushing cards to create a deck
	void push();
	//pushes card with the number x
	void push(int x);
	//removes the last card inserted
	void pop();
	//top to random shuffle
	void topRandShuffle();
	void randTanspose();
	//top to random shuffle in a positon of choice
	void topFixShuffle(int x);
	//takes in a decks and sees ifit can be created from a top to random shuffle, true if yes, false if no
	bool isTopRandom(Deck y);
	//takes in a deck and sees if it is the same
	bool isSame(Deck y);
	void printDeck();
	//converts deck from linked list to array
	int* deckToArray();
	int size();
	//find the number of inversions
	int inversions();
	//creates a 2d array with all possible inversions with the index 0 being inversions at same position, and n is last possible top to rand 
	int* setOfInv();
	
private:
	Card* first;
	Card* last;
	int numOfCards;
};

#endif 
