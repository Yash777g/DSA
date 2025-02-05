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

void solve(ListNode* head, int &carry) {
    if (!head) { return; }
    solve(head->next, carry);

    int prod = head->val*2 + carry;
    head->val = prod % 10;
    carry = prod/10;
}

// recursive approach
ListNode* doubleIt(ListNode* head) {
    int carry = 0;
    solve(head, carry);

    if(carry == 1) {
        ListNode* newHead = new ListNode(1);
        newHead->next = head;
        head = newHead;
    }

    return head;
}

// two pointer approach.
/*ListNode* doubleIt(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    int carry = 0;
    while(curr) {
        if(curr == head && (curr->val)*2 > 9) {
            ListNode* temp = new ListNode(1);
            
            temp->next = head;
            head = temp;
            prev = head;
            curr->val = curr->val*2

        }
    }

    return head;
}*/

// array approach not best way to do it.
/*ListNode* doubleIt(ListNode* head) {
    ListNode* temp = head;
    vector<int> nums;

    while(temp) {
        nums.push_back(temp->val);
        temp = temp->next;
    }

    temp = nullptr;
    ListNode* result = temp;
    int carry = 0;

    for(int i = nums.size()-1; i >= 0; i--) {
        if(nums[i]*2 > 9) {
            ListNode* newnode = new ListNode((nums[i]*2) % 10 + carry);
            carry = 1;
            newnode->next = result;
            result = newnode;
        }

        else {
            ListNode* newnode = new ListNode(nums[i]*2 + carry);
            carry = 0;
            newnode->next = result;
            result = newnode;
        }
    }

    if(carry == 1) {
        ListNode* newnode = new ListNode(carry);
        
        newnode->next = result;
        result = newnode;
    }

    return result;
}*/

int main() {
    ListNode* head = new ListNode(9);
    ListNode* tail = head;

    insert(tail, 9);
    insert(tail, 9);
    print(head);

    head = doubleIt(head);
    print(head);

    return 0;
}