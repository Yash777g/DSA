#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestSubarray(vector<int>& nums) {
    int maxVal = 0, ans = 0, currentStreak = 0;

    for (int num : nums) {
        if (maxVal < num) {
            maxVal = num;
            ans = currentStreak = 0;
        }

        if (maxVal == num) { currentStreak++; } 
        else { currentStreak = 0; }

        ans = max(ans, currentStreak);
    }
    
    return ans;
}

int main() {
    vector<int> nums = {378034,378034,378034};

    int ans = longestSubarray(nums);
    cout << ans;
    return 0;
}