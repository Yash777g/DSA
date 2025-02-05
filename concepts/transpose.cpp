#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int x = matrix.size(), y = matrix[0].size();

    for(int i = 0; i < x; i++) 
        for(int j = i; j < y; j++) 
            swap(matrix[i][j], matrix[j][i]);
        
   vector<vector<int>> tp = matrix;
   return tp;
}

int main() {
    vector<vector<int>> matrix {{1,2,3},{4,5,6},{7,8,9}}, tp = {{0}};
    tp = transpose(matrix);

    for(int i = 0; i < tp.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) 
            cout << tp[i][j] << " ";
        
        cout << endl;
    }
    return 0;
}

