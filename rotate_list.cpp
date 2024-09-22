#include <iostream>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode *next;

        ListNode(int val) {
            this->val = val;
            this->next = NULL;
        }
};

void insert(ListNode* &tail, int val) {
    ListNode* temp = new ListNode(val);

    tail->next = temp;
    tail = temp;
}

int getlenght(ListNode* head) {
    ListNode* temp = head;
    int cnt = 0;

    while(temp) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

ListNode* solve(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* temp = head;

    while(temp->next) {
        prev = temp;
        temp = temp->next;
    }

    ListNode* tail = NULL;
    temp = head;
    while(temp) {
        tail = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    tail->next = head;
    head = tail;
    tail = prev;

    return head;
}

ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL || head->next == NULL) { return head; }

    int len = getlenght(head);
    len = k % len;   

    while(k > 0) {
        head = solve(head);
        k--;
    }

    return head;     
}

void print(ListNode* head) {
    ListNode* temp = head;

    while(temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* tail = head;

    insert(tail, 2);
    insert(tail, 3);
    insert(tail, 4);
    insert(tail, 5);
    print(head);

    head = rotateRight(head, 2);
    print(head);
    cout << 2000000000 % 3;
    return 0;
}