#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct jug{
    // int capacity;
    vector<bool> watermeasure;
    void initialize(int totalCapacity, int howMuchWater) {
        for(int i = 0; i < totalCapacity; ++i) {
            // cout << "AHHH" << endl;
            watermeasure.push_back(true);
        }
        for (int i = howMuchWater; i < watermeasure.size(); ++i) {
            // cout << "EHHHHH" << endl;
            watermeasure[i] = false;
        }
    }
    int countFull() {
        int i;
        for (i = 0; i < watermeasure.size(); ++i) {
            if (watermeasure[i] == false) {
                break;
            }
        }
        return(i);
    }
    int countEmpty() {
        int i;
        for (i = 0; i < watermeasure.size(); ++i) {
            ++i;
        }
        return(watermeasure.size()-i);
    }
    void print() {
        cout << "The capacity of this jug is " << watermeasure.size() << " and it current has " << countFull() << " units of water.";
    }
    int fillToMax(int howMuchInOtherJug) {
        // cout << "HOW MUCH IN JUG  " << howMuchInOtherJug << endl;
        // cout << "YOLO " << currentIndex << " " << capacity << endl;
        // cout << "getDistanceToCapacity " << getDistanceToCapacity()-howMuchInOtherJug << endl;
        // cout << countEmpty() << endl;
        int difference = countEmpty()-howMuchInOtherJug;
        if (difference > 0) {
            for(int i = countFull(); i < countFull()+difference; ++i) {
                watermeasure[i] = true;
            }
            return(0);
        } else if (difference <= 0) {
            for(int i = countFull(); i < watermeasure.size(); ++i) {
                watermeasure[i] = true;
            }
            return(difference);
        } else {
            return(0);
        }
    }
    void pourOut(int arg) {
        int temp = countFull() + arg;
        for(int i = countFull()-1; i >= 0; --i) {
            // cout << i << endl;
            // cout << watermeasure[i] << endl;
            watermeasure[i] = false;
        }
    }
};

struct juggs{
    jug jug4;
    jug jug7;
    jug jug10;
    void print() {
        cout << jug4.countFull() << "/" << jug4.watermeasure.size() << "  ";
        cout << jug7.countFull() << "/" << jug7.watermeasure.size() << "  ";
        cout << jug10.countFull() << "/" << jug10.watermeasure.size();
    }
};

struct adjacencyElement {
    juggs vertex;
    vector<juggs> adjacentVertices;
    // adjacencyElement(int);
    void initialization(juggs arg1) {
        vertex = arg1;
    }
    void initialization(juggs arg1, vector<juggs> arg2) {
        vertex = arg1;
        adjacentVertices = arg2;
    }
    void initialization(vector<juggs> arg2) {
        adjacentVertices = arg2;
    }
    void print() {
        cout << "Jug struct for "; vertex.print(); cout << ":   {";
        for(int i = 0; i < adjacentVertices.size(); ++i) {
            adjacentVertices[i].print();
        }
        cout << "}" << endl;
    }
};

class Graph{
    vector <adjacencyElement > adjacencyList;
public:
    Graph(){
        juggs startJuggs;
        startJuggs.jug4.initialize(4, 4);
        startJuggs.jug7.initialize(7, 7);
        startJuggs.jug10.initialize(10, 0);
        adjacencyElement temp;
        temp.vertex = startJuggs;
        temp.adjacentVertices.push_back(startJuggs);
        adjacencyList.push_back(temp);
        adjacencyList[0].print();
        constructGraph(0, adjacencyList[0].adjacentVertices);
    }
    void constructGraph(int index, vector <juggs> arg) {
        for (int i = 0; i < arg.size(); ++i) {
            arg[i].print();
        }
        cout << "\n\n\n";
        int count = index;
        vector <juggs> tempAdjacencyList;
        adjacencyElement tempAdjacencyElement;
        for (int i = 0; i < arg.size(); ++i) {
            tempAdjacencyList.erase(tempAdjacencyList.begin(), tempAdjacencyList.end());
             tempAdjacencyList = bfs(arg[i]);
             if (tempAdjacencyList.size() != 0) {
                for (int p = 0; p < tempAdjacencyList.size(); ++p) {
                    if (!vertexIn(tempAdjacencyList[i])) {
                        juggs newvertex;
                        newvertex.jug4 = tempAdjacencyList[i].jug4;
                        newvertex.jug7 = tempAdjacencyList[i].jug7;
                        newvertex.jug10 = tempAdjacencyList[i].jug10;
                        newvertex.print();
                        tempAdjacencyElement.initialization(newvertex, tempAdjacencyList);
                        adjacencyList.push_back(tempAdjacencyElement);
                        ++count;
                    } else {
                        int indexx = findVertex(adjacencyList[index]);
                            for (vector<juggs>::iterator z=tempAdjacencyList.begin(); z !=tempAdjacencyList.end(); ++ z) {
                                adjacencyList[indexx].adjacentVertices.push_back(*z);
                            }
                    }
                }
            }
        }
        if (count > index) {
            for (int i = index; i <= count; ++i) {
                constructGraph(i, adjacencyList[i].adjacentVertices);
            }
        }
    }
    vector <juggs> bfs(juggs root) {
        int max;
        int index;
        max = root.jug4.countFull();
        index = 4;
        if (max < root.jug7.countFull()) {
            max = root.jug7.countFull();
            index = 7;
        }
        if (max < root.jug10.countFull()) {
            max = root.jug10.countFull();
            index = 10;
        }
        juggs temp1, temp2;
        temp1.jug4.initialize(root.jug4.countFull()+root.jug4.countEmpty(), root.jug4.countFull());
        temp1.jug7.initialize(root.jug7.countFull()+root.jug7.countEmpty(), root.jug7.countFull());
        temp1.jug10.initialize(root.jug10.countFull()+root.jug10.countEmpty(), root.jug10.countFull());
        temp2.jug4.initialize(root.jug4.countFull()+root.jug4.countEmpty(), root.jug4.countFull());
        temp2.jug7.initialize(root.jug7.countFull()+root.jug7.countEmpty(), root.jug7.countFull());
        temp2.jug10.initialize(root.jug10.countFull()+root.jug10.countEmpty(), root.jug10.countFull());
        if (index == 4) {
            int c = temp1.jug4.fillToMax(root.jug7.countFull());
            temp1.jug7.pourOut(c);
            int d = temp2.jug4.fillToMax(root.jug10.countFull());
            temp2.jug10.pourOut(d);
        } else if (index == 7) {
            int c = temp1.jug7.fillToMax(root.jug4.countFull());
            temp1.jug4.pourOut(c);
            int d = temp2.jug7.fillToMax(root.jug10.countFull());
            temp2.jug10.pourOut(d);
        } else if (index == 10) {
            int c = temp1.jug10.fillToMax(root.jug4.countFull());
            temp1.jug4.pourOut(c);
            int d = temp2.jug10.fillToMax(root.jug7.countFull());
            temp2.jug7.pourOut(d);
        }
        if (vertexIn(temp1)) {
            temp1.jug4.initialize(root.jug4.countFull()+root.jug4.countEmpty(), root.jug4.countFull());
            temp1.jug7.initialize(root.jug7.countFull()+root.jug7.countEmpty(), root.jug7.countFull());
            temp1.jug10.initialize(root.jug10.countFull()+root.jug10.countEmpty(), root.jug10.countFull());
            max = 0;
            if (index == 4) {
                if (root.jug10.countFull() > root.jug7.countFull()) {
                    int c = temp1.jug10.fillToMax(root.jug4.countFull());
                    temp1.jug4.pourOut(c);
                } else {
                    int c = temp1.jug7.fillToMax(root.jug4.countFull());
                    temp1.jug4.pourOut(c);
                }
            } else if (index == 7) {
                if (root.jug4.countFull() > root.jug10.countFull()) {                
                    int c = temp1.jug4.fillToMax(root.jug7.countFull());
                    temp1.jug7.pourOut(c);
                } else {
                    int c = temp1.jug10.fillToMax(root.jug4.countFull());
                    temp1.jug4.pourOut(c);
                }
            } else if (index == 10) {
                if (root.jug4.countFull() > root.jug7.countFull()) {
                    int c = temp1.jug4.fillToMax(root.jug7.countFull());
                    temp1.jug7.pourOut(c);
                } else {
                    int c = temp1.jug7.fillToMax(root.jug4.countFull());
                    temp1.jug4.pourOut(c);
                }
            }
        }

        if (vertexIn(temp2)) {
            temp2.jug4.initialize(root.jug4.countFull()+root.jug4.countEmpty(), root.jug4.countFull());
            temp2.jug7.initialize(root.jug7.countFull()+root.jug7.countEmpty(), root.jug7.countFull());
            temp2.jug10.initialize(root.jug10.countFull()+root.jug10.countEmpty(), root.jug10.countFull());
            max = 0;
            if (index == 4) {
                if (root.jug10.countFull() > root.jug7.countFull()) {
                    int d = temp2.jug10.fillToMax(root.jug7.countFull());
                    temp2.jug7.pourOut(d);
                } else {
                    int d = temp2.jug7.fillToMax(root.jug10.countFull());
                    temp2.jug10.pourOut(d);
                }
            } else if (index == 7) {
                if (root.jug4.countFull() > root.jug10.countFull()) {                
                    int d = temp2.jug4.fillToMax(root.jug10.countFull());
                    temp2.jug10.pourOut(d);
                } else {
                    int d = temp2.jug10.fillToMax(root.jug7.countFull());
                    temp2.jug7.pourOut(d);   
                }
                    
            } else if (index == 10) {
                if (root.jug4.countFull() > root.jug7.countFull()) {
                    int d = temp2.jug4.fillToMax(root.jug10.countFull());
                    temp2.jug10.pourOut(d);
                } else {
                    int d = temp2.jug7.fillToMax(root.jug10.countFull());
                    temp2.jug10.pourOut(d);
                }
                    
            }
        }
        if (vertexIn(temp1)) {
            temp1.jug4.initialize(root.jug4.countFull()+root.jug4.countEmpty(), root.jug4.countFull());
            temp1.jug7.initialize(root.jug7.countFull()+root.jug7.countEmpty(), root.jug7.countFull());
            temp1.jug10.initialize(root.jug10.countFull()+root.jug10.countEmpty(), root.jug10.countFull());
            max = 0;
            if (index == 4) {
                if (root.jug10.countFull() > root.jug7.countFull()) {
                    int c = temp1.jug10.fillToMax(root.jug7.countFull());
                    temp1.jug7.pourOut(c);
                } else {
                    int c = temp1.jug7.fillToMax(root.jug10.countFull());
                    temp1.jug10.pourOut(c);
                }
            } else if (index == 7) {
                if (root.jug4.countFull() > root.jug10.countFull()) {                
                    int c = temp1.jug4.fillToMax(root.jug10.countFull());
                    temp1.jug10.pourOut(c);
                } else {
                    int c = temp1.jug10.fillToMax(root.jug7.countFull());
                    temp1.jug7.pourOut(c);
                }
            } else if (index == 10) {
                if (root.jug4.countFull() > root.jug7.countFull()) {
                    int c = temp1.jug4.fillToMax(root.jug10.countFull());
                    temp1.jug10.pourOut(c);
                } else {
                    int c = temp1.jug7.fillToMax(root.jug10.countFull());
                    temp1.jug10.pourOut(c);
                }
            }
        }

        if (vertexIn(temp2)) {
            temp2.jug4.initialize(root.jug4.countFull()+root.jug4.countEmpty(), root.jug4.countFull());
            temp2.jug7.initialize(root.jug7.countFull()+root.jug7.countEmpty(), root.jug7.countFull());
            temp2.jug10.initialize(root.jug10.countFull()+root.jug10.countEmpty(), root.jug10.countFull());
            max = 0;
            if (index == 4) {
                if (root.jug10.countFull() > root.jug7.countFull()) {
                    int d = temp2.jug10.fillToMax(root.jug4.countFull());
                    temp2.jug4.pourOut(d);
                } else {
                    int d = temp2.jug7.fillToMax(root.jug4.countFull());
                    temp2.jug4.pourOut(d);
                }
            } else if (index == 7) {
                if (root.jug4.countFull() > root.jug10.countFull()) {                
                    int d = temp2.jug4.fillToMax(root.jug7.countFull());
                    temp2.jug7.pourOut(d);
                } else {
                    int d = temp2.jug10.fillToMax(root.jug4.countFull());
                    temp2.jug4.pourOut(d);   
                }
                    
            } else if (index == 10) {
                if (root.jug4.countFull() > root.jug7.countFull()) {
                    int d = temp2.jug4.fillToMax(root.jug7.countFull());
                    temp2.jug7.pourOut(d);
                } else {
                    int d = temp2.jug7.fillToMax(root.jug4.countFull());
                    temp2.jug4.pourOut(d);
                }   
            }
        }
    vector <juggs> temp;
    if (vertexIn(temp1)) {
        cout << "No valid candidates for split 1" << endl;
    } else {
        temp.push_back(temp1);
        if((temp1.jug4.countFull() == 2) || (temp1.jug7.countFull() == 2)) {
            cout << "SUCCESS! Winning Combo at "; temp1.print();
        }
    }
    if (vertexIn(temp2)) {
        cout << "No valid candidates for split 2" << endl;
    } else {
        temp.push_back(temp2);
        if((temp2.jug4.countFull() == 2) || (temp2.jug7.countFull() == 2)) {
            cout << "SUCCESS! Winning Combo at "; temp2.print();
        }
    }
    return(temp);
    }

    bool vertexIn(juggs arg) {
        for (int i = 0; i < adjacencyList.size(); ++i) {
            if ((adjacencyList[i].vertex.jug4.watermeasure == arg.jug4.watermeasure) && (adjacencyList[i].vertex.jug7.watermeasure == arg.jug7.watermeasure) && (adjacencyList[i].vertex.jug10.watermeasure == arg.jug10.watermeasure)) {
                return(true);
                break;
            }
        }
    return(false);
    }

    int findVertex(adjacencyElement arg) {
        for(int i = 0; i < adjacencyList.size(); ++i) {
            if ((arg.vertex.jug4.watermeasure == adjacencyList[i].vertex.jug4.watermeasure) && (arg.vertex.jug7.watermeasure == adjacencyList[i].vertex.jug7.watermeasure) && (arg.vertex.jug10.watermeasure == adjacencyList[i].vertex.jug10.watermeasure)) {
                return(true);
            }
        }
        return(false);
    }
    void print() {
        for(int i = 0; i < adjacencyList.size(); ++i) {
            cout << adjacencyList[i].vertex.jug4.countFull() << "/" << adjacencyList[i].vertex.jug4.countFull() + adjacencyList[i].vertex.jug4.countEmpty() << ":   [";
            for(int p = 0; p < adjacencyList[i].adjacentVertices.size(); ++p) {
                cout << adjacencyList[i].adjacentVertices[p].jug4.countFull() << "/" << adjacencyList[i].adjacentVertices[p].jug4.countFull() + adjacencyList[i].adjacentVertices[p].jug4.countEmpty() << " ";
            }
        }
        cout << "]\n";
    }
};


int main() {
    Graph test;   
    jug test2;
    test2.initialize(10, 0);
}