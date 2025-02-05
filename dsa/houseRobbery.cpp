#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(vector<int>& nums, int n) {
    int include = 0, exclude = 0, ans = 0;
    int prev2 = 0, prev1 = nums[0];

    for(int i = 1; i < n; i++) {
        include = nums[i] + prev2;
        exclude = prev1 + 0;

        ans = max(include,exclude);
        prev2 = prev1;
        prev1 = ans;
    }
    return ans;
}

int rob(vector<int> &nums) {
    int n = nums.size()-1;
    if(n == 0) 
        return 0;
    if(n == 1)
        return nums[0]; 
    
    int result = solve(nums,n);
    return result;
}

int main() {
    vector<int> nums {2,7,9,3,1};
    int ans = rob(nums);
    cout << ans;
    return 0;
}