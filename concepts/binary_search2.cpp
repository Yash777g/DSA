#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int> &nums) {
    if(is_sorted(nums.begin(), nums.end())) {
        cout << "Sorted !!!! " << endl;
        return true;
    }
    
    else 
        cout << "Use linear search !!!!" << endl;
    return false;
} 

void binary_Search(vector<int> nums, int target) {
    int left = 0, right = nums.size() - 1, flag = 0;

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) {
            cout << "Found at index " << mid << endl;
            flag = 1;
            break;
        }

        else if(nums[mid] > target) 
            right = mid - 1;
        
        else
            left = mid + 1;
    }

    if(flag == 0) 
        cout << "Not found" << endl;
}

int main() {
    vector<int> nums {1, 2, 4, 9, 10};
    
    if (check(nums) == 1)
        binary_Search(nums, 5);
        
    return 0;
}