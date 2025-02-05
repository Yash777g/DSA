#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

int countConsistentStrings(string allowed, vector<string>& words) {
    int count = 0;
    unordered_set<char> IsAllowed;

    for(auto &i : allowed) { IsAllowed.insert(i); }

    for(auto &word : words) {
        bool check = true;

        for(auto &i : word) {
            
            if(IsAllowed.find(i) == IsAllowed.end()) {
                check = false;
                break;
            }
        }

        if(check == true) count++;
    }

    return count;
}

int main() {
    vector<string> words  = {"ad","bd","aaab","baa","badab"};
    string allowed = "ab";

    int ans = countConsistentStrings(allowed, words);
    cout << ans;
    return 0;
}