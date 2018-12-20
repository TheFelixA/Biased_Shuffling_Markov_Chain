#ifndef VERTEX_H
#define VERTEX_H

class Vertex
{
public:
	Vertex();
	Vertex(int length);
	Vertex()
	void edges(Vertex* v, int x, int y, int z);
	void edge(int x);

//private:
	friend class Hypercube;
	int data;
	Vertex* e1;
	Vertex* e2;
	Vertex* e3;
};

#endif