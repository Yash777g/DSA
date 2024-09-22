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

ListNode* oddEvenList(ListNode* head) {
    if(!head || !head->next) { return head; }
    
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenhead = even;

    while(even && even->next) {
        odd->next = odd->next->next;
        odd = odd->next;

        even->next = even->next->next;
        even = even->next;
    }

    odd->next = evenhead;
    return head;
}

void print(ListNode* head) {
    ListNode* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* head = node1;
    ListNode* tail = node1;

    insert(tail, 2);
    insert(tail, 3);
    insert(tail, 4);
    insert(tail, 5);
    print(head);

    head = oddEvenList(head);
    print(head);
    return 0;
}