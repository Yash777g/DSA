#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string temp = "", ans = strs[0];

    for(int i = 1; i < strs.size(); i++) {
        string str = strs[i];
        int j = 0, k = 0;

        while(j < ans.size() || k < str.size()) {
            if(ans[j] == str[k]) {
                temp += ans[j];
                j++; k++;
            } else {
                break;
            }
        }
        ans = temp;
        temp = "";
    } 
   return ans;
}

int main() {
    vector<string> strs = {"flower","flow","flight"};
    cout << longestCommonPrefix(strs);
    return 0;
}