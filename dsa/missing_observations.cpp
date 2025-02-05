#include <iostream>
#include <vector>
using namespace std;

vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int m = rolls.size(), sum = 0;

    for(int i = 0; i < m; i++) { sum += rolls[i]; }
    
    int remSum = (mean * (n + m)) - sum;  

    if(remSum > 6*n || remSum < n) { return {}; }

    int avgValue = remSum / n;
    int mod = remSum % n; 
    vector<int> result (n, avgValue);

    for(int i = 0; i < mod ; i++) {
        result[i] += 1;
    }
    
    return result;
}

int main() {
    vector<int> rolls = {1,5,6};
    int mean = 3, n = 4;

    vector<int> sol = missingRolls(rolls, mean, n);

    for(auto &i : sol) {
        cout << i << " ";
    }
    
    return 0;
}
