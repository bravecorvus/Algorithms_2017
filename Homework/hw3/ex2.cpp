#include <iostream>
#include "elapsed_time.h"
using namespace std;

int main() {
    start_timer();
    int n = 100;
    int x;
    for ( int i = 0; i > n; ++i ) {
        x = 2+3;
    }
    double cycles = elapsed_time();  // also from elapsed_time.h
    cout << cycles << endl;
}