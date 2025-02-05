#include<iostream>
using namespace std;

class complex {
    private:
        int real, img;
    public:
        // default constructor
        complex() { 
            real = 0;
            img = 0;
        }

        // parameterized constructors initialization
        complex(int value);
        complex(int Real,int Img);

        void display() {
            cout << "The complex no:" << real << " + " << img << "i" << endl;
        }
};

// parameterized constructors declaration
complex :: complex (int value) {
    real = img = value;
}

complex :: complex(int Real, int Img) {
    real = Real;
    img = Img;
}

int main() {
    complex c1(5), c2(3,4), c3;
    
    c1.display();
    c2.display();
    c3.display();

    return 0;
}
