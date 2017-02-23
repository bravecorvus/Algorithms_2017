#include "elapsed_time.h"
#include <math.h>
#include <iostream>
using namespace std;

void recursion(int n) {
    for(int i =0; i<100; ++i) {
        int x = sin(0.8+0.234);
    }
    if (n > 0) {
        recursion(n/2);
        recursion(n/2);
    }
}

int main() {
    int userinput;
    while (true) {
        cin >> userinput;
        start_timer();
        recursion(userinput);
        double cycle = elapsed_time();
        cout << cycle << endl;
    }
}