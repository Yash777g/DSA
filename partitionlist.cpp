#include <iostream> 
#include <vector>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode* next;

        ListNode(int val) {
            this->val = val;
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
        cout << temp->val << " ";
        temp = temp->next;
    }cout << endl;
}

ListNode* partition(ListNode* head, int x) {
    ListNode* lefthead = new ListNode(0);
    ListNode* left = lefthead;
    ListNode* righthead = new ListNode(0);
    ListNode* right = righthead;

    while(head != NULL) {
        if(head->val < x) {
            left->next = new ListNode(head->val);
            left = left->next;
        }
        
        else {
            right->next = new ListNode(head->val);
            right = right->next;
        }

        head = head->next;
    }

    if(lefthead == NULL) {
        return righthead->next;
    }

    left->next = righthead->next;
    right->next = NULL;

    return lefthead->next;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* tail = head;

    insert(tail, 4);
    insert(tail, 3);
    insert(tail, 2);
    insert(tail, 5);
    insert(tail, 2);
    print(head);

    head = partition(head, 3);
    print(head);

    return 0;
}