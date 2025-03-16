#include <iostream>
#include <vector>
using namespace std;

bool possible(int mid, vector<int>& candies, long long k) {
    int ans = 0;
    for(int i = 0; i < candies.size(); i++) {
        int val = candies[i]/mid;
        ans += val;
    }
    return ans >= k;
}

int maximumCandies(vector<int>& candies, long long k) {
    int maxCandies = 0, max = -1;
    long long sum = 0;

    for(auto i : candies) {
        sum += i;
        if(i > max) max = i;
    }

    if(k == 1) return max;

    long long left = 1, right = max;
    while(left <= right) {
        int mid = left + (right - left) / 2;

        if(possible(mid, candies, k)) {
            left = mid + 1;
            maxCandies = mid;
        } else {
            right = mid - 1;
        }
    }
    return maxCandies;
}

int main() {
    vector<int> candies = {5,8,6};
    long long k = 3;
    cout << maximumCandies(candies, k);
    return 0;
}