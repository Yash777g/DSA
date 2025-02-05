// array implementation
#include <iostream>
using namespace std;

class Stack {
    public:
        int *arr;
        int size;
        int top;

    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int val);
    void pop();
    void peek();
    bool isEmpty();
};

void Stack :: push(int val) {
    if(size - top > 1) {
        arr[++top] = val;
    } else {
        cout << "Stack overflow." << endl;
    }
}

void Stack :: pop() {
    if(top >= 0) {
        cout << "Popped: " << arr[top--] << endl;
    } else {
        cout << "Stack underflow." << endl;
    }
}

void Stack ::  peek() {
    if(top >= 0) {
        cout << "Top is: " << arr[top] << endl;
    } else {
        cout << "Stack is empty." << endl;
    }
}

bool Stack :: isEmpty() {
    if(top == -1) {
        return true;
    } 
    return false;
}

int main() {
    Stack array(5);

    cout << boolalpha << array.isEmpty() << endl;
    array.push(1);
    array.push(2);
    array.push(3);
    array.push(4);
    array.push(5);
    array.peek();

    cout << boolalpha << array.isEmpty() << endl;
    array.pop();
    array.peek();
    return 0;
}