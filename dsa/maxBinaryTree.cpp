#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        if(temp == nullptr) {
            cout << endl;       
            if(!q.empty()) {
                q.push(nullptr);
            }
        } else {
            cout << temp->val << " ";
            if(temp->left) {
                q.push(temp->left);
            } if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

int findmax(vector<int>& nums, int low, int high) {
    int index = -1, max = -1;
    for(int i = low; i < high; i++) {
        if(nums[i] > max) {
            max = nums[i];
            index = i;
        }
    } return index;
}

TreeNode* construct(vector<int>& nums, int low, int high){
    if(low >= high) {
        return nullptr;
    }

    int index = findmax(nums, low, high);

    TreeNode* root = new TreeNode(nums[index]);

    root->left = construct(nums, low, index);
    root->right = construct(nums, index+1, high);
    
    return root;
} 

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return construct(nums, 0, nums.size());
}

int main() {
    vector<int> nums = {3,2,1,6,0,5};
    TreeNode* root = constructMaximumBinaryTree(nums);

    print(root);
    return 0;
}