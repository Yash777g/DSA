#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

string frequencySort(string s) {
    string ans = "";
    unordered_map<char, int> mapping;
    for(auto ch : s) {
        mapping[ch]++;
    }

    vector<pair<int, char>> count;
    for(auto it : mapping) {
        count.push_back({it.second, it.first});
    }

    sort(count.rbegin(), count.rend());
    for(auto ch: count) {
        int freq = ch.first;
        
        while(freq--) {
            ans += ch.second;
        }
    }
    return ans;
}

int main() {
    cout << frequencySort("Aabb");    
    return 0;
}