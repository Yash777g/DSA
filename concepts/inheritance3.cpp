#include <iostream>
#include <string>
using namespace std;

class Animals {
    public:
        string kingdom;

        void setKingdom(string k) {
            this->kingdom = k;
        }
};

class Pets: public Animals {    // single inheritance
    public:
        string color;

        void setColor(string c) {
            this->color = c;
        }
};

class Dogs: public Animals {    // multiple inheritance
    public:
        string voice;
        
        void setVoice(string v) {
            this->voice = v;
        }
};

class Labrador: public Dogs  ,public Pets {       // multilevel inheritance
    public:
        int age;

        void setAge(int a) {
            this->age = a;
        }
};

int main() {
    Labrador obj1;
    Pets obj2;

    obj2.setColor("Black");
    obj1.Pets::setColor("Black");  // it leads to inheritance ambiguity.  
    obj1.Animals::setKingdom("Mammal");
    obj1.setAge(10);
    obj1.setVoice("Bark");


    // cout << obj1.kingdom << endl;
    cout << obj2.color << endl;
    cout << obj1.age << endl;
    cout << obj1.voice << endl;

    return 0;
}