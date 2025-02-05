#include <iostream>
#include <vector>
using namespace std;

// using dp used in longest common subsequence
bool isSubsequence(string s, string t) {
    int n = s.size(), m = t.size();
    std::vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n;i++) {
        for(int j = 1; j <= m;j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m] == n;
}

// two pointer
/*bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    while(i < s.size() && j < t.size()) {
        if(s[i] == t[j]) {
            i++;
        }
        j++;
    } return i == s.size();
}*/

int main() {
    string s = "abc", t = "ahbgdc";
    cout << isSubsequence(s, t); 
    return 0;
}