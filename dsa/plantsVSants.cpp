#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int>& ants, int n) {
    int cnt = 0;
    while (true) {
        vector<int> temp;
        temp.push_back(ants[0]);
        
        for (int i = 1; i < ants.size(); i++) {
            if (ants[i - 1] >= ants[i]) {
                temp.push_back(ants[i]);
            }
        }
        
        if (temp.size() == ants.size()) {
            break; // Stop when no changes occur
        }
        
        ants = temp;
        cnt++;
    }
    
    return cnt;
}


int main() {
    int n;
    cin >> n;
    vector<int> ants(n);
    
    for (int i = 0; i < n; i++) {
        cin >> ants[i];
    }

   cout << solve(ants, n);
    return 0;
}
