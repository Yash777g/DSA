#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int waysToSplitArray(vector<int>& nums) {
    int sum = 0, count = 0;
    for (int num : nums) {
        sum += num;
    }

    int currSum = 0;
    for(int i = 0; i < nums.size() - 1; i++) {
        currSum += nums[i];
        if(currSum >= sum - currSum) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<int> nums = {10,4,-8,7};
    cout << waysToSplitArray(nums) << endl;
    return 0;
}