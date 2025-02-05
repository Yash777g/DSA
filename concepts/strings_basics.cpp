#include <iostream>
#include <string.h>
using namespace std;

int main() {
    string name;
    char gender[6] = {0} ,sport[100] = {0};

    cout << "Enter:";
    cin >> name;
    cin >> gender;
    cin >> sport;

    sport[3]='\0';
    cout << "Name is:" << name << endl;
    cout << "Gender:" << gender << endl;
    cout << "Sport:"<< sport << endl;
    cout << (name + sport);
    
    return 0;
}