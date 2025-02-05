#include <iostream>
using namespace std;

class data1 {
    private:
        int a;
        static int b;
    public:
        data1(int x) {
            a = x;
        }
        void printAddition() {          // normal function can access both static and other members of the class.
            cout << a+b << endl;
        }
        static void change(int x) {     // static functions can only operate static data members not any public ,private or protected data of the class. 
            b = x;
        }
};

int data1::b = 2;     // static data members are initialized by the name of class as objects have no relation with the static member it remains constant for whole class.   

int main() {
    data1 first(5);
    first.printAddition();
    first.change(1);
    first.printAddition();
    return 0;
}