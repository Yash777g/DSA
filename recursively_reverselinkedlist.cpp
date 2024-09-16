#include <iostream>
using namespace std;

class Node {
    public:
        int val;
        Node* next;

        Node(int data) {
            this->val = data;
            this->next = NULL; 
        }
};

void insert(Node* &head, int data) {
    Node* temp = new Node(data);

    temp->next = head;
    head = temp;
}

Node* solve(Node* &head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* track = solve(head->next);

    head->next->next = head;
    head->next = NULL;
    
    return track;
}

Node* reverseList(Node* head) {
    return solve(head);    
}

void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* node1 = new Node(5);
    Node* head = node1;

    insert(head, 4);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);

    print(head);

    head = reverseList(head);
    print(head);

    return 0;
}