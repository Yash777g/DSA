#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> ans(2);
    unordered_map<int, int> freq;

    for (int num : nums1) {
        if (freq.find(num) == freq.end()) {
            freq[num] = 1; 
        }
    }

    for (int num : nums2) {
        if (freq.find(num) == freq.end()) {
            freq[num] = -1;  
        } else if (freq[num] == 1) {
            freq[num] = 0;  
        }
    }

    for(auto &i : freq) {
        if(i.second == 1) {
            ans[0].push_back(i.first);
        } 
        if(i.second == -1) {
            ans[1].push_back(i.first);
        }
    }

    return ans;
}


int main() {
    vector<int> nums1 = {1,2,3,3}, nums2 = {1,1,2,2};
    vector<vector<int>> result = findDifference(nums1, nums2);
    for(auto &i: result) {
        for(auto &j : i) {
            cout << j << " ";
        }cout << endl;
    }
    return 0;
}