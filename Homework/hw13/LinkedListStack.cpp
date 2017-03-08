#include <iostream>
using namespace std;
#include "LinkedListStack.h"

LinkedListStack::LinkedListStack(int inputarray[], int listlen) {
    head = new node;
    head->cell = inputarray[listlen-1];
    stacklen = 1;
    head->tail = new node;
    node *next = head->tail;
    for (int i = listlen-2; i >= 0; --i) {
        next->cell = inputarray[i];
        ++stacklen;
        next->tail = new node;
        next = next->tail;
    }
}
LinkedListStack::LinkedListStack() {
    head = new node;
    head->cell = NULL;
    stacklen = 0;
}
LinkedListStack::~LinkedListStack() {
    node *next = head->tail;
    delete head;
    --stacklen;
    while (stacklen > 0) {
        head = next;
        next = next->tail;
        delete head;
        --stacklen;
    }
}
int LinkedListStack::getTOSElement() {
    return(head->cell);
}
void LinkedListStack::printLinkedListStack() {
    node *next = head->tail;
    cout << "[" << head->cell << ", ";
    for(int i = 0; i <stacklen-1; ++i) {
        cout << next->cell << ", ";
        next = next->tail;
    }
    cout << "]\n\n" << endl;
}
int LinkedListStack::pop() {
    node *newhead = head->tail;
    int returnvar = head->cell;
    delete head;
    --stacklen;
    head = newhead;
    return(returnvar);
}
void LinkedListStack::push(int arg) {
    node *newhead = new node;
    newhead->cell = arg;
    newhead->tail = head;
    head = newhead;
    ++stacklen;
}

int LinkedListStack::getStackLength() {
    return(stacklen);
}