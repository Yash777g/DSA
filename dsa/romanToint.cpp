#include <iostream>
#include <unordered_map>
using namespace std;

int romanToInt(string s) {
    std::unordered_map<char, int> roman = {
        {'M', 1000}, {'D', 500}, {'C', 100},
        {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}
    };
    int result = 0;
    int n = s.length();

    for (int i = 0; i < n; ++i) {
        if (i < n - 1 && roman[s[i]] < roman[s[i + 1]]) {
            result -= roman[s[i]];
        } 
        else { result += roman[s[i]]; }
    }

    
    return result;
}

int main() {
    string s = "LVIII";

    int sol = romanToInt(s);
    cout << sol << endl;
    return 0;
}