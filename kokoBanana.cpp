#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <limits>
using namespace std;

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int maxPile = 0;
    for (int pile : piles) {
        maxPile = max(maxPile, pile);
    }

    int min = 1, max = maxPile;
    while (min < max) {
        int mid = (min + max) / 2, hours = 0;
        for (int pile : piles) {
            hours += ceil((double)pile / mid); 
        }

        if (hours <= h) max = mid; 
        else min = mid + 1; 
    } return min;
}

int main() {
    vector<int> piles = {3,6,7,11};
    cout << minEatingSpeed(piles, 8);
    return 0;
}