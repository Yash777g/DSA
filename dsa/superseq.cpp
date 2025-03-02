#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string shortestCommonSupersequence(string str1, string str2) {
    string res = "";
    int len1 = str1.size();
    int len2 = str2.size();

    vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));

    for(int i = 1; i <= len1; i++) {
        for(int j = 1; j <= len2; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string lcs = "";
    int i = len1, j = len2;

    while(i > 0 && j > 0) {
        if(str1[i-1] == str2[j-1]) {
            lcs += str1[i-1];
            i--; j--;
        } else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());
    int len = lcs.size(), k = 0;
    i = 0, j = 0;
    
    while (k < len) {
        if (i < len1 && j < len2 && str1[i] == str2[j] && str1[i] == lcs[k]) {
            res += str1[i];
            i++; j++; k++;
        } else if (i < len1 && str1[i] != lcs[k]) {
            res += str1[i];
            i++;
        } else if (j < len2) {
            res += str2[j];
            j++;
        }
    }

    while(i < len1) {
        res += str1[i];
        i++;
    } 
    while(j <  len2) {
        res += str2[j];
        j++;
    }
    return res;
}

int main() {
    string ans = shortestCommonSupersequence("bbabacaa","cccababab");
    cout << ans;
    return 0;
}