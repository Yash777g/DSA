#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool areAlmostEqual(string s1, string s2) {
    if(s1 == s2) 
        return true;

    int count = 0, freq[26] = {0};
    for(int i = 0; i < s1.size(); i++) {
        if(s1[i] != s2[i]) {
            count++;
        }
        freq[s1[i] - 'a']++;
        freq[s2[i] - 'a']--;
    }

    for(auto num : freq) {
        if(num != 0) {
            return false;
        }
    }

    if(count == 2) {
        return true;
    }
    return false;
}


int main() {
    cout << areAlmostEqual("bank", "kanb");
    return 0;
}