//*****************************************************
//Noah Stern
//CS 355
//Assignment 14
//11/15/2020
//Main(Driver)
//*****************************************************
#include <iostream>
#include "Vertex.h"
#include "WeightedGraph.h"
using namespace std;

int main() 
{
  WeightedGraph graph;
  graph.readFromFile();
  graph.showGraph();
  return 0;
}
