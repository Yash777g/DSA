#include <iostream>
#include <vector>
#include <unordered_set>
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

void print(ListNode* head) {
    ListNode* temp = head;

    while(temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }cout << endl;
}

ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    std::unordered_set<int> values;
    for(auto &i: nums) {
        values.insert(i);
    }

    ListNode* temp = new ListNode(0);
    ListNode* newhead = temp;

    while(head) {
        if(values.find(head->val) == values.end()) {
            insert(temp, head->val);
        }
        head = head->next;
    }

    return newhead->next;
}

int main() {
    vector<int> nums = {1,2,3};

    ListNode* head = new ListNode(1);
    ListNode* tail = head;

    insert(tail, 2);
    insert(tail, 3);
    insert(tail, 4);
    insert(tail, 5);
    print(head);

    head = modifiedList(nums, head);
    print(head);

    return 0;
}