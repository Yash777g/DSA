#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool canConstruct(string s, int k) {
    if(s.size() < k) {
        return false;
    } if(s.size() == k) {
        return true;
    }

    int arr[26] = {0};
    for(int i = 0; i < s.size(); i++) {
        arr[s[i] - 'a']++;
    }

    int count = 0;
    for(auto &i : arr) {
        if(i%2 != 0) count++;
    }

    if(count > k) return false;
    return true;
}

int main() {
    cout << canConstruct("annabelle", 2);
    return 0;
}