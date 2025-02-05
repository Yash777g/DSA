#include <iostream>
#include <vector>
using namespace std;

int chalkReplacer(vector<int>& chalk, int k) {
    long long sum = 0;
    int index = 0;

    for (int i = 0; i < chalk.size(); i++) { sum += chalk[i]; }

    k = k % sum;

    for(int i = 0; i < chalk.size(); i++) {
        if(k >= 0) {
            k -= chalk[index];
            index++;
        }
        else { return index; }
    }

    return index;
}

int main() {
    vector<int> chalk = {};
    int k = 25;

    int sol = chalkReplacer(chalk, k);
    return 0;
}