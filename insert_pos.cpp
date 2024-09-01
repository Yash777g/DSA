#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1;

    if(target > nums[end]) { return end + 1; }

    while(start <= end) {
        int mid = (start + end) / 2;

        if(nums[mid] == target) { return mid; }

        else if(nums[mid] < target) { start = mid + 1; }

        else { end = mid - 1; }
    }

    return start;
}

int main() {
    vector<int> nums {1,3,5,6};
    int target = 5;

    int sol = searchInsert(nums, target);
    cout << sol;
    return 0;
}