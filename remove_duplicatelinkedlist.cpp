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

ListNode* deleteDuplicates(ListNode* head) {
    if(head == NULL || head) {
        return head;
    }

    ListNode* prev = head;
    ListNode* curr = prev->next;

    while(curr) {
        if(prev->data == curr->data) {
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

void insert(ListNode* &tail, int val) {
    ListNode* temp = new ListNode(val);

    tail->next = temp;
    tail = temp;
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

    insert(tail, 1);
    insert(tail, 2);
    insert(tail, 3);
    insert(tail, 3);
    print(head);

    head = deleteDuplicates(head);
    print(head);
    return 0;
}