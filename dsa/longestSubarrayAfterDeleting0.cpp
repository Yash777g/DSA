#include <iostream>
#include <vector>
using namespace std;

// dp solution
/*int longestSubarray(vector<int>& nums) {
    vector<int> left(nums.size(), 0), right(nums.size(), 0);

    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] == 1) {
            left[i] = left[i-1] + 1;
        }
    }

    for(int i = nums.size()-2; i >= 0; i++) {
        if(nums[i+1] == 1) {
            right[i] = right[i+1] + 1;
        }
    }

    int res = 0;
    for(int i = 0; i < nums.size(); i++) {
        res = max(res, left[i] + right[i] + 1);
    }

    return res;
}*/

// sliding window solution
int longestSubarray(vector<int>& nums) {
    int count = 0;

    
    return count;
}

int main() {
    vector<int> nums = {0,1,1,1,0,1,1,0,1};
    cout << longestSubarray(nums);
    return 0;
}