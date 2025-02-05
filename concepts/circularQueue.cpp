#include <iostream>
using namespace std;

class CircularQueue {
    /* alternative initialization without constructor 
    private:
        int *arr = new int[10001];
        int front = rear = -1;
        static const int size = 10001;
    */ 
    public:
        // constructor initialization
        int *arr;
        int front, rear, size;
        CircularQueue() {
            int *arr = new int[10001];
            front = -1, rear = -1;
            size = 10001;
        }

        ~CircularQueue() {
            delete[] arr;
        }

        int sizeOf();
        void push(int val);
        void pop();
};

// int CircularQueue :: sizeOf() {
//     int size = 0;
//     if (front == -1) {
//         return size;
//     } 
// }

void CircularQueue::push(int val) {
    if ((front == 0 && rear == size - 1) || (rear + 1) % size == front) {
        cout << "Queue is full!!!" << endl;
        return;
    } else if (front == -1) {
        front = rear = 0;
        arr[rear] = val;
    } else {
        arr[rear] = val;
        rear = (rear + 1) % size;
    }
}


void CircularQueue :: pop() {
    if(front == -1) {
        cout << "Queue is empty!!!" << endl;
        return;
    }
    
    cout << "Element popped:" << arr[front] << endl;
    arr[front] = -1;

    if(front == rear) {
        front = rear = -1;
    } else if(front == size-1) {
        front = 0; 
    } else {
        front++;
    }
}

int main() {

    return 0;
}