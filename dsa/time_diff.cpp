#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findMinDifference(vector<string>& timePoints) {
    vector<int> min;
    int minDiff = INT32_MAX;
    
    for(auto &i: timePoints) {
        int h = stoi(i.substr(0, 2));
        int m = stoi(i.substr(3));

        min.push_back(h*60 + m);
    }

    std::sort(min.begin(), min.end());

    for (size_t i = 0; i < min.size() - 1; ++i) {
        minDiff = std::min(minDiff, min[i + 1] - min[i]);
    }

    minDiff = std::min(minDiff, 24 * 60 - min.back() + min.front());

    return minDiff;
}

int main() {
    vector<string> timepoints = {"05:31","22:08","00:35"};

    int ans = findMinDifference(timepoints);  
    cout << ans;  
    return 0;
}