#include <iostream>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode* next;

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
    ListNode* temp = head;
    while(temp) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }std::cout << endl;
}

int getlen(ListNode* head) {
    ListNode* temp = head;
    int cnt = 0;

    while(temp) {
        temp = temp->next;
        cnt++;
    }

    return cnt;
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

void reorderList(ListNode* head) {
    int len = getlen(head);
    if(len == 1 || len == 2) return;
    
    ListNode* left = head;
    for(int i = 1; i < len/2; i++) {
        left = left->next;
    }
    
    ListNode* right = nullptr;
    if(len % 2 == 0) {
        right = left->next;
    }
    else {
        right = left->next->next;
        left = left->next;
    }
    
    left->next = nullptr;
    left = head;
    right = reverse(right);

    for(int i = 1; i <= len; i++) {
        if(i % 2 == 0) {
            ListNode* temp = right->next;

            right->next = left->next;
            left->next = right;

            left = right->next;
            right = temp;
        }
    }
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* tail = head;

    insert(tail, 2);
    //insert(tail, 3);
    //insert(tail, 4);
    //insert(tail, 5);
    print(head);

    reorderList(head);
    print(head);
    return 0;
}