#include <iostream>
using namespace std;
#include "LinkedListStack.h"
#include "elapsed_time.h"

int main() {
    // #19 999 999999
    LinkedListStack test19;
    cout << "For 19 elements, it takes ";
    start_timer();
    for(int i = 0; i < 19; ++i) {
        test19.push(7);
    }
    float x = elapsed_time();
    cout << x << " cycles\n";
    int h;
    for(int i = 0; i < 19; ++i) {
        h = test19.pop();
    }

    LinkedListStack test99;
    cout << "For 99 elements, it takes ";
    start_timer();
    for(int i = 0; i < 99; ++i) {
        test99.push(7);
    }
    float y = elapsed_time();
    cout << y << " cycles\n";
    int r;
    for(int i = 0; i < 99; ++i) {
        r = test99.pop();
    }
    LinkedListStack test999;
    cout << "For 999 elements, it takes ";
    start_timer();
    for(int i = 0; i < 999; ++i) {
        test999.push(7);
    }
    float z = elapsed_time();
    cout << z << " cycles\n";
    int d;
    for(int i = 0; i < 999; ++i) {
        d = test999.pop();
    }
    LinkedListStack test99999999;
    cout << "For 99999999 elements, it takes ";
    start_timer();
    for(int i = 0; i < 99999999; ++i) {
        test99999999.push(7);
    }
    float p = elapsed_time();
    cout << p << " cycles\n";


    // int inputarray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // LinkedListStack test(inputarray, sizeof(inputarray)/sizeof(int));
    // cout << "YOLO" << endl;
    // cout << test.getTOSElement() << endl;
    // cout << test.getStackLength() << endl;
    // test.printLinkedListStack();
    // cout << "We will now try to pop an element off the stack. Before popping, the top of the stack element is " << test.getTOSElement() << " and the stack looks like this (top of stack in the beginning, bottom of stack at the end)" << endl;
    // test.printLinkedListStack();
    // cout << "\n\n";
    // int poppedlement = test.pop();
    // cout << "Popping the test stack gives us " << poppedlement << " and the current top of the stack element is " << test.getTOSElement() << endl;
    // cout << "The Stack looks like this with the top of stack in the beginning and bottom of stack towards the end" << endl;
    // test.printLinkedListStack();
    // cout << "Now let's try pushing back that same value. " << endl;
    // test.push(poppedlement);
    // cout << "Now the linked list should be back as it was before" << endl;
    // test.printLinkedListStack();
}