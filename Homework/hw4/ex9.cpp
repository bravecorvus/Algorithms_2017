#include "elapsed_time.h"
#include <math.h>
#include <iostream>
using namespace std;

int main() {
    int n = 100;
    int x;

    start_timer();
    int t1 = 0;
    // int t2 = 0;

for ( int i = 0; i < n; ++i ) {
  for ( int j = 0; j < i/2; ++j ) {
    for ( int k = 0; k < j; ++k ) {
      x = x + 5;
      t1+=1;
    }
  }
}
    cout << t1 << endl;
    // cout << t2 << endl;
    // double cycles = elapsed_time();  // also from elapsed_time.h
    // cout << cycles << endl;
}