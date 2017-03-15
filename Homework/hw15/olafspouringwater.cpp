#include <ostream>
#include <iostream>
#include <vector>
using namespace std;
int capacity[] = {10, 4, 4};

struct Node{
    int state[3];
    Node(int i, int j, int k) {
        state[0]= i;
        state[1]= j;
        state[2]= k;
    }
    vector<Node> neighbors() const{
        vector<Node> result;
        for(int i = 0; i < 3; ++i) {
            for (int p = 0; p < 3; ++p) {
                int howMuch = state[i];
                if (howMuch + state[p] > capacity[p]) {
                    howMuch = capacity[p] - state[p];
                }
                if (i != p && howMuch > 0) {
                    Node n(*this);
                    n.state[p] += howMuch;
                    n.state[i] -= howMuch;
                    result.push_back(n);
                }
            }
        }
        return(result);
    }
    void print(ostream &os) const{
        os << state[0] << " " << state[1] << " " << state[2] << endl;
    }
    bool operator==(const Node&n) const {
        return(state[0] == n.state[0] && state[1] == n.state[1] && state[2] == n.state[2]);
    }
};
vector<Node> haveISeen;

ostream &operator<< (ostream &os, const Node &n) {
        n.print(os);
        return os;
}
    bool isGoal(const Node&n) {
        return n.state[1] == 2 || n.state[2] == 2;
    }

bool haveISeenIt(const Node&n) {
    for(int i = 0; i < haveISeen.size(); ++i) {
        if(n == haveISeen[i]) {
            return(true);
        }
    }    
    return(false);
}

void explore(const Node &n) {
    if (isGoal(n)) {
        cout << "YES! Found it!" << endl;
        return;
    }
    vector<Node>nbr = n.neighbors();
    // Node p(0, 0, 0);
    // bool temp;
    // for (int i = 0; i < haveISeen.size(); ++i) {
    //     p = haveISeen[i];
    //     temp = false;
    //     for(int z = 0; z < nbr.size(); ++i) {
    //         if (p == nbr[z]) {
    //             temp = true;
    //             break;
    //         }
    //     }
    //     if (!temp) {
    //         haveISeen.push_back(p);
    //     }
    // }
    for(int i = 0; i < nbr.size(); ++i) {
        explore(nbr[i]);
    }
}

int main() {
    Node start(0, 7, 4);        
    cout << start << endl;
    vector<Node> nbr = start.neighbors();
    for(int i = 0, i_end = nbr.size(); i < i_end; ++i) {
        cout << " " << nbr[i] << endl;
    }
}