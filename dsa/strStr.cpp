#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle) {
    if (haystack.size() < needle.size()) return -1;
    if(haystack == needle) return 0;

    for(int i = 0; i <= haystack.size() - needle.size(); i++) {
        string str = haystack.substr(i, needle.size());

        if(str == needle) {
            return i;
        }
    } 
    return -1;        
}

int main() {
    string haystack = "sadlifesadgoal", needle = "sad";
    cout << strStr(haystack, needle);
    return 0;
}