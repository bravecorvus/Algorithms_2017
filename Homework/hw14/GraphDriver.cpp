#include <iostream>
using namespace std;
#include "Graph.h"
#include "elapsed_time.h"
#include <string>
#include <vector>

int main() {
    const char* filename = "input.txt";
    Graph test(filename);
    int root = 0;
    vector <int> dfsOn0 = test.dfs(root);
    cout << "Running DFS on the test graph. The root is " << root << " and using the DFS algorithm, the went through the following vertices in order:\n[";
    for (vector<int>::iterator z=dfsOn0.begin(); z !=dfsOn0.end(); ++ z) {
        if (z == dfsOn0.end()-1) {
            cout << *z << "]";
        } else {
            cout << *z << " ";
        }
    }
    cout << "\n\nNow you can test different values on here, enter 'exit' to exit program" << endl;
    vector <int> dfsvector;
    string userinput;
    int converteduserinput;
    while (true) {
        cin >> userinput;
        if (userinput == "exit") {
            break;
        }
        converteduserinput = stoi(userinput);
        dfsvector = test.dfs(converteduserinput);
        cout << "Running DFS on the test graph. The root is " << converteduserinput << " and using the DFS algorithm, the went through the following vertices in order:\n[";
        if (dfsvector.size() == 0) {
            cout << converteduserinput << "]\n\n";
        } else {
            for (vector<int>::iterator z=dfsvector.begin(); z !=dfsvector.end(); ++ z) {
                if (z == dfsvector.end()-1) {
                    cout << *z << "]";
                } else {
                    cout << *z << " ";
                }
            }
            cout << "\n\n" << endl;
        }
    }
}