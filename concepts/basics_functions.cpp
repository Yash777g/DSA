#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int a = 6 ,b = 4;
    vector<int> nums {1,2,3,4,5};

    if(a > b) 
        swap(a,b);

    cout << "a is:" << a << endl << "b is:" << b << endl;
    cout << *max_element(nums.begin(), nums.end()) << endl;
    cout << *min_element(nums.begin(), nums.end()) << endl;
    return 0;
}