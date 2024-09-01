#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    if(m * n != original.size()) { return {}; }

    vector<vector<int>> result;
    int index = 0; 
    for(int i = 0; i < m; i++) {
        vector<int> temp {};
        
        for(int j = 0; j < n; j++) {
            temp.push_back(original[index]);
            index++;
        }

        result.push_back(temp);
    }

    return result;
}

int main() {
    vector<int> original = {1,2,3};
    int m = 1, n = 3;

    vector<vector<int>> sol = construct2DArray(original, m, n);

    for(int i = 0; i < sol.size(); i++) {
        for(int j = 0; j < sol[0].size(); j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}