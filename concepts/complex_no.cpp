#include <iostream>
using namespace std;

class complex {
    private:
        int a = 0, b = 0;
    public:
        void value(int v1, int v2) {
            a = v1;
            b = v2;
        }

        void sum(complex o1, complex o2);
        void diff(complex o1, complex o2);

        void output(void) {
            cout << "complex is:" << a << "+" << b << "i" << endl;
        }
};

void complex::sum(complex o1, complex o2) {
    a = o1.a + o2.a;
    b = o1.b + o2.b;
}

void complex::diff(complex o1, complex o2) {
    a = o1.a - o2.a;
    b = o1.b - o2.b;
}

int main() {
    complex c1, c2, c3, c4;

    c1.value(1,2);
    c1.output();

    c2.value(3,4);
    c2.output();

    c3.sum(c1,c2);
    c3.output();
    
    c4.diff(c1,c2);
    c4.output();
    return 0;
}