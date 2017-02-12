#include <iostream>
#include <math.h>
#include "elapsed_time.h"
using namespace std;

int main() {
    int n = 100;
    int t = 0;
    // start_timer();
for ( int i = 0; i < n; ++i ) {
    // cout << "i" << endl;
  for ( int j = 0; j < i; ++j ) {
    // cout << "j" << endl;
    for ( int k = 0; k < j; ++k ) {
        // cout << "k" << endl;
      j += k;
      cout << "j " << j << endl; 
      cout << "k " << j << endl; 
    }
  }
  cout << endl;
}

    // double cycles = elapsed_time();  // also from elapsed_time.h
    // cout << cycles << endl;
}