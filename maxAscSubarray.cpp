#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxAscendingSum(vector<int>& nums) {
    int maxSum = nums[0], currSum = nums[0];

    for(int i = 1; i < nums.size(); i++) {
        if(nums[i-1] < nums[i]) {
            currSum +=  nums[i];
            cout << currSum << endl;
        } else {
            maxSum = max(maxSum, currSum);
            currSum = nums[i];
        }
    } maxSum = max(maxSum, currSum);
    return maxSum;
}   

int main() {
    vector<int> nums = {10,20,30,5,10,50};
    cout << maxAscendingSum(nums);
    return 0;
}