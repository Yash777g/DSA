#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int totalSum = 0;
    vector<int> prefixSum (nums.size()+1, 0);
    for(int i = 0; i < nums.size(); i++) {
        totalSum += nums[i];
        prefixSum[i+1] = totalSum;
    }

    for(int i = 0; i < nums.size(); i++) {
        int left = prefixSum[i];
        int right = totalSum - prefixSum[i] - nums[i];
        if(left == right) {
            return i;
        }     
    }
    return -1;
}

int main() {
    vector<int> nums = {1,7,3,6,5,6};
    cout << pivotIndex(nums);
    return 0;
}