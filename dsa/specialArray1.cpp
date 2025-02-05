#include <iostream>
#include <vector>
using namespace std;

bool isArraySpecial(vector<int>& nums) {
    if(nums.size() <= 1) return true;
    for(int i = 1;i < nums.size(); i++) {
        if((nums[i] - nums[i-1]) % 2 == 0) {
            return false;
        }
    } return true;
}

int main() {
    vector<int> nums = {1,5};
    cout << isArraySpecial(nums) << endl;
    cout << 5-1%2;
    return 0;
}