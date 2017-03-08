#include <iostream>
using namespace std;
#include "StackPlus100.h"

int StackPlus100::popStackPlus100() {
    if (topofstack == 0) {
        cout << "StackPlus100 is empty\n\n" << endl;
        return(-1);
    } else {
        --topofstack;
        return(array[topofstack+1]);
    }
}
void StackPlus100::setTOSIndex(int arg) {
    topofstack = arg;
}
void StackPlus100::pushStackPlus100(int arg) {
    ++topofstack;
    if (topofstack > maxstacksize) {//Most efficient Way, Look at alternate implementation below this if and above the else to find the accurate behavior implementation
        temparray = new int[maxstacksize+101];
        for (int i = 0; i <= maxstacksize; ++i) {
            temparray[i] = array[i];
        }
        delete [] array;
        array = temparray;
        maxstacksize += 100;
        array[topofstack] = arg;
    } else {
        array[topofstack] = arg;
    }
}