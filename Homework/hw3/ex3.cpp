#include <iostream>
#include <math.h>
#include "elapsed_time.h"
using namespace std;

int main() {
    int n = 100;
    int x;
    start_timer();
// int t = 0;
for ( int i = 0; i < n; ++i ) {
  for ( int j = 0; j < i/2; ++j ) {
    x = 2398 * 2948 + 3498 * 3948 + 39843 * atan2(32,49);
    // t += 1;
    // cout << "FUCK" << endl;
  }
  // cout << "\n" << endl;
  i = i + 2;
}
    double cycles = elapsed_time();  // also from elapsed_time.h
    cout << cycles << endl;
    // cout << t << endl;
}