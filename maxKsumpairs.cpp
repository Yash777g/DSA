#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// two pointer approach O(nlog(n)) 
/*int maxOperations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int i = 0, j = nums.size() - 1;
    int count = 0;

    while(i < j) {
        if(nums[i] + nums[j] == k) {
            count++;
            i++; j--;
        } else if(nums[i] + nums[j] < k) {
            i++;
        } else {
            j--;
        }
    }
    return count;
}*/

// hash map solution O(n)
int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    
    int res = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(k - nums[i] == nums[i]) {
            res += freq[nums[i]] / 2;
            freq[nums[i]] = 0;
        } else if(freq[k - nums[i]] > 0) {
            int mini = min(freq[nums[i]], freq[k - nums[i]]);
            res += mini;
            freq[k - nums[i]] -= mini; 
        }
        freq[nums[i]] = 0;
    }
    return res;
}


int main() {
    vector<int> nums = {1,3,1,3,4,3,5};
    cout << maxOperations(nums, 6);
    return 0;
}