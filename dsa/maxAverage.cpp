#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    double sum = 0;
    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }

    double maxSum = sum;
    for (int i = k; i < nums.size(); i++) {
        sum = sum - nums[i - k] + nums[i];
        maxSum = max(maxSum, sum);        
    } 
    return maxSum / k; 
}


int main() {
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    cout << findMaxAverage(nums, 4);
    return 0;
}