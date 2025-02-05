#include <iostream>
using namespace std;

class data1 {
    private:
        int a;
        int b;
    public:
        data1(int x) {
            cout << this << endl;       // this pointer saves the address of the current object initialized / the object through which the constructor is called.
        }
        data1(int a, int b) {
            //a = a;                      // poor practice as it will check for the scope and compiler gets confused which a and b are considered. 
            //b = b;

            this->a = a;                // this pointer tells a of class data1 and object second is equal to a and b given to constructor.
            this->b = b;    
            cout << endl << a+b;
        }
};

int main() {
    data1 first(5);     // parameterized constructor.
    cout << &first;
    data1 second(5,6); 
    // data1 third;         // gives error as default constructor is erased as soon as parameterized constructor are developed in a program.
    return 0;
}