#include <iostream>
#include <vector>
#include <string>
using namespace std;

int minimumRecolors(string blocks, int k) {
    int ans = INT32_MAX;
    int i = 0, j = k - 1;

    while(j < blocks.size()) {
        int cnt = 0, temp = k;

        for(int k = i; k <= j; k++) {
            if(blocks[k] == 'W') {
                cnt++;
            } temp--;
        } 

        if(cnt < ans) {
            ans = cnt;
        } 
        j++; i++;
    }
    return ans;        
}

int main() {
    string blocks = "WBBWWBBWBW";
    int k = 7;

    cout << minimumRecolors(blocks, k);
    return 0;
}