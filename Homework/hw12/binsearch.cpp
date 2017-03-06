#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int binarysearch(vector<int>array, int query) {
    for (vector<int>::iterator z=array.begin(); z !=array.end(); ++ z) {
        cout << ' ' << *z;
    }
    cout << "\n" << endl;
    int index = 0;
    if (array.size() == 2) {
        cout << "array size is 2" << endl;
        if (query == array[0]) {
            index = 0;
        } else if (query == array[1]) {
            index = 1;
        } else {
            index = -1;
        }
    } else {
        int midpoint = array.size()/2;
        if (array[midpoint] > query) {
            cout << "IF" << endl;
            vector<int> newarray(&array[0],&array[midpoint]);
            index = binarysearch(newarray, query);
        } else if (array[midpoint] < query) {
            cout << "ELSE IF" << endl;
            vector<int> newarray(&array[midpoint+1],&array[array.size()]);
            index = binarysearch(newarray, query);
            if (index >= 0) {
                index += midpoint;
            }
        } else if (array[midpoint] == query) {
            index = midpoint;
        }
    }
    return(index);
}

void arrayhandler(vector<int>array, string arg2) {
    int query = atoi(arg2.c_str());
    int result = binarysearch(array, query);
    if (result <= 0) {
        cout << "Query not found in array\n" << endl;
    } else {
        cout << "Query found in array at index " << result << "\n" <<endl;
    }
}

int main() {
    vector<int> array;
    int p[] = {89, 113, 295, 98, 93, 55, 122, 25, 87, 209, 
    275, 266, 128, 276, 281, 157, 227, 212, 267, 7, 
    240, 223, 31, 236, 294, 190, 72, 279, 212, 98, 
    198, 206, 195, 267, 105, 58, 256, 74, 89, 169, 159, 
    30, 110, 269, 221, 224, 80, 118, 197, 156, 65, 
    183, 82, 107, 164, 179, 280, 282, 213, 223, 265, 
    101, 269, 65, 168, 130, 88, 203, 10, 146, 62, 
    250, 11, 64, 11, 25, 217, 53, 145, 300, 59, 
    89, 48, 4, 275, 163, 234, 239, 297, 101, 180, 
    190, 92, 91, 138, 70, 126, 165, 299, 20, 65};
    size_t size = sizeof(p)/sizeof(int);
    sort(p, p + size);    
    for (int i = 0; i < sizeof(p)/sizeof(int); ++i) {
        array.push_back(p[i]);
    }
    string userinput;
    while(true) {
        cout << "enter search query" << endl;
        cin >> userinput;
        arrayhandler(array, userinput);
    }
}