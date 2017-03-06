#ifndef _Stack_
#define _Stack_
// 1. Implement a stack data structure as a C++ class. Here is a concise definition for a stack. 
// Please use a simple array as the basis for your data structure. Your stack should have a constructor whose
// argument gives the maximum number of elements to be stored in the stack (thus allowing you to allocate an appropriate fixed-size array),
// as well as push and pop methods. Please submit the C++ code via git.

#include <iostream>
using namespace std;

class Stack {
    int *array;
    int topofstack;
    int maxstacksize;
    public:
        Stack(int inputarray[], int size) {
            array = new int[size];
            int counter = 0;
            for (int i = 0; inputarray[i] != NULL; ++i) {
                ++counter;
                array[i] = inputarray[i];
            }
            topofstack = counter-1;
            maxstacksize = size-1;
        }
        Stack(int size) {
            array = new int[size];
            topofstack = 0;
            maxstacksize = size-1;
        }
        ~Stack() {
            delete [] array;
        }
        int getTop() {
            return(array[topofstack]);
        }
        int getTOSIndex() {
            return(topofstack);
        }
        int getMaxStackIndex() {
            return(maxstacksize);
        }
        void printStack() {
            cout << "[";
            for(int i = 0; i < topofstack; ++i) {
                cout << array[i] << ", ";
            }
            cout << array[topofstack] << "]\n\n" << endl;
        }
        int popStack();
        void pushStack(int);
};



#endif _Stack_