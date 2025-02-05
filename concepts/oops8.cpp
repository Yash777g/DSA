#include <iostream>
using namespace std;

class MyClass {
public:
    MyClass(int x) : myVar(x) {} // Constructor

    int getValue() const { return myVar; } // Const member function

    // Non-const member function
    void setValue(int newVal) {
        myVar = newVal; // Compilation error if myVar is const
    }

private:
    int myVar; // Non-const member variable
};

int main() {
    MyClass obj(5);
    std::cout << obj.getValue() << std::endl; // Accessing const member function
    // obj.setValue(10); // This line would cause a compilation error
    return 0;
}
