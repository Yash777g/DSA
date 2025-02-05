#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    if (numRows == 0) return {};
    if (numRows == 1) return {{1}};

    vector<vector<int>> dp;
    dp[0][0]=1;
    

}


int main() {
    int numRows=5;
    vector<vector<int>> ans=generate(numRows);
    for(int i=0;i<ans.size();i++) {
        for(int j=0;j<ans[i].size();j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}