#include <iostream> 
using namespace std;

class data1 {
    private:
        int a;
        int b;
    public: 
        data1() {               // default constructor developed.
            cout << "default constructor initiated." << endl;
        }

        data1(int a, int b) {       // parameterized constructor.
            this->a = a;
            this->b = b;
        }

        /*data1(data1& temp) {    // copy constructor and passed through reference as passed by value gives error.
            this->a = a;
            this->b = b;
        }*/                 // pass by value created a infinte calling loop between constructor and object.

        void sum() {
            cout << a+b << endl;
        }
};

int main() {
    data1 first;
    data1 second(5,6);
    second.sum();
    data1 third(second);    // copy constructor called automatically when second object is given as a paramter to third object.
    third.sum();
    return 0;
}