#include <iostream>
using namespace std;

int minBitFlips(int start, int goal) {
    int xorRes = start ^ goal;
    int count  =  0;

    while(xorRes) {
        count += xorRes & 1;
        xorRes >>= 1;  
    }

    return count;
}

int main() {
    int start = 7, goal = 10;

    int sol = minBitFlips(start, goal);
    cout << sol;
    return 0 ;
}