#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isVowel(char c) {
    string t = "aeiou";
    for(auto &ch : t) {
        if (ch == c) return true;
    } return false;
}

int maxVowels(string s, int k) {
    int j = 0, count = 0, curr = 0;
    for (int i = 0; i < s.size(); i++) {
        if (isVowel(s[i])) {
            curr++;
        }
        if (i >= k) {
            if (isVowel(s[j])) {
                curr--;
            }
            j++;
        }
        count = max(count, curr);
    }
    return count;
}

int main() {
    string s = "abciiidef";
    cout << maxVowels(s, 3);
    return 0;
}