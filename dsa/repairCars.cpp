#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

long long repairCars(vector<int>& ranks, int cars) {
    long long left = 0, right = 1e14;
    
    while(left < right) {
        long long mid = left + (right - left)/2;
        long long repair = 0;

        for (auto i : ranks) repair += (long long)sqrt(mid / i);
        
        if(repair < cars) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    vector<int> ranks = {4,3,2,1};
    int cars = 10;
    cout << repairCars(ranks, cars);
    return 0;
}