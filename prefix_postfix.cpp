#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int size = nums.size();
    vector<int> output(size);

    int prefix = 1;
    for(int i = 0;i < size;i++) {
        output[i] = prefix;
        prefix = prefix*nums[i];
    }
    int postfix = 1;
    for(int i = size - 1;i >= 0;i--) {
        output[i] = output[i]*postfix;
        postfix = postfix*nums[i];
    }
    return output;
}

int main() {    
    vector<int> nums {1, 2, 3, 4};
    vector<int> answer = productExceptSelf(nums);
    for(int i = 0;i < answer.size();i++) {
        cout << answer[i] << " ";
    }
    return 0;
}