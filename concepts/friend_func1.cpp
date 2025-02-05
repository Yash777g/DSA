#include<iostream>
using namespace std;

class square {
    private:
        int a;
    public:
        // constructor initialization and declaration
        square(int a) : a(a) {}

        void area(square& obj) {
            cout << "Area of square of side " << obj.a << " is " << (obj.a * obj.a) << "\n";
        }

        friend void peri(square&);
        
};

void peri(square &obj) {
    cout << "Perimeter of square of side "<< obj.a << " is " << (4*obj.a) << "\n";
}

int main() {
    square ab(5);
    ab.area(ab);
    peri(ab);

    return 0;
}