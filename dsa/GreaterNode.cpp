#include <iostream> 
#include <vector>
#include <algorithm>
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

// two pointer
vector<int> nextLargerNodes(ListNode* head) {
    vector<int> result;
    ListNode* curr = head;

    while(curr) {
        ListNode* front = curr->next;

        while(front && front->val < curr->val) {
            front = front->next;
        }

        if(front != nullptr) {
            result.push_back(front->val);
        }else {
            result.push_back(0);
        }
        curr = curr->next;
    }

    return result;
}

/*array/stack approach
vector<int> nextLargerNodes(ListNode* head) {
    vector<int> result;
    vector<int> mark;
    ListNode* temp = head;

    int cnt = 0;
    while(temp) {
        mark.push_back(temp->val);
        temp = temp->next;
    }

    for(int i = 0; i < mark.size() - 1; i++) {
        for(int j = i + 1; j < mark.size(); j++) {
            if(mark[i] < mark[j]) {
                result.push_back(mark[j]);
                j = mark.size();
                cnt++;
            }
        }

        if(cnt == 0) {
            result.push_back(0);
        }

        cnt = 0;
    }    

    result.push_back(0);

    return result;
}*/ 

int main() {
    ListNode* head = new ListNode(2);
    ListNode* tail = head;

    insert(tail, 1);
    insert(tail, 5);
    print(head);

    vector<int> ans = nextLargerNodes(head);
    for(auto &i: ans) {
        cout << i << " ";
    }

    return 0;
}