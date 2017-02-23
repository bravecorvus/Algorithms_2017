#include <random>
#include <algorithm>
#include "elapsed_time.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

void sort ( vector<int> &vec ) {
    start_timer();
    int pop = 0;
    int pos = 0;

    for ( vector<int>::iterator it = vec.begin(); it != vec.end(); ++it ) {
        if ( *it > pop ) {
            pop = *it;
            pos = distance( vec.begin(), it );
        }
    }

    vec.erase( vec.begin() + pos );
    double cycles = elapsed_time();  // also from elapsed_time.h
    cout << "Cycle time for this iteration is " << cycles << "\n" << endl;
    if ( !vec.empty() ) {
        sort( vec );
    }

    return vec.push_back( pop );
}

int main () {
    int min = 0;
    int max = 1000;
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased
    int vectorlength = uni(rng);
    cout << "randomly generated length of vector is " << vectorlength << endl;
    vector<int> vec;
    for (int i = 0; i < vectorlength; ++ i) {
        int min = 0;
        int max = 1000;
        std::random_device rd;     // only used once to initialise (seed) engine
        std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
        std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased
        int randomnumber = uni(rng);
        vec.push_back(randomnumber);
    }
    sort( vec );

    for ( vector<int>::iterator it = vec.begin(); it != vec.end(); ++it ) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}