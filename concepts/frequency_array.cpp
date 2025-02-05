#include<iostream>
#include<vector>
using namespace std;

int sumOfUnique(vector<int> &nums) {
    vector<int> freq = {0};
    int sum = 0;

    for(int &i : nums) {          // i as a function of values of nums vector ex: 1 is i next 2 is next 3 is i next 2 is i;
        freq[i]++;
        
        if(freq[i] == 1) 
            sum += i;
            
        else if(freq[i] == 2)
            sum -= i;
    }

    return sum;
}

int main() {
    vector<int> nums {1,2,3,2};
    int ans = 0;

    ans = sumOfUnique(nums);
    cout << ans;
    return 0;
}