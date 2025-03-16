#include <iostream>
#include <vector>
using namespace std;

string convert(string s, int numRows) {
    if (numRows == 1 || numRows >= s.size()) return s;
    vector<vector<char>> grid(numRows, vector<char>(s.size(), ' '));

    int row = 0, col = 0, ch = 0;
    while (ch < s.size()) {

        while (row < numRows && ch < s.size()) {
            grid[row++][col] = s[ch++];
        }

        row -= 2;
        col++;    

        while (row >= 0 && ch < s.size()) {
            grid[row--][col++] = s[ch++];
        }

        row += 2; 
    }

    string ans = "";
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < s.size(); j++) {
            if (grid[i][j] != ' ') {
                ans += grid[i][j];
            }
        }
    }

    return ans;
}

int main() {
    string s = "PAYPALISHIRING";
    cout << convert(s, 4);
    return 0;
}