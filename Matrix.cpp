#include "Matrix.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>

Matrix::Matrix()
{
	matrices = new int*[1];
	matrices[0] = new int[1];
	rows = cols = 1;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			matrices[i][j] = 0;
	}

}

Matrix::Matrix(int row)
{
	matrices = new int*[row];
	for (int i = 0; i < row; i++)
	{
		matrices[i] = new int[row];
	}
	rows = row;
	cols = 1;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			matrices[i][j] = 0;
	}

}

Matrix::Matrix(int row, int col)
{
	matrices = new int*[row];
	for (int i = 0; i < row; i++)
	{
		matrices[i] = new int[col];
	}

	rows = row;
	cols = col;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
			matrices[i][j] = 0;
	}
}

void Matrix::printMatrix()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << matrices[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

//creates a transition matrix from a n! by n! matrix
void Matrix::transitionTopRand(int n)
{
	//creates an array of ordered number from 1 to n;
	int* list = orderedNums(n);
	//uses list ro create a 2d array of permutations
	int** permlist = permutations(list, n);

	//goes through a row i in the matrix
	for (int i = 0; i < rows; i++)
	{
		//goes to each column j in the matrix
		for (int j = 0; j < cols ; j++)
		{
			//Assume array is sorted in lexographical permutation order. So it goes through to check if each index is a top to random shuffle of each other
			if (isTopRand(permlist[i], permlist[j], n))
			{
				matrices[i][j] = 1;
			}
		}
	}
	std::cout << "All spots with 1 are 1/" << n << std::endl;

}


int Matrix::factorial(int x)
{
	if (x == 0)
		return 1;
	else
		return (x * factorial(x - 1));
}

int* Matrix::orderedNums(int last)
{
	int* list;
	list = new int[last];
	for (int i = 0; i < last; i++)
	{
		list[i] = i + 1;
	}

	return list;
}

int** Matrix::permutations(int list[], int size)
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

bool Matrix::isSame(int deck[], int list[], int size)
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

//chechs to see if 2 arrays are a top to random shuffles of each other
//takes in as input the deck to shuffle and list to compare to
bool Matrix::isRandTransposition(int deck[], int list[], int size)
{
	bool found = true;
	for (int i = 0; i < size && found; i++)
	{
		if (deck[i] == list[i])
			found = true;
		else
			found = false;
	}
	int j = 1;
	while (!found && j < size)
	{
		found = true;
		int temp = deck[0];
		deck[0] = deck[j];
		deck[j] = temp;
		for (int i = 0; i < size && found; i++)
		{
			if (deck[i] == list[i])
				found = true;
			else
				found = false;
		}
		temp = deck[0];
		deck[0] = deck[j];
		deck[j] = temp;
		j++;

	}
	return found;
}

//takes a deck to compare to list of numbers to see if it is a toprandom shuffle
bool Matrix::isTopRand(int deck[], int list[], int size)
{
	//copies the deck because we are going to modify it
	int* deckcopy = new int[size];
	for (int i = 0; i < size; i++)
	{
		deckcopy[i] = deck[i];
	}

	bool found = isSame(deck, list, size);
	if (found)
		return found;
	else
	{
		for (int j = 1, k = 0; j < size && !found; j++, k++)
		{
			int temp = deck[k];
			deck[k] = deck[j];
			deck[j] = temp;
			found = isSame(deck, list, size);
		}
	}
	//returns deck back to normal
	for (int i = 0; i < size; i++)
	{
		deck[i] = deckcopy[i];
	}
	delete[] deckcopy;

	return found;
}