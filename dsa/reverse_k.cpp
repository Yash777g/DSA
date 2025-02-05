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
    }
    cout << endl;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if(!head || !head->next) 
        return head;

    ListNode* back = nullptr;
    ListNode* curr = head;
    ListNode* front = nullptr;
    int count = 0;

    while(curr) {
        curr =  curr->next;
        count++;
    }

    if(count < k) {
        return head;
    }

    curr = head;
    count = 0;

    while(curr != nullptr && count < k) {
        front = curr->next;
        curr->next = back;
        back = curr;
        curr = front;
        count++;
    }

    if(front != nullptr) {
        head->next = reverseKGroup(front, k);
    }

    return back;
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

    head = reverseKGroup(head, 3);
    print(head);
    return 0;
}