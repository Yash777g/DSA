#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tupleSameProduct(vector<int>& nums) {
    int count = 0;
    vector<int> freq;

    for(int i = 0; i < nums.size() - 1; i++) {
        for(int j = i+1; j < nums.size(); j++) {
            freq.push_back(nums[i] * nums[j]);
        }
    }

    sort(freq.begin(), freq.end());

    int lastseenprod = -1;
    int countcurr = 0;

    for(int i = 0; i < freq.size(); i++) {
        if(freq[i] == lastseenprod) {
            countcurr++;
        } else {
            int combination = countcurr*(countcurr - 1) / 2;
            count += 8*combination;

            lastseenprod = freq[i];
            countcurr = 1;
        }
    }
    
    return count;
}

/*int tupleSameProduct(vector<int>& nums) {
    int count = 0;
    unordered_map<int, vector<vector<int>>> mapping; 

    for(int i = 0; i < nums.size()-1; i++) {
        for(int j = i+1; j < nums.size(); j++) {
            int product = nums[i] * nums[j];

            mapping[product].push_back({nums[i], nums[j]});
        }
    }

    for(auto i: mapping) {
        vector<vector<int>> temp = i.second;

        int to = 0;
        for(int a = 0; a < temp.size(); a++) {
            for(int b = 0; b < temp[0].size(); b++) {
                to++;
            }
        }

        if(to > 2) {
            to = to/2;
            count += (to * (to-1)) * 4;
        }
    }
    return count;
}*/


int main() {
    vector<int> nums = {2,3,4,6};
    cout << tupleSameProduct(nums);
    return 0;
}