#include <iostream>
using namespace std;
#include "Stack.h"

int main() {
    int inputarray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Stack test(inputarray, 20);
    test.printStack();
    cout << "We will now try to pop an element off the stack. Before popping, the top of the stack element is " << test.getTop() << " and the top of stack index is " << test.getTOSIndex() << "\n\n" << endl;
    int poppedlement = test.popStack();
    cout << "Popping the test stack gives us " << poppedlement << ". and the new top of the stack index is " << test.getTOSIndex() << "\n\n" << endl;
    cout << "Now we will try to fill up the stack just to see if we can fill the stack past the 20 variable limit.\n\n" << endl;
    for (int i = 9; i < 21; ++i)
    {
        test.pushStack(i);
    }
    test.printStack();
    cout << "Now we should be hitting the limit, so let's try to push one more element.\n\n" << endl;
    test.pushStack(21);
}