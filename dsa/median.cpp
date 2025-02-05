#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int size = m + n;

        double median = 0.0;
        vector<double> result;
        
        int i = 0, j = 0;
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                result.push_back(nums1[i]);
                i++;
            }
            else {
                result.push_back(nums2[j]);
                j++;
            }
        }

        while(i < m) {
            result.push_back(nums1[i]);
            i++;
        }
        
        while(j < n) {
            result.push_back(nums2[j]);
            j++;
        }

        for(auto i: result) {
            cout << i << " ";
        }
        cout << endl;

        if (size % 2 == 0) {
            median = (result[size / 2 - 1] + result[size / 2]) / 2;
        } else {
            median = result[size / 2];
        }
        
        return median;
    }

int main() {
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2,4};

    double sol = findMedianSortedArrays(nums1, nums2);
    cout << sol;
    return 0;
}