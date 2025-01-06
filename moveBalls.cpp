#include <iostream>
#include <vector>
using namespace std;

vector<int> minOperations(string boxes) {
    vector<int> prefix(boxes.size(), 0);
    int box = 0, moves = 0;
    for(int i = 0; i < boxes.size(); i++) {
        prefix[i] = box + moves;
        if(boxes[i] == '1') {
            box += 1;
        } moves = prefix[i];
    }

    vector<int> suffix(boxes.size(), 0);
    box = 0, moves = 0;
    for(int i = boxes.size()-1; i >=0; i--) {
        suffix[i] = box + moves;
        if(boxes[i] == '1') {
            box += 1;
        } moves = suffix[i];
    }

    for(int i = 0,j = 0; i < boxes.size(); i++) {
        prefix[i] += suffix[j++];
    }
    return prefix;
}

int main() {
    vector<int> result = minOperations("001011");
    for(auto &i : result) {
        cout << i << " ";
    } 
    return 0;
}