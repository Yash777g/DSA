#include <iostream>
#include <vector>
using namespace std;

vector<int> simpleSieve(int n) {
    vector<bool> prime(n+1, true);
    vector<int> primeNo;

    for(int i = 2; i <= n; i++) {
        if(prime[i] == true) {
            for(int j = i*2; j <= n; j = j+i) {
                prime[j] = false;
            }
        }
    }
n
    for(int i = 2; i <= n; i++) {
        if(prime[i] == true) {
            primeNo.push_back(i);
        }
    }

    return primeNo;
}

int main() {
    int n = 200;
    vector<int> ans = simpleSieve(n);

    for(auto i: ans) {
        cout << i << " ";
    }
    return 0;
}