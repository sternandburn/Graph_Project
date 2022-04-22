//*****************************************************
//Noah Stern
//CS 355
//Assignment 14
//11/15/2020
//WeightedGraph implementation
//*****************************************************
#include <iostream>
#include <fstream>
#include "WeightedGraph.h"
using namespace std;

WeightedGraph::WeightedGraph() 
{
  	numVertices = 0;
}

WeightedGraph::~WeightedGraph() 
{
  	delete[] vertex;
	for (int i = 0; i < numVertices; i++) 
  	{
    	delete[] weight[i];
  	}
  	delete[] weight;
}

//***************************************************
//Name: readFromFile
//Purpose: Dynamically reads graph from the text file 
//Incoming: N/A
//Outgoing: N/A
//Return: N/A
//***************************************************
void WeightedGraph::readFromFile() 
{
  	string name = "", label = "";
  	cout << "Enter graph file name: ";
  	cin >> name;
  	ifstream inFile(name.c_str());
  	if (inFile.is_open()) 
  	{
    	inFile >> numVertices;
    	vertex = new Vertex[numVertices];
    	for (int i = 0; i < numVertices; i++) 
		{
      		inFile >> label;
      		vertex[i].setLabel(label);
    	}
    	weight = new int * [numVertices];
    	for (int y = 0; y < numVertices; y++) 
		{
      		weight[y] = new int[numVertices];
    	}
    	for (int x = 0; x < numVertices; x++) 
		{
      		for (int a = 0; a < numVertices; a++) 
	  		{
        		weight[x][a] = 0;
      		}
    	}
    	while (inFile.good()) 
		{
      		int a = 0, b = 0, weigh = 0;
      		string c = "", d = "";
      		inFile >> c >> d >> weigh;
      		for (int o = 0; o < numVertices; o++) 
	  		{
        		if (vertex[o].getLabel() == c) 
				{
          			a = o;
        		}
				else if	(vertex[o].getLabel() == d) 
				{
          			b = o;
        		}
      		}
      		weight[a][b] = weigh;
    	}

    	inFile.close();
  	}
  	else 
  	  	{
	    	cout << "File not found!";
	    	exit(0);
  	  	}
}

//***************************************************
//Name: showGraph
//Purpose: displays the graphs contents
//Incoming: N/A
//Outgoing: N/A
//Return: N/A
//***************************************************
void WeightedGraph::showGraph() 
{
  	cout << "Vertices" << endl;
  	for (int i = 0; i < numVertices; i++) 
  	{
    	cout << "  " << i << "   " << vertex[i].getLabel() << endl;
  	}
  	cout << endl << "Edges" << endl << "From/To";
  	for (int i = 0; i < numVertices; i++) 
  	{
    	cout << "	 " << vertex[i].getLabel();
  	}
  	cout << endl;
  	for (int i = 0; i < numVertices; i++) 
  	{
    	cout << "     " << vertex[i].getLabel();
    	for (int j = 0; j < numVertices; j++) 
		{
      		if (weight[i][j] == 0) 
	  		{
	  			cout << "	---";
	  		}
      		else
			{
				cout << "	" << weight[i][j];
			}
    	}
    cout << endl;
  }
}

void WeightedGraph::setVertexDegrees()
{
    int deg = 0;
	for (int i = 0; i < numVerticies; i++) 
	{
        deg = 0;
        for (int j = 0; j < numVerticies; j++) 
        {
            if (weight[i][j] > 0) 
			{
				deg = deg + 1;
			}
        }
        vertex[i].setDegree(deg);
    }
}

void WeightedGraph::findVertexColoring() 
{
    int count = 0;
	count = numVerticies;
	
    int res[count];
    for (int i = 0; i < count; i++)
    {
        res[i] = -1;
	}

    int open[count];
    for (int x = 0; x < count; x++) 
    {
        int b = 0, max = 0;
        for(int a = 0; a < count; a++)
		{
            if(res[a] == -1)
			{
				if (max < vertex[a].getDegree())
				{
	              b = a;
	              max = vertex[a].getDegree();
          		}
            }
        }

        for (int c = 0; c < count; c++)
        {
            open[c] = 1;
        }

        for (int v = 0; v < count; v++)
		{
            if (weight[b][v] > 0)
			{
                open[res[v]] = 0;
            }
        }

        for(int i = 0; i < count; i++)
		{
            if (open[i] == 1)
			{
                res[b] = i; 
                break;
            }
        }
    }

  	cout << endl <<"Colors:" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << vertex[i].getLabel() << " " << COLOR[res[i]] << endl;
    }
}


