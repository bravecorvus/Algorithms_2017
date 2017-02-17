#include <iostream>
#include <string>
using namespace std;

void recursion(int n, int &t) {
    t++;
    double x = 2 * 3;
    x = x * 3;

    if (n > 0) {
        recursion(n/2, t);
        recursion(n/2, t);
        recursion(n/2, t);
    }
}

int main() {
    string userinput;
    while (true) {
        int t = 0;
        cin >> userinput;
        int n = stoi(userinput);
        recursion(n, t);
        cout << t << endl;
    }
}