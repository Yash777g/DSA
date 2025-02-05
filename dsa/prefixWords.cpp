#include <iostream>
#include <vector>
using namespace std;

int prefixCount(vector<string>& words, string pref) {
    int count = 0;

    for(auto &str : words) {
        int flag = 1;

        for(int i = 0; i < pref.size(); i++) {
            if(str[i] != pref[i]) {
                flag = 0;
                break;
            }
        }

        if(flag == 1) count++;
    }
    return count;
}

int main() {
    vector<string> words = {"pay","attention","practice","attend"};
    cout << prefixCount(words, "at");
    return 0;
}