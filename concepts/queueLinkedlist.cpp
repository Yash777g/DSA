#include <iostream>
using namespace std;

class list {
    public: 
        int data;
        list *next;

        list(int data) {
            this->data = data;
            this->next = nullptr;
        }
};

class queueList {
    public:
        list *front;
        list *rear;

        queueList() : front(nullptr), rear(nullptr) {}

        void push(int val);
        void pop();
        bool isEmpty();
        void frontOf();
        void rearOf();
};

void queueList :: push(int val) {
    list *newNode = new list(val);

    if(rear == nullptr) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

void queueList :: pop() {
    if(front == nullptr) {
        cout << "Stack underflow" << endl;
    }

    list *temp = front;
    front = front->next;

    if(front == nullptr) {
        rear = nullptr;
    }

    // popped element.
    int data = temp->data;
    delete temp;
}

bool queueList :: isEmpty() {
    return front == nullptr;
}

void queueList :: frontOf() {
    if(front == nullptr) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Front element is " << front->data << endl;
    }
}

void queueList :: rearOf() {
    if(rear == nullptr) {
        cout << "stack underflow" << endl;
    } else {
        cout << "Rear element is " << rear->data << endl;
    }
}

int main() {
    queueList q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.isEmpty() << endl;

    q.frontOf();
    q.rearOf();

    q.pop();
    q.frontOf();
    q.rearOf();

    q.pop();
    q.frontOf();
    q.rearOf();

    q.pop();
    q.frontOf();
    q.rearOf();

    q.pop();
    return 0;
}