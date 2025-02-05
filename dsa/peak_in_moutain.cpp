#include<iostream>
#include<vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int start = 0, end = arr.size() -1, index = 0;

    for(int i = 1; i < arr.size()-1; i++) {
        int mid = start + (end-start / 2);

        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {
            index = i;
            break;
        }
        
        else if(arr[mid] < arr[mid]+1) 
            start = mid + 1;

        else 
            end = mid;
    }

    return index-1;
}

int main() {
    vector<int> arr {0,10,15,20,5,3};
    int ans;

    ans = peakIndexInMountainArray(arr);
    cout << ans;
    return 0;
}