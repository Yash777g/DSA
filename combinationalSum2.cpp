#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<vector<int>> &result, vector<int> candidates, int target, int index, vector<int> &combination) {
     if(target == 0) {
        result.push_back(combination);
        return;
    }

    for(int i = index; i < candidates.size(); i++) {
        if (i > index && candidates[i] == candidates[i - 1]) {
            continue;
        }

        if (candidates[i] > target) {
            break;
        }

        combination.push_back(candidates[i]);
        solve(result, candidates, target - candidates[i], i + 1, combination);
        combination.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> combination;

    sort(candidates.begin(), candidates.end());
    solve(result, candidates, target, 0, combination);
    return result;          
}

int main() {
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;

    vector<vector<int>> ans = combinationSum2(candidates, target);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}