#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isValid(int i, int j, string s) {
    int size = j-i;
    string str = s.substr(i, size);
    
    unordered_map<char,int> freq;
    for(int k = 0; k < str.size(); k++) {
        freq[str[k]]++;
    }

    if(freq['a'] == 0 || freq['b'] == 0 || freq['c'] == 0) {
        return false;
    }
    return true;
}

int numberOfSubstrings(string s) {
    int count = 0;
    int i = 0, j = 0;

    while(j < s.size()) {
        if(isValid(i, j + 1, s)) {
            count += s.size() - j;
            i++;
        }else {
            j++;
        }
    }

    return count;
}

int main() {
    cout << numberOfSubstrings("abcabc");
    return 0;
}