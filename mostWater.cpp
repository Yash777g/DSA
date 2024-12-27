#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
        int n = height.size();
        if (n == 1)
            return height[0];
        if (n == 2)
            return min(height[0], height[1]);

        int i = 0, j = n - 1;
        int maxArea = 0;

        while (i < j) {
            int area = min(height[i], height[j])*(j-i);
            maxArea = max(maxArea, area);

            if (height[i] < height[j]) {
                i++;
            } else {
                j++;
            }
        }
        return maxArea;
    }

int main() {
    vector<int> height = {1,3,2,5,25,24,5};
    cout << maxArea(height);
    return 0;
}