#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size() ,col = matrix[0].size();
    int start = 0 ,end = (row * col) - 1;

    while(start <= end) {
        int mid = start + (end - start)/2;
        int element = matrix[mid / col][mid % col];
        
        if(element == target) 
            return true;
        
        else if(element < target) 
            start = mid + 1;
        
        else 
            end = mid - 1;
    }

    return false;
}

int main() {
    vector<vector<int>> matrix {{1,2,3},{4,5,6},{7,8,9}};
    int target = 6;

    bool ans = searchMatrix(matrix,target);
    cout << ans;
    return 0;
}

