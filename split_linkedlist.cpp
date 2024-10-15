#include <iostream> 
#include <vector>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode* next;

        ListNode(int val) {
            this->val = val;
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
        cout << temp->val << " ";
        temp = temp->next;
    }cout << endl;
}

int getLength(ListNode* head) {
    int count = 0;
    ListNode* temp = head;

    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

vector<ListNode*> splitListToParts(ListNode* head, int k) {
    vector<ListNode*> result(k, nullptr); 
    int totalNodes = getLength(head);     
    
    int partSize = totalNodes / k;
    int extraNodes = totalNodes % k;

    ListNode* curr = head;
    
    for (int i = 0; i < k; i++) {
        if (curr == nullptr) {
            break; 
        }
        
        result[i] = curr;  
        int currentPartSize = partSize + (extraNodes-- > 0 ? 1 : 0);
     
        for (int j = 1; j < currentPartSize; j++) {
            if (curr != nullptr) {
                curr = curr->next;
            }
        }
        
        if (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = nullptr;  
            curr = next;           
        }
    }

    return result;
}


int main() {
    ListNode* head = new ListNode(1);
    ListNode* tail = head;

    insert(tail, 2);
    insert(tail, 3);
    print(head);

    vector<ListNode*> ans = splitListToParts(head, 5);
    
    return 0;
}