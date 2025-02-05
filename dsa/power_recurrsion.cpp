#include <iostream>
using namespace std;

int power(int num, int pow) {
    if (pow == 0) 
        return 1;

    else {
        return num * power(num, pow - 1);
    }
}

int main() {
    int num = 3, pow = 4;

    int ans = power(num, pow);
    cout << ans;
    return 0;
}