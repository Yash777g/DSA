#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

vector<string> uncommonFromSentences(string s1, string s2) {
    unordered_map<string,int> result;
    vector<string> sol;
    string combine = s1 + ' ' + s2;
    string temp = "";

    for(char word: combine) {
        if(word != ' ') {
            temp += word;
        } 
        
        else {
            if(!temp.empty()) {
                result[temp]++;
                temp = "";
            }
        }
    }

    if(!temp.empty()) {
        result[temp]++;
    }


    for(auto &i : result) {
        if(i.second == 1) {
            sol.push_back(i.first);
        }
    }

    return sol;
}

int main() {
    string  s1 = "apple apple", s2 = "banana";

    vector<string> ans = uncommonFromSentences(s1, s2);

    for(auto &i: ans) {
        cout << i << " ";
    }
    return 0;
}