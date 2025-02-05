#include <iostream>
using namespace std;

// array implementation of queue.
class queueArrays {
    public:
        int que[1001];
        int front = 0, rear = 0;

        void push(int data) {
            que[rear] = data;
            rear++;
        }

        void pop() {
            if(front == rear) {
                cout << "queue is empty." << endl;
                front = 0;
                rear = 0;
            }

            que[front] = -1;
            front++;
        }

        int sizeOf();
        void frontOf();
        void rearOf();
        bool isEmpty();
};

int queueArrays :: sizeOf() {
    int size = 0;
    for(int i = front; i < rear; i++) {
        size++;
    } return size;
}

void queueArrays :: frontOf() {
    if(front >= rear) {
        cout << "queue is empty" << endl;
    } else {
        cout << que[front];
    }
}

void queueArrays :: rearOf() {
    if(front >= rear) {
        cout << "queue is empty" << endl;
    } else {
        cout << que[rear];
    }
}

bool queueArrays :: isEmpty() {
    return sizeOf() == 0;
}

int main() {
    queueArrays arr1;
    cout << arr1.isEmpty();

    arr1.push(5);
    arr1.push(3);
    arr1.push(2);
    return 0;
}