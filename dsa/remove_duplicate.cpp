#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.empty()) { return 0; }

    int result = 0;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] != nums[result]) {
            nums[++result] = nums[i];
        }
    }

    return result+1;
}

int main() {
    vector<int> nums {1,1,2};

    int sol = removeDuplicates(nums);
    cout << sol;

    return 0;
}