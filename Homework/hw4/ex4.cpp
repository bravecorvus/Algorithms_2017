#include <iostream>
#include "elapsed_time.h"
#include <math.h>
using namespace std;

int main() {
    int n = 100;
    int x;
    // int t = 0;
    start_timer();
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n/2; ++j ) {
            x = sin(.32);
        }
    }
    double cycles = elapsed_time();  // also from elapsed_time.h
    cout << cycles << endl;
}