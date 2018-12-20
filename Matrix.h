#ifndef MATRIX_H
#define MATRIX_H

#include "Deck.h"

class Matrix
{
public:
	//creates a 1x1 matriz
	Matrix();
	//creates a rowxrow matrix
	Matrix(int row);
	//creates a rowxcolumn matrix
	Matrix(int row, int col);
	//creates an n! by n factorial matrix
	//Matrix(int n);
	//finds transition for n cards
	void transitionTopRand(int n);
	void printMatrix();
	int factorial(int x);
	int* orderedNums(int last);
	int** permutations(int list[], int size);
	bool isSame(int deck[], int list[], int size);
	bool isRandTransposition(int deck[], int list[], int size);
	bool isTopRand(int deck[], int list[], int size);

private:
	int** matrices;
	int rows;
	int cols;
};

#endif // !MATRIX_H
