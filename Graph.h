#ifndef GRAPH_H
#define GRAPH_H

#include "Matrix.h"
#include <iostream>

using namespace std;

class Graph {
    
public:
    //Graph constructor
    Graph(int numVertices);
    
    //input function
    friend istream& operator>>(istream& is, Graph& graph);
    
    
    //output function
    
    friend ostream& operator<<(ostream& os, const Graph& graph);
    
    //generate markov matrix
    Matrix generateMarkov()const;
    
    
    
private:
    Matrix adjMat;
};

#endif