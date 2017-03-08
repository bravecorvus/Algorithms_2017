#ifndef _LinkedListStack_
#define _LinkedListStack_
// 1. Implement a stack data structure as a C++ class. Here is a concise definition for a stack. 
// Please use a simple array as the basis for your data structure. Your stack should have a constructor whose
// argument gives the maximum number of elements to be stored in the stack (thus allowing you to allocate an appropriate fixed-size array),
// as well as push and pop methods. Please submit the C++ code via git.

#include <iostream>
using namespace std;

struct node {
    int cell;
    node *tail;
};

class LinkedListStack {
    node *head;
    int stacklen;
    public:
        LinkedListStack(int inputarray[], int listlen);
        LinkedListStack();
        ~LinkedListStack();
        int getTop();
        int getTOSElement();
        void printLinkedListStack();
        int getStackLength();
        int pop();
        void push(int);
};



#endif _LinkedListStack_