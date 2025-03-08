#include <iostream>
#include <vector>
using namespace std;

vector<int> closestPrimes(int left, int right) {
    if (right - left < 1) return {-1, -1};

    vector<bool> prime(right + 1, true);
    vector<int> primeNo;
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= right; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= right; j += i) {
                prime[j] = false;
            }
        }
    }

    for (int i = left; i <= right; i++) {
        if (prime[i]) {
            primeNo.push_back(i);
        }
    }

    if (primeNo.size() < 2) return {-1, -1};

    int minDiff = INT32_MAX;
    int first = -1, second = -1;
    for (int i = 0; i < primeNo.size() - 1; i++) {
        int diff = primeNo[i + 1] - primeNo[i];
        if (diff < minDiff) {
            minDiff = diff;
            first = primeNo[i];
            second = primeNo[i + 1];
        }
    }

    return {first, second};
}

int main() {
    vector<int> ans = closestPrimes(10, 19);
    return 0;
}