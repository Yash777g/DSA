#include <iostream>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode *next;

        ListNode(int data) {
            this->val = data;
            this->next = NULL;
        }
};

void insert(ListNode* &head, int data) {
    ListNode* newNode = new ListNode(data);

    newNode->next = head;
    head = newNode;
}

int getlenght(ListNode* &head) {
    ListNode* temp = head;
    int cnt = 0;

    while(temp != NULL) {
        cnt++;
        temp = temp->next;
    }

    return cnt;
}

ListNode* middleNode(ListNode* head) {
    int len = getlenght(head);
    cout << len;
    ListNode* temp = head;

    while(len != (len/2)) {
        temp = temp->next;
        len--;
    }        

    return temp;
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
    ListNode* node1 = new ListNode(5);
    ListNode* head = node1;

    insert(head, 4);
    insert(head, 3);

    print(head);

    ListNode* hole = middleNode(head);
    print(hole);
    return 0;
}