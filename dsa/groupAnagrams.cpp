#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    map<string, vector<string>> mapping;

    for(auto str: strs) {
        string sorted = str;
        sort(sorted.begin(), sorted.end());

        mapping[sorted].push_back(str);
    }

    for(auto i: mapping) {
        vector<string> st = i.second;
        ans.push_back(st);
    }
    return ans;       
}

int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    
    vector<vector<string>> result = groupAnagrams(strs);
    for(auto str: result) {
        for(auto st: str) {
            cout << st << " ";
        }
    }
    return 0;
}