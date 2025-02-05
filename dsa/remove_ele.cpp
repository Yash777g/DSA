#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int count = 0, index = 0;
    int len = nums.size();

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[index] = nums[i];
            index++;
        }
    }

    return index;
}

int main() {
    vector<int> nums {0,1,2,2,3,0,4,2};
    int val = 2;

    int sol = removeElement(nums, val);
    cout << sol;
    return 0;
}