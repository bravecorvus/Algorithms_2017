#include <iostream>
#include "elapsed_time.h"

using namespace std;

int main() {
    start_timer();
    int i, x;
    double cycles = elapsed_time();  // also from elapsed_time.h
    cout << "total cycles after initializing i and x " << cycles << endl;

    for (i=0; i<500; i++) {
        start_timer(); // this function is from elapsed_time.h
        x = i;
        double cycles = elapsed_time();  // also from elapsed_time.h
        cout << "total cycles at for loop " << i << " " << cycles << endl;
    }
     start_timer();
    cout << i << endl;
    cycles = elapsed_time();  // also from elapsed_time.h
    cout << "total cycles after print " << cycles << endl;
    start_timer();
    return 0;   
    cycles = elapsed_time();  // also from elapsed_time.h
    cout << "total cycles after return 0;" << cycles << endl;
}