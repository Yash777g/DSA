#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int strictlyincreasing(vector<int>& nums) {
    int len = 1, maxlen = 1;

    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] > nums[i-1]) {
            len++;
        } else {
            maxlen = max(len, maxlen);
            len = 1; 
        }
    }
    maxlen = max(len, maxlen);
    return maxlen;
}

int strictlydecreasing(vector<int>& nums) {
    int len = 1, maxlen = 1;

    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] < nums[i-1]) {
            len++;
        } else {
            maxlen = max(len, maxlen);
            len = 1; 
        }
    }
    maxlen = max(len, maxlen);
    return maxlen;
}

int longestMonotonicSubarray(vector<int>& nums) {
    int inclen = strictlyincreasing(nums);
    int declen = strictlydecreasing(nums);

    return max(inclen, declen);
}

int main() {
    vector<int> nums = {3,2,1};
    cout << longestMonotonicSubarray(nums);
    return 0;
}