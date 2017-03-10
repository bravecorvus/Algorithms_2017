#include <iostream>
#include "Graph.h"
#include <vector>
#include <string>
#include <fstream>
#include <algorithm> 
using namespace std;

adjacencyElement::adjacencyElement(int newNode) {
    vertex = newNode;
}

void adjacencyElement::printAll() {
    cout << " vertex " << vertex << "\nadjacent vertices ";
    for (vector<int>::iterator z=adjacentVertices.begin(); z !=adjacentVertices.end(); ++ z) {
        cout << *z << " ";
    }
    cout << "\n";
}

Graph::Graph(const char *filename) {
    vector <string> temp;
    ifstream f(filename);
    if ( ! f.good() ) {
        cerr << "Error:  unable to open " << filename << endl;
        exit(-1);
    }
    string s;
    int counter = 0;
    while ( f >> s ) {
        temp.push_back(s); //Throw in the values in a temp vector for now
        ++counter;
    }
    listSize = stoi(temp[2]);
    for (int i = 0; i < listSize; ++i) {
        adjacencyElement empty(i);
        adjacencyList.push_back(empty);
    }
    vector <vector <int> > unformatted;
    int p;
    edgeNum = stoi(temp[3]);
    for(int tempdoccounter = 5; tempdoccounter < counter; tempdoccounter +=3) {
        vector <int> temp2;
        p = stoi(temp[tempdoccounter]);
        temp2.push_back(p);
        p = stoi(temp[tempdoccounter+1]);
        temp2.push_back(p);
        unformatted.push_back(temp2);
    }
    constructGraph(unformatted);
}

void Graph::printAdjacentVertices(int arg) {
    for (vector<int>::iterator z=adjacencyList[arg].adjacentVertices.begin(); z !=adjacencyList[arg].adjacentVertices.end(); ++ z) {
        cout << *z << endl;
    }
}

void Graph::constructGraph(vector <vector <int > > unformatted) {
    for (int i = 0; i < edgeNum; ++i)
    {
        adjacencyList[unformatted[i][0]].adjacentVertices.push_back(unformatted[i][1]);
        adjacencyList[unformatted[i][1]].adjacentVertices.push_back(unformatted[i][0]);;
    }
}

void Graph::printAll() {
    for(int i = 0; i < listSize; ++i) {
        cout << adjacencyList[i].vertex << "  -------> [";
            for (vector<int>::iterator z=adjacencyList[i].adjacentVertices.begin(); z !=adjacencyList[i].adjacentVertices.end(); ++ z) {
                if (z == adjacencyList[i].adjacentVertices.end()-1) {
                    cout << *z;
                } else {
                    cout << *z << ", ";
                }
            }
        cout << "]" << endl;
    }
}

int Graph::findMin(int root) {
    int minimum = 999999999;
    int newminimum;
    bool newminimumisminimum;
    for(int i = 0; i < listSize; ++i) {
        newminimum = min(minimum, adjacencyList[root].adjacentVertices[i]);
        newminimumisminimum = true;
        for (int p = 0; p < returnVector.size(); ++p) {
            if (newminimum == returnVector[p]) {
                newminimumisminimum = false;
                break;
            }
        }
        if (newminimumisminimum == true) {
            minimum = newminimum;
            break;
        }
    }
    return(minimum);
}

vector <int> Graph::dfs(int root) {
    if (adjacencyList[root].adjacentVertices.size() == 0) {
        vector <int> empty;
        return(empty);
    }
    visitStack.erase(visitStack.begin(), visitStack.end());
    returnVector.erase(returnVector.begin(), returnVector.end());
    int currentElement = root;
    visitStack.push_back(currentElement);returnVector.push_back(currentElement);
    while (returnVector.size() != edgeNum) {
        currentElement = findMin(currentElement);
        if(currentElement == 999999999) {
            visitStack.pop_back();
            if (visitStack.size() > 0) {
                currentElement = visitStack[visitStack.size()-1];
            } else {
                break;
            }
        } else {
            returnVector.push_back(currentElement);
            visitStack.push_back(currentElement);
        }
    }
    return(returnVector);
}