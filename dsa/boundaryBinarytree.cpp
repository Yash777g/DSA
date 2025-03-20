#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traverseLeft(TreeNode* root, vector<int>& ans) {
    if (!root || (!root->left && !root->right)) return;

    ans.push_back(root->val);
    if (root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
}

void leafNodes(TreeNode* root, vector<int>& ans) {
    if (!root) return;

    if (!root->left && !root->right) {
        ans.push_back(root->val);
        return;
    }

    leafNodes(root->left, ans);
    leafNodes(root->right, ans);
}

void traverseRight(TreeNode* root, vector<int>& ans) {
    if (!root || (!root->left && !root->right)) return;

    if (root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);

    ans.push_back(root->val); 
}

vector<int> boundary(TreeNode* root) {
    if (!root) return {};

    vector<int> ans;
    if (!root->left && !root->right) {
        ans.push_back(root->val);
        return ans;
    }

    ans.push_back(root->val);

    traverseLeft(root->left, ans);

    leafNodes(root, ans);

    vector<int> rightBoundary;
    traverseRight(root->right, rightBoundary);
    ans.insert(ans.end(), rightBoundary.begin(), rightBoundary.end());

    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);
    root->right->right->left = new TreeNode(10);
    root->right->right->right = new TreeNode(11);

    vector<int> result = boundary(root);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
