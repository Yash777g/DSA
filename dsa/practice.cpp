#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res;
    int prefix = 1;

    for(int i = 0; i < nums.size(); i++) {
        res.push_back(prefix);
        prefix = prefix*nums[i];
    }

    int postfix = 1;
    for(int i = nums.size() - 1;  i >= 0; i--) {
        res[i] = res[i]*postfix;
        postfix = postfix*nums[i];
    }

    return res;
}

int main() {
    vector<int> nums = {1,2,3,4};
    vector<int> ans = productExceptSelf(nums);
    for(auto &i: ans) {
        cout << i <<  " "; 
    }
    return 0;
}

