#include<iostream>
using namespace std;

class num1;
class num2;

class num1 {
    private:
        int num;
    public:
        void insert_value(int value) {
            num = value;
        }
        
        void display() {
            cout << "The number1 is:" << num << endl;
        }

        void max(num1 &obj1, num2 &obj2);
};

class num2 {
    private:
        int num;
    public:
        void insert_value(int value) {
            num = value;
        }

        void display() {
            cout << "The number2 is:" << num << endl;
        }

        friend void num1::max(num1 &obj1, num2 &obj2);
};

void num1 :: max(num1 &obj1, num2 &obj2) {
    
    if(obj1.num > obj2.num) 
        cout << "Greatest number is: " << obj1.num;
    else
        cout << "Greatest number is: " << obj2.num;
}

int main() {
    num1 a;
    num2 b;
    
    a.insert_value(49);
    b.insert_value(130);
    
    a.display();
    b.display();
    
    a.max(a,b);
    return 0;
}