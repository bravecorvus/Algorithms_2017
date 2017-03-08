#include <iostream>
using namespace std;
#include "LinkedListStack.h"

int main() {
    int inputarray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    LinkedListStack test(inputarray, sizeof(inputarray)/sizeof(int));
    cout << "YOLO" << endl;
    cout << test.getTOSElement() << endl;
    cout << test.getStackLength() << endl;
    test.printLinkedListStack();
    cout << "We will now try to pop an element off the stack. Before popping, the top of the stack element is " << test.getTOSElement() << " and the stack looks like this (top of stack in the beginning, bottom of stack at the end)" << endl;
    test.printLinkedListStack();
    cout << "\n\n";
    int poppedlement = test.pop();
    cout << "Popping the test stack gives us " << poppedlement << " and the current top of the stack element is " << test.getTOSElement() << endl;
    cout << "The Stack looks like this with the top of stack in the beginning and bottom of stack towards the end" << endl;
    test.printLinkedListStack();
    cout << "Now let's try pushing back that same value. " << endl;
    test.push(poppedlement);
    cout << "Now the linked list should be back as it was before" << endl;
    test.printLinkedListStack();
}