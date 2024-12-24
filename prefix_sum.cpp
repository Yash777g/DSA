#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal) {
    int result = 0, sum = 0, count = 0, l = 0;
    
    for (int  r = 0; r < nums.size(); r++) {
        sum += nums[r];
        if (nums[r] == 1) count = 0;
        
        while ((l <= r) && (sum >= goal)) {
            if (sum == goal) count++;
            sum -= nums[l++];
        }
        result += count;
    }
    
    return result;
}

int main() {
    vector<int> nums {1, 0, 1, 0, 1};
    int goal = 2;
    
    int answer = numSubarraysWithSum(nums, goal);
    cout << answer;
    return 0;
}