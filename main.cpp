#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Card.h"
#include "Deck.h"
#include <algorithm>
#include "Matrix.h"
#include <fstream>
#include "Functions.h"
#include "Vertex.h"
#include "Hypercube.h"
#include <cmath>
#include <math.h>

using namespace std;

int main()
{
	srand(time(NULL));

	//array of odd numbers between 1-8
	int odd[4];

	//array of even numbers between 1-8
	int even[4];

	//4 n 3 of the odd and even arrays
	int** oarr;
	int** earr;

	//initialize odd array
	for (int i = 0; i < 4; i++)
	{
		odd[i] = 2 * i + 1;
	}

	//initialize odd array
	for (int i = 0; i < 4; i++)
	{
		even[i] = 2 * (i + 1);
	}

	//creates an array of all combinations of 4 choose 3
	earr = printCombination(even, 4, 3);
	oarr = printCombination(odd, 4, 3);

	//wholeMain();

	//Generate a 2d Array with first column as the vertex you are at and rest of the columns are other vertices you can travel
	int** edges = new int*[8];
	for (int i = 0; i < 8; i++)
	{
		edges[i] = new int[4];
		edges[i][0] = i + 1;
	}
	//initializing the edges
	
	for (int i = 0; i < 8; i++)
	{
		if (edges[i][0] % 2 == 1)
		{
			for (int j = 1; j < 4; j++)
			{
				edges[i][j] = earr[i/2][j-1];
			}
		}
		else
		{
			for (int j = 1; j < 4; j++)
			{
				edges[i][j] = oarr[(i-1)/2][j - 1];
			}
		}		
	}
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << edges[i][j] << " | ";
		}
		cout << endl;
	}
	cout << endl;
	
	//Perform choose your weapon
	int vertex1, vertex2, temp, temp2;
	for (int num = 0; num < 1; num++)
	{
		vertex1 = rand() % 8;
		vertex2 = rand() % 4;
		cout << "rand nums are " << vertex1 << " " << vertex2 << endl;
		if (vertex2 != 0)
		{
			int i = 0, j = 1;
			cout << "Edges: " << edges[vertex1][vertex2] << " " << edges[vertex1][0] << endl;
			temp2 = edges[vertex1][vertex2];
			temp = edges[vertex1][0];
			edges[vertex1][vertex2] = temp;
			edges[vertex1][0] = temp2;
			//cout << "V1: " << temp << ", V2: " << temp2 << endl;
			for
			while ((edges[i][0] != temp2 || i == vertex1) && i < 8)
			{
				i++;
			}
			while (edges[i][j] != temp && j < 4)
			{
				j++;
			}
			//cout << "edge: " << edges[i][0] << " " << edges[i][j] << endl;
			//cout << "I = " << i << " and J = " << j << endl;
			edges[i][0] = temp;
			edges[i][j] = temp2;
		}
	}
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cout << edges[i][j] << " | ";
			}
			cout << endl;
		}

	//Hypercube* test = new Hypercube();
	//test->addEdge(1, 8);
	//test->first->edges(test->first, 2, 4, 6);
	//test->first->e1->edges(test->first->e1, 1, 3, 5);
	////test->first->e1->e2->pointTo(2, 4, 8);
	////test->first->e1->e3->pointTo(2, 6, 8);
	////test->first->e2->edges(test->first->e2, 1, 3, 7);
	//test->first->e3->edges(test->first->e3, 1, 5, 7);

	///*test->last->pointTo(test->last, 3, 5, 7);
	//test->last->e1->pointTo(test->last, 2, 4, 8);
	//test->last->e2->pointTo(test->last, 2, 6, 8);
	//test->last->e3->pointTo(test->last, 4, 8, 8);*/

	//cout << test->first->data << test->first->e1->data << test->first->e2->data << test->first->e3->data << endl;
	////cout << test->last->data << test->last->e1->data << test->last->e2->data << test->last->e3->data << endl;

	////temp = test->first->data;
	////test->first->data = test->first->e2->data;
	////test->first->e2->data = temp;


	return 0;
}
