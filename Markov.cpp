#include <iostream>
#include <fstream>
#include "Matrix.h"
#include "Graph.h"
#include <cstdlib>

using namespace  std;

Matrix MarkovClustering(const Graph& graph);
void CleanUp(Matrix& m);

int main() {
    
    ifstream infile("inputGraph.txt");
    if(!infile) {
        cerr<<"Error opening file."<<endl;
        exit(1);
    }
    
    int numVertices;
    
    infile>>numVertices;
    
    Graph graph(numVertices);
    
    infile>>graph;
    
    cout<<graph<<endl;
    
    cout<<endl<<endl<<endl;
    
    Matrix m = MarkovClustering(graph);
    
    CleanUp(m);
    cout<<m<<endl;
    
}

void CleanUp(Matrix& m) {
    for(int i=0; i<m.getNumRows(); i++)
        for(int j=0; j<m.getNumCols(); j++)
            if(m(i,j) <= 0.0001)
                m(i,j) = 0.0;
}

Matrix MarkovClustering(const Graph& graph) {
    
    Matrix M = graph.generateMarkov();
    cout<<M<<endl;
    
    while(true) {
        
        cout<<M<<endl<<endl;
        
        Matrix M1 = M.inflate();
        cout<<M1<<endl;
    
        M1 = M1 * M1;
        
    
        cout<<M1<<endl;
    
        if(M==M1)
          break;
        
        CleanUp(M1);
        M = M1;
        
    }
    
    return M;
}