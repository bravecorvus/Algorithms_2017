#include <iostream>
#include <math.h>
#include "elapsed_time.h"
using namespace std;

int main() {
    int n = 100;
    start_timer();
for ( int i = 0; i < n; ++i ) {
  for ( int j = 0; j < i; ++j ) {
    for ( int k = 0; k < j; ++k ) {
      k = k*2;
    }
  }
}
    double cycles = elapsed_time();  // also from elapsed_time.h
    cout << cycles << endl;
}