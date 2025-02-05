#include <iostream>
#include <vector>
using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> result;
    int max = 0;

    for(int i = 0; i < candies.size(); i++) {
        if(max < candies[i]) 
            max = candies[i];
    }

    for(int i = 0; i < candies.size(); i++) {
        if(candies[i] + extraCandies >= max) {
            result.push_back(true);
        } else {
            result.push_back(false);
        }
    }

    return result;
}

int main() {
    vector<int> candies = {2,3,5,1,2};
    int extraCandies = 3;

    vector<bool> res = kidsWithCandies(candies, extraCandies);
    for(const auto &i : res) {
        cout << i << " ";
    }
    return 0;
}
