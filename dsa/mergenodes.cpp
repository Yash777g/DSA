#include <iostream>
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
    }
    cout << endl;
}

ListNode* mergeNodes(ListNode* head) {
    ListNode* temp = head;
    ListNode* dummyhead = new ListNode(0);
    ListNode* result = dummyhead;
    int sum = 0;

    while(temp) {
        if(temp->val == 0) {
            dummyhead->next = new ListNode(sum);
            dummyhead = dummyhead->next;
            sum = 0;
        }
        sum = sum + temp->val;
        temp = temp->next;
    } 

    return result->next->next;    
}

int main() {
    ListNode* head = new ListNode(0);
    ListNode* tail = head;

    insert(tail, 3);
    insert(tail, 1);
    insert(tail, 0);
    insert(tail, 4);
    insert(tail, 5);
    insert(tail, 2);
    insert(tail, 0);
    print(head);

    head = mergeNodes(head);
    print(head);

    return 0;
}