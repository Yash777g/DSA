#include <iostream>
#include <stack>
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
        cout << temp->val << " ";
        temp = temp->next;
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

// stack approach without reversing the linkedlist.
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1;
    stack<int> s2;

    ListNode* temp = l1;
    while(temp) {
        s1.push(temp->val);
        temp = temp->next;
    }

    temp = l2;
    while(temp) {
        s2.push(temp->val);
        temp = temp->next;
    }

    ListNode* ans = new ListNode(0);
    ListNode* anshead = ans;

    int carry = 0;

    while(!s1.empty() || !s2.empty() || carry != 0) {
        int x = !s1.empty() ? s1.top() : 0;
        int y = !s2.empty() ? s2.top() : 0;

        int sum = x + y + carry;
        carry = sum / 10;
        ans->next = new ListNode(sum % 10);
        ans = ans->next;

        if(!s1.empty()) s1.pop();
        if(!s2.empty()) s2.pop();
    }

    ListNode* result = reverse(anshead->next);
    delete anshead;  
        
    return result;
}

// reverse linkedlist approach.
/*ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);

    ListNode* ans = new ListNode(0);
    ListNode* anshead = ans;

    int carry = 0;

    while(l1 != NULL || l2 != NULL || carry != 0) {
        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;

        int sum = x + y + carry;
        carry = sum / 10;
        ans->next = new ListNode(sum % 10);
        ans = ans->next;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    anshead = anshead->next;
    anshead = reverse(anshead);
    
    return anshead;
}*/

int main() {
    ListNode* head1 = new ListNode(7);
    ListNode* tail1 = head1;

    insert(tail1, 2);
    insert(tail1, 4);
    insert(tail1, 3);
    print(head1);
    
    ListNode* head2 = new ListNode(5);
    ListNode* tail2 = head2;

    insert(tail2, 6);
    insert(tail2, 4);
    print(head2);

    ListNode* head = addTwoNumbers(head1, head2);
    print(head);

    return 0;
}