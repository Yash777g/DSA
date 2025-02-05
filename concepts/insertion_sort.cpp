#include <iostream>
#include <vector>
using namespace std;

void insertion_Sort(vector<int> &nums) {
    int n = nums.size();

    for(int i = 1; i < n; i++) {
        for(int j = i-1; j >= 0; j--) {

            if(nums[j+1] < nums[j]) 
                swap(nums[j+1], nums[j]);
            else 
                break;
        }
    }
}

int main() {
    vector<int> nums {6,1,3,25,19};

    insertion_Sort(nums);
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    return 0;
}