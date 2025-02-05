#include <iostream>
#include <stack>
using namespace std;

string reverseString(string &s) {
    // 1st method time complexity: 0(n/2) and space complexity: 0(1) 
    /*for(int i = 0; i < s.size()/2; i++) {
        swap(s[i], s[s.size() - i - 1]);
    }

    return s;*/

    // 2nd method time complexity: 0(n) and space complexity: 0(n)
    stack<char> str;
    for(int i = 0; i < s.size(); i++) {
        str.push(s[i]);
    }
    
    string b = "";
    while(!str.empty()) {
        b += str.top();
        str.pop();
    }

    return b;
}

int main() {
    string s = "abcde";
    cout << reverseString(s) << endl;
    return 0;
}   