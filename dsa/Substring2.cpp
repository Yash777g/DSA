#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> freq(128, 0);
    int maxLen = 0, i = 0, j = 0;

    while(j < s.size()) {
        freq[s[j]]++;

        while(freq[s[j]] > 1) {
            freq[s[i]]--;
            i++;
        }

        maxLen = max(maxLen, j - i + 1);
        j++;
    }

    return maxLen;
}

int main() {
    string s = "pwwkew";

    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}