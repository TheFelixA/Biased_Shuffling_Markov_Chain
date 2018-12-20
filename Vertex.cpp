#include "Vertex.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Vertex::Vertex()
{
	data = 1;
	e1 = NULL;
	e2 = NULL;
	e3 = NULL;
}

Vertex::Vertex(int x)
{
	data = x;
	e1 = NULL;
	e2 = NULL;
	e3 = NULL;
}
//makes all three vertice of a vertex points to 3 new vertices with data x,y, and z
void Vertex::edges(Vertex* v, int x, int y, int z)
{
	Vertex* v1 = new Vertex(x);
	//v1->e1 = v;
	e1 = v1;

	Vertex* v2 = new Vertex(y);
	//v2->e1 = v;
	e2 = v2;

	Vertex* v3 = new Vertex(z);
	//v3->e1 = v;
	e3 = v3;
}