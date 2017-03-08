#ifndef _StackTimesTwo_
#define _StackTimesTwo_
// 1. Implement a stack data structure as a C++ class. Here is a concise definition for a stack. 
// Please use a simple array as the basis for your data structure. Your stack should have a constructor whose
// argument gives the maximum number of elements to be stored in the stack (thus allowing you to allocate an appropriate fixed-size array),
// as well as push and pop methods. Please submit the C++ code via git.

#include <iostream>
using namespace std;

class StackTimesTwo {
    int *array;
    int *temparray;
    int topofstack;
    int maxstacksize;
    public:
        StackTimesTwo(int inputarray[], int size) {
            array = new int[size];
            int counter = 0;
            for (int i = 0; inputarray[i] != NULL; ++i) {
                ++counter;
                array[i] = inputarray[i];
            }
            topofstack = counter-1;
            maxstacksize = size-1;
        }
        StackTimesTwo(int size) {
            array = new int[size];
            topofstack = 0;
            maxstacksize = size-1;
        }
        ~StackTimesTwo() {
            delete [] array;
        }
        int getTop() {
            return(array[topofstack]);
        }
        int getTOSIndex() {
            return(topofstack);
        }
        int getMaxStackTimesTwoIndex() {
            return(maxstacksize);
        }
        void printStackTimesTwo() {
            cout << "Starting at the top of the stack, and ending at the bottom of the stack\n[";
            for(int i = topofstack; i > 0; --i) {
                cout << array[i] << ", ";
            }
            cout << array[0] << "]\n\n" << endl;
        }
        void setTOSIndex(int);
        int popStackTimesTwo();
        void pushStackTimesTwo(int);
};



#endif _StackTimesTwo_