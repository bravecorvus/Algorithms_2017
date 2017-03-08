#include <iostream>
using namespace std;
#include "StackPlus.h"
#include "elapsed_time.h"

int main() {
        // #19 999 999999
    int fi[1];fi[0] = 7;
    StackPlus test19(fi, 1, 1);
    cout << "For 19 elements, it takes ";
    start_timer();
    for(int i = 0; i < 19; ++i) {
        test19.pushStackPlus(7);
    }
    float x = elapsed_time();
    cout << x << " cycles\n";

    StackPlus test99(fi, 1, 1);
    cout << "For 99 elements, it takes ";
    start_timer();
    for(int i = 0; i < 99; ++i) {
        test99.pushStackPlus(7);
    }
    float y = elapsed_time();
    cout << y << " cycles\n";

    StackPlus test999(fi, 1, 1);
    cout << "For 999 elements, it takes ";
    start_timer();
    for(int i = 0; i < 999; ++i) {
        test999.pushStackPlus(7);
    }
    float z = elapsed_time();
    cout << z << " cycles\n";

    StackPlus test999999999(fi, 1, 1);
    cout << "For 999999999 elements, it takes ";
    start_timer();
    for(int i = 0; i < 999999999; ++i) {
        test999999999.pushStackPlus(7);
    }
    float p = elapsed_time();
    cout << p << " cycles\n";
    // int inputarray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // StackPlus test(inputarray, 20);
    // test.printStackPlus();
    // cout << "We will now try to pop an element off the stack. Before popping, the top of the stack element is " << test.getTop() << " and the top of stack index is " << test.getTOSIndex() << "\n\n" << endl;
    // int poppedlement = test.popStackPlus();
    // cout << "Popping the test stack gives us " << poppedlement << ". and the new top of the stack index is " << test.getTOSIndex() << "\n\n" << endl;
    // cout << "Now the stack looks like\n";
    // test.printStackPlus();
    // cout << "Now we will try to fill up the stack just to see if we can fill the stack right on the 20 variable limit\n\n" << endl;
    // for (int i = 10; i < 21; ++i)
    // {
    //     test.pushStackPlus(i);
    // }
    // test.printStackPlus();
    // cout << "Now we should be hitting the limit, so let's try to push one more element.\n\n" << endl;
    // test.pushStackPlus(21);
    // cout << "Now the stack looks like\n";
    // test.printStackPlus();   
    // cout << "Max stack index is now " << test.getMaxStackPlusIndex() << " and the TOS index is " << test.getTOSIndex() << endl;
}