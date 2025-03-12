#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode* right;
        TreeNode* left;

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
            cout << " " << temp->val << " ";
            if(temp->left) {
                q.push(temp->left);
            } if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

int solve(int& maxLen, TreeNode* root) {
    if(!root) {
        return 0;
    }

    int left = solve(maxLen, root->left);
    int right = solve(maxLen, root->right);

    maxLen = max(maxLen, left+right);
    return 1 + max(left, right);;
}

int diameterOfBinaryTree(TreeNode* root) {
    int maxLen = 0;
    solve(maxLen, root);
    return maxLen;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    print(root);

    cout << diameterOfBinaryTree(root);
    return 0;
}