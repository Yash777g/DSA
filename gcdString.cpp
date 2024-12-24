#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

string gcdOfStrings(string str1, string str2) {
    int a = str1.size(), b = str2.size();
    int len = gcd(a, b);

    string ans = "";
    ans = str2.substr(0, len);
    
    for(int i = 0; i < a/len; i++) {
        if(str1.substr(i*len, len) != ans) {
            return "";
        }
    }

    for(int i = 0; i < b/len; i++) {
        if(str2.substr(i*len, len) != ans) {
            return "";
        }
    }

    return ans;
}

int main() {
    string str1 = "TAUXXTAUXXTAUXXTAUXXTAUXX", str2 = "TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX";
    cout << gcdOfStrings(str1, str2) << endl;
    return 0;
}

