#include <iostream>
#include <vector>
using namespace std;

int mySqrt(int x) {
    if(x <= 1) 
        return x;

    long start = 1, end = x / 2;
    long mid = start + (end - start)/2;

    while(start <= end) {
        
        if(mid*mid == x) 
            return mid;
        
        else if((mid*mid) > x) 
            end = mid - 1;
    
        else 
            start = mid + 1;
            
        mid = start + (end - start)/2;
    }
    return mid - 1;
}

int main() {
    int x = 2147395599, ans = mySqrt(x);
    cout << ans;
    return 0;
}