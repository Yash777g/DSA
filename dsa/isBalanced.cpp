#include <iostream>
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

int height(TreeNode* root) {
    if(!root) {
        return 0;
    }
    
    int left = height(root->left);
    if(left == -1) return -1;

    int right = height(root->right);
    if(right == -1) return -1;

    if (abs(left - right) > 1) return -1;

    int ans = max(left, right) + 1;
    return ans;
}

bool isBalanced(TreeNode* root) {
    return height(root) != -1;
}

int main() {
    TreeNode* root = new TreeNode(3);
    
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    print(root);
    return 0;
}

