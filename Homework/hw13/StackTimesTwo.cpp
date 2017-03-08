#include <iostream>
using namespace std;
#include "StackTimesTwo.h"

int StackTimesTwo::popStackTimesTwo() {
    if (topofstack == 0) {
        cout << "StackTimesTwo is empty\n\n" << endl;
        return(-1);
    } else {
        --topofstack;
        return(array[topofstack+1]);
    }
}
void StackTimesTwo::setTOSIndex(int arg) {
    topofstack = arg;
}
void StackTimesTwo::pushStackTimesTwo(int arg) {
    ++topofstack;
    if (topofstack > maxstacksize) {//Most efficient Way, Look at alternate implementation below this if and above the else to find the accurate behavior implementation
        temparray = new int[(maxstacksize+1)*2];
        for (int i = 0; i <= maxstacksize; ++i) {
            temparray[i] = array[i];
        }
        delete [] array;
        array = temparray;
        maxstacksize = (maxstacksize+1)*2-1;
        array[topofstack] = arg;
    } else {
        array[topofstack] = arg;
    }
}