#include <iostream>
using namespace std;

class shop {
    private:
        int id[5] = {0} ,price[5] = {0} ,cnt = 0;
    public:
        void entry(void);
        void display(void);
};

void shop :: entry(void) {
        cout << "Enter the item id:";
        cin >> id[cnt];
        cout << "Enter the item price:";
        cin >> price[cnt];
        cnt++;
}

void shop :: display(void) {
    for(int i = 0 ;i < cnt ;i++) {
        cout << "item id:" << id[i] << "\n";
        cout << "price is:" << price[i] << "\n";
    }   
}

int main() {
    int n = 0;
    shop dukan;

    cout << "Enter no of entries:";
    cin >> n;

    for(int i = 0 ;i < n ;i++) {
        dukan.entry();
    }
    
    dukan.display();
    return 0;
}