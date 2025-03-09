#include <iostream>
#include <vector>
using namespace std;

int numberOfAlternatingGroups(vector<int>& colors, int k) {
    int size = colors.size();
    int count = 0;
    int validLength = 1;

    for (int i = 1; i < size + k - 1; i++) { 
        if (colors[i % size] != colors[(i - 1) % size]) {
            validLength++;
        } else {
            validLength = 1;
        }

        if (validLength >= k) count++;
    }

    return count;
}

int main() {
    vector<int> colors = {0,1,0,1,0}; 
    cout << numberOfAlternatingGroups(colors, 3);
    return 0;
}