#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* back;

        Node(int val) {
            data = val;
            this->next = NULL;
            this->back = NULL;
        }

        ~Node() {
            this->next = NULL;
            this->back = NULL;
            
            delete next;
            delete back;
        }
};

void insertAtHead(Node* &head, int val) {
    if(head == NULL) { 
        Node* temp = new Node(val);
        head = temp; 
    }

    else {
        Node* temp = new Node(val);
        temp->next = head;
        head->back = temp;
        head = temp;
    }
}

void insertAtTail(Node* &tail, int val) {
    if(tail == NULL) { 
        Node* temp = new Node(val);
        tail = temp; 
    }


    else {
        Node* temp = new Node(val);
        tail->next = temp;
        temp->back = tail;
        tail = temp;
    }
}

void insertAtPosition(Node* &head, Node* tail, int val, int position) {
    if(position == 1) { insertAtHead(head, val); }
    Node* temp = head;

    int cnt = 0;
    while(cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }

    if(temp == NULL) { insertAtTail(tail, val); }

    Node* node1 = new Node(val);
    
    node1->next = temp->next;
    temp->next->back = node1;
    
    temp->next = node1;
    node1->back = temp;
}

void deleteAtHead(Node* &head) {
    Node* temp = head;

    temp->next->back = NULL;
    head = temp->next;
    temp->next = NULL;

    delete temp;
}

void deleteAtPosition(Node* &head, Node* &tail, int position){
    if(position == 1) { 
        deleteAtHead(head);
        return; 
    }
    
    int cnt = 0;
    Node* curr = head;
    Node* prev = NULL;

    while(cnt < position - 1) {
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    curr->back = NULL;
    prev->next = curr->next;
    curr->next = NULL;

    delete curr;
}

void deleteAtTail(Node* &head, Node* & tail) {
    Node* temp = head
}

void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void getLen(Node* &head) {
    int len = 0;
    Node* temp = head;
    
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }

    cout << len << endl;
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, 20);
    insertAtHead(head, 30);

    insertAtTail(tail, 40);
    insertAtTail(tail, 50);

    insertAtPosition(head, tail, 100, 3);

    print(head);
    cout << "head is "  << head->data << endl;
    cout << "tail is " << tail->data << endl;
    getLen(head);

    deleteAtHead(head);
    deleteAtPosition(head, tail, 2);
    
    print(head);
    cout << "head is "  << head->data << endl;
    cout << "tail is " << tail->data << endl;
    getLen(head);

    return 0;
}