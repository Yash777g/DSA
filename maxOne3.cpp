#include <iostream>
#include <vector>
using namespace std;

inline int max(int a, int b) {
    if(a > b) {
        return a;
    } return b;
}

int longestOnes(vector<int>& nums, int k) {
    int i = 0, j = 0;
    int maxOne = 0;

    while(j < nums.size()) {
        if(nums[j] == 0) {
            k--;
        } while(k < 0) {
            if(nums[i] == 0) {
                k++;
            } i++;
        }
        maxOne = max(maxOne, j-i+1);
        j++;
    }

    return maxOne;
}

int main() {
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    cout << longestOnes(nums, 2);
    return 0;
}