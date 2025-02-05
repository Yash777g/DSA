#include <iostream>
#include <string>
using namespace std;

class Human {
    private:
        int age;    // private members cant be accessed by any other class than itself.
    
    public:
        int height;
        int weight;
    
        void setHeight(int h) {
            this->height = h;
        }
        void setWeight(int w) {
            this->weight = w;
        }
        void setAge(int a) {
            this->age = a;
        }

        void getAge() {         // private members can be only accessed by setter and getter methods only inside the class.
            cout << age;        
        }
};

class Male: protected  Human {      // now public members of parent class are protected members for male class.
    public:
        string Name;

        void setName(string n) {
            this->Name = n;
        }
};

class Female: private  Human {      // now public members of parent class are private members for female class.
    public:
        string Name;

        void setName(string n) {
            this->Name = n;
        }
};

int main() {
    Male obj1;
    Female obj2;
    
    // obj1.setHeight(171);   // protected members can be accessed inside class and child class not outside them.
    // obj2.setAge(20);     // private members can be only accessed inside class but not outside the class.
    return 0;
}