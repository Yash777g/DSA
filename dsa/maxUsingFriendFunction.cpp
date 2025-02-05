#include <iostream>
using namespace std;

class number2;
class number1;

class number1 {
    private:
        int number;
    public:
        number1(int number) : number(number) {}
        void max(number1 &obj1, number2 &obj2);
        
        void display() {
            cout << number;
        }
};

class number2 {
    private:
        int number;
    public:
        number2(int number) : number(number) {}
        friend void number1 :: max(number1&, number2&);
};

void number1 :: max(number1 &obj1, number2 &obj2) {
    cout << (obj1.number*(obj1.number > obj2.number) + obj2.number*(obj2.number > obj1.number));
    }

int main() {
    number1 n1(46);
    number2 n2(99999);

    n1.max(n1, n2);

    return 0;
}