#include <iostream>
#include <vector>
using namespace std;

int longestNiceSubarray(vector<int>& nums) {
    int left = 0, right = 0;
    int sum = 0, xorSum = 0, ans = 0;

    while(right < nums.size()) {
        sum += nums[right];
        xorSum ^= nums[right++];

        while(sum != xorSum) {
            sum -= nums[left];
            xorSum ^= nums[left++];
        }

        ans = max(ans, right - left + 1);
    }

    return ans;
}

int main() {
    vector<int> nums = {1,3,8,48,10};
    cout << longestNiceSubarray(nums); 
    return 0;
}