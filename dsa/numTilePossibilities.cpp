#include <iostream>
using namespace std;

int count(int freq[26]) {
    int ans = 0;

    for(int i = 0; i < 26; i++) {
        if(freq[i] == 0) continue;

        freq[i]--;
        ans++;
        ans += count(freq);
        freq[i]++;
    }

    return ans;
}

int numTilePossibilities(string tiles) {
    int freq[26] = {0};

    for(auto ch: tiles) {
        freq[ch-'A']++;
    }

    return count(freq);
}

int main() {
    cout << numTilePossibilities("AAABBC");
    return 0;
}