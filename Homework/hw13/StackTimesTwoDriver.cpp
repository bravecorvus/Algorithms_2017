#include <iostream>
using namespace std;
#include "StackTimesTwo.h"

int main() {
    int inputarray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    StackTimesTwo test(inputarray, 20);
    test.printStackTimesTwo();
    cout << "We will now try to pop an element off the stack. Before popping, the top of the stack element is " << test.getTop() << " and the top of stack index is " << test.getTOSIndex() << "\n\n" << endl;
    int poppedlement = test.popStackTimesTwo();
    cout << "Popping the test stack gives us " << poppedlement << ". and the new top of the stack index is " << test.getTOSIndex() << "\n\n" << endl;
    cout << "Now the stack looks like\n";
    test.printStackTimesTwo();
    cout << "Now we will try to fill up the stack just to see if we can fill the stack right on the 20 variable limit\n\n" << endl;
    for (int i = 10; i < 21; ++i)
    {
        test.pushStackTimesTwo(i);
    }
    test.printStackTimesTwo();
    cout << "Now we should be hitting the limit, so let's try to push one more element.\n\n" << endl;
    test.pushStackTimesTwo(21);
    cout << "Now the stack looks like\n";
    test.printStackTimesTwo();   
    cout << "Max stack index is now " << test.getMaxStackTimesTwoIndex() << " and the TOS index is " << test.getTOSIndex() << endl;
}