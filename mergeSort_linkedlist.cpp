#include <iostream>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode* next;

        ListNode(int val) {
            this->val = val;
            this->next =nullptr;
        }

        ListNode() {
            this->val = 0;
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

ListNode* findmid(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

ListNode* mergelist(ListNode* left, ListNode* right) {
    if(!left) 
        return right;
    if(!right) 
        return left;

    ListNode* dummyhead = new ListNode(0);
    ListNode* curr = dummyhead;

    while(left != nullptr && right != nullptr) {
        if(left->val < right->val) {
            curr->next = left;
            curr = left;
            left = left->next;
        } else {
            curr->next = right;
            curr = right;
            right = right->next;
        }
    }

    while(left) {
        curr->next = left;
        curr = left;
        left = left->next;
    }

    while(right) {
        curr->next = right;
        curr = right;
        right = right->next;
    }

    return dummyhead->next;
}

ListNode* sortList(ListNode* head) {
    if(!head || !head->next) 
        return head;

    ListNode* left = head;
    ListNode* mid = findmid(head);
    ListNode* right = mid->next;

    mid->next = nullptr;
    left = sortList(left);
    right = sortList(right);

    ListNode* result = mergelist(left, right);

    return result;
}

int main() {
    ListNode* head = new ListNode(5);
    ListNode* tail = head;

    insert(tail, 2);
    insert(tail, 8);
    insert(tail, 1);
    insert(tail, 4);
    print(head);

    head = sortList(head);
    print(head);

    return 0;
}