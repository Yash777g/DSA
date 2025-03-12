#include <iostream>
#include <unordered_map>
using namespace std;

bool isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return true;
    }
    return false;
}

long solve(string word, int k) {
    long long cnt = 0;
    int start = 0, consonantCount = 0;
    unordered_map<char, int> freq;

    for (int end = 0; end < word.size(); end++) {
        if (isVowel(word[end])) {
            freq[word[end]]++;
        } else {
            consonantCount++;
        }

        while (freq.size() == 5 && consonantCount >= k) {
            cnt += word.size() - end;

            if (isVowel(word[start])) {
                if (--freq[word[start]] == 0) {
                    freq.erase(word[start]);
                }
            } else {
                consonantCount--;
            }
            start++;
        }
    }
    return cnt;
}

long long countOfSubstrings(string word, int k) {
    return solve(word, k) - solve(word, k + 1);
}

int main() {
    string word = "ieaouqqieaouqq";
    cout << countOfSubstrings(word, 1);
    return 0;
}