#include<iostream>
#include<vector>
using namespace std;

void linear_search(vector<int> &arr, int key) {
    int cnt = 0;

    for(int i = 0; i < arr.size(); i++) {
        if(key == arr[i]) {
            cout << "Element found at index: " << i;
            cnt++;
        }
    }
    
    if(cnt == 0) 
        cout << "Element not found!!!";
}

int main() {
    vector<int> arr {2,1,4,5,3};
    int key = 3;

    linear_search(arr, key);
    return 0;
}