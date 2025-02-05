#include <iostream>
using namespace std;

class Maths {
    public:
        int a = 0;
        int b = 0;

        void operator+ (Maths &obj) {
            int value = this->a;
            int value1 = obj.a;
            cout << value - value1 << " Operator overloading." << endl;
        }
};

class Vector {          // class vector.
    public:
        int x = 0;
        int y = 0;

        Vector(int a, int b) {      // constructor 
            this->x = a;
            this->y = b;
        }

        Vector operator+ (Vector &obj) {        // + operator overloaded to add 2 vector components in x and y direction.
            return Vector(x + obj.x ,y + obj.y);
        }

        Vector operator- (Vector &obj) {        // - operator overloaded to subtract 2 vector components in x and y direction.
            return Vector(x - obj.x ,y - obj.y);
        }
};

int main() {
    Maths A ,B;

    A.a = 41031;
    B.a = 4;
    A + B;

    Vector v1(3,4) ,v2(6,8);
    Vector v3 = v1 + v2;
    Vector v4 = v2 - v1;

    cout << "(" << v3.x << "," << v3.y << ")" << endl;    
    cout << "(" << v4.x << "," << v4.y << ")";
    return 0;
}