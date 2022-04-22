//*****************************************************
//Noah Stern
//CS 355
//Assignment 14
//11/15/2020
//WeightedGraph header
//*****************************************************
#include <iostream>
#include <fstream>
#include "Vertex.h"
const string COLOR[] = {"red", "blue", "yellow", "green", "orange", "violet", "gray", "brown"};
class WeightedGraph 
{
  	private:
	    int numVertices;
	  	Vertex * vertex;
	  	int ** weight;
		void setVertexDegrees();
		void findVertexColoring();
	public:
	    WeightedGraph();
	  	~WeightedGraph();
	  	void readFromFile();
	  	void showGraph();
};
