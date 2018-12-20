#ifndef HYPERCUBE_H
#define HYPERCUBE_H
#include "Vertex.h"

class Hypercube
{
public:
	//creates a 3d hypercube
	Hypercube();
	//creates a X-D hypercube
	void addEdge(int x, int y);
	void addDimension();
//private:
	int dimension;
	int** vertices;


};

#endif