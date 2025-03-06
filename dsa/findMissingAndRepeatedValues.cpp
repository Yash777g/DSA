#include <iostream>
#include <vector>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int repeated = 0, missing = 0;
    int size = grid.size();
    int freq[2501];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int index = grid[i][j];
            freq[index - 1]++;
        }
    }

    for (int i = 0; i < size * size; i++) {
        if (freq[i] == 2) {
            repeated = i + 1;
        }
        if (freq[i] == 0) {
            missing = i + 1;
        }
    }

    return {repeated, missing};
}

int main() {
    vector<vector<int>> grid = {{9,1,7},{8,9,2},{3,4,6}};
    vector<int> ans = findMissingAndRepeatedValues(grid);

    for(auto &i : ans) {
        cout << i << " ";
    }
    return 0;
}