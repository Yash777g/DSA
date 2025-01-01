#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int maxScore(string s) {
    int score = 0, zero = 0, one = 0;

    for(auto &ch: s) {
        if(ch == '1') one++;
    }

    for(int i = 0; i < s.size()-1; i++) {
        if(s[i] == '0') zero++;
        else one--;

        score = max(score, zero + one);
    }

    return score;
}

int main() {
    string s = "011101";
    cout << maxScore(s);
    return 0;
}