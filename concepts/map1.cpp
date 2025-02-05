#include <iostream>
#include <string.h>
#include <unordered_map>
using namespace std;

int main() {
    string s = "abdcebdc";
    unordered_map<char, int> count;
    
    for(int i = 0; i < s.size(); i++) 
        count[s[i]]++;
 
    for(auto &i: count) 
        cout << "key is: " << "(" << i.first << "," << i.second << ")" << endl;
    
    return 0;
}