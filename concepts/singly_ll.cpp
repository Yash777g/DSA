#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int data) {
            this-> data = data;
            this->next = NULL;
        }

        ~Node() {
            if(this->next != NULL) {
                this->next = NULL;
                delete next;
            }
        }
};

void insertAtHead(Node* &head, int val) {
    Node* temp =  new Node(val);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int val) {
    Node* temp = new Node(val);
    tail->next = temp;
    tail = temp;
}

void insertAtMiddle(Node* &head, int position, int val, Node* &tail) {
    if(position == 1) {
        insertAtHead(head, val);
        return;
    }

    int cnt = 1;
    Node* temp = head;

    while(cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL) {
        insertAtTail(tail, val);
        return;
    }

    Node* temp1 = new Node(val);
    temp1->next = temp->next;
    temp->next = temp1;
}

void deleteAtHead(Node* &head) {
    Node* temp = head;
        
    head = head->next;
    temp->next = NULL;
        
    delete temp;
}

void deleteAtTail(Node* &head, Node* & tail) {
    Node* temp = head;

    while(temp->next->next != NULL) {
        temp = temp->next;  
    }

    tail = temp;
    temp->next = NULL;

    delete temp->next;
}

void deleteNode(Node* &head, Node* &tail, int position) {
    // at head
    if(position == 1) {
        deleteAtHead(head);
        return;
    }

    int cnt = 1;
    Node* curr = head;
    Node* prev = NULL;

    while(cnt < position) {
        prev = curr;
        curr= curr->next;
        cnt++;
    }

    // at tail
    if(curr->next == NULL) {
        deleteAtTail(head, tail);
        return;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    Node* node1 = new Node(10);  
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, 20);
    insertAtHead(head, 30);

    insertAtTail(tail, 5);
    insertAtTail(tail, 1);

    insertAtMiddle(head, 3, 15, tail);
    insertAtMiddle(head, 3, 18, tail);
    insertAtMiddle(head, 5, 12, tail);

    insertAtMiddle(head, 9, -5, tail);
    
    print(head);
    cout << "head is " << head->data << endl;
    cout << "tail is " << tail->data << endl;

    deleteAtHead(head);
    deleteAtTail(head, tail);
    deleteNode(head, tail, 3);
    deleteNode(head, tail, 1);
    deleteNode(head, tail, 5);

    print(head);
    cout << "head is " << head->data << endl;
    cout << "tail is " << tail->data << endl;

    return 0;
}