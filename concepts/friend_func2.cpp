#include<iostream>
using namespace std;

class calculator;
class integer;

class integer {
    private:
        int a, b;
        friend class calculator;
    public:
        void setdata(int x, int y);
};  

void integer :: setdata(int x, int y) {
    a = x;
    b = y;
    cout << "Value of a:" << a << endl;
    cout << "Value of b:" << b << endl;
}

class calculator {
    public:
        void sum(int a, int b) {
            cout << "Sum is:" << a + b;
        }

        void choice(int ch, integer &obj) {
            switch(ch) {
                case 1:
                    cout << "sum -> " << obj.a + obj.b << endl;
                    break;
                case 2:
                    cout << "difference -> " << obj.a - obj.b << endl;
                    break;
                case 3:
                    cout << "multiplication -> " << obj.a * obj.b << endl;
                    break;
                case 4:
                    cout << "division -> " << obj.a / obj.b << endl;
                    break;
                default:
                    cout << "Have a nice day !!!!" << endl;
            }   
        }
};

int main() {
    integer obj;
    calculator obj1;

    obj.setdata(4,5);
    obj1.choice(1,obj);
    obj1.choice(2,obj);
    obj1.choice(3,obj);
    obj1.choice(4,obj);
    obj1.choice(6,obj);

    return 0;
}