#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string check_odd(string s, string result, int len) {
    int flag = 0;

    for(int i = 0; i < s.length(); i++) {
        int left = i, right = i;
        
        // for odd lenght
        while((left >= 0 && right < s.length()) && s[left] == s[right]) {
            left--;
            right++;

            if(flag < right - left + 1) {
                result = s.substr(left + 1, right - left - 1);
                flag = right - left + 1;
            }
        }
    }

    return result;
}

string check_even(string s, string result, int len) {
    int flag = 0;

    for(int i = 0; i < s.length(); i++) {
        int left = i, right = i + 1;
        
        // for even lenght
        while((left >= 0 && right < s.length()) && s[left] == s[right]) {
            left--;
            right++;

            if(flag < right - left + 1) {
                result = s.substr(left + 1, right - left - 1);
                flag = right - left + 1;
            }
        }
    }

    return result;
}

string longestPalindrome(string s) {
    if(s.length() == 1) {
        return s;
    }

    string result = "";
    string odd = "", even = "";
    int lenght = 0;

    odd = check_odd(s, result, lenght);
    even = check_even(s, result, lenght);

    if(odd.length() > even.length()) { return odd; }
   
   return even;
}

int main() {
    string s = "accd";

    string sol = longestPalindrome(s);  
    cout << sol; 
    return 0;
}