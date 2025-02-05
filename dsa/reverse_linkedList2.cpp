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

void insert(int val, ListNode* &tail) {
    ListNode* temp = new ListNode(val);

    tail->next = temp;
    tail = temp;
}

ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* forward = curr->next;

    while(curr != nullptr) {
        forward = curr->next;
        curr->next = prev;
        
        prev = curr;
        curr = forward;
    }

    head = prev;
    return prev;
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || left == right) return head;

    ListNode* dummyhead = new ListNode(0);
    dummyhead->next = head;
    ListNode* back = dummyhead;
    
    for(int i = 1; i < left; i++) {
        back = back->next;
    }

    ListNode* end = dummyhead;
    ListNode* front = end->next;
    
    for(int i = 0; i < right; i++) {
        end = front;
        front = front->next;
    }

    end->next = nullptr;
    back->next = reverse(back->next);

    ListNode* tail = nullptr;
    back = dummyhead;
    
    while(back) {
        tail = back;
        back = back->next;
    }

    tail->next = front;

    return dummyhead->next;
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
    ListNode* head = new ListNode(1);
    ListNode* tail = head;

    //insert(1, tail);
    insert(2, tail);
    insert(3, tail);
    insert(4, tail);
    insert(5, tail);
    //insert(6, tail);
    print(head);

    head = reverseBetween(head, 1, 3);
    print(head);

    return 0;
}