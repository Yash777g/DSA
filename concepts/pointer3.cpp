#include<iostream>
using namespace std;

int main() {
    int value = 5;
    int *ptr = &value;
    int **ptr2 = &ptr;
    
    cout << value << "\t" << &value << endl;
    cout << *ptr << "\t" << ptr << "\t" << &ptr << endl;
    cout << *ptr2 << "\t" << ptr2 << "\t" << &ptr2 << endl;
    return 0;
}