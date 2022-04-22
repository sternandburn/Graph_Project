//*****************************************************
//Noah Stern
//CS 355
//Assignment 14
//11/15/2020
//Vertex class implementation
//*****************************************************
#include <iostream>
#include <fstream>
#include "Vertex.h"

Vertex::Vertex() 
{
	label = "";
}

string Vertex::getLabel() 
{
  	return label;
}

void Vertex::setLabel(string l) 
{
  	label = l;
}

int Vertex::getDegree() 
{
  return degree;
}

void Vertex::setDegree(int d) 
{
  degree = d;
}

