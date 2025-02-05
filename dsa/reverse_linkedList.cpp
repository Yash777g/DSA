#include <iostream>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode *next;

        ListNode(int data) {
            this->next = NULL;
            this->val = data;
        }

        ~ListNode() {
            if(this->next != NULL) {
                this->next = NULL;
                delete next;
            }
        }
};

void insert(int val, ListNode* &head) {
    ListNode* temp = new ListNode(val);

    temp->next = head;
    head = temp;
}

// approach no 1 
ListNode* reverseList(ListNode* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* curr = head;
    ListNode* backward = NULL;
    ListNode* forward = curr->next;

    while(curr != NULL) {
        forward = curr->next;
        curr->next = backward;

        backward = curr;
        curr = forward;
    }

    head = backward;
    return head;
}

void print(ListNode* &head) {
    ListNode* temp = head;

    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    ListNode* node1 = new ListNode(5);
    ListNode* head = node1;

    insert(4, head);
    insert(3, head);
    insert(2, head);
    insert(1, head);

    print(head);

    head = reverseList(head);
    print(head);

    return 0;
}