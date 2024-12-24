#include<iostream>
#include<vector>

int missingNumber(std :: vector<int>& nums) {
    int sum = 0;
    sum = (nums.size() * (nums.size() + 1)) / 2;
    
    for(int i = 0; i < nums.size(); i++) 
        sum -= nums[i];
    
    return sum;
}

int main() {
    std :: vector<int> nums {0};
    int ans = 0;
    
    ans = missingNumber(nums);
    std :: cout << ans;
    return 0;
}