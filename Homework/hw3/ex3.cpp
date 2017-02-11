#include <iostream>
#include <math.h>
#include "elapsed_time.h"
using namespace std;

int main() {
    start_timer();
    int n = 100;
    int x;
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n/2; ++j ) {
            x = sin(.32);
        }
    }
    double cycles = elapsed_time();  // also from elapsed_time.h
    cout << cycles << endl;
}