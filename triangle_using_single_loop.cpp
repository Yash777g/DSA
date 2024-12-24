#include <iostream>
using namespace std;

void triangle(int num) {
    int cnt = 0 ,sum = 0 ,a = 1;

    for(int i = 0 ;i < (num * (num + 1))/2 ;i++) {
        sum = i;
        cnt = (a * (a + 1))/2;

        if(sum == cnt) {
            a++;
            cout << endl;
        }
        cout << i + 1 <<" ";
    }
}

void triangleStar(int num) {
    int cnt = 0 ,sum = 0 ,a = 1;

    for(int i = 0 ;i < (num * (num + 1))/2 ;i++) {
        sum = i;
        cnt = (a * (a + 1))/2;

        if(sum == cnt) {
            a++;
            cout << endl;
        }
        cout << "*" << " ";
    }
}

int main() {
    int num = 5;
    triangle(num);
    
    cout << endl;
    triangleStar(num);
    return 0;
}