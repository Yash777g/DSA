#include<iostream>
#include<vector>
using namespace std;

int duplicateElement(vector<int>& nums) {
    int result = 0;

    for(int i = 0; i < nums.size(); i++) 
        result = result^nums[i];
    
    for(int i = 0; i < nums.size(); i++) 
        result = result^i;
    
    return result;
}

int main() {
    vector<int> nums {1,2,3,4,2};
    
    int answer = duplicateElement(nums);
    cout << answer;
    return 0;
}