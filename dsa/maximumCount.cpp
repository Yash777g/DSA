#include <iostream>
#include <vector>
using namespace std;

int maximumCount(vector<int>& nums) {
    int last = nums.size()-1;
    if(nums[0] > 0 || nums[last] < 0) {
        return nums.size();
    }

    int pos = 0, neg = 0;
    for(auto i : nums) {
        if(i > 0) {
            pos++;
        } else if(i < 0){
            neg++;
        }
    } return max(neg, pos);
}

int main() {
    vector<int> nums = {-4,-3,-2,-1,0,1,2,3};
    return 0;
}