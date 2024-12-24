#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// time complexity O(n) and space complexity O(1) linear approach
/*int max(vector<int> &nums) {
    int max = nums[0];
    for (int i = 1; i < nums.size(); i++) 
        if (nums[i] > max) 
            max = nums[i];
    
    return max;
}

int min(vector<int> &nums) {
    int min = nums[0];
    for (int i = 1; i < nums.size(); i++) 
        if (nums[i] < min) 
            min = nums[i];
    
    return min;
}*/

// time complexity O(log(n)) and space complexity O(1) divide and conqueror approach
void max_min(const std::vector<int> &nums, int start, int end, int &max, int &min) {
    if(start == end) 
        max = min = nums[start];
    
    else if(start + 1 == end) { 
        if(nums[start] > nums[end]) {
            max = nums[start];
            min = nums[end];
        } 
        else {
            max = nums[end];
            min = nums[start];
        }
    } 
    
    else {
        int mid = (start + end) / 2;
        int max1, min1, max2, min2;
        
        max_min(nums, start, mid, max1, min1);
        max_min(nums, mid + 1, end, max2, min2);
        
        max = (max1 > max2) ? max1 : max2;
        min = (min1 < min2) ? min1 : min2;
    }
}


int main() {
    vector<int> nums {1,2,3,4,5};
    int max = 0, min = 0;
    //cout << max(nums) << endl;
    //cout << min(nums) << endl;

    max_min(nums, 0, nums.size() - 1, max, min);
    cout << max << endl << min;
    return 0;
}