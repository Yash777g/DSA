#include <iostream> 
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
    public:
        int val;
        Node* next;
        Node* random;

        Node(int val) {
            this->val = val;
            this->next = NULL;
            this->random = NULL;
        }
};

void insert(Node* &tail, int val) {
    Node* newNode = new Node(val);

    tail->next = newNode;
    tail = newNode;
}

void print(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }cout << endl;
}

// intertwen nodes
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        Node* curr = head;
        while (curr) {
            Node* new_node = new Node(curr->val);
            new_node->next = curr->next;
            curr->next = new_node;
            curr = new_node->next;
        }
        
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        Node* old_head = head;
        Node* new_head = head->next;
        Node* curr_old = old_head;
        Node* curr_new = new_head;
        
        while (curr_old) {
            curr_old->next = curr_old->next->next;
            curr_new->next = curr_new->next ? curr_new->next->next : nullptr;
            curr_old = curr_old->next;
            curr_new = curr_new->next;
        }
        
        return new_head;       
    }
};

// map approach
Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
        
    unordered_map<Node*, Node*> old_to_new;
        
    Node* curr = head;
    while (curr) {
        old_to_new[curr] = new Node(curr->val);
        curr = curr->next;
    }
        
    curr = head;
    while (curr) {
        old_to_new[curr]->next = old_to_new[curr->next];
        old_to_new[curr]->random = old_to_new[curr->random];
        curr = curr->next;
    }
        
    return old_to_new[head];
}

int main() {
    Node* head = new Node(1);
    Node* tail = head;

    insert(tail, 2);
    insert(tail, 3);
    insert(tail, 4);
    insert(tail, 5);
    print(head);

    head = copyRandomList(head);
    print(head);
    return 0;
}