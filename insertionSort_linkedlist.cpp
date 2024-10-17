#include <iostream>
using namespace std;

class ListNode{
    public:
        int val;
        ListNode *next;

        ListNode(int val) {
            this->val = val;
            this->next = nullptr;
        }
};

void insert(ListNode* &tail, int val) {
    ListNode* temp = new ListNode(val);

    tail->next = temp;
    tail = temp;
}

void print(ListNode* head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }cout << endl;
}

ListNode* insertionSortList(ListNode* head) {
    ListNode* dummy = new ListNode(10000);

    while(head) {
        ListNode* temp = dummy;
        ListNode* forward = head->next;

        while(temp->next && temp->next->val < head->val) {
            temp = temp->next;
        }

        head->next = temp->next;
        temp->next = head;
        head = forward;
    }

    return dummy->next;     
}

int main() {
    ListNode* head = new ListNode(5);
    ListNode* tail = head;

    insert(tail, 9);
    insert(tail, 1);
    insert(tail, 15);
    insert(tail, 3);
    print(head);
    
    head = insertionSortList(head);
    print(head);
    
    return 0;
}