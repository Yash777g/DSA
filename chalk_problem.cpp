#include <iostream>
#include <vector>
using namespace std;

int chalkReplacer(vector<int>& chalk, int k) {
        long sum = 0;
        int index = 0;

        for (int i = 0; i < chalk.size(); i++) {
            sum += chalk[i];
        }

        k = k % sum;

        while (k > 0) {
            if (chalk[index] < k) {
                k -= chalk[index];
                index++;
            }

            else {
                k -= chalk[index];
            }
        }

        return index;
    }

int main() {
    vector<int> chalk = {};
    int k = 25;

    int sol = chalkReplacer(chalk, k);
    return 0;
}