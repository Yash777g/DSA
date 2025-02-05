#include <iostream>
#include <string>
using namespace std;

class Animal {
    public:
        void voice() {                      // first voice method becomes default if no other method is defined in child class then this method will be called.
            cout << "speaking" << endl;
        }
        
        void color(string c) {
            cout << c << endl;
        }
};

class Dog :public Animal {
    public:
        void voice() {                  // same method with same name arguements and return type is created.
            cout << "barking" << endl;  // at runtime it will be displayed over parent class method.
        }

        void age(int a) {
            cout << a << endl;
        }
};

int main() {
    Dog Pluto;

    Pluto.voice();
    Pluto.color("black");
    Pluto.age(11);

    return 0;
}