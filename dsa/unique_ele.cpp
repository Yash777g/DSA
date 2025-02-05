#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int i = 0; i < nums.size(); i++) 
        ans = ans ^ nums[i];
    
    return ans;
}

int main() {
    vector<int> nums {4,2,1,2,1};
    int ans = 0;

    ans = singleNumber(nums);
    cout << ans;
    return 0; 
}