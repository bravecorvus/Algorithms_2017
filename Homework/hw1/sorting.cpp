#include <chrono>
#include <typeinfo>
#include <iostream>
using namespace std;
using namespace chrono;

int main() {
    int initiallist[4] = {0, 1, 2, 3};
    unsigned long starttime = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    int finallist[sizeof(initiallist)/sizeof(int)];
    for (int i = 0; i < sizeof(initiallist)/sizeof(int); ++i) {
        if (i == 0) {
            finallist[0] = initiallist[0];
        } else {
            if (finallist[0] < initiallist[i]) {
                finallist[0] = initiallist[i];
            }
        }
    }
    int lastlargest = finallist[0];
    int currentlargest;
    for (int x = 1; x < sizeof(initiallist)/sizeof(int); ++x) {
        for (int i = 0; i < sizeof(initiallist)/sizeof(int); ++i) {
            if (i == 0 && initiallist[0] < lastlargest) {
                currentlargest = initiallist[0];
            } else {
                if (currentlargest < initiallist[i] && initiallist[i] < lastlargest) {
                    currentlargest = initiallist[i];
                }
            }
        }
        finallist[x] = currentlargest;
        lastlargest = currentlargest;
    }
    unsigned long endtime = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    for (int i = 0; i < sizeof(finallist)/sizeof(int); ++ i) {
        cout << finallist[i] << endl;
    }
    cout << "Algorithm took " << endtime-starttime << " nanoseconds to complete" << endl;
}