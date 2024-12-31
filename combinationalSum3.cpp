#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int> &combination, vector<vector<int>> &result, int k, int n, int i) {
    if(k == combination.size()) {
        if(n == 0) result.push_back(combination);
        return;
    }

    for (int num = i; num <= 9; ++num) {
        if (n - num < 0) break; 

        combination.push_back(num);
        solve(combination, result, k, n - num, num + 1); 
        combination.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    if(n > 45) return {{}};

    vector<vector<int>> result;
    vector<int> combination;
    solve(combination, result, k, n, 1);
    return result;
}

int main() {
    vector<vector<int>> ans = combinationSum3(3, 7);
    for(auto &i: ans) {
        for(auto &j: i) cout << j << " ";
        cout << endl;
    }
    return 0;
}