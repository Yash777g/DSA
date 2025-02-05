#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string largestNumber(vector<int>& nums) {
    string result = "";
    vector<string> temp;
    
    for(auto &i: nums) {
        temp.push_back(to_string(i));
    }

    sort(temp.begin(), temp.end(), [] (string a, string b) {
        return a + b > b + a;
    });

    for(auto &i:temp) {
        result += i;
    }

    return result;
}

int main() {
    vector<int> nums {3,30,34,5,9};

    string ans = largestNumber(nums);
    cout << ans;
    return 0;
}