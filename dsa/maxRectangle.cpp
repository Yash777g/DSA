#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// next smaller element index
vector<int> nextSmaller(vector<int> heights, int n) {
    stack<int> temp; 
    temp.push(-1);
    vector<int> result(n);
    
    for(int i = n-1; i >= 0; i--) {
        while(temp.top() != -1 && heights[temp.top()] >= heights[i]) {
            temp.pop();
        } result[i] = temp.top();
        temp.push(i); 
    } return result;
}

// previous smaller element index
vector<int> prevSmaller(vector<int> heights, int n) {
    stack<int> temp;
    temp.push(-1);
    vector<int> result(n);

    for(int i = 0; i < n; i++) {
        while(temp.top() != -1 && heights[temp.top()] >= heights[i]) {
            temp.pop();
        } result[i] = temp.top();
        temp.push(i);
    }
    return result;
}

int largestRectangleArea(vector<int>& heights) {
    int maxArea = 0, n = heights.size();
    vector<int> next(n), prev(n);
    
    next = nextSmaller(heights, n);
    prev = prevSmaller(heights, n);
    for(auto &i : next) {
        cout << i << " ";
    }cout << endl;
    for(auto &i : prev) {
        cout << i << " ";
    }cout << endl;
    
    for(int i = 0; i < n-1; i++) {
        if(next[i] == -1) next[i] = n;

        int area = heights[i]*(next[i] - prev[i] - 1);
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main() {
    vector<int> heights = {2,1,5,6,2,3};
    cout << largestRectangleArea(heights);
    return 0;
}