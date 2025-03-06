#include <iostream>
using namespace std;

/*long long coloredCells(int n) {
    if(n == 1) {
        return n;
    }

    long long ans = 1;
    long long add = 4;
    for(int i = 1; i < n; i++) {
        ans += add;
        add += 4;
    }

    return ans;
}*/

long long coloredCells(int n) {
    return 2*n*(n-1) + 1;
}

int main() {
    cout << coloredCells(5);
    return 0;
}