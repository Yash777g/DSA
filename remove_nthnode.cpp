#include <iostream>
using namespace std;

class ListNode {
    public:
        int data;
        ListNode* next;

        ListNode(int val) {
            this->data = val;
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
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getlenght(ListNode* head) {
    ListNode* temp = head;
    int cnt = 0;

    while(temp!= NULL) {
        temp = temp->next;
        cnt++;
    }

    return cnt;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(!head || !head->next) { return NULL; }
    
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* nfast = head;

    while(n > 0) {
        nfast = nfast->next;
        n--;
    }

    while(nfast) {
        prev = curr;
        curr = curr->next;
        nfast = nfast->next;
    }

    if(!prev) { return curr->next; }
    prev->next = curr->next;

    // can be optimized.
    /*int len = getlenght(head);
    int cnt = 0;

    if(len - n == 0) {
        return head->next;
    }

    while(cnt < (len - n)) {
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;*/

    return head;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* tail = head;

    insert(tail, 2);
    print(head);

    head = removeNthFromEnd(head, 2);
    print(head);
    return 0;
}