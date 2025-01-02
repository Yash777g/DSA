#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    vector<int> prefix (words.size()+1 , 0);
    vector<int> ans;
    int count = 0;
    for(int i = 0; i < words.size(); i++) {
        string str = words[i];
        if(isVowel(str[0]) && isVowel(str[str.size()-1])) {
            count++;
        } prefix[i+1] = count;
    }

    for(auto &query : queries) {
        int left = query[0], right = query[1];
        int res = prefix[right + 1] - prefix[left];
        ans.push_back(res);
    }
    return ans;
}

int main() {
    vector<string> words = {"aba","bcb","ece","aa","e"};
    vector<vector<int>> queries = {{0,2},{1,4},{1,1}};
    vector<int> result = vowelStrings(words, queries);

    for(auto &i : result) {
        cout << i << " ";
    }
    return 0;
}