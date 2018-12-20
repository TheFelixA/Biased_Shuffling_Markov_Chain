#include "Deck.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Deck::Deck()
{
	first = NULL;
	last = NULL;
	numOfCards = 0;
}

int Deck::size()
{
	return numOfCards;
}

void Deck::push()
{
	++numOfCards;
	if (first == NULL)
	{
		first = new Card(numOfCards);
		last = first;
	}
	else
	{
		last->next = new Card(numOfCards);
		last = last->next;
	}
}

void Deck::push(int x)
{
	++numOfCards;
	if (first == NULL)
	{
		first = new Card(x);
		last = first;
	}
	else
	{
		last->next = new Card(x);
		last = last->next;
	}
}

void Deck::topRandShuffle()
{
	//the random position to move the card to {0, 1, ... numOFcards}
	int position = (rand() % numOfCards);
	int hold;
	Card* temp = first;
	//cout << "Position is " << position;

	if (position == 0)
	{
		return;
	}
	else
	{
		while (position > 0)
		{
			hold = temp->data;
			temp->data = temp->next->data;
			temp->next->data = hold;
			temp = temp->next;

			position--;
		}
	}

}

void Deck::randTanspose()
{
	//the random position to move the card to {0, 1, ... numOFcards}
	int position = (rand() % numOfCards) + 1;
	//temperaility holds cards data
	int hold;
	Card* temp;
	temp = first;

	for (int i = 1; i < position; i++)
	{
		temp = temp->next;
	}

	hold = temp->data;
	temp->data = first->data;
	first->data = hold;
}

void Deck::topFixShuffle(int x)
{
	int hold;
	Card* temp;
	temp = first;

	for (int i = 1; i < x; i++)
	{
		temp = temp->next;
	}

	hold = temp->data;
	temp->data = first->data;
	first->data = hold;
}

void Deck::printDeck()
{
	if (numOfCards > 0)
	{
		Card* temp;
		temp = first;
		while (temp->next != NULL)
		{
			temp->printCard();
			temp = temp->next;
		}
		temp->printCard();
	}
}

bool Deck::isSame(Deck y)
{
	bool found = true;
	Card* temp1 = first;
	Card* temp2 = y.first;
	if (numOfCards == y.numOfCards)
	{
		int i = 0;
		while (found && i < numOfCards)
		{
			if (temp1->data == temp2->data)
			{
				found = true;
			}
			else
				found = false;
			temp1 = temp1->next;
			temp2 = temp2->next;
			i++;
		}
	}
	else
		return false;

	return found;
}

bool Deck::isTopRandom(Deck y)
{
	bool found = isSame(y);
	Card* temp1 = first;
	int position = 1;

	if (found)
		return found;
	else
	{
		//exchanges the data to keep making it a top to random shuffle
		while (position < numOfCards && !found)
		{
			int temp = temp1->data;
			temp1->data = temp1->next->data;
			temp1->next->data = temp;
			temp1 = temp1->next;
			/*temp2 = temp1->next;
			temp1->next = temp2->next;
			temp2->next = temp1;*/
			position++;
			found = isSame(y);
		}

		//return the list back to normal
		//while (position > 1)
		//{
		//	int temp = temp1->data;
		//	temp1->data = temp1->next->data;
		//	temp1->next->data = temp;
		//	/*temp2 = temp1->next;
		//	temp1->next = temp2->next;
		//	temp2->next = temp1;*/
		//	position--;
		//	found = isSame(y);
		//}
		return found;
	}



	//if (numOfCards == y.numOfCards)
	//{
	//	while (!found && i < numOfCards)
	//	{
	//		found = true;
	//		for (int j = 0; j < numOfCards && found; j++)
	//		{
	//			if (temp1->data == temp2->data)
	//				found = true;
	//			else
	//				found = false;
	//			temp1 = temp1->next;
	//			temp2 = temp2->next;
	//		}
	//	}

	//	/*while (temp1->next != NULL && temp2->next != NULL && found)
	//	{
	//		if (temp1->data == temp2->data)
	//		{
	//			found = true;
	//		}
	//		else
	//			found = false;
	//		temp1 = temp1->next;
	//		temp2 = temp2->next;
	//	}
	//	if (temp1->data == temp2->data)
	//	{
	//		found = true;
	//	}
	//	else
	//		found = false;


	//	if (!found)
	//	{
	//		found = true;
	//		while (temp1 != NULL && temp2 != NULL && found)
	//		{
	//			temp1 = x.first;

	//			if (temp1->data == temp2->data)
	//			{
	//				found = true;
	//			}
	//			else
	//				found = false;
	//		}
	//	}*/
	//}
	//else
	//	return false;
}

int* Deck::deckToArray()
{
	int* deck = new int[numOfCards];
	Card* temp = first;
	for (int i = 0; i < numOfCards; i++)
	{
		deck[i] = temp->data;
		temp = temp->next;
	}

	return deck;
}

int Deck::inversions()
{
	int count = 0;
	if (numOfCards == 0)
		return 0;
	else if (numOfCards == 1)
		return 1;
	else
	{
		Card* temp1 = first;
		Card* temp2;
		for (int i = 0; i < numOfCards; i++)
		{
			temp2 = temp1->next;
			for (int j = i+1; j < numOfCards; j++)
			{
				if (temp1->data > temp2->data)
					count++;
				temp2 = temp2->next;
			}
			temp1 = temp1->next;
		}
	}
	return count;
}

int* Deck::setOfInv()
{
	//array of numofInver
	int* inv;
	int hold;
	inv = new int[numOfCards];
	//create a new deck to use class functions on
	Deck cards;
	//temp1 is for our newly created deck, temp2 is to copy data from this deck to our new deck so we dont mess up the deck
	Card* temp1;
	Card* temp2 = first;
	//creating the new deck
	for (int i = 0; i < numOfCards; i++)
	{
		cards.push(temp2->data);
		temp2 = temp2->next;
	}
	temp1 = cards.first;
	int i = 0;
	//find the inversion of each top to random permutaion
	while (temp1->next != NULL && i < numOfCards)
	{
		inv[i] = cards.inversions();
		hold = temp1->data;
		temp1->data = temp1->next->data;
		temp1->next->data = hold;
		temp1 = temp1->next;
		i++;
	}
	inv[i] = cards.inversions();

	return inv;
}