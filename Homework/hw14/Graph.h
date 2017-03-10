#ifndef _Graph_
#define _Graph_
// 1. Implement a stack data structure as a C++ class. Here is a concise definition for a stack. 
// Please use a simple array as the basis for your data structure. Your stack should have a constructor whose
// argument gives the maximum number of elements to be stored in the stack (thus allowing you to allocate an appropriate fixed-size array),
// as well as push and pop methods. Please submit the C++ code via git.

#include <iostream>
#include <vector>
using namespace std;

struct adjacencyElement {
    int vertex;
    vector<int> adjacentVertices;
    adjacencyElement(int);
    void printAll();
};

class Graph {
    private:
        int listSize;
        int edgeNum;
        // int **unformatted;
        vector <adjacencyElement> adjacencyList;
        vector<int> visitStack;
        vector <int> returnVector;
        void constructGraph(vector <vector <int> >);
        bool searchHaveVisited(int);
        int searchAdjacencyList(int);
        int findMin(int);
        // int search(int);
    public:
        Graph(const char *);
        void printAdjacentVertices(int);
        void printAll();
        vector<int> dfs(int);
};



#endif