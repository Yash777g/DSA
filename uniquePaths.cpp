#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    int count = 0;

    dp[1][1] = 1;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == 1 && j == 1) {
                continue;
            } dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    for(auto &i : dp) {
        for(auto &j : i) 
            cout << j << " ";
        cout << endl;
    }
    return dp[m][n];
}

int main() {
    cout << uniquePaths(3,7);
    return 0;
}