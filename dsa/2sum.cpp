#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//0(n2) solution using nested loop
// vector<int> twoSum(vector<int>& nums, int target) {ṇ
//         int n = nums.size();
//         for (int i = 0; i < n - 1; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (nums[i] + nums[j] == target) {
//                     return {i, j};
//                 }
//             }
//         }
//         return {}; 
//     }

//O(n) solution using hashtable
vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (map.count(complement) && map[complement] != i) {
                return {i, map[complement]};
            }
        }

        return {};
    }

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    return 0;
}