#include <iostream>
#include "elapsed_time.h"
#include <math.h>
using namespace std;

int main() {
    int n = 1000;
    int x;
    // int t = 0;
    start_timer();
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < i; ++j ) {
            x = 32*sin(.32);
            // t += 1;
        }
    }
    double cycles = elapsed_time();  // also from elapsed_time.h
    cout << cycles << endl;
    // cout << t << endl;
}