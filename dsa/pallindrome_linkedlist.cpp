#include <iostream>
#include <vector>
#include <string>
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
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    
    std::cout << endl;
}

int getlenght(ListNode* head) {
    ListNode* temp = head;
    int cnt = 0;

    while(temp) {
        cnt++;
        temp = temp->next;
    }

    return cnt;
}

// O(n)-> time but O(1) -> space complexity
bool isPalindrome(ListNode* head) {
    if(head == nullptr) { return false; }
    
    int size = 0;
    ListNode *temp = head;
    
    while (temp != nullptr) {
        ++size;
        temp = temp->next;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *current = head;
    ListNode *prev = nullptr;
        
    while (current != slow) {
        ListNode *forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;
    }

    if (size % 2 != 0 && slow != nullptr) { slow = slow->next; }
    
    while (slow != nullptr) {
        if (prev != nullptr && slow->data != prev->data) { return false; }
            
        slow = slow->next;
        if (prev != nullptr) { prev = prev->next; }
    }

    return true;
}

// O(n) -> space and time complexity
/*bool isPalindrome(ListNode* head) {
    vector<int> nums;
    ListNode* temp = head;

    while(temp) {
        nums.push_back(temp->data);
        temp = temp->next;
    }

    int start = 0, end = nums.size() - 1;
    while(start <= end) {
        if(nums[start] != nums[end]) {
            return false;
        }
        start++;
        end--;
    }

    return true;
}*/

int main() {
    ListNode* head = new ListNode(1);
    ListNode* tail = head;

    insert(tail, 2);
    insert(tail, 2);
    insert(tail, 1);
    print(head);

    bool ans = isPalindrome(head);
    std::cout << ans;

    return 0;
}