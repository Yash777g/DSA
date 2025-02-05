#include <iostream>
using namespace std;

class operations {
    private:
        int a = 0 ,b = 0;
    public:
        void prod(int a,int b);

        void sum(int a,int b) {
            cout << "Sum is:" << (a + b) << "\n";
        }
};

void operations :: prod(int a,int b) {
    cout << "Product is:" << (a * b);
}

int main() {
    operations ps;

    ps.sum(3,4);
    ps.prod(5,6);
    
    return 0;
}