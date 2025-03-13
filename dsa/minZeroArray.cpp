#include <iostream>
#include <vector>
using namespace std;

int minZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size(), sum = 0, k = 0;
    vector<int> differenceArray(n + 1);

    for (int index = 0; index < n; index++) {
        while (sum + differenceArray[index] < nums[index]) {
            k++;
            if (k > queries.size()) {
                return -1;
            }

            int left = queries[k - 1][0], right = queries[k - 1][1], val = queries[k - 1][2];

            if (right >= index) {
                differenceArray[max(left, index)] += val;
                differenceArray[right + 1] -= val;
            }
        }

        sum += differenceArray[index];
    }
    return k;
}

int main() {
    vector<int> nums = {2, 0, 2};
    vector<vector<int>> queries = {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}};
    cout << minZeroArray(nums, queries);
    return 0;
}