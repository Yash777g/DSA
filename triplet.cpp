#include <iostream>
#include <vector>
using namespace std;

bool increasingTriplet(vector<int>& nums) {
    if (nums.size() < 3) return false;

    int first = INT32_MAX, second = INT32_MAX;

    for (int num : nums) {
        if (num <= first) {
            first = num;
        } else if (num <= second) {
            second = num;
        } else {
            return true;
        }
    }

    return false;
}


int main() {
    vector<int> nums = {0,4,2,1,0,-1,-3};
    cout << increasingTriplet(nums);
    return 0;
}