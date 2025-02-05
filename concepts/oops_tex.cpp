#include<iostream>
#include<string>
using namespace std;

class human{
    private:        
        int height;
        string skin_colour;
    public:
    // human(int Height, string Skin_colour);

    /* human(int Height, string Skin_colour) {     
        height = Height;
        skin_colour = Skin_colour;
    }*/

    // human() { }          //default constructor made by programmer.
    //                     //if no constructor is defined ,compiler provides a default constructor by itself like the given beside. 

    human(int height, string skin_colour) : height{height}, skin_colour{skin_colour} {}

    human () {}

    human(human &obj) {
        height=obj.height;
    }

    void display();

    void set_height() {
        int lamba;
        cout << "Enter height:";
        cin >> lamba;
        height = lamba;
    }

    void get_height() {
        cout << height;
    }
};

void human::display() {
       get_height();
    }

/*human :: human(int Height ,string Skin_colour) {
    height = Height;
   skin_colour = Skin_colour;
}*/

int main() {
    human asian1(180, "milky white");
    human asian2(asian1);
    asian2.get_height();
    // human nigga;
    // nigga.set_height();
    // nigga.get_height();
    // nigga.display();
    // asian.display();
    return 0;
}