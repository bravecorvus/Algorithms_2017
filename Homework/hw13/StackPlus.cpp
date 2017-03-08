#include <iostream>
using namespace std;
#include "StackPlus.h"

int StackPlus::popStackPlus() {
    if (topofstack == 0) {
        cout << "StackPlus is empty\n\n" << endl;
        return(-1);
    } else {
        --topofstack;
        return(array[topofstack+1]);
    }
}
void StackPlus::setTOSIndex(int arg) {
    topofstack = arg;
}
void StackPlus::pushStackPlus(int arg) {
    // ++topofstack;
    if (topofstack == maxstacksize) {
        int *temparray = new int[maxstacksize+101];
        for (int i = 0; i <= maxstacksize; ++i) {
            temparray[i] = array[i];
        }
        delete [] array;
        array = temparray;
        temparray = NULL;
        maxstacksize += 100;
        array[topofstack] = arg;
        ++topofstack;
    } else {
        array[topofstack] = arg;
        ++topofstack;
    }
}