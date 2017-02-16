#include <iostream>
#include "elapsed_time.h"
#include <math.h>
using namespace std;

int main() {
    int n = 1000;
    int x;
    start_timer();
    for ( int i = 0; i < n; ++i ) {
      for ( int j = i; j < n; ++j ) {
        x = 38 + 29*(348*tan(.328));
      }
    }
    double cycles = elapsed_time();  // also from elapsed_time.h
    cout << cycles << endl;
}