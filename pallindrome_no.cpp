#include<iostream>
using namespace std;

bool isPalindrome(int x) {
    int temp = x, rev = 0;
    if(x < 0) 
        return false;
        
    else { 
        while(x != 0) {
            rev = x%10 + (rev*10);
            x = x/10;
        }
    }

    if(rev != temp)
        return false; 
        
    return true;
}

int main() {
    int x = 121;
    bool ans = isPalindrome(x);
    
    cout << ans;
    return 0;
}