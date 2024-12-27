#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();
    int i = 0, j = n - 1;
    int area = 0;

    while (i < j) {
        int currentArea = min(height[i], height[j]) * (j - i);
        area = max(area, currentArea);

        if (height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    } return area;
}


int main() {
    vector<int> height = {1,3,2,5,25,24,5};
    cout << maxArea(height);
    return 0;
}