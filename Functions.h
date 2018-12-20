#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <stdlib.h>

//#include "Matrix.h"

using namespace std;

int factorial(int x);
int* orderedNums(int last);
int** permutations(int list[], int size);
double* setofQ(int numArray[], int size, int q);
//double* setOfProb(double numArray[], int size, double z);
bool isSame(int deck[], int list[], int size);
double addInv(double numArray[], int size);
//bool isRandTransposition(int deck[], int list[], int size);
//bool isTopRand(int deck[], int list[], int size);
void printArray(double numArray[], int size);
void printArray(int numArray[], int size);
void wholeMain();
int** printCombination(int arr[], int n, int r);
void combinationUtil(int arr[], int data[], int start, int end, int index, int r, int** comb, int &count);



// The main function that prints all combinations of size r
// in arr[] of size n. This function mainly uses combinationUtil()
int** printCombination(int arr[], int n, int r)
{
	int count = 0;
	// the possible number of combinations
	int numerator = factorial(n);
	int denom = factorial(r) * factorial(n - r);
	int numOfCom = numerator / denom;

	cout << "The num of combinations is " << numOfCom << endl;

	// A temporary array to store all combination one by one
	int* data = new int[r];

	//2d array that will be returned containing all combination
	int** combinations = new int*[numOfCom];
	for (int i = 0; i < numOfCom; i++)
	{
		combinations[i] = new int[r];
	}

	// Print all combination using temprary array 'data[]'
	combinationUtil(arr, data, 0, n - 1, 0, r, combinations, count);

	return combinations;
}

/* arr[]  ---> Input Array
data[] ---> Temporary array to store current combination
start & end ---> Staring and Ending indexes in arr[]
index  ---> Current index in data[]
r ---> Size of a combination to be printed */
void combinationUtil(int arr[], int data[], int start, int end, int index, int r, int** combinations, int &count)
{
	// Current combination is ready to be printed, print it
	if (index == r)
	{
		for (int j = 0; j < r; j++)
			combinations[count][j] = data[j];
		count = count + 1;
		return;
	}
	
	// replace index with all possible elements. The condition
	// "end-i+1 >= r-index" makes sure that including one element
	// at index will make a combination with remaining elements
	// at remaining positions
	for (int i = start; i <= end && end - i + 1 >= r - index; i++)
	{
		data[index] = arr[i];
		combinationUtil(arr, data, i + 1, end, index + 1, r, combinations, count);
	}
}


void wholeMain()
{
	ofstream shuffleData;

	//To find Transition Matrix
	int decknum = 4;
	int fact;

	cout << "How many cards are in your deck: ";
	cin >> decknum;
	fact = factorial(decknum);
	int* nums = orderedNums(decknum);
	int** perm = permutations(nums, decknum);

	//cout << "You lexographical order of cards are (Index::Order) " << endl;
	//for (int i = 0; i < fact; i++)
	//{
	//	cout << i + 1 << "::";
	//	for (int j = 0; j < decknum; j++)
	//	{
	//		cout << perm[i][j] << " ";
	//	}
	//	cout << "  ";
	//	if (i % 4 == 3)
	//		cout << endl;
	//}
	//

	//Matrix mat(fact, fact);

	////cout << "\nYour empty matrix is\n";
	////mat.printMatrix();
	//mat.transitionTopRand(decknum);

	//cout << "Your transition matrix with " << decknum << " cards is \n";
	//mat.printMatrix();

	//Implementing top to random for larger values of n
	Deck test;
	int index;
	bool found;
	//Count keeps track of howmany times an ordering occurs
	int* count = new int[fact];
	for (int i = 0; i < fact; i++)
	{
		count[i] = 0;
	}
	int* deckArray;
	//deck of 4 cards
	for (int i = 0; i < decknum; i++)
	{
		test.push();
	}
	cout << "The starting order of the cards is: ";
	test.printDeck();

	//
	//Inversions and transition to next toptorand using their prob
	//double z;
	//double* setQ;
	//const double q = 0.5;
	//int* invCount = test.setOfInv();
	//double rnum;
	//for (int i = 0; i < 10; i++)
	//{
	//	//prints the inversion for each top to random shuffle
	//	//printArray(invCount, decknum);
	//	//test.printDeck();
	//	setQ = setofQ(invCount, decknum, q);
	//	z = addInv(setQ, decknum);

	//	//multiplies the q by 100 so we can use a random number to distribute
	//	for (int i = 0; i < decknum; i++)
	//	{
	//		setQ[i] = 100 * (setQ[i] / z);
	//	}
	//	//printArray(setQ, decknum);
	//	rnum = (rand() % 100) + 1;
	//	cout << "Random number is " << rnum << endl;
	//	int seti = 0;
	//	//finds the appropriate place to put the card based on our bias and random number
	//	//while rand is >0 we keep subtracting intervals to find where we should insert card
	//	while (rnum > 0)
	//	{
	//		rnum -= setQ[seti];
	//		seti++;
	//	}
	//	cout << "SetQ index is " << seti - 1 << endl;
	//	test.topFixShuffle(seti);

	//	test.printDeck();
	//	cout << endl;
	//}
	//

	for (int i = 0; i < 10000; i++)
	{
		found = false;
		for (int j = 0; j < 10000; j++)
		{
			test.topRandShuffle();
			//cout << "\n";
			//test.printDeck();
		}
		//cout << "\n";
		//test.printDeck();

		deckArray = test.deckToArray();
		int k = 0;
		while (!found && k < fact)
		{
			found = isSame(deckArray, perm[k], decknum);
			k++;
		}
		index = k - 1;
		count[index]++;

	}

	/*cout << "\n";
	for (int i = 0; i < fact; i++)
	{
	cout << "Index: " << i + 1 << ", Count: " << count[i] << " ";
	if (i % 3 == 2)
	cout << endl;
	}
	cout << "\n";*/
	//test.printDeck();

	shuffleData.open("10000Tx10000S.txt");
	shuffleData << "Index" << "," << "Count" << endl;
	for (int i = 0; i < fact; i++)
	{
		shuffleData << i + 1 << "," << count[i] << endl;
	}
	shuffleData.close();
}

int factorial(int x)
{
	if (x == 0)
		return 1;
	else
		return (x * factorial(x - 1));
}

int* orderedNums(int last)
{
	int* list;
	list = new int[last];
	for (int i = 0; i < last; i++)
	{
		list[i] = i + 1;
	}

	return list;
}

int** permutations(int list[], int size)
{
	//numer of orders of permutations
	int orders = factorial(size);
	//creates a 2d array
	int** listOfPerm;
	//makes a 0rders by n array
	listOfPerm = new int*[orders];
	//initiallzes each row to be a an int array of size n
	for (int i = 0; i < orders; i++)
	{
		listOfPerm[i] = new int[size];
	}
	int i = 0;

	//transfers the permutations to the array
	do
	{
		for (int j = 0; j < size; j++)
		{
			listOfPerm[i][j] = list[j];
		}
		//cout << list[0] << " " << list[1] << " " << list[2] << endl;
		i++;
	} while (std::next_permutation(list, list + size));

	return listOfPerm;
}

//checks to see if deck and list of numbers are the same
bool isSame(int deck[], int list[], int size)
{
	bool same = true;
	for (int i = 0; i < size && same; i++)
	{
		if (deck[i] == list[i])
			same = true;
		else
			same = false;
	}
	return same;
}

////chechs to see if 2 arrays are a top to random shuffles of each other
////takes in as input the deck to shuffle and list to compare to
//bool isRandTransposition(int deck[], int list[], int size)
//{
//	bool found = true;
//	for (int i = 0; i < size && found; i++)
//	{
//		if (deck[i] == list[i])
//			found = true;
//		else
//			found = false;
//	}
//	int j = 1;
//	while (!found && j < size)
//	{
//		found = true;
//		int temp = deck[0];
//		deck[0] = deck[j];
//		deck[j] = temp;
//		for (int i = 0; i < size && found; i++)
//		{
//			if (deck[i] == list[i])
//				found = true;
//			else
//				found = false;
//		}
//		temp = deck[0];
//		deck[0] = deck[j];
//		deck[j] = temp;
//		j++;
//
//	}
//	return found;
//}
//
////takes a deck to compare to list of numbers to see if it is a toprandom shuffle
//bool isTopRand(int deck[], int list[], int size)
//{
//	//copies the deck because we are going to modify it
//	int* deckcopy = new int[size];
//	for (int i = 0; i < size; i++)
//	{
//		deckcopy[i] = deck[i];
//	}
//	
//	bool found = isSame(deck, list, size);
//	if (found)
//		return found;
//	else
//	{
//		for (int j = 1, k = 0; j < size && !found; j++, k++)
//		{
//			int temp = deck[k];
//			deck[k] = deck[j];
//			deck[j] = temp;
//			found = isSame(deck, list, size);
//		}
//	}
//	//returns deck back to normal
//	for (int i = 0; i < size; i++)
//	{
//		deck[i] = deckcopy[i];
//	}
//	delete[] deckcopy;
//
//	return found;
//}

void printArray(int numArray[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << numArray[i] << " ";
	}
	cout << endl;
}

void printArray(double numArray[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << numArray[i] << " ";
	}
	cout << endl;
}

//makes an array of all q
double* setofQ(int numArray[], int size, double q)
{
	double* qset = new double[size];
	for (int i = 0; i < size; i++)
	{
		qset[i] = pow(q, numArray[i]);
	}

	return qset;
}

//Find the denomitator z
double addInv(double numArray[], int size)
{
	double total = 0;
	for (int i = 0; i < size; i++)
	{
		total += numArray[i];
	}

	return total;
}



#endif