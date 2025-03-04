#include <iostream>
#include <vector>
using namespace std;

bool checkPowersOfThree(int n) {
    while(n > 1) {
        if(n % 3 == 2){
            return false;
        }
        n = n / 3;
    }
    return true;
}

int main() {
    cout << checkPowersOfThree(12);
    return 0;
} 