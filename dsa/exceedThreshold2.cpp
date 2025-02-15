#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int minOperations(vector<int>& nums, int k) {
    priority_queue<long long int, vector<int>, greater<int>> minHeap;
    int steps = 0;

    long long int num1 = 0, num2 = 0;
    for(auto i : nums) {
        minHeap.push(i);
    }    

    while(num1 < k) {
        num1 = minHeap.top();
        minHeap.pop();
        num2 = minHeap.top();
        minHeap.pop();

        long long int fn = (num1*2) + num2;
        minHeap.push(fn);
        steps++;
    }
    return steps-1;
}

int main() {
    vector<int> nums = {1,1,2,4,9};
    cout << minOperations(nums, 20);
    return 0;
}
