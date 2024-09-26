#include <iostream> 
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
    public:
        int val;
        Node* next;
        Node* random;

        Node(int val) {
            this->val = val;
            this->next = NULL;
            this->random = NULL;
        }
};

void insert(Node* &tail, int val) {
    Node* newNode = new Node(val);

    tail->next = newNode;
    tail = newNode;
}

void print(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }cout << endl;
}

// map approach
Node* copyRandom(Node* head) {
    Node* copyhead = head;
    Node* copytail = copyhead;
    Node* temp = head->next;

    while(temp) {
        Node* newNode = new Node(temp->val);

        copytail->next = newNode;
        copytail = newNode;
        temp = temp->next;
    }

    unordered_map<Node*,Node*> mapping;
    temp = head;
    Node* temp2 = copyhead;

    while(temp && temp2) {
        mapping[temp] = copyhead;
        temp = temp->next;
        temp2 = temp2->next;
    }

    temp = head;
    temp2 = copyhead;

    while(temp) {
        temp2->random = mapping[temp->random];
        temp = temp->next;
        temp2 = temp2->next;
    }

    return copyhead;
}

int main() {
    Node* head = new Node(1);
    Node* tail = head;

    insert(tail, 2);
    insert(tail, 3);
    insert(tail, 4);
    insert(tail, 5);
    print(head);

    head = copyRandom(head);
    print(head);
    return 0;
}