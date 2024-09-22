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

ListNode* checkloop(ListNode* head) {
    if (head == NULL || head->next == NULL) return NULL;

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow) {
            return slow;
        }
    }

    return NULL;
}

//O(1) space complexity
ListNode *detectCycle(ListNode* head) {
    if (!head || !head->next) return nullptr;
        
    ListNode *end = checkloop(head);
    if (end != nullptr) {
        ListNode *start = head;
            
           
        while (start != end) {
            start = start->next;
            end = end->next;
        }
            
        return start;
    }
    return nullptr; 
}


// map approach might take extra space
/*ListNode* detectCycle(ListNode* head) {
    if (head == NULL || head->next == NULL) return NULL;

    unordered_map<ListNode*,bool> visited;
    ListNode* temp = head;

    while(temp) {
        if(visited[temp] == true) { return temp; }

        visited[temp] = true;
        temp = temp->next;
    }

    return NULL;
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

    ListNode* node = detectCycle(head);
    cout << node;

    return 0;
}