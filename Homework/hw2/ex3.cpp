#include <iostream>
#include "elapsed_time.h"

using namespace std;

int main() {
    int i, x;

    for (i=0; i<500; i++) {
        start_timer(); // this function is from elapsed_time.h
        x = i;
        double cycles = elapsed_time();  // also from elapsed_time.h
        cout << "total cycles at for loop " << i << " " << cycles << endl;
    }
     start_timer();
    cout << i << endl;
    double cycles = elapsed_time();  // also from elapsed_time.h
    cout << "total cycles after print " << cycles << endl;
    
}