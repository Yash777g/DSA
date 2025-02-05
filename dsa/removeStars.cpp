#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string removeStars(string s) {
    string str = "";

    for(char &ch : s) {
        if(ch == '*') {
            str.pop_back();
        } else {
            str.push_back(ch);
        }
    }
    return str;
}

int main() {
    string s = "leet**cod*e";
    cout << removeStars(s);
    return 0;
}