#include "elapsed_time.h"
#include <math.h>
#include <iostream>
using namespace std;

void recursion(int n)
{
  double x = 2 * 3;
  x = x * 3;
 
  if (n > 0)
    recursion(n - 1);
}

int main() {
    int n = 100;
    start_timer();
    recursion(n);
    double cycles = elapsed_time();  // also from elapsed_time.h
    cout << cycles << endl;
}