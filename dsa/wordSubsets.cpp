#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    vector<string> ans;
    map<char,int> freq;
    for (auto word : words2) {
        map<char, int> temp;
        for (auto ch : word) {
            temp[ch]++;
        }
        for (auto ch : temp) {
            freq[ch.first] = max(freq[ch.first], ch.second);
        }
    }

    for(auto word: words1) {
        map<char,int> temp;
        int flag = 1;

        for(auto ch : word) temp[ch]++;
        for(auto ch : freq) {
            if(temp.find(ch.first) == temp.end() || temp[ch.first] < ch.second) {
                flag = 0;
            }
        }

        if(flag == 1) ans.push_back(word);
    
    }
    return ans;
}

int main() {
    vector<string> words1 = {"amazon","apple","facebook","google","leetcode"}, words2 = {"lo","eo"};
    vector<string> result = wordSubsets(words1, words2);
    for(auto &i : result) {
        cout << i << " ";
    }
    return 0;
}