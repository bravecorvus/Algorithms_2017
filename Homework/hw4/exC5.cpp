#include "elapsed_time.h"
#include <math.h>
#include <iostream>
using namespace std;

void recursion(int n)
{
  double x = 2 * 3;
  int t = 0;
  for ( int i = 0; i < n; ++i ) {
    for ( int j = 0; j < i; ++j ) {
      x = 32*sin(.32);
      t += 1;
    }
  }
 cout << t << endl;
  if (n > 0)
    recursion(n/2);
}

int main() {
    int n = 100;
    start_timer();
    recursion(n);
    double cycles = elapsed_time();  // also from elapsed_time.h
    cout << cycles << endl;
}