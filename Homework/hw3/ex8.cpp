#include <iostream>
#include <math.h>
#include "elapsed_time.h"
using namespace std;

int main() {
    int n = 100;
    start_timer();
int t = 0;

for ( int i = 0; i < n; ++i ) {
    cout << "i" << endl;
  for ( int j = 0; j < i/2; j+=2 ) {
    i = i + 2;
    // t += 1;
    cout << "j " << i << endl;
    // if (i > 9000) {
    //     break;
    //     break;
    // }
  }
  cout << endl;
}
  // cout << endl;
// }
    // cout << t << endl;
    double cycles = elapsed_time();  // also from elapsed_time.h
    // cout << cycles << endl;
}