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

void bfsTraversal(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()) {
        TreeNode* temp = q.front();
        // for reverse level order traversal use stack
        // stack<int> reverse;
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
            } 
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void solve(TreeNode* root) {
    if(root->left == nullptr && root->right == nullptr) {
        return;
    }

    TreeNode* temp = root->right;
    root->right = root->left;
    root->left = temp;

    if(root->left) 
        solve(root->left);
    if(root->right)
        solve(root->right);
}

TreeNode* invertTree(TreeNode* root) {
    if(root == nullptr) {
        return root;
    }
    
    solve(root);
    return root;
}

int main() {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(2, node1, node3);

    TreeNode* node6 = new TreeNode(6);
    TreeNode* node9 = new TreeNode(9);
    TreeNode* node7 = new TreeNode(7, node6, node9);

    TreeNode* root = new TreeNode(4, node2, node7);

    bfsTraversal(root);
    root = invertTree(root);
    bfsTraversal(root);
    return 0;
}