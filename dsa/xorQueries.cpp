#include <iostream>
#include <vector>
using namespace std;

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int len = arr.size();
    vector<int> prefix(len);

    prefix[0] = arr[0];

    for(int i = 1; i < arr.size(); i++) {
        prefix[i] = prefix[i - 1] ^ arr[i];        
    }

    vector<int> ans = {};

    for(auto &q : queries) {
        int left = q[0], right = q[1];

        if(left == 0) { ans.push_back(prefix[right]); }

        else { ans.push_back(prefix[right] ^ prefix[left - 1]); }
    }

    return ans;
}

int main() {
    vector<int> arr = {1,3,4,8};
    vector<vector<int>> queries = {{0,1},{1,2},{0,3},{3,3}};

    vector<int> sol = xorQueries(arr, queries);

    for(auto &i : sol) {
        cout << i << " ";
    }

    return 0;
}