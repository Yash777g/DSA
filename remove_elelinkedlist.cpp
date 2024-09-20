#include <iostream>
using namespace std;

class ListNode {
    public:
        int data;
        ListNode* next;

        ListNode(int val) {
            this->data = val;
            this->next = nullptr;
        }
};

void insert(ListNode* &tail, int val) {
    ListNode* temp = new ListNode(val);

    tail->next = temp;
    tail = temp;
}

ListNode* removeElements(ListNode* &head, int val) {
    if(!head) { return head; }

    ListNode* prev = NULL;
    ListNode* curr = head;

    while(curr) {
        if(curr->data == val && curr == head) {
            head = head->next;
            curr->next = NULL;
            delete curr;
            curr = head;
        }

        else if(curr->data == val) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }

        else {
            prev = curr;
            curr = curr->next;
        }
    }

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
    ListNode* node1 = new ListNode(7);
    ListNode* head = node1;
    ListNode* tail = node1;

    insert(tail, 7);
    insert(tail, 7);
    insert(tail, 7);
    print(head);

    head = removeElements(head, 7);
    print(head);

    return 0;
}