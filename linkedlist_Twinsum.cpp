#include <iostream>
using namespace std;

class ListNode {
    public:
        int data;
        ListNode* next;

        ListNode(int data) {
            this->data = data;
            this->next = nullptr;
        }
};

void insert(ListNode* &tail, int data) {
    ListNode* newNode = new ListNode(data);
    tail->next = newNode;
    tail = newNode;
}

void print(ListNode* head) {
    ListNode* curr = head;
    while(curr) {
        cout << curr->data << " ";
        curr = curr->next;
    } cout << endl;
}

int lenght(ListNode* head) {
    ListNode* temp = head;
    int count = 0;
    while(temp) {
        count++;
        temp = temp->next;
    } return count;
}

ListNode* reverse(ListNode* &head) {
    ListNode* curr = head;
    ListNode* prev = nullptr;

    while(curr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    } return prev;
}

int pairSum(ListNode* head) {
    int len = lenght(head)/2;
    ListNode* prev = nullptr;
    ListNode* curr = head;
    
    while(len--) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = nullptr;
    prev = head;
    int maxi = 0;
    curr = reverse(curr);
    while(curr) {
        maxi = max(maxi, prev->data + curr->data);
        prev = prev->next;
        curr = curr->next;
    } return maxi;
}

int main() {
    ListNode* head = new ListNode(5);
    ListNode* tail = head;
    
    insert(tail, 4);
    insert(tail, 2);
    insert(tail, 1);
    cout << pairSum(head);
    
    return 0;
}