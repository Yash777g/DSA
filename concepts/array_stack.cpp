#include <iostream>
#include <vector>
using namespace std;

void push(vector<int> &nums, int value, int &top) {
    top++;
    nums.push_back(value); 
}

void pop(vector<int> &nums, int &top) {
    if(top >= 0) {
        nums[top] = 0;
        top--;
    }
    
    else { cout << "Stack is empty !!!!" << endl; }
}

void display(vector<int> &nums, int &top) {
    if(top < 0) { cout << "Stack is empty !!!!"; }
    
    for(int i = top; i >=0; i--) {
        cout << nums[i] << "\n";
    }
    
    cout << "\n";
}

int main() {
    vector<int> nums;
    int top = -1;

    push(nums, 5, top);
    push(nums, 10, top);
    push(nums, 15, top);
    push(nums, 20, top);

    display(nums, top);

    pop(nums, top);
    display(nums, top);
    return 0;
}