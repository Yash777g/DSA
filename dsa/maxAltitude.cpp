#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int largestAltitude(vector<int>& gain) {
    int ans = 0, res = 0;
    for(int i = 0; i < gain.size(); i++) {
        ans += gain[i];
        res = max(res, ans);
    } return res;
}

int main() {
    vector<int> gain = {1,2,12,-5,-6,50,6};
    cout << largestAltitude(gain);
    return 0;    
}