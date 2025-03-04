#include <iostream>
#include <vector>
using namespace std;

vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector<int> ans;

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] < pivot) {
            ans.push_back(nums[i]);
        }
    }

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == pivot) {
            ans.push_back(nums[i]);
        }
    }

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] > pivot) {
            ans.push_back(nums[i]);
        }
    }
    return ans;   
}

int main() {
    vector<int> nums = {9,12,5,10,14,3,10};
    vector<int> res = pivotArray(nums, 10);

    for(auto i : res) {
        cout << i << " ";
    }
    return 0;
}