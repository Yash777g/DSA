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

ListNode* swapPairs(ListNode* head) {
    if(head == NULL || head->next == NULL) { return head; }

    ListNode* temp = head->next;
    head->next = swapPairs(head->next->next);
    temp->next = head;

    return temp;       
}

void print(ListNode* head) {
    ListNode* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* tail = head;

    insert(tail, 2);
    insert(tail, 3);
    insert(tail, 4);
    insert(tail, 5);
    insert(tail, 6);
    print(head);

    head = swapPairs(head);
    print(head);
    return 0;
}