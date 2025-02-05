#include <iostream>
#include <string>
using namespace std;

class Animal {  // parent/super/base class.
    private:
        string category;

    public:
        string color;
        string voice;
    
        void setColor(string s) {
            this->color = s;
        }
        void setVoice(string v) {
            this->voice = v;
        }
        
};

class Dogs: public Animal {     // child/derived/sub class.     It is an example of single inheritance.
    public:
        int age;

        void setAge(int a) {
            this->age = a;
        }
};

int main() {
    Dogs Pug;       // object vreated of child/derived class.

    Pug.setColor("black");
    Pug.setVoice("bark");
    Pug.setAge(8);

    //Pug.category("Mammal");    // private members cant be accessed through any medium (access modifier).

    cout << Pug.color << endl;
    cout << Pug.voice << endl;
    cout << Pug.age << endl;
    return 0;
}