#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr, int start, int end) {
    int mid = start + (end - start) / 2;
    int len1 = mid - start + 1; 
    int len2 = end - mid;

    vector<int> nums1(len1, 0);
    vector<int> nums2(len2, 0);
    
    int mainIndex = start;
    for(int i = 0; i < len1; i++) {
        nums1[i] = arr[mainIndex++];
    }
    mainIndex = mid + 1;
    for (int i = 0; i < len2; i++) {
        nums2[i] = arr[mainIndex++];
    }
    
    int index1 = 0, index2 = 0, index = start;
    while(index1 < len1 && index2 < len2) {
        if(nums1[index1] > nums2[index2]) {
            arr[index++] = nums2[index2++];
        }
        else {
            arr[index++] = nums1[index1++];
        }
    }
    while(index1 < len1) {
        arr[index++] = nums1[index1++];
    }
    while(index2 < len2) {
        arr[index++] = nums2[index2++];
    }
}


void mergeSort(vector<int>& arr,int start,int end) {
    if(start >= end) 
        return;
    
    int mid = start + (end-start) / 2;
    
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, end);
}

int main() {
    vector<int> arr {993, -987, -964, -948, -925, -896, -895, 883, -804, -765, -704, -676, 640, -616, -564, -517, 506, -326, 20};
    
    int n = arr.size();
    mergeSort(arr, 0, n-1);
    
    for(int i = 0; i < n; i++)
        std :: cout << arr[i] << " ";
    
    std :: cout << endl;

    return 0;
}