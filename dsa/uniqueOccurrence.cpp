#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

// using map and set
bool uniqueOccurrences(vector<int>& arr) {
    map<int, int> count;
    for(int i=0;i<arr.size();i++) {
        count[arr[i]]++;
    }
        
    set<int> seen;
    for(auto& x:count) {
        if(seen.find(x.second) != seen.end()) {
            return false;
        }
        seen.insert(x.second);
    }
    return true;
}

// using only vector
/*bool uniqueOccurrences(vector<int>& arr) {
    vector<int> freq(2001,0);
    for(auto &i: arr) {
        freq[i+1000]++;
    } sort(freq.begin(), freq.end());

    for(int i = 0; i < 2000; i++) {
        if(freq[i] == freq[i+1] && freq[i] != 0)  return false;
    }
    return true;
}*/

int main() {
    vector<int> nums = {1,2,2,1,1,3};
    cout << uniqueOccurrences(nums);
    return 0;
}