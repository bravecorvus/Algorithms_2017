#include <vector>
#include <ostream>
#include <string>
#include <iostream>
using namespace std;
struct adjacencyRow{
    string vertex;
    vector <string> adjacentVertices;
    adjacencyRow(string arg1) {
        vertex = arg1;
    }
    adjacencyRow(string arg1, vector<string> arg2) {
        vertex = arg1;
        for (vector<string>::iterator z=arg2.begin(); z !=arg2.end(); ++ z) {
            adjacentVertices.push_back(*z);
        }
    }
    void rewrite(string arg1, vector<string> arg2) {
        vertex = arg1;
        adjacentVertices.clear();
        for (vector<string>::iterator z=arg2.begin(); z !=arg2.end(); ++ z) {
            adjacentVertices.push_back(*z);
        }   
    }
    void print(ostream &os) const{
        os << "Vertex: " << vertex << "[";
            for (int i = 0, p = adjacentVertices.size(); i < p; ++i) {
                if (p - i == 1) {
                    os << adjacentVertices[i] << "]" << endl;
                    break;
                }
                os << adjacentVertices[i] << ", ";
            }
        }
};

ostream &operator<< (ostream &os, const adjacencyRow &n) {
        n.print(os);
        return os;
}

vector<adjacencyRow> adjacencyList;
vector<string>  stack;

bool searchVertex(vector<string> visited, string current) {
    int i; int p;
    int returnbool = false;
    for(i = 0, p = visited.size(); i < p; ++i) {
        if (current == visited[i]) {
            returnbool = true;
            break;
        }
    }
    return(returnbool);
}

vector<string> adjacentNotInVisited(adjacencyRow row, vector<string> visited) {
    vector<string> returnvector;
    for (vector<string>::iterator z=row.adjacentVertices.begin(); z !=row.adjacentVertices.end(); ++ z) {
        if (searchVertex(visited, *z) == false) {
            returnvector.push_back(*z);
        } else {
            continue;
        }
    }
    return(returnvector);
}

int findIndex(vector<adjacencyRow> thelist, string current) {
    int returnint = 0;
    for (vector<adjacencyRow>::iterator z=thelist.begin(); z !=thelist.end(); ++ z) {
        if (z->vertex == current) {
            break;
        }
        ++returnint;
    }
    return(returnint);
}

void dfs(vector<adjacencyRow> graph, string root) {
    vector<string> visited;
    string current;
    stack.push_back(root);
    while(stack.size() > 0) {
        current = stack[stack.size()-1];
        stack.pop_back();
        if (searchVertex(visited, current) == false) {
            visited.push_back(current);
            vector <string> unique = adjacentNotInVisited(graph[findIndex(graph, current)], visited);
            for (vector<string>::iterator z=unique.end()-1; z !=unique.begin()-1; -- z) {
                stack.push_back(*z);
            }
        }
    }
        cout << "Root: " << root << "  [";
        for (vector<string>::iterator z=visited.begin(); z !=visited.end(); ++ z) {
            if (z == visited.end()-1) {
                cout << *z << "]" << endl;
                break;
            }
            cout << *z << ", ";
        }
}

int main() {
    string ver;
    vector <string> adj;
    ver = "A";
    adj = {"B", "C"};
    adjacencyRow temp(ver, adj);
    adjacencyList.push_back(temp);
    ver = "B";
    adj.clear();
    adj = {"A", "D", "E"};
    temp.rewrite(ver, adj);
    adjacencyList.push_back(temp);
    ver = "C";
    adj.clear();
    adj = {"A", "F"};
    temp.rewrite(ver, adj);
    adjacencyList.push_back(temp);
    ver = "D";
    adj.clear();
    adj = {"B"};
    temp.rewrite(ver, adj);
    adjacencyList.push_back(temp);
    ver = "E";
    adj.clear();
    adj = {"B", "F"};
    temp.rewrite(ver, adj);
    adjacencyList.push_back(temp);
    ver = "F";
    adj.clear();
    adj = {"C", "E"};
    temp.rewrite(ver, adj);
    adjacencyList.push_back(temp);
        for (vector<adjacencyRow>::iterator z=adjacencyList.begin(); z !=adjacencyList.end(); ++ z) {
            cout << *z << endl;
        }
    dfs(adjacencyList, "A");
}