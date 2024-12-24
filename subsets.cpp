#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>& nums, vector<vector<int>>& output, vector<int>& current, int index) {
    
    output.push_back(current);

    for (int i = index; i < nums.size(); i++) {
        // Include ki call
        current.push_back(nums[i]);
        
        // Recursive function
        solve(nums, output, current, i + 1);
        
        // Exclude ki call
        current.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> output;
    vector<int> current;

    int index = 0;
    solve(nums, output, current, index);
    
    return output;
}


int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> answer = subsets(nums);

    for(int i = 0 ;i < answer.size() ;i++) {
        for(int j = 0 ;j < answer[0].size() ;j++) {
            cout << answer[i][j];
        }
    }
    return 0;
}