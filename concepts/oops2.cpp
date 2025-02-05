#include <iostream>
using namespace std;

class data1 {
    private:
        int a;
    public:
        void setdata (int x) {
            a = x;
        }
        void getdata () {
            cout << a;
        }
};

int main () {
    data1 *first = new data1;     // dynamic allocation 
    // here first stores the address and *first values.
    first->setdata(5);              // arrow operator works same as dot operator 
    first->getdata();

    cout << endl;
    // second approach
    (*first).setdata(7);
    (*first).getdata();

    // after use deleting the pointer.
    delete first;
    cout << endl;
    first->getdata(); // gets a garbage value now for first variable no longer a pointer.
    return 0;
}