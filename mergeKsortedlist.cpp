#include <iostream>
#include <vector>
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
    while(head) {   
        cout << head->val << " ";
        head = head->next;
    }cout << endl;
}

ListNode* divideConquer(std::vector<ListNode*>& lists, int left, int right);
ListNode* mergeSort(ListNode* l1, ListNode* l2);

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.empty()) { return nullptr; }
    return divideConquer(lists, 0, lists.size()- 1);
}

ListNode* divideConquer(vector<ListNode*>& lists, int left, int right) {
    if(left == right) return lists[left];

    int mid = left + (right - left)/2;
    ListNode* leftList = divideConquer(lists, left, mid);
    ListNode* rightList = divideConquer(lists, mid+1, right);
    return mergeSort(leftList, rightList);
}

ListNode* mergeSort(ListNode* l1, ListNode* l2) {
    if(!l1)
        return l2;
    if(!l2)
        return l1;

    ListNode* head = new ListNode(0);
    ListNode* tail = head;
    while(l1 && l2) {
        if(l1->val <= l2->val) {
            tail->next = l1;
            tail = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            tail = l2;
            l2 = l2->next;
        }
    }

    while(l1) {
        tail->next = l1;
        tail = l1;
        l1 = l1->next;
    }

    while(l2) {
        tail->next = l2;
        tail = l2;
        l2 = l2->next;
    }

    return head->next;
}

int main() {
    ListNode* head1 = new ListNode(1);
    ListNode* tail1 = head1;

    insert(tail1 ,4);
    insert(tail1 ,5);

    ListNode* head2 = new ListNode(1);
    ListNode* tail2 = head2;

    insert(tail2 ,3);
    insert(tail2 ,4);

    ListNode* head3 = new ListNode(2);
    ListNode* tail3 = head3;

    insert(tail3 ,6);

    vector<ListNode*> lists = {head1, head2, head3};
    for(auto &i : lists) {
        print(i);
    }

    ListNode* head = mergeKLists(lists);
    print(head);

    return 0;
}