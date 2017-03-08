#include <iostream>
using namespace std;
#include "StackPlus100.h"

int main() {
    int inputarray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    StackPlus100 test(inputarray, 20);
    test.printStackPlus100();
    cout << "We will now try to pop an element off the stack. Before popping, the top of the stack element is " << test.getTop() << " and the top of stack index is " << test.getTOSIndex() << "\n\n" << endl;
    int poppedlement = test.popStackPlus100();
    cout << "Popping the test stack gives us " << poppedlement << ". and the new top of the stack index is " << test.getTOSIndex() << "\n\n" << endl;
    cout << "Now the stack looks like\n";
    test.printStackPlus100();
    cout << "Now we will try to fill up the stack just to see if we can fill the stack right on the 20 variable limit\n\n" << endl;
    for (int i = 10; i < 21; ++i)
    {
        test.pushStackPlus100(i);
    }
    test.printStackPlus100();
    cout << "Now we should be hitting the limit, so let's try to push one more element.\n\n" << endl;
    test.pushStackPlus100(21);
    cout << "Now the stack looks like\n";
    test.printStackPlus100();   
    cout << "Max stack index is now " << test.getMaxStackPlus100Index() << " and the TOS index is " << test.getTOSIndex() << endl;
}