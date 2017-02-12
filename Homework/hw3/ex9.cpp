#include <iostream>
#include <math.h>
#include "elapsed_time.h"
using namespace std;

int main() {
    int n = 100;
    start_timer();
int t = 0;
int x;
for ( int i = 0; i < n; ++i ) {
    // cout << "i" << i << endl;
  for ( int j = 0; j < i; ++j ) {
    // cout << "j" << j << endl;
    for ( int k = 0; k < j; ++k ) {
        // cout << "k" << k << endl;
        t += 1;
      x = x + 5;
    }
  }
  // cout << endl;
}
    // cout << t << endl;
    double cycles = elapsed_time();  // also from elapsed_time.h
    cout << cycles << endl;
}