#include <iostream> 
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int top = 0 ,left = 0 ,bottom = matrix.size() - 1 ,right = matrix[0].size() - 1;
    vector<int> result;

    while(top <= bottom && left <= right) {
        if(top <= bottom)
            for(int i = left ;i <= right ;i++)
                result.push_back(matrix[top][i]);
            top++;
            
        if(right >= left)
            for(int i = top ;i <= bottom ;i++)
                result.push_back(matrix[i][right]);
            right--;
            
        if(bottom >= top)
            for(int i = right ;i >= left ;i--)
                result.push_back(matrix[bottom][i]);
            bottom--;
            
        if(left <= right)
            for(int i = bottom ;i >= top ;i--)
                result.push_back(matrix[i][left]);
            left++;
    }

    return result;
}

int main() {
    vector<vector<int>> matrix {{1,2,3},{4,5,6},{7,8,9}}; 
    vector<int> result = spiralOrder(matrix);

    for(int i = 0 ;i < result.size() ;i++) 
        cout << result[i] << " ";
    
    return 0;
}