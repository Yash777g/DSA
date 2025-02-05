#include <iostream>
#include <vector>
using namespace std;

void linearSearch(vector<int> &nums, int target, int start, int end) {
    if(start > end) { 
        cout << "Not Found !!!" << endl;
        return;
    }
    
    if(nums[start] == target) {
        cout << "Found at index: " << start << endl;
    }
    else {
        linearSearch(nums, target, start + 1, end);
    }
}

int main() {
    vector<int> nums {1,2,3,4,5};
    int target = 4;

    linearSearch(nums, target, 0, nums.size() - 1);
    return 0;
}