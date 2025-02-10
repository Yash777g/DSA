#include <iostream>
using namespace std;

string clearDigits(string s) {
    string ans = "";
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};

    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            ans.pop_back();
        } else {
            ans.push_back(s[i]);
        }
    }
    return ans;
}

int main() {
    cout << clearDigits("abc12");
    return 0;
}