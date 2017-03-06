#include <iostream>
using namespace std;
#include "Stack.h"

int Stack::popStack() {
    if (topofstack == 0) {
        cout << "Stack is empty\n\n" << endl;
    } else {
        --topofstack;
        return(array[topofstack+1]);
    }
}

void Stack::pushStack(int arg) {
    if (topofstack > maxstacksize) {
        cout << "Stack has already reached the maximum capacity\n\n";
    } else {
        ++topofstack;
        array[topofstack] = arg;
    }
}