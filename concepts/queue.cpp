#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    // stl queue
    queue<int> arr;

    arr.push(5);
    arr.push(2);
    arr.push(3);

    cout << arr.front() << endl;
    cout << arr.back() << endl;

    arr.pop();
    arr.pop();

    cout << arr.front() << endl;
    cout << arr.back() << endl;
    
    return 0;
}