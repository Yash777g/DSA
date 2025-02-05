#include <iostream>
using namespace std;

class ListNode {
    public:
        int data;
        ListNode* next;

        ListNode(int val) {
            this->data = val;
            this->next = NULL;
        }
};

void insert(ListNode* &tail, int val) {
    ListNode* newNode = new ListNode(val);

    tail->next = newNode;
    tail = newNode;
}

void print(ListNode* head) {
    ListNode* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }cout << endl;
}

ListNode* deleteMiddle(ListNode* head) {
    ListNode* temp = head;
    int size = 0;

    while(temp) {
        size++;
        temp = temp->next;
    }
    size = size/2;
    ListNode* prev = NULL;
    ListNode* curr = head;

    while(size > 0) {
        prev = curr;
        curr = curr->next;
        size--;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;

    return head;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* tail = head;

    insert(tail, 2);
    insert(tail, 3);
    insert(tail, 4);
    insert(tail, 5);
    print(head);

    head = deleteMiddle(head);
    print(head);
    return 0;
}