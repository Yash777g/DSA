#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

string shiftingLetters(string s, vector<vector<int>>& shifts) {
    vector<int> shift(s.size(), 0);
    for(auto &i : shifts) {
        int left = i[0];
        int right = i[1]+1;

        if(i[2] == 1) {
            shift[left] += 1;
            shift[right] -= 1;
        } else {
            shift[left] -= 1;
            shift[right] += 1;
        }
    }

    for(int i = 1; i < shift.size(); i++) {
        shift[i] += shift[i-1];
    }
    
    for(int i = 0; i < shift.size(); i++) {
        int rotate = shift[i]%26;
        s[i] = (s[i] - 'a' + rotate + 26) % 26 + 'a';
    }
    return s;
}

int main() {
    string s = "abc";
    vector<vector<int>> shifts = {{0,1,0},{1,2,1},{0,2,1}};
    cout << shiftingLetters(s, shifts);
    return 0;
}