#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long long countBadPairs(vector<int>& nums) {
    unordered_map<int, int> freq;
    long long int size = nums.size(), goodpairs = 0, ans = (size*(size-1))/2;
    
    for(int i = 0; i < nums.size(); i++) {
        freq[nums[i] - i]++;
    } 

    for(auto i: freq) {
        int count = i.second;
        if(count > 1) {
            goodpairs += (count*(count-1))/2; 
        }
    }

    return ans - goodpairs;
}

int main() {
    vector<int> nums = {4,1,3,3};
    cout << countBadPairs(nums);
    return 0;
}