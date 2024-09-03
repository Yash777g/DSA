#include <iostream>
#include <math.h>
using namespace std;

int getLucky(string s, int k) {
    int ans = 0;

    for(char ch : s) {
        int temp = ch - '`';

        if(temp > 9) { ans += temp / 10; }
        ans += temp % 10;
    }

    while(--k) {
        if(ans < 10) return ans;
        int temp = 0;

        while(ans) {
            temp += ans % 10;
            ans /= 10;
        }

        ans = temp;
    }
    return ans;
}

int main() {
    string s = "az";
    int k = 2;

    int sol = getLucky(s, k);
    //cout << sol;
    return 0;
}