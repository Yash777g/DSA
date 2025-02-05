#include <iostream>
#include <vector>
using namespace std;

void selection_Sort(vector<int> &nums) {
    int min = 0;

    for(int i = 0; i < nums.size(); i++) {
        min = i;

        for(int j = 0; j < nums.size(); j++) {
            if(nums[min] < nums[j]) 
                min = j;

            swap(nums[min], nums[i]);
        }
    }
}

int main() {
    vector<int> nums {23,1,14,9,2,99,-10,-2};

    selection_Sort(nums);
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    return 0;
}