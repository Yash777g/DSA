#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*string reverseWords(string s) {
    vector<string> stack;
    string temp = "";
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') {
            if(temp != "") {
                stack.push_back(temp);
                temp = "";
            }
        } else {
            temp += s[i];
        }
    } if(temp != "") {
        stack.push_back(temp);    
    } s = "";
    for(int i = stack.size() - 1; i >= 0; i--) {
        s.append(stack[i]);
        s += " ";
    }
    s.pop_back();
    return s;
}*/

string reverseWords(string s) {
    string reversed = "";
    reverse(s.begin(), s.end());

    for(int i = 0; i < s.size(); i++) {
        string word = "";
        while(s[i] = ' ' && i < s.size()) {
            word += s[i];
            i++;
        } 
        reverse(word.begin(), word.end());
        if(word.size() > 0) {
            reversed += " " + word;
        }
    }
    return reversed.substr(1);
}

int main() {
    string str = "  hello world  ";
    cout << reverseWords(str);
    return 0;
}