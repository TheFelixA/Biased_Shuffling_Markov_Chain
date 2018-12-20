#include "Card.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Card::Card()
{
	data = (rand() % 52) + 1;
	next = NULL;
}

Card::Card(int x)
{
	data = x;
	next = NULL;
}

void Card::printCard()
{
	cout << data << " ";
}