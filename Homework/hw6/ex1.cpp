#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // random number generator 0-1000000
    // taken from http://stackoverflow.com/questions/5008804/generating-random-integer-from-a-range
    int min = 0;
    int max = 1000000;
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased
    int random_integer = uni(rng);
    vector<int> intvector;
    for (int i = 0; i < random_integer; ++i) {
        intvector.push_back(0);
    }
    for (vector<int>::iterator z=intvector.begin(); z !=intvector.end(); ++ z)
    {
        cout << *z;
    }
    cout << endl;
}