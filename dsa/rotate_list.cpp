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

int getLen(ListNode*& head, ListNode*& tail) {
    ListNode* temp = head;
    int count = 0;
    
    while (temp != NULL) {
        count++;
        tail = temp;
        temp = temp->next;
    
    }
    return count;
}

ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    ListNode* tail = NULL;

    int len = getLen(head, tail);
    int pos = k % len;

    if (pos == 0) {
        return head;
    }
    pos = len - pos;

    tail->next = head;
    ListNode* temp = NULL;

    while (pos != 0) {
        temp = head;
        head = head->next;
        pos--;
    }

    temp->next = NULL;
    return head;
}

// more optimized code ??
/*int getlenght(ListNode* head) {
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
    k = k % len;   

    while(k > 0) {
        head = solve(head);
        k--;
    }

    return head;     
}*/

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