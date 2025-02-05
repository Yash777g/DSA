#include<iostream>
#include<vector>
using namespace std;

void address(vector<int>& vec) {
    vector<int> *ptr = &vec;
    for(int i = 0; i < vec.size(); i++) 
        cout << &vec[i] << " ";

    cout << endl;

    for(int i = 0; i < vec.size(); i++) 
        cout << ptr++ << " ";

    cout << endl << ptr;
}

void addRess(int num) {
    int *ptr = &num;
    cout << num << " " << &num << endl;
    cout << ptr << " " << *ptr << " " << &ptr;
}

int main() {
    vector<int> vec {2,1,4,5,3};
    int num = 5;
    
    address(vec);
    addRess(num);
    return 0;
}