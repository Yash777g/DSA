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

    
}

bool isBalanced(TreeNode* root) {
    int left = height(root->left);  
    int right = height(root->right);
    
    if(abs(left-right) == 1 || left-right == 0) {
        return true;
    } return false;
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

