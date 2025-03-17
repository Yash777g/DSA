#include <iostream>
#include <vector>
using namespace std;

bool divideArray(vector<int>& nums) {
    int n = nums.size()/2, cnt = 0;
    int arr[501] = {0};

    for(auto i : nums) {
        arr[i]++;
    }

    for(auto i: arr) {
        if(i % 2 != 0) {
            return false;
        } cnt += i/2;
    }

    return cnt == n;
}

int main() {
    vector<int> nums = {3,2,3,2,2,2};
    cout << divideArray(nums);
    return 0;
}