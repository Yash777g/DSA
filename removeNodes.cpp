#include <iostream>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode *next;

        ListNode(int val) {
            this->val = val;
            this->next = nullptr;
        }
};

void insert(int val, ListNode* &tail) {
    ListNode* newNode = new ListNode(val);
    tail->next = newNode;
    tail = newNode;
}

void print(ListNode* head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }cout << endl;
}

ListNode* reverse(ListNode* head) {
    ListNode* back = nullptr;
    ListNode* curr = head;
    ListNode* front = curr->next;

    while(curr) {
        front = curr->next;
        curr->next = back;
        back = curr;
        curr = front;
    }

    return back;
}
 
ListNode* removeNodes(ListNode* head) {
    head = reverse(head);
        
    ListNode* curr = head;
    ListNode* front = curr->next;

    while(front) {
        if(curr->val > front->val) {
            curr->next = front->next;
            front->next = nullptr;
        } else {
            curr = front;
        }

        front = curr->next;
    }

    head = reverse(head);
    return head;
}

int main() {
    ListNode* head = new ListNode(5);
    ListNode* tail = head;

    insert(2, tail);
    insert(13, tail);
    insert(4, tail);
    insert(8, tail);

    print(head);
    head = removeNodes(head);
    print(head);
    
    return 0;
}
