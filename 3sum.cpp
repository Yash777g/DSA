#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int target = 0;
    sort(nums.begin(), nums.end());
    set<vector<int>> sets;
    vector<vector<int>> output;

    for (int i = 0; i < nums.size(); i++) {
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == target) {
                sets.insert({nums[i], nums[j], nums[k]});
                j++;
                k--;
            } 

            else if (sum < target) { j++; } 
            else { k--; }
        }
    }

        for(auto triplets : sets) { output.push_back(triplets); }
        return output;
}

int main() {
    vector<int> nums {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = threeSum(nums);

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}