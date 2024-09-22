#include <iostream>
#include <unordered_map>
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

//O(1) space complexity
bool hasCycle(ListNode* head) {
    if (head == NULL || head->next == NULL) return false;

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow) {
            return true;
        }
    }

    return false;
}

// map approach might take extra space
/*bool hasCycle(ListNode* head) {
    if (head == NULL || head->next == NULL) return false;

    unordered_map<ListNode*,bool> visited;
    ListNode* temp = head;

    while(temp) {
        if(visited[temp] == true) { return true; }

        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}*/

void print(ListNode* head) {
    ListNode* temp = head;

    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }cout << endl;
}

int main() {
    ListNode* head = new ListNode(3);
    ListNode* tail = head;

    insert(tail, 2);
    insert(tail, 0);
    insert(tail, -4);
    print(head);

    bool ans = hasCycle(head);
    cout << ans;

    return 0;
}