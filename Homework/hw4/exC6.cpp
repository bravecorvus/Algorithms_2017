#include "elapsed_time.h"
#include <math.h>
#include <iostream>
using namespace std;

void recursion(int n)
{
  double x = 2 * 3;
  int t = 0;
  for ( int i = 0; i < n; ++i ) {
    for ( int j = 0; j < n/2; ++j ) {
      for ( int k = 0; k < n; ++k ) {
        t += 1;
        x = 5*x - 4;
      }
    }
  }
 cout << t << endl;
  if (n > 0)
    recursion(n/3);
}

int main() {
    int n = 100;
    start_timer();
    recursion(n);
    double cycles = elapsed_time();  // also from elapsed_time.h
    cout << cycles << endl;
}