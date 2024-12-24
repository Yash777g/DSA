#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

void solve(vector<vector<int>>& result, vector<int>& nums, int index) {
    if (index >= nums.size()) {
        result.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]); 
        solve(result, nums, index + 1);
        swap(nums[index], nums[i]); 
    }
}


vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    int index = 0;
    
    solve(result, nums, index);
    return result;
}

int main() {
    vector<int> nums {1,2,3};
    vector<vector<int>> answer = permute(nums);
    
    for(int i = 0; i < answer.size(); i++) { 
        for(int j = 0; j < answer[0].size(); j++) 
            cout << answer[i][j] << " ";
        cout << endl;
    }
    return 0;
}