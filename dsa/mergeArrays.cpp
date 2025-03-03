#include <iostream>
#include <vector>
using namespace std;

void mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
    vector<vector<int>> ans;
    int i = 0, j = 0;
    int len1 = nums1.size(), len2 = nums2.size();
    
    while (i < len1 && j < len2) {
        if (nums1[i][0] == nums2[j][0]) {
            ans.push_back(
                {nums1[i][0], nums1[i][1] + nums2[j][1]});
            i++;
            j++;
        } else if (nums1[i][0] < nums2[j][0]) {
            ans.push_back(nums1[i]);
            i++;
        } else {
            ans.push_back(nums2[j]);
            j++;
        }
    }

    while (i < len1) {
        ans.push_back(nums1[i]);
        i++;
    }

    while (j < len2) {
        ans.push_back(nums2[j]);
        j++;
    }
    
    // return ans;
}

int main() {
    vector<vector<int>> nums1 = {{1,2},{2,3},{4,5}};
    vector<vector<int>> nums2 = {{1,4},{3,2},{4,1}};

    mergeArrays(nums1, nums2);

    return 0;
}