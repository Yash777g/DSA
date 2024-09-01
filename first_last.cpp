#include <iostream>
#include <vector>
using namespace std;

// O(n) time complexity
// vector<int> searchRange(vector<int>& nums, int target) {
//     vector<int> index = {-1,-1};

//     for(int i = 0; i < nums.size(); i++) {
//         // little optimization
//         if(nums[i] > target) { break; }

//         if(nums[i] == target) {
//             index[0] = i;
//             index[1] = i + 1;
//         }
//     }

//     return index;
// }

// O(log(n)) time complexity
int leftSide(vector<int> nums, int target) {
        int start = 0, end = nums.size() - 1;
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target == nums[mid]) {
                ans = mid;
                end = mid - 1;
            } else if (target < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }

    int rightSide(vector<int> nums, int target) {
        int start = 0, end = nums.size() - 1;
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                ans = mid;
                start = mid + 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = leftSide(nums, target);
        int right = rightSide(nums, target);
        return {left, right};
    }

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;

    vector<int> sol = searchRange(nums, target);
    cout << sol[0] << "  " << sol[1]; 
    return 0;
}