#include <iostream>
#include "elapsed_time.h"
#include <math.h>
using namespace std;

int main() {
    int n = 1000;
    int x;
    // int t1 = 0;
    // int t2 = 0;
    start_timer();
    for ( int i = 0; i < n; ++i ) {
      for ( int j = 0; j < i/2; ++j ) {
        x = 2398 * 2948 + 3498 * 3948 + 39843 * atan2(32,49);
        // t1 += 1;
      }
      i = i + 2;
      // t2 += 2;
    }
    double cycles = elapsed_time();  // also from elapsed_time.h
    cout << cycles << endl;
    // cout << t << endl;
}