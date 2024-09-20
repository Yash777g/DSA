#include <iostream>
using namespace std;

class ListNode {
    public:
        int data;
        ListNode* next;

        ListNode(int val) {
            this->data = val;
            this->next = nullptr;
        }
};

void insert(ListNode* &tail, int val) {
    ListNode* temp = new ListNode(val);

    tail->next = temp;
    tail = temp;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head = new ListNode(0);
    ListNode* curr = head;

    while(list1 != NULL && list2 != NULL) {
        if(list1->data < list2->data) {
            curr->next = new ListNode(list1->data);
            curr = curr->next;
            list1 = list1->next;
        }

        else if(list1->data > list2->data) {
            curr->next = new ListNode(list2->data);
            curr = curr->next;
            list2 = list2->next;
        }

        else {
            curr->next = new ListNode(list1->data);
            curr = curr->next;
            list1 = list1->next;
        }
    }

    while(list1 != NULL) {
        curr->next = new ListNode(list1->data);
        curr = curr->next;
        list1 = list1->next;
    }

    while(list2 != NULL) {
        curr->next = new ListNode(list2->data);
        curr = curr->next;
        list2 = list2->next;
    }

    ListNode* result = head->next;
    delete head;
    
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
    ListNode* node1 = new ListNode(1);
    ListNode* head1 = node1;
    ListNode* tail1 = node1;

    insert(tail1,2);
    insert(tail1,4);
    print(head1);

    ListNode* node2 = new ListNode(1);
    ListNode* head2 = node2;
    ListNode* tail2 = node2;

    insert(tail2,3);
    insert(tail2,4);
    print(head2);

    ListNode* head = mergeTwoLists(head1, head2);
    print(head);
    return 0;
}