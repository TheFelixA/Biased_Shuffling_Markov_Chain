#include "Hypercube.h"
#include <iostream>
#include <cstdlib>

Hypercube::Hypercube()
{
	first = NULL;
	last = NULL;
	numOfE = 0;
}

void Hypercube::addEdge(int x, int y)
{
	first = new Vertex(x);
	last = new Vertex(y);
	numOfE =+ 2;
}