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

void insert(int val, ListNode* &tail) {
    ListNode* temp = new ListNode(val);

    tail->next = temp;
    tail = temp;    
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* curr = dummyHead;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {   
        int x = l1 ? l1->data : 0;
        int y = l2 ? l2->data : 0;
        int sum = carry + x + y;
            
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
            
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
    }

    ListNode* result = dummyHead->next;
    delete dummyHead;  
        
    return result;
}


void print(ListNode* head) {
    ListNode* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    ListNode* node1 = new ListNode(2);
    ListNode* tail1 = node1;
    ListNode* head1 = node1;

    insert(4, tail1);
    insert(3, tail1);
    print(head1);

    ListNode* node2 = new ListNode(5);
    ListNode* tail2 = node2;
    ListNode* head2 = node2;

    insert(6, tail2);
    insert(4, tail2);
    print(head2);    

    ListNode* head = addTwoNumbers(head1, head2);
    print(head);
    return 0;
}