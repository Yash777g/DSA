#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int equalPairs(vector<vector<int>>& grid) {
    int count = 0, n = grid.size();
    unordered_map<int, string> row;
    unordered_map<int, string> col;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            row[i] += to_string(grid[i][j]);
            row[i] += "/";
            col[i] += to_string(grid[j][i]);
            col[i] += "/";
        } 
    }

    for(auto &i : row) {
        string str1 = i.second;
        for(auto &j : col) {
            string str2 = j.second;
            if(str1 == str2) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    vector<vector<int>> grid = {{2,1,1,7},{1,1,1,1},{23,1,5,1},{2,12,3,2}};
    cout << equalPairs(grid);
    return 0;
}