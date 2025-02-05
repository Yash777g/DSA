#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

inline bool isVowel(char c) {
    string vowels = "aeiouAEIOU";
    for(int i = 0; i < vowels.size(); i++) {
        if(c == vowels[i]) {
            return true;
        }
    }
    return false;
}

string reverseVowels(string s) {
    int i = 0, j = s.size() - 1;
    while(i < j) {
        if(isVowel(s[i]) && isVowel(s[j])) {
            swap(s[i], s[j]);
            i++;
            j--;
        } else if(!isVowel(s[j])) {
            j--;
        } else {
            i++;
        }
    }
    return s;
}


int main() {
    string s = "IceCreAm";
    cout << reverseVowels(s);
    return 0;
}