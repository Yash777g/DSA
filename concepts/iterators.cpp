#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

int main() {
    std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7};

    // array or vector iterator
    for(auto it = v1.begin(); it != v1.end(); it++) {
        cout << *it << " ";
    }cout << endl;

    std::unordered_map<int, int> hash = {{1,2}, {3,5}, {6,9}, {4,2}};
    // map iterator
    for(auto it = hash.begin(); it != hash.end(); it++) {
        cout << it->first << " - " << it->second << endl;
    }

    set<int> values = {7,5,3,2,5,4,1};
    // set iterator
    for(auto it = values.begin(); it != values.end(); it++) {
        cout << *it << " ";
    }cout << endl;
    return 0;
}