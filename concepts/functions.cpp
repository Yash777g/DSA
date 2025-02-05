#include <iostream>
using namespace std;

void insert(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "Enter the elements in array: ";
        cin >> arr[i];
    }
}

void print(int arr[], int n) {
    cout << "Elements in array: ";

    for(int i = 0; i < n; i++) 
        cout << arr[i] << " ";
}

int main() {
    int n = 3, arr[10] = {0};

    insert(arr, n);
    print(arr, n);
    return 0;
}