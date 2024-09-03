#include <iostream>
#include <math.h>
using namespace std;

int getLucky(string s, int k) {
    int num = 0, flag = 0;

    for(int i = s.size() - 1; i >= 0; i--) {
        num = num + (s[i] - 'a' + 1) * pow(10, flag);
        
        
        cout << num << "    " << (s[i] - 'a' + 1 )* pow(10, flag) << "     " << (s[i] - 'a' + 1)  << endl;
        flag++;
    }

    //cout << num;
    return 0;
}

int main() {
    string s = "az";
    int k = 2;

    int sol = getLucky(s, k);
    //cout << sol;
    return 0;
}