#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*vector<string> stringMatching(vector<string>& words) {
    vector<string> result;
    for(int i = 0; i < words.size() - 1; i++) {
        for(int j = i+1; j < words.size(); j++) {
            if (i != j && words[j].find(words[i]) != string::npos) {
                result.push_back(words[i]);
                break;
            }
        }
    }
    
    return result;
}*/

vector<string> stringMatching(vector<string>& words) {
    
}

int main() {
    vector<string> words = {"mass","as","superhero","hero"};    
    vector<string> ans = stringMatching(words);
    return 0;
}