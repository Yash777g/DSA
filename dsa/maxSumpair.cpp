#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int digitsum(int num) {
    int sum = 0;
    while(num > 0) {
        sum += num%10;
        num /= 10;
    } return sum;
}

/* using hashmap
int maximumSum(vector<int>& nums) {
    int maxSum = -1;
    unordered_map<int, vector<int>> mapping;

    for(int i = 0; i < nums.size(); i++) {
        int sum = digitsum(nums[i]);
        mapping[sum].push_back(nums[i]);
    }

    for(auto i: mapping) {
        vector<int> num = i.second;
        int sum = -1;

        if(num.size() < 2) {
            continue;
        } else {
            int size = num.size()-1;
            sort(num.begin(), num.end());
            sum = num[size] + num[size-1];
        }
        maxSum = max(maxSum, sum);
    } 
    return maxSum;
}*/

// without hashmap
int maximumSum(vector<int>& nums) {
    int sum = 0, maxSum = -1;
    vector<int> sameDigitsSum(82, -1);

    for(int i = 0; i < nums.size(); i++) {
        sum = digitsum(nums[i]);
        if(sameDigitsSum[sum] != -1) {
            maxSum = max(maxSum, sameDigitsSum[sum] + nums[i]);
            sameDigitsSum[sum] = max(sameDigitsSum[sum], nums[i]);
        } else {
            sameDigitsSum[sum] = nums[i];
        }
    } return maxSum;
} 

int main() {
    vector<int> nums = {18,43,36,13,7};
    cout << maximumSum(nums);   
    return 0;
}