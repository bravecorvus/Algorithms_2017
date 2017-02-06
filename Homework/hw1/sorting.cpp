#include <iostream>
#include <array>
using namespace std;

int main() {
    std::array<int, 4> a1{{0, 1, 2, 3}};
    int i = 0;
    for (i = 0; i < sizeof(a1)/sizeof(int); ++i){} //emtpy loop to save length of loop into i
    cout << i
}