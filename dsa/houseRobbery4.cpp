#include <iostream>
#include <vector>
using namespace std;

int minCapability(vector<int>& nums, int k) {
    int right = -1, left = INT32_MAX;
    int ans = 0;
    for(auto i : nums) {
         if(i > right) right = i;
         if(i < left) left = i; 
    }

    while(left <= right) {
        int mid = left + (right-left)/2;

        int cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= mid) {
                cnt++; i++;
            }
        }

        if(cnt >= k) {
            ans = mid;
            right = mid-1;
        } else {
            left = mid+1;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {2,3,5,9};
    int k = 2;
    cout << minCapability(nums, k);
    return 0;
}