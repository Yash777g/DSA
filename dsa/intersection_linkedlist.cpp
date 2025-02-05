#include <iostream>
#include <unordered_map>
using namespace std;

class ListNode{
    public:
        int val;
        ListNode* next;

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

void print(ListNode* head) {
    ListNode* temp = head;

    while(temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }cout << endl;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_map<ListNode*, bool> visited;
    ListNode* temp = headA;

    while(temp) {
        visited[temp] = true;
        temp = temp->next;
    }

    temp = headB;
    while(temp) {
        if(visited[temp]) return temp;
        temp = temp->next;
    }

    return NULL;        
}

int main() {
    ListNode* head1 = new ListNode(1);
    ListNode* tail1 = head1;

    insert(tail1, 2);
    insert(tail1, 3);
    insert(tail1, 4);
    insert(tail1, 5);
    insert(tail1, 6);
    insert(tail1, 7);
    print(head1);

    ListNode* head2 = new ListNode(4);
    ListNode* tail2 = head2;

    insert(tail2, 5);
    insert(tail2, 6);
    insert(tail2, 7);
    print(head2);

    ListNode* head = getIntersectionNode(head1, head2);
    print(head);

    return 0;
}