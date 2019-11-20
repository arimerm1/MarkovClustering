#include "Matrix.h"
#include "Graph.h"
#include <iostream>
using namespace std;


//constructor
Graph::Graph(int numVertices):adjMat(numVertices, numVertices) {}
    
//input function
istream& operator>>(istream& is, Graph& graph) {
    int v1, v2;
    
    while(is>>v1>>v2) {
        graph.adjMat(v1, v2) = 1;
        graph.adjMat(v2, v1) = 1;
    }
    return is;
}
    
    //generate markov matrix
Matrix Graph::generateMarkov()const {
    
    Matrix result(adjMat.getNumRows(), adjMat.getNumCols());
    
    for(int i=0; i<adjMat.getNumRows(); i++)
        for(int j=0; j<adjMat.getNumCols(); j++)
            result[i][j] = adjMat[i][j];
    
    for(int i=0; i<result.getNumRows(); i++)
        result(i,i) = 1;
    cout<<result<<endl;
    
    for(int j=0; j<result.getNumCols(); j++) {
        double sum = 0.0;
        for(int i = 0; i<result.getNumRows(); i++)
            sum+= result(i,j);
        for(int i = 0; i<result.getNumRows(); i++)
            result(i,j)/= sum;
    }
    
    return result;
}

//output method

ostream& operator<<(ostream& os, const Graph& graph) {
    return os<<graph.adjMat;
}