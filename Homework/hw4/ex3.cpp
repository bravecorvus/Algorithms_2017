#include "elapsed_time.h"
#include <math.h>
#include <iostream>
using namespace std;

int main() {
    int n = 100;
    int x;
    start_timer();
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < i; ++j ) {
            x = 32*sin(.32);
        }
    }
    double cycles = elapsed_time();  // also from elapsed_time.h
    cout << cycles << endl;
}