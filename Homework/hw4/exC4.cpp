#include "elapsed_time.h"
#include <math.h>
#include <iostream>
using namespace std;

void recursion(int n)
{
  double x = 2 * 3;
  for ( int i = 0; i < n; ++i ) {
    x = 2+3;
  }
  // cout << "n " << n << endl;
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