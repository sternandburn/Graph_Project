//*****************************************************
//Noah Stern
//CS 355
//Assignment 14
//11/15/2020
//Vertex class header
//*****************************************************
#ifndef VERTEX_HEADER
#define VERTEX_HEADER
#include <iostream>
#include <fstream>
using namespace std;
const string COLOR[] = {"red", "blue", "yellow", "green", "orange", "violet", "gray", "brown"};

class Vertex 
{
	private:
    	string label;
		int degree;
  	public:
    	Vertex();
  		string getLabel();
  		void setLabel(string);
		int getDegree();
		void setDegree(int d);
};
#endif
