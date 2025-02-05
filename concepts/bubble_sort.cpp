#include <iostream>
#include <vector>
using namespace std;

void bubble_Sort(vector<int> &nums) {
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j < n - i - 1; j++) {
            
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}

int main() {
    vector<int> nums {3, 1, 51, 19, 23, -101, 102};

    bubble_Sort(nums);
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}