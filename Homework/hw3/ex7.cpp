#include <iostream>
#include <math.h>
#include "elapsed_time.h"
using namespace std;

int main() {
    int n = 100;
    start_timer();
int t = 0;
for ( int i = 0; i < n; ++i ) {
  for ( int j = 0; j < i/2; ++j ) {
    i = i + 1;
    // cout << i << endl;
    t += 1;
  }
  // cout << endl;
}
    cout << t << endl;
    double cycles = elapsed_time();  // also from elapsed_time.h
    // cout << cycles << endl;
}