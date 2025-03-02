#include <iostream>
#include <vector>
using namespace std;

vector<int> applyOperations(vector<int>& nums) {
    for(int i = 0; i < nums.size()-1; i++) {
        if(nums[i] == nums[i+1]) {
            nums[i] *= 2;
            nums[i+1] = 0;
        }
    }

    int j = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            swap(nums[i], nums[j++]);
        }
    }
    return nums;
}

int main() {
    vector<int> nums = {1,2,2,1,1,0};
    
    vector<int> res = applyOperations(nums);
    for(auto i : res) {
        cout << i << " ";
    } 
    return 0;
}