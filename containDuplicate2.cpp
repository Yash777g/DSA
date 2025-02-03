#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    vector <pair<int, int>> temp;

	for (int i = 0; i < nums.size(); i++) {
		temp.push_back(make_pair(nums.at(i), i));
	}

    sort(temp.begin(), temp.end());
    for(int i = 1; i < temp.size(); i++) {
        if(temp[i].first == temp[i-1].first) {
            if(temp[i].second - temp[i-1].second <= k) {
                return true;
            }
        }
    }

    // unordered_map<int,vector<int>> mapping;
    // for(int i = 0; i < nums.size(); i++) {
    //     mapping[nums[i]].push_back(i);
    // }

    // for(auto &i : mapping) {
    //     cout << i.first << ":";
    //     for(auto &val : i.second) {
    //         cout << val << " ";
    //     } cout << endl;
    // }

    // for(auto &i : mapping) {
    //     vector<int> values = i.second;
    //     for(int j = 1; j < values.size(); j++) {
    //         if(values[j] - values[j-1] <= k) {
    //             return true;
    //         }
    //     }
    // }
    return false;
}

int main() {
    vector<int> nums = {1,2,3,1};
    cout << containsNearbyDuplicate(nums, 3);
    return 0;
}