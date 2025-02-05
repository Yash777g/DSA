#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    set<vector<int>> set;
    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size() - 3; i++) {
        for(int j = i+1; j < nums.size() - 2; j++) {
            int left = j + 1, right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[j] + nums[left] + nums[right]; 
                if (sum == target) {
                    set.insert({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;
                } 

                else if (sum < target) { left++; } 
                else { right--; }
            }
        }
    } 
    
    for(auto quadruple : set) { result.push_back(quadruple); }
    return result;
}

int main() {
    vector<int> nums = {1,0,-1,0,-2,2};
    vector<vector<int>> ans = fourSum(nums, 0);

    for(auto &i: ans) {
        for(auto &j : i){
            cout << j << " ";
        } cout << endl;
    }    
    return 0;
}