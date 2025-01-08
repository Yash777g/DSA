#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool isPrefix(string a, string b) {
    int m = a.size();
    int n = b.size();

    if(m >= n) return 0;

    for(int i = 0; i < m; i++) {
        if(a[i] != b[i]) return 0;
    } return 1;
}

bool isSuffix(string a, string b) {
    int m = a.size();
    int n = b.size();

    if(m >=n) return 0;

    for (int i = 0; i < m; i++) { 
        if (a[i] != b[n-m+i]) return 0; 
    } return 1;
}

int countPrefixSuffixPairs(vector<string>& words) {
    int count = 0;
    for(int i = 0; i < words.size() - 1; i++) {
        for(int j = i + 1; j < words.size(); j++) {
            if(isPrefix(words[i], words[j]) && isSuffix(words[i], words[j])) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    vector<string> words = {"bb","bb"};
    cout << countPrefixSuffixPairs(words) << endl;
    return 0;
}