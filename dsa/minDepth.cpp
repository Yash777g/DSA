#include <iostream>
#include <queue>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int minDepth(TreeNode* root) {
    if(!root) {
        return 0;
    }

    if(!root->left) return minDepth(root->right) + 1;
    if(!root->right) return minDepth(root->left) + 1;

    return min(minDepth(root->left), minDepth(root->right)) + 1;
}

int main() {
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node2 = new TreeNode(2, node3, node5);
    TreeNode* node9 = new TreeNode(9, nullptr, node7);
    TreeNode* root = new TreeNode(4, node2, node9);

    cout << minDepth(root);
    return 0;
}