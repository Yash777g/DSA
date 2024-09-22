#include <iostream>
#include <unordered_map>
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
    }
    cout << endl;
}

ListNode* deleteDuplicates(ListNode* head) {
    if(!head) { return nullptr; }
    if(head->next == nullptr) { return head; }

    ListNode* temp = head;
    unordered_map<int,int> freq;

    while(temp) {
        freq[temp->data]++;
        temp = temp->next;
    }

    ListNode* curr = head;
    ListNode* prev = NULL;
    
    while(curr) {
        if(freq[curr->data] > 1 && curr == head) {
            head = head->next;
            curr = head;
        }

        else if(freq[curr->data] > 1) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }

        else {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* tail = head;
    
    insert(tail, 2);
    insert(tail, 3);
    insert(tail, 3);
    insert(tail, 4);
    insert(tail, 4);
    insert(tail, 5);
    print(head);

    head = deleteDuplicates(head);
    print(head);

    return 0;
}