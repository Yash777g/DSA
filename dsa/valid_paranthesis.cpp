#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> result;

    for(char ch : s){
        if(ch == '(' || ch == '{' || ch == '[') { result.push(ch); }
            
        else if(result.empty()) { return false; }
        
        else if(result.top() == '(' && ch == ')') { result.pop(); }
            
        else if(result.top() == '{' && ch == '}') { result.pop(); }
            
        else if(result.top() == '[' && ch == ']') { result.pop(); }
        
        else{ return false; }
    }
    
    return result.empty();
}

int main() {
    string s = "()";

    bool sol = isValid(s);
    cout << sol;
    return 0;
}