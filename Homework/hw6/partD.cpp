#include <random>
#include <algorithm>
#include <vector>
#include <iostream>
#include "elapsed_time.h"
#include <math.h>
using namespace std;

void recurrence (int minimum, vector<int> &intvector, vector<int> &sortedvector, int &counter) {
    ++counter;
    if(intvector.size() > 0) {
        start_timer();
        sortedvector.push_back(intvector[minimum]);
        intvector.erase(intvector.begin()+minimum);
        int smallest = 0;
        for (vector<int>::iterator z=intvector.begin(); z !=intvector.end(); ++ z)
        {
            if (*z < intvector[smallest]) {
                smallest = distance(intvector.begin(), z);
            }
        }
        double cycles = elapsed_time();  // also from elapsed_time.h
        cout << "Cycle time for this iteration is " << cycles << "\n" << endl;
        recurrence(smallest, intvector, sortedvector, counter);
    }
}

int main() {
    int min = 0;
    int max = 1000;
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased
    int vectorlength = uni(rng);
    cout << "randomly generated length of vector is " << vectorlength << endl;
    int counter = 0;
    vector<int> intvector;
    for (int i = 0; i < vectorlength; ++ i) {
        int min = 0;
        int max = 1000;
        std::random_device rd;     // only used once to initialise (seed) engine
        std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
        std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased
        int randomnumber = uni(rng);
        intvector.push_back(randomnumber);
    }

    for (vector<int>::iterator z=intvector.begin()+1; z !=intvector.end(); ++ z)
        {
            cout << *z << " ";
        }

    cout << "\n\n\n\n" << endl;
    int smallest = 0;
    for (vector<int>::iterator z=intvector.begin()+1; z !=intvector.end(); ++ z)
    {
        if (*z < intvector[smallest]) {
            smallest = distance( intvector.begin(), z);
        }
    }
    std::vector<int> sortedvector;
    start_timer();
    recurrence(smallest, intvector, sortedvector, counter);   
    double cycles = elapsed_time();  // also from elapsed_time.h
    cout << "Total Cycle time is " << cycles << "\n" << endl;
    for (vector<int>::iterator z=sortedvector.begin()+1; z !=sortedvector.end(); ++ z)
    {
        cout << *z << " ";
    }

    cout << "recurrance ran " << counter << " times." << endl;
}