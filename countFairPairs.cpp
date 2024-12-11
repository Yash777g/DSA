#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// might complete it later
/*long long countFairPairs(vector<int>& nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    long long count = 0;

    for(int i = 0; i < nums.size() - 1; i++) {
        auto lower_bound_it = std::lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
        auto upper_bound_it = std::upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
        
        count += upper_bound_it - lower_bound_it;
    }

    return count;
}*/

long long countFairPairs(vector<int>& nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    long long count = 0;

    for(int i = 0; i < nums.size(); i++) {
        int start = i, end = nums.size() - 1;
        int left = -1, right = -1;

        upper -= nums[i];
        lower -= nums[i];

        while(start <= end) {
            int mid = (start + end) / 2;

            if(nums[mid] <= upper) {
                start = mid + 1;
                right = mid;
            }

            else {
                end = mid - 1;
            }
        }

        start = i, end = nums.size() - 1;
        while(start <= end) {
            int mid = (start + end) / 2;

            if(nums[mid] >= lower) {
                end = mid - 1;
                left = mid;
            }

            else {
                start = mid + 1;
            }
        }

        upper += nums[i];
        lower += nums[i];

        if (left != -1 && right != -1 && left <= right) {
            count += (right - left + 1);
        }
    }

    return count;
}

int main() {
    vector<int> nums = {0,1,7,4,4,5};
    cout << countFairPairs(nums, 3, 6);
    return 0;
}