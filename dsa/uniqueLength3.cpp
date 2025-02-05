#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

int countPalindromicSubsequence(string s) {
    int count = 0;
    unordered_map<char, pair<int,int>> occurence;
    for(int i = 0; i < s.size(); i++) {
        if(occurence.find(s[i]) == occurence.end()) {
            occurence[s[i]].first = i;
        } occurence[s[i]].second = i;
    }     

    for(auto &ch : occurence) {
        auto &index = ch.second;
        int left = index.first, right = index.second;

        set<char> check;
        for(int i = left+1; i < right; i++) {
            check.insert(s[i]);
        } count += check.size();
    }
    return count;
}

int main() {
    string s = "bbcbaba";
    cout << countPalindromicSubsequence(s);
    return 0;
}