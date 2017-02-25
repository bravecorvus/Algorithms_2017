#include <iostream>
#include <vector>
using namespace std;

int main() {

    string a;
    cout << "Enter string" << endl;
    cin >> a;
    char b[a.size()];
    for(int i = 0; i < a.size(); ++i) {
        b[i] = a[i];
    }
    int first = b[0];
    int last = b[sizeof(b)/sizeof(char)-1];
    int second;
    if (sizeof(b)/sizeof(char) == 1) {
        second = last;
    } else {
        second = b[1];
    }
    int modthis = 499;
    int hashkey = second * (first+last)%modthis;
    // vector<int> * newnew = new vector<int>(499);
    vector<vector <int> > newnew;
    newnew.reserve(500);
    newnew[0].push_back(15);
    cout << newnew.size() << endl;
}