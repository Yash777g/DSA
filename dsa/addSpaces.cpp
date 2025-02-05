#include <iostream>
#include <vector>
#include <string>
using namespace std;

string addSpaces(string s, vector<int>& spaces) {
    string ans = "";
    int j = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if(j < spaces.size() && i == spaces[j]) {
            ans += " ";
            j++;
        }

        ans += s[i];
    }

    return ans;
}

int main() {
    string s = "LeetcodeHelpsMeLearn";
    vector<int> spaces = {8, 13 ,15};

    cout << addSpaces(s, spaces);
    return 0;
}