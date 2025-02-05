#include <iostream>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode *next;

        ListNode(int val) {
            this->val = val;
            this->next = nullptr;
        }
};

class Stack {
    private:
        ListNode* top;
    
    public:
        Stack() {
            top = nullptr;
        }

        void push(int val);
        void pop();
        void peek();
        bool isEmpty();

        ~Stack() {
            while(top != nullptr) {
                pop();
            }
        }
};

void Stack :: push(int val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = top;
    top = newNode;
}

void Stack :: pop() {
    if(top == nullptr) {
        cout << "Stack underflow." << endl;
    } else {
        ListNode* temp = top;
        top = top->next;
        delete temp;
    }
}

void Stack :: peek() {
    if(top == nullptr) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Top is: " << top->val << endl;
    }
}

bool Stack :: isEmpty() {
    if(top == nullptr) {
        return true;
    }
    return false;
}

int main() {
    Stack list;
    cout << boolalpha << list.isEmpty() << endl;

    list.push(1);
    list.push(2);
    list.push(3);
    list.peek();

    list.pop();
    list.peek();
    cout << boolalpha << list.isEmpty() << endl;
    return 0;
}