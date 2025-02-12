#include <iostream>
#include <stack>
using namespace std;

// inbuilt function !!!
/*string removeOccurrences(string s, string part) {
        while(s.length()>0 && s.length()>s.find(part)){
           s.erase(s.find(part),part.length());
        }
        return s;
}*/
bool check(string s, string part, int m, int i){
    int j = 0;
    while(j < m){
        if(s[i] != part[j]){
            return false;
        }
        i++;j++;
    }
    return true;
}

string removeOccurrences(string s, string part) {
    string temp;
    int i = 0, count = 0;

    while(count != s.size()){
        i = 0, count = 0;

        while(i < s.size()){
            if(check(s, part, part.size(), i)){
                i += part.size();
                count--;
            } else{
                temp.push_back(s[i++]);
                count++;
            }   
        }
        s = temp;
        temp="";
    }
    return s;
}

int main() {
    cout << removeOccurrences("daabcbaabcbc", "abc");
    return 0;
}