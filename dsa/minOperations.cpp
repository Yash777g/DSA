#include <iostream>
#include <vector>
using namespace std;

bool isOne(vector<int>& nums, int left, int right) {
    for(int i = left; i < right; i++) {
        if(nums[i] == 0) return false;
    } return true;
}

int minOperations(vector<int>& nums) {
    int cnt = 0;

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == 0) {
            if(i+2 >= nums.size()) { return -1;}
            else {
                nums[i] ^= 1; nums[i+1] ^= 1; nums[i+2] ^= 1;
                cnt++;
            } 
        }
    }
    return cnt;
}

int main() {
    vector<int> nums = {0,1,1,1,0,0};
    cout << minOperations(nums);
    return 0;
}