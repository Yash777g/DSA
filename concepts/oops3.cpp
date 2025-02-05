#include <iostream>
using namespace std;

class data1 {
    private:
        int a;
    public:
        void setdata(int x) {
            a = x;
        }
        data1() {                   // default constructor always gets created.
            cout << "constructor called";
        }
        void getdata() {
            cout << a;
        }
};

int main() {
    data1 a;            // default constructor called at the object initialization.
    cout << endl << "flow of constructor" << endl;
    a.setdata(5);
    a.getdata();
    return 0;
}