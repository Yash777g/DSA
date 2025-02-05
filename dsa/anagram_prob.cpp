#include <iostream>
#include <string.h>
using namespace std;

bool solution(string s, string t) {
    int arr[26] = {0};

    for(int i = 0 ;i < s.size() ;i++) {
        ++arr[s[i] - 'a'];
        --arr[t[i] - 'a'];
    }

    for(int i = 0 ;i < 26 ;i++){
        if(arr[i] > 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string s = "yash", t = "hsay";           
    bool ans = solution(s,t);
    cout << ans;
    return 0;
}