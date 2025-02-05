#include<iostream>
using namespace std;

int fibonacci(int n, int a, int b) {
    int sum = 0;

    if(n != 0) {
        sum = a + b;
        cout << sum << endl;
        fibonacci(n - 1, b, sum);
    }
    
    return 0;
}

int main() {
    int n = 9, a = 0, b = 1;

    cout << "0" <<endl << "1" << endl;
    fibonacci(n, a, b);
    return 0;
}