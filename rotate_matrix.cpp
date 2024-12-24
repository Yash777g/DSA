#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int row = matrix.size(), col = matrix[0].size();
        
    for(int i = 0; i < row; i++) {
        
        for(int j = i; j < col; j++) { swap(matrix[i][j], matrix[j][i]); }
    }

    for(int i = 0; i < row; i++) { reverse(matrix[i].begin(), matrix[i].end()); }
}

int main() {
    vector<vector<int>> matrix {{1,2,3},{4,5,6},{7,8,9}};
    rotate(matrix);

    for(auto &i: matrix) {
        for(auto &j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

