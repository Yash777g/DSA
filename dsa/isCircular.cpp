#include <iostream>
#include <map>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode *next;

        ListNode(int val) {
            this->val = val;
            this->next = nullptr;
        }
};

void insert(int val, ListNode* &tail) {
    ListNode* newNode = new ListNode(val);
    tail->next = newNode;
    tail = newNode;
}

void print(ListNode* head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }cout << endl;
}

// approach no 1 iterative method
/*bool isCircular(ListNode* head) {
    if(head == nullptr || head->next == nullptr) 
        return false;

    ListNode* temp = head->next;
    while(temp != head && temp != nullptr) {
        temp = temp->next;
    }

    if(temp == head) 
        return true;
    
    return false;
}*/

// approach no 2 map
bool isCircular(ListNode* head) {
    if(head == nullptr || head->next == nullptr) 
        return false;
    
    map<ListNode*, bool> visited;

    ListNode* temp = head;
    while(temp) {
        if(visited[temp] == false) 
            visited[temp] = true;
        
        else 
            return true;
        
        temp = temp->next;
    }

    return false;
}

int main() {
    ListNode* head1 = new ListNode(5);
    ListNode* tail1 = head1;

    insert(2, tail1);
    insert(13, tail1);
    insert(4, tail1);
    
    ListNode* newNode = new ListNode(8);
    tail1->next = newNode;
    tail1 = newNode;
    newNode->next = head1;

    //print(head1);
    cout << boolalpha << isCircular(head1) << endl;

    ListNode* head2 = new ListNode(3);
    ListNode* tail2 = head2;

    insert(5, tail2);
    insert(9, tail2);
    insert(8, tail2);

    cout << boolalpha << isCircular(head2);
    return 0;
}