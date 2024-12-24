#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

void solve(vector<string>& result, string output, int index, string digits) {
    
    string mapping[10] = {" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    if(index >= digits.size()) {
        result.push_back(output);
        return ;
    }
    
    int number = digits[index]- '0';
    string value = mapping[number];
    
    for(int i = 0; i < value.size(); i++) {
        output.push_back(value[i]);
        solve(result, output, index+1, digits);
        //backtracking by removing old elements by new elements.
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> result;
    string output = "";
    
    int index = 0;
    solve(result, output, index, digits);
    return result;
}

int main() {
    string digits = "23";
    vector<string> answer = letterCombinations(digits);
    
    for(int i = 0; i < answer.size(); i++) 
        cout << answer[i] << " ";
    return 0;
}