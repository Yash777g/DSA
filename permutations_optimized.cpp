#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int> nums, vector<vector<int>>& result, int index) {
    if(index == nums.size()-1) {
        result.push_back(nums);
        return;
    }

    for(int i = index; i < nums.size(); i++) {
        if(i != index && nums[index] == nums[i]) {
            continue;
        }
        swap(nums[index], nums[i]);
        solve(nums,result, index+1);
        //swap(nums[index],nums[i]);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> last;
    
    int index = 0;
    solve(nums, result, index);
    return result;
}

int main() {
    vector<int> nums {2,2,1,1};
    vector<vector<int>> answer = permuteUnique(nums);
    
    for(int i = 0; i < answer.size(); i++) {
        for(int j = 0; j < answer[0].size(); j++) {
            cout << answer[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}