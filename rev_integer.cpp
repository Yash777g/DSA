#include <iostream>
using namespace std;

int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            if (rev > INT32_MAX / 10 || rev < INT32_MIN / 10) {
                return 0;
            }
            rev = x % 10 + (rev * 10);
            x = x / 10;
        }
        return rev;
    }

int main() {
    int x = 123;

    int sol = reverse(x);
    cout << sol;
    return 0;
}