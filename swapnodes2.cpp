#include <iostream>
#include <vector>
#include <algorithm>
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
    }cout << endl;
}

ListNode* swapNodes(ListNode* head, int k) {
    ListNode* temp = head;
    vector<int> nums;

    while(temp) {
        nums.push_back(temp->data);
        temp = temp->next;
    }

    int start = k - 1;
    int end = nums.size() - k;

    swap(nums[start], nums[end]);

    temp = new ListNode(0);
    ListNode* dummy = temp;
    
    for(int i = 0; i < nums.size(); i++) {
        ListNode* newNode = new ListNode(nums[i]);
        temp->next = newNode;
        temp = temp->next;
    }

    return dummy->next;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* tail = head;

    insert(tail, 2);
    insert(tail, 3);
    insert(tail, 4);
    insert(tail, 5);
    print(head);

    head = swapNodes(head, 2);
    print(head);
    return 0;
}