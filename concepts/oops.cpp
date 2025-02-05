#include <iostream>
using namespace std;

class integers {
    private:
        char a;
    public:                                     // private members of class can be accessed by the members of class only.
        void setValue(int x, char name) {
            if(name = 'a') {                    // passcode if name is equal to a give access otherwise deny.
                a = x;
            }
        }
        void getvalue() {
            cout << a;
        }
};

int main() {                // static allocation
    integers a,b;
    
    a.setValue(9,'a');
    a.getvalue();
    
    cout << endl << sizeof(integers);
    return 0;
}