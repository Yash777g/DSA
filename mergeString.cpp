#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string mergeAlternately(string word1, string word2) {
    int i = 0;
    string ans = "";

    for(i = 0; i < word1.size(); i++) {
        ans += word1[i];
        if(word2[i] != '\0')
            ans += word2[i];
    }

    if(i < word2.size())
        ans.append(word2.substr(i, word2.size()));
    
    return ans;
}

int main() {
    string word1 = "ab", word2 = "pqrs";
    cout << mergeAlternately(word1, word2) << endl;
    return 0;
}