#include <iostream>
#define pi 22/7
using namespace std;

class Maths {
    public:
        //int data;

        void area(int side) {                                           // method/function overloading.
            cout << "Area of square : " << side* side << endl;
        }
        
        void area(double radius) {                                              // area function is overloaded to three different forms.
            cout << "Area of circle : " << radius*radius*pi << endl;    
        }

        void area(int lenght, int breadth) {                                       // only paramters change allow method overloading.
            cout << "Area of rectangle : " << lenght*breadth << endl;   
        }
        
        /*void square(int base, int height) {
            cout << 0.5*base*height << endl;
        }*/
};

int main() {
    Maths Square;
    Maths Circle;
    Maths Rectangle;
    //Maths Triangle;

    Square.area(5);
    Circle.area(7.0);
    Rectangle.area(4,5);
    //Triangle.square(4,5);

    return 0;
}