// shallow and deep copy (copy constructor).
#include <iostream>
#include <string.h>
using namespace std;

class data1 {
    private:
        int a;
        int b;
        
    public:
        data1() {} // default constructor.

        char operation[10];
        data1(int x,int y,char operation[10]) {
            a = x;
            b = y;
            strcpy(this->operation,operation);
        }
        void sum() {
            cout << "sum is:" << a+b << endl;
            cout << "operation is:" << operation << endl;
        }

        ~data1() {
            cout << "destructor called" << endl;
        } // destructor called for statically created objects automatically.
};

int main() {
    char operation[10] = "sum";
    data1 first(3, 4, operation);
    first.sum();
  
    data1 second(first);        // default copy constrcutor.
    second.sum();

    cout << endl;
    // deep copy concept
    first.operation[0] = 'd';       // changes made in first object doesnt reflect in second object.
    first.sum();
    second.sum();

    cout << endl;
    // copy assignment constructor
    first = second;
    first.sum();
    second.sum();

    cout << endl;
    data1 *third = new data1(); // destructor is called manually for the objects created by reference.
    delete third;
    return 0;
}