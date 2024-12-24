#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<vector<int>> &result, vector<int> candidates, int target, int index, vector<int> &combination) {
    if(target == 0) {
        result.push_back(combination);
        return;
    }

    if(target < 0) 
        return;

    for(int i = index; i < candidates.size(); i++) {
        combination.push_back(candidates[i]);
        solve(result, candidates, target - candidates[i], i, combination);
        combination.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> combination;

    solve(result, candidates, target, 0, combination);
    return result;          
}

int main() {
    vector<int> candidates = {2,3,6,7};
    int target = 7;

    vector<vector<int>> ans = combinationSum(candidates, target);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}